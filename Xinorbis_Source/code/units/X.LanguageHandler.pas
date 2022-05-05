{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.LanguageHandler;

interface

uses
  System.SysUtils, System.UITypes, Classes, Forms, Vcl.Dialogs,

  TMSLogging,

  X.Constants;

{$REGION constants}
const
  rsEllipsis                        = '...';

  rsJan                             = 0;
  rsFeb                             = 1;
  rsMar                             = 2;
  rsApr                             = 3;
  rsMxy                             = 4;
  rsJun                             = 5;
  rsJul                             = 6;
  rsAug                             = 7;
  rsSep                             = 8;
  rsOct                             = 9;
  rsNov                             = 10;
  rsDec                             = 11;
  rsJanuary                         = 12;
  rsFebruary                        = 13;
  rsMarch                           = 14;
  rsApril                           = 15;
  rsMay                             = 16;
  rsJune                            = 17;
  rsJuly                            = 18;
  rsAugust                          = 19;
  rsSeptember                       = 20;
  rsOctober                         = 21;
  rsNovember                        = 22;
  rsDecember                        = 23;
  rsAbout                           = 24;
  rsAccessed                        = 25;
  rsAccessedDate                    = 26;
  rsAccessedDateDDMMYYYY            = 27;
  rsAccessedDateMMDDYYYY            = 28;
  rsAccessedToday                   = 29;
  rsAddCurrentFolder                = 30;
  rsAddFileNamesToDateTab           = 31;
  rsAddTo                           = 32;
  rsAddZipFile                      = 33;
  rsAdvanced                        = 34;
  rsAdvancedOptions                 = 35;
  rsAfter                           = 36;
  rsAll                             = 37;
  rsAllOtherFiles                   = 38;
  rsAllowSQLStatementsWhenSearching = 39;
  rsAllUsers                        = 40;
  rsAnalysedAt                      = 41;
  rsAnalyseThisFolder               = 42;
  rsAnalysingData                   = 43;
  rsAnd                             = 44;
  rsAppearance                      = 45;
  rsArchive                         = 46;
  rsAreYouSureContinue              = 47;
  rsAsPercent                       = 48;
  rsAssociatedFileExtensions        = 49;
  rsAttr                            = 50;
  rsAudio                           = 51;
  rsAutomaticallyCheckForUpdates    = 52;
  rsAutoOpen                        = 53;
  rsAutoRefresh                     = 54;
  rsAutosave                        = 55;
  rsAutoSaveFolderReports           = 56;
  rsAutosaveOptions                 = 57;
  rsAutoSaveReports                 = 58;
  rsAvailable                       = 59;
  rsAvailableHow                    = 60;
  rsAvailableTimes                  = 61;
  rsAvanced                         = 62;
  rsBackupYourXinorbisData          = 63;
  rsBarGraphColour                  = 64;
  rsBarGraphResolution              = 65;
  rsBefore                          = 66;
  rsBlack                           = 67;
  rsBlue                            = 68;
  rsBuilding                        = 69;
  rsBuildingWebReports              = 70;
  rsByDate                          = 71;
  rsByQuantity                      = 72;
  rsBySize                          = 73;
  rsBytes                           = 74;
  rsC1                              = 75;
  rsC10                             = 76;
  rsC2                              = 77;
  rsC3                              = 78;
  rsC4                              = 79;
  rsC5                              = 80;
  rsC6                              = 81;
  rsC7                              = 82;
  rsC8                              = 83;
  rsC9                              = 84;
  rsCancel                          = 85;
  rsCategories                      = 86;
  rsCategory                        = 87;
  rsCategoryColours                 = 88;
  rsCDROM                           = 89;
  rsChange                          = 90;
  rsChart                           = 91;
  rsChartOptions                    = 92;
  rsChartZoomLevel                  = 93;
  rsCheckForUpdates                 = 94;
  rsChooseFolders                   = 95;
  rsChooseReportType                = 96;
  rsClearScanHistory                = 97;
  rsClearScanHistoryPrompt          = 98;
  rsClickToAdd                      = 99;
  rsClose                           = 100;
  rsCollapseNodes                   = 101;
  rsColourCode                      = 102;
  rsCombine                         = 103;
  rsCombineDrivesFolders            = 104;
  rsCompareFolder                   = 105;
  rsCompareFolderTree               = 106;
  rsCompressed                      = 107;
  rsCompressedFiles                 = 108;
  rsComputer                        = 109;
  rsConfigure                       = 110;
  rsContainingText                  = 111;
  rsContains                        = 112;
  rsContainsExclusions              = 113;
  rsContentsFirstRecord             = 114;
  rsContextHelp                     = 115;
  rsCopy                            = 116;
  rsCopyChartToClipboard            = 117;
  rsCopyLastReportToClipboard       = 118;
  rsCopyTableToClipboard            = 119;
  rsCopyTo                          = 120;
  rsCopyTreeClipboard               = 121;
  rsCreated                         = 122;
  rsCreatedDate                     = 123;
  rsCreatedDateDDMMYYYY             = 124;
  rsCreatedDateMMDDYYYY             = 125;
  rsCreatedToday                    = 126;
  rsCSVFiles                        = 127;
  rsCSVReport                       = 128;
  rsCSVReportSavedAs                = 129;
  rsCumulative                      = 130;
  rsCustom                          = 131;
  rsCustom1                         = 132;
  rsCustom10                        = 133;
  rsCustom2                         = 134;
  rsCustom3                         = 135;
  rsCustom4                         = 136;
  rsCustom5                         = 137;
  rsCustom6                         = 138;
  rsCustom7                         = 139;
  rsCustom8                         = 140;
  rsCustom9                         = 141;
  rsCustomise                       = 142;
  rsCustomReportFiles               = 143;
  rsCustomViewer                    = 144;
  rsCyan                            = 145;
  rsDate                            = 146;
  rsDateFormat                      = 147;
  rsDates                           = 148;
  rsDateTime                        = 149;
  rsDateTree                        = 150;
  rsDay                             = 151;
  rsDayInitials                     = 152;
  rsDayMonth                        = 153;
  rsDefaultCSVOutputSettings        = 154;
  rsDefaultTextReportOutputSettings = 155;
  rsDelete                          = 156;
  rsDeleteFHAreYouSure              = 157;
  rsDelta                           = 158;
  rsDetail                          = 159;
  rsDetailed                        = 160;
  rsDialog1                         = 161;
  rsDialog10                        = 162;
  rsWelcomeTo                       = 163;
  rsDialog12                        = 164;
  rsDialog13                        = 165;
  rsDialog2                         = 166;
  rsDialog3                         = 167;
  rsDialog4                         = 168;
  rsDialog5                         = 169;
  rsDialog6                         = 170;
  rsDialog7                         = 171;
  rsDialog8                         = 172;
  rsDialog9                         = 173;
  rsDifferenceLeft                  = 174;
  rsDifferenceRight                 = 175;
  rsDiskSpaceFree                   = 176;
  rsDiskSpaceUsed                   = 177;
  rsDiskSpaceWasted                 = 178;
  rsDocOptions                      = 179;
  rsDoesntContain                   = 180;
  rsDoNothing                       = 181;
  rsDontBuildDateTree               = 182;
  rsDontGetFileOwnerDetails         = 183;
  rsDriveCannotDetermind            = 184;
  rsDriveDetailsFor                 = 185;
  rsDriveFree                       = 186;
  rsDriveReport1                    = 187;
  rsDriveReport10                   = 188;
  rsDriveReport11                   = 189;
  rsDriveReport2                    = 190;
  rsDriveReport3                    = 191;
  rsDriveReport4                    = 192;
  rsDriveReport5                    = 193;
  rsDriveReport6                    = 194;
  rsDriveReport7                    = 195;
  rsDriveReport8                    = 196;
  rsDriveReport9                    = 197;
  rsDriveUsed                       = 198;
  rsDuplicateFilenames              = 199;
  rsDuplicatesFileName              = 200;
  rsDuplicatesFileSize              = 201;
  rsDuplicatesName                  = 202;
  rsDuplicatesSize                  = 203;
  rsEdit                            = 204;
  rsEditExclusion                   = 205;
  rsEmptyFolders                    = 206;
  rsEnableFolderHistory             = 207;
  rsEnableFullFileLogging           = 208;
  rsEncrypted                       = 209;
  rsEnterANameFor                   = 210;
  rsEqualTo                         = 211;
  rsErrorOpening                    = 212;
  rsErrorTitle                      = 213;
  rsExclude                         = 214;
  rsExcludedFiles                   = 215;
  rsExcludedFolder                  = 216;
  rsExcludedFolders                 = 217;
  rsExcludeFilesFromScan            = 218;
  rsExcludeFromScan                 = 219;
  rsEXE                             = 220;
  rsExists                          = 221;
  rsExit                            = 222;
  rsExplodeLargestSlice             = 223;
  rsExplore                         = 224;
  rsExploreFolder                   = 225;
  rsExploreThisFolder               = 226;
  rsExploring                       = 227;
  rsExportContent                   = 228;
  rsExportList                      = 229;
  rsExportSelectedFile              = 230;
  rsExportSelectedToFile            = 231;
  rsExtension                       = 232;
  rsExtensionOptions                = 233;
  rsExtensionOptions1               = 234;
  rsExtensionOptions2               = 235;
  rsExtensionOptions3               = 236;
  rsExtensions                      = 237;
  rsFavourite                       = 238;
  rsFavourites                      = 239;
  rsFieldDataType                   = 240;
  rsFile                            = 241;
  rsFileAccessHistory               = 242;
  rsFileAge                         = 243;
  rsFileAttributes                  = 244;
  rsFileCreationHistory             = 245;
  rsFileDates                       = 246;
  rsFileExtensions                  = 247;
  rsFileHistoryCompare              = 248;
  rsFileHistoryDBInfo               = 249;
  rsFileHistorySearch               = 250;
  rsFileModificationHistory         = 251;
  rsFileName                        = 252;
  rsFileOwner                       = 253;
  rsFilePath                        = 254;
  rsFileProperties                  = 255;
  rsFiles                           = 256;
  rsFileSize                        = 257;
  rsFileSizeBytes                   = 258;
  rsFileSizeOnDisk                  = 259;
  rsFileSizeSpread                  = 260;
  rsFilesLeftNotRight               = 261;
  rsFilesRightNotLeft               = 262;
  rsFilesSizeChanged                = 263;
  rsFileTypes                       = 264;
  rsFilter                          = 265;
  rsFolder                          = 266;
  rsFolderDetail                    = 267;
  rsFolderDoesNotExist              = 268;
  rsFolderHistory                   = 269;
  rsFolderHistoryComputer           = 270;
  rsFolderHistoryFolder             = 271;
  rsFolderHistoryFor                = 272;
  rsFolderHistoryInfo               = 273;
  rsFolderList                      = 274;
  rsFolderProperties                = 275;
  rsFolders                         = 276;
  rsFolderScans                     = 277;
  rsFoldersRootQuantity             = 278;
  rsFoldersRootSize                 = 279;
  rsFoldersToScan                   = 280;
  rsFolderStructure                 = 281;
  rsFound                           = 282;
  rsFoundIn                         = 283;
  rsFrom                            = 284;
  rsFTPHost                         = 285;
  rsFTPPassword                     = 286;
  rsFTPUsername                     = 287;
  rsFullFileList                    = 288;
  rsFullFilePath                    = 289;
  rsGeneral                         = 290;
  rsGenerateFilenames               = 291;
  rsGenerateMD5                     = 292;
  rsGenerateMD5Checksum             = 293;
  rsGFX                             = 294;
  rsGradientColours                 = 295;
  rsGradientFrom                    = 296;
  rsGradientTo                      = 297;
  rsGraphBackground                 = 298;
  rsGraphics                        = 299;
  rsGreen                           = 300;
  rsGrey                            = 301;
  rsHardDisk                        = 302;
  rsHasBeenSelected                 = 303;
  rsHashFiles                       = 304;
  rsHelp                            = 305;
  rsHexEdit                         = 306;
  rsHidden                          = 307;
  rsHide                            = 308;
  rsHint1                           = 309;
  rsHint2                           = 310;
  rsHint3                           = 311;
  rsHint4                           = 312;
  rsHint5                           = 313;
  rsHint6                           = 314;
  rsHint7                           = 315;
  rsHint8                           = 316;
  rsHintM1                          = 317;
  rsHintM2                          = 318;
  rsHintM3                          = 319;
  rsHintM4                          = 320;
  rsHintM5                          = 321;
  rsHistory                         = 322;
  rsHour                            = 323;
  rsHTMLCReportSavedAs              = 324;
  rsHTMLFiles                       = 325;
  rsHTMLReport                      = 326;
  rsHTMLReport1                     = 327;
  rsHTMLReport10                    = 328;
  rsHTMLReport11                    = 329;
  rsHTMLReport12                    = 330;
  rsHTMLReport13                    = 331;
  rsHTMLReport14                    = 332;
  rsHTMLReport15                    = 333;
  rsHTMLReport16                    = 334;
  rsHTMLReport17                    = 335;
  rsHTMLReport2                     = 336;
  rsHTMLReport3                     = 337;
  rsHTMLReport4                     = 338;
  rsHTMLReport5                     = 339;
  rsHTMLReport6                     = 340;
  rsHTMLReport7                     = 341;
  rsHTMLReport8                     = 342;
  rsHTMLReport9                     = 343;
  rsHTMLReportOptions               = 344;
  rsHTMLReportSavedAs               = 345;
  rsIgnore                          = 346;
  rsIgnoreFirstRecord               = 347;
  rsImport                          = 348;
  rsImportList                      = 349;
  rsImportScanDetail                = 350;
  rsIncludeColumnTitles             = 351;
  rsIncludeFullPath                 = 352;
  rsIncludeImages                   = 353;
  rsInformationPages                = 354;
  rsInitialFolder                   = 355;
  rsInterval                        = 356;
  rsJIT                             = 357;
  rsKilobytes                       = 358;
  rsLabel                           = 359;
  rsLabelColour                     = 360;
  rsLabelPercent                    = 361;
  rsLabelPercentTotal               = 362;
  rsLabelValue                      = 363;
  rsLanguage                        = 364;
  rsLargest                         = 365;
  rsLargestFiles                    = 366;
  rsLastMonth                       = 367;
  rsLastWeek                        = 368;
  rsLayoutFiles                     = 369;
  rsLeftSideProgressBar             = 370;
  rsLegend                          = 371;
  rsLinkHover                       = 372;
  rsLinkNormal                      = 373;
  rsLoad                            = 374;
  rsLoadingFileHistoryData          = 375;
  rsLogarthmic                      = 376;
  rsMagnitude                       = 377;
  rsMainChart                       = 378;
  rsMaySlowDownReport               = 379;
  rsMegabytes                       = 380;
  rsModified                        = 381;
  rsModifiedDate                    = 382;
  rsModifiedDateDDMMYYYY            = 383;
  rsModifiedDateMMDDYYYY            = 384;
  rsModifiedToday                   = 385;
  rsMonth                           = 386;
  rsMonthYear                       = 387;
  rsMoreDetail                      = 388;
  rsMostConvenient                  = 389;
  rsMOV                             = 390;
  rsMove                            = 391;
  rsMoveTo                          = 392;
  rsMovie                           = 393;
  rsNewest                          = 394;
  rsNewestFiles                     = 395;
  rsNoFHFSelected                   = 396;
  rsNoFileData                      = 397;
  rsNoFilesFound                    = 398;
  rsNoFilesToCompress               = 399;
  rsNoMatchesFound                  = 400;
  rsNoneFound                       = 401;
  rsNormal                          = 402;
  rsNormalDistribution              = 403;
  rsNotContentIndexed               = 404;
  rsNoTempFilesFound                = 405;
  rsNotEqualTo                      = 406;
  rsNOT_SPECIFIED                   = 407;
  rsNull                            = 408;
  rsNullFiles                       = 409;
  rsNumberOfFiles                   = 410;
  rsNumberOfFolders                 = 411;
  rsOf                              = 412;
  rsOFF                             = 413;
  rsOffice                          = 414;
  rsOffline                         = 415;
  rsOlderThan                       = 416;
  rsOldest                          = 417;
  rsOldestFiles                     = 418;
  rsOn                              = 419;
  rsOpen                            = 420;
  rsOpenInApplication               = 421;
  rsOpenInApplicationsDefault       = 422;
  rsOpenInFileHistory               = 423;
  rsOpenLastReport                  = 424;
  rsOpenWithCustomViewer            = 425;
  rsOptimisations                   = 426;
  rsOptions                         = 427;
  rsOrange                          = 428;
  rsOrganiseReports                 = 429;
  rsORIReport1                      = 430;
  rsORIReport2                      = 431;
  rsORIReport3                      = 432;
  rsORIReport4                      = 433;
  rsORIReport5                      = 434;
  rsORIReport6                      = 435;
  rsORIReport7                      = 436;
  rsORIReport8                      = 437;
  rsORIReport9                      = 438;
  rsOther                           = 439;
  rsOutputAsCSV                     = 440;
  rsOutputAsHTML                    = 441;
  rsOutputAsXML                     = 442;
  rsOutputOptions                   = 443;
  rsOwner                           = 444;
  rsPageBackground                  = 445;
  rsPath                            = 446;
  rsPaths                           = 447;
  rsPatternToExclude                = 448;
  rsPercent                         = 449;
  rsPercentTotal                    = 450;
  rsPleaseWait                      = 451;
  rsPleaseWaitFolderHistory         = 452;
  rsPNGFiles                        = 453;
  rsPostScan                        = 454;
  rsPreview                         = 455;
  rsPRG                             = 456;
  rsProcessedIn                     = 457;
  rsProgramming                     = 458;
  rsPrograms                        = 459;
  rsPurple                          = 460;
  rsQty                             = 461;
  rsQtyOfFiles                      = 462;
  rsQuantity                        = 463;
  rsQuantityFilesUser               = 464;
  rsQuick                           = 465;
  rsQuickFoldersAlreadyExists       = 466;
  rsQuickReportPreferences          = 467;
  rsQuickReports                    = 468;
  rsRAMDisk                         = 469;
  rsRange                           = 470;
  rsReadOnly                        = 471;
  rsRed                             = 472;
  rsReference                       = 473;
  rsRefresh                         = 474;
  rsRelativeToPrevious              = 475;
  rsRelativeToToday                 = 476;
  rsRemoteDrive                     = 477;
  rsRemovable                       = 478;
  rsRenameCustomCategory            = 479;
  rsReparseFile                     = 480;
  rsReport                          = 481;
  rsReportBrowser                   = 482;
  rsReportBugFeature                = 483;
  rsReportColours                   = 484;
  rsReportDetail1                   = 485;
  rsReportDetail2                   = 486;
  rsReportFor                       = 487;
  rsReportItems                     = 488;
  rsReportLayout                    = 489;
  rsReportOptions                   = 490;
  rsReportsFolder                   = 491;
  rsReportsURL                      = 492;
  rsRestoreDefaultExtensions        = 493;
  rsRestoreDefaults                 = 494;
  rsRightSideProgressBar            = 495;
  rsSave                            = 496;
  rsSaveAll                         = 497;
  rsSaveAs                          = 498;
  rsSaveChart                       = 499;
  rsSaveData                        = 500;
  rsSaveDoExist                     = 501;
  rsSaveDontExist                   = 502;
  rsSaveReports                     = 503;
  rsSavetoAll                       = 504;
  rsSavingReports                   = 505;
  rsScan                            = 506;
  rsScanADriveFolder                = 507;
  rsScanData                        = 508;
  rsScanDriveFolder                 = 509;
  rsScanHistory                     = 510;
  rsScanningFolder                  = 511;
  rsScanningProgress                = 512;
  rsScanTheDriveFolder              = 513;
  rsSearch                          = 514;
  rsSearchResultLimit               = 515;
  rsSearchSyntax                    = 516;
  rsSelect                          = 517;
  rsSelectCategories                = 518;
  rsSelectDateTime                  = 519;
  rsSelectedFolder                  = 520;
  rsSelectScanDateTime              = 521;
  rsSeparator                       = 522;
  rsSetBargraphToASingleColour      = 523;
  rsSettings                        = 524;
  rsSFX                             = 525;
  rsShow                            = 526;
  rsShowAll                         = 527;
  rsShowCategorised                 = 528;
  rsShowCustom                      = 529;
  rsShowFiles                       = 530;
  rsShowFileSizesAs                 = 531;
  rsShowFullPath                    = 532;
  rsShowing                         = 533;
  rsShowLabels                      = 534;
  rsShowNames                       = 535;
  rsShowNonZero                     = 536;
  rsShowSizesIn                     = 537;
  rsShowUncategorised               = 538;
  rsSize                            = 539;
  rsSizeBefore                      = 540;
  rsSizeChanges                     = 541;
  rsSizeFilesUser                   = 542;
  rsSizeNow                         = 543;
  rsSizeOD                          = 544;
  rsSizeOfFiles                     = 545;
  rsSizeOfFilesBytes                = 546;
  rsSizeOnDisk                      = 547;
  rsSmallest                        = 548;
  rsSmallestFiles                   = 549;
  rsSparseFile                      = 550;
  rsSpecial                         = 551;
  rsStarted                         = 552;
  rsStatus                          = 553;
  rsSuggestedFileType               = 554;
  rsSummary                         = 555;
  rsSummReport1                     = 556;
  rsSummReport10                    = 557;
  rsSummReport11                    = 558;
  rsSummReport12                    = 559;
  rsSummReport13                    = 560;
  rsSummReport14                    = 561;
  rsSummReport15                    = 562;
  rsSummReport2                     = 563;
  rsSummReport3                     = 564;
  rsSummReport4                     = 565;
  rsSummReport5                     = 566;
  rsSummReport6                     = 567;
  rsSummReport7                     = 568;
  rsSummReport8                     = 569;
  rsSummReport9                     = 570;
  rsSupportedFileTypes              = 571;
  rsSYS                             = 572;
  rsSystem                          = 573;
  rsTable                           = 574;
  rsTableBackground                 = 575;
  rsTableDisplay                    = 576;
  rsTableHeader                     = 577;
  rsTableName                       = 578;
  rsTableRowHeight                  = 579;
  rsTables                          = 580;
  rsTableTextColour                 = 581;
  rsTableTextColour2                = 582;
  rsTemp                            = 583;
  rsTempFilePTNF                    = 584;
  rsTempFilePTSF                    = 585;
  rsTempFiles                       = 586;
  rsTempList                        = 587;
  rsTemporary                       = 588;
  rsText                            = 589;
  rsTextColour                      = 590;
  rsTextFiles                       = 591;
  rsTextReport                      = 592;
  rsTextReport1                     = 593;
  rsTextReport10                    = 594;
  rsTextReport11                    = 595;
  rsTextReport12                    = 596;
  rsTextReport13                    = 597;
  rsTextReport14                    = 598;
  rsTextReport15                    = 599;
  rsTextReport16                    = 600;
  rsTextReport17                    = 601;
  rsTextReport2                     = 602;
  rsTextReport3                     = 603;
  rsTextReport4                     = 604;
  rsTextReport5                     = 605;
  rsTextReport6                     = 606;
  rsTextReport7                     = 607;
  rsTextReport8                     = 608;
  rsTextReport9                     = 609;
  rsTextReportFilename              = 610;
  rsTextReportSavedAs               = 611;
  rsTheRootNotExist                 = 612;
  rsThisWeek                        = 613;
  rsTime                            = 614;
  rsTMP                             = 615;
  rsTo                              = 616;
  rsToggleGradient                  = 617;
  rsTools                           = 618;
  rsTop101                          = 619;
  rsTotalSize                       = 620;
  rsTotalSizeofFilesAnalysed        = 621;
  rsTree                            = 622;
  rsTreeChart                       = 623;
  rsTreeFileName                    = 624;
  rsTreeFiles                       = 625;
  rsTreeReport                      = 626;
  rsTreeReportSavedAs               = 627;
  rsTrial                           = 628;
  rsType                            = 629;
  rsTypesOfTempFiles                = 630;
  rsUncat                           = 631;
  rsUncategorised                   = 632;
  rsUnknown                         = 633;
  rsUnknownFileType                 = 634;
  rsUpdateProgress1                 = 635;
  rsUpdateProgress2                 = 636;
  rsUpdateProgress3                 = 637;
  rsUpdateProgress4                 = 638;
  rsUpdateProgress5                 = 639;
  rsUpdateProgress6                 = 640;
  rsUpdatingFolderHistory           = 641;
  rsUpload                          = 642;
  rsUploading                       = 643;
  rsUploadingHTMLGraphs             = 644;
  rsUploadingIndexPages             = 645;
  rsUsageByUser                     = 646;
  rsUsed                            = 647;
  rsUsedSpace                       = 648;
  rsUserDefined                     = 649;
  rsUserDetails                     = 650;
  rsUserManual                      = 651;
  rsUsers                           = 652;
  rsValue                           = 653;
  rsView                            = 654;
  rsViewOpenFile                    = 655;
  rsWebReports                      = 656;
  rsWeek                            = 657;
  rsWeekYear                        = 658;
  rsWelcome                         = 659;
  rsWhenFewer                       = 660;
  rsWhichData                       = 661;
  rsWhite                           = 662;
  rsWindowsFiles                    = 663;
  rsWithinTheLast                   = 664;
  rsWizard                          = 665;
  rsXBytes                          = 666;
  rsXFileList                       = 667;
  rsXGigabytes                       = 668;
  rsXinorbisDataFolder               = 669;
  rsXinorbisDataFolderChanges        = 670;
  rsXinorbisFileList                 = 671;
  rsXinorbisHome                     = 672;
  rsXinorbisReportFilename           = 673;
  rsXKilobytes                       = 674;
  rsXMegabytes                       = 675;
  rsXMLCReportSavedAs                = 676;
  rsXMLFiles                         = 677;
  rsXMLReport                        = 678;
  rsXMLReportSavedAs                 = 679;
  rsXValue                           = 680;
  rsYear                             = 681;
  rsYellow                           = 682;
  rsYesterday                        = 683;
  rsZIP                              = 684;
  rsReportNotFound                   = 685;
  rsCheckingForUpdates               = 686;
  rsCopyToClipboard                  = 687;
  rsWarning                          = 688;
  rsErrorSavingReport                = 689;
  rsErrorSaving                      = 690;
  rsProVersionOnly                   = 691;
  rsCustomiseQuickFolderMenu         = 692;
  rsAddXinorbisToExplorerContextMenu = 693;
  rsTutorial                         = 694;
  rsPurchaseXinorbis                 = 695;
  rsEnabled                          = 696;
  rsDisabled                         = 697;
  rsPleaseSelectADate                = 698;
  rsSearching                        = 699;
  rsANewVersionIsAvailable           = 700;
  rsNoNewVersionIsAvailable          = 701;
  rsError                            = 702;
  rsSocialMedia                      = 703;
  rsThanks                           = 704;
  rsPortable                         = 705;
  rsStandard                         = 706;
  rsTitleColour                      = 707;
  rsMultiColoured                    = 708;
  rsGradient                         = 709;
  rsDefault                          = 710;
  rsSearchResults                    = 711;
  rsHideNames                        = 712;
  rsUnableToConnectTo                = 713;
  rsImportCSVData                    = 714;
  rsHours                            = 715;
  rsMinute                           = 716;
  rsMinutes                          = 717;
  rsSecond                           = 718;
  rsSeconds                          = 719;
  rsName                             = 720;
  rsEmailAddress                     = 721;
  rsActivationKey                    = 722;
  rsSorryThisFeatureNotAvailable     = 723;
  rsErrorCompressingFiles            = 724;
  rsInstalledVersion                 = 725;
  rsLatestAvailableOnline            = 726;
  rsDownload                         = 727;
  rsUpdateNow                        = 728;
  rsVersion                          = 729;
  rsWebsite                          = 730;
  rsXinorbisIsBusy                   = 731;
  rsErrorOpeningXinorbisSystemFile   = 732;
  rsAvailableFolderHistoryScans      = 733;
  rsScans                            = 734;
  rsExcludeEmpty                     = 735;
  rsSelected                         = 736;
  rsPleaseWaitWebReports             = 737;
  rsInvalidNameEmailCodeCombination  = 738;
  rsExport                           = 739;
  rsPleaseCheckXinorbisInstalled     = 740;
  rsDatabaseIsEmpty                  = 741;
  rsBadCSVFile                       = 742;
  rsDoesNotExist                     = 743;
  rsMultipleFolders                  = 744;
  rsDatabaseConnections              = 745;
  rsErrorConnectingODBC              = 746;
  rsInvalidInput                     = 747;
  rsMissingFile                      = 748;
  rsSearchFinished                   = 749;
  rsThisMonth                        = 750;
  rsFolderMap                        = 751;
  rsResetChartGradientColours        = 752;
  rsUsersWarning                     = 753;
  rsTimeLine                         = 754;
  rsDisplayColour                    = 755;
  rsLeft                             = 756;
  rsRight                            = 757;
  rsShowLog                          = 758;
  rsSaveLog                          = 759;
  rsRestoreToDefaults                = 760;
  rsSelectAll                        = 761;
  rsSelectNone                       = 762;
  rsCopyResultsToClipboard           = 763;
  rsDataSource                       = 764;
  rsNew                              = 765;
  rsCannotFindFileParam              = 766;
  rsFTPUploadTestFailed              = 767;
  rsFolderExploder                   = 768;
  rsWebReportsSettingsMissing        = 769;
  rsDontProcessTempFiles             = 770;
  rsTempFilesWarning                 = 771;
  rsScanButton                       = 772;
  rsAllOtherTables                   = 773;
  rsLogs                             = 774;
  rsLength                           = 775;
  rsFileNameLength                   = 776;
  rsTextReport18                     = 777;
  rsTextReport19                     = 778;
  rsNoDataToExport                   = 779;
  rsThisReportCanBeImported          = 780;
  rsReportContainsVirtualFiles       = 781;
  rsScanStoppedBeforeComplete        = 782;
  rsIgnoreVirtualFolders             = 783;

  rsDateDD                           = 0;
  rsDateMM                           = 1;
  rsDateYYYY                         = 2;

  rsUnitB                            = 0;
  rsUnitKB                           = 1;
  rsUnitMB                           = 2;
  rsUnitGB                           = 3;
  rsUnitTB                           = 4;


{$ENDREGION}


type
  TLanguageHandler = class
    class procedure InitLanguage(aLanguageID : integer);
    class function  LoadLanguage(aFileName : string): boolean;
    class function  LoadUnits(aFileName : string): boolean;
    class function  GetLanguageSymbol(languageindex : integer): string;

    class function  FillParameter(aID : integer; aParam : string): string;

    class procedure BuildXDates;

    class procedure Free;
  end;


var
  XText : TStringList;
  XDate : TStringList;
  XUnit : TStringList;

  magnilabels     : array[0..__MagnitudesCount] of string = ('<=1$K', '1$K < x <=1$M', '1$M < x <=10$M', '10$M < x <=50$M', '50$M < x <=100$M', '100$M < x <=150$M',
                                                             '150$M < x <=200$M', '200$M < x <=250$M', '250$M < x <=500$M', '500$M < x <=1$G', '1$G < x <=2$G',
                                                             '2$G < x <=5$G', '>5$G');

  magnilabels2    : array[0..__MagnitudesCount] of string = ('<=1$K', '1$K<=1$M', '1$M<=10$M', '10$M<=50$M', '50$M<=100$M', '100$M<=150$M',
                                                             '150$M<=200$M', '200$M<=250$M', '250$M<=500$M', '500$M<=1$G', '1$G<=2$G',
                                                             '2$G<=5$G', '>5$G');

  magnilabels3    : array[0..__MagnitudesCount] of string = ('<= 1$K', '1$K - 1$M', '1$M - 10$M', '10$M - 50$M', '50$M - 100$M',
                                                         '100$M - 150$M', '150$M - 200$M', '200$M - 250$M', '250$M - 500$M', '500$M - 1$G',
                                                         '1$G - 2$G', '2$G - 5$G', '5$G+');


implementation


uses
  X.SystemGlobal;


class procedure TLanguageHandler.InitLanguage(aLanguageID : integer);
var
  lFileName : string;
  lDidLoad : boolean;
  t : integer;

begin
  lFileName := GSystemGlobal.ExePath + 'data\languages\' + GetLanguageSymbol(aLanguageID) + '\language.txt';

  if not FileExists(lFileName) then begin
    aLanguageID := languageUK; // default

    lFileName := GSystemGlobal.ExePath + 'data\languages\' + GetLanguageSymbol(aLanguageID) + '\language.txt';

    TMSLogger.Error('Couldn''t find "\' + GetLanguageSymbol(aLanguageID) + '\language.txt". Defaulting to UK, let''s hope it exists :|');
  end;

  lDidLoad := LoadLanguage(lFileName);

  if not(lDidLoad) then begin
    MessageDlg('Unable to load language details.' + #13#13 +
               lFileName + #13#13 +
               'Please check Xinorbis is installed correctly!', mtError, [mbOK], 0);

    TMSLogger.Error('Language load fail "' + lFileName + '".');

    Halt(0);
  end;

  // ===========================================================================

  lFileName := GSystemGlobal.ExePath + 'data\languages\' + GetLanguageSymbol(aLanguageID) + '\units.txt';

  if not FileExists(lFileName) then begin
    aLanguageID := languageUK; // default

    lFileName := GSystemGlobal.ExePath + 'data\languages\' + GetLanguageSymbol(aLanguageID) + '\units.txt';

    TMSLogger.Error('Couldn''t find "\' + GetLanguageSymbol(aLanguageID) + '\units.txt". Defaulting to UK, let''s hope it exists :|');
  end;

  lDidLoad := LoadUnits(lFileName);

  if not(lDidLoad) then begin
    MessageDlg('Unable to load language details.' + #13#13 +
               lFileName + #13#13 +
               'Please check Xinorbis is installed correctly!', mtError, [mbOK], 0);

    TMSLogger.Error('Units load fail "' + lFileName + '".');

    Halt(0);
  end
  else begin
    for t:= 0 to __MagnitudesCount do begin
      magnilabels[t]  := StringReplace(magnilabels[t],  '$K', XUnit[rsUnitKB], [rfReplaceAll]);
      magnilabels[t]  := StringReplace(magnilabels[t],  '$M', XUnit[rsUnitMB], [rfReplaceAll]);
      magnilabels[t]  := StringReplace(magnilabels[t],  '$G', XUnit[rsUnitGB], [rfReplaceAll]);

      magnilabels2[t] := StringReplace(magnilabels2[t], '$K', XUnit[rsUnitKB], [rfReplaceAll]);
      magnilabels2[t] := StringReplace(magnilabels2[t], '$M', XUnit[rsUnitMB], [rfReplaceAll]);
      magnilabels2[t] := StringReplace(magnilabels2[t], '$G', XUnit[rsUnitGB], [rfReplaceAll]);

      magnilabels3[t] := StringReplace(magnilabels3[t], '$K', XUnit[rsUnitKB], [rfReplaceAll]);
      magnilabels3[t] := StringReplace(magnilabels3[t], '$M', XUnit[rsUnitMB], [rfReplaceAll]);
      magnilabels3[t] := StringReplace(magnilabels3[t], '$G', XUnit[rsUnitGB], [rfReplaceAll]);
    end;
  end;
end;


class function TLanguageHandler.LoadLanguage(aFileName : string): boolean;
var
  tf : TextFile;
  s : string;

begin
  Result := False;

  if FileExists(aFileName) then begin
    XText := TStringList.Create;

    AssignFile(tf, aFileName, CP_UTF8);
    Reset(tf);

    while not(eof(tf)) do begin
      Readln(tf, s);

      XText.Add(s);
    end;

    CloseFile(tf);

    // ======================================================================

    BuildXDates;

    // ======================================================================

    Result := True;
  end;
end;


class function TLanguageHandler.LoadUnits(aFileName : string): boolean;
var
  tf : TextFile;
  s : string;

begin
  Result := False;

  if FileExists(aFileName) then begin
    XUnit := TStringList.Create;

    AssignFile(tf, aFileName, CP_UTF8);
    Reset(tf);

    while not(eof(tf)) do begin
      Readln(tf, s);

      XUnit.Add(s);
    end;

    CloseFile(tf);

    // ======================================================================

    Result := True;
  end;
end;


class function TLanguageHandler.GetLanguageSymbol(languageindex : integer): string;
 begin
  Assert((languageindex >= LanguageUK) and (languageindex <= LanguageCAT), 'GetLanguageSymbol :: input error (' + IntToStr(languageindex) + ')');

  case languageindex of
     LanguageUK  : Result := 'uk';
     LanguageNL  : Result := 'nl';
     LanguageFR  : Result := 'fr';
     LanguageDE  : Result := 'de';
     LanguageIT  : Result := 'it';
     LanguagePT  : Result := 'pt';
     LanguageES  : Result := 'es';
     LanguageSW  : Result := 'sw';
     LanguageCZ  : Result := 'cz';
     LanguageHU  : Result := 'hu';
     LanguageUS  : Result := 'us';
     LanguageRU  : Result := 'ru';
     LanguageCAT : Result := 'cat';
  else
    result := 'uk';
  end;
end;


class procedure TLanguageHandler.BuildXDates;
begin
  XDate := TStringList.Create;

  // rsDateDD
  XDate.Add(LowerCase(XText[rsDay][1] + XText[rsDay][1]));

  // rsDateMM
  XDate.Add(LowerCase(XText[rsMonth][1] + XText[rsMonth][1]));

  // rsDateYYYY
  XDate.Add(LowerCase(XText[rsYear][1] + XText[rsYear][1] + XText[rsYear][1] + XText[rsYear][1])) ;
end;


class function TLanguageHandler.FillParameter(aID : integer; aParam : string): string;
begin
  Result := StringReplace(XText[aID], '%$', aParam, []);
end;


class procedure TLanguageHandler.Free;
begin
  XText.Free;
  XDate.Free;
  XUnit.Free;
end;


end.
