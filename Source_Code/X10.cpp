//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Code\Frames\XFrameExploder.cpp", FrameExploder); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSummary.cpp", FrameSummary); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameMap.cpp", FrameMap); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameProperties.cpp", FrameProperties); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSearch.cpp", FrameSearch); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSelect.cpp", FrameSelect); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameStructure.cpp", FrameStructure); /* TFrame: File Type */
USEFORM("Code\Forms\XFormExplore.cpp", Form4);
USEFORM("Code\Forms\XFormFileAges.cpp", FormFileAges);
USEFORM("Code\Forms\XFormFileSpread.cpp", FormFileSpread);
USEFORM("Code\Forms\XFormGetDate.cpp", Form7);
USEFORM("Code\Forms\XFormGetDateBetween.cpp", Form6);
USEFORM("Code\Forms\XFormAbout.cpp", FormAbout);
USEFORM("Code\Forms\XFormCategoryColours.cpp", Form2);
USEFORM("Code\Forms\XFormChartOptions.cpp", Form17);
USEFORM("Code\Forms\XFormExcludeFiles.cpp", Form14);
USEFORM("Code\Forms\XFormExcludeFolders.cpp", Form15);
USEFORM("Code\Forms\XFormSearchWizard.cpp", Form11);
USEFORM("Code\Forms\XFormGetSizeBetween.cpp", Form5);
USEFORM("Code\Forms\XFormLanguageSelect.cpp", Form10);
USEFORM("Code\Forms\XFormMoreDetail.cpp", Form16);
USEFORM("Code\Forms\XFormReportOptions.cpp", Form8);
USEFORM("Code\Forms\XFormSearchSyntax.cpp", Form12);
USEFORM("main.cpp", FormMain);
USEFORM("Code\Forms\System\XFormXinorbisDialog.cpp", FormXDialog);
USEFORM("Code\Forms\Editing\XFormEditXmlReport.cpp", Form20);
USEFORM("Code\Forms\Splash\XFormProgress.cpp", Form18);
USEFORM("Code\Forms\Splash\XFormSplash.cpp", FormProgress);
USEFORM("Code\Forms\System\XFormSelectLanguage.cpp", Form3);
USEFORM("Code\Forms\System\XFormSettings.cpp", Form23);
USEFORM("Code\Forms\Data\XFormImportFromCSV.cpp", FormImportCSV);
USEFORM("Code\Forms\Editing\XFormEditCSVReport.cpp", Form13);
USEFORM("Code\Forms\Editing\XFormEditHTMLReport.cpp", Form22);
USEFORM("Code\Forms\Editing\XFormEditTextReport.cpp", Form21);
USEFORM("Code\Forms\Editing\XFormEditTreeReport.cpp", Form19);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TFormAbout), &FormAbout);
		TStyleManager::TrySetStyle("Carbon");
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
