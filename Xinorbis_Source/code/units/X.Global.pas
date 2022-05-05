unit X.Global;

interface

uses
  Classes, ComCtrls, Contnrs, SysUtils, Generics.Defaults, System.Generics.Collections,
  Registry, Windows,

  X.CFileObject, X.CUserData,
  X.FileExtension, X.CFolderHistoryInfo, X.Constants, X.LanguageHandler;


var
  FHCCStatus             : array[0..19] of boolean;
  HGraphData             : TStringList;
  FHGraphData            : TStringList;

  // ----------------------------------------------------------------------------

  months                 : array[1..12] of string;
  shortmonths            : array[1..12] of String;
  TypeDescriptions       : array[0..19] of string;
  TypeDescriptionsSmall  : array[0..19] of string;

  LanguageTabs           : array[0..11] of string;
  LanguageTypes          : array[0..__AttributesTotalCount] of string;

  TextReport             : array[0..18] of string;
  SummaryReport          : array[0..14] of string;
  DriveReport            : array[0..10] of string;
  GenericReportItems     : array[0..17] of string;
  OtherReportItems       : array[1..9] of string;

  ExtSpreadSearch        : array[0..__FileCategoriesCount, 1..2] of Int64;

  // ============================================================================

  CompareFileNames          : TComparison<TFileObject>;
  CompareFileSizes          : TComparison<TFileObject>;
  CompareFileDates          : TComparison<TFileObject>;
  CompareFileAttributes     : TComparison<TFileObject>;
  CompareFileDatesCreated   : TComparison<TFileObject>;
  CompareFileDatesAccessed  : TComparison<TFileObject>;
  CompareFileDatesModified  : TComparison<TFileObject>;
  CompareFileNamePathLS     : TComparison<TFileObject>;
  CompareFileNamePathFH     : TComparison<TFileObject>;
  CompareFileNamePathTreeLS : TComparison<TFileObject>;
  CompareFileNamePathTreeFH : TComparison<TFileObject>;

  CompareOwnerSD            : TComparison<TFileObject>;

  CompareFHPaths            : TComparison<TFolderHistoryInfo>;

  CompareExtensions         : TComparison<TFileExtension>;

  SortUsersBySizeDesc       : TComparison<TUserData>;
  SortUsersBySizeAsc        : TComparison<TUserData>;
  SortUsersByCountDesc      : TComparison<TUserData>;
  SortUsersByCountAsc       : TComparison<TUserData>;


type
  TGlobal = class
    class procedure InitialiseSortCode;
    class procedure InitialiseGlobalText;

    class procedure LoadTypeDescriptions;
  end;


{  XText[rsTextReport1  = '==================================================================';
  XText[rsTextReport2  = '-- File Types ----------------------------------------------------';
  XText[rsTextReport3  = 'Category --------------------- Qty --- As % ---- Size -- As % ----';
  XText[rsTextReport4  = '-- Attributes ----------------------------------------------------';
  XText[rsTextReport5  = 'Attributes ------------------- Qty --- As % ---- Size -- As % ----';
  XText[rsTextReport6  = '-- Folder List ---------------------------------------------------';
  XText[rsTextReport7  = 'Folder ----------------------- Qty --- As % ---- Size -- As % ----';
  XText[rsTextReport8  = '-- Magnitudes ----------------------------------------------------';
  XText[rsTextReport9  = '-- Extension Details ---------------------------------------------';
  XText[rsTextReport10 = '-- Null Files ----------------------------------------------------';
  XText[rsTextReport11 = '-- Empty Folders -------------------------------------------------';
  XText[rsTextReport12 = '-- Users ---------------------------------------------------------';
  XText[rsTextReport13 = 'Name ------------------------- Qty --- As % ---- Size -- As % ----';
  XText[rsTextReport14 = '-- Top 101 Largest Files -----------------------------------------';
  XText[rsTextReport15 = '-- Top 101 Smallest Files ----------------------------------------';
  XText[rsTextReport16 = '-- Top 101 Newest Files ------------------------------------------';
  XText[rsTextReport17 = '-- Top 101 Oldest Files ------------------------------------------';

  XText[rsSummReport0  = '                Analysed :';
  XText[rsSummReport1  = ' Number of Files         :';
  XText[rsSummReport2  = ' Number of Folders       :';
  XText[rsSummReport3  = ' Size of Files           :';
  XText[rsSummReport4  = ' Size of Files (on disk) :';
  XText[rsSummReport5  = ' Disk space wasted       :';
  XText[rsSummReport6  = ' Null files              :';
  XText[rsSummReport7  = ' Empty folders           :';
  XText[rsSummReport8  = ' Average File Size       :';
  XText[rsSummReport9  = ' Average Files/Folder    :';
  XText[rsSummReport10 = ' Largest Folder          : \';
  XText[rsSummReport12 = ' Largest Folder          : <root> (';
  XText[rsSummReport13 = ' Largest File            :';
  XText[rsSummReport14 = ' User with largest share :';
  XText[rsSummReport15 = '                         : Quantity     Size';

  XText[rsDriveReport0  = ' Drive Type              :';
  XText[rsDriveReport1  = ' Space on Drive          :';
  XText[rsDriveReport2  = ' Free Space              :';
  XText[rsDriveReport3  = ' Sectors per Cluster     :';
  XText[rsDriveReport4  = ' Bytes per Sector        :';
  XText[rsDriveReport5  = ' Free Clusters           :';
  XText[rsDriveReport6  = ' Total Clusters          :';
  XText[rsDriveReport7  = ' Volume Name             :';
  XText[rsDriveReport8  = ' Serial Number           :';
  XText[rsDriveReport9  = ' File System             :';
  XText[rsDriveReport10 = ' Drive Type              : Remote (Network) Drive';

  XText[rsHTMLReport0  = 'Charts and Images';
  XText[rsHTMLReport1  = 'Header';
  XText[rsHTMLReport2  = 'Simple summary';
  XText[rsHTMLReport3  = 'File attributes';
  XText[rsHTMLReport4  = 'Categories';
  XText[rsHTMLReport5  = 'Folders within root';
  XText[rsHTMLReport6  = 'Magnitude data';
  XText[rsHTMLReport7  = 'Categories and file extension';
  XText[rsHTMLReport8  = 'Null files / folders';
  XText[rsHTMLReport9  = 'File dates (Created)';
  XText[rsHTMLReport10 = 'File dates (Accessed)';
  XText[rsHTMLReport11 = 'File dates (Modified)';
  XText[rsHTMLReport12 = 'User details';
  XText[rsHTMLReport13 = 'Top 101 largest Files';
  XText[rsHTMLReport14 = 'Top 101 smallest Files';
  XText[rsHTMLReport15 = 'Top 101 newest files';
  XText[rsHTMLReport16 = 'Top 101 oldest files';

  XText[rsORIReport1 = 'Header';
  XText[rsORIReport2 = 'File / folder count';
  XText[rsORIReport3 = 'File size';
  XText[rsORIReport4 = 'Null files / folders';
  XText[rsORIReport5 = 'Averages';
  XText[rsORIReport6 = 'Largest file / folder';
  XText[rsORIReport7 = 'User';
  XText[rsORIReport8 = 'Category stats';
  XText[rsORIReport9 = 'Drive';     }


implementation


uses
  X.GlobalObjects;


class procedure TGlobal.InitialiseSortCode;
begin
  CompareFileAttributes := function(const Left, Right : TFileObject): integer
                           begin
                             if Left.Attributes > Right.Attributes then
                               Result := 1
                             else if Left.Attributes < Right.Attributes then
                               Result := -1
                             else
                               Result := 0;
                           end;

  CompareFileNames := function(const Left, Right : TFileObject): integer
                      begin
                        Result := AnsiCompareText(Left.FileName, Right.FileName);
                      end;

  CompareFileSizes := function(const Left, Right : TFileObject): integer
                      begin
                        if Left.FileSize > Right.FileSize then
                          Result := 1
                        else if Left.FileSize < Right.FileSize then
                          Result := -1
                        else
                          Result := 0;
                      end;

  CompareFileDates := function(const Left, Right : TFileObject): integer
                      begin
                        if Left.FileDateC > Right.FileDateC then
                          Result := 1
                        else if Left.FileDateC < Right.FileDateC then
                          Result := -1
                        else
                          Result := 0;
                      end;

  CompareFileDatesCreated := function(const Left, Right : TFileObject): integer
                      begin
                        if Left.FileDateC > Right.FileDateC then
                          Result := 1
                        else if Left.FileDateC < Right.FileDateC then
                          Result := -1
                        else
                          Result := 0;
                      end;

  CompareFileDatesAccessed := function(const Left, Right : TFileObject): integer
                      begin
                        if Left.FileDateA > Right.FileDateA then
                          Result := 1
                        else if Left.FileDateA < Right.FileDateA then
                          Result := -1
                        else
                          Result := 0;
                      end;

  CompareFileDatesModified := function(const Left, Right : TFileObject): integer
                      begin
                        if Left.FileDateM > Right.FileDateM then
                          Result := 1
                        else if Left.FileDateM < Right.FileDateM then
                          Result := -1
                        else
                          Result := 0;
                      end;

  CompareFileNamePathLS := function(const Left, Right : TFileObject): integer
                      begin
                          Result := CompareText(GScanDetails[dataLatestScan].Folders[Left.FilePathIndex] + Left.FileName,
                                                GScanDetails[dataLatestScan].Folders[Right.FilePathIndex] + Right.FileName);
                      end;

  CompareFileNamePathFH := function(const Left, Right : TFileObject): integer
                      begin
                        Result := CompareText(GScanDetails[dataFolderHistory].Folders[Left.FilePathIndex] + Left.FileName,
                                              GScanDetails[dataFolderHistory].Folders[Right.FilePathIndex] + Right.FileName);
                      end;

  CompareFileNamePathTreeLS := function(const Left, Right : TFileObject): integer
                      begin
                        Result := CompareText(StringReplace(GScanDetails[dataLatestScan].Folders[Left.FilePathIndex] + Left.FileName, '\', ' ',   [rfReplaceAll]),
                                              StringReplace(GScanDetails[dataLatestScan].Folders[Right.FilePathIndex] + Right.FileName, '\', ' ', [rfReplaceAll]));
                      end;

  CompareFileNamePathTreeFH := function(const Left, Right : TFileObject): integer
                      begin
                        Result := CompareText(StringReplace(GScanDetails[dataFolderHistory].Folders[Left.FilePathIndex] + Left.FileName, '\', ' ',   [rfReplaceAll]),
                                              StringReplace(GScanDetails[dataFolderHistory].Folders[Right.FilePathIndex] + Right.FileName, '\', ' ', [rfReplaceAll]));
                      end;

  CompareOwnerSD   := function(const Left, Right : TFileObject): integer
                      begin
                          Result := CompareText(GScanDetails[dataSearch].Users[Left.Owner].Name,
                                                GScanDetails[dataSearch].Users[Right.Owner].Name);
                      end;

  // == File History ===========================================================

  CompareFHPaths   := function(const Left, Right : TFolderHistoryInfo): integer
                      begin
                        Result := CompareText(Left.ScanPath, Right.ScanPath);
                      end;

  CompareExtensions := function(const Left, Right : TFileExtension): integer
                      begin
                        Result := CompareText(Left.Name, Right.Name);
                      end;

  // == Users ==================================================================

  SortUsersBySizeDesc := function(const Left, Right : TUserData): integer
                      begin
                        if Left.Data[XUserSize] < Right.Data[XUserSize] then
                          Result := 1
                        else if Left.Data[XUserSize] > Right.Data[XUserSize] then
                          Result := -1
                        else
                          Result := 0;
                      end;

  SortUsersBySizeAsc:= function(const Left, Right : TUserData): integer
                      begin
                        if Left.Data[XUserSize] > Right.Data[XUserSize] then
                          Result := 1
                        else if Left.Data[XUserSize] < Right.Data[XUserSize] then
                          Result := -1
                        else
                          Result := 0;
                      end;

  SortUsersByCountDesc:= function(const Left, Right : TUserData): integer
                      begin
                        if Left.Data[XUserCount] < Right.Data[XUserCount] then
                          Result := 1
                        else if Left.Data[XUserCount] > Right.Data[XUserCount] then
                          Result := -1
                        else
                          Result := 0;
                      end;

  SortUsersByCountAsc := function(const Left, Right : TUserData): integer
                      begin
                        if Left.Data[XUserCount] > Right.Data[XUserCount] then
                          Result := 1
                        else if Left.Data[XUserCount] < Right.Data[XUserCount] then
                          Result := -1
                        else
                          Result := 0;
                      end;
end;


class procedure TGlobal.InitialiseGlobalText;
begin
  months[1]  := XText[rsJanuary]; months[2]  := XText[rsFebruary];  months[3]  := XText[rsMarch];
  months[4]  := XText[rsApril];   months[5]  := XText[rsMay];       months[6]  := XText[rsJune];
  months[7]  := XText[rsJuly];    months[8]  := XText[rsAugust];    months[9]  := XText[rsSeptember];
  months[10] := XText[rsOctober]; months[11] := XText[rsNovember];  months[12] := XText[rsDecember];

  shortmonths[1] := XText[rsJan]; shortmonths[2] := XText[rsFeb]; shortmonths[3] := XText[rsMar];
  shortmonths[4] := XText[rsApr];  shortmonths[5] := XText[rsMxy];  shortmonths[6] := XText[rsJun];
  shortmonths[7] := XText[rsJul]; shortmonths[8] := XText[rsAug];  shortmonths[9] := XText[rsSep];
  shortmonths[10] := XText[rsOct];  shortmonths[11] := XText[rsNov];  shortmonths[12] := XText[rsDec];

  TypeDescriptions[0]  := XText[rsTemporary];  TypeDescriptions[1]  := XText[rsPrograms];
  TypeDescriptions[2]  := XText[rsSystem];     TypeDescriptions[3]  := XText[rsGraphics];
  TypeDescriptions[4]  := XText[rsMovie];      TypeDescriptions[5]  := XText[rsAudio];
  TypeDescriptions[6]  := XText[rsOffice];     TypeDescriptions[7]  := XText[rsProgramming];
  TypeDescriptions[8]  := XText[rsCompressed]; TypeDescriptions[9]  := XText[rsUncategorised];
  TypeDescriptions[10] := XText[rsCustom1];    TypeDescriptions[11] := XText[rsCustom2];
  TypeDescriptions[12] := XText[rsCustom3];    TypeDescriptions[13] := XText[rsCustom4];
  TypeDescriptions[14] := XText[rsCustom5];    TypeDescriptions[15] := XText[rsCustom6];
  TypeDescriptions[16] := XText[rsCustom7];    TypeDescriptions[17] := XText[rsCustom8];
  TypeDescriptions[18] := XText[rsCustom9];    TypeDescriptions[19] := XText[rsCustom10];

  TypeDescriptionsSmall[0]  := XText[rsTMP];   TypeDescriptionsSmall[1]  := XText[rsEXE];
  TypeDescriptionsSmall[2]  := XText[rsSYS];   TypeDescriptionsSmall[3]  := XText[rsGFX];
  TypeDescriptionsSmall[4]  := XText[rsMOV];   TypeDescriptionsSmall[5]  := XText[rsSFX];
  TypeDescriptionsSmall[6]  := XText[rsOFF];   TypeDescriptionsSmall[7]  := XText[rsPRG];
  TypeDescriptionsSmall[8]  := XText[rsZIP];   TypeDescriptionsSmall[9]  := XText[rsUncat];
  TypeDescriptionsSmall[10] := XText[rsC1];    TypeDescriptionsSmall[11] := XText[rsC2];
  TypeDescriptionsSmall[12] := XText[rsC3];    TypeDescriptionsSmall[13] := XText[rsC4];
  TypeDescriptionsSmall[14] := XText[rsC5];    TypeDescriptionsSmall[15] := XText[rsC6];
  TypeDescriptionsSmall[16] := XText[rsC7];    TypeDescriptionsSmall[17] := XText[rsC8];
  TypeDescriptionsSmall[18] := XText[rsC9];    TypeDescriptionsSmall[19] := XText[rsC10];

  TextReport[0]  := XText[rsTextReport1];
  TextReport[1]  := XText[rsTextReport2];
  TextReport[2]  := XText[rsTextReport3];
  TextReport[3]  := XText[rsTextReport4];
  TextReport[4]  := XText[rsTextReport5];
  TextReport[5]  := XText[rsTextReport6];
  TextReport[6]  := XText[rsTextReport7];
  TextReport[7]  := XText[rsTextReport8];
  TextReport[8]  := XText[rsTextReport9];
  TextReport[9]  := XText[rsTextReport10];
  TextReport[10] := XText[rsTextReport11];
  TextReport[11] := XText[rsTextReport12];
  TextReport[12] := XText[rsTextReport13];
  TextReport[13] := XText[rsTextReport14];
  TextReport[14] := XText[rsTextReport15];
  TextReport[15] := XText[rsTextReport16];
  TextReport[16] := XText[rsTextReport17];
  TextReport[17] := XText[rsTextReport18];
  TextReport[18] := XText[rsTextReport19];

  LanguageTypes[0]  := XText[rsNull] + ' ' + XText[rsFolders];
  LanguageTypes[1]  := XText[rsHidden];
  LanguageTypes[2]  := XText[rsSystem];
  LanguageTypes[3]  := XText[rsArchive];
  LanguageTypes[4]  := XText[rsNullFiles];
  LanguageTypes[5]  := XText[rsReadOnly];
  LanguageTypes[6]  := XText[rsCompressed];
  LanguageTypes[7]  := XText[rsEncrypted];
  LanguageTypes[8]  := 'Recall on Open';
  LanguageTypes[9]  := 'Recall on Data Access';
  LanguageTypes[10] := XText[rsOffline];
  LanguageTypes[11] := XText[rsCreatedToday];
  LanguageTypes[12] := XText[rsAccessedToday];
  LanguageTypes[13] := XText[rsModifiedToday];

  LanguageTypes[14] := XText[rsTemporary];
  LanguageTypes[15] := XText[rsFolder];
  LanguageTypes[16] := XText[rsFile];
  LanguageTypes[17] := 'No extension';
  LanguageTypes[18] := XText[rsSparseFile];
  LanguageTypes[19] := XText[rsReparseFile];
  LanguageTypes[20] := XText[rsNotContentIndexed];

  GenericReportItems[0]  := XText[rsHTMLReport1];
  GenericReportItems[1]  := XText[rsHTMLReport2];
  GenericReportItems[2]  := XText[rsHTMLReport3];
  GenericReportItems[3]  := XText[rsHTMLReport4];
  GenericReportItems[4]  := XText[rsHTMLReport5];
  GenericReportItems[5]  := XText[rsHTMLReport6];
  GenericReportItems[6]  := XText[rsHTMLReport7];
  GenericReportItems[7]  := XText[rsHTMLReport8];
  GenericReportItems[8]  := XText[rsHTMLReport9];
  GenericReportItems[9]  := XText[rsHTMLReport10];
  GenericReportItems[10] := XText[rsHTMLReport11];
  GenericReportItems[11] := XText[rsHTMLReport12];
  GenericReportItems[12] := XText[rsHTMLReport13];
  GenericReportItems[13] := XText[rsHTMLReport14];
  GenericReportItems[14] := XText[rsHTMLReport15];
  GenericReportItems[15] := XText[rsHTMLReport16];
  GenericReportItems[16] := XText[rsHTMLReport17];
  GenericReportItems[17] := XText[rsFileNameLength];

  SummaryReport[0]  := XText[rsSummReport1]  + ' ';
  SummaryReport[1]  := XText[rsSummReport2]  + ' ';
  SummaryReport[2]  := XText[rsSummReport3]  + ' ';
  SummaryReport[3]  := XText[rsSummReport4]  + ' ';
  SummaryReport[4]  := XText[rsSummReport5]  + ' ';
  SummaryReport[5]  := XText[rsSummReport6]  + ' ';
  SummaryReport[6]  := XText[rsSummReport7]  + ' ';
  SummaryReport[7]  := XText[rsSummReport8]  + ' ';
  SummaryReport[8]  := XText[rsSummReport9]  + ' ';
  SummaryReport[9]  := XText[rsSummReport10] + ' ';
  SummaryReport[10] := XText[rsSummReport11] + ' ';
  SummaryReport[11] := XText[rsSummReport12] + ' ';
  SummaryReport[12] := XText[rsSummReport13] + ' ';
  SummaryReport[13] := XText[rsSummReport14] + ' ';
  SummaryReport[14] := XText[rsSummReport15] + ' ';

  DriveReport[0]  := XText[rsDriveReport1]  + ' ';
  DriveReport[1]  := XText[rsDriveReport2]  + ' ';
  DriveReport[2]  := XText[rsDriveReport3]  + ' ';
  DriveReport[3]  := XText[rsDriveReport4]  + ' ';
  DriveReport[4]  := XText[rsDriveReport5]  + ' ';
  DriveReport[5]  := XText[rsDriveReport6]  + ' ';
  DriveReport[6]  := XText[rsDriveReport7]  + ' ';
  DriveReport[7]  := XText[rsDriveReport8]  + ' ';
  DriveReport[8]  := XText[rsDriveReport9]  + ' ';
  DriveReport[9]  := XText[rsDriveReport10] + ' ';
  DriveReport[10] := XText[rsDriveReport11] + ' ';
end;


class procedure TGlobal.LoadTypeDescriptions;
var
  Reg: TRegistry;
  t : integer;

  function ReadRegistryString(const keyname : string; const defaultval : string): string;
   begin
    if Reg.ValueExists(keyname) then
      Result := Reg.ReadString(keyname)
    else
      Result := defaultval;
  end;


begin
  Reg := TRegistry.Create(KEY_READ);

    try
      Reg.RootKey := HKEY_CURRENT_USER;
      Reg.OpenKey('\software\' + XinorbisRegistryKey + '\Xinorbis8', True);

      for t := 1 to 10 do
        TypeDescriptions[t + 9] := ReadRegistryString('Custom' + IntToStr(t), TypeDescriptions[t + 9]);
    finally
      Reg.Free;
    end;
end;


end.
