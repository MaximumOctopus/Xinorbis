//---------------------------------------------------------------------------

#ifndef XFrameExploderH
#define XFrameExploderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>

#include "XExploder.h"

#include "FolderDetail.h"
#include "XExploderDataObject.h"

//---------------------------------------------------------------------------
class TFrameExploder : public TFrame
{
__published:	// IDE-managed Components
	TPanel *pExploderTop;
	TLabel *lExploderFolder;
	TShape *shapeExploder;
	TBitBtn *bBack;
	TLabel *lExploderDetails2;
	TLabel *lExploderDetails1;
	TRadioButton *rbByQuantity;
	TRadioButton *rbBySize;
	TPanel *pExploder;
	void __fastcall rbBySizeClick(TObject *Sender);
	void __fastcall pExploderResize(TObject *Sender);
private:

	XExploder *ExploderX;

	std::vector<XExploderDataObject*> ExploderCache;
	std::vector<FolderDetail*> DirectoryList;

	bool HasData = false;
    bool AddToCache = false;
	int DirectoryIndex = -1;
	int OldIndex = -1;

	void Init();
    void DeInit();

	void BuildFromCache();
	void BuildFromFolderID(int, int, unsigned __int64);

	void ClearExploder();

	void BeginData(const std::wstring, int, unsigned __int64);
	void AddData(const std::wstring, int, int, unsigned __int64, int);
	void EndData();

    void AddItemToCache(const std::wstring, int, int, unsigned __int64, int);

	void __fastcall OnMouseMove(int);
	void __fastcall OnMouseClick(int, int, unsigned __int64);
	void __fastcall OnGoBack();
	void __fastcall OnMouseDblClick(int);
	void __fastcall OnMouseRightClick(int);


public:		// User declarations
	__fastcall TFrameExploder(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameExploder *FrameExploder;
//---------------------------------------------------------------------------
#endif
