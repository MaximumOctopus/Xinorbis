//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Code\Frames\XFrameProperties.cpp", FrameProperties); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameMap.cpp", Frame6); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameExploder.cpp", Frame5); /* TFrame: File Type */
USEFORM("Code\Forms\XFormSearchWizard.cpp", Form11);
USEFORM("Code\Forms\XFormSearchSyntax.cpp", Form12);
USEFORM("Code\Frames\XFrameSummary.cpp", FrameSummary); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameStructure.cpp", Frame4); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSelect.cpp", FrameSelect); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSearch.cpp", Frame7); /* TFrame: File Type */
USEFORM("main.cpp", Form1);
USEFORM("Code\Forms\XFormFileSpread.cpp", Form2);
USEFORM("Code\Forms\XFormFileAges.cpp", Form3);
USEFORM("Code\Forms\XFormExplore.cpp", Form4);
USEFORM("Code\Forms\XFormAbout.cpp", Form9);
USEFORM("Code\Forms\XFormReportOptions.cpp", Form8);
USEFORM("Code\Forms\XFormLanguageSelect.cpp", Form10);
USEFORM("Code\Forms\XFormGetSizeBetween.cpp", Form5);
USEFORM("Code\Forms\XFormGetDateBetween.cpp", Form6);
USEFORM("Code\Forms\XFormGetDate.cpp", Form7);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Carbon");
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm11), &Form11);
		Application->CreateForm(__classid(TForm12), &Form12);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
