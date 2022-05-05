{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Database.Sqlite;

interface


uses
  System.Classes, System.SysUtils, Vcl.ComCtrls, Data.DB, Data.SqlExpr, Data.DbxSqlite,

  TMSLogging,

  AdvGrid, htmltv,

  X.Dialogs.Dialog,

  X.CFileObject, X.Constants, X.CUserData, X.GlobalObjects, X.Settings,

  X.LanguageHandler, X.Conversions, X.Utility, X.Formatting, X.Global, X.ScanDetails, X.CSizeOfFolder,
  X.SystemGlobal;


type
  PNodeData = ^TNodeData;
  TNodeData = record
    FolderID : integer;
  end;

  DBSqlite = class
    class function  CreateEmptyFile(const path : string): boolean;

    class function  DeleteTable(const tablename : string): boolean;
    class procedure GetAllAvailableTables(var aTables : TStringList);
    class function  TableExists(const tablename : string): boolean;

    class function  ExportTableToCSV(const filename, tablename : string): boolean;
    class function  ExportTableToXML(const filename, tablename : string): boolean;

    class function  PopulateGridFromSQL(grid : TAdvStringGrid; const sql : string; option1 : integer; option2 : boolean): TSizeOfFolder;
    class procedure InitialiseTreeWithFolders(const tablename : string; treeview : THTMLTreeView);
    class procedure PopulateTreeFolder(const tablename : string; treeview : THTMLTreeView; node : TTreeNode; folder : string; folderID : integer);
    class procedure PopulateXinFilesFromTable(const tablename : string);
  end;


implementation


const
  fFilePath      = 0;
  fFilePathIndex = 0;
  fFileName      = 1;
  fFileSize      = 2;
  fFileSizeDisk  = 3;
  fFileDateC     = 4;
  fFileDateA     = 5;
  fFileDateM     = 6;
  fCategory      = 7;
  fDirectory     = 8;
  fReadonly      = 9;
  fHidden        = 10;
  fSystem        = 11;
  fArchive       = 12;
  fTemp          = 13;
  fOwner         = 14;


class function DBSqlite.CreateEmptyFile(const path : string): boolean;
var
  f : file;

begin
   Result := False;

  if not(FileExists(path)) then begin

    try
      AssignFile(f, path);
      Rewrite(f);

      CloseFile(f);

      TMSLogger.Info('Sqlite::Created blank file');

      Result := True;
    except
      on e : exception do begin
        TMSLogger.Error('Sqlite::Error creating blank file.');
      end;
    end;
  end;
end;


class function DBSqlite.DeleteTable(const tablename : string): boolean;
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;

begin
  Result := True;

  lSQliteConnection := TSQLConnection.Create(Nil);

  try
    try
      lSQliteConnection.DriverName  := 'Sqlite';
      lSQliteConnection.LoginPrompt := False;
      lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

      lSQliteConnection.Connected   := True;

      lSQliteConnection.Execute('DROP TABLE "' + tablename + '";', nil, lResults);
    except
      on e : exception do begin
        Result := False;

        TMSLogger.Error('Error deleting sql table "' + tablename + '".');
      end;
    end;
  finally
    lSQliteConnection.Connected := False;

    FreeAndNil(lSQliteConnection);
  end;
end;


class procedure DBSqlite.GetAllAvailableTables(var aTables : TStringList);
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;

begin
  aTables := TStringList.Create;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lSQliteConnection.Execute('SELECT name FROM sqlite_master WHERE type=''table'' ORDER BY name;', nil, lResults);

    if not lResults.IsEmpty then begin
      lResults.First;

      while not lResults.Eof do begin
        aTables.Add(lResults.Fields[0].AsString);

        lResults.Next;
      end;
    end;

  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


class function DBSqlite.TableExists(const tablename : string): boolean;
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;

begin
  Assert(tablename <> '', 'TableExists :: Empty table name');

  Result := False;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    try

      lSQliteConnection.Execute('SELECT count(*) FROM sqlite_master WHERE type="table" AND name="' + tablename + '";', nil, lResults);

      if not lResults.IsEmpty then begin
        lResults.First;

        if lResults.Fields[0].AsInteger > 0 then
          Result := True;
      end;

    except
      on e : exception do begin
        Result := False;

        TMSLogger.Error('SQlite::Error getting table list.');
        TMSLogger.Error(e.Message);
      end;
    end;

  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


// =============================================================================
// =============================================================================


class function DBSqlite.ExportTableToCSV(const filename, tablename : string): boolean;
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;
  wp : TextFile;
  s, status : string;

begin
  Result := True;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    try
      lSQliteConnection.Execute('SELECT FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner FROM "' + tablename + '";',
                                nil,
                                lResults);
    except
      Result := False;

      Exit;
    end;

    if not lResults.IsEmpty then begin
      lResults.First;

      AssignFile(wp, filename);

        {$I-}
        Rewrite(wp);

        if IOResult <> 0 then begin
          ShowXDialog(XText[rsErrorSavingReport] + ' (CSV)',
                      XText[rsErrorSaving] + ' "' + FileName + '".',
                      XDialogTypeWarning);
        end
        else begin
          writeln(wp, XText[rsFolder]           + ',' +
                      XText[rsPath]             + ',' +
                      XText[rsFileName]         + ',' +
                      XText[rsSizeOfFilesBytes] + ',' +
                      XText[rsSizeOnDisk]       + ',' +
                      XText[rsCreatedDate]      + ',' +
                      XText[rsAccessedDate]     + ',' +
                      XText[rsModifiedDate]     + ',' +
                      XText[rsCategory]         + ',' +
                      XText[rsFileAttributes]   + ',' +
                      XText[rsOwner]);

          while not lResults.Eof do begin
            if lResults.Fields[fDirectory].AsString = '1' then begin
              s := '"Y",';

              s := s + '"' + TXFormatting.Privacy(lResults.Fields[fFilePath].AsString) + '",';
              s := s + '"' + TXFormatting.Privacy(lResults.Fields[fFileName].AsString) + '",';

              s := s + '"-1",';
              s := s + '"-1",';

              s := s + '"' + TConvert.StrDateToFString(lResults.Fields[fFileDateC].AsString) + '",';
              s := s + '"' + TConvert.StrDateToFString(lResults.Fields[fFileDateA].AsString) + '",';
              s := s + '"' + TConvert.StrDateToFString(lResults.Fields[fFileDateM].AsString) + ' ",';

              s := s + '"' + lResults.Fields[fCategory].AsString + '",';

              status := '------';

              if lResults.Fields[fDirectory].AsString = '1' then status[1] := 'D';
              if lResults.Fields[fReadonly].AsString  = '1' then status[2] := 'R';
              if lResults.Fields[fSystem].AsString    = '1' then status[4] := 'S';
              if lResults.Fields[fHidden].AsString    = '1' then status[3] := 'H';
              if lResults.Fields[fArchive].AsString   = '1' then status[5] := 'A';
              if lResults.Fields[fTemp].AsString      = '1' then status[6] := 'T';

              s := s + '"' + status + '",';

              s := s + '"' + TXFormatting.Privacy(lResults.Fields[fOwner].AsString) + '"';
            end
            else begin
              s := '"N",';

              s := s + '"' + TXFormatting.Privacy(lResults.Fields[fFilePath].AsString) + '",';
              s := s + '"' + TXFormatting.Privacy(lResults.Fields[fFileName].AsString) + '",';

              s := s + '"' + lResults.Fields[fFileSize].AsString + '",';
              s := s + '"' + lResults.Fields[fFileSizeDisk].AsString + '",';

              s := s + '"' + TConvert.StrDateToFString(lResults.Fields[fFileDateC].AsString) + '",';
              s := s + '"' + TConvert.StrDateToFString(lResults.Fields[fFileDateA].AsString) + '",';
              s := s + '"' + TConvert.StrDateToFString(lResults.Fields[fFileDateM].AsString) + '",';

              s := s + '"' + lResults.Fields[fCategory].AsString + '",';

              status := '------';

              if lResults.Fields[fDirectory].AsString = '1' then status[1] := 'D';
              if lResults.Fields[fReadonly].AsString  = '1' then status[2] := 'R';
              if lResults.Fields[fSystem].AsString    = '1' then status[4] := 'S';
              if lResults.Fields[fHidden].AsString    = '1' then status[3] := 'H';
              if lResults.Fields[fArchive].AsString   = '1' then status[5] := 'A';
              if lResults.Fields[fTemp].AsString      = '1' then status[6] := 'T';

              s := s + '"' + status + '",';

              s := s + '"' + TXFormatting.Privacy(lResults.Fields[fOwner].AsString) + '"';
            end;

            writeln(wp, s);

            lResults.Next;
          end;
        end;

        Writeln(wp, '</xinorbisfilelist>');

        CloseFile(wp);
        {$I+}
      end;

  finally
    lSQliteConnection.Connected := False;

    FreeAndNil(lSQliteConnection);
  end;
end;


class function DBSqlite.ExportTableToXML(const filename, tablename : string): boolean;
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;
  wp : TextFile;

begin
  Result := True;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    try
      lSQliteConnection.Execute('SELECT FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner FROM "' + tablename + '";',
                                nil,
                                lResults);
    except
      Result := False;

      Exit;
    end;

    if not lResults.IsEmpty then begin
      lResults.First;

      AssignFile(wp, filename);

      {$I-}
      Rewrite(wp);

      if IOResult <> 0 then begin
        ShowXDialog(XText[rsErrorSaving] + ' (XML)',
                    XText[rsErrorSaving] + ' "' + FileName + '".',
                    XDialogTypeWarning);
      end
      else begin
        Writeln(wp, '<?xml version="1.0"?>');
        Writeln(wp, '<!--  -->');
        Writeln(wp, '<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
        Writeln(wp, '<!-- from SQlite database table: "' + tablename + '" -->');
        Writeln(wp, '<!-- http://www.xinorbis.com  (c) Paul A Freshney ' + TUtility.GetCurrentYear + ' -->');
        Writeln(wp, '<!--  -->');
        Writeln(wp, '<xinorbisfilelist>');

        while not lResults.Eof do begin
          Writeln(wp, '<file>');
          Writeln(wp, TXFormatting.InsertElement('name',            TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(ExtractFilename(lResults.Fields[fFileName].AsString))), 2));
          Writeln(wp, TXFormatting.InsertElement('path',            TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(lResults.Fields[fFilePath].AsString)), 2));
          Writeln(wp, TXFormatting.InsertElement('sizewords',       TConvert.ConvertToUsefulUnit(lResults.Fields[fFileSize].AsLargeInt), 2));
          Writeln(wp, TXFormatting.InsertElement('sizebytes',       lResults.Fields[fFileSize].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('sizeondiskwords', TConvert.ConvertToUsefulUnit(lResults.Fields[fFileSizeDisk].AsLargeInt), 2));
          Writeln(wp, TXFormatting.InsertElement('sizeondiskbytes', lResults.Fields[fFileSizeDisk].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('owner',           TXFormatting.Privacy(lResults.Fields[fOwner].AsString), 2));
          Writeln(wp, TXFormatting.InsertElement('datecreated',     lResults.Fields[fFileDateC].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('dateaccessed',    lResults.Fields[fFileDateA].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('datemodified',    lResults.Fields[fFileDateM].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('category',        lResults.Fields[fCategory].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('directory',       lResults.Fields[fDirectory].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('readonly',        lResults.Fields[fReadonly].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('hidden',          lResults.Fields[fHidden].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('system',          lResults.Fields[fSystem].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('archive',         lResults.Fields[fArchive].AsString, 2));
          Writeln(wp, TXFormatting.InsertElement('temp',            lResults.Fields[fTemp].AsString, 2));
          Writeln(wp, '</file>');

          lResults.Next;
        end;

        Writeln(wp, '</xinorbisfilelist>');

        CloseFile(wp);
        {$I+}
      end;
    end;

  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


// =============================================================================
// =============================================================================


class procedure DBSqlite.InitialiseTreeWithFolders(const tablename : string; treeview : THTMLTreeView);
var
  modernss : boolean;
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;
  t : integer;
  nodeID       : array[0..100] of TTreeNode;
  nodeIDFolder : array[0..100] of string;
  nodeIDPointer: integer;
  NodeDataPtr : PNodeData;

 begin
  Assert(tablename <> '', 'InitialiseTreeWithFolders :: Empty table');

  modernss := TableExists(tablename + 'F');

  treeview.Items.Clear;
  treeview.Items.BeginUpdate;

  // ===========================================================================

  for t := 0 to 100 do begin
    nodeID[t]       := nil;
    nodeIDFolder[t] := '';
  end;

  nodeIDPointer := 0;

  // ===========================================================================

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    if modernss then
      lSQliteConnection.Execute('SELECT FilePath FROM "' + tablename + 'F";',
                                 nil, lResults)
    else
      lSQliteConnection.Execute('SELECT FilePath FROM "' + tablename + '";',
                                 nil, lResults);

    if not lResults.IsEmpty then begin
      lResults.First;

      // ===================================================================

      New(NodeDataPtr);
      NodeDataPtr^.folderID := 0;

      nodeID[nodeIDPointer]       := treeview.Items.AddObjectFirst(Nil, lResults.Fields[0].AsString, NodeDataPtr);
      nodeIDFolder[nodeIDPointer] := lResults.Fields[0].AsString;

      nodeID[nodeIDPointer].ImageIndex    := 3;
      nodeID[nodeIDPointer].SelectedIndex := 3;

      lResults.Next;

      // ===================================================================

      while not lResults.Eof do begin
        for t:=nodeIDPointer downto 0 do begin

          if Pos(nodeIDFolder[t], lResults.Fields[0].AsString) <> 0 then begin
            nodeIDPointer := t + 1;

            New(NodeDataPtr);
            if modernss then
              NodeDataPtr^.folderID := lResults.RecNo         // to do, make sure this works!!
            else
              NodeDataPtr^.folderID := -1;

            nodeID[nodeIDPointer]       := treeview.Items.AddChildObject(nodeID[t], TUtility.LastFolder(lResults.Fields[0].AsString), NodeDataPtr);
            nodeIDFolder[nodeIDPointer] := lResults.Fields[0].AsString;

            treeview.items.addchild(nodeID[nodeIDPointer], '*');

            nodeID[nodeIDPointer].ImageIndex    := 2;
            nodeID[nodeIDPointer].SelectedIndex := 11;

            Break;
          end;
        end;

        lResults.Next;
      end;
    end;
  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;

  treeview.Items.EndUpdate;
end;


class procedure DBSqlite.PopulateTreeFolder(const tablename : string; treeview : THTMLTreeView; node : TTreeNode; folder : string; folderID : integer);
var
  modernss : boolean;
  newnode : TTreeNode;
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;

 begin
  Assert(tablename <> '', 'PopulateTreeFolder :: Empty table');

  modernss := TableExists(tablename + 'F');

  treeview.Items.BeginUpdate;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    if modernss then
      lSQliteConnection.Execute('SELECT FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Readonly, Hidden, System, Archive, Temp, Owner FROM "' + tablename + '" WHERE Directory=0 AND FilePathIdx=' + IntToStr(folderID) + ';',
                                 nil, lResults)
    else
      lSQliteConnection.Execute('SELECT FilePath FROM "' + tablename + '" WHERE FilePath = "' + folder + '";',
                                 nil, lResults);


    if not lResults.IsEmpty then begin
      lResults.First;

      while not lResults.Eof do begin
        newnode := treeview.Items.AddChild(node, lResults.Fields[0].AsString + '   (' + TConvert.ConvertToUsefulUnit(lResults.Fields[1].AsLargeInt) + ')');

        newnode.ImageIndex    := -1;
        newnode.SelectedIndex := -1;

        lResults.Next;
      end;
    end;
  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;

  // ===========================================================================

  if node.Item[0].Text = '*' then
    node.Item[0].Delete;

  // ===========================================================================

  treeview.Items.EndUpdate;
end;


class procedure DBSqlite.PopulateXinFilesFromTable(const tablename : string);
 var
  tfo : TFileObject;
  z,a : integer;
  tud : TUserData;
  modernss : boolean;
  tempString : string;
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;

begin
  Assert(tablename <> '', 'PopulateXinFilesFromTable :: Empty table');

  modernss := TableExists(tablename + 'F');

  GScanDetails[dataFolderHistory].Folders.Clear;
  GScanDetails[dataFolderHistory].Files.Clear;

  // =========================================================================
  // == build folder data ====================================================
  // =========================================================================

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lSQliteConnection.Execute('SELECT FilePath FROM "' + tablename + 'F";', nil, lResults);

    if not lResults.IsEmpty then begin
      lResults.First;

      while not lResults.Eof do begin
        GScanDetails[dataFolderHistory].Folders.Add(lResults.Fields[0].AsString);

        lResults.Next;
      end;
    end;
  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;

  // =========================================================================
  // == build file data ======================================================
  // =========================================================================

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lSQliteConnection.Execute('SELECT FilePathIdx, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner FROM "' + tablename + '";',
                              nil,
                              lResults);

    if not lResults.IsEmpty then begin
      lResults.First;

      while not lResults.Eof do begin
        tfo := TFileObject.Create;

        tfo.Filename       := lResults.Fields[fFileName].AsString;

        if modernss then
          tfo.FilePathIndex  := lResults.Fields[fFilePathIndex].AsInteger
        else begin
          tempString         := lResults.Fields[fFilePath].AsString;

          a := GScanDetails[dataFolderHistory].Folders.IndexOf(tempstring);

          if a <> -1 then
            tfo.FilePathIndex := a
          else begin
            GScanDetails[dataFolderHistory].Folders.Add(tempString);
            tfo.FilePathIndex := GScanDetails[dataFolderHistory].Folders.Count - 1;
          end;
        end;

        tfo.FileSize       := lResults.Fields[fFileSize].AsLargeInt;
        tfo.FileSizeOnDisk := lResults.Fields[fFileSizeDisk].AsLargeInt;

        tfo.FileDateC      := lResults.Fields[fFileDateC].AsInteger;
        tfo.FileDateA      := lResults.Fields[fFileDateA].AsInteger;
        tfo.FileDateM      := lResults.Fields[fFileDateM].AsInteger;

        tfo.FileCategory   := lResults.Fields[fCategory].AsInteger;

        tfo.Attributes     := 0;

        if lResults.Fields[fDirectory].AsString = '1' then
          inc(tfo.Attributes, System.SysUtils.faDirectory);

        if lResults.Fields[fReadonly].AsString = '1' then
          inc(tfo.Attributes, System.SysUtils.faReadOnly);

        if lResults.Fields[fHidden].AsString = '1' then
          inc(tfo.Attributes, System.SysUtils.faHidden);

        if lResults.Fields[fSystem].AsString = '1' then
          inc(tfo.Attributes, System.SysUtils.faSysFile);

        if lResults.Fields[fArchive].AsString = '1' then
          inc(tfo.Attributes, System.SysUtils.faArchive);

        if lResults.Fields[fTemp].AsString = '1' then
          tfo.Temp := True
        else
          tfo.Temp := False;

        if XSettings.Optimisations.GetUserDetails then begin
          z := TUtility.FindUserIndex(dataFolderHistory, lResults.Fields[fOwner].AsString);

          if z = -1 then begin
            tud      := TUserData.Create;
            tud.Name := lResults.Fields[fOwner].AsString;

            GScanDetails[dataFolderHistory].Users.Add(tud);

            z := GScanDetails[dataFolderHistory].Users.Count - 1;

            inc(GScanDetails[dataFolderHistory].Users[z].Data[XUserCount]);
            inc(GScanDetails[dataFolderHistory].Users[z].Data[XUserSize], tfo.FileSize);
          end;
        end
        else
          z := 0;

        tfo.Owner := z;

        // ===================================================================

        GScanDetails[dataFolderHistory].Files.Add(tfo);

        if GScanDetails[dataFolderHistory].Files.Count mod 5000 = 0 then begin
//          Application.ProcessMessages;
        end;

        lResults.Next;
      end;
    end;
  finally
    lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);
  end;
end;


class function DBSqlite.PopulateGridFromSQL(grid : TAdvStringGrid; const sql : string; option1 : integer; option2 : boolean): TSizeOfFolder;
var
  lSQliteConnection : TSQLConnection;
  lResults : TDataSet;
  status : string;

  begin
  Assert(grid <> nil, 'PopulateGridFromSQL :: Nil grid');

  grid.ClearRows(1, grid.RowCount - 1);
  grid.RowCount := 2;

  Result.Data[XFileCount]   := 0;
  Result.Data[XFolderCount] := 0;
  Result.Data[XFileSize]    := 0;

  lSQliteConnection := TSQLConnection.Create(Nil);

  lSQliteConnection.DriverName  := 'Sqlite';
  lSQliteConnection.LoginPrompt := False;
  lSQliteConnection.Params.Add('Database=' + GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db');

  try
    lSQliteConnection.Connected := True;

    lSQliteConnection.Execute(sql, nil, lResults);

    if not lResults.IsEmpty then begin
      lResults.First;

      while not lResults.Eof do begin
        if option2 then
            grid.Cells[FHschFilename, grid.RowCount - 1] := lResults.Fields[fFilePath].AsString + lResults.Fields[fFileName].AsString
          else
            grid.Cells[FHschFilename, grid.RowCount - 1] := lResults.Fields[fFileName].AsString;

          if lResults.Fields[fDirectory].AsString = '1' then
            grid.Cells[FHschSize, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
          else
            grid.Cells[FHschSize, grid.RowCount - 1] := TConvert.GetSizeString(option1, StrToInt64(lResults.Fields[fFileSize].AsString));

          if lResults.Fields[fDirectory].AsString = '1' then
            grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
          else
            grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := TConvert.GetSizeString(option1, StrToInt64(lResults.Fields[fFileSizeDisk].AsString));

          grid.Cells[FHschCreated, grid.RowCount - 1]  := TConvert.StrDateToFString(lResults.Fields[fFileDateC].AsString);
          grid.Cells[FHschAccessed, grid.RowCount - 1] := TConvert.StrDateToFString(lResults.Fields[fFileDateA].AsString);
          grid.Cells[FHschModified, grid.RowCount - 1] := TConvert.StrDateToFString(lResults.Fields[fFileDateM].AsString);
          grid.Cells[FHschOwner, grid.RowCount - 1]    := lResults.Fields[fOwner].AsString;

          status := '------';

          if lResults.Fields[fDirectory].AsString = '1' then status[1] := 'D';
          if lResults.Fields[fReadonly].AsString  = '1' then status[2] := 'R';
          if lResults.Fields[fHidden].AsString    = '1' then status[3] := 'H';
          if lResults.Fields[fSystem].AsString    = '1' then status[4] := 'S';
          if lResults.Fields[fArchive].AsString   = '1' then status[5] := 'A';
          if lResults.Fields[fTemp].AsString      = '1' then status[6] := 'T';

          grid.Cells[FHschStatus, grid.RowCount - 1]   := status;

          grid.Cells[FHschCategory, grid.RowCount - 1] := lResults.Fields[fCategory].AsString;

          if lResults.Fields[fDirectory].AsString = '1' then
            grid.Cells[FHschSortSize,       grid.RowCount - 1] := '-1'
          else
            grid.Cells[FHschSortSize,       grid.RowCount - 1] := lResults.Fields[fFileSize].AsString;

          grid.Cells[FHschSortSizeOnDisk, grid.RowCount - 1] := lResults.Fields[fFileSizeDisk].AsString;
          grid.Cells[FHschSortCreated,    grid.RowCount - 1] := lResults.Fields[fFileDateC].AsString;
          grid.Cells[FHschSortAccessed,   grid.RowCount - 1] := lResults.Fields[fFileDateA].AsString;
          grid.Cells[FHschSortModified,   grid.RowCount - 1] := lResults.Fields[fFileDateM].AsString;

          inc(Result.Data[XFileSize], lResults.Fields[fFileSize].AsLargeInt);

          if lResults.Fields[fDirectory].AsString = '1' then // is folder
            inc(Result.Data[XFolderCount])
          else
            inc(Result.Data[XFileCount]);

          grid.RowCount := grid.RowCount + 1;

        lResults.Next;
      end;
    end;

  finally
   lSQliteConnection.Connected := False;
    FreeAndNil(lSQliteConnection);

    if (Result.Data[XFolderCount]) + (Result.Data[XFileCount]) > 0 then
      grid.RowCount := grid.RowCount - 1;
  end;
end;


end.
