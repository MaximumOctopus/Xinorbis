//---------------------------------------------------------------------------

#ifndef XFrameMapH
#define XFrameMapH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "XMap.h"

//---------------------------------------------------------------------------
class TFrameMap : public TFrame
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *lMapFolder;
	TLabel *lMapSize;
	TShape *shapeMap;
	TComboBox *cbMapSizeSelect;
	TLabel *lMapDetails1;
	TLabel *lMapDetails2;
	TCheckBox *cbHighlightMode;
	TRadioButton *rbBySize;
	TRadioButton *rbByQuantity;
	TPanel *pMap;
	TLabel *lDebug;
	void __fastcall rbBySizeClick(TObject *Sender);
	void __fastcall cbMapSizeSelectChange(TObject *Sender);
	void __fastcall cbHighlightModeClick(TObject *Sender);
private:

	const static int kBlockSizeA = 0;
	const static int kBlockSizeB = 1;

	int OldIndex = -1;

	XMap *MapX;

	void Init();

	void __fastcall OnMouseClick(int);
	void __fastcall OnMouseMove(int);
	void __fastcall OnDebug(const std::wstring);

public:
	__fastcall TFrameMap(TComponent* Owner);

	int DataSource = 0;

	bool HasData = false;
	bool NeedsRefresh = true;

	void DeInit();

	void Clear();
	void Update();

	void SetDataSource(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameMap *FrameMap;
//---------------------------------------------------------------------------
#endif
