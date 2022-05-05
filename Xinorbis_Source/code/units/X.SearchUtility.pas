{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.SearchUtility;

interface


uses
  System.SysUtils, System.Classes,

  X.LanguageHandler,

  X.Settings, X.Utility, X.Constants, X.CSearchCriteriaObject, X.Conversions;


type
  TSearchUtility = class
  private
    class procedure GetTokens(const aInput : string; var aParameter, aValue : string; var aTest : integer);

    class procedure ProcessSearchTermSize(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessSearchTermTime(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessSearchTermDate(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessSearchTermUser(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessSearchTermFNL(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessSearchTermCategory(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessSearchTermTypes(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessExtensions(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessExcludeFolder(var aTSCO : TSearchCriteriaObject; aInput : string);
    class procedure ProcessIncludeFolder(var aTSCO : TSearchCriteriaObject; aInput : string);
  public
    class function  GetSearchText(category : integer): string;
    class function  GetSearchAttribute(attrib : integer): string;
    class function  GetSearchSize(aFromSize, aFromUnit, aToSize, aToUnit : integer): string;

    class procedure IntegerValueHelper(var aTSCO : TSearchCriteriaObject; aInput : string; aFrom, aTo, aSearchType : integer);

    class function  ProcessSearchTerm(const s : string): TSearchCriteriaObject;
    class function  ProcessSearchTermToSQL(const aInput : string): string;
    class function  ProcessSearchTermToSQLPost(const s : string): string;
    class function  ProcessSearchTermToSQLPostODBC(const s : string): string;

    class function  XinorbisSearchToSQL(const xdate, xfolder, xcomputer, xinsearch : string; limitx, limity : integer; demomode : boolean): string;
    class function  XinorbisSearchAllToSQL(const xdate, xfolder, xcomputer : string; demomode : boolean): string;
  end;


const
  testLessThan    = 0;
  testEqualTo     = 1;
  testGreaterThan = 2;
  testNotEqualTo  = 3;
  testContains    = 4;
  testNotContains = 5;


implementation


const
  CCategoryTermCount = 27;
  CCategoryTerms  : array[1..CCategoryTermCount] of string =
                      ('PROG',
                       'SYS', 'SYSTEM',
                       'GFX', 'GRAPHIC',
                       'MOVIE', 'FILM',
                       'SND', 'SOUND', 'AUDIO',
                       'OFF', 'OFFICE',
                       'COD',
                       'COM', 'ZIP',
                       'OTH',
                       'C1', 'C2', 'C3', 'C4', 'C5', 'C6',
                       'C7', 'C8', 'C9', 'C10', 'CX');

  CCategoryValues : array[1..CCategoryTermCount] of integer =
                      (Category_Program,
                       Category_System, Category_System,
                       Category_Graphics, Category_Graphics,
                       Category_Movie, Category_Movie,
                       Category_Sound, Category_Sound, Category_Sound,
                       Category_Office, Category_Office,
                       Category_Code,
                       Category_Compressed, Category_Compressed,
                       Category_Other,
                       Category_Custom_1, Category_Custom_2, Category_Custom_3,
                       Category_Custom_4, Category_Custom_5, Category_Custom_6,
                       Category_Custom_7, Category_Custom_8, Category_Custom_9,
                       Category_Custom_10, Category_Custom_All);

  CTypeTermCount  = 21;
  CTypeTerms      : array[1..CTypeTermCount] of string =
                      ('FILE', 'FOLDER', 'NOEXT', 'HIDDEN',
                       'SYSTEM', 'ARCHIVE', 'SPARSEFILE', 'REPARSEPOINT',
                       'COMPRESSED', 'OFFLINE', 'NOTCONTENTI', 'ENCRYPTED',
                       'NULL', 'READONLY', 'CREATED', 'ACCESSED',
                       'MODIFIED', 'TEMP', 'RECALLONOPEN', 'RECALLONDATAACCESS', 'VIRTUAL');

  CTypeValues     : array[1..CTypeTermCount] of integer =
                      (FileType_File, FileType_Folder, FileType_NoExtension, FileType_Hidden,
                       FileType_System, FileType_Archive, FileType_SparseFile, FileType_Reparsepoint,
                       FileType_Compressed, FileType_Offline, FileType_NotContentI, FileType_Encrypted,
                       FileType_Null, FileType_ReadOnly, FileType_CreatedToday, FileType_AccessedToday,
                       FileType_ModifiedToday, FileType_Temp, FileType_RecallOnOpen, FileType_RecallOnDataAccess, FileType_Virtual);

  CModeField = 0;
  CModeTest  = 1;
  CModeValue = 2;


class function TSearchUtility.GetSearchText(category : integer): string;
 begin
  case category of
    Category_Program    : Result := '#PROG';
    Category_System     : Result := '#SYS';
    Category_Graphics   : Result := '#GFX';
    Category_Movie      : Result := '#MOVIE';
    Category_Sound      : Result := '#SOUND';
    Category_Office     : Result := '#OFF';
    Category_Code       : Result := '#COD';
    Category_Compressed : Result := '#COM';
    Category_Other      : Result := '#OTH';
    Category_Custom_1   : Result := '#C1';
    Category_Custom_2   : Result := '#C2';
    Category_Custom_3   : Result := '#C3';
    Category_Custom_4   : Result := '#C4';
    Category_Custom_5   : Result := '#C5';
    Category_Custom_6   : Result := '#C6';
    Category_Custom_7   : Result := '#C7';
    Category_Custom_8   : Result := '#C8';
    Category_Custom_9   : Result := '#C9';
    Category_Custom_10  : Result := '#C10';
    20, 99              : Result := '#CX';
  else
    Result := '#PROG';
  end;
end;


class function TSearchUtility.GetSearchAttribute(attrib : integer): string;
 begin
  case attrib of
    FileType_System             : Result := '@SYSTEM';
    FileType_Hidden             : Result := '@HIDDEN';
    FileType_Archive            : Result := '@ARCHIVE';
    FileType_Null               : Result := '@NULL';
    FileType_ReadOnly           : Result := '@READONLY';
    FileType_Compressed         : Result := '@COMPRESSED';
    FileType_Encrypted          : Result := '@ENCRYPTED';
    FileType_CreatedToday       : Result := '@CREATED';
    FileType_AccessedToday      : Result := '@ACCESSED';
    FileType_ModifiedToday      : Result := '@MODIFIED';
    FileType_Temp               : Result := '@TEMP';
    FileType_Folder             : Result := '@FOLDER';
    FileType_File               : Result := '@FILE';
    FileType_RecallOnOpen       : Result := '@RECALLONOPEN';
    FileType_RecallOnDataAccess : Result := '@RECALLONDATAACCESS';
    FileType_Virtual            : Result := '@VIRTUAL';
  else
    Result := '@FILE';
  end;
end;


class function TSearchUtility.GetSearchSize(aFromSize, aFromUnit, aToSize, aToUnit : integer): string;
begin
  if aFromSize <> -1 then begin
    Result := '(size>' + IntToStr(aFromSize) + XUnit[aFromUnit] + ')';
  end;

  if aToSize <> -1 then begin
    if Result <> '' then
      Result := Result + ' ';

    Result := Result + '(size<' + IntToStr(aToSize) + XUnit[aToUnit] + ')';
  end;
end;


class procedure TSearchUtility.IntegerValueHelper(var aTSCO : TSearchCriteriaObject;
                                                 aInput : string;
                                                 aFrom, aTo, aSearchType : integer);
var
  aValue : integer;

begin
  aValue := StrToIntDef(Copy(aInput, aFrom, length(aInput) - aTo), -1);

  if aValue <> -1 then begin
    aTSCO.sctype       := aSearchType;
    aTSCO.integervalue := aValue;
  end
  else begin
    aTSCO.sctype       := SearchTypeERROR;
    aTSCO.error        := XText[rsInvalidInput] + ' "' + Copy(aInput, aFrom, length(aInput) - aTo) + '"';
  end;
end;


class function TSearchUtility.ProcessSearchTerm(const s : string): TSearchCriteriaObject;
begin
  Assert(s <> '', 'ProcessSearchTerm :: blank input');

  Result := TSearchCriteriaObject.Create;

  if Pos('SIZE', s) > 0 then begin
    ProcessSearchTermSize(Result, s);
  end;

  if Pos('TIME', s) > 0 then begin
    ProcessSearchTermTime(Result, s);
  end;

  if Pos('DATE', s) > 0 then begin
    ProcessSearchTermDate(Result, s);
  end;

  if Pos('USER', s) > 0 then begin
    ProcessSearchTermUser(Result, s);
  end;

  if ((Pos('FILENAMELENGTH', s) > 0) or  (Pos('FILEPATHLENGTH', s) > 0)) then begin
    ProcessSearchTermFNL(Result, s);
  end;

  if Pos('EXTENSION=', s) > 0 then begin
    ProcessExtensions(Result, s);
  end;

  if Pos('EXCLUDEFOLDER=', s) > 0 then begin
    ProcessExcludeFolder(Result, s);
  end;

  if Pos('INCLUDEFOLDER=', s) > 0 then begin
    ProcessIncludeFolder(Result, s);
  end;

  if s <> '' then begin
    if s[1] = '#' then begin
      ProcessSearchTermCategory(Result, s);
    end
    else if s[1] = '@' then begin
      ProcessSearchTermTypes(Result, s);
    end;
  end;
end;


class procedure TSearchUtility.ProcessSearchTermSize(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  if lParameter = 'SIZE' then begin
    case lTest of
      testLessThan    : aTSCO.sctype := SearchTypeSizeLess;
      testEqualTo     : aTSCO.sctype := SearchTypeSizeEqual;
      testGreaterThan : aTSCO.sctype := SearchTypeSizeMore;
    end;

    aTSCO.integervalue := TConvert.ConvertUsefulUnitToInteger(lValue);
  end;
end;


class procedure TSearchUtility.ProcessSearchTermTime(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  if lParameter = 'ATIME' then begin
    case lTest of
      testLessThan    : aTSCO.sctype := SearchTypeATimeLess;
      testEqualTo     : aTSCO.sctype := SearchTypeATimeEqual;
      testGreaterThan : aTSCO.sctype := SearchTypeATimeMore;
    end;

    aTSCO.integervalue := TConvert.TimeFromAnyFormatToHHMM(lValue);
  end
  else if lParameter = 'MTIME' then begin
    case lTest of
      testLessThan    : aTSCO.sctype := SearchTypeMTimeLess;
      testEqualTo     : aTSCO.sctype := SearchTypeMTimeEqual;
      testGreaterThan : aTSCO.sctype := SearchTypeMTimeMore;
    end;

    aTSCO.integervalue := TConvert.TimeFromAnyFormatToHHMM(lValue);
  end
  else if (lParameter = 'TIME') or (lParameter = 'CTIME') then begin
    case lTest of
      testLessThan    : aTSCO.sctype := SearchTypeTimeLess;
      testEqualTo     : aTSCO.sctype := SearchTypeTimeEqual;
      testGreaterThan : aTSCO.sctype := SearchTypeTimeMore;
    end;

    aTSCO.integervalue := TConvert.TimeFromAnyFormatToHHMM(lValue);
  end;
end;


class procedure TSearchUtility.ProcessSearchTermDate(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  if (lParameter = 'DATE') or (lParameter = 'CDATE') then begin
    case lTest of
      testLessThan    : aTSCO.sctype := SearchTypeDateLess;
      testEqualTo     : aTSCO.sctype := SearchTypeDateEqual;
      testGreaterThan : aTSCO.sctype := SearchTypeDateMore;
    end;

    aTSCO.integervalue := TConvert.DateFromAnyFormatToYYYYMMDD(lValue);
  end
  else if lParameter = 'ADATE' then begin
    case lTest of
      testLessThan    : aTSCO.sctype := SearchTypeADateLess;
      testEqualTo     : aTSCO.sctype := SearchTypeADateEqual;
      testGreaterThan : aTSCO.sctype := SearchTypeADateMore;
    end;

    aTSCO.integervalue := TConvert.DateFromAnyFormatToYYYYMMDD(lValue);
  end
  else if lParameter = 'MDATE' then begin
    case lTest of
      testLessThan    : aTSCO.sctype := SearchTypeMDateLess;
      testEqualTo     : aTSCO.sctype := SearchTypeMDateEqual;
      testGreaterThan : aTSCO.sctype := SearchTypeMDateMore;
    end;

    aTSCO.integervalue := TConvert.DateFromAnyFormatToYYYYMMDD(lValue);
  end;
end;


class procedure TSearchUtility.ProcessSearchTermUser(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  if lParameter = 'USER' then begin
    case lTest of
      testLessThan,
      testEqualTo,
      testGreaterThan : aTSCO.sctype := SearchTypeUsername;
      testNotEqualTo  : aTSCO.sctype := SearchTypeNotUsername;
      testContains    : aTSCO.sctype := SearchTypeUsernameContains;
      testNotContains : aTSCO.sctype := SearchTypeUsernameNotContains;
    end;

    aTSCO.stringvalue := UpperCase(lValue);
  end;
end;


class procedure TSearchUtility.ProcessSearchTermFNL(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  idx : integer;

begin
  if Pos('FILENAMELENGTH=' , aInput) <> 0 then begin
    idx := Pos('FILENAMELENGTH=', aInput);

    IntegerValueHelper(aTSCO, aInput, idx + 15, 15, SearchTypeFilenameLengthEqual);
  end
  else if Pos('FILENAMELENGTH<' , aInput) <> 0 then begin
    idx := Pos('FILENAMELENGTH<', aInput);

    IntegerValueHelper(aTSCO, aInput, idx + 15, 15, SearchTypeFilenameLengthLess);
  end
  else if Pos('FILENAMELENGTH>' , aInput) <> 0 then begin
    idx := Pos('FILENAMELENGTH>', aInput);

    IntegerValueHelper(aTSCO, aInput, idx + 15, 15, SearchTypeFilenameLengthMore);
  end
  else if Pos('FILEPATHLENGTH=' , aInput) <> 0 then begin
    idx := Pos('FILEPATHLENGTH=', aInput);

    IntegerValueHelper(aTSCO, aInput, idx + 15, 15, SearchTypeFilePathLengthEqual);
  end
  else if Pos('FILEPATHLENGTH<' , aInput) <> 0 then begin
    idx := Pos('FILEPATHLENGTH<', aInput);

    IntegerValueHelper(aTSCO, aInput, idx + 15, 15, SearchTypeFilePathLengthLess);
  end
  else if Pos('FILEPATHLENGTH>' , aInput) <> 0 then begin
    idx := Pos('FILEPATHLENGTH>', aInput);

    IntegerValueHelper(aTSCO, aInput, idx + 15, 15, SearchTypeFilePathLengthMore);
  end
end;


class procedure TSearchUtility.ProcessExtensions(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  if lParameter = 'EXTENSION' then begin
    if lTest = testEqualTo then begin
      aTSCO.sctype       := SearchTypeFileExtensionEqual;
      aTSCO.stringvalue  := UpperCase(lValue);

      if aTSCO.stringvalue <> '' then begin
        if aTSCO.stringvalue[1] <> '.' then
          aTSCO.stringvalue := '.' + aTSCO.stringvalue;
      end;
    end;
  end;
end;


class procedure TSearchUtility.ProcessExcludeFolder(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  if lParameter = 'EXCLUDEFOLDER' then begin
    if lTest = testEqualTo then begin
      aTSCO.sctype       := SearchTypeFolderExclude;
      aTSCO.stringvalue  := UpperCase(lValue);
    end;
  end;
end;


class procedure TSearchUtility.ProcessIncludeFolder(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  if lParameter = 'INCLUDEFOLDER' then begin
    if lTest = testEqualTo then begin
      aTSCO.sctype       := SearchTypeFolderInclude;
      aTSCO.stringvalue  := UpperCase(lValue);
    end;
  end;
end;


class procedure TSearchUtility.ProcessSearchTermCategory(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  lParameter, lValue : string;
  lTest : integer;

begin
  GetTokens(aInput, lParameter, lValue, lTest);

  case lTest of
    testEqualTo    : aTSCO.sctype := SearchTypeCategory;
    testNotEqualTo : aTSCO.sctype := SearchTypeNotCategory;
  end;

  aTSCO.integervalue := StrToIntDef(lValue, 1);
end;


class procedure TSearchUtility.ProcessSearchTermTypes(var aTSCO : TSearchCriteriaObject; aInput : string);
var
  t : integer;

begin
  for t:= 1 to CTypeTermCount do begin
    if Pos('@' + CTypeTerms[t], aInput) > 0 then begin
      if aInput[length(aInput)] = '-' then
        aTSCO.sctype := SearchTypeNotFileType
      else
        aTSCO.sctype := SearchTypeFileType;

      aTSCO.integervalue := CTypeValues[t];
    end;
  end;
end;


class function TSearchUtility.ProcessSearchTermToSQL(const aInput : string): string;
var
  f_length : string;
  lParameter, lValue : string;
  lTest : integer;

begin
  Assert(aInput <> '', 'ProcessSearchTermToSQL :: blank input');

  if XSettings.Database.UseODBC then // sqlite and sqlserver have different functions for length :(
    f_length := 'len'
  else
    f_length := 'length';

  Result := '';

  GetTokens(aInput, lParameter, lValue, lTest);

  if lParameter = 'SIZE' then begin
    case lTest of
      testLessThan    : Result := '(FileSize<=' + TConvert.ConvertUsefulUnitToString(lValue) + ')';
      testEqualTo     : Result := '(FileSize='  + TConvert.ConvertUsefulUnitToString(lValue) + ')';
      testGreaterThan : Result := '(FileSize>=' + TConvert.ConvertUsefulUnitToString(lValue) + ')';
    end;
  end

  else if lParameter = 'ADATE' then begin
    case lTest of
      testLessThan    : Result := '(FileDateA<=' + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
      testEqualTo     : Result := '(FileDateA='  + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
      testGreaterThan : Result := '(FileDateA>=' + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
    end;
  end

  else if lParameter = 'MDATE' then begin
    case lTest of
      testLessThan    : Result := '(FileDateM<=' + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
      testEqualTo     : Result := '(FileDateM='  + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
      testGreaterThan : Result := '(FileDateM>=' + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
    end;
  end

  else if lParameter = 'DATE' then begin
    case lTest of
      testLessThan    : Result := '(FileDateC<=' + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
      testEqualTo     : Result := '(FileDateC='  + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
      testGreaterThan : Result := '(FileDateC>=' + IntToStr(TConvert.DateFromAnyFormatToYYYYMMDD(lValue)) + ')';
    end;
  end

  else if lParameter = 'USER' then begin
    case lTest of
      testLessThan,
      testEqualTo,
      testGreaterThan : Result := '(Owner='''           + UpperCase(lValue) + ''')';
      testNotEqualTo  : Result := '(Owner!='''          + UpperCase(lValue) + ''')';
      testContains    : Result := '(Owner LIKE ''%'     + UpperCase(lValue) + '%'')';
      testNotContains : Result := '(Owner NOT LIKE ''%' + UpperCase(lValue) + '%'')';
    end;
  end

  else if lParameter = 'FILENAMELENGTH' then begin
    case lTest of
      testLessThan    : Result := '(' + f_length + '(FileName)<=' + lValue + ')';
      testEqualTo     : Result := '(' + f_length + '(FileName)='  + lValue + ')';
      testGreaterThan : Result := '(' + f_length + '(FileName)>=' + lValue + ')';
    end;
  end

  else if lParameter = 'FILEPATHLENGTH' then begin
    case lTest of
      testLessThan    : Result := '(' + f_length + '(FileName) + ' + f_length + '(FilePath)<=' + lValue + ')';
      testEqualTo     : Result := '(' + f_length + '(FileName) + ' + f_length + '(FilePath)='  + lValue + ')';
      testGreaterThan : Result := '(' + f_length + '(FileName) + ' + f_length + '(FilePath)>=' + lValue + ')';
    end;
  end

  else if lParameter = 'CATEGORY' then begin
    case lTest of
      testEqualTo     : Result := '(Category='  + lValue + ')';
      testNotEqualTo  : Result := '(Category!=' + lValue + ')';
    end;
  end

  else if lParameter = 'ATTRIBUTES' then begin
    case StrToIntDef(lValue, FileType_File) of
      FileType_File          : Result := '(Directory=0)';
      FileType_Folder        : Result := '(Directory=1)';
      FileType_Hidden        : Result := '(Hidden=1)';
      FileType_System        : Result := '(System=1)';
      FileType_Archive       : Result := '(Archive=1)';
      FileType_Null          : Result := '(FileSize=0)';
      FileType_ReadOnly      : Result := '(Readonly=1)';
      FileType_CreatedToday  : Result := '(FileDateC=' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + ')';
      FileType_AccessedToday : Result := '(FileDateA=' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + ')';
      FileType_ModifiedToday : Result := '(FileDateM=' + TUtility.GetDate(GETTIMEFORMAT_YYYYMMDD) + ')';
      FileType_Temp          : Result := '(Temp=1)';
    end;

    if lTest = testNotEqualTo then
      Result := StringReplace(Result, '=', '!=', [rfReplaceAll]);
  end

  else if lParameter = 'TOP' then begin
    Result := ''
  end

  else if lParameter = 'BOT' then begin
    Result := '';
  end

  else if lParameter = 'FILE' then begin
    Result := '(FileName LIKE ''%' + UpperCase(lValue) + '%'')';
  end

  else if lParameter = 'EXTENSION' then begin
    Result := '(FilePath LIKE ''%' + UpperCase(lValue) + '%'') OR (FileName LIKE ''%' + UpperCase(lValue) + '%'')';
  end

  else begin
    Result := '(FilePath LIKE ''%' + UpperCase(lValue) + '%'') OR (FileName LIKE ''%' + UpperCase(lValue) + '%'')';
  end;
end;


class function TSearchUtility.ProcessSearchTermToSQLPost(const s : string): string;
 begin
  Assert(s <> '', 'ProcessSearchTermToSQLPost :: blank input');

  Result := '';

  if XSettings.Database.UseODBC then begin
    if Pos('TOP=', s) <> 0 then begin
      Result := ' ORDER BY FileSize DESC';
    end
    else if Pos('CTOP=', s) <> 0 then begin
      Result := ' ORDER BY FileDateC DESC';
    end
    else if Pos('ATOP=', s) <> 0 then begin
      Result := ' ORDER BY FileDateA DESC';
    end
    else if Pos('MTOP=', s) <> 0 then begin
      Result := ' ORDER BY FileDateM DESC';
    end
    else if Pos('BOT=', s) <> 0 then begin
      Result := ' ORDER BY FileSize ASC';
    end;
  end
  else begin
    if Pos('TOP=', s) <> 0 then begin
      Result := ' ORDER BY FileSize DESC LIMIT ' + UpperCase(Copy(s, 5, length(s) - 4));
    end
    else if Pos('CTOP=', s) <> 0 then begin
      Result := ' ORDER BY FileDateC DESC LIMIT ' + UpperCase(Copy(s, 6, length(s) - 5));
    end
    else if Pos('ATOP=', s) <> 0 then begin
      Result := ' ORDER BY FileDateA DESC LIMIT ' + UpperCase(Copy(s, 6, length(s) - 5));
    end
    else if Pos('MTOP=', s) <> 0 then begin
      Result := ' ORDER BY FileDateM DESC LIMIT ' + UpperCase(Copy(s, 6, length(s) - 5));
    end
    else if Pos('BOT=', s) <> 0 then begin
      Result := ' ORDER BY FileSize ASC LIMIT ' + UpperCase(Copy(s, 5, length(s) - 4));
    end;
  end;
end;


class function TSearchUtility.ProcessSearchTermToSQLPostODBC(const s : string): string;
 begin
  Assert(s <> '', 'ProcessSearchTermToSQLPostODBC :: blank input');

  Result := '';

  if Pos('TOP=', s) <> 0 then
    Result := 'TOP ' + UpperCase(Copy(s, 5, length(s) - 4)) + ' '
  else if Pos('CTOP=', s) <> 0 then
    Result := 'TOP ' + UpperCase(Copy(s, 6, length(s) - 5)) + ' '
  else if Pos('ATOP=', s) <> 0 then
    Result := 'TOP ' + UpperCase(Copy(s, 6, length(s) - 5)) + ' '
  else if  Pos('MTOP=', s) <> 0 then
    Result := 'TOP ' + UpperCase(Copy(s, 6, length(s) - 5)) + ' '
  else if Pos('BOT=', s) <> 0 then
    Result := 'TOP ' + UpperCase(Copy(s, 5, length(s) - 4)) + ' ';
end;


class function TSearchUtility.XinorbisSearchToSQL(const xdate, xfolder, xcomputer, xinsearch : string; limitx, limity : integer; demomode : boolean): string;
 var
  SQLTerms : TStringList;
  t : integer;

  procedure GetSearchTerms(const xinsearch2 : string);
   var
    i : integer;
    s : string;
    reading : boolean;
    inside : boolean;

    function AddThisKeyword(const s : string): string;
     var
      ts : string;

     begin
      ts := ProcessSearchTermToSQL(s);

      if ts <> '' then
        SQLTerms.Add(ts);
    end;

   begin
    s       := '';
    reading := False;
    inside  := False;
    SQLTerms.Clear;

    for i := 1 to length(xinsearch2) do begin
      if xinsearch2[i] = '"' then begin
        if reading=False then
          reading := True
        else begin
          reading := False;

          AddThisKeyword(UpperCase(s));
          s := '';
        end;
      end
      else if xinsearch2[i] = '(' then
        inside := True
      else if xinsearch2[i] = ')' then
        inside := False
      else if (xinsearch2[i] = ' ') and not(inside) then begin
        if reading then
          s := s + ' '
        else begin
          if s <> '' then begin
            AddThisKeyword(UpperCase(s));
            s := '';
          end;
        end;
      end
      else begin
        s := s + xinsearch2[i];
      end;
    end;

    if s <> '' then AddThisKeyword(UpperCase(s));
  end;

  procedure GetODBCSpecificPreTerms(const xinsearch2 : string);
   var
    i : integer;
    s : string;
    reading : boolean;
    inside : boolean;

    function AddThisKeyword(const s : string): string;
     var
      ts : string;

     begin
      ts := ProcessSearchTermToSQLPostODBC(s);

      if ts <> '' then
        SQLTerms.Add(ts);
    end;

   begin
    s       := '';
    reading := False;
    inside  := False;
    SQLTerms.Clear;

    for i := 1 to length(xinsearch2) do begin
      if xinsearch2[i] = '"' then begin
        if reading = False then
          reading := True
        else begin
          reading := False;

          AddThisKeyword(UpperCase(s));
          s := '';
        end;
      end
      else if xinsearch2[i] = '(' then
        inside := True
      else if xinsearch2[i] = ')' then
        inside := False
      else if (xinsearch2[i] = ' ') and not(inside) then begin
        if reading then
          s:= S + ' '
        else begin
          if s <> '' then begin
            AddThisKeyword(UpperCase(s));
            s := '';
          end;
        end;
      end
      else begin
        s := s + xinsearch2[i];
      end;
    end;

    if s <> '' then AddThisKeyword(UpperCase(s));
  end;

  procedure GetPostTerms(const xinsearch2 : string);
   var
    i : integer;
    s : string;
    reading : boolean;
    inside : boolean;

    function AddThisKeyword(const s : string): string;
     var
      ts : string;

     begin
      ts := ProcessSearchTermToSQLPost(s);

      if ts <> '' then
        SQLTerms.Add(ts);
    end;

   begin
    s       := '';
    reading := False;
    inside  := False;
    SQLTerms.Clear;

    for i := 1 to length(xinsearch2) do begin
      if xinsearch2[i] = '"' then begin
        if reading = False then
          reading := True
        else begin
          reading := False;

          AddThisKeyword(UpperCase(s));
          s := '';
        end;
      end
      else if xinsearch2[i] = '(' then
        inside := True
      else if xinsearch2[i] = ')' then
        inside := False
      else if (xinsearch2[i] = ' ') and not(inside) then begin
        if reading then
          s := s + ' '
        else begin
          if s <> '' then begin
            AddThisKeyword(UpperCase(s));
            s := '';
          end;
        end;
      end
      else begin
        s := s + xinsearch2[i];
      end;
    end;

    if s <> '' then AddThisKeyword(UpperCase(s));
  end;

 begin
  if xinsearch <> '' then begin

    SQLTerms := TStringList.Create;

    // == now add required fields ==============================================

    Result := 'SELECT ';

    if XSettings.Database.UseODBC then begin
      GetODBCSpecificPreTerms(xinsearch);

      if SQLTerms.Count <> 0 then
        Result := Result + ' ' + SQLTerms[0];
    end;

    // == now add required fields ==============================================

    if demomode then
      Result := Result + ' *'
    else
      Result := Result + ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner';

    // =========================================================================

    Result := Result + ' FROM ';

    // =========================================================================

    if demomode then
      Result := Result + '$x$'
    else
      Result := Result + '"' + TConvert.CreateTableName(xdate, xfolder, xcomputer) + '"';

    // =========================================================================

    GetSearchTerms(xinsearch);

    if SQLTerms.Count <> 0 then begin
      Result := Result + ' WHERE ';

      for t := 0 to SQLTerms.Count - 1 do begin
        Result := Result + SQLTerms[t];

        if t <> SQLTerms.Count - 1 then
          Result := Result + ' AND ';
      end;
    end;

    // ===========================================================================

    GetPostTerms(xinsearch);

    if SQLTerms.Count <> 0 then begin
      Result := Result + ' ' + SQLTerms[0];
    end;

    // ===========================================================================

    SQLTerms.Free;

    if Pos(' LIMIT ', Result) = 0 then begin
      if XSettings.Database.UseODBC then
        Result := Result + ';'
      else
        Result := Result + ' LIMIT ' + IntToStr(limitx) + ', ' + IntToStr(limity) + ';';
    end;

    // ===========================================================================
  end;
end;


class function TSearchUtility.XinorbisSearchAllToSQL(const xdate, xfolder, xcomputer : string; demomode : boolean): string;
 begin
  // == now add required fields ==============================================

  Result := 'SELECT FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner';

  // =========================================================================

  Result := Result + ' FROM ';

  // =========================================================================

  if demomode then
    Result := Result + '$x$'
  else
    Result := Result + '"' + TConvert.CreateTableName(xdate, xfolder, xcomputer) + '"';

  // =========================================================================

  Result := Result + ';'
end;


// format
// lparameter ltest lvalue
// alphanumeric !=<>~ anything
// OR
// #x- #x
//
class procedure TSearchUtility.GetTokens(const aInput : string; var aParameter, aValue : string; var aTest : integer);
var
  lMode : integer;
  lPos : integer;
  lTest : string;
  t : integer;

begin
  aParameter := '';
  aValue     := '';
  aTest      := testEqualTo;
  lTest      := '';

  lMode      := 0;
  lPos       := 1;

  if aInput <> '' then begin

    if aInput[1] = '#' then begin
      aParameter := 'CATEGORY';

      for t:= 1 to CCategoryTermCount do begin
        if Pos('#' + CCategoryTerms[t], aInput) > 0 then begin
          if aInput[length(aInput)] = '-' then
            aTest := testNotEqualTo
          else
            aTest := testEqualTo;

          aValue := IntToStr(CCategoryValues[t]);
        end;
      end;
    end
    else if aInput[1] = '@' then begin
      aParameter := 'ATTRIBUTES';

      for t:= 1 to CTypeTermCount do begin
        if Pos('@' + CTypeTerms[t], aInput) > 0 then begin
          if aInput[length(aInput)] = '-' then
            aTest := testNotEqualTo
          else
            aTest := testEqualTo;

          aValue := IntToStr(CTypeValues[t]);

        end;
      end;
    end
    else begin
      while lPos <= length(aInput) do begin
        case lMode of
          CModeField : begin
                         if TUtility.IsAlphabetCharacter(Ord(aInput[lPos])) then begin
                           aParameter := aParameter + aInput[lPos];

                           inc(lPos);
                         end
                         else
                           lMode := 1;
                       end;
          CModeTest  : begin
                         if TUtility.IsTestCharacter(Ord(aInput[lPos])) then begin
                           lTest := lTest + aInput[lPos];

                           inc(lPos);
                         end
                         else begin
                           if (lTest = '<') or (lTest = '<=') or (lTest = '=<') then
                             aTest := testLessThan
                           else if (lTest = '=') or (lTest = '==') then
                             aTest := testEqualTo
                           else if (lTest = '>') or (lTest = '>=') or (lTest = '=>') then
                             aTest := testGreaterThan
                           else if (lTest = '!=') or (lTest = '<>') then
                             aTest := testNotEqualTo
                           else if (lTest = '~') then
                             aTest := testContains
                           else if (lTest = '!~') or (lTest = '~!') then
                             aTest := testNotContains;

                           lMode := 2;
                         end;
                       end;
          CModeValue : begin
                         aValue := aValue + aInput[lPos];

                         inc(lPos);
                       end;
        end;
      end;
    end;
  end;
end;


end.
