{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Thread.WebReports;

interface

uses
  Classes, StdCtrls, IdFTP, IdComponent,

  X.LanguageHandler, X.SystemGlobal, X.FindFile;

type
  TWebReportsThread = class(TThread)
  private
    FLabel         : TLabel;
    FNavLabel      : TLabel;
    FMemo          : TMemo;
    ftpMain        : TIdFTP;
    FFindFile      : TFindFile;
    FFilelist      : TStringList;
    FTempOutput    : string;
    FCurrentFolder : string;

    procedure BuildWebReportIndex;
    procedure ftpMainStatus(ASender: TObject; const AStatus: TIdStatus; const AStatusText: String);
    procedure ftpMainWork(ASender: TObject; AWorkMode: TWorkMode; AWorkCount: Int64);
    procedure ftpMainWorkBegin(Sender: TObject; AWorkMode: TWorkMode; AWorkCountMax: Int64);
    procedure ftpMainWorkEnd(Sender: TObject; AWorkMode: TWorkMode);

    procedure ffMainFolderChange(const Folder: String);
    procedure ffMainFileMatchWebReportImages(const FileInfo: TFileDetails);
  public
    procedure SetData(aLabel : TLabel; aNavLabel : TLabel; aMemo : TMemo);
  protected
    procedure Execute; override;
  end;


implementation


uses
  Forms, Sysutils, X.Utility,

  X.Dialogs.Dialog,

  X.Conversions, X.Global, X.Settings, X.Constants;


const
  wrms = '&nbsp;|&nbsp;';


procedure TWebReportsThread.SetData(aLabel : TLabel; aNavLabel : TLabel; aMemo : TMemo);
 begin
   FLabel    := aLabel;
   FNavLabel := aNavLabel;
   FMemo     := aMemo;
end;


procedure TWebReportsThread.Execute;
 var
  t, idx, newuploads : integer;
  tf : textfile;
  frag, s : string;

  function FTPFolderExists(folderincurrent : string): boolean;
   var
    z : integer;

   begin
    Result := False;

    for z := 0 to FFilelist.Count - 1 do begin
      if FFilelist.Strings[z][1] = 'd' then
        if pos(' ' + folderincurrent, FFilelist.Strings[z]) <> 0 then
          Result := True;
    end;
  end;

  function FTPFileExists(fileincurrent : string): boolean;
   var
    z : integer;

   begin
    Result := False;

    for z := 0 to FFilelist.Count - 1 do begin
      if FFilelist.Strings[z][1] = '-' then
        if pos(' ' + fileincurrent, FFilelist.Strings[z]) <> 0 then
          Result := True;
    end;
  end;

 begin
  FreeOnTerminate := True;

  FCurrentFolder  := '';

  FTempOutput     := FNavLabel.Caption;

  FFindFile := TFindFile.Create(Application);
  FFilelist := TStringList.Create;
  ftpMain   := TIdFTP.Create(Nil);
  ftpMain.OnStatus    := ftpMainStatus;
  ftpMain.OnWork      := ftpMainWork;
  ftpMain.OnWorkBegin := ftpMainWorkBegin;
  ftpMain.OnWorkEnd   := ftpMainWorkEnd;

  FMemo.Clear;
  FLabel.Visible    := True;
  FLabel.Caption    := '0%';
  FNavLabel.Caption := FTempOutput + ' (0%)';

  // ===========================================================================

  idx := 0;
  for t := 1 to 4 do
    if XSettings.ftpOptions[t] = '' then inc(idx);

  if idx = 0 then begin
    FMemo.Lines.Add(XText[rsBuildingWebReports]);
    FMemo.Lines.Add('');

    BuildWebReportIndex;

    // =========================================================================

    ftpMain.Host     := XSettings.ftpOptions[ftpHost];
    ftpMain.Password := XSettings.ftpOptions[ftpPassword];
    ftpMain.Username := XSettings.ftpOptions[ftpUsername];

    try
      ftpMain.Connect;
    except
    end;

    if ftpMain.Connected then begin
      if XSettings.ftpOptions[ftpInitialFolder] <> '' then
        ftpMain.ChangeDir(XSettings.ftpOptions[ftpInitialFolder]); // this is the FTP site root folder (might be blank)

      // ===========================================================================

      ftpMain.List(FFilelist);

      if Not(FTPFolderExists(XSettings.ftpOptions[ftpRemoteFolder])) then
        ftpMain.MakeDir(XSettings.ftpOptions[ftpRemoteFolder])    // this is the name of the user's report folder
      else
        FMemo.Lines.Add('"' + XSettings.ftpOptions[ftpRemoteFolder] + '" already exists.');

      // ===========================================================================

      if XSettings.ftpOptions[ftpRemoteFolder] <> '' then
        ftpMain.ChangeDir(XSettings.ftpOptions[ftpRemoteFolder]);

      // ===========================================================================

      ftpMain.List(FFileList);

      if Not(FTPFolderExists('data')) then
        ftpMain.MakeDir('data')    // HTML report images
      else
        FMemo.Lines.Add('"data" already exists.');

      ftpMain.ChangeDir('data');

      ftpMain.List(FFilelist);

      FMemo.Lines.Add('');
      FMemo.Lines.Add(XText[rsUploadingHTMLGraphs]);
      FMemo.Lines.Add('');

      FFindFile.Criteria.Files.Location := GSystemGlobal.AppDataPath + 'reports';
      FFindFile.OnFolderChange          := ffMainFolderChange;
      FFindFile.OnFileMatch             := ffMainFileMatchWebReportImages;
      FFindFile.Execute;

      // ===========================================================================
      // ===========================================================================

      ftpMain.ChangeDirUp;

      ftpMain.List(FFilelist);

      newuploads := 0;

      if FileExists(GSystemGlobal.AppDataPath + 'Reports\reportlist.dat') then begin
        AssignFile(tf, GSystemGlobal.AppDataPath + 'Reports\reportlist.dat');
        {$I-}
        Reset(tf);

        if IOResult <> 0 then begin
          FMemo.Lines.Add(XText[rsWarning] + #13#13 + XText[rsErrorOpening] + ' "' + GSystemGlobal.AppDataPath + 'Reports\reportlist.dat".');

//    ShowXDialog(XText[rsWarning], 'Error opening "'+UsersPath+'Reports\reportlist.dat".', XDialogTypeWarning);
        end
        else begin
          while not(eof(tf)) do begin
            Readln(tf, s);

            idx  := 0;
            frag := '';

            for t := 1 to length(s) do begin
              if s[t] = ';' then begin
                case idx of
                  3 : if FileExists(frag) then begin
                        if not(FTPFileExists(ExtractFileName(frag))) then begin
                          FMemo.Lines.Add(XText[rsUploading] + ': ' + frag);
                          ftpMain.Put(frag, ExtractFileName(frag));

                          inc(newuploads);
                        end
                        else
                          FMemo.Lines.Add(XText[rsExists] + ' ' + frag);
                      end;
                end;

                inc(idx);
                frag := '';
              end
              else
                frag := frag + s[t];
            end;

          end;

          CloseFile(tf);
        end;
        {$I+}
      end;

      // ===========================================================================
      // ===========================================================================

      FMemo.Lines.Add('');
      FMemo.Lines.Add(XText[rsUploadingIndexPages]);
      FMemo.Lines.Add('');

      ftpMain.Put(GSystemGlobal.AppDataPath + 'index.htm', 'index.htm');
      ftpMain.Put(GSystemGlobal.AppDataPath + 'fh.htm', 'fh.htm');
      ftpMain.Put(GSystemGlobal.ExePath + 'data\system\webreports\style.css', 'style.css');

      // ===========================================================================
      // ===========================================================================

      FMemo.Lines.Add('New report uploads: ' + IntToStr(newuploads));

      // ===========================================================================
      // ===========================================================================

      ftpMain.Disconnect;
    end
    else
      FMemo.Lines.LoadFromFile(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) + '\text5.dat', TEncoding.UTF8);
  end
  else begin
    FMemo.Lines.LoadFromFile(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) + '\text4.dat', TEncoding.UTF8);
  end;

  FLabel.Visible    := False;

  FNavLabel.Caption := FTempOutput;

  FreeAndNil(FFindFile);
  FreeAndNil(FFilelist);
  FreeAndNil(ftpMain);
end;


procedure TWebReportsThread.BuildWebReportIndex;
 var
  outf : Textfile;
  idx, lastidx, t, z, cx : integer;
  s, frag, cat, cat2, cat3 : string;
  reportslist : TStringList;

 begin
  if FileExists(GSystemGlobal.AppDataPath + 'Reports\reportlist.dat') then begin
    reportslist := TStringList.Create;
    reportslist.LoadFromFile(GSystemGlobal.AppDataPath + 'Reports\reportlist.dat');

    lastidx := -1;

    for z := 0 to reportslist.Count - 1 do begin
      s       := reportslist.strings[z];
      cat     := '';
      idx     := 0;

      for t := 1 to length(s) do begin
         if s[t] = ';' then begin
            case idx of
              0 : begin
                    cat     := frag + ';';
                    lastidx := StrToInt(frag);
                  end;
              1 : cat := frag + ';' + cat;
              2 : begin
                    case lastidx of
                      ReportASCII    : cat2 := 'H';
                      ReportCSV      : cat2 := 'G';
                      ReportHTML     : cat2 := 'F';
                      ReportSummary  : cat2 := 'E';
                      ReportText     : cat2 := 'D';
                      ReportTree     : cat2 := 'C';
                      ReportXinorbis : cat2 := 'B';
                      ReportXML      : cat2 := 'A';
                    end;

                    cat := cat2 + copy(frag, 1, 14) + ';' + cat;
                  end;
              3 : cat := cat + frag + ';';
              4 : cat := cat + frag + ';';
            end;

            inc(idx);
            frag := '';
          end
          else
            frag := frag + s[t];
      end;

      reportslist.strings[z] := cat;
    end;

    reportslist.Sort;
    reportslist.SaveToFile(GSystemGlobal.AppDataPath + 'Reports\reportlistnew.dat');

    // =========================================================================
    // =========================================================================
    // =========================================================================

    AssignFile(outf, GSystemGlobal.AppDataPath + 'index.htm');
    Rewrite(outf);

    Writeln(outf, '<html><head><title>Xinorbis Reports</title><link href="style.css" rel="stylesheet" type="text/css" media="screen" /></head><body class="JF"><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#E1F9FF">');
    Writeln(outf, '<tr><td colspan="4" class="JL">Xinorbis Reports</td></tr><tr><td colspan="4">&nbsp;</td></tr><tr><td width="200" class="JO">&nbsp;&nbsp;' + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + '</td>');
    Writeln(outf, '<td align="center" width="200" bgcolor="#FFFFFF"><b>' + XText[rsFolderScans] + '</b></td><td align="center" width="201" bgcolor="#CCCCCC"><a href="fh.htm">' + XText[rsFolderHistory] + '</a></td><td width="977">&nbsp;</td></tr></table><table width="960" class="JS"><tr><td>&nbsp;</td></tr><tr>&nbsp;<td></td></tr><tr align="center"><td>');
    Writeln(outf, '<a class="m" href="#ascii">ASCII</a>' + wrms + '<a class="m" href="#csv">CSV</a>' + wrms + '<a class="m" href="#html">HTML</a>' + wrms + '<a class="m" href="#text">Text</a>' + wrms + '<a class="m" href="#tree">Tree</a>' + wrms + '<a class="m" href="#xinorbis">Xinorbis</a>' + wrms + '<a class="m" href="#xml">XML</a></td></tr><tr><td>&nbsp;</td></tr><tr><td>&nbsp;</td></tr></table>');

    lastidx := -1;
    cx      := 0;

    for z:=reportslist.count - 1 downto 0 do begin
      s    := reportslist.strings[z];
      idx  := 0;
      frag := '';

      if Pos('\FH_', s) = 0 then begin
        for t := 1 to length(s) do begin
          if s[t] = ';' then begin
            case idx of
              0 : cat2 := TConvert.StrDateToFString(Copy(frag, 2, 8)) + ' ' + frag[10] + frag[11] + ':' + frag[12] + frag[13];
              1 : cat  := frag;
              2 : begin
                    if StrToInt(frag) <> lastidx then begin
                      if lastidx <> -1 then
                        Writeln(outf, '</table>');

                      Writeln(outf, '<table align="center" width="960" class="JF"><tr class="JT"><td colspan="3">');

                      case StrToInt(frag) of
                        ReportASCII    : Writeln(outf, '<a name="ascii">ASCII</td></tr>');
                        ReportCSV      : Writeln(outf, '<a name="csv">CSV</td></tr>');
                        ReportHTML     : Writeln(outf, '<a name="html">HTML</td></tr>');
                        ReportText     : Writeln(outf, '<a name="text">Text</td></tr>');
                        ReportTree     : Writeln(outf, '<a name="tree">Tree</td></tr>');
                        ReportXinorbis : Writeln(outf, '<a name="xinorbis">Xinorbis</td></tr>');
                        ReportXML      : Writeln(outf, '<a name="xml">XML</td></tr>');
                        ReportSummary  : writeln(outf, '<a name="xml">Summary</td></tr>');
                      end;

                      lastidx := StrToInt(frag);
                      cx      := 0;
                    end;
                  end;
              3 : cat3 := frag;
              4 : if FileExists(cat3) then begin
                    if odd(cx) then
                      Writeln(outf, '<tr><td width="100"></td><td width="160">' + cat2 + '</td><td width="700"><a href="' + ExtractFileName(cat3) + '">' + cat + '</a> <span class="JS">(' + frag + ')</span></td></tr>')
                    else
                      Writeln(outf, '<tr bgcolor="#F2F5F9"><td width="100"></td><td width="160">' + cat2 + '</td><td width="700"><a href="' + ExtractFileName(cat3) + '">' + cat + '</a> <span class="JS">(' + frag + ')</span></td></tr>');

                    inc(cx);
                  end;
            end;

            inc(idx);
            frag := '';
          end
          else
            frag := frag + s[t];
        end;
      end;
    end;

    Writeln(outf, '</table><br/><br/><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#EEEEEE" class="JF"><tr><td colspan="4">&nbsp;</td></tr><tr><td width="1578" colspan="4">');
    Writeln(outf, '<div align="center"><a href="http://www.maximumoctopus.com" target="_blank">www.MaximumOctopus.com</a> :: <a href="http://www.Xinorbis.com" target="_blank">www.xinorbis.com</a> :: (c) Paul Alan Freshney ' + TUtility.GetCurrentYear);
    Writeln(outf, '</div></td></tr><tr><td colspan="4">&nbsp;</td></tr>');

    CloseFile(outf);

    // =========================================================================
    // =========================================================================
    // =========================================================================

    AssignFile(outf, GSystemGlobal.AppDataPath + 'fh.htm');
    Rewrite(outf);

    Writeln(outf, '<html><head><title>Xinorbis Reports</title><link href="style.css" rel="stylesheet" type="text/css" media="screen" /></head><body class="JF"><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#E1F9FF">');
    Writeln(outf, '<tr><td colspan="3" class="JL">Xinorbis Reports</td></tr><tr><td colspan="4">&nbsp;</td></tr><tr><td width="200" class="JO">&nbsp;&nbsp;' + TUtility.GetDate(GETTIMEFORMAT_DISPLAY) + '</td>');
    Writeln(outf, '<td align="center" width="200" bgcolor="#CCCCCC"><a href="index.htm">' + XText[rsFolderScans] + '</a></td><td align="center" width="201" bgcolor="#FFFFFF"><b>' + XText[rsFolderHistory] + '</b></td><td width="977">&nbsp;</td></tr></table><table width="960" class="JS"><tr><td>&nbsp;</td></tr><tr>&nbsp;<td></td></tr><tr align="center"><td>');
    Writeln(outf, '<a class="m" href="#ascii">ASCII</a>' + wrms + '<a class="m" href="#csv">CSV</a>' + wrms + '<a class="m" href="#html">HTML</a>' + wrms + '<a class="m" href="#text">Text</a>' + wrms + '<a class="m" href="#tree">Tree</a>' + wrms + '<a class="m" href="#xinorbis">Xinorbis</a>' + wrms + '<a class="m" href="#xml">XML</a></td></tr><tr><td>&nbsp;</td></tr><tr><td>&nbsp;</td></tr></table>');

    lastidx := -1;
    cx      := 0;

    for z := reportslist.Count - 1 downto 0 do begin
      s    := reportslist.strings[z];
      idx  := 0;
      frag := '';

      if Pos('\FH_', s) <> 0 then begin
        for t := 1 to length(s) do begin
          if s[t] = ';' then begin
            case idx of
              0 : cat2 := TConvert.StrDateToFString(Copy(frag, 2, 8)) + ' ' + frag[10] + frag[11] + ':' + frag[12] + frag[13];
              1 : cat  := frag;
              2 : begin
                    if StrToInt(frag) <> lastidx then begin
                      if lastidx <> -1 then
                        Writeln(outf, '</table>');

                      Writeln(outf, '<table align="center" width="960" class="JF"><tr class="JT"><td colspan="3">');

                      case StrToIntDef(frag, -1) of
                        ReportASCII    : Writeln(outf, '<a name="ascii">ASCII</td></tr>');
                        ReportCSV      : Writeln(outf, '<a name="csv">CSV</td></tr>');
                        ReportHTML     : Writeln(outf, '<a name="html">HTML</td></tr>');
                        ReportText     : Writeln(outf, '<a name="text">Text</td></tr>');
                        ReportTree     : Writeln(outf, '<a name="tree">Tree</td></tr>');
                        ReportXinorbis : Writeln(outf, '<a name="xinorbis">Xinorbis</td></tr>');
                        ReportXML      : Writeln(outf, '<a name="xml">XML</td></tr>');
                        ReportSummary  : Writeln(outf, '<a name="xml">Summary</td></tr>');
                      else
                        ShowXDialog('Unknown Report Type',
                                    'Found unknown report type "' + frag + '".',
                                    XDialogTypeInformation);
                      end;

                      lastidx := StrToInt(frag);

                      cx := 0;
                    end;
                  end;
              3 : cat3 := frag;
              4 : if FileExists(cat3) then begin
                    if odd(cx) then
                      Writeln(outf, '<tr><td width="100"></td><td width="160">' + cat2 + '</td><td width="700"><a href="' + ExtractFileName(cat3) + '">' + cat + '</a> <span class="JS">(' + frag + ')</span></td></tr>')
                    else
                      Writeln(outf, '<tr bgcolor="#F2F5F9"><td width="100"></td><td width="160">' + cat2 + '</td><td width="700"><a href="' + ExtractFileName(cat3) + '">' + cat + '</a> <span class="JS">(' + frag + ')</span></td></tr>');

                    inc(cx);
                  end;
            end;

            inc(idx);
            frag := '';
          end
          else
            frag := frag + s[t];
        end;
      end;
    end;

    Writeln(outf, '</table><br/><br/><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#EEEEEE" class="JF"><tr><td colspan="4">&nbsp;</td></tr><tr><td width="1578" colspan="4">');
    Writeln(outf, '<div align="center"><a href="http://www.maximumoctopus.com" target="_blank">www.MaximumOctopus.com</a> :: <a href="http://www.Xinorbis.com" target="_blank">www.xinorbis.com</a> :: (c) Paul Alan Freshney ' + TUtility.GetCurrentYear);
    Writeln(outf, '</div></td></tr><tr><td colspan="4">&nbsp;</td></tr>');

    CloseFile(outf);

    reportslist.Free;
  end;
end;


procedure TWebReportsThread.ftpMainStatus(ASender: TObject; const AStatus: TIdStatus; const AStatusText: String);
 begin
  FMemo.Lines.Add(AStatusText);
end;


procedure TWebReportsThread.ftpMainWorkBegin(Sender: TObject; AWorkMode: TWorkMode; AWorkCountMax: Int64);
 begin
  FLabel.Tag        := AWorkCountMax;
  FLabel.Caption    := '0%';
  FNavLabel.Caption := FTempOutput + ' (0%)';

  FLabel.Refresh;
  FNavLabel.Refresh;
end;


procedure TWebReportsThread.ftpMainWork(ASender: TObject; AWorkMode: TWorkMode; AWorkCount: Int64);
 begin
  if FLabel.Tag <> 0 then begin
    FLabel.Caption    := IntToStr(Round((AWorkCount / FLabel.Tag) * 100)) + '%';
    FNavLabel.Caption := FTempOutput + ' (' + FLabel.Caption + ' )';
  end
  else begin
    FLabel.Caption    := '100%';
    FNavLabel.Caption := FTempOutput + ' (' + FLabel.Caption + ' )';
  end;

  FLabel.Refresh;
  FNavLabel.Refresh
end;


procedure TWebReportsThread.ftpMainWorkEnd(Sender: TObject; AWorkMode: TWorkMode);
 begin
  FLabel.Caption    := '100%';
  FNavLabel.Caption := FTempOutput + ' (100%)';

  FLabel.Refresh;
  FNavLabel.Refresh
end;


procedure TWebReportsThread.ffMainFolderChange(const Folder: String);
 begin
  FCurrentFolder := Folder;
end;


procedure TWebReportsThread.ffMainFileMatchWebReportImages(const FileInfo: TFileDetails);

  function FTPFileExists(const fileincurrent : string): boolean;
   var
    z : integer;

   begin
    Result := False;

    if FFileList.Count > 0 then begin    
      for z := 0 to FFilelist.Count - 1 do begin
        if FFilelist.strings[z][1] = '-' then
          if pos(' ' + fileincurrent, FFilelist.Strings[z]) <> 0 then
            Result := True;
      end;
    end;
  end;

 begin
  if ((Pos('.jpg', FileInfo.Name) <> 0) or (Pos('.png', FileInfo.Name) <> 0)) then begin
    try
      if not(FTPFileExists(fileinfo.name)) then begin
        FMemo.Lines.Add(XText[rsUploading] + ' ' + FCurrentFolder + FileInfo.Name);

        ftpMain.Put(FCurrentFolder + FileInfo.Name, FileInfo.Name)
      end
      else
        FMemo.Lines.Add(XText[rsExists] + ' ' + FCurrentFolder + FileInfo.Name);
    except
    end;
  end;
end;


end.
