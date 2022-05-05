unit X.PopulateXinfiles;

interface


uses SysUtils, dialogs,

     TMSLogging,

     X.Dialogs.Dialog,

     X.Utility, X.Prescan, X.Constants, X.Global, X.Settings, X.CFileObject, X.FileExtension,
     X.CUserData, X.Conversions, X.GlobalObjects, X.CCSVDataFormat, X.LanguageHandler,
     X.CXinorbisReports;


type
  TPopulate = class
    class function FromXinFilesFromCSV(aDataIndex : integer; aCSVDataFormat : TCSVDataFormat; const aFileName : string): boolean;

    class function FromXinFilesFromReport(aDataIndex : integer; const aFileName : string): boolean;  // .zsr
    class function FromXin2FilesFromReport(aDataIndex : integer; const aFileName : string): boolean; // .zsr2
  private
    class function  GetScanPathFromFolderList(aDataIndex : integer): string;
    class function  GetXin2Section(aInput : string): integer;
    class procedure SetMagnitude(aCategory, aDataIndex : integer; aFileSize : Int64);
  end;


implementation


class procedure TPopulate.SetMagnitude(aCategory, aDataIndex : integer; aFileSize : Int64);
begin
   if aCategory > __FileCategoriesCount then Exit;

   if (aFileSize >= 0) and (aFileSize <= 1024) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  0, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  0, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  0, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  0, 1] + aFileSize;
   end
   else if (aFileSize>1024) and (aFileSize <= (1024 * 1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  1, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  1, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  1, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  1, 1] + aFileSize;
   end
   else if (aFileSize>(1024*1024)) and (aFileSize <= 10 * (1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  2, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  2, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  2, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  2, 1] + aFileSize;
   end
   else if (aFileSize>10*(1024*1024)) and (aFileSize<=50*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  3, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  3, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  3, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  3, 1] + aFileSize;
   end
   else if (aFileSize>50*(1024*1024)) and (aFileSize<=100*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  4, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  4, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  4, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  4, 1] + aFileSize;
   end
   else if (aFileSize>100*(1024*1024)) and (aFileSize<=150*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  5, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  5, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  5, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  5, 1] + aFileSize;
   end
   else if (aFileSize>150*(1024*1024)) and (aFileSize <= 200*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  6, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  6, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  6, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  6, 1] + aFileSize;
   end
   else if (aFileSize>200*(1024*1024)) and (aFileSize<=250*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  7, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  7, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  7, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  7, 1] + aFileSize;
   end
   else if (aFileSize>250*(1024*1024)) and (aFileSize <= 500*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  8, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  8, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  8, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  8, 1] + aFileSize;
   end
   else if (aFileSize>500*(1024*1024)) and (aFileSize<=1000*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  9, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  9, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory,  9, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory,  9, 1] + aFileSize;
   end
   else if (aFileSize > 1000 * (1024 * 1024)) and (aFileSize <= 2000 * (1024 * 1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory, 10, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory, 10, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory, 10, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory, 10, 1] + aFileSize;
   end
   else if (aFileSize > 2000 * (1024 * 1024)) and (aFileSize <= Int64(5000)*(1024*1024)) then begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory, 11, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory, 11, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory, 11, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory, 11, 1] + aFileSize;
   end
   else begin
     GScanDetails[aDataIndex].Magnitude.Data[aCategory, 12, 0] := GScanDetails[aDataIndex].Magnitude.Data[aCategory, 12, 0] + 1;
     GScanDetails[aDataIndex].Magnitude.Data[aCategory, 12, 1] := GScanDetails[aDataIndex].Magnitude.Data[aCategory, 12, 1] + aFileSize;
   end;
end;


class function TPopulate.GetScanPathFromFolderList(aDataIndex : integer): string;
var
  f : string;
  t : integer;

begin
  if GScanDetails[aDataIndex].Folders.Count > 0 then begin
    f := GScanDetails[aDataIndex].Folders[0];

    for t := 1 to GScanDetails[aDataIndex].Folders.Count - 1 do begin
      if length(GScanDetails[aDataIndex].Folders[t]) < length(f) then
        f := GScanDetails[aDataIndex].Folders[t];
    end;

    Result := f;
  end
  else
    Result := 'unknown :(';
end;


class function TPopulate.FromXinFilesFromCSV(aDataIndex : integer; aCSVDataFormat : TCSVDataFormat; const aFileName : string): boolean;
var
  tf : TextFile;
  s,r,fdir,fname : string;
  z,t,i,a : integer;
  xfo : TFileObject;
  tud : TUserData;
  recordcount : integer;
  processthisfield, inquotes : boolean;
  tempString : string;

  function IsValidNumber(const s : string): boolean;
   var
    t : integer;

  begin
   Result := True;

   for t := 1 to length(s) do
     if (ord(s[t]) < 48) or (ord(s[t]) > 57) then
       Result := False;
  end;
  
 begin
  Result := True;

  if FileExists(aFileName) then begin

    GScanDetails[aDataIndex].ClearAll; // to do, maybe need to set MD5 and others

    GScanDetails[aDataIndex].InitNow;

    GScanDetails[aDataIndex].ScanType   := ScanTypeNormal;
    GScanDetails[aDataIndex].ScanSource := ScanSourceFileCSV;
    GScanDetails[aDataIndex].Filename   := aFileName;

    GScanDetails[aDataIndex].ScanPath   := 'unknown :(';

    recordcount := 0;

    AssignFile(tf, aFileName);
    Reset(tf);

    XSettings.Forms.ProgressForm.SetProcessIcon(1);

    while not(eof(tf)) do begin
      Readln(tf, s);

      s := s + ' ';

      if Pos(',', s) <> 0 then begin
        xfo := TFileObject.Create;
        xfo.FileName       := '';
        xfo.FilePathIndex  := 0;
        xfo.FileSize       := 0;
        xfo.FileSizeOnDisk := 0;
        xfo.FileDateC      := TConvert.DateToYYYYMMDDI(Now);
        xfo.FileDateA      := TConvert.DateToYYYYMMDDI(Now);
        xfo.FileDateM      := TConvert.DateToYYYYMMDDI(Now);
        xfo.FileTimeC      := 0;
        xfo.FileTimeA      := 0;
        xfo.FileTimeM      := 0;
        xfo.FileCategory   := 7;
        xfo.Attributes     := 0;
        xfo.Temp           := False;
        xfo.Owner          := 0;

        r := '';
        i := 0;
        processthisfield := False;
        inquotes         := False;

        for t := 1 to length(s) do begin

          case s[t] of
            '"' : begin
                    if inquotes then begin
                      case s[t + 1] of
                        ',' : inquotes := False;
                      else
                        r := r + s[t];
                      end;
                    end
                    else
                      inquotes := not(inquotes);
                  end;
            ',' : begin
                    if not(inquotes) then
                      processthisfield := True;
                  end;
          else
            r := r + s[t];
          end;

          if processthisfield then begin
            if i <= MaxCSVFields then begin
              if not((recordcount = 0) and (aCSVDataFormat.IgnoreFirstRecord)) then begin
                r := Trim(r);

                case aCSVDataFormat.Fields[i] of
                   CFieldIgnore            : {}; // ignore
                   CFieldFullFilePath      : begin
                                               xfo.FileName := ExtractFileName(r);

                                               tempString   := ExtractFilePath(r);

                                               a := GScanDetails[aDataIndex].Folders.IndexOf(tempstring);

                                               if a <> -1 then
                                                 xfo.FilePathIndex := a
                                               else begin
                                                 GScanDetails[aDataIndex].Folders.Add(tempString);
                                                 xfo.FilePathIndex := GScanDetails[aDataIndex].Folders.Count - 1;
                                               end;
                                             end;
                   CFieldFileSizeBytes     : if IsValidNumber(r) then begin
                                               xfo.FileSize := StrToInt64(r);

                                               inc(GScanDetails[aDataIndex].TotalSize, xfo.FileSize);

                                               SetMagnitude(0, aDataIndex, xfo.FileSize);
                                             end
                                             else
                                               xfo.attributes:=xfo.Attributes+faDirectory;
                   CFieldFileSizeOnDIsk    : if IsValidNumber(r) then
                                               xfo.FileSizeOnDisk:=StrToInt64(r);
                   CFieldCreatedDDMMYYYY   : if length(r) = 10 then
                                               xfo.FileDateC := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
                   CFieldCreatedMMDDYYYY   : xfo.FileDateC := TConvert.UStoUKDate(r);
                   CFieldModifiedDDMMYYYY  : if length(r) = 10 then
                                               xfo.FileDateM := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
                   CFieldModifiedMMDDYYYY  : xfo.FileDateM := TConvert.UStoUKDate(r);
                   CFieldAccessedDDMMYYYY  : if length(r) = 10 then
                                               xfo.FileDateA := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
                   CFieldAccessedMMDDYYYY  : xfo.FileDateA := TConvert.UStoUKDate(r);
                  CFieldFilePath           : if r[length(r)] <> '\' then
                                               fdir := r + '\'
                                             else
                                               fdir := r;
                  CFieldFileName           : fname:=r;
                  CFieldOwner              : begin
                                               if XSettings.Optimisations.GetUserDetails then begin
                                                 z := TUtility.FindUserIndex(1, r);
                                                 if z = -1 then begin
                                                   tud      := TUserData.Create;
                                                   tud.Name := r;

                                                   GScanDetails[aDataIndex].Users.Add(tud);

                                                   z := GScanDetails[aDataIndex].Users.Count - 1;
                                                 end;

                                                 xfo.Owner:=z;

                                                 inc(GScanDetails[aDataIndex].Users[z].Data[XUserCount]);
                                                 inc(GScanDetails[aDataIndex].Users[z].Data[XUserSize], xfo.FileSize);
                                               end;
                                             end;
                  CFieldCategory           : if IsValidNumber(r) then begin
                                               xfo.FileCategory := StrToInt(r);

                                               SetMagnitude(xfo.FileCategory, aDataIndex, xfo.FileSize);
                                             end;
                  CFieldReadOnly           : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faReadOnly;
                  CFieldHidden             : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faHidden;
                  CFieldSystem             : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faSysFile;
                  CFieldArchive            : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Attributes := xfo.Attributes + Sysutils.faArchive;
                  CFieldTemp               : if IsValidNumber(r) then
                                               if StrToInt(r) <> 0 then
                                                 xfo.Temp := True;
                  CFieldAttributes         : if IsValidNumber(r) then
                                               xfo.Attributes := StrToInt(r);
                  CFieldCreatedTimeHHMMSS  : if IsValidNumber(r) then
                                               xfo.FileTimeC := StrToInt(r);
                  CFieldModifiedTimeHHMMSS : if IsValidNumber(r) then
                                               xfo.FileTimeA := StrToInt(r);
                  CFieldAccessedTimeHHMMSS : if IsValidNumber(r) then
                                               xfo.FileTimeM := StrToInt(r);
                end;
              end;

              r := '';

              processthisfield := False;
              inquotes         := False;
            end;

            inc(i);
          end;
        end;

        if i <= MaxCSVFields then begin
          if not((recordcount = 0) and (aCSVDataFormat.IgnoreFirstRecord)) then begin
            r := Trim(r);

            case aCSVDataFormat.Fields[i] of
              CFieldIgnore             : {}; // ignore
              CFieldFullFilePath       : begin
                                           xfo.FileName := ExtractFileName(r);

                                           tempString   := ExtractFilePath(r);

                                           a := GScanDetails[aDataIndex].Folders.IndexOf(tempstring);

                                           if a <> -1 then
                                             xfo.FilePathIndex := a
                                           else begin
                                             GScanDetails[aDataIndex].Folders.Add(tempString);
                                             xfo.FilePathIndex := GScanDetails[aDataIndex].Folders.Count - 1;
                                           end;
                                         end;
              CFieldFileSizeBytes      : if IsValidNumber(r) then begin
                                           xfo.FileSize := StrToInt64(r);

                                           if xfo.FileSize > 0 then
                                             inc(GScanDetails[aDataIndex].TotalSize, xfo.FileSize);

                                           //-- now lets put the size into the magnitude section --------------------
                                           SetMagnitude(0, aDataIndex, xfo.FileSize);
                                         end
                                         else
                                           xfo.attributes := xfo.Attributes+faDirectory;
              CFieldFileSizeOnDisk     : if IsValidNumber(r) then
                                           xfo.FileSizeOnDisk := StrToInt64(r);
              CFieldCreatedDDMMYYYY    : if (length(r) = 10) then
                                           xfo.FileDateC := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
              CFieldCreatedMMDDYYYY    : xfo.FileDateC := TConvert.UStoUKDate(r);
              CFieldModifiedDDMMYYYY   : if (length(r) = 10) then
                                           xfo.FileDateM := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
              CFieldModifiedMMDDYYYY   : xfo.FileDateM := TConvert.UStoUKDate(r);
              CFieldAccessedDDMMYYYY   : if (length(r) = 10) then
                                           xfo.FileDateA := StrToInt(r[7] + r[8] + r[9] + r[10] + r[4] + r[5] + r[1] + r[2]);
              CFieldAccessedMMDDYYYY   : xfo.FileDateA := TConvert.UStoUKDate(r);
              CFieldFilePath           : if r[length(r)] <> '\' then
                                          fdir := r + '\'
                                        else
                                          fdir:=r;
              CFieldFileName           : fname:=r;
              CFieldOwner              : begin
                                           if XSettings.Optimisations.GetUserDetails then begin
                                             z := TUtility.FindUserIndex(aDataIndex, r);

                                             if z = -1 then begin
                                               tud      := TUserData.Create;
                                               tud.Name := r;

                                               GScanDetails[aDataIndex].Users.Add(tud);

                                               z := GScanDetails[aDataIndex].Users.Count - 1;
                                             end;

                                             xfo.Owner := z;

                                             inc(GScanDetails[aDataIndex].Users[z].Data[XUserCount]);
                                             inc(GScanDetails[aDataIndex].Users[z].Data[XUserSize], xfo.FileSize);
                                           end;
                                         end;
              CFieldCategory           : if IsValidNumber(r) then begin
                                           xfo.FileCategory := StrToInt(r);

                                           SetMagnitude(xfo.FileCategory, aDataIndex, xfo.FileSize);
                                         end;
              CFieldReadOnly           : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Attributes := xfo.Attributes + Sysutils.faReadOnly;
              CFieldHidden             : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Attributes := xfo.Attributes + faHidden;
              CFieldSystem             : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Attributes := xfo.Attributes + faSysFile;
              CFieldArchive            : if IsValidNumber(r) then
                                           if StrToInt(r) <> 0 then
                                             xfo.Attributes := xfo.Attributes + faArchive;
              CFieldTemp               : if IsValidNumber(r) then
                                          if StrToInt(r) <> 0 then
                                            xfo.Temp := True;
              CFieldAttributes         : if IsValidNumber(r) then
                                           xfo.Attributes := StrToInt(r);
              CFieldCreatedTimeHHMMSS  : if IsValidNumber(r) then
                                           xfo.FileTimeC := StrToInt(r);
              CFieldModifiedTimeHHMMSS : if IsValidNumber(r) then
                                           xfo.FileTimeA := StrToInt(r);
              CFieldAccessedTimeHHMMSS : if IsValidNumber(r) then
                                           xfo.FileTimeM := StrToInt(r);
            end;
          end;
        end;

        if xfo.FileName = '' then
          xfo.FileName := fname;

//        if xfo.FilePath='' then
//          xfo.FilePath:=fdir;

        if not((recordcount = 0) and (aCSVDataFormat.IgnoreFirstRecord)) then
          GScanDetails[aDataIndex].Files.Add(xfo);

        inc(recordcount);
      end;
    end;

    CloseFile(tf);

    GScanDetails[aDataIndex].ScanPath := GetScanPathFromFolderList(aDataIndex);

    if GScanDetails[aDataIndex].Users.Count = 0 then begin
      tud      := TUserData.Create;
      tud.Name := XText[rsNOT_SPECIFIED];

      GScanDetails[aDataIndex].Users.Add(tud);

      GScanDetails[aDataIndex].Users[0].Data[XUserCount] := GScanDetails[aDataIndex].FileCount;
      GScanDetails[aDataIndex].Users[0].Data[XUserSize]  := GScanDetails[aDataIndex].TotalSize;
    end;
  end
  else
    Result := False;
end;


class function TPopulate.FromXinFilesFromReport(aDataIndex : integer; const aFileName : string): boolean;
 var
  str, tempstring : string;
  tf : TextFile;
  xfo : TFileObject;
  detailedmode : boolean;
  a,z : integer;
  tud : TUserData;

  function GetRootFolder(const s : string): string;
   var
    t,ix,zc : integer;

   begin
    Result := '';
    ix := TUtility.CountCharacters(s, '\') - 1;
    zc := 0;
    t  := 1;

    while zc < ix do begin
      Result := Result + s[t];

      if s[t] = '\' then
        inc(zc);

      inc(t);
    end;
  end;

  function GetLastFolder(const s : string): string;
   var
    t : integer;

   begin
    Result := '';
    
    t := length(s) - 1;

    while s[t] <> '\' do begin
      Result := s[t] + Result;

      dec(t);
    end
  end;

begin
  Result := True;

  if FileExists(aFileName) then begin

   GScanDetails[aDataIndex].ScanSource := ScanSourceFileXinNormal;
   GScanDetails[aDataIndex].Filename   := aFileName;

    // ===========================================================================

    AssignFile(tf, aFileName);
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      Result := False;

      TMSLogger.Error('Error <' + IntToStr(IOResult) + '> loading report "' + aFileName + '".')
    end
    else begin
      //read title, but ignore for the moment!
      Readln(tf, str); //title

      if Pos('Report of: ', str) <> 0 then begin    // load v1 file
        if str[1] = 'X' then begin
         GScanDetails[aDataIndex].ScanPath := Copy(str, 13, length(str) - 12);
          detailedmode := True;

         GScanDetails[aDataIndex].ScanSource := ScanSourceFileXinDetailed;
        end
        else begin
          detailedmode := False;
          GScanDetails[aDataIndex].ScanPath := Copy(str, 12, length(str) - 11);
        end;

        Readln(tf, str); //date

        while not(eof(tf)) do begin
          ReadLn(tf, str);

          // =====================================================================

          xfo := TFileObject.Create;
          xfo.FileName       := '';
          xfo.FilePathIndex  := 0;
          xfo.FileSize       := 0;
          xfo.FileSizeOnDisk := 0;
          xfo.FileDateC      := TConvert.DateToYYYYMMDDI(Now);
          xfo.FileDateA      := TConvert.DateToYYYYMMDDI(Now);
          xfo.FileDateM      := TConvert.DateToYYYYMMDDI(Now);
          xfo.FileTimeC      := 0;
          xfo.FileTimeA      := 0;
          xfo.FileTimeM      := 0;
          xfo.FileCategory   := 7;
          xfo.Attributes     := 0;
          xfo.Temp           := False;
          xfo.Owner          := 0;

          // =====================================================================

          if str <> '' then begin
            if str[length(str)] = '\' then begin
              inc(xfo.Attributes, faDirectory);
            end;

            xfo.FileName := ExtractFileName(str);

            tempString   := ExtractFilePath(str);

            a := GScanDetails[aDataIndex].Folders.IndexOf(tempstring);

            if a <> -1 then
              xfo.FilePathIndex := a
            else begin
              GScanDetails[aDataIndex].Folders.Add(tempString);
              xfo.FilePathIndex := GScanDetails[aDataIndex].Folders.Count - 1;
            end;
          end;

          ReadLn(tf, str);
          if StrToInt64(str) >= 0 then begin
            xfo.FileSize       := StrToInt64(str);
            xfo.FileSizeOnDisk := StrToInt64(str);
          end
          else begin
            xfo.FileSize       := 0;
            xfo.FileSizeOnDisk := 0;
          end;

          xfo.FileDateC    := TConvert.DateTimeToInteger(Now);
          xfo.FileDateA    := TConvert.DateTimeToInteger(Now);
          xfo.FileDateM    := TConvert.DateTimeToInteger(Now);

          xfo.FileTimeC    := 0;
          xfo.FileTimeA    := 0;
          xfo.FileTimeM    := 0;

          if detailedmode then begin
            ReadLn(tf, str);
            xfo.FileSizeOnDisk := StrToInt64(str);

            ReadLn(tf, str);
            xfo.FileDateC      := StrToInt(str);

            ReadLn(tf, str);
            xfo.FileDateA      := StrToInt(str);

            ReadLn(tf, str);
            xfo.FileDateM      := StrToInt(str);

            ReadLn(tf, str);
            xfo.FileCategory   := StrToInt(str);

            ReadLn(tf, str);
            if str = '1' then inc(xfo.Attributes, Sysutils.faReadOnly);

            ReadLn(tf, str);
            if str = '1' then inc(xfo.Attributes, Sysutils.faHidden);

            ReadLn(tf, str);
            if str = '1' then inc(xfo.Attributes, Sysutils.faSysFile);

            ReadLn(tf, str);
            if str = '1' then inc(xfo.Attributes, Sysutils.faArchive);

            ReadLn(tf, str);
            xfo.Temp           := TConvert.StringBoolToInteger(str);

            // ===================================================================

            ReadLn(tf, str);

            if str = '' then
              str := XText[rsUnknown];

            z := TUtility.FindUserIndex(1, str);
            if z = -1 then begin
              tud      := TUserData.Create;
              tud.Name := str;

              GScanDetails[aDataIndex].Users.Add(tud);

              z := GScanDetails[aDataIndex].Users.Count - 1;
            end;

            xfo.Owner := z;

            // =====================================================================
          end
          else begin
            xfo.Attributes   := 0;
            xfo.Temp         := False;
            xfo.FileCategory := Category_Other;
            xfo.Owner        := 0;
          end;

          if GScanDetails[aDataIndex].Folders[xfo.FilePathIndex] <> '' then
            GScanDetails[aDataIndex].Files.Add(xfo);
        end;

        CloseFile(tf);

        if not(detailedmode) then
          ShowXDialog('Information', XText[rsReportDetail1] + #13#13 + XText[rsReportDetail2], XDialogTypeInformation);
      end
      else
        ShowXDialog(XText[rsError],
                    XText[rsDialog2],
                    XDialogTypeWarning);
    end;
  end
  else begin
    Result := False;

    TMSLogger.Error('Error report file not found "' + aFileName + '".');
  end;
  {$I+}
end;


class function TPopulate.GetXin2Section(aInput : string): integer;
begin
  Result := Xin2SectionUnknown;

  if Pos('info', aInput) <> 0 then
    Result := Xin2SectionInfo
  else if Pos('folderlist', aInput) <> 0 then
    Result := Xin2SectionFolders
  else if Pos('file', aInput) <> 0 then
    Result := Xin2SectionFile;
end;


class function TPopulate.FromXin2FilesFromReport(aDataIndex : integer; const aFileName : string): boolean;
var
  str : string;
  sectionId, rowIndex : integer;
  tf : TextFile;
  xfo : TFileObject;
  z : integer;
  tud : TUserData;

begin
  Result := True;

  if FileExists(aFileName) then begin

    GScanDetails[aDataIndex].ScanSource := ScanSourceFileXin2Detailed;
    GScanDetails[aDataIndex].Filename   := aFileName;

    // ===========================================================================

    sectionId := -1;
    rowIndex  := 0;

    AssignFile(tf, aFileName);
    {$I-}
    Reset(tf);

    if IOResult <> 0 then begin
      Result := False;

      TMSLogger.Error('Error <' + IntToStr(IOResult) + '> loading report "' + aFileName + '".')
    end
    else begin

      while not(eof(tf)) do begin
        readln(tf, str);

        if str <> '' then begin
          case str[1] of
            '{' : begin
                    sectionId := GetXin2Section(LowerCase(str));

                    rowIndex  := 0;

                    case sectionId of
                      Xin2SectionFile : begin
                                          xfo := TFileObject.Create;
                                          xfo.FileName       := '';
                                          xfo.FilePathIndex  := 0;
                                          xfo.FileSize       := 0;
                                          xfo.FileSizeOnDisk := 0;
                                          xfo.FileDateC      := TConvert.DateToYYYYMMDDI(Now);
                                          xfo.FileDateA      := TConvert.DateToYYYYMMDDI(Now);
                                          xfo.FileDateM      := TConvert.DateToYYYYMMDDI(Now);
                                          xfo.FileTimeC      := 0;
                                          xfo.FileTimeA      := 0;
                                          xfo.FileTimeM      := 0;
                                          xfo.FileCategory   := 7;
                                          xfo.Attributes     := 0;
                                          xfo.Temp           := False;
                                          xfo.Owner          := 0;;
                                        end;
                    end;
                  end;
            '}' : begin
                    case sectionId of
                      Xin2SectionFile : GScanDetails[aDataIndex].Files.Add(xfo);
                    end;

                    sectionId := -1;
                  end;
          else
            case sectionId of
              Xin2SectionInfo    : case rowIndex of
                                     1 : GScanDetails[aDataIndex].ScanPath := str;
                                   end;
              Xin2SectionFolders : GScanDetails[aDataIndex].Folders.Add(str);
              Xin2SectionFile    : case rowIndex of
                                     CRowFileName : xfo.FileName       := str;
                                     CRowFilePathIndex : xfo.FilePathIndex  := StrToInt(str);
                                     CRowSize : xfo.FileSize       := StrToInt64(str);
                                     CRowSizeOnDisk : xfo.FileSizeOnDisk := StrToInt64(str);
                                     CRowDateCreated : xfo.FileDateC      := StrToInt(str);
                                     CRowDateAccessed : xfo.FileDateA      := StrToInt(str);
                                     CRowDateModified : xfo.FileDateM      := StrToInt(str);
                                     CRowTimeCreated : xfo.FileTimeC      := StrToInt(str);
                                     CRowTimeAccessed : xfo.FileTimeA      := StrToInt(str);
                                     CRowTimeModified : xfo.FileTimeM      := StrToInt(str);
                                     CRowCategory : xfo.FileCategory   := StrToInt(str);
                                     CRowReadOnly : {};
                                     CRowHidden : {};
                                     CRowSysFile : {};  // individual attribute flags, not needed
                                     CRowArchive : {};
                                     CRowTemp : {};
                                     CRowOwner : begin
                                            if str = '' then
                                              str := XText[rsUnknown];

                                            z := TUtility.FindUserIndex(1, str);

                                            if z = -1 then begin
                                              tud      := TUserData.Create;
                                              tud.Name := str;

                                              GScanDetails[aDataIndex].Users.Add(tud);

                                              z := GScanDetails[aDataIndex].Users.Count - 1;
                                            end;

                                            xfo.Owner := z;
                                          end;
                                     CRowAttributes : xfo.Attributes     := StrToInt(str);
                                   end;
            end;

            inc(rowIndex);
          end;
        end;
      end;
    end;

    CloseFile(tf);
  end
  else begin
    Result := False;

    TMSLogger.Error('Error report file not found "' + aFileName + '".');
  end;
  {$I+}
end;


end.
