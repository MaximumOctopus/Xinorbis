{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.Search;

interface

uses
  Classes, SyncObjs, Generics.Collections,

  X.FileExtension, X.FileExtensionsObject, X.CFileObject,

  X.LanguageHandler, X.Windows;

type
  TGetResults = procedure(aSize : int64; aFilesCount, aFolderCount : integer) of object;

  TSearchThread = class(TThread)
  private
    FSearchSize   : int64;
    FFilesCount   : integer;
    FFoldersCount : integer;

    UserSearchTerms : string;
    FSource    : integer;

    FSendResults : TGetResults;

    FCriticalSection : TCriticalSection;
  protected
    procedure Execute; override;
  public
    procedure SetData(aSource : integer; const s : string);

    destructor Destroy; override;

    property OnGetResults    : TGetResults read FSendResults write FSendResults;
  end;

implementation

uses
  {main,} sysutils, math,

     X.Constants, X.Utility, X.Global, X.Settings, X.CSearchCriteriaObject,
     X.CUserData, X.SearchUtility, X.Conversions, X.GlobalObjects;


destructor TSearchThread.Destroy;
begin
  FCriticalSection.Free;

  inherited Destroy;
end;


procedure TSearchThread.SetData(aSource : integer; const s : string);
var
  t : integer;

begin
  UserSearchTerms  := s;
  FSource          := aSource;

  FSearchSize      := 0;
  FFilesCount      := 0;
  FFoldersCount    := 0;

  FCriticalSection := TCriticalSection.Create;

  for t := 1 to __FileCategoriesCount do begin // clear data
    ExtSpreadSearch[t, 1] := 0;
    ExtSpreadSearch[t, 2] := 0;
  end;
end;


procedure TSearchThread.Execute;
 var
  t,x,z : integer;
  SearchCriteria : TObjectList<TSearchCriteriaObject>;
  SearchTerms : TStringList;
  QuickTerms : TStringList;
  FoundTerms : TStringList;
  found : boolean;
  tsco : TSearchCriteriaObject;
  SearchPosition : integer;
  tfo : TFileObject;
  tfn : TFileObject;
  CategorySearchFound, UserSearchFound, ExcludeFolderSearchFound, IncludeFolderSearchFound : boolean;
  CategorySearchCount, UserSearchCount, ExcludeFolderSearchCount, IncludeFolderSearchCount : integer;

  procedure GetSearchTerms;
   var
    i : integer;
    s : string;
    sco : TSearchCriteriaObject;
    reading : boolean;
    inside : boolean;

    function AddThisKeyword(const s : string): boolean;
     begin
      Result := True;

      sco := TSearchUtility.ProcessSearchTerm(s);

      if sco.sctype <> SearchTypeNONE then begin
        SearchCriteria.Add(sco);

        Result := False;
      end;
    end;

   begin
    s       := '';
    reading := False;
    inside  := False;

    for i := 1 to length(UserSearchTerms) do begin
      if UserSearchTerms[i] = '"' then begin
        if reading = False then
          reading := True
        else begin
          reading := False;

          if AddThisKeyword(UpperCase(s)) then
            SearchTerms.Add('"' + UpperCase(s) + '"');
          s := '';
        end;
      end
      else if UserSearchTerms[i] = '(' then
        inside := True
      else if UserSearchTerms[i] = ')' then
        inside := False
      else if (UserSearchTerms[i] = ' ') and not(inside) then begin
        if reading then
          s := s + ' '
        else begin
          if s <> '' then begin
            if AddThisKeyword(UpperCase(s)) then begin // not a bracketted search function, must
                                                       // be a text AND or single string search
              SearchTerms.Add(UpperCase(s));
            end;

            s := '';
          end;
        end;
      end
      else begin
        s := s + UserSearchTerms[i];
      end;
    end;

    if s <> '' then if AddThisKeyword(UpperCase(s)) then SearchTerms.Add(UpperCase(s));
  end;

  procedure ProcessQuickTerms(const s : string);
   var
    i : integer;
    ret : string;
    inside : boolean;

   begin
    QuickTerms.Clear;
    ret    := '';
    inside := False;

    for i := 1 to length(s) do begin
      if s[i] = '"' then begin
        { do nothing }
      end
      else if s[i] = '(' then
        inside := True
      else if s[i] = ')' then
        inside := False
      else if (s[i] = ' ') and not(inside) then begin
        QuickTerms.Add(ret);
        ret := '';
      end
      else
        ret := ret + s[i];
    end;

    if ret <> '' then QuickTerms.Add(ret);
  end;

 begin
  SearchPosition  := 0;

  FreeOnTerminate := True;

  FCriticalSection.Acquire;

  SearchCriteria        := TObjectlist<TSearchCriteriaObject>.Create;
  SearchTerms           := TStringList.Create;
  SearchTerms.Sorted    := True;
  QuickTerms            := TStringList.Create;
  FoundTerms            := TStringList.Create;
  FoundTerms.Sorted     := True;

  try
    GetSearchTerms;

    SearchTerms.Sort;

    // -------------------------------------------------------------------------

    CategorySearchCount      := 0;
    UserSearchCount          := 0;
    ExcludeFolderSearchCount := 0;
    IncludeFolderSearchCount := 0;

    for z := 0 to SearchCriteria.Count - 1 do begin
      tsco := SearchCriteria.Items[z];

      case tsco.sctype of
        SearchTypeCategory      : inc(CategorySearchCount);
        SearchTypeNotCategory   : inc(CategorySearchCount);
        SearchTypeUsername      : inc(UserSearchCount);
        SearchTypeNotUsername   : inc(UserSearchCount);
        SearchTypeFolderExclude : inc(ExcludeFolderSearchCount);
        SearchTypeFolderInclude : inc(IncludeFolderSearchCount);
      end;
    end;

    if CategorySearchCount = 0 then
      CategorySearchfound := True
    else
      CategorySearchfound := False;

    if UserSearchCount = 0 then
      UserSearchfound := True
    else
      UserSearchfound := False;

    if ExcludeFolderSearchCount = 0 then
      ExcludeFolderSearchFound := True
    else
      ExcludeFolderSearchFound := False;

    if IncludeFolderSearchCount = 0 then
      IncludeFolderSearchFound := True
    else
      IncludeFolderSearchFound := False;

    // =========================================================================
    // =========================================================================

    for t := 0 to GScanDetails[FSource].Files.Count - 1 do begin

      tfo   := GScanDetails[FSource].Files.Items[t];

      found := False;

      // search for each search term -------------------------------------------
      for x := 0 to SearchTerms.Count - 1 do begin
          if SearchTerms.Strings[x][1] = '"' then begin  // this is an AND search...
            ProcessQuickTerms(SearchTerms.Strings[x]);

            FoundTerms.Clear;

            for z := 0 to QuickTerms.Count - 1 do begin
              if Pos(QuickTerms.Strings[z], UpperCase(GScanDetails[FSource].Folders[tfo.FilePathIndex] + tfo.FileName)) <> 0 then begin
                if FoundTerms.IndexOf(QuickTerms.Strings[z]) = -1 then
                  FoundTerms.Add(QuickTerms.Strings[z]);
              end;
            end;

            if FoundTerms.Count = QuickTerms.Count then
              found := True;
          end
          else begin
            z := Pos('*', SearchTerms.Strings[x]);

            if z <> 0 then begin
              if ((faDirectory and tfo.Attributes) = 0) then begin
                if z = 1 then begin
                  if Pos(Copy(SearchTerms.Strings[x], 2, Length(SearchTerms.Strings[x]) - 1), UpperCase(tfo.FileName)) =
                     Length(tfo.FileName) - Length(SearchTerms.Strings[x]) + 2 then found := True;
                end
                else if z=Length(SearchTerms.Strings[x]) then begin
                  if Pos(Copy(SearchTerms.Strings[x], 1, Length(SearchTerms.Strings[x]) - 1), UpperCase(tfo.FileName)) = 1 then found := True;
                end;
              end;
            end
            else begin
              if Pos(SearchTerms.Strings[x], UpperCase(GScanDetails[FSource].Folders[tfo.FilePathIndex] + tfo.FileName)) <> 0 then begin
                found := True;
              end;
            end;
          end;
        end;

        // if there are no search terms, but search criteria then we set found to
        // true in order that we check every item for the criteria
        if (SearchTerms.Count = 0) and (SearchCriteria.Count > 0) then
          found := True;

        // =======================================================================
        // =======================================================================

        // == process any special search criteria ================================
        if (found = True) and (SearchCriteria.Count <> 0) then begin
          for z := 0 to SearchCriteria.Count - 1 do begin
            tsco := SearchCriteria.Items[z];

            case tsco.sctype of
              SearchTypeSizeLess   : begin  // size <
                                       if ((faDirectory and tfo.Attributes) = 0) then begin
                                         if not(tfo.FileSize <= tsco.integervalue) then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
              SearchTypeSizeEqual  : begin  // size =
                                       if ((faDirectory and tfo.Attributes) = 0) then begin
                                         if not(tfo.FileSize <> tsco.integervalue) then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
              SearchTypeSizeMore   : begin // size >
                                       if ((faDirectory and tfo.Attributes) = 0) then begin
                                         if not(tfo.FileSize >= tsco.integervalue) then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
              SearchTypeDateLess   : begin // date <
                                       if tfo.FileDateC <> 0 then begin
                                         if tfo.FileDateC > tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
              SearchTypeDateMore   : begin // date >
                                       if tfo.FileDateC <> 0 then begin
                                         if tfo.FileDateC < tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
              SearchTypeDateEqual  : begin // date =
                                       if tfo.FileDateC <> 0 then begin
                                         if tfo.FileDateC <> tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
              SearchTypeATimeLess  : begin
                                       if tfo.FileTimeA > tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeATimeMore  : begin
                                       if tfo.FileTimeA < tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeATimeEqual : begin
                                       if tfo.FileTimeA <> tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeMTimeLess  : begin
                                       if tfo.FileTimeM > tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeMTimeMore  : begin
                                       if tfo.FileTimeM < tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeMTimeEqual : begin
                                       if tfo.FileTimeM <> tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeTimeLess   : begin
                                       if tfo.FileTimeC > tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeTimeMore   : begin
                                       if tfo.FileTimeC < tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeTimeEqual  : begin
                                       if tfo.FileTimeC <> tsco.integervalue then
                                         found := False;
                                     end;
              SearchTypeFileType   : begin  // hidden and system etc.
                                       case tsco.integervalue of
                                         FileType_Hidden             : if ((faHidden and tfo.Attributes) = 0)                     then found := False;
                                         FileType_System             : if ((faSysFile and tfo.Attributes) = 0)                    then found := False;
                                         FileType_Archive            : if ((faArchive and tfo.Attributes) = 0)                    then found := False;
                                         FileType_Null               : if tfo.FileSize <> 0                                       then found := False;
                                         FileType_ReadOnly           : if ((Sysutils.faReadOnly and tfo.Attributes) = 0)          then found := False;
                                         FileType_Compressed         : if ((faCompressed and tfo.Attributes) = 0)                 then found := False;
                                         FileType_Encrypted          : if ((faEncrypted and tfo.Attributes) = 0)                  then found := False;
                                         FileType_RecallOnOpen       : if ((faRecallOnOpen and tfo.Attributes) = 0)               then found := False;
                                         FileType_RecallOnDataAccess : if ((faRecallOnDataAccess and tfo.Attributes) = 0)         then found := False;
                                         FileType_Offline            : if ((faOffline and tfo.Attributes) = 0)                    then found := False;
                                         FileType_CreatedToday       : if tfo.FileDateC <> GScanDetails[FSource].TodayAsInteger   then found := False;
                                         FileType_AccessedToday      : if tfo.FileDateA <> GScanDetails[FSource].TodayAsInteger   then found := False;
                                         FileType_ModifiedToday      : if tfo.FileDateM <> GScanDetails[FSource].TodayAsInteger   then found := False;
                                         FileType_Temp               : if tfo.Temp = False                                        then found := False;
                                         FileType_Folder             : if ((faDirectory and tfo.Attributes) = 0)                  then found := False;
                                         FileType_File               : if ((faDirectory and tfo.Attributes) = faDirectory)        then found := False;
                                         FileType_NoExtension        : if ExtractFileExt(tfo.FileName) <> ''                      then found := False;
                                         FileType_SparseFile         : if ((faSparseFile and tfo.Attributes) = 0)                 then found := False;
                                         FileType_Reparsepoint       : if ((faReparsePoint and tfo.Attributes) = 0)               then found := False;
                                         FileType_NotContentI        : if ((faNotContentI and tfo.Attributes) = 0)                then found := False;

                                         FileType_Virtual            : if ((faRecallOnOpen and tfo.Attributes) = 0) and
                                                                          ((faRecallOnDataAccess and tfo.Attributes) = 0) and
                                                                          ((faOffline and tfo.Attributes) = 0)                    then found := False;
                                       end;
                                     end;
              SearchTypeNotFileType: begin  // hidden and system etc.
                                       case tsco.integervalue of
                                         FileType_Hidden             : if ((faHidden and tfo.Attributes) = faHidden)                         then found := False;
                                         FileType_System             : if ((faSysFile and tfo.Attributes) = faSysFile)                       then found := False;
                                         FileType_Archive            : if ((faArchive and tfo.Attributes) = faArchive)                       then found := False;
                                         FileType_Null               : if tfo.FileSize = 0                                                   then found := False;
                                         FileType_ReadOnly           : if ((Sysutils.faReadOnly and tfo.Attributes) = Sysutils.faReadOnly)   then found := False;
                                         FileType_Compressed         : if ((faCompressed and tfo.Attributes) = faCompressed)                 then found := False;
                                         FileType_Encrypted          : if ((faEncrypted and tfo.Attributes) = faEncrypted)                   then found := False;
                                         FileType_RecallOnOpen       : if ((faRecallOnOpen and tfo.Attributes) = faRecallOnOpen)             then found := False;
                                         FileType_RecallOnDataAccess : if ((faRecallOnDataAccess and tfo.Attributes) = faRecallOnDataAccess) then found := False;
                                         FileType_Offline            : if ((faOffline and tfo.Attributes) = faOffline)                       then found := False;
                                         FileType_CreatedToday       : if tfo.FileDateC = GScanDetails[FSource].TodayAsInteger               then found := False;
                                         FileType_AccessedToday      : if tfo.FileDateA = GScanDetails[FSource].TodayAsInteger               then found := False;
                                         FileType_ModifiedToday      : if tfo.FileDateM = GScanDetails[FSource].TodayAsInteger               then found := False;
                                         FileType_Temp               : if tfo.Temp = True                                                    then found := False;
                                         FileType_Folder             : if ((faDirectory and tfo.Attributes) = faDirectory)                   then found := False;
                                         FileType_File               : if ((faDirectory and tfo.Attributes) = 0)                             then found := False;
                                         FileType_NoExtension        : if ExtractFileExt(tfo.FileName) <> ''                                 then found := False;
                                         FileType_SparseFile         : if ((faSparseFile and tfo.Attributes) = faSparseFile)                 then found := False;
                                         FileType_Reparsepoint       : if ((faReparsePoint and tfo.Attributes) = faReparsePoint)             then found := False;
                                         FileType_NotContentI        : if ((faNotContentI and tfo.Attributes) = faNotContentI)               then found := False;

                                         FileType_Virtual            : if ((faRecallOnOpen and tfo.Attributes) = faRecallOnOpen) or
                                                                          ((faRecallOnDataAccess and tfo.Attributes) = faRecallOnDataAccess) or
                                                                          ((faOffline and tfo.Attributes) = faOffline)                       then found := False;
                                       end;
                                     end;
              SearchTypeADateLess  : begin // adate <
                                       if tfo.FileDateA <> 0 then begin
                                         if tfo.FileDateA > tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
              SearchTypeADateMore  : begin // adate >
                                       if tfo.FileDateA <> 0 then begin
                                         if tfo.FileDateA < tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
             SearchTypeADateEqual  : begin // adate =
                                       if tfo.FileDateA <> 0 then begin
                                         if tfo.FileDateA <> tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
             SearchTypeMDateLess   : begin // mdate <
                                       if tfo.FileDateM <> 0 then begin
                                         if tfo.FileDateM > tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
             SearchTypeMDateMore   : begin // mdate >
                                       if tfo.FileDateM <> 0 then begin
                                         if tfo.FileDateM < tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
             SearchTypeMDateEqual  : begin // mdate =
                                       if tfo.FileDateM <> 0 then begin
                                         if tfo.FileDateM <> tsco.integervalue then
                                           found := False;
                                       end
                                       else found := False;
                                     end;
             SearchTypeFilenameLengthEqual : begin
                                               if length(tfo.FileName) <> tsco.integervalue then
                                                 found := False
                                               else
                                                 found := True;
                                             end;
             SearchTypeFilenameLengthLess  : begin
                                               if length(tfo.FileName) > tsco.integervalue then
                                                 found := False
                                               else
                                                 found := True;
                                             end;
             SearchTypeFilenameLengthMore : begin
                                               if length(tfo.FileName) < tsco.integervalue then
                                                 found := False
                                               else
                                                 found := True;
                                             end;
             SearchTypeFilePathLengthEqual : begin
                                               if length(GScanDetails[FSource].Folders[tfo.FilePathIndex]) + length(tfo.FileName) <> tsco.integervalue then
                                                 found := False
                                               else
                                                 found := True;
                                             end;
             SearchTypeFilePathLengthLess  : begin
                                               if length(GScanDetails[FSource].Folders[tfo.FilePathIndex]) + length(tfo.FileName) > tsco.integervalue then
                                                 found := False
                                               else
                                                 found := True;
                                             end;
             SearchTypeFilePathLengthMore : begin
                                               if length(GScanDetails[FSource].Folders[tfo.FilePathIndex]) + length(tfo.FileName) < tsco.integervalue then
                                                 found := False
                                               else
                                                 found := True;
                                             end;
             SearchTypeFileExtensionEqual : begin
                                              if UpperCase(ExtractFileExt(tfo.FileName)) <> tsco.stringvalue then
                                                 found := False
                                               else
                                                 found := True;
                                            end;
            end;
          end;
        end;

        // =======================================================================
        // =======================================================================

        if CategorySearchCount > 0 then begin
          CategorySearchfound := False;

          for z := 0 to SearchCriteria.Count - 1 do begin
            tsco := SearchCriteria.Items[z];

            case tsco.sctype of
              SearchTypeCategory     : begin // category
                                         if ((faDirectory and tfo.Attributes) = 0) then begin
                                           if tsco.integervalue = Category_Custom_All then begin
                                             if tfo.FileCategory >= Category_Custom_1 then
                                               CategorySearchfound := True;
                                           end
                                           else
                                             if tfo.FileCategory = tsco.integervalue then
                                               CategorySearchfound := True;
                                         end;
                                       end;
              SearchTypeNotCategory  : begin // category
                                         if ((faDirectory and tfo.Attributes) = 0) then begin
                                           if tsco.integervalue = Category_Custom_All then begin
                                             if tfo.FileCategory < Category_Custom_1 then
                                               CategorySearchfound := True;
                                         end
                                         else
                                           if tfo.FileCategory <> tsco.integervalue then
                                             CategorySearchfound := True;
                                         end;
                                       end;
            end;
          end;
        end;

        // =======================================================================
        // =======================================================================

        if UserSearchCount > 0 then begin
          UserSearchFound := True;

          for z := 0 to SearchCriteria.Count - 1 do begin
            tsco := SearchCriteria.Items[z];

            case tsco.sctype of
              SearchTypeUsername            : if UpperCase(GScanDetails[FSource].Users[tfo.Owner].Name) <> tsco.stringvalue then
                                                UserSearchFound := False;
              SearchTypeNotUsername         : if UpperCase(GScanDetails[FSource].Users[tfo.Owner].Name) = tsco.stringvalue then
                                                UserSearchFound := False;
              SearchTypeUsernameContains    : if Pos(tsco.stringvalue, UpperCase(GScanDetails[FSource].Users[tfo.Owner].Name)) = 0 then
                                                UserSearchFound := False;
              SearchTypeUsernameNotContains : if Pos(tsco.stringvalue, UpperCase(GScanDetails[FSource].Users[tfo.Owner].Name)) <> 0 then
                                                UserSearchFound := False;
            end;
          end;
        end;

        // =======================================================================
        // =======================================================================

        if ExcludeFolderSearchCount > 0 then begin
          ExcludeFolderSearchFound := True;

          for z := 0 to SearchCriteria.Count - 1 do begin
            tsco := SearchCriteria.Items[z];

            case tsco.sctype of
              SearchTypeFolderExclude       : if Pos(tsco.stringvalue, UpperCase(GScanDetails[FSource].Folders[tfo.FilePathIndex])) > 0 then
                                                ExcludeFolderSearchFound := False;
            end;
          end;
        end;

        // =======================================================================
        // =======================================================================

        if IncludeFolderSearchCount > 0 then begin
          IncludeFolderSearchFound := False;

          for z := 0 to SearchCriteria.Count - 1 do begin
            tsco := SearchCriteria.Items[z];

            case tsco.sctype of
              SearchTypeFolderInclude       : if Pos(tsco.stringvalue, UpperCase(GScanDetails[FSource].Folders[tfo.FilePathIndex])) > 0 then
                                                IncludeFolderSearchFound := True;
            end;
          end;
        end;

        // =======================================================================
        // =======================================================================

        Found := (Found and CategorySearchFound and UserSearchFound and ExcludeFolderSearchFound and IncludeFolderSearchFound);

        // =======================================================================
        // =======================================================================        
                                           
        if found = True then begin
          inc(ExtSpreadSearch[tfo.FileCategory, 1]);
          inc(ExtSpreadSearch[tfo.FileCategory, 2], tfo.FileSize);

          if ((faDirectory and tfo.Attributes) = faDirectory) then
            inc(FFoldersCount)
          else
            inc(FFilesCount);

          inc(FSearchSize, tfo.FileSize);
          inc(SearchPosition);

          // ===================================================================

          tfn := TFileObject.Create;

          tfn.FilePathIndex  := GScanDetails[FSource].Files.Items[t].FilePathIndex;
          tfn.FileName       := GScanDetails[FSource].Files.Items[t].FileName;
          tfn.FileSize       := GScanDetails[FSource].Files.Items[t].FileSize;
          tfn.FileSizeOnDisk := GScanDetails[FSource].Files.Items[t].FileSizeOnDisk;
          tfn.FileDateC      := GScanDetails[FSource].Files.Items[t].FileDateC;
          tfn.FileDateA      := GScanDetails[FSource].Files.Items[t].FileDateA;
          tfn.FileDateM      := GScanDetails[FSource].Files.Items[t].FileDateM;
          tfn.FileTimeC      := GScanDetails[FSource].Files.Items[t].FileTimeC;
          tfn.FileTimeA      := GScanDetails[FSource].Files.Items[t].FileTimeA;
          tfn.FileTimeM      := GScanDetails[FSource].Files.Items[t].FileTimeM;
          tfn.FileCategory   := GScanDetails[FSource].Files.Items[t].FileCategory;
          tfn.Attributes     := GScanDetails[FSource].Files.Items[t].Attributes;
          tfn.Temp           := GScanDetails[FSource].Files.Items[t].Temp;
          tfn.Owner          := GScanDetails[FSource].Files.Items[t].Owner;

          GScanDetails[dataSearch].Files.Add(tfn);

          // ===================================================================
        end;
      end;
  finally
    FoundTerms.Free;
    QuickTerms.Free;
    SearchCriteria.Free;
    SearchTerms.Free;
  end;

  if Assigned(FSendResults) then
    FSendResults(FSearchSize, FFilesCount, FFoldersCount);

  FCriticalSection.Leave;
end;


end.
