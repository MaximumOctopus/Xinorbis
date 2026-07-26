//---------------------------------------------------------------------------

#ifndef XFormMoreDetailH
#define XFormMoreDetailH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>

#include <vector>

//---------------------------------------------------------------------------
class TForm16 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TBitBtn *bHelp;
	TBitBtn *bClose;
	TBitBtn *bFilter;
	TPanel *Panel3;
	TBevel *Bevel1;
	TSpeedButton *sbBack;
	TScrollBox *ScrollBox1;
	TPanel *pAttributes;
	TCheckBox *cbAHidden;
	TCheckBox *cbASystem;
	TCheckBox *cbAArchive;
	TCheckBox *cbAReadOnly;
	TCheckBox *cbATemp;
	TPanel *pOwner;
	TComboBox *cbUSelect;
	TEdit *eUContent;
	TPanel *pModified;
	TComboBox *cbModified1;
	TDateTimePicker *dtpModified1;
	TComboBox *cbModified2;
	TDateTimePicker *dtpModified2;
	TPanel *pAccessed;
	TComboBox *cbAccessed1;
	TDateTimePicker *dtpAccessed1;
	TComboBox *cbAccessed2;
	TDateTimePicker *dtpAccessed2;
	TPanel *pCreated;
	TComboBox *cbCreated1;
	TComboBox *cbCreated2;
	TDateTimePicker *dtpCreated2;
	TDateTimePicker *dtpCreated1;
	TPanel *pCategory;
	TCheckBox *sbProg;
	TCheckBox *sbSys;
	TCheckBox *sbGfx;
	TCheckBox *sbMovie;
	TCheckBox *sbSnd;
	TCheckBox *sbOffice;
	TCheckBox *sbCode;
	TCheckBox *sbCompressed;
	TCheckBox *sbOther;
	TCheckBox *sbCustom1;
	TCheckBox *sbCustom2;
	TCheckBox *sbCustom3;
	TCheckBox *sbCustom4;
	TCheckBox *sbCustom7;
	TCheckBox *sbCustom5;
	TCheckBox *sbCustom8;
	TCheckBox *sbCustom6;
	TCheckBox *sbCustom9;
	TCheckBox *sbCustom10;
	TPanel *pSize;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *eSLT;
	TComboBox *cbSLTUnit;
	TEdit *eSGT;
	TComboBox *cbSGTUnit;
	TPanel *pContaining;
	TLabel *lContaining;
	TEdit *eContaining;
	TPanel *pNameLength;
	TLabel *Label1;
	TLabel *Label4;
	TEdit *eNLLT;
	TEdit *eNLGT;
	TPanel *Panel1;
	TPanel *Panel4;
	TImageList *ilExplore;
	TPopupMenu *PopupMenu1;
	TMenuItem *miExploreFolder;
	TCheckBox *cbContainingText;
	TCheckBox *cbFileSize;
	TCheckBox *cbCategory;
	TCheckBox *cbFileAttributes;
	TCheckBox *cbCreatedDate;
	TCheckBox *cbAccessedDate;
	TCheckBox *cbModifiedDate;
	TCheckBox *cbFileOwner;
	TCheckBox *cbNameLength;
	TStringGrid *sgExplore;
	TLabel *Label5;
	void __fastcall sbBackClick(TObject *Sender);
	void __fastcall sgExploreDblClick(TObject *Sender);
	void __fastcall bFilterClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall cbUSelectChange(TObject *Sender);
	void __fastcall eSLTEnter(TObject *Sender);
	void __fastcall eSLTExit(TObject *Sender);
	void __fastcall bHelpClick(TObject *Sender);
	void __fastcall miExploreFolderClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight);
	void __fastcall cbContainingTextClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sgExploreDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall cbCreated1Change(TObject *Sender);
private:

	constexpr static int kUnitsBytes     = 0;
	constexpr static int kUnitsKilobytes = 1;
	constexpr static int kUnitsMegabytes = 2;
	constexpr static int kUnitsGigabytes = 3;

	constexpr static int kColIcon            = 0;
	constexpr static int kColFolderName      = 1;
	constexpr static int kColFileCount       = 2;
	constexpr static int kColFilesAsPercent  = 3;
	constexpr static int kColSize            = 5;
	constexpr static int kColSizeAsPercent   = 6;
	constexpr static int kColFileCountPCache = 7;
	constexpr static int kColSizePCache      = 8;
	constexpr static int kColSizeCache       = 9;

	int PanelHeights[6] = { 64, 89, 204,  121, 81, 65 };

	std::wstring OldText = L"";

	TDateTimePicker* DateControls[6];
	TCheckBox* CategoryControls[19];

	void Init();

	void CheckForValidSearch();

	void BuildFrom(const std::wstring);

public:
	__fastcall TForm16(TComponent* Owner);

	int DataSource = 0;

	std::vector<std::wstring> DirectoryList;
	std::wstring ExplorePath = L"";
};

void OpenMoreDetails(int, const std::wstring);

//---------------------------------------------------------------------------
extern PACKAGE TForm16 *Form16;
//---------------------------------------------------------------------------
#endif
