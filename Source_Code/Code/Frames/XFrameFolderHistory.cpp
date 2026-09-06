//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFrameFolderHistory.h"

#include "SettingsHandler.h"

extern SettingsHandler *GSettingsHandler;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameFolderHistory *FrameFolderHistory;
//---------------------------------------------------------------------------
__fastcall TFrameFolderHistory::TFrameFolderHistory(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------


void TFrameFolderHistory::Init()
{
	//sgFHCompareLeft->DefaultRowHeight  = GSettingsHandler->Appearance.RowHeight;
//	sgFHCompareRight->DefaultRowHeight = GSettingsHandler->Appearance.RowHeight;
//	sgFHTable->DefaultRowHeight        = GSettingsHandler->Appearance.RowHeight;

  /*	sbFHCLHideCreated.Hint    := XText[rsHint1];
	sbFHCRHideAccessed.Hint   := XText[rsHint1];
	sbFHCLHideAccessed.Hint   := XText[rsHint2];
	sbFHCRHideAccessed.Hint   := XText[rsHint2];
	sbFHCLHideModified.Hint   := XText[rsHint3];
	sbFHCRHideModified.Hint   := XText[rsHint3];
	sbFHCLHideOwner.Hint      := XText[rsHint4];
	sbFHCRHideOwner.Hint      := XText[rsHint4];
	sbFHCLHideAttributes.Hint := XText[rsHint5];
	sbFHCRHideAttributes.Hint := XText[rsHint5];
	sbFHCLHideSOD.Hint        := XText[rsHint6];
	sbFHCRHideSOD.Hint        := XText[rsHint6];
	sbFHCShowLeft.Hint        := XText[rsHint8];
	sbFHCShowRight.Hint       := XText[rsHint8];


  t, lWidth : integer;
  lFA : array[0..2] of string;

begin
  lFA[0] := XText[rsCreated];
  lFA[1] := XText[rsAccessed];
  lFA[2] := XText[rsModified];

  FCharts[1] := vtcFolderHistory;

  // ===========================================================================

  miFHCSSaveAll.Caption  := XText[rsSaveAll];
  miFHCSSaveDo.Caption   := XText[rsSaveDoExist];
  miFHCSSaveDont.Caption := XText[rsSaveDontExist];

  // ===========================================================================

  miGenericExport.Caption        := XText[rsExportContent] + rsEllipsis;
  miGenericClipboard.Caption     := XText[rsCopyTableToClipboard];
  miGenericClipboardHTML.Caption := XText[rsSaveAs] + ' HTML';;

  // ===========================================================================

  miChartOptions.Caption         := XText[rsChartOptions];
  miCOSave.Caption               := XText[rsSaveChart];
  miCOCopy.Caption               := XText[rsCopyChartToClipboard];
  miCOAdvanced.Caption           := XText[rsAdvancedOptions];

  // ===========================================================================

  cbFHCompareUnits.Clear;

  cbFHCompareFolderInclude.Caption := XText[rsIncludeFullPath];

  tsFHMainStatus.Caption := 'Stats' + '        ';
  tsFHMainSearch.Caption := XText[rsSearch] + '        ';

  tsFHChart.Caption := XText[rsChart] + '        ';
  tsFHTable.Caption := XText[rsTable] + '        ';
  lFHCTotalSize.Caption := XText[rsTotalSize] + ':';


  rbFHSize.Caption               := XText[rsBySize];
  rbFHMagSize.Caption            := XText[rsBySize];

  rbFHCount.Caption                := XText[rsByQuantity];
  rbFHMagCount.Caption             := XText[rsByQuantity];

  lFHCompareSize.Caption := XText[rsSize];
  lFHCompareSize.Caption   := XText[rsSize];

  cbFHComparePath.Caption  := XText[rsShowFullPath];

  lFHFolderCount.Caption  := XText[rsFolders] + ':';
  lFHCMagnitude.Caption     := XText[rsMagnitude];

  sbFHOpenFolder.Caption:= XText[rsOpen];

  cbFHCompareColour.Caption       := XText[rsColourCode];
  llFHPleaseWait.Caption := XText[rsLoadingFileHistoryData] + rsEllipsis;

  rbFJTRToday.Caption:= XText[rsRelativeToToday];
  rbFJTRPrevious.Caption := XText[rsRelativeToPrevious];
  tsFHCompare.Caption := XText[rsFileHistoryCompare] + '        ';

  lFHAvailableComputer.Caption  := XText[rsFolderHistoryComputer];
  lFHAvailablePath.Caption      := XText[rsFolderHistoryFolder];

  lWidth := Max(lFHAvailableComputer.Width, lFHAvailablePath.Width);

  cbFHAvailableComputer.Left    := lFHAvailableComputer.Left + lWidth + 8;
  cbFHAvailableFilter.Left      := lFHAvailablePath.Left + lWidth + 8;
  cbFHAvailablePath.Left        := cbFHAvailableFilter.Left + 58;
  sbFHFolderInfo.Left           := cbFHAvailablePath.Left + cbFHAvailablePath.Width + 8;

  bFHISelect.Caption            := XText[rsSelectScanDateTime];
  bFHCompareLeft.Caption        := XText[rsSelectScanDateTime];
  bFHCompareRight.Caption       := XText[rsSelectScanDateTime];
  bFHCompareFolderLeft.Caption  := XText[rsSelectScanDateTime];
  bFHCompareFolderRight.Caption := XText[rsSelectScanDateTime];
  bFHCompareTreeLeft.Caption    := XText[rsSelectScanDateTime];
  bFHCompareTreeRight.Caption   := XText[rsSelectScanDateTime];

  tsFHCompareFolder.Caption  := XText[rsCompareFolder] + '        ';
  tsFHCompareFolder2.Caption := XText[rsCompareFolderTree] + '        ';

  lFHCFiles.Caption      := XText[rsFiles] + ':';
  lFHCCategory.Caption   := XText[rsCategory] + ':';
  lFHCFilesCount.Caption := XText[rsFiles] + ':';

  cbFHCompareUnits.Items.Add(XText[rsMostConvenient]);
  cbFHCompareUnits.Items.Add(XText[rsBytes]);
  cbFHCompareUnits.Items.Add(XText[rsKilobytes]);
  cbFHCompareUnits.Items.Add(XText[rsMegabytes]);

  FQuickCompareA := THashedStringList.Create;
  FQuickCompareB := THashedStringList.Create;

  tsFHTimeLine.Caption := XText[rsTimeLine] + '        ';

  tsFHMainSearch.TabVisible := False;

  GXGuiUtil.SetButtonOffImage(sbFHCLHideCreated,    CImageCreated);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideAttributes, CImageAttributes);
  GXGuiUtil.SetButtonOffImage(sbFHCLHideSOD,        CImageSizeOnDisk);

  GXGuiUtil.SetButtonOffImage(sbFHCRHideCreated,    CImageCreated);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideAccessed,   CImageAccessed);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideModified,   CImageModified);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideOwner,      CImageOwner);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideAttributes, CImageAttributes);
  GXGuiUtil.SetButtonOffImage(sbFHCRHideSOD,        CImageSizeOnDisk);

  GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, 8);
  GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);

  InitDisplayDoOnce;

  if XSettings.FHCompare[1, 1] then sbFHCLHideCreatedClick(sbFHCLHideCreated);
  if XSettings.FHCompare[1, 2] then sbFHCLHideCreatedClick(sbFHCLHideAccessed);
  if XSettings.FHCompare[1, 3] then sbFHCLHideCreatedClick(sbFHCLHideModified);
  if XSettings.FHCompare[1, 4] then sbFHCLHideCreatedClick(sbFHCLHideOwner);
  if XSettings.FHCompare[1, 5] then sbFHCLHideCreatedClick(sbFHCLHideAttributes);
  if XSettings.FHCompare[1, 6] then sbFHCLHideCreatedClick(sbFHCLHideSOD);

  if XSettings.FHCompare[2, 1] then sbFHCRHideCreatedClick(sbFHCRHideCreated);
  if XSettings.FHCompare[2, 2] then sbFHCRHideCreatedClick(sbFHCRHideAccessed);
  if XSettings.FHCompare[2, 3] then sbFHCRHideCreatedClick(sbFHCRHideModified);
  if XSettings.FHCompare[2, 4] then sbFHCRHideCreatedClick(sbFHCRHideOwner);
  if XSettings.FHCompare[2, 5] then sbFHCRHideCreatedClick(sbFHCRHideAttributes);
  if XSettings.FHCompare[2, 6] then sbFHCRHideCreatedClick(sbFHCRHideSOD);

  FHCatButtons[0]:=sbFHCF1;   FHCatButtons[1]:=sbFHCF2;   FHCatButtons[2]:=sbFHCF3;   FHCatButtons[3]:=sbFHCF4;   FHCatButtons[4]:=sbFHCF5;
  FHCatButtons[5]:=sbFHCF6;   FHCatButtons[6]:=sbFHCF7;   FHCatButtons[7]:=sbFHCF8;   FHCatButtons[8]:=sbFHCF9;   FHCatButtons[9]:=sbFHCF10;
  FHCatButtons[10]:=sbFHCF11; FHCatButtons[11]:=sbFHCF12; FHCatButtons[12]:=sbFHCF13; FHCatButtons[13]:=sbFHCF14; FHCatButtons[14]:=sbFHCF15;
  FHCatButtons[15]:=sbFHCF16; FHCatButtons[16]:=sbFHCF17; FHCatButtons[17]:=sbFHCF18; FHCatButtons[18]:=sbFHCF19; FHCatButtons[19]:=sbFHCF20;

  for t := 0 to __FileCategoriesCount do begin
    GXGuiUtil.SetFolderHistoryButtonImage(FHCatButtons[t], FHCCImageBase[t]);

    FHCatButtons[t].Hint := FHCatButtons[t].Hint + ' (' + TypeDescriptionsSmall[t] + ')';
  end;

  cbFHCompareUnits.ItemIndex := 0;

  SetTheme;

  InitUpdate;	*/
}


#pragma region Application_Control
void TFrameFolderHistory::ResetDisplay(bool aDisableBuildInformationTabs, bool aMode)
{
/*  TGridUtility.ConfigureInfoTable(sgFHCDLeft);
  TGridUtility.ConfigureInfoTable(sgFHCDRight);

  // ===========================================================================

  bFHISelect.Enabled  := aDisableBuildInformationTabs;
  sbFHGetDate.Enabled := aDisableBuildInformationTabs;

  // ===========================================================================

    sgFHTable.ClearRows(1, sgFHTable.RowCount - 1);
    sgFHTable.RowCount := 2;

    sgFHTable.Cells[ 0, 0] := XText[rsDate];
    sgFHTable.Cells[ 1, 0] := XText[rsFiles];
    sgFHTable.Cells[ 2, 0] := XText[rsDelta];
    sgFHTable.Cells[ 4, 0] := XText[rsFolders];
    sgFHTable.Cells[ 5, 0] := XText[rsDelta];
    sgFHTable.Cells[ 7, 0] := XText[rsTotalSize];
    sgFHTable.Cells[ 8, 0] := XText[rsDelta];
    sgFHTable.Cells[10, 0] := XText[rsUsedSpace];
    sgFHTable.Cells[11, 0] := XText[rsDelta];

  // ===========================================================================

    sgFHCompareLeft.ClearRows(1, sgFHCompareLeft.RowCount - 1);
    sgFHCompareLeft.RowCount := 2;

    if aMode = False then begin
      sgFHCompareLeft.Cells[ 0, 0]  := XText[rsFilename];
      sgFHCompareLeft.Cells[ 1, 0]  := XText[rsSize];
      sgFHCompareLeft.Cells[ 2, 0]  := XText[rsSizeOD];
      sgFHCompareLeft.Cells[ 3, 0]  := XText[rsCreated];
      sgFHCompareLeft.Cells[ 4, 0]  := XText[rsAccessed];
      sgFHCompareLeft.Cells[ 5, 0]  := XText[rsModified];
      sgFHCompareLeft.Cells[ 6, 0]  := XText[rsOwner];
      sgFHCompareLeft.Cells[ 7, 0]  := XText[rsStatus];
    end;

    eFHCompareSearchChange(Nil);
    lFHCompareRight.HTMLText[0] := rsEllipsis;
    lFHCompareLeft.HTMLText[0]  := rsEllipsis;

  // ===========================================================================

    sgFHCompareRight.ClearRows(1, sgFHCompareRight.RowCount - 1);
    sgFHCompareRight.RowCount := 2;

    if aMode=False then begin
	  sgFHCompareRight.Cells[ 0, 0]  := XText[rsFilename];
      sgFHCompareRight.Cells[ 1, 0]  := XText[rsSize];
      sgFHCompareRight.Cells[ 2, 0]  := XText[rsSizeOD];
      sgFHCompareRight.Cells[ 3, 0]  := XText[rsCreated];
      sgFHCompareRight.Cells[ 4, 0]  := XText[rsAccessed];
      sgFHCompareRight.Cells[ 5, 0]  := XText[rsModified];
      sgFHCompareRight.Cells[ 6, 0]  := XText[rsOwner];
      sgFHCompareRight.Cells[ 7, 0]  := XText[rsStatus];
    end;

  // ===========================================================================

    vtcFolderHistory.SeriesList.Clear;

  // ============================================================================

  if Assigned(FOnResetDisplay) then
	FOnResetDisplay(dataFolderHistory);*/
}
#pragma end_region


#pragma region Application_Settings
void TFrameFolderHistory::LoadSettings()
{
/*var
  t, lChart : integer;
  s : string;
  lReg : TRegistry;

begin
  XSettings.OpenSettings(True);

  if (XSettings.customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
    for t := 1 to MaximumFolderHistory do begin
      s := XSettings.ReadStringFromSettings('Prefs', 'FHSearchTerm' + IntToStr(t), '');
   //   if s <> '' then
    //    eFHSearch.Items.Add(s);

      s := XSettings.ReadStringFromSettings('Prefs', 'FHSearchCompareTerm' + IntToStr(t), '');
      if s <> '' then
        eFHCompareSearch.Items.Add(s);
	end;
  end
  else begin
    lReg := TRegistry.Create(KEY_READ);

    try
      lReg.RootKey := HKEY_CURRENT_USER;
      lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHSearchTerm', True);

      t := 0;
      While lReg.ValueExists('Term' + IntToStr(t)) do begin
     //   eFHSearch.Items.Add(lReg.ReadString('Term' + IntToStr(t)));
        inc(t);
      end;
    finally
      lReg.Free;
    end;

	lReg := TRegistry.Create(KEY_READ);

    try
      lReg.RootKey := HKEY_CURRENT_USER;
      lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHCompareSearchTerm', True);

      t := 0;
      While lReg.ValueExists('Term' + IntToStr(t)) do begin
        eFHCompareSearch.Items.Add(lReg.ReadString('Term' + IntToStr(t)));
        inc(t);
	  end;
	finally
	  lReg.Free;
	end;
  end;

  // ===========================================================================

  for t := 1 to __ChartCount do begin
	lChart := XSettings.ReadIntegerFromSettings('Charts', 'FileHistory_' + IntToStr(t), 0, -1);

	TChartUtility.SetChartType(FCharts[t], lChart);
  end;

  XSettings.CloseSettings; */
}


void TFrameFolderHistory::SaveSettings()
{
/*  t : integer;
  lReg : TRegistry;

begin
  XSettings.OpenSettings(False);

  XSettings.WriteBoolToSettings('FHCompare', 'X1Y1', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideCreated.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y2', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideAccessed.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y3', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideModified.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y4', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideOwner.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y5', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideAttributes.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X1Y6', sgFHCompareLeft.IsHiddenColumn(sbFHCLHideSOD.Tag));

  XSettings.WriteBoolToSettings('FHCompare', 'X2Y1', sgFHCompareRight.IsHiddenColumn(sbFHCRHideCreated.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y2', sgFHCompareRight.IsHiddenColumn(sbFHCRHideAccessed.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y3', sgFHCompareRight.IsHiddenColumn(sbFHCRHideModified.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y4', sgFHCompareRight.IsHiddenColumn(sbFHCRHideOwner.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y5', sgFHCompareRight.IsHiddenColumn(sbFHCRHideAttributes.Tag));
  XSettings.WriteBoolToSettings('FHCompare', 'X2Y6', sgFHCompareRight.IsHiddenColumn(sbFHCRHideSOD.Tag));

  if (XSettings.customsettings.SettingsSaveLocation = SaveLocationConfigIni) then begin
  {  if eFHSearch.Items.Count <> 0 then begin
	  for t := 0 to eFHSearch.Items.Count - 1 do begin
		XSettings.WriteStringToSettings('Prefs', 'FHSearchTerm' + IntToStr(t + 1), eFHSearch.Items[t]);
	  end;
	end;    }

	if eFHCompareSearch.Items.Count <> 0 then begin
	  for t := 0 to eFHCompareSearch.Items.Count - 1 do begin
		XSettings.WriteStringToSettings('Prefs', 'FHSearchCompareTerm' + IntToStr(t + 1), eFHCompareSearch.Items[t]);
	  end;
	end;
  end
  else begin
   { if eFHSearch.Items.Count <> 0 then begin
	  lReg := TRegistry.Create(KEY_WRITE);

	  try
		lReg.RootKey := HKEY_CURRENT_USER;
		lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHSearchTerm', True);

		for t := 0 to eFHSearch.Items.Count - 1 do
		  if t < 20 then lReg.WriteString('Term' + IntToStr(t), eFHSearch.Items[t]);
	  finally
	   lReg.Free;
	  end;
	end;    }

	if eFHCompareSearch.Items.Count <> 0 then begin
	  lReg := TRegistry.Create(KEY_WRITE);

	  try
		lReg.RootKey := HKEY_CURRENT_USER;
		lReg.OpenKey('\software\' + XinorbisRegistryKey + '\FHCompareSearchTerm', True);

		for t := 0 to eFHCompareSearch.Items.Count - 1 do
		  if t < 20 then lReg.WriteString('Term' + IntToStr(t), eFHCompareSearch.Items[t]);
	  finally
		lReg.Free;
	  end;
	end;
  end;

  // ===========================================================================

  for t := 1 to __ChartCount do begin
	XSettings.WriteIntegerToSettings('Charts', 'FileHistory_' + IntToStr(t), TChartUtility.GetChartType(FCharts[t]));
  end;

  XSettings.CloseSettings; */
}
#pragma end_region


#pragma region Application_Hooks
#pragma end_region


#pragma region Public_Stuff
int TFrameFolderHistory::GetActivePage()
{
	return pcStats->ActivePageIndex;
}


void TFrameFolderHistory::SetActivePage(int page)
{
	pcStats->ActivePageIndex = page;
}


std::wstring TFrameFolderHistory::GetSelectedPath()
{
	return L"";//Result := cbFHAvailablePath.Text;
}


void TFrameFolderHistory::SetSelectedPath(const std::wstring path)
{
/*var
  t, xfound : integer;
begin
  if aPath <> '' then begin

	xfound := -1;

	cbFHAvailableComputerChange(Nil);

	for t := 0 to cbFHAvailablePath.Items.Count - 1 do begin
	  if UpperCase(cbFHAvailablePath.Items[t]) = UpperCase(aPath) then
		xfound := t;
	end;

	if xfound <> -1 then begin
	  cbFHAvailablePath.ItemIndex := xfound;

	  sbFHOpenFolderClick(Nil);
	end;
  end; */
}


std::wstring TFrameFolderHistory::GetSelectedComputer()
{
	return L"";//  Result := cbFHAvailableComputer.Text;
}


std::wstring TFrameFolderHistory::GetFolderHistoryItem(int index)
{
/*	if (index < clbFolderHistory.Count)
	{
		Result := clbFolderHistory.Items[Index];
	}      */

	return L"";
}


std::wstring TFrameFolderHistory::GetFolderHistoryItemSelected()
{
	return L"";// Result := clbFolderHistory.Items[bFHISelect.Tag];
}


void TFrameFolderHistory::DoFHSearch(const std::wstring search_term)
{
}


void TFrameFolderHistory::DoCompareSearch(const std::wstring search_term)
{
/*	if aSearchTerm <> '')
	{
		eFHCompareSearch.Text := aSearchTerm;

		sbFHCompareSearchClick(Nil);
	}*/
}


void TFrameFolderHistory::DoCompareDriveSearch(const std::wstring search_term)
{
/*	if aSearchTerm <> '')
	{
		eFHCompareDriveFolder.Text := aSearchTerm;

		sbFHCompareFolderSearchClick(Nil);
	}*/
}


bool TFrameFolderHistory::GetAvailablePathContains(const std::wstring path)
{
/*	if cbFHAvailablePath.Items.IndexOf(aPath) = -1)
	{
		Result := True
	}
	else
	{
		Result := False;
	}*/
}
#pragma end_region


#pragma region Tab_Stats
void __fastcall TFrameFolderHistory::SpeedButton1Click(TObject *Sender)
{
/*  if not(XSettings.ProcessWindowsVisible) then begin

	lDBExists := True;

	if not(XSettings.Database.UseODBC) then
	  if not(FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db')) then
		lDBExists := False;

	if lDBExists then begin
	  if cbFHAvailablePath.Text <> '' then begin

		GScanDetails[dataFolderHistory].ScanPath := cbFHAvailablePath.Text;

		tpFHStats.Visible  := True;         // to do make sure new layout
		tsFHMainSearch.TabVisible := True;

		ResetDisplay(True, False);

		BuildFolderHistory(cbFHAvailableComputer.Text, cbFHAvailablePath.Text);

		BuildTimeLine;
	  end
	  else
		ShowXDialog(XText[rsWarning], XText[rsNoFHFSelected], XDialogTypeWarning);
	end
	else
	  ShowXDialog(XText[rsError] + ' ' + XText[rsFolderHistory],
				  TLanguageHandler.FillParameter(rsCannotFindFileParam, GSystemGlobal.AppDataPath + 'FolderHistory\Database\Xinorbis.db'),
				  XDialogTypeWarning);
	}*/
}


void __fastcall TFrameFolderHistory::cbFHAvailableComputerChange(TObject *Sender)
{
/*  fha : TFolderHistoryInfo;
  t : integer;
  s : string;

 begin
  cbFHAvailableFilter.Items.Clear;
  cbFHAvailableFilter.Items.Add('*');
  cbFHAvailableFilter.Sorted := True;
  cbFHAvailablePath.Items.Clear;

  for t := 0 to FolderHistoryAvailable.Count - 1 do begin
    fha := FolderHistoryAvailable[t];

    if fha.ComputerName = cbFHAvailableComputer.Items[cbFHAvailableComputer.ItemIndex] then begin
      if (AnsiStartsStr('\\', fha.ScanPath)) then
        s := '\\'
      else
        s := Copy(fha.ScanPath, 1, 3);

      if (cbFHAvailableFilter.Items.IndexOf(s) = -1) then
        cbFHAvailableFilter.Items.Add(s);

	  cbFHAvailablePath.Items.Add(fha.ScanPath);
    end;
  end;

  if (cbFHAvailablePath.Tag < cbFHAvailablePath.Items.Count) and (cbFHAvailablePath.Tag <> -1) then
    cbFHAvailablePath.ItemIndex := cbFHAvailablePath.Tag
  else begin
    cbFHAvailableFilter.ItemIndex := 0;
    cbFHAvailablePath.ItemIndex   := 0;
  end;

  cbFHAvailablePath.Refresh;*/
}


void __fastcall TFrameFolderHistory::cbFHAvailableFilterChange(TObject *Sender)
{
/*  fha : TFolderHistoryInfo;
  t : integer;
  lAll : boolean;

 begin
  cbFHAvailablePath.Items.Clear;

  if cbFHAvailableFilter.Text = '*' then
    lAll := true
  else
    lAll := false;

  for t := 0 to FolderHistoryAvailable.Count - 1 do begin
    fha := FolderHistoryAvailable[t];

    if fha.ComputerName = cbFHAvailableComputer.Items[cbFHAvailableComputer.ItemIndex] then begin
      if lAll then
        cbFHAvailablePath.Items.Add(fha.ScanPath)
      else begin
        if AnsiStartsStr(cbFHAvailableFilter.Text, fha.ScanPath) then
          cbFHAvailablePath.Items.Add(fha.ScanPath)
      end;
    end;
  end;

  if (cbFHAvailablePath.Tag < cbFHAvailablePath.Items.Count) and (cbFHAvailablePath.Tag <> -1) then
    cbFHAvailablePath.ItemIndex := cbFHAvailablePath.Tag
  else
    cbFHAvailablePath.ItemIndex   := 0;

  cbFHAvailablePath.Refresh;*/
}


void __fastcall TFrameFolderHistory::cbFHAvailablePathChange(TObject *Sender)
{
/*  ResetDisplay(False, False);

  cbFHAvailablePath.Tag   := cbFHAvailablePath.ItemIndex;

  bFHISelect.Caption      := XText[rsSelectDateTime];
  bFHISelect.Enabled      := False;
  bFHISelect.Tag          := -1;

  // ===========================================================================

  bFHCompareLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareRight.Caption := XText[rsSelectDateTime];
  bFHCompareLeft.Tag      := -1;
  bFHCompareRight.Tag     := -1;

  bFHCompareLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareRight.Caption := XText[rsSelectDateTime];
  bFHCompareLeft.Tag      := -1;
  bFHCompareRight.Tag     := -1;

  bFHCompareFolderLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareFolderRight.Caption := XText[rsSelectDateTime];
  bFHCompareFolderLeft.Tag      := -1;
  bFHCompareFolderRight.Tag     := -1;

  bFHCompareTreeLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareTreeRight.Caption := XText[rsSelectDateTime];
  bFHCompareTreeLeft.Tag      := -1;
  bFHCompareTreeRight.Tag     := -1;

  tvFHTLeft.Items.Clear;
  tvFHTRight.Items.Clear;

  // ===========================================================================

  if Assigned(FOnUpdateLeftStatusPanel) then
	  FOnUpdateLeftStatusPanel(0);*/
}


void __fastcall TFrameFolderHistory::SpeedButton2Click(TObject *Sender)
{
/*  s := DoShowCalendar(clbFolderHistory.Items);

  if s <> '' then begin
	dx := TConvert.IntDateToString(StrToInt(Copy(s, 1, 8))) + ' ' +
								   s[9] + s[10] + ':' + s[11] + s[12] + ':' + s[13] + s[14];

	i := FindFolderHistoryItem(dx);

	if i <> -1 then begin
	  bFHISelect.Tag     := i;
	  bFHISelect.Caption := dx;

	 if bFHISelect.Tag <> -1 then
	   sbFHBuildInformationTabsClick(nil);
	end;
	}*/
}


void __fastcall TFrameFolderHistory::bFHISelectClick(TObject *Sender)
{
/*  if not(XSettings.ProcessWindowsVisible) then begin
	puFHSelectDate.Tag := 1;

	puFHSelectDate.Popup(FGetLeftOffset + bFHISelect.Left + 20,
						 FGetTopOffset + 227);
  end;*/
}


void __fastcall TFrameFolderHistory::pcStatsChange(TObject *Sender)
{
/*  if Assigned(FSetTutorialBarText) then
	FSetTutorialBarText(GSystemGlobal.ExePath + 'data\languages\' + TLanguageHandler.GetLanguageSymbol(XSettings.CurrentLanguage) +
												'\tutorial\fht' + IntToStr(tpFHStats.ActivePageIndex) + '.dat');  // to do make sure new layout

  if tpFHStats.ActivePageIndex = 5 then
	atlFolderHistory.VerticalMargin := Round(atlFolderHistory.Height / 2) - 10;*/
}


void TFrameFolderHistory::BuildFolderHistorySelectDataMenu()
{ /*
  mi : TMenuItem;
  LastYearNode, LastMonthNode, LastDayNode : TMenuItem;
  lyy, lmm, ldd, t : integer;
  cyy, cmm, cdd : integer;
  xdate : string;

 begin
  bFHISelect.Tag := -1;
  LastYearNode   := Nil;
  LastMonthNode  := Nil;
  LastDayNode    := Nil;
  lyy            := -1;
  lmm            := -1;
  ldd            := -1;

  puFHSelectDate.Items.Clear;

  for t := 0 to clbFolderHistory.Count - 1 do begin
    xdate := TConvert.DateTimeFToYYYYMMDD(clbFolderHistory.Items[t]);

    if xdate <> '' then begin
	  cyy := StrToInt(Copy(xdate, 1, 4));
      cmm := StrToInt(Copy(xdate, 5, 2));
      cdd := StrToInt(Copy(xdate, 7, 2));

      if cyy <> lyy then begin
        mi := TMenuItem.Create(puFHSelectDate);
        mi.Caption := IntToStr(cyy);

        puFHSelectDate.Items.Add(mi);
        LastYearNode := mi;

        lyy := cyy;
      end;

      if cmm <> lmm then begin
        mi := TMenuItem.Create(puFHSelectDate);
        mi.Caption := months[cmm];

        LastYearNode.Add(mi);
        LastMonthNode := mi;

        lmm := cmm;
      end;

      if cdd <> ldd then begin
        mi := TMenuItem.Create(puFHSelectDate);
		mi.Caption := IntToStr(cdd);

		LastMonthNode.Add(mi);
		LastDayNode := mi;

		ldd := cdd;
	  end;

	  mi := TMenuItem.Create(puFHSelectDate);
	  mi.OnClick := miSelectDateTimeClick;
	  mi.Caption := Copy(clbFolderHistory.Items[t], 12, 8);
	  mi.Tag     := t;

	  LastDayNode.Add(mi);
	end;
  end; */
}


void TFrameFolderHistory::BuildFolderHistoryAvailable()
{
/* var
  sr : TSearchRec;
  tf : TextFile;
  fha : TFolderHistoryInfo;
  sp, thispc  : string;
  t, tpxidx : integer;

 function GetPathFromFHFile(const FileName : string): string;
  var
   s : string;

  begin
   AssignFile(tf, FileName);
   {$I-}
   Reset(tf);

   if IOResult <> 0 then begin
	 ShowXDialog(XText[rsError] + ': ' + XText[rsFolderHistory],
				 XText[rsErrorOpening] + ' "' + filename + '".',
				 XDialogTypeWarning);
   end
   else begin
	 Readln(tf, s);

	 CloseFile(tf);
   end;
   {$I+}

   Result := s;
 end;

 function GetComputerNameFromPath(const FileName : string): string;
  var
   s : string;
   i,z : integer;

  begin
   s := '';
   z := Pos('FOLDERHISTORY\', UpperCase(FileName));

   i := z + 14;
   while FileName[i] <> '\' do begin
	 s := s + FileName[i];

	 inc(i);
   end;

   Result := s;
 end;

 begin
  if (XSettings.HistorySettings.Enabled) and (XSettings.System.UserEnabledFH) then begin
	cbFHAvailablePath.Items.Clear;
	cbFHAvailableComputer.Items.Clear;
	FolderHistoryAvailable.Clear;

	thispc := TXWindows.GetComputerNetName;
	tpxidx := 0;

	// firstly we need a list of computer names and paths that have been scanned...
	if FindFirst(GSystemGlobal.AppDataPath + 'folderhistory\' + thispc + '\*.xfh', $3F, sr) = 0 then begin
	  repeat
		sp := GetPathFromFHFile(GSystemGlobal.AppDataPath + 'folderhistory\' + thispc + '\' + sr.Name);

		fha := TFolderHistoryInfo.Create;
		fha.ScanPath     := sp;
		fha.MD5          := sr.Name;
		fha.ComputerName := GetComputerNameFromPath(GSystemGlobal.AppDataPath + 'folderhistory\' + thispc + '\' + sr.Name);;

		FolderHistoryAvailable.Add(fha);

	  until FindNext(sr) <> 0;

	  FindClose(sr);
	end;

	// now we populate the GUI with the new details
	for t := 0 to FolderHistoryAvailable.Count - 1 do begin
	  fha := FolderHistoryAvailable[t];

	  if cbFHAvailableComputer.Items.IndexOf(fha.ComputerName) = -1 then
		cbFHAvailableComputer.Items.Add(fha.ComputerName);

	  if fha.ComputerName = thispc then
		tpxidx := cbFHAvailableComputer.Items.Count - 1;

	end;

	FolderHistoryAvailable.Sort(TComparer<TFolderHistoryInfo>.Construct(CompareFHPaths));

	cbFHAvailableComputer.ItemIndex := tpxidx;

	cbFHAvailableComputerChange(Nil);

	if cbFHAvailableComputer.Items.Count = 0 then begin
	  cbFHAvailableComputer.Items.Add(thispc);
	  cbFHAvailableComputer.ItemIndex := 0;
	end;

	cbFHAvailableComputer.Tag := -1;
	cbFHAvailablePath.Tag     := -1;
  end;*/
}
#pragma end_region



#pragma region Tab_Stats_Chart
void __fastcall TFrameFolderHistory::sbFHCF1Click(TObject *Sender)
{
//
}
#pragma end_region


#pragma region Tab_Stats_Table
void TFrameFolderHistory::InitTable()
{
/*	sgFHTable.ColWidths[0]  := sgFHTable.Width - 603;
	sgFHTable.ColWidths[1]  := 70;
	sgFHTable.ColWidths[2]  := 70;
	sgFHTable.ColWidths[3]  := 6;
	sgFHTable.ColWidths[4]  := 70;
	sgFHTable.ColWidths[5]  := 70;
	sgFHTable.ColWidths[6]  := 6;
	sgFHTable.ColWidths[7]  := 70;
	sgFHTable.ColWidths[8]  := 70;
	sgFHTable.ColWidths[9]  := 6;
	sgFHTable.ColWidths[10] := 70;
	sgFHTable.ColWidths[11] := 70;*/
}


void __fastcall TFrameFolderHistory::StringGrid1DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*  if (ACol > 0) and (ARow > 0) then begin
	if sgFHTable.Cells[ACol, ARow] <> '' then begin
	  if gdSelected in State then begin
		sgFHTable.Canvas.Brush.Color := sgFHTable.SelectionColor;
	  end
	  else begin
		if odd(ARow) then
		  sgFHTable.Canvas.Brush.Color := sgFHTable.Bands.PrimaryColor
		else
		  sgFHTable.Canvas.Brush.Color := $00FFFFFF;
	  end;

	  //sgFHTAble.Canvas.FillRect(Rect);
//      sgFHTable.Canvas.TextRect(Rect, Rect.Left + sgFHTable.ColWidths[ACol] - sgFHTable.Canvas.TextWidth(sgFHTable.Cells[ACol, ARow]) - 5, Rect.Top + 1, sgFHTable.Cells[ACol, ARow]);
	end;
  end;*/
}


void TFrameFolderHistory::BuildFolderHistoryTable()
{
/*TGridUtility.ClearStringGird(sgFHTable, False);

  // now build table ===========================================================

  sgFHTable.BeginUpdate;

  sgFHTable.RowCount := 1 + clbFolderHistory.Items.Count;

  i := clbFolderHistory.Items.Count;

  if rbFJTRPrevious.Checked then begin
    for t := 0 to clbFolderHistory.Items.Count - 1 do begin
      sgFHTable.Cells[ 0, i] := FolderHistory[t].ScanDateStr;

      sgFHTable.Cells[ 1, i] := IntToStr(FolderHistory[t].FileCount);
      sgFHTable.Cells[ 4, i] := IntToStr(FolderHistory[t].FolderCount);
      sgFHTable.Cells[ 7, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSize);
      sgFHTable.Cells[10, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSizeOnDisk);

      if t = 0 then begin
        sgFHTable.Cells[ 2, i] := '';
        sgFHTable.Cells[ 5, i] := '';
        sgFHTable.Cells[ 8, i] := '';
        sgFHTable.Cells[11, i] := '';
      end
      else begin
        sgFHTable.Cells[ 2, i] := TConvert.GetDelta(FolderHistory[t].FileCount -
                                                    FolderHistory[t - 1].FileCount);

        sgFHTable.Cells[ 5, i] := TConvert.GetDelta(FolderHistory[t].FolderCount -
                                                    FolderHistory[t - 1].FolderCount);

        sgFHTable.Cells[ 8, i] := TConvert.GetDeltaSize(FolderHistory[t].FileSize-
                                                        FolderHistory[t - 1].FileSize);

        sgFHTable.Cells[11, i] := TConvert.GetDeltaSize(FolderHistory[t].FileSizeOnDisk-
                                                        FolderHistory[t - 1].FileSizeOnDisk);
      end;

      dec(i);
    end;
  end
  else begin
    for t := 0 to clbFolderHistory.Items.Count - 1 do begin
      sgFHTable.Cells[ 0, i] := FolderHistory[t].ScanDateStr;

      sgFHTable.Cells[ 1, i] := IntToStr(FolderHistory[t].FileCount);
      sgFHTable.Cells[ 4, i] := IntToStr(FolderHistory[t].FolderCount);
      sgFHTable.Cells[ 7, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSize);
      sgFHTable.Cells[10, i] := TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSizeOnDisk);

      if t = clbFolderHistory.Items.Count - 1 then begin
        sgFHTable.Cells[ 2, i] := '';
        sgFHTable.Cells[ 5, i] := '';
        sgFHTable.Cells[ 8, i] := '';
        sgFHTable.Cells[11, i] := '';
      end
      else begin
        sgFHTable.Cells[ 2, i] := TConvert.GetDelta(FolderHistory[t].FileCount -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FileCount);

        sgFHTable.Cells[ 5, i] := TConvert.GetDelta(FolderHistory[t].FolderCount -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FolderCount);

        sgFHTable.Cells[ 8, i] := TConvert.GetDeltaSize(FolderHistory[t].FileSize -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FileSize);

        sgFHTable.Cells[11, i] := TConvert.GetDelta(FolderHistory[t].FileSizeOnDisk -
                                           FolderHistory[clbFolderHistory.Items.Count - 1].FileSizeOnDisk);
      end;

      dec(i);
    end;
  end;

  sgFHTable.EndUpdate; */
}
#pragma end_region


#pragma region Tab_Stats_TimeLine
/*procedure TFrameFolderHistory.atlFolderHistoryDblClick(Sender: TObject);
{
  sbTLResetClick(Nil);
}


procedure TFrameFolderHistory.atlFolderHistoryIndicatorClick(
  Sender: TObject; indicator: TAdvSmoothTimeLineBarIndicator);
var
  lFHId : integer;

begin
  lFHId := indicator.Tag;

  lFHTLIndicatorDetails.HTMLText[0] := TConvert.DateToString(FolderHistory[lFHID].ScanDate) +
									   ' @' + TConvert.TimeToString(FolderHistory[lFHID].ScanDate, True) +
									   ' <b>' + IntToStr(FolderHistory[lFHId].FileCount) + '</b> ' + XText[rsFiles] +
									   ' (<b>' + TConvert.ConvertToUsefulUnit(FolderHistory[lFHId].FileSize) + '</b>)';
end;


procedure TFrameFolderHistory.atlFolderHistoryMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
  lFHTLUnderCursor.Caption := TConvert.DateToString(atlFolderHistory.XToDateTime(X));
}


procedure TFrameFolderHistory.sbTLResetClick(Sender: TObject);
begin
  atlFolderHistory.Range.RangeFrom := oldTLFrom;
  atlFolderHistory.Range.RangeTo   := oldTLTo;

  atlFolderHistory.Resize;
end;


procedure TFrameFolderHistory.sbTLSaveClick(Sender: TObject);
var
  lFileName : string;

begin
  lFileName := TXSaveDialog.ExecuteImages(TUtility.GetDefaultFileName('.png', XText[rsTimeLine]));

  if lFileName <> '' then begin
    try
      atlFolderHistory.SaveToImage(lFileName,
                                   atlFolderHistory.Width, atlFolderHistory.Height,
                                   itPNG);
    except
      on e : exception do begin
        ShowXDialog(XText[rsWarning],
                    XText[rsErrorSaving] + ' "' + lFileName + '". ' + e.ClassName + ' / ' + e.Message,
                    XDialogTypeWarning);
      end;
    end;
  end;*/
#pragma end_region


#pragma region Tab_Generic
void __fastcall TFrameFolderHistory::ShowCalendar(TObject *Sender)
{
/* var
  s,dx : string;
  i : integer;

 begin
  s := DoShowCalendar(clbFolderHistory.Items);

  if s <> '' then begin
	dx := TConvert.IntDateToString(StrToInt(Copy(s, 1, 8))) + ' ' +
								   s[9] + s[10] + ':' + s[11] + s[12] + ':' + s[13] + s[14];

	i := FindFolderHistoryItem(dx);

    if i <> -1 then begin
	  case TSpeedButton(Sender).Tag of
		CCompareLeft        : begin
                                bFHCompareLeft.Tag     := i;
								bFHCompareLeft.Caption := dx;
							  end;
        CCompareRight       : begin
                                bFHCompareRight.Tag     := i;
								bFHCompareRight.Caption := dx;
                              end;
        CCompareFolderLeft  : begin
								bFHCompareFolderLeft.Tag     := i;
								bFHCompareFolderLeft.Caption := dx;
                              end;
		CCompareFolderRight : begin
                                bFHCompareFolderRight.Tag     := i;
                                bFHCompareFolderRight.Caption := dx;
							  end;
		CCompareTreeLeft    : begin
                                bFHCompareTreeLeft.Tag     := i;
								bFHCompareTreeLeft.Caption := dx;
                              end;
		CCompareTreeRight   : begin
								bFHCompareTreeRight.Tag     := i;
								bFHCompareTreeRight.Caption := dx;
							  end;
	  end;
	end;
  end; */
}
#pragma end_region


#pragma region Tab_Search_Compare
void TFrameFolderHistory::InitCompare()
{
   /*	sgFHCompareLeft.HideColumns(8, 13);

	sgFHCompareLeft.ColWidths[0] := sgFHCompareLeft.Width - 530;
	sgFHCompareLeft.ColWidths[1] := 70;
	sgFHCompareLeft.ColWidths[2] := 70;
	sgFHCompareLeft.ColWidths[3] := 70;
	sgFHCompareLeft.ColWidths[4] := 70;
	sgFHCompareLeft.ColWidths[5] := 70;
	sgFHCompareLeft.ColWidths[6] := 100;
	sgFHCompareLeft.ColWidths[7] := 55;

	// ===========================================================================

	sgFHCompareRight.HideColumns(8, 13);

	sgFHCompareRight.ColWidths[0] := sgFHCompareRight.Width - 530;
	sgFHCompareRight.ColWidths[1] := 70;
	sgFHCompareRight.ColWidths[2] := 70;
	sgFHCompareRight.ColWidths[3] := 70;
	sgFHCompareRight.ColWidths[4] := 70;
	sgFHCompareRight.ColWidths[5] := 70;
	sgFHCompareRight.ColWidths[6] := 100;
	sgFHCompareRight.ColWidths[7] := 55;*/
}


void __fastcall TFrameFolderHistory::sbGoSearchClick(TObject *Sender)
{
/*  if not(XSettings.ProcessWindowsVisible) then begin
	if not(XSettings.ProcessWindowsVisible) then begin
	  if (bFHCompareLeft.Tag <> -1) and (bFHCompareRight.Tag <> -1) then begin
		if eFHCompareSearch.Text <> '' then begin
		  FHCompareBuildLeft(Nil);
		  FHCompareBuildRight(Nil);

		  if eFHCompareSearch.Items.IndexOf(eFHCompareSearch.Text) = -1 then begin
			if eFHCompareSearch.Text <> '' then
			  eFHCompareSearch.Items.Insert(0, eFHCompareSearch.Text);
		  end;
		end;
	  end
	  else
		ShowXDialog(XText[rsWarning], XText[rsPleaseSelectADate], XDialogTypeWarning);
	end;
  end;*/
}


void __fastcall TFrameFolderHistory::eSearchChange(TObject *Sender)
{
/*  lCLPagePrevious.Tag     := 0;
  lCRPagePrevious.Tag     := 0;

  lCLPagePrevious.Enabled := False;
  lCLPageNext.Enabled     := False;
  lCLPageNumber.Caption   := '1';
  lCLShowing.Caption      := 'n/a';

  lCRPagePrevious.Enabled := False;
  lCRPageNext.Enabled     := False;
  lCRPageNumber.Caption   := '1';
  lCRShowing.Caption      := 'n/a';*/
}


void __fastcall TFrameFolderHistory::eSearchKeyPress(TObject *Sender, System::WideChar &Key)
{
/*  if key = #13 then
  {
	sbFHCompareSearchClick(sbFHCompareSearch);
  }*/
}


void __fastcall TFrameFolderHistory::BitBtn1Click(TObject *Sender)
{
/*  puFHSelectDate.Tag := 2;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareLeft.Left + 20,
					   FGetTopOffset + Panel46.Height + Panel32.Height + pFHCompare.Height + 80);*/
}


void __fastcall TFrameFolderHistory::BitBtn2Click(TObject *Sender)
{
/*  puFHSelectDate.Tag := 3;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareRight.Left + Panel15.Left ,
					   FGetTopOffset + Panel46.Height + Panel32.Height + pFHCompare.Height + 80);*/
}


void __fastcall TFrameFolderHistory::cbCompareColourCodeClick(TObject *Sender)
{
/*  if sgFHCompareLeft.Cells[0,1] <> '' then
	sgFHCompareLeft.Refresh;

  if sgFHCompareRight.Cells[0,1] <> '' then
	sgFHCompareRight.Refresh;*/
}


void __fastcall TFrameFolderHistory::SpeedButton8Click(TObject *Sender)
{
/*  TGridUtility.ToggleColumn(sgFHCompareLeft,
							TSpeedbutton(Sender),
							TableColumnLookup[(TSpeedbutton(Sender).Tag * 2) + 1],
							TableColumnLookup[TSpeedbutton(Sender).Tag * 2]);

  Splitter2Moved(Nil);*/
}


void __fastcall TFrameFolderHistory::SpeedButton17Click(TObject *Sender)
{
/*  TGridUtility.ToggleColumn(sgFHCompareRight, TSpeedbutton(Sender), TableColumnLookup[(TSpeedbutton(Sender).Tag * 2) + 1], TableColumnLookup[TSpeedbutton(Sender).Tag * 2]);

  Splitter2Moved(Nil);*/
}


void __fastcall TFrameFolderHistory::SpeedButton15Click(TObject *Sender)
{
/*  if sbFHCShowLeft.Tag = 0 then begin
	GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, CImageShow);
	Screen.Cursor := crHourGlass;

	sbFHCShowLeft.Tag := 1;
	cbFHCompareColour.Checked := False;
	i := 0;

	FQuickCompareB.Clear;

	for t := 1 to sgFHCompareRight.RowCount - 1 do begin
	  FQuickCompareB.Add(sgFHCompareRight.Cells[0, t]);
	end;

	FQuickCompareB.Sort;

	// ===========================================================================

	for t := 1 to sgFHCompareLeft.RowCount - 1 do begin
	  if FQuickCompareB.IndexOf(sgFHCompareLeft.Cells[0, t]) <> -1 then
		sgFHCompareLeft.Cells[FHschCategory, t] := '1'
	  else begin
		sgFHCompareLeft.Cells[FHschCategory, t] := '2';

		inc(i);
	  end;
	end;

	lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(i) + '</b> ' + XText[rsFiles] + '.';
	Screen.Cursor := crDefault;
  end
  else begin
	sbFHCShowLeft.Tag := 0;
	GImageHandler->SetButtonOnImage(sbFHCShowLeft, kImageShow);
  end;

  sgFHCompareLeft.Refresh;*/
}


void __fastcall TFrameFolderHistory::SpeedButton26Click(TObject *Sender)
{
/*  if sbFHCShowRight.Tag = 0 then begin
	GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);

	Screen.Cursor := crHourGlass;

	sbFHCShowRight.Tag        := 1;
	cbFHCompareColour.Checked := False;
	i := 0;

	FQuickCompareA.Clear;

	for t := 1 to sgFHCompareLeft.RowCount - 1 do begin
	  FQuickCompareA.Add(sgFHCompareLeft.Cells[0, t]);
	end;

	FQuickCompareA.Sort;

	// ===========================================================================

	for t := 1 to sgFHCompareRight.RowCount - 1 do begin
	  if FQuickCompareA.IndexOf(sgFHCompareRight.Cells[0, t]) <> -1 then
		sgFHCompareRight.Cells[FHschCategory, t] := '1'
	  else begin
		sgFHCompareRight.Cells[FHschCategory, t] := '2';

		inc(i);
	  end;
	end;

	lFHCompareRight.Caption := XText[rsFound] + ' <b>' + IntToStr(i) + '</b> ' + XText[rsFiles] + '.';;

	Screen.Cursor := crDefault;
  end
  else begin
	GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);
	sbFHCShowRight.Tag := 0;
  end;

  sgFHCompareRight.Refresh;*/
}


/*procedure TFrameFolderHistory.FHCompareBuildLeft(Sender : TObject);
 var
  SQL : string;

 begin
  if Pos('SELECT ', eFHCompareSearch.Text) <> 0 then begin
    if XSettings.HistorySettings.SQLinSearch then begin
	  SQL := StringReplace(eFHCompareSearch.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

      SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
      SQL := '';

      ShowXDialog(XText[rsWarning],
                  XText[rsDialog10],
                  XDialogTypeWarning);
    end;
  end
  else begin
    SQL := TSearchUtility.XinorbisSearchToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareLeft.Tag]),
                                              cbFHAvailablePath.Text,
                                              cbFHAvailableComputer.Text,
                                              eFHCompareSearch.Text,
                                              lCLPagePrevious.Tag * XSettings.General.MaxSearchResults,
                                              XSettings.General.MaxSearchResults,
                                              False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
    if SQL <> '' then begin
      sbFHCShowLeft.Tag := 0;
      GXGuiUtil.SetButtonOffImage(sbFHCShowLeft, 8);
      Screen.Cursor := crSQLWait;

      LastSQL[2] := SQL;

      GCompareLeftThread := TCompareLeftThread.Create(True);
	  GCompareLeftThread.SetData(SQL, cbFHCompareUnits.ItemIndex, cbFHComparePath.Checked, sgFHCompareLeft);
      GCompareLeftThread.OnTerminate := CompareLeftThreadOnTerminate;
	  GCompareLeftThread.Priority    := tpTimeCritical;        //tpTimeCritical
	  GCompareLeftThread.Start;
	end;
  end
  else begin
	ShowXDialog(XText[rsWarning],
				XText[rsNoFileData] + ': ' +bFHCompareLeft.Caption,
				XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.FHCompareBuildRight(Sender : TObject);
 var
  SQL : string;

 begin
  if Pos('SELECT ', eFHCompareSearch.Text) <> 0 then begin
	if XSettings.HistorySettings.SQLinSearch then begin
	  SQL := StringReplace(eFHCompareSearch.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

	  SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
	  SQL := '';

      ShowXDialog(XText[rsWarning], XText[rsDialog10], XDialogTypeWarning);
    end;
  end
  else begin
	SQL := TSearchUtility.XinorbisSearchToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text, eFHCompareSearch.Text, lCRPagePrevious.Tag*XSettings.General.MaxSearchResults, XSettings.General.MaxSearchResults, False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
	if SQL <> '' then begin
	  sbFHCShowRight.Tag := 0;
	  GXGuiUtil.SetButtonOffImage(sbFHCShowRight, 8);
	  Screen.Cursor := crSQLWait;

	  LastSQL[3] := SQL;

	  GCompareRightThread := TCompareRightThread.Create(True);
	  GCompareRightThread.SetData(SQL, cbFHCompareUnits.ItemIndex, cbFHComparePath.Checked, sgFHCompareRight);
	  GCompareRightThread.OnTerminate := CompareRightThreadOnTerminate;
      GCompareRightThread.Priority    := tpTimeCritical;
      GCompareRightThread.Start;
	end;
  end
  else begin
	ShowXDialog(XText[rsWarning],
				XText[rsNoFileData] + ': ' + bFHCompareRight.Caption,
				XDialogTypeWarning);
  end;
end;      */


/*void procedure TFrameFolderHistory.CompareLeftThreadOnTerminate(Sender : TObject);
 begin
  if sgFHCompareLeft.Cells[0, 1] <> '' then begin
    if CompareData[XLeftSide].Data[XFileCount] = 0 then
      lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(CompareData[XLeftSide].Data[XFolderCount]) + '</b> ' + XText[rsFolders] + '.'
    else if CompareData[XRightSide].Data[XFolderCount] = 0 then
      lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(CompareData[XLeftSide].Data[XFileCount]) + '</b> ' + XText[rsFiles] + ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XLeftSide].Data[XFileSize]) + '</b>).'
    else
      lFHCompareLeft.HTMLText[0] := XText[rsFound] + ' <b>' + IntToStr(CompareData[XLeftSide].Data[XFileCount]) + '</b> ' + XText[rsFiles] + ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XLeftSide].Data[XFileSize]) + '</b>) + <b>' + IntToStr(CompareData[XLeftSide].Data[XFolderCount]) + '</b> ' + XText[rsFolders] + '.';
  end
  else
    lFHCompareLeft.HTMLText[0] := XText[rsNoFilesFound];

  // == navigation logic ===================================================

  lCLPageNumber.Caption := IntToStr(lCLPagePrevious.Tag + 1);
  lCLShowing.Caption    := IntToStr(lCLPagePrevious.Tag * XSettings.General.MaxSearchResults + 1) + rsEllipsis +
                                    IntToStr((lCLPagePrevious.Tag * XSettings.General.MaxSearchResults) + XSettings.General.MaxSearchResults);

  if lCLPagePrevious.Tag = 0 then
    lCLPagePrevious.Enabled := False
  else
    lCLPagePrevious.Enabled := True;

  if CompareData[XLeftSide].Data[XFileCount] + CompareData[XLeftSide].Data[XFolderCount] < XSettings.General.MaxSearchResults then begin
    if lCLPagePrevious.Tag = 0 then
      lCLPagePrevious.Enabled := False
    else
      lCLPagePrevious.Enabled := True;

    lCLPageNext.Enabled := False;
  end
  else begin
    lCLPagePrevious.Enabled := True;
    lCLPageNext.Enabled     := False;
  end;

  // =======================================================================

  sgFHCompareLeft.EndUpdate;

  TGridUtility.SortTable(sgFHCompareLeft, sgFHCompareLeft.SortSettings.Column);

  Screen.Cursor := crDefault;
end;


procedure TFrameFolderHistory.CompareRightThreadOnTerminate(Sender : TObject);
 begin
  if sgFHCompareRight.Cells[0,1] <> '' then begin
    if CompareData[XRightSide].Data[XFileCount] = 0 then
      lFHCompareRight.HTMLText[0] := XText[rsFound] +
                                     ' <b>' + IntToStr(CompareData[XRightSide].Data[XFolderCount]) + '</b> ' +
                                     XText[rsFolders] + '.'
    else if CompareData[XRightSide].Data[XFolderCount] = 0 then
      lFHCompareRight.HTMLText[0] := XText[rsFound] +
                                     ' <b>' + IntToStr(CompareData[XRightSide].Data[XFileCount]) + '</b> ' +
                                     XText[rsFiles] +
                                     ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XRightSide].Data[XFileSize]) + '</b>).'
	else
      lFHCompareRight.HTMLText[0] := XText[rsFound] +
                                     ' <b>' + IntToStr(CompareData[XRightSide].Data[XFileCount]) + '</b> ' +
                                     XText[rsFiles] +
                                     ' (<b>' + TConvert.ConvertToUsefulUnit(CompareData[XRightSide].Data[XFileSize]) + '</b>) + <b>' +
                                     IntToStr(CompareData[XRightSide].Data[XFolderCount]) + '</b> ' + XText[rsFolders] + '.';
  end
  else
    lFHCompareRight.HTMLText[0] := XText[rsNoFilesFound];

  // == navigation logic ===================================================

  lCRPageNumber.Caption := IntToStr(lCRPagePrevious.Tag + 1);
  lCRShowing.Caption    := IntToStr(lCRPagePrevious.Tag * XSettings.General.MaxSearchResults + 1) + rsEllipsis + IntToStr((lCRPagePrevious.Tag * XSettings.General.MaxSearchResults) + XSettings.General.MaxSearchResults);

  if lCRPagePrevious.Tag = 0 then
    lCRPagePrevious.Enabled := False
  else
    lCRPagePrevious.Enabled := True;

  if CompareData[XRightSide].Data[XFileCount] + CompareData[XRightSide].Data[XFolderCount] < XSettings.General.MaxSearchResults then begin
    if lCRPagePrevious.Tag = 0 then
      lCRPagePrevious.Enabled := False
    else
      lCRPagePrevious.Enabled := True;

    lCRPageNext.Enabled := False;
  end
  else begin
    lCRPagePrevious.Enabled := True;
    lCRPageNext.Enabled     := False;
  end;

  // =======================================================================

  sgFHCompareRight.EndUpdate;

  TGridUtility.SortTable(sgFHCompareRight, sgFHCompareLeft.SortSettings.Column);

  Screen.Cursor := crDefault;
} */


void __fastcall TFrameFolderHistory::Splitter1Moved(TObject *Sender)
{
/*  i := 530;

  if sgFHCompareLeft.IsHiddenColumn(2) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(3) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(4) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(5) then dec(i, 70);
  if sgFHCompareLeft.IsHiddenColumn(6) then dec(i, 100);
  if sgFHCompareLeft.IsHiddenColumn(7) then dec(i, 55);

  sgFHCompareLeft.ColWidths[0]  := sgFHCompareLeft.Width - i;

  i := 530;

  if sgFHCompareRight.IsHiddenColumn(2) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(3) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(4) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(5) then dec(i, 70);
  if sgFHCompareRight.IsHiddenColumn(6) then dec(i, 100);
  if sgFHCompareRight.IsHiddenColumn(7) then dec(i, 55);

  sgFHCompareRight.ColWidths[0] := sgFHCompareRight.Width - i; */
}


void __fastcall TFrameFolderHistory::StringGrid2DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*procedure TFrameFolderHistory.sgFHCompareLeftDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
 var
  l,w : integer;

 begin
  if (cbFHCompareColour.Checked) then begin
	if ARow <> 0 then begin

	  TAdvStringGrid(Sender).Canvas.Brush.Color := GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
	  TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
	end;
  end
  else if (sbFHCShowLeft.Tag = 1) then begin
	if ARow <> 0 then begin
	  TAdvStringGrid(Sender).Canvas.Brush.Color := CompareColoursX[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
	  TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
	end;
  end;

  if ACol > 0 then begin
	case ACol of
	  1,2 : begin
			  w := TAdvStringGrid(Sender).Canvas.TextWidth(TAdvStringGrid(Sender).Cells[ACol, ARow]);
			  l := TAdvStringGrid(Sender).ColWidths[ACol] - w;

			  TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + l - 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
			end;
	end;
  end;
end;*/
}


void __fastcall TFrameFolderHistory::StringGrid3DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*
  if (cbFHCompareColour.Checked) then begin
	if ARow <> 0 then begin
	  TAdvStringGrid(Sender).Canvas.Brush.Color := GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
	  TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
	end;
  end
  else if (sbFHCShowRight.Tag = 1) then begin
	if ARow <> 0 then begin
	  TAdvStringGrid(Sender).Canvas.Brush.Color := CompareColoursX[StrToInt(TAdvStringGrid(Sender).Cells[FHschCategory, ARow])];
	  TAdvStringGrid(Sender).Canvas.TextRect(Rect, Rect.Left + 2, Rect.Top + 2, TAdvStringGrid(Sender).Cells[ACol, ARow]);
	end;
  end;
end; */
}
#pragma end_region


#pragma region Tab_Search_CompareFolder
void __fastcall TFrameFolderHistory::sbCompareFolderSearchClick(TObject *Sender)
{
/*  if not(XSettings.ProcessWindowsVisible) then begin
	if (bFHCompareFolderLeft.Tag <> -1) and (bFHCompareFolderRight.Tag <> -1) then begin
	  if eFHCompareDriveFolder.Text <> '' then begin

		FHCompareFolderBuildLeft(Nil);
		FHCompareFolderBuildRight(Nil);
	  end;
	end
	else
	  ShowXDialog(XText[rsWarning], XText[rsPleaseSelectADate], XDialogTypeWarning);
  end;*/
}


void __fastcall TFrameFolderHistory::BitBtn5Click(TObject *Sender)
{
/*  puFHSelectDate.Tag := 5;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareLeft.Left + 20,
					   FGetTopOffset + Panel46.Height + Panel4.Height + Panel45.Height + 80);*/
}


void __fastcall TFrameFolderHistory::BitBtn6Click(TObject *Sender)
{
/*  puFHSelectDate.Tag := 6;

  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareLeft.Left + Panel49.Left + 20,
					   FGetTopOffset + Panel46.Height + Panel4.Height + Panel45.Height + 80);*/
}


/*procedure TFrameFolderHistory.FHCompareFolderBuildLeft(Sender : TObject);
var
  SQL : string;

begin
  if Pos('SELECT ', eFHCompareDriveFolder.Text) <> 0 then begin
    if XSettings.HistorySettings.SQLinSearch then begin
      SQL := StringReplace(eFHCompareDriveFolder.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

      SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
      SQL := '';
      ShowXDialog(XText[rsWarning], XText[rsDialog10], XDialogTypeWarning);
    end;
  end
  else begin
    SQL := TSearchUtility.XinorbisSearchAllToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text, False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderLeft.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
    if SQL <> '' then begin
      LastSQL[2] := SQL;

      GCompareFolderLeftThread := TCompareFolderLeftThread.Create(True);
      GCompareFolderLeftThread.SetData(SQL, eFHCompareDriveFolder.Text, lFHCDLeft, sgFHCDLeft);
      GCompareFolderLeftThread.OnTerminate := CompareFolderLeftThreadOnTerminate;
      GCompareFolderLeftThread.Priority    := tpTimeCritical;        //tpTimeCritical
      GCompareFolderLeftThread.Start;
    end;
  end
  else begin
    ShowXDialog(XText[rsWarning],
                XText[rsNoFileData] + ': ' + bFHCompareLeft.Caption,
                XDialogTypeWarning);
  end;
end;


procedure TFrameFolderHistory.FHCompareFolderBuildRight(Sender : TObject);
 var
  SQL : string;

 begin
  if Pos('SELECT ', eFHCompareDriveFolder.Text) <> 0 then begin
    if XSettings.HistorySettings.SQLinSearch then begin
	  SQL := StringReplace(eFHCompareDriveFolder.Text, '*', ' FilePath, FileName, FileSize, FileSizeDisk, FileDateC, FileDateA, FileDateM, Category, Directory, Readonly, Hidden, System, Archive, Temp, Owner ', [rfReplaceAll]);

      SQL := StringReplace(SQL, '$x$', '"' + TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text) + '"', [rfReplaceAll]);
    end
    else begin
      SQL := '';

      ShowXDialog(XText[rsWarning], XText[rsDialog10], XDialogTypeWarning);
    end;
  end
  else begin
    SQL := TSearchUtility.XinorbisSearchAllToSQL(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text, False)
  end;

  if TableExists(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareFolderRight.Tag]), cbFHAvailablePath.Text, cbFHAvailableComputer.Text)) then begin
    if SQL <> '' then begin
      LastSQL[2] := SQL;

      GCompareFolderRightThread := TCompareFolderRightThread.Create(True);
	  GCompareFolderRightThread.SetData(SQL, eFHCompareDriveFolder.Text, lFHCDRight, sgFHCDRight);
      GCompareFolderRightThread.OnTerminate := CompareFolderRightThreadOnTerminate;
      GCompareFolderRightThread.Priority    := tpTimeCritical;        //tpTimeCritical
      GCompareFolderRightThread.Start;
    end;
  end
  else begin
    ShowXDialog(XText[rsWarning],
                XText[rsNoFileData] + ': ' + bFHCompareLeft.Caption,
                XDialogTypeWarning);
  end;
end;               */


void __fastcall TFrameFolderHistory::Splitter2Moved(TObject *Sender)
{
/*	sgFHCDLeft.ColWidths[0]  := 10;
	sgFHCDLeft.ColWidths[2]  := 50;
	sgFHCDLeft.ColWidths[3]  := 52;
	sgFHCDLeft.ColWidths[4]  := 4;
	sgFHCDLeft.ColWidths[5]  := 60;
	sgFHCDLeft.ColWidths[6]  := 52;

	sgFHCDLeft.ColWidths[1]  := sgFHCDLeft.Width - (230 + 23);

	sgFHCDRight.ColWidths[0] := 10;
	sgFHCDRight.ColWidths[2] := 50;
	sgFHCDRight.ColWidths[3] := 52;
	sgFHCDRight.ColWidths[4] := 4;
	sgFHCDRight.ColWidths[5] := 60;
	sgFHCDRight.ColWidths[6] := 52;

	sgFHCDRight.ColWidths[1] := sgFHCDRight.Width - (230 + 23); */
}


void __fastcall TFrameFolderHistory::StringGrid5DrawCell(TObject *Sender, System::LongInt ACol,
          System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
/*  if ARow <> 0 then begin
    case ACol of
      CFieldEmpty           : begin
								Rect.Left   := Rect.Left;
								Rect.Top    := Rect.Top;
                                Rect.Right  := Rect.Right;
                                Rect.Bottom := Rect.Bottom;

								if TAdvStringGrid(Sender).Cells[7, Arow] <> '' then begin
                                  TAdvStringGrid(Sender).Canvas.Brush.Color := GSystemGlobal.FileCategoryColors[StrToInt(TAdvStringGrid(Sender).Cells[7, Arow])];
                                  TAdvStringGrid(Sender).Canvas.Rectangle(Rect);
								end;
                              end;
	  CFieldCategoryCountPC : begin
                                TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[5];
                                TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

                                if TAdvStringGrid(Sender).Cells[9, ARow] <> '0' then begin
								  zRect.Top    := Rect.Top + 1;
								  zRect.Bottom := Rect.Bottom - 1;
								  zRect.Left   := Rect.Left + 1;
								  zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[9, ARow]);

								  TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[6];
								  TAdvStringGrid(Sender).Canvas.FillRect(zRect);
								end;

								TAdvStringGrid(Sender).Canvas.Brush.Style := bsClear;
								TAdvStringGrid(Sender).Canvas.Font.Color  := clBlack;
								TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender).Cells[3, ARow]);
							  end;
	  CFieldCategorySizePC  : begin
                                TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[5];
								TAdvStringGrid(Sender).Canvas.Rectangle(Rect);

								if TAdvStringGrid(Sender).Cells[10, ARow] <> '0' then begin
								  zRect.Top    := Rect.Top + 1;
								  zRect.Bottom := Rect.Bottom - 1;
								  zRect.Left   := Rect.Left + 1;
								  zRect.Right  := Rect.Left + StrToInt(TAdvStringGrid(Sender).Cells[10, ARow]);

								  TAdvStringGrid(Sender).Canvas.Brush.Color := XSettings.Navigation.BarColours[6];
								  TAdvStringGrid(Sender).Canvas.FillRect(zRect);
								end;

								TAdvStringGrid(Sender).Canvas.Brush.Style := bsClear;
								TAdvStringGrid(Sender).Canvas.Font.Color  := clBlack;
								TAdvStringGrid(Sender).Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, TAdvStringGrid(Sender).Cells[6, ARow]);
							  end;
	end;
  end;*/
}

#pragma end_region


#pragma region Tab_Search_CompareFolderTree
void __fastcall TFrameFolderHistory::sbCompareTreeClick(TObject *Sender)
{
/*procedure TFrameFolderHistory.SpeedButton1Click(Sender: TObject);
begin
  if not(XSettings.ProcessWindowsVisible) then begin
	if bFHCompareTreeLeft.Tag <> -1 then
	  InitialiseTreeWithFolders(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeLeft.Tag]),
								cbFHAvailablePath.Text, cbFHAvailableComputer.Text), tvFHTLeft);

	if bFHCompareTreeRight.Tag <> -1 then
	  InitialiseTreeWithFolders(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeRight.Tag]),
								cbFHAvailablePath.Text, cbFHAvailableComputer.Text), tvFHTRight);

	sbFHCompareFolder2LeftSaveClick.Enabled  := True;
	sbFHCompareFolder2RightSaveClick.Enabled := True;
  end;
end;         */
}


void __fastcall TFrameFolderHistory::bCompareTreeLeftClick(TObject *Sender)
{
//  puFHSelectDate.Tag := 7;

//  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareTreeLeft.Left + 20,
//					   FGetTopOffset + Panel46.Height + Panel48.Height + Panel55.Height + 80);
}


void __fastcall TFrameFolderHistory::bCompareTreeRightClick(TObject *Sender)
{
//  puFHSelectDate.Tag := 8;

//  puFHSelectDate.Popup(FGetLeftOffset + bFHCompareTreeRight.Left + Panel56.Left + 20,
//					   FGetTopOffset + Panel46.Height + Panel48.Height + Panel55.Height + 80);
}


void __fastcall TFrameFolderHistory::SpeedButton28Click(TObject *Sender)
{
//	TGridUtility.SaveFHStringGridData(sgFHCompareLeft, eFHCompareSearch.Text, fhscModeSaveAll);
}


void __fastcall TFrameFolderHistory::SpeedButton29Click(TObject *Sender)
{
//  TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, fhscModeSaveAll);
}


void __fastcall TFrameFolderHistory::TreeView1Expanding(TObject *Sender, TTreeNode *Node,
		  bool &AllowExpansion)
{
/*  if PNodeData(Node.Data)^.FolderID <> -2 then begin
	PopulateTreeFolder(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeLeft.Tag]),
					   cbFHAvailablePath.Text,
					   cbFHAvailableComputer.Text),
					   tvFHTLeft, node, '', PNodeData(Node.Data)^.FolderID);

	PNodeData(Node.Data)^.FolderID := -2;
	}*/
}


void __fastcall TFrameFolderHistory::TreeView2Expanding(TObject *Sender, TTreeNode *Node,
		  bool &AllowExpansion)
{
/*  if PNodeData(Node.Data)^.FolderID <> -2 then begin
	PopulateTreeFolder(TConvert.CreateTableName(TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHCompareTreeRight.Tag]),
					   cbFHAvailablePath.Text,
					   cbFHAvailableComputer.Text),
					   tvFHTLeft, node, '', PNodeData(Node.Data)^.FolderID);

	PNodeData(Node.Data)^.FolderID := -2;
  end;*/
}
#pragma end_region


#pragma region Popup_Charts
void __fastcall TFrameFolderHistory::miCOSaveClick(TObject *Sender)
{
/*  mychart : TChart;
  lFileName : string;

 begin
  lFileName := TXSaveDialog.ExecuteImages(TUtility.GetDefaultFileName('.png', XText[rsChart]));

  if lFileName <> '' then begin
	mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

	TChartUtility.SaveChartToPNG(mychart, lFileName);
  end; */
}


void __fastcall TFrameFolderHistory::miCOCopyClick(TObject *Sender)
{
/*  mychart : TChart;

 begin
  mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  TChartUtility.CopyChartToClipboard(mychart);*/
}


void __fastcall TFrameFolderHistory::miCOAdvancedClick(TObject *Sender)
{ /*
  mychart : TChart;
  tceo    : TChartOptions;

  mychart := TChart(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  tceo := XSettings.Charts.Options;

  tceo.ChartType := TChartUtility.GetChartType(mychart);

  // ===========================================================================

  tceo := DoAdvancedChartOptions(tceo);

  // ===========================================================================

  if tceo.Result = 1 then begin
	TChartUtility.SetAdvancedOptions(mychart, tceo);

	if Assigned(FChartsHaveChanged) then
	  FChartsHaveChanged;
  end;                          */
}
#pragma end_region


#pragma region Popup_CompareSave
void __fastcall TFrameFolderHistory::puFHCompareSavePopup(TObject *Sender)
{
/*  status : boolean;

  function DoExist(sg : TAdvStringGrid): integer;
   var
	t : integer;

   begin
	Result := 0;

	for t := 1 to sg.RowCount - 1 do begin
	  if sg.Cells[FHschCategory, t] = '1' then inc(Result);
	end
  end;

  function DontExist(sg : TAdvStringGrid): integer;
   var
	t : integer;

   begin
	Result := 0;

	for t := 1 to sg.RowCount - 1 do begin
	  if sg.Cells[FHschCategory, t] = '2' then inc(Result);
	end
  end;

 begin
  miFHCSSaveDo.Caption   := XText[rsSaveDoExist];
  miFHCSSaveDont.Caption := XText[rsSaveDontExist];

  case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : begin
		  if sbFHCShowLeft.Tag = 0 then
			status := False
		  else begin
			status := True;

			miFHCSSaveDo.Caption   := XText[rsSaveDoExist] + ' (' + IntToStr(DoExist(sgFHCompareLeft)) + ')';
			miFHCSSaveDont.Caption := XText[rsSaveDontExist] + ' (' + IntToStr(DontExist(sgFHCompareLeft)) + ')';
		  end;

          miFHCSSaveDo.Enabled   := status;
		  miFHCSSaveDont.Enabled := status;
		end;
	2 : begin
          if sbFHCShowRight.Tag = 0 then
			status := False
          else begin
			status := True;

			miFHCSSaveDo.Caption   := XText[rsSaveDoExist] + ' (' + IntToStr(DoExist(sgFHCompareRight)) + ')';
			miFHCSSaveDont.Caption := XText[rsSaveDontExist] + ' (' + IntToStr(DontExist(sgFHCompareRight)) + ')';
          end;

		  miFHCSSaveDo.Enabled     := status;
          miFHCSSaveDont.Enabled   := status;
		end;
  end;        */
}


void __fastcall TFrameFolderHistory::miFHCSSaveAllClick(TObject *Sender)
{    /*
	case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	}  */
}


void __fastcall TFrameFolderHistory::miFHCSSaveDoClick(TObject *Sender)
{       /*
	case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	} */
}


void __fastcall TFrameFolderHistory::miFHCSSaveDontClick(TObject *Sender)
{          /*
	case TSpeedbutton(Tpopupmenu(Sender).PopupComponent).Tag of
	1 : TGridUtility.SaveFHStringGridData(sgFHCompareLeft,  eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	2 : TGridUtility.SaveFHStringGridData(sgFHCompareRight, eFHCompareSearch.Text, TMenuItem(Sender).Tag);
	} */
}
#pragma end_region


#pragma region Popup_GenericTable
void __fastcall TFrameFolderHistory::puGenericTablePopup(TObject *Sender)
{
/*  lTable : TAdvStringGrid;
  lStatus : boolean;

begin
  if not(XSettings.ProcessWindowsVisible) then begin
	lTable := TAdvStringGrid(Tpopupmenu(Sender).PopupComponent);

	if (lTable.Cells[0, 1] = '') and (lTable.Cells[1, 1] = '') then
	  lStatus := False
	else
	  lStatus := True;

	miGenericExport.Enabled        := lStatus;
	miGenericClipboard.Enabled     := lStatus;
	miGenericClipboardHTML.Enabled := lStatus;
  end; */
}


void __fastcall TFrameFolderHistory::miGenericExportClick(TObject *Sender)
{
/*  grid : TAdvStringGrid;
  lFileName : string;

begin
  grid      := TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  lFileName := TXSaveDialog.ExecuteReports(TUtility.GetDefaultFileName('.csv', XText[rsSearch] + '_' + XText[rsExport]));

  if lFileName <> '' then begin
	TGridUtility.SaveGrid(grid, lFileName);
  end; */
}


void __fastcall TFrameFolderHistory::miGenericClipboardClick(TObject *Sender)
{
/*  grid : TAdvStringGrid;

  grid := TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  grid.CopyToClipBoard; */
}


void __fastcall TFrameFolderHistory::miGenericClipboardHTMLClick(TObject *Sender)
{
/*  grid : TAdvStringGrid;

  grid := TAdvStringGrid(Tpopupmenu(TMenuItem(Sender).GetParentMenu).PopupComponent);

  grid.CopyToClipBoardAsHTML; */
}
#pragma end_region


#pragma region Popup_QuickSearch
/*procedure TFrameFolderHistory.miQuickSearchClick(Sender: TObject);
 var
  ss : string;
  ix : integer;

 begin
  ss := '';
  ix := -1;

  if Pos('{', MenuStrings[TMenuItem(Sender).Tag]) <> 0 then
	ss := ParseMenuSearchCommand(MenuStrings[TMenuItem(Sender).Tag])
  else if MenuStrings[TMenuItem(Sender).Tag][1] = '$' then
	ix := ParseMenuSearchCommandII(MenuStrings[TMenuItem(Sender).Tag])
  else
	ss := MenuStrings[TMenuItem(Sender).Tag];

  if ix <> -1 then begin
	case ix of
	  1 : if Assigned(FOpenSearchWizard) then
			FOpenSearchWizard(0);
		  end;
  end
  else begin
	if ss = 'SetLastSQL' then begin
	  //
	end
	else begin
	  if ss <> '' then begin
		case Tpopupmenu(TMenuItem(Sender).GetParentMenu).Tag of
		  3 : begin
				eFHCompareSearch.Text := ss;
				eFHCompareSearchChange(Nil);

				sbFHCompareSearchClick(sbFHCompareSearch);
			  end;
		  4 : begin
				eFHCompareDriveFolder.Text := ss;
			  end;
		end;
	  end;
	end;
  end;
}     */
#pragma end_region


#pragma region Popup_SelectDate
void __fastcall TFrameFolderHistory::miSelectDateTimeClick(TObject *Sender)
{
/*  lOldID : integer;

begin
  case Tpopupmenu(TMenuItem(Sender).GetParentMenu).Tag of
	1 : begin
		  lOldID := bFHISelect.Tag;

		  bFHISelect.Tag     := TMenuItem(Sender).Tag;
		  bFHISelect.Caption := clbFolderHistory.Items[bFHISelect.Tag];

		  if bFHISelect.Tag <> lOldID then
			sbFHBuildInformationTabsClick(nil);
		end;
	2 : begin
		  bFHCompareLeft.Tag     := TMenuItem(Sender).Tag;
		  bFHCompareLeft.Caption := clbFolderHistory.Items[bFHCompareLeft.Tag];
		end;
	3 : begin
		  bFHCompareRight.Tag     := TMenuItem(Sender).Tag;
		  bFHCompareRight.Caption := clbFolderHistory.Items[bFHCompareRight.Tag];
		end;
//    4 : begin
//        end;
	5 : begin
		  bFHCompareFolderLeft.Tag     := TMenuItem(Sender).Tag;
		  bFHCompareFolderLeft.Caption := clbFolderHistory.Items[bFHCompareFolderLeft.Tag];
		end;
	6 : begin
		  bFHCompareFolderRight.Tag     := TMenuItem(Sender).Tag;
		  bFHCompareFolderRight.Caption := clbFolderHistory.Items[bFHCompareFolderRight.Tag];
		end;
	7 : begin
		  bFHCompareTreeLeft.Tag     := TMenuItem(Sender).Tag;
		  bFHCompareTreeLeft.Caption := clbFolderHistory.Items[bFHCompareTreeLeft.Tag];
		end;
	8 : begin
		  bFHCompareTreeRight.Tag     := TMenuItem(Sender).Tag;
		  bFHCompareTreeRight.Caption := clbFolderHistory.Items[bFHCompareTreeRight.Tag];
		end;
  end;*/
}
#pragma end_region


#pragma region TimeLine
/*void TFrameFolderHistory::BuildTimeLine;
var
  t : integer;
  lRangeFrom, lRangeTo : TDateTime;

begin
  if FolderHistory.Count <> 0 then begin
    lRangeFrom := Now;
    lRangeTo   := EncodeDate(1975, 01, 01);

	atlFolderHistory.BeginUpdate;

    atlFolderHistory.RangeAppearance.DivisionFormat := TConvert.GetDateFormat + ' hh:nn';

    atlFolderHistory.TimeLineIndicators.Clear;

    for t := 0 to FolderHistory.Count - 1 do begin
      with atlFolderHistory.TimeLineIndicators.Add do begin
        Shape           := isDiamond;

        Position        := FolderHistory[t].ScanDate;

        AnnotationColor := spectrumcolours[t mod spectrummod];

        Color           := clWhite;
        ColorTo         := AnnotationColor;

        Annotation      := IntToStr(FolderHistory[t].FileCount) + ' ' + XText[rsFiles] + ' (' + TConvert.ConvertToUsefulUnit(FolderHistory[t].FileSize) + ')';

        Fixed           := True;

        Tag             := t;

        if odd(t) then
          AnnotationPosition := apOnTop
        else
          AnnotationPosition := apAtBottom;

        if FolderHistory[t].ScanDate < lRangeFrom then
          lRangeFrom := FolderHistory[t].ScanDate;

        if FolderHistory[t].ScanDate > lRangeTo then
          lRangeTo := FolderHistory[t].ScanDate;
      end;
    end;

	atlFolderHistory.EndUpdate;

    atlFolderHistory.Range.MinimumRange := IncDay(lRangeFrom, -7);
    atlFolderHistory.Range.MaximumRange := IncDay(lRangeTo, 7);

	atlFolderHistory.Range.RangeFrom    := lRangeFrom;
	atlFolderHistory.Range.RangeTo      := lRangeTo;

    oldTLFrom := lRangeFrom;
	oldTLTo   := lRangeTo;

	sbTLResetClick(nil);
  end;
end;             */
#pragma end_region

/*
	property SelectedPath                     : string                  read  GetSelectedPath           write SetSelectedPath;
    property SelectedComputer                 : string                  read  GetSelectedComputer;
    property FolderHistoryItem[Index: integer]: string                  read  GetFolderHistoryItem;
    property FolderHistoryItemSelected        : string                  read  GetFolderHistoryItemSelected;
    property ActivePage                       : integer                 read  GetActivePage             write SetActivePage;
    property OnExtSetSidePanelDisplay         : TExtSetSidePanelDisplay read  FOnExtSetSidePanelDisplay write FOnExtSetSidePanelDisplay;
    property OnProcessWindowProgressChange    : TProcessWindowProgress  read  FOnProcessWindowProgress  write FOnProcessWindowProgress;
    property OnProcessWindowStatusChange      : TProcessWindowStatus    read  FOnProcessWindowStatus    write FOnProcessWindowStatus;
    property OnSettingsTab                    : TOpenSettingsTab        read  FOnOpenSettingsTab        write FOnOpenSettingsTab;
    property OnUpdateLeftStatusPanel          : TUpdateLeftStatusPanel  read  FOnUpdateLeftStatusPanel  write FOnUpdateLeftStatusPanel;
    property OnSetStatusBarText               : TSetStatusBarText       read  FSetStatusBarText         write FSetStatusBarText;
    property OnSetTutorialBarText             : TSetTutorialBarText     read  FSetTutorialBarText       write FSetTutorialBarText;
    property OnOpenSearchWizard               : TOpenSearchWizard       read  FOpenSearchWizard         write FOpenSearchWizard;
    property OnResetDisplay                   : TOnResetDisplay         read  FOnResetDisplay           write FOnResetDisplay;
    property OnScanFromFolderHistory          : TScanFromFolderHistory  read  FScanFromFolderHistory    write FScanFromFolderHistory;
    property OnUpdateHistoryFinished          : TUpdateHistoryFinished  read  FOnUpdateHistoryFinished  write FOnUpdateHistoryFinished;
    property OnChartsHaveChanged              : TChartsHaveChanged      read  FChartsHaveChanged        write FChartsHaveChanged;

    property GetLeftOffset                    : TGetLeftOffset          read  FGetLeftOffset            write FGetLeftOffset;
    property GetTopOffset                     : TGetTopOffset           read  FGetTopOffset             write FGetTopOffset;

    property IsFHUpdateThreadRunning          : TIsFHUpdateThreadRunning read FIsFHUpdateThreadRunning write FIsFHUpdateThreadRunning;

    property QuickCompareA                    : THashedStringList       read  FQuickCompareA            write FQuickCompareA;
    property QuickCompareB                    : THashedStringList       read  FQuickCompareB            write FQuickCompareB;
  end;

{$region init}


procedure TFrameFolderHistory.InitUpdate;
var
  i : integer;

begin
  SetTableRowHeights;

  for i := 1 to __ChartCount do begin
    TChartUtility.SetAdvancedOptions(FCharts[i], XSettings.Charts.Options);
  end;
end;


procedure TFrameFolderHistory.InitDisplayDoOnce ;
begin
  TGridUtility.ConfigureInfoTable(sgFHCDLeft);
  TGridUtility.ConfigureInfoTable(sgFHCDRight);

  LoadSettings;
end;


procedure TFrameFolderHistory.SetSelectedPathWithoutExecute(aPath : string);
var
  t, xfound : integer;
begin
  if aPath <> '' then begin

    xfound := -1;

    cbFHAvailableComputerChange(Nil);

    for t := 0 to cbFHAvailablePath.Items.Count - 1 do begin
      if cbFHAvailablePath.Items[t] = UpperCase(aPath) then
        xfound := t;
    end;

    if xfound <> -1 then begin
      cbFHAvailablePath.ItemIndex := xfound;
    end;
  end;
end;


procedure TFrameFolderHistory.eFHCompareDriveFolderKeyPress(Sender: TObject;
  var Key: Char);
begin
  if key = #13 then begin
    sbFHCompareFolderSearchClick(Nil);
  end;
end;








procedure TFrameFolderHistory.lFHCFilesClick(Sender: TObject);

  procedure SetToggleIcon(ix : TImage; imageindex : integer);
   var
    tbmp : TBitmap;

   begin
    tbmp := TBitmap.Create;

    ilToggle.GetBitmap(imageindex, tbmp);
    ix.Picture.Bitmap.Assign(tbmp);

    tbmp.Free;

    ix.Tag := 1 - ix.Tag;
  end;

 begin
  if TPanel(TLabel(Sender).Parent).Height = TPanel(TLabel(Sender).Parent).Tag then
    TPanel(TLabel(Sender).Parent).Height := 21
  else
    TPanel(TLabel(Sender).Parent).Height := TPanel(TLabel(Sender).Parent).Tag;

  case TLabel(Sender).Tag of
    CSectionFiles    : SetToggleIcon(Image35, 1 - Image35.Tag);
    CSectionCategory : SetToggleIcon(Image36, 1 - Image36.Tag);
  end;
end;


procedure TFrameFolderHistory.rbFHCountClick(Sender: TObject);
 var
  fhidx : integer;

 begin
  if clbFolderHistory.ItemIndex <> -1 then begin
    fhidx := (FolderHistory.Count - clbFolderHistory.ItemIndex) - 1;

    lFHFileCount.Caption := IntToStr(FolderHistory[fhidx].FileCount);
    lFHFileSize.Caption  := TConvert.ConvertToUsefulUnit(FolderHistory[fhidx].FileSize);
    lFHFolders.Caption   := IntToStr(FolderHistory[fhidx].FolderCount);
  end;

  TDisplayUtility.BuildFolderHistoryGraph(GScanDetails[dataFolderHistory].ScanPath, vtcFolderHistory, clbFolderHistory, rbFHCount.Checked, rbFHSize.Checked, rbFHMagCount.Checked, rbFHMagSize.Checked);
end;


procedure TFrameFolderHistory.rbFJTRTodayClick(Sender: TObject);
begin
  BuildFolderHistoryTable;
end;


procedure TFrameFolderHistory.sbFHBuildInformationTabsClick(Sender: TObject);
var
  dt : string;

begin
  if (bFHISelect.Tag <> -1) then begin

    DT := TConvert.DateTimeFToYYYYMMDDHHMMSS(clbFolderHistory.Items[bFHISelect.Tag]);

    // ===========================================================================

    if TableExists(TMD5.Generate(UpperCase(cbFHAvailablePath.Text)) + DT + cbFHAvailableComputer.Text) then begin

//      if Assigned(FOnProcessWindowStatus) then
//        FOnProcessWindowStatus(CWindowAnalysisProgress, 1);

      TPreScan.PurgeAllData(dataFolderHistory, Nil, Nil, Nil); //sgNullFiles, sgSearchResults);

      Screen.Cursor          := crSQLWait;
      llFHPleaseWait.Visible := True;

      if Assigned(FScanFromFolderHistory) then
        FScanFromFolderHistory(cbFHAvailablePath.Text,
                               TMD5.Generate(UpperCase(cbFHAvailablePath.Text)) + DT + cbFHAvailableComputer.Text,
                               TConvert.YYYYMMDDHHMMSSToString(DT));

      if assigned(FOnUpdateHistoryFinished) then
        FOnUpdateHistoryFinished;

      llFHPleaseWait.Visible := False;
    end
    else begin
      ShowXDialog(XText[rsWarning], XText[rsNoFileData] + ': ' + bFHISelect.Caption, XDialogTypeWarning);
    end;
  end;
end;


procedure TFrameFolderHistory.sbFHCF1Click(Sender: TObject);
var
 idx : integer;

begin
  FHCCStatus[TSpeedbutton(Sender).Tag] := not FHCCStatus[TSpeedbutton(Sender).Tag];

  if FHCCStatus[TSpeedbutton(Sender).Tag] then
    idx := FHCCImageBase[TSpeedbutton(Sender).Tag]
  else
    idx := FHCCImageBase[TSpeedbutton(Sender).Tag] + 1;

  GXGuiUtil.SetFolderHistoryButtonImage(TSpeedbutton(Sender), idx);

  rbFHCountClick(Nil);
end;


procedure TFrameFolderHistory.sbFHCompareFavouritesClick(Sender: TObject);
begin
  puFHQuickSearch.Tag := TSpeedbutton(Sender).Tag;

  puFHQuickSearch.Popup(FGetLeftOffset + 38, FGetTopOffset + 205);
end;


procedure TFrameFolderHistory.sbFHCompareFolder2LeftSaveClickClick(
  Sender: TObject);
var
  stree : THTMLTreeView;
  lFileName : string;

begin
  lFileName := TXSaveDialog.Execute(XText[rsTextFiles] + ' (*.txt)|*.txt',
                                    '.txt',
                                    TUtility.GetDefaultFileName('.txt', XText[rsFileHistoryCompare] + '_' + XText[rsLeft]));

  if lFileName <> '' then begin

    case TSpeedbutton(Sender).Tag of
      CLeft  : stree := tvFHTLeft;
      CRight : stree := tvFHTRight;
    else
      stree := tvFHTLeft;
    end;

    try
      stree.SaveToFile(lFileName);
    except
      on e : exception do begin
        TMSLogger.Error('Error saving tree "' + e.ClassName + ' / ' + e.Message);
      end;
    end;
  end;
end;


procedure TFrameFolderHistory.sbFHCompareFolderLeftSaveClick(Sender: TObject);
 var
  sgrid : TAdvStringGrid;
  lFileName : string;

 begin
  lFileName := TXSaveDialog.ExecuteReports(TUtility.GetDefaultFileName('.csv', XText[rsFileHistoryCompare] + '_' + XText[rsLeft]));

  if lFileName <> '' then begin
    case TSpeedbutton(Sender).Tag of
      CLeft  : sgrid := sgFHCDLeft;
      CRight : sgrid := sgFHCDRight;
    else
      sgrid := sgFHCDLeft;
    end;

    TGridUtility.SaveGrid(sgrid, lFileName);
  end;
end;


procedure TFrameFolderHistory.sbFHFolderInfoClick(Sender: TObject);
begin
  DoDBSelectedFolder(cbFHAvailableComputer.Text, UpperCase(cbFHAvailablePath.Text));
end;





procedure TFrameFolderHistory.CompareFolderRightThreadOnTerminate(Sender : TObject);
 begin
  sgFHCDRight.EndUpdate;

  Screen.Cursor := crDefault;
end;



procedure TFrameFolderHistory.BuildFolderHistory(const ComputerName, ScanPath : string);
 begin
  bFHISelect.Caption            := XText[rsSelectDateTime];
  bFHCompareLeft.Caption        := XText[rsSelectDateTime];
  bFHCompareRight.Caption       := XText[rsSelectDateTime];
  bFHCompareFolderLeft.Caption  := XText[rsSelectDateTime];
  bFHCompareFolderRight.Caption := XText[rsSelectDateTime];

  bFHISelect.Tag                := -1;
  bFHISelect.Enabled            := True;
  bFHCompareLeft.Tag            := -1;
  bFHCompareRight.Tag           := -1;
  bFHCompareFolderLeft.Tag      := -1;
  bFHCompareFolderRight.Tag     := -1;

  FolderHistory.Clear;

  clbFolderHistory.Clear;

  sgFHCompareLeft.ClearRows(1, sgFHCompareLeft.RowCount - 1);
  sgFHCompareRight.ClearRows(1, sgFHCompareRight.RowCount - 1);
  sgFHCompareLeft.RowCount  := 2;
  sgFHCompareRight.RowCount := 2;

  if LoadFolderHistory(ComputerName, ScanPath, clbFolderHistory.Items) then begin

    if FolderHistory.Count > 0 then begin

      BuildFolderHistoryTable;

      // ===========================================================================

      TDisplayUtility.BuildFolderHistoryGraph(FrameSelect.ePath.Text, vtcFolderHistory, clbFolderHistory, rbFHCount.Checked, rbFHSize.Checked, rbFHMagCount.Checked, rbFHMagSize.Checked);

      if clbFolderHistory.Count <> 0 then begin
        clbFolderHistory.Checked[0]     := True;
        clbFolderHistory.ItemIndex      := 0;
		rbFHCountClick(Nil);
      end;

      if clbFolderHistory.Count <> 0 then
        FileHistoryControlStatus(True)
      else
        FileHistoryControlStatus(False);
    end
    else begin
      ShowXDialog(XText[rsError] + ' :: ' + XText[rsFolderHistory], 'Error building File History!', XDialogTypeWarning);
    end;
  end
  else begin
    if FileExists(GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(UpperCase(ScanPath)) + '.xfh') then begin
      if MessageDlg(XText[rsDialog7] + #13#13 + XText[rsDialog8], mtInformation, [mbYes, mbNo], 0) = mrYes then begin
        RepairFile(TMD5.Generate(UpperCase(ScanPath)) + '.xfh', GSystemGlobal.AppDataPath + 'FolderHistory\' + ComputerName + '\' + TMD5.Generate(ScanPath) + '.xfh');
      end;
    end;
  end;

  BuildFolderHistorySelectDataMenu;
end;


procedure TFrameFolderHistory.tpFHStatsResize(Sender: TObject);
begin
  atlFolderHistory.VerticalMargin := Round(atlFolderHistory.Height / 2) - 10;

  Panel14.Width              := Round(tpFHStats.Width / 2);        // to do make sure new layout

  sgFHTable.ColWidths[0]     := sgFHTable.Width - 615;

  Splitter2Moved(Nil);
  splitterFHCDMoved(Nil);

  sbFHCSearchSyntax.Left     := pFHCompare.Width - 28;
end;


function TFrameFolderHistory.FindFolderHistoryItem(const xItem : string): integer;
 var
   t : integer;

 begin
  Result := -1;

  for t := 0 to clbFolderHistory.Items.Count - 1 do begin
	if clbFolderHistory.Items[t] = xItem then begin
      Result := t;

      Break;
    end;
  end;
end;


procedure TFrameFolderHistory.FileHistoryControlStatus(newstatus : boolean);
 var
  t : integer;

 begin
  bFHISelect.Enabled  := newstatus;
  sbFHGetDate.Enabled := newstatus;

  rbFHCount.Enabled                := newstatus;
  rbFHSize.Enabled                 := newstatus;

  rbFJTRToday.Enabled              := newstatus;
  rbFJTRPrevious.Enabled           := newstatus;

  for t := 0 to __FileCategoriesCount do
    FHCatButtons[t].Enabled := newstatus;

  rbFHMagCount.Enabled               := newstatus;
  rbFHMagSize.Enabled                := newstatus;

  sbFHCompareFavourites.Enabled      := newstatus;
  sbfhCompareDriveFavourites.Enabled := newstatus;
  sbFHCompareSearch.Enabled          := newstatus;
  sbFHCSearchSyntax.Enabled          := newstatus;
  eFHCompareSearch.Enabled           := newstatus;
  cbFHCompareUnits.Enabled           := newstatus;
  cbFHComparePath.Enabled            := newstatus;
  cbFHCompareColour.Enabled          := newstatus;
  sbFHCompareLeftSave.Enabled        := newstatus;
  sbFHCompareRightSave.Enabled       := newstatus;

  sbFHCompareFolderSearch.Enabled    := newstatus;
  eFHCompareDriveFolder.Enabled      := newstatus;
  sbFHCompareFolderLeftSave.Enabled  := newstatus;
  sbFHCompareFolderRightSave.Enabled := newstatus;
end;


//par1, caption; par2, text FileName; par3, zsr report, par4; html report, par5; do charts, par6; xml reports
function TFrameFolderHistory.SaveReports(var TextOptions : TTextReportOptions; var CSVOptions  : TCSVReportOptions;
                                         var HTMLOptions : THTMLReportOptions; var XinOptions  : TXinorbisReportOptions;
                                         var XMLOptions  : TXMLReportOptions;  var TreeOptions : TTreeReportOptions): boolean;

var
  lReportOutput : TStringList;

begin
  if Assigned(FSetStatusBarText) then
    FSetStatusBarText(XText[rsSavingReports] + ' ' + XText[rsPleaseWait]);

  Result := True;

  // =========================================================================
  // -- save out text version ------------------------------------------------
  // =========================================================================
  if TextOptions.FileName <> '' then begin
    lReportOutput := TStringList.Create;

     GReportText.GenerateTextReport(dataFolderHistory, lReportOutput, TextOptions);

    FreeAndNil(lReportOutput);
  end;

  // =========================================================================
  // -- save out xinorbis report ---------------------------------------------
  // =========================================================================
  if XinOptions.FileName <> '' then begin
	GReportXinorbis.GenerateXinorbisReport(dataFolderHistory, XinOptions);
  end;

  // =========================================================================
  // -- save out HTML version ------------------------------------------------
  // =========================================================================
  if HTMLOptions.FileName <> '' then begin
    GReportHTML.GenerateHTMLReport(dataFolderHistory, HTMLOptions, '');
  end;

  // =========================================================================
  // -- save out XML version -------------------------------------------------
  // =========================================================================
  if XMLOptions.FileName <> '' then begin
    lReportOutput := TStringList.Create;

    if XMLOptions.XMLData = CDataSummary then
      GReportXML.GenerateXMLOutput(dataFolderHistory, XMLOptions, lReportOutput)
    else
      GReportXML.GenerateXMLOutputFileList(XMLOptions.FileName, lReportOutput, dataFolderHistory, LayoutUnknown);

    FreeAndNil(lReportOutput);
  end;

  // =========================================================================
  // -- save out CSV version -------------------------------------------------
  // =========================================================================
  if CSVOptions.FileName <> '' then begin
    lReportOutput := TStringList.Create;

    GReportCSV.GenerateCSVReport(dataFolderHistory, lReportOutput, CSVOptions, LayoutUnknown);

    FreeAndNil(lReportOutput);
  end;

  // =========================================================================
  // -- save out Tree version ------------------------------------------------
  // =========================================================================
  if TreeOptions.FileName <> '' then begin
    if not(FIsFHUpdateThreadRunning) then begin
      lReportOutput := TStringList.Create;

      GReportTree.GenerateTreeReport(dataFolderHistory, lReportOutput, TreeOptions);

      FreeAndNil(lReportOutput);
    end;
  end;

  // =========================================================================
  // -------------------------------------------------------------------------
  // =========================================================================

  if Assigned(FSetStatusBarText) then
    FSetStatusBarText('');
end;


procedure TFrameFolderHistory.RepairFile(const scanpath, FileName : string);
 begin
  if RenameFile(FileName, ExtractFilePath(FileName) + scanpath) then
    ShowXDialog(XText[rsWarning],
                XText[rsDialog5],
                XDialogTypeInformation)
  else
	ShowXDialog(XText[rsWarning],
				XText[rsDialog6],
				XDialogTypeInformation);
end;


procedure TFrameFolderHistory.CompareFolderLeftThreadOnTerminate(Sender : TObject);
 begin
  sgFHCDLeft.EndUpdate;

  Screen.Cursor := crDefault;
end;

procedure TFrameFolderHistory.SpeedButton4Click(Sender: TObject);
begin
  THelp.OpenSearchManual;
end;
3428*/
