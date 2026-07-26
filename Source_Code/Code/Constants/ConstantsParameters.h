// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/Xinorbis
//
// =====================================================================

#pragma once

const static std::wstring kCmdConsole = L"/console";

const static std::wstring kCmdCompare = L"/compare";

const static std::wstring kCmdNoUsers = L"/nouser";
const static std::wstring kCmdNoProcess = L"/noprocess";
const static std::wstring kCmdNoTemp = L"/notemp";
const static std::wstring kCmdNoOutput = L"/nooutput";

const static std::wstring kCmdTest = L"/test";
const static std::wstring kCmdStatistics = L"/stats";
const static std::wstring kCmdListRoot = L"/listroot";

//const static std::wstring k L"/p") != std::wstring::npos) { return 0x01; }
//const static std::wstring k L"/o") != std::wstring::npos) { return 0x02; }

const static std::wstring kCmdCats = L"/meow";
const static std::wstring kCmdLoadConfig = L"/load";
const static std::wstring kCmdSaveConfig = L"/save";

const static std::wstring kCmdCSVReport = L"/csv";
const static std::wstring kCmdHTMLReport = L"/html";
const static std::wstring kCmdJSONReport = L"/json";
const static std::wstring kCmdTextReport = L"/txt";
const static std::wstring kCmdTreeReport = L"/tree";
const static std::wstring kCmdXMLReport = L"/xml";
const static std::wstring kCmdXFLReport = L"/xfl";
const static std::wstring kCmdXinorbisReport = L"/xin";
const static std::wstring kCmdDeepHTMLReport = L"/deephtml";
const static std::wstring kCmdDeepTextReport = L"/deeptext";

const static std::wstring kCmdDateReportDay = L"/dated";
const static std::wstring kCmdDateReportMonth = L"/datem";
const static std::wstring kCmdDateReportYear = L"/datey";

const static std::wstring kCmdSummary = L"/sum";
const static std::wstring kCmdAllTwenty = L"/all20";
const static std::wstring kCmdTopTwenty = L"/top20";
const static std::wstring kCmdBottomTwenty = L"/bottom20";
const static std::wstring kCmdNewTwenty = L"/new20";
const static std::wstring kCmdOldTwenty = L"/old20";
const static std::wstring kCmdFolderTopTwenty = L"/folderstop20";

const static std::wstring kCmdAttributes = L"/attributes";
const static std::wstring kCmdCategories = L"/categories";
const static std::wstring kCmdExtensions = L"/extensions";
const static std::wstring kCmdFileDates = L"/filedates";
const static std::wstring kCmdMagnitude = L"/magnitude";
const static std::wstring kCmdNullFiles = L"/nullfiles";
const static std::wstring kCmdTemporaryFiles = L"/tempfiles";
const static std::wstring kCmdUsers = L"/users";
const static std::wstring kCmdBenford = L"/benford";

const static std::wstring kCmdDuplicateFileName = L"/dn";
const static std::wstring kCmdDuplicateFileSize = L"/ds";

const static std::wstring kCmdAllFolders = L"/allfolders";
const static std::wstring kCmdAllowVirtual = L"/allowvirtual";

const static std::wstring kCmdFilterCategory = L"/filter";

const static std::wstring kCmdExcludeFile = L"/xf";
const static std::wstring kCmdExcludeFolder = L"/xd";

const static std::wstring kCmdExcludeHidden = L"/xh";
const static std::wstring kCmdExcludeReadOnly = L"/xr";
const static std::wstring kCmdExcludeTemp = L"/xt";

const static std::wstring kCmdSetContextMenu = L"/setcontextmenu";
const static std::wstring kCmdDeleteContextMenu = L"/deletecontextmenu";


enum class ParameterOption {
	None = 0, ScanFolder = 1, Cats = 2,
	LoadConfig = 3, SaveConfig = 4,
	CSVReport = 5, HTMLReport = 6, JSONReport = 7, TextReport = 8, TreeReport = 9, XMLReport = 10, XMLFullListReport = 11, XinorbisReport = 12, DeepHTMLReport = 13, DeepTextReport = 14,
	Summary = 14, TopTwenty = 15, BottomTwenty = 16, NewTwenty = 17, OldTwenty = 18, FolderTopTwenty = 19, AllTwenty = 20, ReportCategories = 21, ReportUsers = 22,
	ReportDuplicateFileName = 23, ReportDuplicateFileSize = 24,
	AllFolders = 25, AllVirtual = 26,
	NoUsers = 27, NoProcess = 28, NoTemp = 29,
	SetContextMenu = 30, DeleteContextMenu = 31,
	Statistics = 32, ListRoot = 33, NoOutput = 34,
	ReportExtensions = 35, ReportFileDates = 36, ReportMagnitude = 37, ReportAttributes = 38,
	ReportNullFiles = 39, ReportTemporaryFiles = 40,
	ExcludeHidden = 41, ExcludeReadOnly = 42, ExcludeTemp = 43, ExcludeFolder = 44, ExcludeFile = 45,
	CSVImportFile = 46, FilterCategory = 47,
	BenfordsLaw = 48,
	Compare = 49, DateReportDay = 50, DateReportMonth = 51, DateReportYear = 52
};

static const int kCommandListCount = 53;

static const std::wstring CommandList[kCommandListCount] = {
	kCmdCats, kCmdLoadConfig, kCmdSaveConfig,
	kCmdCSVReport, kCmdHTMLReport, kCmdJSONReport, kCmdTextReport, kCmdTreeReport, kCmdXMLReport, kCmdXFLReport, kCmdXinorbisReport, kCmdDeepHTMLReport, kCmdDeepTextReport,
	kCmdSummary, kCmdTopTwenty, kCmdBottomTwenty, kCmdNewTwenty, kCmdOldTwenty, kCmdFolderTopTwenty, kCmdAllTwenty,
	kCmdAttributes, kCmdCategories, kCmdExtensions, kCmdFileDates, kCmdMagnitude, kCmdNullFiles, kCmdTemporaryFiles, kCmdUsers,
	kCmdDuplicateFileName, kCmdDuplicateFileSize,
	kCmdAllFolders, kCmdAllowVirtual,
	kCmdNoUsers, kCmdNoProcess, kCmdNoTemp,
	kCmdSetContextMenu, kCmdDeleteContextMenu,
	kCmdStatistics, kCmdListRoot, kCmdNoOutput,
	kCmdExcludeHidden, kCmdExcludeReadOnly, kCmdExcludeTemp, kCmdExcludeFolder, kCmdExcludeFile,
	kCmdFilterCategory,
	kCmdBenford,
	kCmdCompare, kCmdDateReportDay, kCmdDateReportMonth, kCmdDateReportYear
};

static const ParameterOption ParameterReference[kCommandListCount] = {
	ParameterOption::Cats, ParameterOption::LoadConfig, ParameterOption::SaveConfig,
	ParameterOption::CSVReport, ParameterOption::HTMLReport, ParameterOption::JSONReport, ParameterOption::TextReport, ParameterOption::TreeReport, ParameterOption::XMLReport, ParameterOption::XMLFullListReport, ParameterOption::XinorbisReport, ParameterOption::DeepHTMLReport, ParameterOption::DeepTextReport,
	ParameterOption::Summary, ParameterOption::TopTwenty, ParameterOption::BottomTwenty, ParameterOption::NewTwenty, ParameterOption::OldTwenty, ParameterOption::FolderTopTwenty, ParameterOption::AllTwenty,
	ParameterOption::ReportAttributes, ParameterOption::ReportCategories, ParameterOption::ReportExtensions, ParameterOption::ReportFileDates, ParameterOption::ReportMagnitude, ParameterOption::ReportNullFiles, ParameterOption::ReportTemporaryFiles, ParameterOption::ReportUsers,
	ParameterOption::ReportDuplicateFileName, ParameterOption::ReportDuplicateFileSize,
	ParameterOption::AllFolders, ParameterOption::AllVirtual,
	ParameterOption::NoUsers, ParameterOption::NoProcess, ParameterOption::NoTemp,
	ParameterOption::SetContextMenu, ParameterOption::DeleteContextMenu,
	ParameterOption::Statistics, ParameterOption::ListRoot, ParameterOption::NoOutput,
	ParameterOption::ExcludeHidden, ParameterOption::ExcludeReadOnly, ParameterOption::ExcludeTemp, ParameterOption::ExcludeFolder, ParameterOption::ExcludeFile,
	ParameterOption::FilterCategory,
	ParameterOption::BenfordsLaw,
	ParameterOption::Compare, ParameterOption::DateReportDay, ParameterOption::DateReportMonth, ParameterOption::DateReportYear
};

const static int kReportParametersCount = 30;

const static std::wstring ReportCommandList[kReportParametersCount] = {
	kCmdCSVReport, kCmdHTMLReport, kCmdJSONReport, kCmdSummary, kCmdTreeReport, kCmdTextReport, kCmdXMLReport, kCmdXFLReport, kCmdXinorbisReport,
	kCmdTopTwenty, kCmdBottomTwenty, kCmdNewTwenty, kCmdOldTwenty, kCmdAllTwenty,
	kCmdAttributes, kCmdCategories, kCmdExtensions, kCmdFileDates, kCmdMagnitude, kCmdNullFiles, kCmdTemporaryFiles, kCmdUsers,
	kCmdDuplicateFileName, kCmdDuplicateFileSize,
	kCmdDeepTextReport, kCmdDeepHTMLReport,
	kCmdBenford, kCmdDateReportDay, kCmdDateReportMonth, kCmdDateReportYear
};


struct ParameterData
{
	std::wstring OriginalInput = L"";					// original command-line switch

	std::wstring Command = L"";
	std::wstring ReportOptions = L"";
	std::wstring FileName = L"";
	std::wstring Value = L"";

	ParameterOption Parameter = ParameterOption::None;

	bool IsDatabase = false;
	bool IsProcessing = false;
	bool IsReport = false;

	bool IsDateReport = false;
	bool IsFileDateReport = false;
	bool IsSizeReport = false;
};


struct CompareData
{
	bool Enabled = false;
	std::wstring Path = L"";
};


struct OptimisationsData
{
	bool UseFastAnalysis = true;
	bool GetUserDetails = false;
};


struct StructFilter
{
	int Category = -1;
};
