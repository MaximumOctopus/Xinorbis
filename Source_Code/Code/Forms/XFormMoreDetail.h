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
	TStringGrid *StringGrid1;
	TLabel *Label5;
private:	// User declarations
public:		// User declarations
	__fastcall TForm16(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm16 *Form16;
//---------------------------------------------------------------------------
#endif
