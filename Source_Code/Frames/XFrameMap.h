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
	void __fastcall rbBySizeClick(TObject *Sender);
	void __fastcall cbMapSizeSelectChange(TObject *Sender);
	void __fastcall cbHighlightModeClick(TObject *Sender);
private:

	const static int kBlockSizeA = 0;
	const static int kBlockSizeB = 1;

	bool HasData = false;
	int OldIndex = -1;

	XMap *MapX;

	void Init();

    void ClearMap();

	void __fastcall OnMouseClick(int);
    void __fastcall OnMouseMove(int);

public:
	__fastcall TFrameMap(TComponent* Owner);

	void DeInit();

	void BeginData();
	void AddData(const std::wstring, int, unsigned __int64, int);
	void EndData();

	void SetDataSource(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameMap *FrameMap;
//---------------------------------------------------------------------------
#endif
