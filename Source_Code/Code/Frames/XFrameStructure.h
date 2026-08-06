//---------------------------------------------------------------------------

#ifndef XFrameStructureH
#define XFrameStructureH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrameStructure : public TFrame
{
__published:	// IDE-managed Components
	TPanel *pMainNavigation;
	TPanel *Panel25;
	TPanel *Panel2;
	TSpeedButton *sbNMCreated;
	TSpeedButton *sbNMAccessed;
	TSpeedButton *sbNMModified;
	TSpeedButton *sbNMUsers;
	TSpeedButton *sbNMAttributes;
	TSpeedButton *sbNMColourCode;
	TSpeedButton *sbNMSizeOnDisk;
	TSpeedButton *sbNLFilter;
	TPanel *Panel26;
	TPanel *Panel27;
	TSpeedButton *sbNavigationBack;
	TSpeedButton *sbNSBCreated;
	TSpeedButton *sbNSBAccessed;
	TSpeedButton *sbNSBModified;
	TSpeedButton *sbNSBUsers;
	TSpeedButton *sbNSBAttributes;
	TSpeedButton *sbNSBColourCode;
	TSpeedButton *sbNSBSizeOnDisk;
	TSpeedButton *sbNRFilter;
	TPopupMenu *puNavigateOptions;
	TMenuItem *miPUNO1;
	TMenuItem *miPUNO2;
	TMenuItem *miPUNO3;
	TMenuItem *miPUNO4;
	TMenuItem *miPUNO5;
	TMenuItem *miPUNO6;
	TMenuItem *miPUNO7;
	TMenuItem *miPUNO8;
	TMenuItem *miPUNO9;
	TMenuItem *miNOCustom;
	TMenuItem *miPUNO10;
	TMenuItem *miPUNO11;
	TMenuItem *miPUNO12;
	TMenuItem *miPUNO13;
	TMenuItem *miPUNO14;
	TMenuItem *miPUNO15;
	TMenuItem *miPUNO16;
	TMenuItem *miPUNO17;
	TMenuItem *miPUNO18;
	TMenuItem *miPUNO19;
	TPopupMenu *puCharts;
	TMenuItem *miChartOptions;
	TMenuItem *N9;
	TMenuItem *miCOSave;
	TMenuItem *miCOCopy;
	TMenuItem *miCOAdvanced;
	TImageList *XFNImages;
	TPopupMenu *puSearch;
	TMenuItem *miSearchOpen;
	TMenuItem *miSearchOpenCustom;
	TMenuItem *N4;
	TMenuItem *miExploreDirectory;
	TMenuItem *miSFileProperties;
	TMenuItem *miGenerateMD5;
	TMenuItem *miHexEdit;
	TMenuItem *N21;
	TMenuItem *miCopyMenu;
	TMenuItem *miCopySelected;
	TMenuItem *miCopyAll;
	TMenuItem *miMoveMenu;
	TMenuItem *miMoveSelected;
	TMenuItem *miMoveAll;
	TMenuItem *miDeleteMenu;
	TMenuItem *miDeleteSelected;
	TMenuItem *miDeleteAll;
	TMenuItem *N23;
	TMenuItem *miZIP;
	TMenuItem *N22;
	TMenuItem *miSearchExportToCB;
	TMenuItem *N36;
	TMenuItem *miSaveAs;
	TStringGrid *sgLeftSide;
	TStringGrid *sgRightSide;
	TSplitter *Splitter1;
	TChart *vtcFS;
	TPieSeries *Series3;
	TLabel *lNavigationDetails;
	void __fastcall miPUNO1Click(TObject *Sender);
	void __fastcall puSearchPopup(TObject *Sender);
	void __fastcall miHexEditClick(TObject *Sender);
	void __fastcall miSearchOpenClick(TObject *Sender);
	void __fastcall miSearchOpenCustomClick(TObject *Sender);
	void __fastcall miExploreDirectoryClick(TObject *Sender);
	void __fastcall miSFilePropertiesClick(TObject *Sender);
	void __fastcall miGenerateMD5Click(TObject *Sender);
	void __fastcall miCopySelectedClick(TObject *Sender);
	void __fastcall miCopyAllClick(TObject *Sender);
	void __fastcall miMoveSelectedClick(TObject *Sender);
	void __fastcall miMoveAllClick(TObject *Sender);
	void __fastcall miDeleteSelectedClick(TObject *Sender);
	void __fastcall miDeleteAllClick(TObject *Sender);
	void __fastcall miZIPClick(TObject *Sender);
	void __fastcall miSearchExportToCBClick(TObject *Sender);
	void __fastcall miSaveAsClick(TObject *Sender);
	void __fastcall miCOSaveClick(TObject *Sender);
	void __fastcall miCOCopyClick(TObject *Sender);
	void __fastcall miCOAdvancedClick(TObject *Sender);
	void __fastcall sbNavigationBackClick(TObject *Sender);
	void __fastcall sbNLFilterClick(TObject *Sender);
	void __fastcall sbNSBColourCodeClick(TObject *Sender);
	void __fastcall sbNMCreatedClick(TObject *Sender);
	void __fastcall sbNMColourCodeClick(TObject *Sender);
	void __fastcall sgRightSideDblClick(TObject *Sender);
	void __fastcall sgLeftSideDblClick(TObject *Sender);
	void __fastcall Panel25Resize(TObject *Sender);
	void __fastcall Panel26Resize(TObject *Sender);
	void __fastcall sgLeftSideDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall sgRightSideDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
private:

	static constexpr int kLeftFileName  = 1;
	static constexpr int kRightFileName = 1;
	static constexpr int kLeftOptions  = 0;
	static constexpr int kRightOptions = 1;

	static constexpr int LeftSideWidths[17]  = { 64, 64, 64, 64, 64, 64, 64, 64, 64,
												 64, 64, 64, 64, 64, 64, 64, 64 };

	static constexpr int RightSideWidths[17] = { 28, 148, 64, 64, 64, 64, 64, 64, 64,
												 64,  64, 64, 64, 64, 64, 64, 64 };

	TMenuItem* NavigateFilter[19];

//	NavigateRightSide *nrs = nullptr;

	bool FilterChanged = true;

    std::wstring CurrentFolder = L"";

	// init
    void Init();
	void InitUpdate();
	void InitHint();

	// settings
	void LoadSettings();
	void SaveSettings();

	void BuildNavigationTab();

	// generic
    std::wstring GetSelectedFileName(int);

public:
	__fastcall TFrameStructure(TComponent* Owner);

    int DataSource = 0;

	void UpdateGUICustomNames();

	std::function<void()> OnChartsHaveChanged;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameStructure *FrameStructure;
//---------------------------------------------------------------------------
#endif
