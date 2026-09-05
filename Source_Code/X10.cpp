//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Code\Frames\XFrameWebReports.cpp", Frame3); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSummary.cpp", FrameSummary); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameMap.cpp", FrameMap); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameFolderHistory.cpp", FrameFolderHistory); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameExploder.cpp", FrameExploder); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameProperties.cpp", FrameProperties); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameStructure.cpp", FrameStructure); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSelect.cpp", FrameSelect); /* TFrame: File Type */
USEFORM("Code\Frames\XFrameSearch.cpp", FrameSearch); /* TFrame: File Type */
USEFORM("Code\Forms\XFormUserWizard.cpp", Form12);
USEFORM("Code\Forms\XFormShowMD5.cpp", Form22);
USEFORM("Code\Forms\XFormReference.cpp", Form2);
USEFORM("Code\Forms\XFormQuickMenuBuilder.cpp", Form9);
USEFORM("Code\Forms\XFormMoreDetail.cpp", FormMoreDetail);
USEFORM("Code\Forms\XFormReportOptions.cpp", Form8);
USEFORM("Code\Forms\XFormSearchWizard.cpp", Form11);
USEFORM("Code\Forms\XFormSearchSyntax.cpp", FormSearchSyntax);
USEFORM("Code\Forms\XFormReportSave.cpp", FormReportSaves);
USEFORM("Code\Frames\XFrameDuplicates.cpp", FrameDuplicates); /* TFrame: File Type */
USEFORM("main.cpp", FormMain);
USEFORM("Code\Forms\System\XFormDebug.cpp", FormDebug);
USEFORM("Code\Forms\System\XFormCheckVersion.cpp", FormCheckVersion);
USEFORM("Code\Forms\Splash\XFormSplash.cpp", FormProgress);
USEFORM("Code\Forms\System\XFormHelp.cpp", Form1);
USEFORM("Code\Forms\System\XFormSettings.cpp", FormSettings);
USEFORM("Code\Forms\System\XFormSelectLanguage.cpp", Form3);
USEFORM("Code\Forms\System\XFormLog.cpp", FormLog);
USEFORM("Code\Forms\Splash\XFormProgress.cpp", Form18);
USEFORM("Code\Forms\Editing\XFormEditCSVReport.cpp", FormEditCSVReport);
USEFORM("Code\Forms\Data\XFormImportFromCSV.cpp", FormImportCSV);
USEFORM("Code\Forms\Database\XFormDBSelectedFolder.cpp", Form20);
USEFORM("Code\Forms\Editing\XFormEditHTMLReport.cpp", FormEditHTMLReport);
USEFORM("Code\Forms\Editing\XFormEditXmlReport.cpp", FormEditXmlReport);
USEFORM("Code\Forms\Editing\XFormEditTreeReport.cpp", FormEditTreeReport);
USEFORM("Code\Forms\Editing\XFormEditTextReport.cpp", FormEditTextReport);
USEFORM("Code\Forms\XFormFileSpread.cpp", FormFileSpread);
USEFORM("Code\Forms\XFormFileAssociations.cpp", FormFileAssociations);
USEFORM("Code\Forms\XFormFileAges.cpp", FormFileAges);
USEFORM("Code\Forms\XFormGetCopyMove.cpp", FormGetCopyMove);
USEFORM("Code\Forms\XFormGetSizeBetween.cpp", Form5);
USEFORM("Code\Forms\XFormGetDateBetween.cpp", Form6);
USEFORM("Code\Forms\XFormGetDate.cpp", Form7);
USEFORM("Code\Forms\XFormExcludeFolders.cpp", Form15);
USEFORM("Code\Forms\XFormCalendar.cpp", Form21);
USEFORM("Code\Forms\XFormAbout.cpp", FormAbout);
USEFORM("Code\Forms\System\XFormXinorbisDialog.cpp", FormXDialog);
USEFORM("Code\Forms\XFormCategoryColours.cpp", FormCategoryColours);
USEFORM("Code\Forms\XFormExcludeFiles.cpp", Form14);
USEFORM("Code\Forms\XFormCombine.cpp", Form13);
USEFORM("Code\Forms\XFormChartOptions.cpp", Form17);
USEFORM("Code\Forms\Database\XFormDatabaseInfo.cpp", Form19);
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
