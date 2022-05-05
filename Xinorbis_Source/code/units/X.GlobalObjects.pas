{
  (c) Paul Alan Freshney 2002-2020
  (c) Aardvark Digital 2002
  (c) Maximum Octopus Limted 2020

  www.freshney.org :: paul@freshney.org :: maximumoctopus.com :: xinorbis.com

  Last Modified: January 11th 2020
}


unit X.GlobalObjects;

interface

uses
  System.Generics.Collections,

  X.Thread.CompareFolderLeft, X.Thread.CompareFolderRight,
  X.Thread.CompareLeft, X.Thread.CompareRight, X.Thread.WebReports, X.ScanAnalysis,

  X.ScanDetails,

  X.GuiUtil;

var
  GCompareLeftThread               : TCompareLeftThread;
  GCompareRightThread              : TCompareRightThread;
  GCompareFolderLeftThread         : TCompareFolderLeftThread;
  GCompareFolderRightThread        : TCompareFolderRightThread;

  GWebReportsThread                : TWebReportsThread;

  GXinorbisScan                    : TXinorbisScan;

  GXGuiUtil                        : TGuiUtil;

  GScanDetails                     : TObjectList<TScanDetails>;


implementation


end.
