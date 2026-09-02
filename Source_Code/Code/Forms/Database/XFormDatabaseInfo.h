//---------------------------------------------------------------------------

#ifndef XFormDatabaseInfoH
#define XFormDatabaseInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm19 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TLabel *lSize;
	TLabel *lTables;
	TPanel *Panel2;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TSpeedButton *sbSearch;
	TBevel *Bevel1;
	TBitBtn *sbShowNames;
	TBitBtn *sbDeleteTable;
	TBitBtn *bSave;
	TBitBtn *bExportCSV;
	TBitBtn *bExportXML;
	TBitBtn *bCancel;
	TBitBtn *BitBtn1;
	TStringGrid *sgDatabase;
	void __fastcall sbShowNamesClick(TObject *Sender);
	void __fastcall sbDeleteTableClick(TObject *Sender);
	void __fastcall bSaveClick(TObject *Sender);
	void __fastcall bExportCSVClick(TObject *Sender);
	void __fastcall bExportXMLClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall sbSearchClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall sgDatabaseDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall sgDatabaseClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:

    constexpr static int InfoWidths[6] = { 99, 147, 101, 320, 64, 50 };

	void DeleteFromDatabaseXFH(const std::wstring, const std::wstring);

	void Init();

    void BuildDisplay();

public:
	__fastcall TForm19(TComponent* Owner);
};

void OpenDatabaseInformation();
//---------------------------------------------------------------------------
extern PACKAGE TForm19 *Form19;
//---------------------------------------------------------------------------
#endif
