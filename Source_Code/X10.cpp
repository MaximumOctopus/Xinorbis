//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("main.cpp", Form1);
USEFORM("Code\Frames\XFrameSelect.cpp", Frame1); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSummary.cpp", Frame2); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameProperties.cpp", Frame3); /* TFrame: File Type */
USEFORM("Code\Frames\XFraneStructure.cpp", Frame4); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameExploder.cpp", Frame5); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameMap.cpp", Frame6); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSearch.cpp", Frame7); /* TFrame: File Type */
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Carbon");
		Application->CreateForm(__classid(TForm1), &Form1);
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
