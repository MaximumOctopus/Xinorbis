//---------------------------------------------------------------------------

#ifndef XFramePropertiesH
#define XFramePropertiesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
class TFrameProperties : public TFrame
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *tsCategories;
	TTabSheet *tsTypes;
	TTabSheet *tsExtensions;
	TTabSheet *tsFolders;
	TTabSheet *tsMagnitude;
	TTabSheet *tsDates;
	TTabSheet *tsHistory;
	TTabSheet *tsTop101;
	TTabSheet *tsNull;
	TTabSheet *tsUsers;
	TTabSheet *tsTemporary;
	TTabSheet *tsLength;
	TPanel *Panel1;
	TStringGrid *sgCategories;
	TSplitter *Splitter1;
	TPopupMenu *puCharts;
	TMenuItem *miChartOptions;
	TMenuItem *N9;
	TMenuItem *miCOSave;
	TMenuItem *miCOCopy;
	TMenuItem *miCOAdvanced;
	TPopupMenu *puType;
	TMenuItem *miTypeExportContent;
	TMenuItem *miTypeZip;
	TMenuItem *miTypeExportCB;
	TPopupMenu *puExtensionsMain;
	TMenuItem *miOtherAddTo;
	TMenuItem *miOA1;
	TMenuItem *miOA2;
	TMenuItem *miOA3;
	TMenuItem *miOA4;
	TMenuItem *miOA5;
	TMenuItem *miOA6;
	TMenuItem *miOA7;
	TMenuItem *miOA8;
	TMenuItem *miCustomEM;
	TMenuItem *miOA9;
	TMenuItem *miOA10;
	TMenuItem *miOA11;
	TMenuItem *miOA12;
	TMenuItem *miOA13;
	TMenuItem *miOA14;
	TMenuItem *miOA15;
	TMenuItem *miOA16;
	TMenuItem *miOA17;
	TMenuItem *miOA18;
	TMenuItem *N2;
	TMenuItem *miShowOtherFiles;
	TMenuItem *miExtensionsExportTableCSV;
	TMenuItem *N37;
	TMenuItem *SaveasCSV2;
	TPopupMenu *puFolders;
	TMenuItem *miFolderMoreDetail;
	TMenuItem *miScanFromDirList;
	TMenuItem *miExploreFromDirList;
	TMenuItem *miFolderExportSelectedCB;
	TPopupMenu *puMagnitude;
	TMenuItem *miMagnitudeExport;
	TMenuItem *miMagnitudeZip;
	TMenuItem *miMagnitudeExportCB;
	TPopupMenu *puTreeDate;
	TMenuItem *MenuItem20;
	TMenuItem *MenuItem18;
	TMenuItem *MenuItem19;
	TMenuItem *miFileDatesExploreDir;
	TMenuItem *miFileDatesInfo;
	TMenuItem *miDGenerateMD5;
	TMenuItem *N11;
	TMenuItem *miFileDatesExport;
	TMenuItem *miFileDatesExportCB;
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
	TPopupMenu *puUsers;
	TMenuItem *miUsersExportSelected;
	TMenuItem *miUsersZip;
	TMenuItem *miUsersExportSelectedCB;
	TPopupMenu *puFolderConfig;
	TMenuItem *miFCO;
	TMenuItem *miFCOShowAll;
	TMenuItem *N110;
	TMenuItem *N28;
	TMenuItem *N31;
	TMenuItem *N41;
	TMenuItem *N51;
	TMenuItem *N101;
	TMenuItem *N151;
	TPopupMenu *puTableDisplay;
	TMenuItem *miTDShowAll;
	TMenuItem *miTDNonZero;
	TMenuItem *miTDUserDefined;
	TMenuItem *N13;
	TMenuItem *miTD1;
	TMenuItem *miTD2;
	TMenuItem *miTD3;
	TMenuItem *miTD4;
	TMenuItem *miTD5;
	TMenuItem *miTD6;
	TMenuItem *miTD7;
	TMenuItem *miTD8;
	TMenuItem *miTD9;
	TMenuItem *miTDCustom;
	TMenuItem *miTD10;
	TMenuItem *miTD11;
	TMenuItem *miTD12;
	TMenuItem *miTD13;
	TMenuItem *miTD14;
	TMenuItem *miTD15;
	TMenuItem *miTD16;
	TMenuItem *miTD17;
	TMenuItem *miTD18;
	TMenuItem *miTD19;
	TPopupMenu *puTable;
	TMenuItem *miTableExportSelected;
	TMenuItem *miTableZip;
	TMenuItem *miTableExportSelectedCB;
	TPopupMenu *puNullFiles;
	TMenuItem *miNFExplore;
	TMenuItem *miNFProperties;
	TPopupMenu *puNullFolders;
	TMenuItem *miNFExploreFolder;
	TMenuItem *miNFFolderProperties;
	TPopupMenu *puLength;
	TMenuItem *miLengthShowAll;
	TMenuItem *miLengthNonZero;
	TSpeedButton *sbCategoriesPie;
	TSpeedButton *sbCategoriesBar;
	TSpeedButton *SpeedButton4;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TChart *vtcCategories;
	TPieSeries *Series1;
	TSplitter *Splitter2;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;
	TPanel *Panel10;
	TPanel *Panel11;
	TPanel *Panel12;
	TTreeView *TreeView2;
	TChart *Chart1;
	TStringGrid *StringGrid1;
	TSplitter *Splitter3;
	TChart *Chart2;
	TStringGrid *StringGrid2;
	TSplitter *Splitter4;
	TChart *Chart3;
	TTreeView *TreeView3;
	TSplitter *Splitter5;
	TChart *Chart4;
	TStringGrid *StringGrid3;
	TSplitter *Splitter6;
	TChart *Chart5;
	TPanel *Panel13;
	TChart *Chart6;
	void __fastcall sbCategoriesPieClick(TObject *Sender);
	void __fastcall sbCategoriesBarClick(TObject *Sender);
private:	// User declarations

    void Init();
	void InitCategoriesTable();

	// tab categories
	void BuildCategoriesTable();
	void BuildCategoriesChart();

    // tab

public:		// User declarations
	__fastcall TFrameProperties(TComponent* Owner);

	void Update();
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameProperties *FrameProperties;
//---------------------------------------------------------------------------
#endif
