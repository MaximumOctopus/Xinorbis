{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.Database.ODBC;

interface


uses
  System.Classes, System.SysUtils, Vcl.ComCtrls, ADODB, AdvGrid, htmltv,

  X.Dialogs.Dialog,

  X.CFileObject, X.Constants, X.CUserData, X.Settings, X.GlobalObjects, X.CSizeOfFolder,

  X.LanguageHandler, X.Utility, X.Formatting, X.Global, X.Conversions;


type
  PNodeData = ^TNodeData;
  TNodeData = record
    FolderID : integer;
  end;

  DBODBC = class
    class procedure DeleteTable(const tablename : string);
    class function  TableExists(const tablename : string): boolean;

    class function  ExportTableToCSV(const filename, tablename : string): boolean;
    class function  ExportTableToXML(const filename, tablename : string): boolean;

    class function  PopulateGridFromSQL(grid : TAdvStringGrid; const sql : string; option1 : integer; option2 : boolean): TSizeOfFolder;
    class procedure InitialiseTreeWithFolders(const tablename : string; treeview : THTMLTreeView);
    class procedure PopulateTreeFolder(const tablename : string; treeview : THTMLTreeView; node : TTreeNode; folder : string; folderID : integer);
    class procedure PopulateXinFilesFromTable(const tablename : string);
  end;


var
  XODBC    : TADOConnection;


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



class procedure DBODBC.DeleteTable(const tablename : string);
begin
  {}
end;


class function DBODBC.TableExists(const tablename : string): boolean;
var
  lTables : TStringList;
  t : integer;

begin
  Assert(tablename <> '', 'TableExists :: Empty table name');

  Result := False;

  lTables := TStringList.Create;

  try
    XODBC.GetTableNames(lTables, False);

    if lTables.Count <> 0 then begin
      for t := 0 to lTables.Count - 1 do begin
        if lTables.Strings[t] = tablename then begin
          Result := True;

          Break;
        end;
      end;
    end;
  finally
    lTables.Free;
  end;
end;


// =============================================================================
// =============================================================================


class function DBODBC.ExportTableToCSV(const filename, tablename : string): boolean;
var
  status, s : string;
  tf : TextFile;
  XQuery : TADOQuery;

begin
  Result := True;

  XQuery := TADOQuery.Create(nil);

  try
    XQuery.Connection := XODBC;
    XQuery.SQL.Add('SELECT * FROM "' + tablename + '"');
    XQuery.Open;

    AssignFile(tf, filename);

    {$I-}
    Rewrite(tf);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorSavingReport] + ' (CSV)',
                  XText[rsErrorSaving] + ' "' + FileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      writeln(tf, XText[rsFolder] + ',' +
                  XText[rsPath] + ',' +
                  XText[rsFileName] + ',' +
                  XText[rsSizeOfFilesBytes] + ',' +
                  XText[rsSizeOnDisk] + ',' +
                  XText[rsCreatedDate] + ',' +
                  XText[rsAccessedDate] + ',' +
                  XText[rsModifiedDate] + ',' +
                  XText[rsCategory] + ',' +
                  XText[rsFileAttributes] + ',' +
                  XText[rsOwner]);

      while not XQuery.eof do begin
        if XQuery.FieldByName('Directory').AsInteger = 1 then begin
          s := '"Y",';

          s := s + '"' + TXFormatting.Privacy(XQuery.FieldByName('FilePath').AsString) + '",';
          s := s + '"' + TXFormatting.Privacy(XQuery.FieldByName('FileName').AsString) + '",';

          s := s + '"-1",';
          s := s + '"-1",';

          s := s + '"' + TConvert.StrDateToFString(XQuery.FieldByName('FileDateC').AsString) + '",';
          s := s + '"' + TConvert.StrDateToFString(XQuery.FieldByName('FileDateA').AsString) + '",';
          s := s + '"' + TConvert.StrDateToFString(XQuery.FieldByName('FileDateM').AsString) + '",';

          s := s + '"' + XQuery.FieldByName('Category').AsString + '",';

          status := '------';

          if XQuery.FieldByName('Directory').AsInteger = 1 then status[1] := 'D';
          if XQuery.FieldByName('Readonly').AsInteger = 1  then status[2] := 'R';
          if XQuery.FieldByName('System').AsInteger = 1    then status[4] := 'S';
          if XQuery.FieldByName('Hidden').AsInteger = 1    then status[3] := 'H';
          if XQuery.FieldByName('Archive').AsInteger = 1   then status[5] := 'A';
          if XQuery.FieldByName('Temp').AsInteger = 1      then status[6] := 'T';

          s := s + '"' + status + '",';

          s := s + '"' + TXFormatting.Privacy(XQuery.FieldByName('Owner').AsString) + '"';
        end
        else begin
          s := '"N",';

          s := s + '"' + TXFormatting.Privacy(XQuery.FieldByName('FilePath').AsString) + '",';
          s := s + '"' + TXFormatting.Privacy(XQuery.FieldByName('FileName').AsString) + '",';

          s := s + '"' + XQuery.FieldByName('FileSize').AsString + '",';
          s := s + '"' + XQuery.FieldByName('FileSizeDisk').AsString + '",';

          s := s + '"' + TConvert.StrDateToFString(XQuery.FieldByName('FileDateC').AsString) + '",';
          s := s + '"' + TConvert.StrDateToFString(XQuery.FieldByName('FileDateA').AsString) + '",';
          s := s + '"' + TConvert.StrDateToFString(XQuery.FieldByName('FileDateM').AsString) + '",';

          s := s + '"' + XQuery.FieldByName('Category').AsString + '",';

          status := '------';

          if XQuery.FieldByName('Directory').AsInteger = 1 then status[1] := 'D';
          if XQuery.FieldByName('Readonly').AsInteger = 1  then status[2] := 'R';
          if XQuery.FieldByName('System').AsInteger = 1    then status[4] := 'S';
          if XQuery.FieldByName('Hidden').AsInteger = 1    then status[3] := 'H';
          if XQuery.FieldByName('Archive').AsInteger = 1   then status[5] := 'A';
          if XQuery.FieldByName('Temp').AsInteger = 1      then status[6] := 'T';

          s := s + '"' + status + '",';

          s := s + '"' + TXFormatting.Privacy(XQuery.FieldByName('Owner').AsString) + '"';
        end;

        writeln(tf, s);

        XQuery.Next;
      end;

      CloseFile(tf);
    end;
   {$I+}

  finally
    XQuery.Free;
  end;
end;


class function DBODBC.ExportTableToXML(const filename, tablename : string): boolean;
var
  wp : TextFile;
  XQuery : TADOQuery;

begin
  Result := True;

  XQuery := TADOQuery.Create(nil);

  try
    XQuery.Connection := XODBC;
    XQuery.SQL.Add('SELECT * FROM "' + tablename + '"');
    XQuery.Open;

    AssignFile(wp, filename);

    {$I-}
    Rewrite(wp);

    if IOResult <> 0 then begin
      ShowXDialog(XText[rsErrorSavingReport] + ' (XML)',
                  XText[rsErrorSaving] + ' "' + FileName + '".',
                  XDialogTypeWarning);
    end
    else begin
      Writeln(wp, '<?xml version="1.0"?>');
      Writeln(wp, '<!--  -->');
      Writeln(wp, '<!-- generated with Xinorbis ' + x8Title + ' - ' + x8Date + ' -->');
      Writeln(wp, '<!-- from ODBC database table: "' + tablename + '" -->');
      Writeln(wp, '<!-- http://www.xinorbis.com (c) Paul A Freshney ' + TUtility.GetCurrentYear + ' -->');
      Writeln(wp, '<!--  -->');
      Writeln(wp, '<xinorbisfilelist>');

      while not XQuery.eof do begin
        Writeln(wp, '<file>');
        Writeln(wp, TXFormatting.InsertElement('name',            TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(ExtractFilename(XQuery.FieldByName('FileName').AsString))), 2));
        Writeln(wp, TXFormatting.InsertElement('path',            TXFormatting.ReplaceEntitiesForXML(TXFormatting.Privacy(XQuery.FieldByName('FilePath').AsString)), 2));
        Writeln(wp, TXFormatting.InsertElement('sizewords',       TConvert.ConvertToUsefulUnit(StrToInt64(XQuery.FieldByName('FileSize').AsString)), 2));
        Writeln(wp, TXFormatting.InsertElement('sizebytes',       XQuery.FieldByName('FileSize').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('sizeondiskwords', TConvert.ConvertToUsefulUnit(StrToInt64(XQuery.FieldByName('FileSizeDisk').AsString)), 2));
        Writeln(wp, TXFormatting.InsertElement('sizeondiskbytes', XQuery.FieldByName('FileSizeDisk').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('owner',           TXFormatting.Privacy(XQuery.FieldByName('Owner').AsString), 2));
        Writeln(wp, TXFormatting.InsertElement('datecreated',     XQuery.FieldByName('FileDateC').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('dateaccessed',    XQuery.FieldByName('FileDateA').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('datemodified',    XQuery.FieldByName('FileDateM').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('category',        XQuery.FieldByName('Category').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('directory',       XQuery.FieldByName('Directory').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('readonly',        XQuery.FieldByName('Readonly').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('hidden',          XQuery.FieldByName('Hidden').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('system',          XQuery.FieldByName('System').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('archive',         XQuery.FieldByName('Archive').AsString, 2));
        Writeln(wp, TXFormatting.InsertElement('temp',            XQuery.FieldByName('Temp').AsString, 2));
        Writeln(wp, '</file>');

        XQuery.Next;
      end;

      Writeln(wp, '</xinorbisfilelist>');

      CloseFile(wp);
    end;
    {$I+}

  finally
    XQuery.Free;
  end;
end;


// =============================================================================
// =============================================================================


class procedure DBODBC.InitialiseTreeWithFolders(const tablename : string; treeview : THTMLTreeView);
var
  XQuery : TADOQuery;
  modernss : boolean;
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

  XQuery := TADOQuery.Create(nil);

  try
    XQuery.Connection := XODBC;

    XQuery := TADOQuery.Create(nil);
    XQuery.Connection := XODBC;

    if modernss then
      XQuery.SQL.Add('SELECT FilePath FROM "' + tablename + 'F"')
    else
      XQuery.SQL.Add('SELECT FilePath FROM "'  +tablename + '"');

    XQuery.Open;

    // ===================================================================

    New(NodeDataPtr);
    NodeDataPtr^.folderID := 0;

    nodeID[nodeIDPointer]       := treeview.Items.AddObjectFirst(Nil, XQuery.Fields[0].AsString, NodeDataPtr);
    nodeIDFolder[nodeIDPointer] := XQuery.Fields[0].AsString;

    nodeID[nodeIDPointer].ImageIndex    := 3;
    nodeID[nodeIDPointer].SelectedIndex := 3;

    XQuery.Next;

    // ===================================================================

    while not XQuery.eof do begin
      for t:=nodeIDPointer downto 0 do begin
        if Pos(nodeIDFolder[t], XQuery.Fields[0].AsString) <> 0 then begin
          nodeIDPointer := t + 1;

          New(NodeDataPtr);
          if modernss then
            NodeDataPtr^.folderID := XQuery.RecNo
          else
            NodeDataPtr^.folderID := -1;

          nodeID[nodeIDPointer]       := treeview.Items.AddChildObject(nodeID[t], TUtility.LastFolder(XQuery.Fields[0].AsString), NodeDataPtr);

          nodeIDFolder[nodeIDPointer] := XQuery.Fields[0].AsString;

          treeview.items.addchild(nodeID[nodeIDPointer], '*');

          nodeID[nodeIDPointer].ImageIndex    := 2;
          nodeID[nodeIDPointer].SelectedIndex := 11;

          Break;
        end;
      end;

      XQuery.Next;
    end;
  finally
    XQuery.Free;
  end;

  treeview.Items.EndUpdate;
end;


class procedure DBODBC.PopulateTreeFolder(const tablename : string; treeview : THTMLTreeView; node : TTreeNode; folder : string; folderID : integer);
var
  XQuery : TADOQuery;
  modernss : boolean;
  newnode : TTreeNode;

begin
  Assert(tablename <> '', 'PopulateTreeFolder :: Empty table');

  modernss := TableExists(tablename + 'F');

  treeview.Items.BeginUpdate;

  // ===========================================================================

  XQuery := TADOQuery.Create(nil);

  try
    XQuery.Connection := XODBC;

    XQuery := TADOQuery.Create(nil);
    XQuery.Connection := XODBC;

    if modernss then
      XQuery.SQL.Add('SELECT FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Readonly, Hidden, System, Archive, Temp, Owner FROM "' + tablename + '" WHERE Directory=0 AND FilePathIdx=' + IntToStr(folderID) + ';')
    else
      XQuery.SQL.Add('SELECT FilePath FROM "' + tablename + '" WHERE FilePath = "' + folder + '";');

    XQuery.Open;

    while not XQuery.eof do begin
      newnode := treeview.Items.AddChild(node, XQuery.Fields[0].AsString + '   (' + TConvert.ConvertToUsefulUnit(StrToInt64(XQuery.Fields[1].AsString)) + ')');

        newnode.ImageIndex    := -1;
        newnode.SelectedIndex := -1;

      XQuery.Next;
    end;
  finally
    XQuery.Free;
  end;

  // ===========================================================================

  if node.Item[0].Text = '*' then
    node.Item[0].Delete;

  // ===========================================================================

  treeview.Items.EndUpdate;
end;


class function DBODBC.PopulateGridFromSQL(grid : TAdvStringGrid; const sql : string; option1 : integer; option2 : boolean): TSizeOfFolder;
var
  status : string;
  XQuery : TADOQuery;

 begin
  Assert(grid <> nil, 'PopulateGridFromSQL :: Nil grid');

  grid.ClearRows(1, grid.RowCount - 1);
  grid.RowCount := 2;

  Result.Data[XFileCount]   := 0;
  Result.Data[XFolderCount] := 0;
  Result.Data[XFileSize]    := 0;

  XQuery := TADOQuery.Create(nil);

  try
    XQuery.Connection := XODBC;
    XQuery.SQL.Add(sql);
    XQuery.Open;

    while not XQuery.eof do begin
      if option2 then
        grid.Cells[FHschFilename, grid.RowCount - 1] := XQuery.FieldByName('FilePath').AsString+XQuery.FieldByname('FileName').AsString
      else
        grid.Cells[FHschFilename, grid.RowCount - 1] := XQuery.FieldByName('FileName').AsString;

      if XQuery.FieldByname('Directory').AsString = '1' then
        grid.Cells[FHschSize, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
      else
        grid.Cells[FHschSize, grid.RowCount - 1] := TConvert.GetSizeString(option1, StrToInt64(XQuery.FieldByName('FileSize').AsString));

      if XQuery.FieldByname('Directory').AsString = '1' then
        grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := ' ' + UpperCase(XText[rsFolder])
      else
        grid.Cells[FHschSizeOnDisk, grid.RowCount - 1] := TConvert.GetSizeString(option1, StrToInt64(XQuery.FieldByName('FileSize').AsString));

      grid.Cells[FHschCreated, grid.RowCount - 1]  := TConvert.StrDateToFString(XQuery.FieldByName('FileDateC').AsString);
      grid.Cells[FHschAccessed, grid.RowCount - 1] := TConvert.StrDateToFString(XQuery.FieldByName('FileDateA').AsString);
      grid.Cells[FHschModified, grid.RowCount - 1] := TConvert.StrDateToFString(XQuery.FieldByName('FileDateM').AsString);
      grid.Cells[FHschOwner, grid.RowCount - 1]    := XQuery.FieldByName('Owner').AsString;

      status := '------';

      if XQuery.FieldByname('Directory').AsInteger = 1 then status[1] := 'D';
      if XQuery.FieldByname('Readonly').AsInteger = 1  then status[2] := 'R';
      if XQuery.FieldByname('Hidden').AsInteger = 1    then status[3] := 'H';
      if XQuery.FieldByname('System').AsInteger = 1    then status[4] := 'S';
      if XQuery.FieldByname('Archive').AsInteger = 1   then status[5] := 'A';
      if XQuery.FieldByname('Temp').AsInteger = 1      then status[6] := 'T';

      grid.Cells[FHschStatus, grid.RowCount - 1]   := status;

      grid.Cells[FHschCategory, grid.RowCount - 1] := XQuery.FieldByname('Category').AsString;

      if XQuery.FieldByName('Directory').AsInteger = 1 then
        grid.Cells[FHschSortSize,       grid.RowCount - 1] := '-1'
      else
        grid.Cells[FHschSortSize,       grid.RowCount - 1] := XQuery.FieldByname('FileSize').AsString;

      grid.Cells[FHschSortSizeOnDisk, grid.RowCount - 1] := XQuery.FieldByname('FileSizeDisk').AsString;
      grid.Cells[FHschSortCreated,    grid.RowCount - 1] := XQuery.FieldByname('FileDateC').AsString;
      grid.Cells[FHschSortAccessed,   grid.RowCount - 1] := XQuery.FieldByname('FileDateA').AsString;
      grid.Cells[FHschSortModified,   grid.RowCount - 1] := XQuery.FieldByname('FileDateM').AsString;

      inc(Result.Data[XFileSize], StrToInt64(XQuery.FieldByName('FileSize').AsString));

      if XQuery.FieldByname('Directory').AsInteger = 1 then // is folder
        inc(Result.Data[XFolderCount])
      else
        inc(Result.Data[XFileCount]);

      grid.RowCount := grid.RowCount + 1;

      XQuery.Next;
    end;
  finally
    XQuery.Free;

    if (Result.Data[XFolderCount]) +(Result.Data[XFileCount]) > 0 then
      grid.RowCount := grid.RowCount - 1;
  end;
end;


class procedure DBODBC.PopulateXinFilesFromTable(const tablename : string);
var
  tfo : TFileObject;
  XQuery : TADOQuery;
  z,a : integer;
  tud : TUserData;
  modernss : boolean;
  tempString : string;

begin
  Assert(tablename <> '', 'PopulateXinFilesFromTable :: Empty table');

  modernss := TableExists(tablename + 'F');

  if XSettings.Database.UseODBC then begin

    GScanDetails[dataFolderHistory].Folders.Clear;
    GScanDetails[dataFolderHistory].Files.Clear;

    // =========================================================================
    // == build folder data ====================================================
    // =========================================================================

    if modernss then begin
      XQuery := TADOQuery.Create(nil);

      XQuery.Connection := XODBC;
      XQuery.SQL.Add('SELECT FilePath FROM "' + tablename + 'F"');
      XQuery.Open;

      while not XQuery.eof do begin
        GScanDetails[dataFolderHistory].Folders.Add(XQuery.Fields[0].AsString);

        XQuery.Next;
      end;

      XQuery.Free;
    end;

    // =========================================================================
    // == build file data ======================================================
    // =========================================================================

    XQuery := TADOQuery.Create(nil);

    try
      XQuery.Connection := XODBC;

      if modernss then
        XQuery.SQL.Add('SELECT FilePathIdx, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner FROM "' + tablename + '"')
      else
        XQuery.SQL.Add('SELECT FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner FROM "' + tablename + '"');

      XQuery.Open;

      while not XQuery.eof do begin
        tfo := TFileObject.Create;

        tfo.Filename       := XQuery.Fields[1].AsString;

        if modernss then
          tfo.FilePathIndex  := XQuery.Fields[fFilePathIndex].AsInteger
        else begin
          tempString         := XQuery.Fields[fFilePath].AsString;

          a := GScanDetails[dataFolderHistory].Folders.IndexOf(tempstring);

          if a <> -1 then
            tfo.FilePathIndex := a
          else begin
            GScanDetails[dataFolderHistory].Folders.Add(tempString);
            tfo.FilePathIndex := GScanDetails[dataFolderHistory].Folders.Count - 1;
          end;
        end;

        tfo.FileSize       := StrToInt64(XQuery.Fields[2].AsString);
        tfo.FileSizeOnDisk := StrToInt64(XQuery.Fields[3].AsString);

        tfo.FileDateC      := StrToInt(XQuery.Fields[4].AsString);
        tfo.FileDateA      := StrToInt(XQuery.Fields[5].AsString);
        tfo.FileDateM      := StrToInt(XQuery.Fields[6].AsString);

        tfo.FileCategory   := StrToInt(XQuery.Fields[7].AsString);

        tfo.Attributes     := 0;

        if XQuery.Fields[8].AsInteger = 1 then
          inc(tfo.Attributes, System.SysUtils.faDirectory);

        if XQuery.Fields[9].AsInteger = 1 then
          inc(tfo.Attributes, System.SysUtils.faReadOnly);

        if XQuery.Fields[10].AsInteger = 1 then
          inc(tfo.Attributes, System.SysUtils.faHidden);

        if XQuery.Fields[11].AsInteger = 1 then
          inc(tfo.Attributes, System.SysUtils.faSysFile);

        if XQuery.Fields[12].AsInteger = 1 then
          inc(tfo.Attributes, System.SysUtils.faArchive);

        if XQuery.Fields[13].AsInteger = 1 then
          tfo.Temp := True
        else
          tfo.Temp := False;

        if XSettings.Optimisations.GetUserDetails then begin
          z := TUtility.FindUserIndex(dataFolderHistory, XQuery.Fields[14].AsString);
          if z = -1 then begin
            tud      := TUserData.Create;
            tud.Name := XQuery.Fields[14].AsString;

            GScanDetails[dataFolderHistory].Users.Add(tud);

            z := GScanDetails[dataFolderHistory].Users.Count - 1;

            inc(GScanDetails[dataFolderHistory].Users[z].Data[XUserCount]);
            inc(GScanDetails[dataFolderHistory].Users[z].Data[XUserSize], tfo.FileSize);
          end
        end
        else
          z := 0;

        tfo.Owner := z;

        // =====================================================================

        GScanDetails[dataFolderHistory].Files.Add(tfo);

        if GScanDetails[dataFolderHistory].Files.Count mod 5000 = 0 then begin
//          Application.ProcessMessages;
        end;

        XQuery.Next;
      end;
    finally
      XQuery.Free;
    end;
  end
end;


end.
