object frmMain: TfrmMain
  Left = 271
  Top = 119
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  ClientHeight = 819
  ClientWidth = 1440
  Color = clBtnFace
  Enabled = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = mMainMenu
  OldCreateOrder = False
  Position = poDefault
  Scaled = False
  ShowHint = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnConstrainedResize = FormConstrainedResize
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label8: TLabel
    Left = 48
    Top = 355
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label9: TLabel
    Left = 48
    Top = 419
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object pTutorial: TPanel
    Left = 0
    Top = 728
    Width = 1440
    Height = 72
    Align = alBottom
    Color = clWhite
    Padding.Left = 2
    Padding.Top = 2
    Padding.Right = 2
    Padding.Bottom = 2
    ParentBackground = False
    TabOrder = 0
    Visible = False
    object lTutorial: THTMLabel
      Left = 3
      Top = 3
      Width = 1434
      Height = 66
      Align = alClient
      Color = clWhite
      HTMLText.Strings = (
        
          'Welcome to <b>Xinorbis</b>. This box will give you hints and tip' +
          's as you use Xinorbis. <b>Double click</b> this text to close th' +
          'e tutorial Window. You can open it again by selecting <b>Tutoria' +
          'l</b> from the <b>Help</b> menu.<br><br>If this is your first ti' +
          'me using Xinorbis then click the button above labelled <b>Scan a' +
          ' drive or folder</b>.')
      ParentColor = False
      Transparent = True
      OnDblClick = lTutorialDblClick
      Version = '1.9.2.8'
      ExplicitLeft = 6
      ExplicitTop = 51
      ExplicitWidth = 1549
    end
  end
  object anbNavigationPanel: TAdvNavBar
    Left = 0
    Top = 82
    Width = 214
    Height = 646
    Align = alLeft
    Color = clWhite
    ActiveColor = 16645114
    ActiveColorTo = 16643051
    ActiveTabIndex = 3
    BorderColor = 13542013
    CaptionColor = 16575452
    CaptionColorTo = 16571329
    CaptionFont.Charset = DEFAULT_CHARSET
    CaptionFont.Color = clBlack
    CaptionFont.Height = -15
    CaptionFont.Name = 'Tahoma'
    CaptionFont.Style = [fsBold]
    CollapsedCaption = 'Collapsed'
    DefaultGradientDirection = gdVertical
    DefaultTabColorTo = clWhite
    DownTabColor = 16575452
    DownTabColorTo = 16571329
    DownTabMirrorColor = clNone
    DownTabMirrorColorTo = clNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    HoverTabColor = 16645114
    HoverTabColorTo = 16643051
    HoverTabMirrorColor = clNone
    HoverTabMirrorColorTo = clNone
    PopupIndicator = False
    SectionColor = 16645114
    SectionColorTo = 16643051
    SectionFont.Charset = DEFAULT_CHARSET
    SectionFont.Color = clWindowText
    SectionFont.Height = -11
    SectionFont.Name = 'Tahoma'
    SectionFont.Style = []
    ShowHint = True
    ShowSplitter = False
    SplitterPosition = 4
    SplitterColor = 16575452
    SplitterColorTo = 16571329
    Style = esWindows7
    Version = '2.1.0.1'
    OnChange = anbNavigationPanelChange
    object anbPanelHelp: TAdvNavBarPanel
      Left = 1
      Top = 27
      Width = 212
      Height = 438
      Caption = '.'
      CaptionStyle = []
      Color = clWhite
      PanelIndex = 0
      Sections = <>
      object Image21: TImage
        Left = 12
        Top = 34
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image23: TImage
        Left = 12
        Top = 50
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lHelpContext: TLabel
        Left = 22
        Top = 48
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = miContextHelpClick
      end
      object Image22: TImage
        Left = 12
        Top = 66
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lHelpManual: TLabel
        Left = 22
        Top = 64
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = miUserManualClick
      end
      object Image30: TImage
        Left = 12
        Top = 90
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lHelpReference: TLabel
        Left = 22
        Top = 88
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = miReferenceClick
      end
      object Image31: TImage
        Left = 12
        Top = 106
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lHelpSearchSyntax: TLabel
        Left = 22
        Top = 104
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
      end
      object lHelpCatColours: TLabel
        Left = 22
        Top = 120
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = miShowCategoryColoursClick
      end
      object Image27: TImage
        Left = 12
        Top = 122
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image4: TImage
        Left = 12
        Top = 146
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lHelpSendFeedback: TLabel
        Left = 22
        Top = 144
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = lHelpSendFeedbackClick
      end
      object Image43: TImage
        Left = 12
        Top = 163
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lShowLog: TLabel
        Left = 22
        Top = 161
        Width = 43
        Height = 13
        Cursor = crHandPoint
        Caption = 'Show log'
        OnClick = lShowLogClick
      end
      object lHelpMain: TLabel
        Left = 22
        Top = 32
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
      end
    end
    object anbPanelQuickReports: TAdvNavBarPanel
      Left = 1
      Top = 27
      Width = 212
      Height = 438
      Caption = '.'
      CaptionStyle = []
      Color = clWhite
      PanelIndex = 1
      Sections = <>
      object Image18: TImage
        Left = 12
        Top = 51
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lReportCSV: TLabel
        Left = 22
        Top = 49
        Width = 19
        Height = 13
        Cursor = crHandPoint
        Caption = 'CSV'
        Enabled = False
        Transparent = True
        OnMouseDown = lReportCSVMouseDown
      end
      object lReportHTML: TLabel
        Left = 22
        Top = 65
        Width = 26
        Height = 13
        Cursor = crHandPoint
        Caption = 'HTML'
        Enabled = False
        PopupMenu = puCustomReport
        Transparent = True
        OnMouseDown = lReportHTMLMouseDown
      end
      object Image19: TImage
        Left = 12
        Top = 67
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image20: TImage
        Left = 12
        Top = 83
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lReportText: TLabel
        Tag = 3
        Left = 22
        Top = 80
        Width = 22
        Height = 13
        Cursor = crHandPoint
        Caption = 'Text'
        Enabled = False
        PopupMenu = puCustomReport
        Transparent = True
        OnMouseDown = lReportTextMouseDown
      end
      object lReportTree: TLabel
        Tag = 5
        Left = 22
        Top = 97
        Width = 22
        Height = 13
        Cursor = crHandPoint
        Caption = 'Tree'
        Enabled = False
        PopupMenu = puCustomReport
        Transparent = True
        OnMouseDown = lReportTreeMouseDown
      end
      object lReportXinorbis: TLabel
        Left = 22
        Top = 113
        Width = 37
        Height = 13
        Cursor = crHandPoint
        Caption = 'Xinorbis'
        Enabled = False
        Transparent = True
        OnMouseDown = lReportXinorbisMouseDown
      end
      object lReportXML: TLabel
        Left = 22
        Top = 129
        Width = 19
        Height = 13
        Cursor = crHandPoint
        Caption = 'XML'
        Enabled = False
        Transparent = True
        OnMouseDown = lReportXMLMouseDown
      end
      object Image32: TImage
        Left = 12
        Top = 155
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lReportPreferences: TLabel
        Left = 22
        Top = 153
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Transparent = True
        OnClick = lReportPreferencesClick
      end
      object Image29: TImage
        Left = 12
        Top = 131
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image26: TImage
        Left = 12
        Top = 99
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image28: TImage
        Left = 12
        Top = 115
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image1: TImage
        Left = 12
        Top = 34
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lReportSummary: TLabel
        Left = 22
        Top = 32
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        Transparent = True
        OnMouseDown = lReportSummaryMouseDown
      end
    end
    object anbPanelView: TAdvNavBarPanel
      Left = 1
      Top = 27
      Width = 212
      Height = 438
      Caption = '.'
      CaptionStyle = []
      Color = clWhite
      PanelIndex = 2
      Sections = <>
      object Image12: TImage
        Left = 12
        Top = 34
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lTaskID1: TLabel
        Left = 22
        Top = 32
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = lTaskID1Click
      end
      object Image13: TImage
        Left = 12
        Top = 50
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lTaskID2: TLabel
        Left = 22
        Top = 48
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = lTaskID2Click
      end
      object Image14: TImage
        Left = 12
        Top = 66
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lTaskID3: TLabel
        Left = 22
        Top = 64
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = lTaskID3Click
      end
      object lTaskID4: TLabel
        Left = 22
        Top = 80
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = lTaskID4Click
      end
      object Image24: TImage
        Left = 12
        Top = 82
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image15: TImage
        Left = 12
        Top = 99
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lAdvID1: TLabel
        Left = 22
        Top = 97
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = miDFileSizeClick
      end
      object Image16: TImage
        Left = 12
        Top = 115
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lAdvID2: TLabel
        Left = 22
        Top = 113
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = miDDuplicatesNameClick
      end
      object Image17: TImage
        Left = 12
        Top = 131
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image8: TImage
        Left = 12
        Top = 163
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image25: TImage
        Left = 12
        Top = 147
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lAdvID4: TLabel
        Left = 22
        Top = 145
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = miMoreFolderDetailClick
      end
      object lAdvID5: TLabel
        Left = 22
        Top = 161
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = lAdvID5Click
      end
      object lAdvID3: TLabel
        Left = 22
        Top = 129
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        Enabled = False
        OnClick = miDDuplicatesSizeClick
      end
    end
    object anbPanelWelcome: TAdvNavBarPanel
      Left = 1
      Top = 27
      Width = 212
      Height = 438
      Caption = '.'
      CaptionStyle = []
      Color = clWhite
      PanelIndex = 3
      Sections = <>
      object Image9: TImage
        Left = 12
        Top = 34
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object Image10: TImage
        Left = 12
        Top = 50
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lWelcomeImportScan: TLabel
        Left = 22
        Top = 48
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = sbLoadFromReportClick
      end
      object Image11: TImage
        Left = 12
        Top = 66
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lWelcomeFolderHistory: TLabel
        Left = 22
        Top = 64
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = sbMainFolderHistoryClick
      end
      object Image34: TImage
        Left = 12
        Top = 82
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lWelcomeReports: TLabel
        Left = 22
        Top = 80
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = lWelcomeReportsClick
      end
      object Image37: TImage
        Left = 12
        Top = 98
        Width = 6
        Height = 10
        AutoSize = True
        Picture.Data = {
          07544269746D6170FE000000424DFE0000000000000036000000280000000600
          00000A0000000100180000000000C8000000130B0000130B0000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00
          FF404040404040404040404040FF00FF0000FF00FF4040404040404040404040
          40FF00FF0000FF00FF404040404040404040404040FF00FF0000FF00FF404040
          404040404040404040FF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FF0000}
        Transparent = True
      end
      object lWelcomeWebReports: TLabel
        Left = 22
        Top = 96
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = lWelcomeWebReportsClick
      end
      object lWelcomeScan: TLabel
        Left = 22
        Top = 32
        Width = 4
        Height = 13
        Cursor = crHandPoint
        Caption = '.'
        OnClick = sbNewScanClick
      end
    end
  end
  object W7ToolBar1: TW7ToolBar
    Left = 0
    Top = 51
    Width = 1440
    Height = 31
    Version = '1.0.2.0'
    ShowTopBorder = False
    object tbHome: TW7ToolButton
      Left = 3
      Top = 4
      Width = 30
      Height = 24
      Version = '1.0.2.0'
      Images = ilNavToolbar_On
      ImageIndex = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = tbHomeClick
    end
    object tbNavigatePrevious: TW7ToolButton
      Left = 39
      Top = 4
      Width = 30
      Height = 24
      Version = '1.0.2.0'
      Images = ilNavToolbar_On
      ImageIndex = 1
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = tbNavigatePreviousClick
    end
    object tbNavigateNext: TW7ToolButton
      Left = 71
      Top = 4
      Width = 30
      Height = 24
      Version = '1.0.2.0'
      Enabled = False
      Images = ilNavToolbar_On
      ImageIndex = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = tbNavigateNextClick
    end
    object tbPrivacy: TW7ToolButton
      Left = 107
      Top = 4
      Width = 30
      Height = 24
      Version = '1.0.2.0'
      Images = ilNavToolbar_On
      ImageIndex = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = tbPrivacyClick
    end
    object tbToggleFH: TW7ToolButton
      Left = 139
      Top = 4
      Width = 30
      Height = 24
      Version = '1.0.2.0'
      Images = ilNavToolbar_On
      ImageIndex = 5
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = tbToggleFHClick
    end
  end
  object W7ToolBar2: TW7ToolBar
    Left = 0
    Top = 0
    Width = 1440
    Height = 51
    Version = '1.0.2.0'
    ShowTopBorder = False
    object tbSave: TW7ToolButton
      Left = 3
      Top = 4
      Width = 39
      Height = 41
      Version = '1.0.2.0'
      Images = ilBigToolbar
      ImageIndex = 0
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = miSaveReportsClick
    end
    object tbPreferences: TW7ToolButton
      Left = 45
      Top = 4
      Width = 39
      Height = 41
      Hint = 'settings'
      Version = '1.0.2.0'
      Images = ilBigToolbar
      ImageIndex = 5
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = tbPreferencesClick
    end
    object tbReportFolder: TW7ToolButton
      Left = 87
      Top = 4
      Width = 39
      Height = 41
      Hint = 'Open report folder'
      Version = '1.0.2.0'
      Images = ilBigToolbar
      ImageIndex = 3
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = miReportBrowserClick
    end
    object tbWebReports: TW7ToolButton
      Left = 129
      Top = 4
      Width = 39
      Height = 41
      Hint = 'Open Web Reports'
      Version = '1.0.2.0'
      Images = ilBigToolbar
      ImageIndex = 6
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = tbWebReportsClick
    end
    object tbRefresh: TW7ToolButton
      Left = 177
      Top = 4
      Width = 39
      Height = 41
      Hint = 'Refresh all displays without rescanning'
      Version = '1.0.2.0'
      Images = ilBigToolbar
      ImageIndex = 2
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = tbRefreshClick
    end
    object tbSearchWizard: TW7ToolButton
      Left = 222
      Top = 4
      Width = 39
      Height = 41
      Hint = 'search wizard'
      Version = '1.0.2.0'
      Enabled = False
      Images = ilBigToolbar
      ImageIndex = 9
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = tbSearchWizardClick
    end
    object tbHelp: TW7ToolButton
      Left = 267
      Top = 4
      Width = 39
      Height = 41
      Version = '1.0.2.0'
      Images = ilBigToolbar
      ImageIndex = 4
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = Help2Click
    end
    object tbBuy: TW7ToolButton
      Left = 312
      Top = 4
      Width = 39
      Height = 41
      Hint = 'Buy Xinorbis 8'
      Version = '1.0.2.0'
      Images = ilBigToolbar
      ImageIndex = 7
      IconSize = is32px
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 5978398
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      Visible = False
      OnClick = miDonateClick
    end
  end
  object sbMain: THTMLStatusBar
    Left = 0
    Top = 800
    Width = 1440
    Height = 19
    AnchorHint = False
    Panels = <
      item
        DateFormat = 'mm/dd/yyyy'
        HTMLOffsetY = 0
        Progress.BackGround = clBtnFace
        Progress.TextColor = clBlack
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        TimeFormat = 'hh:mm:ss'
        Width = 600
      end
      item
        DateFormat = 'mm/dd/yyyy'
        HTMLOffsetY = 0
        Progress.BackGround = clBtnFace
        Progress.TextColor = clBlack
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        TimeFormat = 'hh:mm:ss'
        Width = 50
      end>
    SimplePanel = False
    URLColor = clBlue
    Version = '1.5.0.0'
  end
  object vtcHTML: TChart
    Left = 225
    Top = 302
    Width = 346
    Height = 200
    AllowPanning = pmNone
    BackWall.Brush.Style = bsClear
    BackWall.Pen.Visible = False
    Legend.Alignment = laLeft
    Legend.Brush.Gradient.Direction = gdRadial
    Legend.TextStyle = ltsPlain
    MarginBottom = 1
    MarginLeft = 1
    MarginRight = 1
    MarginTop = 1
    Title.Text.Strings = (
      '.....')
    AxisVisible = False
    ClipPoints = False
    Frame.Visible = False
    View3DOptions.Elevation = 315
    View3DOptions.Orthogonal = False
    View3DOptions.Perspective = 0
    View3DOptions.Rotation = 360
    View3DWalls = False
    Zoom.Allow = False
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 5
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object PieSeries6: TPieSeries
      Marks.BackColor = clWhite
      Marks.Color = clWhite
      XValues.Order = loAscending
      YValues.Name = 'Pie'
      YValues.Order = loNone
      Frame.InnerBrush.BackColor = clRed
      Frame.InnerBrush.Gradient.EndColor = clGray
      Frame.InnerBrush.Gradient.MidColor = clWhite
      Frame.InnerBrush.Gradient.StartColor = 4210752
      Frame.InnerBrush.Gradient.Visible = True
      Frame.MiddleBrush.BackColor = clYellow
      Frame.MiddleBrush.Gradient.EndColor = 8553090
      Frame.MiddleBrush.Gradient.MidColor = clWhite
      Frame.MiddleBrush.Gradient.StartColor = clGray
      Frame.MiddleBrush.Gradient.Visible = True
      Frame.OuterBrush.BackColor = clGreen
      Frame.OuterBrush.Gradient.EndColor = 4210752
      Frame.OuterBrush.Gradient.MidColor = clWhite
      Frame.OuterBrush.Gradient.StartColor = clSilver
      Frame.OuterBrush.Gradient.Visible = True
      Frame.Width = 4
      Gradient.Balance = 26
      Gradient.Direction = gdDiagonalDown
      Gradient.EndColor = 919731
      Gradient.StartColor = 919731
      Gradient.Visible = True
      OtherSlice.Legend.Visible = False
      OtherSlice.Text = 'Other'
      PiePen.Visible = False
    end
  end
  object vtcHTML2: TChart
    Left = 225
    Top = 95
    Width = 346
    Height = 201
    BackWall.Brush.Style = bsClear
    Legend.TextStyle = ltsPlain
    MarginBottom = 1
    MarginLeft = 1
    MarginRight = 1
    MarginTop = 1
    Title.Text.Strings = (
      '')
    View3D = False
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 6
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      Marks.Visible = False
      Marks.BackColor = clWhite
      Marks.Color = clWhite
      MultiBar = mbNone
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object ilToolbar: TImageList
    BlendColor = clBlack
    BkColor = clLime
    DrawingStyle = dsTransparent
    Left = 1032
    Top = 2
    Bitmap = {
      494C010133001C0658091000100000FF0000FF10FFFFFFFFFFFFFFFF424D3600
      000000000000360000002800000040000000D0000000010020000000000000D0
      00000000000000000000000000000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000EDAC0000EDAC0000EDAC0000EDAC
      0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC
      0000EDAC0000EDAC0000EDAC0000EDAC000000FF000000FF000000FF0000B1E0
      F20000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      0000ABD2ED00F9FCFE0000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000EDAC0000EDAB0000EDA90000EDAA
      0000EEAD1F00EEAF2F00EEAC0E00EDA90000EDAA0000EDAC0000EDAC0000EDAC
      0000EDAC0000EDAC0000EDAC0000EDAC000000FF000000FF000000FF000032B0
      DF0030ADDE0087CEEB0000FF000000FF000000FF000000FF00009ACDEB002290
      D3000D81CC0000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF00006494
      BA0022679D0081A8C60000FF000000FF0000EDAC0000EFB65800F5D2A700FAE7
      D300FCF1E500FCF3E800FCEFE100F8E1C800F3C99200EEAF2F00EDAA0000EDAC
      0000EDAC0000EDAC0000EDAC0000EDAC000000FF000000FF000000FF000044B8
      E30050CBEF0039B7E5002AA9DD0073C5E70082CAEA00269ED9002AA3DD0039AE
      E500198CD10000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF00006F9CC200558D
      BC0089B5DD00185F970000FF000000FF0000EFB03500F3C99100F8DEC100FCF1
      E400FFFEFD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBEEE000F1C07A00EDA9
      0000EDAC0000EDAC0000EDAC0000EDAC000000FF000000FF000000FF00005BC3
      E7004DCAEE0054CEF10050C8EF0040BAE80039B5E50046BDEB0044BAEB003EB3
      E8002C9AD60000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF00007BA4CA006497C5009DC1
      E4006699C7003171A50000FF000000FF0000EDAC0200EDAA0000EDA80000EEAE
      3300F8DDBC00FFFFFD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFAF500F3C7
      8D00EDA90000EDAC0100EDAC0000EDAC000000FF000000FF000000FF00007AD0
      EC0049C8EC0049CCF10031C3ED0042C4EE0046C3ED002CB6EA0026B1E8003CB4
      E70046ABDD0000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF0000E8CF
      BA00DBB29200D3A68000D0A17C00D2A68500AEA1990075A2CC00ABCBE80076A4
      CE00407BAF0000FF000000FF000000FF0000EDAC0000EDAB0000EFB44D00FAE8
      D500FFFDFB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEF8
      F200F0BC6D00EDAA0000EDAC0000EDAC000000FF000000FF000000FF00009BDC
      F10044C6EA0057D2F20027C2ED0023BDEC001FB7EA001BB3E90036B9EA003AB3
      E60067BDE40000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF0000E8CAB000E8C9
      AE00F5E1CD00F7E5D300F7E5D100F3DDC800DFBA9C00C7A8910086AED5005087
      BB0000FF000000FF000000FF000000FF0000EDAC0100EDA90000F3C99000FEFA
      F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FAE7D300EDAB0000EDAC0000EDAC000000FF000000FF0000F5FCFE0046C2
      E60059D5F20046D0F20029C4EE0025C0ED0022BBEB001DB6E90021B4E90046BD
      EB002AA7DB00E6F4FB0000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF0000F1DBC800EDD0B700F8E8
      D900F5DEC800F3D8BD00F3D6BB00F4DBC200F7E4D200DFBB9D00A097950000FF
      000000FF000000FF000000FF000000FF0000EDAC0000EEAE2900F8E0C600FFFD
      FA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFDFA00F1C07900EDAA0000EDAC000000FF0000FAFEFE004DC8E9004ACE
      ED005EDBF50030CDF1002CC8EF0027C3EE0024BEEC0020B8EA001CB4E90049C0
      EC0037B2E4002DA8DD00EBF7FC0000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF0000EECEB200F7E7D700F6E1
      CC00F4DBC200F4DAC000F3D8BD00F3D7BB00F4DBC200F3DEC900D2A8870000FF
      000000FF000000FF000000FF000000FF0000EDA60000F5D0A400FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F6D8B400EDA90000EDAC000000FF000054CEEB004CD2EE0063E1
      F60041D6F40032CFF2002ECBF0002AC6EF0026C1ED0022BCEB001FB7EA0020B4
      E90047BEEC0036B2E40032ABDD00EFF8FC000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF0000F0CEAF00F9ECDF00F5DF
      C800F5DDC600F4DCC300F4DAC100F3D9BE00F3D7BD00F8E6D300D3A6800000FF
      000000FF000000FF000000FF000000FF0000EDA90000F4CE9D00FDF5EB00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FAE6D200EDAA0000EDAC00005ED3EE004DD5EF0058DCF2005EDE
      F50060DEF5005FDCF60048D4F3002DC9EF0029C4EE0035C4ED0050C9EF004CC4
      EE0045BEEB003DB7E70033B0E20036ADDE000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF0000F4D3B500F9EDE100F6E1
      CC00F5DFC900F5DEC700F4DCC400F4DBC200F4DAC000F8E7D600D7AB870000FF
      000000FF000000FF000000FF000000FF0000EDA70000F3C78E00FFFDFB00FFFF
      FF00FFFCFA00FAEAD800F5D3AB00F6D5AF00FFFEFC00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FBEDDC00EDAA0000EDAC0000F6FDFE00B6EBF7007FDCF1005BD0
      ED0042C7E90049CEED005BD9F40047D3F2003ACBF00055CFF1003EBFE80035B7
      E2004BBCE4006EC8E900A3DBF100E6F5FB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF0000F8DBC100F9EBDE00F7E7
      D600F6E1CC00F5E0CA00F5DEC800F5DDC500F6E1CB00F5E2D000DFB9990000FF
      000000FF000000FF000000FF000000FF0000EDA60000F8E1C600FFFFFF00FBEB
      DB00F1C07A00EDAB0000EDA70000F0BB6B00FFFDFA00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFCF800F5D2A600EDAB050000FF000000FF000000FF000000FF
      000000FF00009CE2F30049CEED005DD9F40059D6F30043C5EA0079D1ED0000FF
      000000FF000000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF0000FCEAD800F8E2CC00FAEE
      E300F7E7D600F6E2CE00F6E1CB00F6E3D000F9EADD00ECCFB500ECD4BF0000FF
      000000FF000000FF000000FF000000FF0000EDA60000F7DCBB00F9E2CA00EEAE
      2C00EDAA0000EDAC0000EDAC0000EEAD1B00FAE7D200FFFFFF00FFFFFF00FFFF
      FF00FFFEFD00FEF8F000F6D6AF00EFB2410000FF000000FF000000FF000000FF
      000000FF000000FF000047CAEA0056D6F20059D6F3003AC0E600FAFDFE0000FF
      000000FF000000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF0000FBE4CE00F9E2
      CD00FAECDE00F9EEE200F9EDE200F8E9DA00F0D5BD00EDD0B70000FF000000FF
      000000FF000000FF000000FF000000FF0000EDAB0000EFB44C00EEAF3000EDAB
      0000EDAC0000EDAC0000EDAC0000EDAB0000EFB34900F8DEC100FCF2E700FBED
      DD00F3CA9400F1BC6D00F2C58600EEAB000000FF000000FF000000FF000000FF
      000000FF000000FF0000BCECF70048CEED0048CDED009BE0F30000FF000000FF
      000000FF000000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF0000FCEA
      D900FADDC200F6D6B900F4D3B500F3D4B800F5E0CD0000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000EDAC0200EDAB0000EDAC0000EDAC
      0000EDAC0000EDAC0000EDAC0000EDAC0100EDAB0000EDAA0000EEAE2700EEAC
      0200EDAA0000EDAB0000EDAA0000EDAC040000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000058D1EC0047CBEA0000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000EDAC0000EDAC0000EDAC0000EDAC
      0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC0000EDAC
      0000EDAC0000EDAC0000EDAC0000EDAC000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF0000D8F5FB00C1EEF80000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF000000FF000000FF
      000000FF000000FF0000CA8A6100C3845800D38B6800E18F7000DC8D6C00DA8B
      6D00D78A6E00CD8B6C00AB6D4400A65F2E0000FF000000FF000000FF0000C896
      6200CA986500CA976500CA976500CA976500CA976400C9976400C9976400CA98
      6500C895620000FF000000FF000000FF000000FF0000ACC3DC00C08A7500CB70
      3400D27E4100D37E4100D17C4100CD7A3F00B45F3F00B1B9C900C4DDF30000FF
      000000FF000000FF000000FF000000FF000000FF000076B2E6003E91DB00348C
      D900348CD900348CD900348CD900348CD900348CD900348CD900348CD900348B
      D900398FDA0085B9E90000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF0000C6835500EFCEBA00DDFFFF0087EEC700A2F4D700A2F6
      D7008CEEC700E0FFFF00DDA28500AB6A3E00A1A1A1007A7A7A0058585800C795
      6100F9F7F600F9F1EC00F9F1EB00F8F0E900F7EDE600F4EAE100F2E8DE00FAF8
      F600C7946100242424004B4B4B0096969600529CE2007185AC00C87E5900FFBA
      6600FFB76100FFB05E00FFB25D00FFB45C00DE88570087737E004C9BE60000FF
      000000FF000000FF000000FF000000FF00004799DD00DEF1FA00A8DDF4009EDB
      F40096DAF3008ED8F30086D7F3007FD4F20079D3F20072D2F1006CD0F10069CF
      F100C2EAF8003F95DB0000FF000000FF000000FF000000FF0000C5C5C500A5A5
      A500A1A1A100ABABAB00C37F5100EFB69A00EAF3E80051BF84006FC9980071C9
      990054BF8400E4F4E900DD9C7B00AA693A006B6B6B00A7A7A700B5B5B5008181
      8100AFACAA00C5C0BD00C5C0BD00C5C0BD00C5C0BD00C5C0BD00C5C0BD00ADAA
      A8002C2C2C00B5B5B5009B9B9B00232323003685D30093ACCC00E7AF7300FFB8
      5F00FEB05F00FEA75B00FDA05500FF974D00FD934D00B39FA2004E96DE0000FF
      000000FF000000FF000000FF000000FF00003B97DB00EFFAFE00A1E9F90091E5
      F80081E1F70072DEF60063DAF50054D7F40047D3F30039D0F2002ECDF10026CB
      F000CAF2FB003B97DB0000FF000000FF000000FF0000A9A9A900CECECE00EDED
      ED00F4F4F400F5F5F500C4815400EAB69700F3F3EA00EDF1E600EFF1E600EFF0
      E600EDF1E500F3F5ED00D59C7900B070440070707000B5B5B500B5B5B5009595
      95008181810081818100797979006E6E6E006161610052525200434343004242
      42006E6E6E00B5B5B500B5B5B50025252500DDC3B500B7755C00FDD7B200FFD6
      8400FFCA6500FFC05E00FFB45600FFA75700FFC59200D67D5B00B7907F0000FF
      000000FF000000FF000000FF000000FF00003C9DDB00F2FAFD00B3EDFA00A4E9
      F90095E6F80085E2F70081E1F7007AE0F7006FDDF60062DAF50054D6F30047D3
      F200E8F9FD003594DA0000FF000000FF0000B0B0B000DEDEDE00F3F3F300DBDB
      DB00D2D2D200DBDBDB00C98B6100E6B59200E2A78100E1A78100DEA37D00DCA1
      7B00DB9F7900D99E7700D49A7300BB7E570075757500BBBBBB00BBBBBB008D8D
      8D00D4D4D400B9B9B900B9B9B900B9B9B900B9B9B900B9B9B900B9B9B900D3D3
      D30083838300BBBBBB00BBBBBB002A2A2A0000FF0000DDB29B00CF7A5A00FFE8
      C000ADAA8600A79E7D00A0927500F7CA9C00E4947500C883650000FF000000FF
      000000FF000000FF000000FF000000FF00003BA3DB00F6FCFE00C8F2FC00B9EF
      FB00ACECFA008CE4F8008AE3F80082E1F70079DFF7006DDDF60061DAF50057D7
      F400E7F8FD003594DA0000FF000000FF0000B3B3B300F0F0F000DEDEDE00D4D4
      D400D2D2D200DBDBDB00CA8D6500EAB89900DDA57E00DDA68000DBA37C00D9A0
      7A00D9A07900D89F7800D89E7800BF845D007A7A7A00D7D7D700D7D7D7009797
      9700D8D8D800BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00D7D7
      D7008E8E8E00D7D7D700D7D7D7003F3F3F0000FF000000FF0000CB9E8700707C
      960073ADE70081B1E3007DB2E7006C98C40074552C005CA4640059A8680059A7
      670056A3640054935600BFB2BA00C4DDF3003BA8DB00FEFFFF00F8FDFF00F6FD
      FF00F5FCFF00DEDBD100ADCAC500A6C5C000A4C3BD009EBDB60097BAB30092B8
      B200E1CBB7003594DA00C3845200D0A17D00B5B5B500F2F2F200E2E2E200D8D8
      D800D5D5D500DCDCDC00C8885D00EFBFA100FDFCFA00FEFCFB00FEFDFD00FEFD
      FC00FDFBFA00FDFCFB00DDA88500C17F53007E7E7E00F9F9F900F9F9F900ABAB
      AB00DFDFDF00CBCBCB00CBCBCB00CBCBCB00CBCBCB00CBCBCB00CBCBCB00DFDF
      DF00A3A3A300F9F9F900F9F9F9006161610000FF000000FF0000BBB7BA0073A4
      D600ACD1F200AED7FD00B0D4F50092C0E7005483890079CF940077CE8E0076CE
      8F0076CE91006BB474005A8F5A004C9BE60039ADDB00E8F6FB007EC5EA005BAE
      E30051A8E10061ADDF00EDF6F700EDF5F600E7EFF300E5ECEE00E5EBED00E5EB
      ED00F8F3EF003594DA00F0E2D800C58B5E00B7B7B700F3F3F300E7E7E700DDDD
      DD00D9D9D900E0E0E000C7865B00EFC09E00FFFFFF00CC936E00FFFFFF00FFFF
      FF00FFFBF700FFF8F100E4AF8C00C78A610084848400FCFCFC00FCFCFC00CBCB
      CB00F2F2F200F2F2F200F2F2F200F2F2F200F2F2F200F2F2F200F2F2F200F2F2
      F200C6C6C600FCFCFC00FCFCFC007171710000FF000000FF00006B8EB700A7BF
      DB0096C5F100A1D0FB0096C6F300B6CFE400417AA70078CE8F0075CD890070CB
      83006ACB7B006AC97900609661004E96DE0040AEDC00F1FAFD0094DEF50093DC
      F40081D5F200C0A9970091C1E4003594DA003594DA003594DA003594DA003594
      DA003594DA003594DA00F0E2D800C4865400B8B8B800F4F4F400EAEAEA00E1E1
      E100DDDDDD00E3E3E300CC8D6500F3CDB000FFFFFF00E3C7B300FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00EABFA100C989600097979700D2D2D200E8E8E8007D7D
      7D007D7D7D007D7D7D007D7D7D007D7D7D007D7D7D007D7D7D007D7D7D007D7D
      7D007D7D7D00E8E8E800C4C4C4006D6D6D0000FF000000FF0000617EA9005069
      9A006380AE007CA6D6005573A500435D9200446798007CD09F0077CE970071CD
      8E0072CD88009DD8AB006DB0700088A78B0041B4DC00F7FCFE008EE4F80091DE
      F5009FE0F500E3B18C00FAF6F100EAC9AE00FFFFFF00E8C7AC00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F1E5DB00C6865500BABABA00F5F5F500EEEEEE00E6E6
      E600E2E2E200E6E6E600D4976E00D49E7B00D0987100D6A48200CD8E6800CD90
      6900D09A7500D1997300C88B620000FF0000DDDDDD009A9A9A00CCCCCC00C78B
      4E00F9F4ED00FEE8D800FEE8D700FDE5D300FCE4D100FAE0C700F9DDC300FAF4
      ED00C7854A00C3C3C30074747400CDCDCD0000FF000000FF0000C5CCD5004562
      9600415B9000415B9000415B9000415B90006F8F9E00849993007D948900758C
      7F00A4D5B10082BF850077AE7B0000FF00003CB5DB00FDFEFE00FEFFFF00FEFE
      FF00FDFEFF00E5B48F00FAF6F200E9C6AA00E9C6AC00E8C7AC00E8C7AC00E9C9
      B000E8C8B000E8CCB500F2E7DE00C88A5900BBBBBB00F6F6F600EBEBEB00DEDE
      DE00D6D6D600D5D5D500D1D1D100C3C3C300BCBCBC00C0C0C000E5E5E500ABAB
      AB0000FF000000FF000000FF000000FF000000FF0000CECECE0087878700C589
      4C00F9F4EF00FEE7D700FDE7D500FCE6D200FBE1CC00F8DCC200F6DABD00FAF4
      EF00C483480061616100BCBCBC0000FF000000FF000000FF000000FF0000ACB7
      C5004C6A9B00415D920046629800577987006E7A940073ADE70081B1E3007DB2
      E7006C98C40068916A0000FF000000FF000059C2E00061C3E20063C4E30063C4
      E30063C4E300E7B79400FBF7F400E9C3A600FFFFFF00E8C7AC00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F7F1EB00CB8F5F00BDBDBD00F7F7F700E7E7E700EFEF
      EF00F6F6F600FBFBFB00FAFAFA00F0F0F000DEDEDE00C3C3C300E6E6E600ACAC
      AC0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000C68C
      4F00F9F4F000FCE6D300FDE7D300FBE3CD00FAE0C800F5D6BB00F3D4B500F8F4
      F000C4854A0000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF0000BBB7BA0073A4D600ACD1F200AED7FD00B0D4
      F50092C0E7007D92AA0000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000E9BA9800FBF7F400E9C3A600E9C3A600E9C3A600E9C3A600E9C3
      A600E9C3A600E9C3A600FBF7F400CE936400BFBFBF00F8F8F800FEFEFE00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBFBFB00EAEAEA00AEAE
      AE0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000C88D
      5100F9F5F100FCE3CF00FCE4CF00FAE1CA00F9DDC400F4E9DF00F7F2EC00F5EF
      E900C380480000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF00007AA0C500B8D0E70096C5F100A1D0FB0096C6
      F300B6CFE4004B93C70000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000EBBD9B00FBF7F400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FBF7F400D1976A00CBCBCB00E1E1E100FEFEFE00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBFBFB00CFCFCF00C9C9
      C90000FF000000FF000000FF000000FF000000FF000000FF000000FF0000C88D
      5200F9F5F100FCE3CD00FBE3CD00F9E0C800F8DCC200FDFBF800FCE6CD00E2B6
      8400D5A8840000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000079A3C70034AEE50065B8E6008DC8F6003BAD
      E6001DA7E500319ED70000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000ECBF9E00FBF7F4009CD5A50098D3A1008BCB930082C689007EC3
      84007AC1800076BE7C00FBF7F400D49B6F0000FF0000C7C7C700D0D0D000E8E8
      E800F3F3F300FDFDFD00FCFCFC00EDEDED00E0E0E000C2C2C200C0C0C00000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000C588
      4D00F7F2EC00F8F4EE00F8F3ED00F8F3ED00F8F2EC00F2E6D700E2B27D00DB95
      690000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF0000C3CFD90023A4DF0019A6E50019A6E50019A6
      E50019A6E50083ABC50000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000EFC6A800FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7
      F400FBF7F400FBF7F400FBF7F400D8A3780000FF000000FF000000FF0000D0D0
      D000C3C3C300B8B8B800B8B8B800C3C3C300CDCDCD0000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000E8CE
      B900D7AA7C00C88C5000C88C4F00CA915500CB905500C5894D00DDAF8D0000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000A8BECD00319DD5001BA5E40024A1
      DF0077A6C40000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000F7E1D200F1C8AC00EDC09F00EBBE9D00E7B79300E4B28C00E2AF
      8800E0AC8400DDA98000DCA57D00E2B6960000FF0000E2C0AA00CC8D6600C071
      4000BC6B3600BC6B3600BC6B3600BC6A3600BC6A3600BB6A3500BB6A3500BB69
      3500BD6E3B00CA8B6300E3C2AE0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF00004E4E4E003F3F3F003F3F
      3F003F3F3F005152510000FF000000FF000000FF000000FF00004E4E4E003F3F
      3F003F3F3F003F3F3F005152510000FF000000FF000000FF0000E2C0AA00CC8D
      6600C0714000BC6B3600BC6B3600BC6B3600BC6A3600BC6A3600BB6A3500BB6A
      3500BB693500BD6E3B00CA8B6300E3C2AE0000FF0000C57C4D00F8F2EB00F7EC
      DF00F6EBDE00F6EADE00F6EADC00F6EADC00FAF3EB00FAF3EB00FAF2EA00FCF7
      F300FCF8F400FEFEFD00C37A4D0000FF000000FF000000FF000000FF000000FF
      0000C5C5C500A5A5A500A1A1A100ABABAB00A7A7A7009595950098989800BFBF
      BF0000FF000000FF000000FF000000FF000019191A009D607F00AF6A8F00AF6A
      8F00AF6A8F009D5F80002626260000FF000000FF000019191A009D5F8000AF69
      9100AF699100AF6995009D5F83002626260000FF000000FF0000C57C4D00F8F1
      EA00F7ECDF00F6EBDE00F6EADE00F6EADC00F6EADC00FAF3EB00FAF3EB00FAF2
      EA00FCF7F300FCF8F400FEFEFD00C37A4D0000FF0000C2774000F5EBDF00FCE4
      D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FDFBF800BC6B370000FF000000FF000000FF000000FF0000A9A9
      A900CECECE00EDEDED00F4F4F400F5F5F500F4F4F400EFEFEF00E2E2E200BABA
      BA009595950000FF000000FF000000FF000019191A009D5F6F00E28E9000FF96
      9C00BA7782009D5F6F002626260000FF000000FF000019191A009D5F7100D37C
      8F00FF96A000E28E94009D5F72002626260000FF000000FF0000C2774000F5EB
      DF00FCE4D1009FA9BC00617DA300FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FCE4D100FDFBF800BC6B370000FF0000C37C4200F7EDE300FCE4
      D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FBF7F400BD6C370000FF000000FF000000FF0000B0B0B000DEDE
      DE00F3F3F300DBDBDB00D2D2D200DBDBDB00D6D6D600C0C0C000C9C9C900E6E6
      E600C4C4C4009595950000FF000000FF000000FF00004E4E4E00746B6700E2A9
      8500BC9071006869680000FF000000FF000000FF000000FF000060606000BD8E
      7100E2A38500666464005152510000FF000000FF000000FF0000C37C4200F7ED
      E300FCE4D1009FADB300738FA200FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FCE4D100FBF7F400BD6C3700E8A38B00D17D4300F3E0D300FCE4
      D100E48C6D00D1764000FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FCF9F500C1743C0000FF000000FF000000FF0000B3B3B300F0F0
      F000DEDEDE00D4D4D400D2D2D200DBDBDB00D6D6D600BFBFBF00B0B0B000B3B3
      B300DEDEDE009999990000FF000000FF000000FF000000FF0000353535006566
      5B00F9E38E00999C6B007474740000FF000000FF000067676700A5976800E8D8
      8D00636354003A3A3A0000FF000000FF0000E6ECDF00A5B892008CA5740096AF
      7E0096AF7D0089A5750084A2720095AE7D0095AF7D0091AB7800A7BC9200E4EA
      DE00FCE4D100FCE4D100FCF9F500C1743C00EAAF9800E7A26B00D17D4B00FEE5
      D500E2875E00D4844F00E9A08800FCE5D300FCE4D100FCE2CE00FCE2CC00FBE0
      C900FBE1C800FDFAF700C37A410000FF000000FF000000FF0000B5B5B500F2F2
      F200E2E2E200D8D8D800D5D5D500DCDCDC00D8D8D800C0C0C000B3B3B300B7B7
      B700E0E0E0009F9F9F0000FF000000FF000000FF000000FF000000FF00002525
      2500615F4800DDFF9100718054004D4A4E0088848500788C5400D7FA9300616D
      58002D2D2D0000FF000000FF000000FF000000FF0000ECF0E900869E71004574
      0000517D1E00547F250056802700517D1E0049790000839F6A00ECF0E900FCE2
      CC00FBE0C900FBE1C800FDFAF700C37A4100EFC1AE00E7A16800D2814600FCDF
      CC00E9A18500E69C6700D17A4000FDE6D500FDE5D300FCE4D100FCE2CD00FBE1
      CB00FBE1C900FBF7F200C780450000FF000000FF000000FF0000B7B7B700F3F3
      F300E7E7E700DDDDDD00D9D9D900E0E0E000DBDBDB00C4C4C400B8B8B800BBBB
      BB00E1E1E100A3A3A30000FF000000FF000000FF000000FF000000FF000000FF
      000050505100656D5100AEFF91005D6E5300566C4E00AEFF910059664E001A1A
      190000FF000000FF000000FF000000FF000000FF000000FF0000B2C4A00084A0
      69007A9B5A007C9C5D007C9C5D007B9B5C0084A26800B2C5A000FCE4D100FCE2
      CD00FBE1CB00FBE1C900FBF7F200C7804500F0C8B500E6A46900E8A67000D27E
      4600E89C7C00E8A16D00D3844D00EFB49B00FDE5D300FBE4D000FBE3CC00FADF
      C700FADFC600FAF2EA00C884480000FF000000FF000000FF0000B8B8B800F4F4
      F400EAEAEA00E1E1E100DDDDDD00E3E3E300DEDEDE00C9C9C900BDBDBD00BFBF
      BF00E2E2E200A6A6A60000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000757575005A8C62008FFAA2008FFAA200597C50008884850000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000B4C0AA006188
      3400698E4300698E4400698E4400688D4200648C3400C1CEB500FBE4D000FBE3
      CC00FADFC700FADFC600FAF2EA00C8844800F2D1BE00E6A56900E6A68400D281
      4400E7A46C00E4926200E38D4A00D17D4300FCE4D100FBE1CC00FAE0C700F9DD
      C300F8DCC200FAF4ED00C8864B0000FF000000FF000000FF0000BABABA00F5F5
      F500EEEEEE00E6E6E600E2E2E200E6E6E600E1E1E100CDCDCD00C2C2C200C2C2
      C200E3E3E300A8A8A80000FF000000FF000000FF000000FF000000FF000000FF
      000000FF00003A3A3A0044524F0091FEDB008EFAD100494A4C003D3D3D0000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000F3F6F000A7B8
      9A00577F2D005D8535005C853400638C3C00AFC2A100F2F6EF00FBE1CC00FAE0
      C700F9DDC300F8DCC200FAF4ED00C8864B00F8E7DD00E6A26200EFCAB500FEE7
      D700D2834700E79C7600FDE6D400D17F4300EBA88A00FADFC700F8DCC200F6DA
      BD00F6D8BB00FAF4EF00C8874C0000FF000000FF000000FF0000BBBBBB00F6F6
      F600EBEBEB00DEDEDE00D6D6D600D5D5D500D1D1D100C3C3C300BCBCBC00C0C0
      C000E5E5E500ABABAB0000FF000000FF000000FF000000FF000000FF000000FF
      000000FF00006669670083CDD7007CBBCC007CBBCC007BC6D30039353C0000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000C88C5000839C
      6B00769656007A9A5B007A9A5A0079995A0084A36600FBE1CC00FADFC700F8DC
      C200F6DABD00F6D8BB00FAF4EF00C8874C00F0C7AF00E8AC7100E49F6300FCE6
      D300E3975300E3955000FCE4D100E5986F00D2814600F7D8BD00F5D6BB00F3D4
      B500F1D2B300F8F4F000C6864C0000FF000000FF000000FF0000BDBDBD00F7F7
      F700E7E7E700EFEFEF00F6F6F600FBFBFB00FAFAFA00F0F0F000DEDEDE00C3C3
      C300E6E6E600ACACAC0000FF000000FF000000FF000000FF000000FF000000FF
      00004545450070A2BD0081BDD600727479006161640080C3E2006F9FBD005656
      570000FF000000FF000000FF000000FF000000FF000000FF0000C88D5100CED8
      C600577A390045720D00477316004D791400BCCAB100FAE0C800F8DCC200F5D6
      BB00F3D4B500F1D2B300F8F4F000C6864C00E8AE8700E4A05B00E4A05B00EDB1
      8C00EDB49100E49B5800EDB28F00EBAD8900D2824500E28E5600F4E9DF00F7F2
      EC00FBF7F300F5EFE900C380480000FF000000FF000000FF0000BFBFBF00F8F8
      F800FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBFB
      FB00EAEAEA00AEAEAE0000FF000000FF000000FF000000FF000000FF00006A6A
      6A006E85AD0084B5E200565E65003A3A3A003535350050595B008EBAEA00637A
      94007474740000FF000000FF000000FF000000FF000000FF0000C88D5100F9F5
      F1008AA56F0065894200678B45007E9E5E00FAE1CA00F9DDC400F6D9BC00F4E9
      DF00F7F2EC00FBF7F300F5EFE900C380480000FF0000C88D5200F9F5F100FCE3
      CD00FBE3CE00FBE3CD00FBE2CB00F9E0C800F8DCC200F5D6BA00FDFBF800FCE6
      CD00FAE5C900E2B68400D5A8840000FF000000FF000000FF0000CBCBCB00E1E1
      E100FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBFB
      FB00CFCFCF00C9C9C90000FF000000FF000000FF00002D2D2D00606060005664
      8C008EA0EA003A3841006364620000FF000000FF0000575757002F39480091A3
      FF004E56800071706C003132310000FF000000FF000000FF0000C88D5200F9F5
      F100C8D0C200487417003A6E0000A5B89600F9E0C800F8DCC200F5D6BA00FDFB
      F800FCE6CD00FAE5C900E2B68400D5A8840000FF0000CA925A00FAF6F200FAE0
      C700FBE1C900FBE2C900FBE0C800F9DFC500F8DBC100F4D6B800FFFBF800F6D8
      B400E1B07D00DC96690000FF000000FF000000FF000000FF000000FF0000C7C7
      C700D0D0D000E8E8E800F3F3F300FDFDFD00FCFCFC00EDEDED00E0E0E000C2C2
      C200C0C0C00000FF000000FF000000FF000000FF00004D4460008670C600AA91
      FF009783E2008570C60058506C0000FF000000FF00004D4460008570C600A090
      EA00A191FF008170C60058506C0000FF000000FF000000FF0000CA925A00FAF6
      F200FAE0C700B6C1AE00688D4500FBE0C800F9DFC500F8DBC100F4D6B800FFFB
      F800F6D8B400E1B07D00DC96690000FF000000FF0000D2A27400F8F3ED00F8F4
      EE00F8F4ED00F8F3ED00F8F3ED00F8F3ED00F8F2EC00F7F2EC00F2E6D700E2B2
      7D00DC986B0000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000D0D0D000C3C3C300B8B8B800B8B8B800C3C3C300CDCDCD0000FF
      000000FF000000FF000000FF000000FF000000FF0000544460009370C5009370
      C5009370C5009370C5005F506B0000FF000000FF0000524460009070C5009070
      C5009070C5009070C5005F506B0000FF000000FF000000FF0000D2A27400F8F3
      ED00F8F4EE00F8F4ED00F8F3ED00F8F3ED00F8F3ED00F8F2EC00F7F2EC00F2E6
      D700E2B27D00DC986B0000FF000000FF000000FF0000E8CEB900D7AA7C00CC94
      5B00CA905500CA905500CA905500CA915500CB905500C98F5500CF9D6900DDB1
      900000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF00002E2E2E003F3F3F003F3F
      3F003F3F3F003F3F3F003132310000FF000000FF00002E2E2E003F3F3F003F3F
      3F003F3F3F003F3F3F003132310000FF000000FF000000FF0000E8CEB900D7AA
      7C00CC945B00CA905500CA905500CA905500CA915500CB905500C98F5500CF9D
      6900DDB1900000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      0000DDDDDD00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00DDDDDD0000FF
      000000FF000000FF000000FF000000FF000000FF0000E2C0AA00CC8D6600C071
      4000BC6B3600BC6B3600BC6B3600BC6A3600BC6A3600BB6A3500BB6A3500BB69
      3500BD6E3B00CA8B6300E3C2AE0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000ECECEC00CCCC
      CC00919191007A7A7A007A7A7A007A7A7A007A7A7A007A7A7A009E9E9E00CCCC
      CC00ECECEC0000FF000000FF000000FF000000FF0000C57C4D00F8F2EB00F7EC
      DF00F6EBDE00F6EADE00F6EADC00F6EADC00FAF3EB00FAF3EB00FAF2EA00FCF7
      F300FCF8F400FEFEFD00C37A4D0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000E4E4E400ADADAD007A7A
      7A00A8A8A800D0D0D000C7C7C700C1C1C100D0D0D000CDCDCD00AEAEAE007A7A
      7A00ADADAD00ECECEC0000FF000000FF000000FF0000C2774000F5EBDF00FCE4
      D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FDFBF800BC6B370000FF000000FF000052525200525252005252
      5200525252005252520052525200525252005252520052525200525252005252
      520052525200525252005252520000FF000000FF000066666600666666006666
      6600666666006666660066666600666666006666660066666600666666006666
      660066666600666666006666660000FF000000FF00009E9E9E0081818100CDCD
      CD00C7C7C700D0D0D000D0D0D000B0B0B000D0D0D000D2D2D200DCDCDC00D2D2
      D2007A7A7A00B6B6B60000FF000000FF000000FF0000C37C4200F7EDE300FCE4
      D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FBF7F400BD6C370000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000066666600666666006666
      6600666666006666660066666600666666006666660066666600666666006666
      660066666600666666006666660000FF0000E4E4E40081818100C7C7C700DCDC
      DC00D2D2D200F2F2F200A6A6A6008A8A8A00B6B6B600F2F2F200EEEEEE00F2F2
      F200C7C7C7007A7A7A0000FF000000FF000000FF0000C6804600F7F0E600FCE4
      D100FCE4D100E5D9C200689E700057966500599766006CA07300FCE4D100FCE4
      D100FCE4D100FCF9F500C1743C0000FF000000FF000052525200525252005252
      5200525252005252520052525200525252005252520052525200525252005252
      520052525200525252005252520000FF000000FF000066666600666666006666
      6600666666006666660066666600666666006666660066666600666666006666
      660066666600666666006666660000FF0000B7B7B70097979700B7B7B7009F9F
      9F00B1B1B100A6A6A600B8B8B800CECECE00BBBBBB00B0B0B000B1B1B100A0A0
      A000D2D2D20081818100ECECEC0000FF0000328449001A753300197533001974
      3300448A5200619B6B00BBD6C30078BB840061AB6A0057966400FCE2CC00FBE0
      C900FBE1C800FDFAF700C37A410000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000066666600666666006666
      6600666666006666660066666600666666006666660066666600666666006666
      660066666600666666006666660000FF0000ADADAD0097979700969696003C3C
      3C00030303007C7C7C00E4E4E400FFFFFF00AEAEAE003C3C3C00030303007C7C
      7C00AFAFAF008B8B8B00C8C8C80000FF0000A3C8AD001B7533005BA06E004996
      5C0047905B00C7DDCD005DB6710067AE7500448D58001B753300FCE2CD00FBE1
      CB00FBE1C900FBF7F200C780450000FF000000FF0000B5B5B5001E1E1E00B5B5
      B5001E1E1E00B5B5B5001E1E1E00B5B5B5001E1E1E00B5B5B500525252005252
      520052525200525252005252520000FF000000FF000033333300333333003333
      3300333333003333330033333300333333003333330033333300333333003333
      330033333300333333003333330000FF00009E9E9E00A8A8A80096969600FEFE
      FE00474747006A6A6A00E4E4E400FFFFFF00A0A0A000EEEEEE006C6C6C007474
      7400AFAFAF0097979700ADADAD0000FF0000FFFFFF00828143001F7837004891
      5D00C7DDCD006AC0840071B68200448E5900B1C1A100FBE4D000FBE3CC00FADF
      C700FADFC600FAF2EA00C884480000FF000000FF00001E1E1E00B5B5B5001E1E
      1E00B5B5B5001E1E1E00B5B5B5001E1E1E00B5B5B5001E1E1E0000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000033333300333333003333
      3300333333003333330033333300333333003333330033333300333333003333
      330033333300333333003333330000FF00009E9E9E00A6A6A600A8A8A8009F9F
      9F006E6E6E00AEAEAE00FFFFFF00ECECEC00ECECEC009F9F9F006E6E6E009696
      9600C7C7C700A8A8A800ADADAD0000FF0000FFFFFF00C48C4F00619E7100C5DC
      CC0076C9970073BC8700438D580055936000F5E0CC00FBE1CC00FAE0C700F9DD
      C300F8DCC200FAF4ED00C8864B0000FF000000FF0000B5B5B5001E1E1E00B5B5
      B5001E1E1E00B5B5B5001E1E1E00B5B5B5001E1E1E00B5B5B500525252005252
      520052525200525252005252520000FF000000FF000033333300333333003333
      3300333333003333330033333300333333003333330033333300333333003333
      330033333300333333003333330000FF000091919100A8A8A800AFAFAF00C7C7
      C700D2D2D200EEEEEE00FFFFFF00CACACA00FFFFFF00EEEEEE00DCDCDC00CDCD
      CD00B7B7B700A0A0A0009191910000FF0000FAFCFA00718C5500C0D9C80082D3
      A3006DC18A00549563004B96600051976400679A6800F4DCC300F8DCC200F6DA
      BD00F6D8BB00FAF4EF00C8874C0000FF000000FF00001E1E1E00B5B5B5001E1E
      1E00B5B5B5001E1E1E00B5B5B5001E1E1E00B5B5B5001E1E1E0000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00007A7A7A00B7B7B700AFAFAF00B7B7
      B700C7C7C700D2D2D200FFFFFF00CACACA00F2F2F200D2D2D200CDCDCD00C7C7
      C700B7B7B700B7B7B7007A7A7A0000FF000080B28E00B5D3BE009CDAB50074C8
      9500549563004A935F005DA4740059A16E005097640062976200E9D1B400F3D4
      B500F1D2B300F8F4F000C6864C0000FF000000FF0000B5B5B5001E1E1E00B5B5
      B5001E1E1E00B5B5B5001E1E1E00B5B5B5001E1E1E00B5B5B500525252005252
      520052525200525252005252520000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00007A7A7A00B3B3B300B7B7B700AFAF
      AF00B7B7B700C7C7C700FEFEFE00C8C8C800DCDCDC00CDCDCD00C7C7C700B7B7
      B700B7B7B700B8B8B8007A7A7A0000FF00005B9C6E00568C5700539666005495
      6300A1B995008DAE83002E7F42002E7F41003A8448003682450090B49000F7F2
      EC00FBF7F300F5EFE900C380480000FF000000FF00001E1E1E00B5B5B5001E1E
      1E00B5B5B5001E1E1E00B5B5B5001E1E1E00B5B5B5001E1E1E0000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00007A7A7A00B8B8B800B8B8B800B7B7
      B700AFAFAF00B7B7B700DCDCDC00DCDCDC00CDCDCD00C7C7C700B7B7B700B7B7
      B700C1C1C100B8B8B8007A7A7A0000FF000000FF0000C88D5200F9F5F100FCE3
      CD00FBE3CE00FBE3CD00FBE2CB00F9E0C800F8DCC200F5D6BA00FDFBF800FCE6
      CD00FAE5C900E2B68400D5A8840000FF000000FF0000B5B5B5001E1E1E00B5B5
      B5001E1E1E00B5B5B5001E1E1E00B5B5B5001E1E1E00B5B5B500525252005252
      520052525200525252005252520000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00007A7A7A00C1C1C100CECECE00DCDC
      DC009797970097979700AFAFAF00C7C7C700A8A8A80097979700A0A0A000DCDC
      DC00CECECE00C1C1C1007A7A7A0000FF000000FF0000CA925A00FAF6F200FAE0
      C700FBE1C900FBE2C900FBE0C800F9DFC500F8DBC100F4D6B800FFFBF800F6D8
      B400E1B07D00DC96690000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00007A7A7A00B7B7B700CDCDCD008B8B
      8B00CACACA00BCBCBC00BCBCBC00BCBCBC00BCBCBC00CACACA00CACACA008B8B
      8B00D2D2D200C8C8C8007A7A7A0000FF000000FF0000D2A27400F8F3ED00F8F4
      EE00F8F4ED00F8F3ED00F8F3ED00F8F3ED00F8F2EC00F7F2EC00F2E6D700E2B2
      7D00DC986B0000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000AEAEAE007A7A7A0091919100ECEC
      EC0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000E4E4
      E4007A7A7A007A7A7A009E9E9E0000FF000000FF0000E8CEB900D7AA7C00CC94
      5B00CA905500CA905500CA905500CA915500CB905500C98F5500CF9D6900DDB1
      900000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00007B7B7B007B7B7B007B7B7B007878
      7800787878007878780078787800787878007474740074747400747474007171
      7100717171007070700070707000707070000B0B0B0020202000202020002020
      20007B7B7B007B7B7B0020202000202020002020200020202000202020002020
      20002020200020202000202020000B0B0B0020202000202020003C3C3C003C3C
      3C003C3C3C003C3C3C003C3C3C003C3C3C003C3C3C003C3C3C003C3C3C003C3C
      3C003C3C3C003C3C3C003C3C3C003C3C3C002E2E2E002E2E2E002E2E2E001E1E
      1E001E1E1E001E1E1E0009090900090909000909090000000000000000000000
      0000000000000000000000000000000000007F7F7F0098989800959595009595
      950091919100919191008C8C8C008A8A8A008A8A8A0086868600868686008383
      830083838300828282008282820070707000202020004C4C4C004C4C4C004C4C
      4C00F7F7F700F7F7F7004C4C4C004C4C4C004C4C4C004C4C4C004C4C4C004C4C
      4C004C4C4C004C4C4C004C4C4C00202020002020200037373700373737007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C003C3C3C009C9C9C009C9C9C009494
      940094949400949494008D8D8D008C8C8C008888880086868600848484008282
      82007E7E7E007C7C7C007C7C7C00000000007F7F7F00989898008B8B8B008888
      88008888880086868600828282008282820080808000808080007D7D7D007D7D
      7D007B7B7B007B7B7B008282820071717100202020004C4C4C004C4C4C004C4C
      4C00F7F7F700F7F7F7004C4C4C004C4C4C004C4C4C004C4C4C004C4C4C004C4C
      4C004C4C4C004C4C4C004C4C4C00202020002020200037373700373737003737
      37007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C003C3C3C009C9C9C008C8C8C008888
      880084848400828282007F7F7F007C7C7C007979790075757500727272006F6F
      6F006C6C6C006C6C6C007C7C7C0000000000F7F7F700F8F8F800F6F6F600C9C9
      C900CDCDCD00B4B4B400B9B9B900ECECEC00F0F0F000EFEFEF00EEEEEE00EDED
      ED00ECECEC00ECECEC00F0F0F000D9D9D900202020004C4C4C004C4C4C004C4C
      4C00F7F7F700F7F7F7004C4C4C004C4C4C004C4C4C004C4C4C004C4C4C004C4C
      4C004C4C4C004C4C4C004C4C4C00202020002020200037373700373737003737
      3700373737007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C003C3C3C00A3A3A3008F8F8F008C8C
      8C008888880084848400828282007F7F7F007C7C7C0079797900757575007272
      72006F6F6F006C6C6C007E7E7E0000000000F7F7F700F8F8F800F6F6F600F2F2
      F200A2A2A2008A8A8A00ECECEC00DDDDDD00F0F0F000F0F0F000EFEFEF00EEEE
      EE00EDEDED00ECECEC00EFEFEF00E0E0E0007B7B7B00F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F7007B7B7B002020200037373700373737003737
      370037373700373737007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C00FDFDFD00FDFDFD00FCFCFC00FCFC
      FC00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F600F5F5F500F4F4
      F400F3F3F300F3F3F300F4F4F400E5E5E500F7F7F700F9F9F900F7F7F700CFCF
      CF0093939300D9D9D900CACACA00DEDEDE00F2F2F200F0F0F000F0F0F000EFEF
      EF00EEEEEE00EDEDED00EFEFEF00E0E0E0007B7B7B00F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F7007B7B7B002020200037373700373737003737
      37003737370037373700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F00FDFDFD00FEFEFE00FDFDFD00FCFC
      FC00FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F600F5F5
      F500F4F4F400F3F3F300F5F5F500E5E5E500F7F7F700F9F9F900F8F8F800EDED
      ED00A0A0A00093939300E0E0E000ECECEC00F3F3F300F2F2F200F0F0F000F0F0
      F000EFEFEF00EEEEEE00EFEFEF00E0E0E000202020004C4C4C004C4C4C004C4C
      4C00F7F7F700F7F7F7004C4C4C004C4C4C004C4C4C004C4C4C004C4C4C004C4C
      4C004C4C4C004C4C4C004C4C4C00202020002020200037373700373737003737
      370037373700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F00FDFDFD00FEFEFE00FEFEFE00FDFD
      FD00FCFCFC00FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6
      F600F5F5F500F4F4F400F5F5F500E5E5E500F7F7F700F9F9F900F8F8F800F8F8
      F800EAEAEA00DDDDDD00EFEFEF00F5F5F500F5F5F500F3F3F300F2F2F200F0F0
      F000F0F0F000EFEFEF00EFEFEF00E0E0E000202020004C4C4C004C4C4C004C4C
      4C00F7F7F700F7F7F7004C4C4C004C4C4C004C4C4C004C4C4C004C4C4C004C4C
      4C004C4C4C004C4C4C004C4C4C00202020002020200037373700373737003737
      3700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F00676767009C9C9C008B8B8B008989
      89008787870084848400828282007F7F7F007D7D7D007A7A7A00777777007575
      750072727200727272007C7C7C005454540082828200A5A5A500959595009595
      95009595950091919100919191008F8F8F008B8B8B008B8B8B00888888008686
      860083838300828282008C8C8C0078787800202020004C4C4C004C4C4C004C4C
      4C00F7F7F700F7F7F7004C4C4C004C4C4C004C4C4C004C4C4C004C4C4C004C4C
      4C004C4C4C004C4C4C004C4C4C0020202000202020003737370037373700FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F00676767009D9D9D008B8B8B008B8B
      8B00898989008787870084848400828282007F7F7F007D7D7D007A7A7A007777
      770075757500727272007F7F7F005454540082828200A5A5A500A5A5A500A5A5
      A500A5A5A500A0A0A000A0A0A0009D9D9D009D9D9D0098989800989898009595
      950091919100919191008C8C8C00787878000B0B0B0020202000202020002020
      20007B7B7B007B7B7B0020202000202020002020200020202000202020002020
      20002020200020202000202020000B0B0B0020202000202020007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F00676767009D9D9D009D9D9D009C9C
      9C009C9C9C00989898009898980093939300939393008E8E8E008E8E8E008A8A
      8A00878787008484840081818100545454008282820082828200828282008282
      8200818181008181810081818100818181007F7F7F007F7F7F007F7F7F007B7B
      7B007B7B7B007B7B7B00787878007878780000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00006767670067676700676767006767
      67006767670064646400646464006464640064646400646464005E5E5E005E5E
      5E005E5E5E005A5A5A005A5A5A005454540000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00006C6C6C0059595900595959005959
      59004A4A4A00BBBBBB00BBBBBB00B1B1B100AAAAAA00AAAAAA009F9F9F006767
      6700676767006464640064646400646464009191910091919100919191009191
      910085858500858585008B8B8B008B8B8B008B8B8B0087878700858585007E7E
      7E00858585007E7E7E007E7E7E007E7E7E006565650056565600565656004949
      490049494900CDCDCD00C8C8C800C8C8C800C2C2C200C2C2C200C2C2C2007171
      7100717171007070700070707000707070001919190036363600363636003636
      360036363600282828003C3C3C003C3C3C003C3C3C003C3C3C003C3C3C003C3C
      3C003C3C3C003C3C3C003C3C3C001A1A1A006C6C6C00BEBEBE00BCBCBC00B8B8
      B800B4B4B400EDEDED00ECECEC00E9E9E900E8E8E800E6E6E600E6E6E6009696
      960093939300919191009292920064646400A4A4A400EBEBEB00EBEBEB00EBEB
      EB00EBEBEB00E5E5E500E5E5E500E5E5E500E1E1E100E1E1E100E1E1E100DCDC
      DC00DCDCDC00DCDCDC00DCDCDC007E7E7E005E5E5E00ABABAB00A9A9A900A6A6
      A600A2A2A200F8F8F800F7F7F700F7F7F700F6F6F600F5F5F500F4F4F4008383
      830083838300818181008181810070707000363636006D6D6D006D6D6D006D6D
      6D006D6D6D00515151007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C007B7B7B00C2C2C200B4B4B400AEAE
      AE00AEAEAE00ECECEC00E9E9E900E8E8E800E6E6E600E4E4E400E2E2E2008A8A
      8A0087878700848484009191910064646400A4A4A400F0F0F000E5E5E500E5E5
      E500E1E1E100E1E1E100DCDCDC00DCDCDC00D8D8D800D8D8D800D3D3D300D3D3
      D300D0D0D000CECECE00DFDFDF008787870065656500AEAEAE009A9A9A009A9A
      9A0095959500F8F8F800F7F7F700F6F6F600F5F5F500F4F4F400F4F4F4007C7C
      7C007B7B7B007B7B7B008181810071717100363636006D6D6D006D6D6D006D6D
      6D00ADADAD00D2D2D200A3A3A300888888007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C007B7B7B00C7C7C700B8B8B800B4B4
      B400AEAEAE00EEEEEE00ECECEC00EBEBEB00E8E8E800E6E6E600E4E4E4008E8E
      8E008A8A8A0087878700939393006767670085858500DCDCDC00C1C1C100C1C1
      C100B8B8B800B8B8B800B8B8B800B0B0B000B0B0B000AAAAAA00AAAAAA00A3A3
      A300A3A3A3009E9E9E00C1C1C100626262006B6B6B00AEAEAE009F9F9F009A9A
      9A009A9A9A00F9F9F900F8F8F800F7F7F700F6F6F600F5F5F500F4F4F4007E7E
      7E007C7C7C007C7C7C008383830071717100363636006D6D6D006D6D6D00ADAD
      AD00ADADAD008989890088888800A3A3A300888888007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C0087878700C7C7C700BCBCBC00B8B8
      B800B4B4B400F1F1F100EEEEEE00ECECEC00EBEBEB00E8E8E800E6E6E6009292
      92008E8E8E008A8A8A0096969600676767006D6D6D00C5C5C5009C9C9C009999
      990095959500919191008E8E8E00898989008989890084848400818181007D7D
      7D007D7D7D0079797900A2A2A200626262006B6B6B00B4B4B400A1A1A1009F9F
      9F009A9A9A00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F600F5F5F5007F7F
      7F007E7E7E007C7C7C008484840074747400363636006D6D6D006D6D6D00D2D2
      D2007F7F7F00D7D7D700A6A6A60088888800A3A3A3007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C0087878700CACACA00BEBEBE00BCBC
      BC00B8B8B800F1F1F100EEEEEE00EDEDED00EDEDED00EBEBEB00E9E9E9009696
      9600929292008F8F8F009B9B9B006D6D6D006D6D6D00C5C5C500A1A1A1009C9C
      9C009999990095959500919191008E8E8E008989890089898900848484008181
      81007D7D7D007D7D7D00A2A2A2006262620072727200B4B4B400A5A5A500A1A1
      A1009E9E9E00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F6008181
      81007F7F7F007E7E7E008686860074747400363636006D6D6D006D6D6D00ADAD
      AD0088888800A6A6A600A3A3A3007F7F7F00A3A3A3007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C008E8E8E00CECECE00C2C2C200BEBE
      BE00BCBCBC00EEEEEE00EDEDED00EBEBEB00E9E9E900E8E8E800E6E6E6009999
      990096969600929292009B9B9B006D6D6D006D6D6D00C5C5C500A1A1A100A1A1
      A1009C9C9C009999990095959500919191008E8E8E0089898900898989008484
      8400818181007D7D7D00A2A2A2006262620072727200B4B4B400A8A8A800A5A5
      A500A1A1A100FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F7008282
      8200818181007F7F7F008686860074747400363636006D6D6D006D6D6D008B8B
      8B00ADADAD00ADADAD007F7F7F00CACACA007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C0091919100CECECE00C4C4C400C2C2
      C200BFBFBF00EEEEEE00EBEBEB00ECECEC00EBEBEB00E9E9E900E6E6E6009E9E
      9E009999990096969600A2A2A2006D6D6D0050505000BCBCBC00848484008484
      84007B7B7B007B7B7B006F6F6F006F6F6F006565650058585800585858005858
      580047474700474747008E8E8E003E3E3E0072727200B6B6B600A9A9A900A6A6
      A600A2A2A200FDFDFD00FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F8008484
      840082828200818181008989890074747400363636006D6D6D006D6D6D006D6D
      6D008B8B8B00A1A1A100A3A3A3007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C0094949400D1D1D100C7C7C700C4C4
      C400C2C2C200EDEDED00ECECEC00EBEBEB00E9E9E900E9E9E900E6E6E600A2A2
      A2009E9E9E0099999900A8A8A8006D6D6D0048484800BABABA00818181008181
      8100787878007878780068686800686868006868680058585800585858004A4A
      4A004A4A4A003E3E3E008E8E8E003E3E3E0075757500B8B8B800ABABAB00A9A9
      A900A6A6A600FDFDFD00FDFDFD00FCFCFC00FBFBFB00FAFAFA00F9F9F9008686
      860084848400838383008D8D8D0074747400363636006D6D6D006D6D6D006D6D
      6D006D6D6D00515151007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F003C3C3C0094949400D1D1D100D1D1D100D1D1
      D100CECECE00F8F8F800F7F7F700F7F7F700F7F7F700F4F4F400F4F4F400B1B1
      B100B1B1B100A8A8A800A8A8A8007373730048484800BABABA00BABABA00BABA
      BA00B5B5B500B5B5B500ADADAD00ADADAD00ADADAD00A4A4A400A4A4A4009C9C
      9C009C9C9C0094949400949494003E3E3E0072727200B8B8B800B8B8B800B6B6
      B600B6B6B600FEFEFE00FDFDFD00FDFDFD00FCFCFC00FCFCFC00FBFBFB009494
      940091919100919191008D8D8D00787878001919190036363600363636003636
      360036363600282828003C3C3C003C3C3C003C3C3C003C3C3C003C3C3C003C3C
      3C003C3C3C003C3C3C003C3C3C001A1A1A009494940094949400949494009494
      940091919100DEDEDE00DEDEDE00D4D4D400D4D4D400CFCFCF00CFCFCF007979
      7900797979007373730073737300737373004A4A4A0048484800484848004848
      4800484848003E3E3E003E3E3E003E3E3E003E3E3E003E3E3E003E3E3E003E3E
      3E003E3E3E003E3E3E003E3E3E003E3E3E007D7D7D0075757500757575007272
      720072727200E5E5E500E2E2E200E2E2E200DEDEDE00DEDEDE00DBDBDB007B7B
      7B007B7B7B007B7B7B00787878007878780000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      0000DDDDDD00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00DDDDDD0000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000EBECED00CCCC
      CC00818DA00066758C0066758C0066758C0066758C0066758C00919BAA00CCCC
      CC00EBECED0000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000DFE3E700A4ABB6006675
      8C0094A3BA00BCCDDA00B7C4D400B0BAD900BCCDDA00BEC9DB00A1ABBC006675
      8C00A4ABB600EBECED0000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF00000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000FF000000FF0000919BAA006D7C9400BEC9
      DB00B7C4D400BCCDDA00BCCDDA0095ACC300BCCDDA00C5CFDE00D3DAE500C5CF
      DE0066758C00B1B5BB0000FF000000FF00007C7C7C00A3A3A30068686800A8A8
      A8005A5A5A004B4B4B009494940068686800686868005A5A5A00434343004343
      4300757575005858580068686800434343001515150015151500151515001515
      1500151515001B1B1B001B1B1B001B1B1B001B1B1B0020202000251F25002020
      20002020200020202000202020002020200000FF00000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000FF0000DFE3E7006D7C9400B7C4D400D3DA
      E500C5CFDE00ECF1F4009FA2B2007B80A800B1B5BB00ECF1F400E4ECF600ECF1
      F400B7C4D40066758C0000FF000000FF00007C7C7C00E6E6E600F6F6F600C5C5
      C500F9F9F900CFCFCF00F6F6F600AAAAAA00AAAAAA00E4E4E400B4B4B400E8E8
      E800AAAAAA00E0E0E000AFAFAF00434343000D0D0D00575757005D5D5D006262
      620065656500696969006D6D6D0073737300737373007A7A7A007A7A7A008181
      81008181810081818100818181002020200000FF00000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000FF0000AEB5BF008392A900A6B3C7008099
      B6008AABCA0094A0BB00A8AFD600C1C8E100AEB4D00095ACC3008AABCA008A9B
      B300C5CFDE006D7C9400EBECED0000FF00007C7C7C00E6E6E600CFCFCF00F0F0
      F000A1A1A100F2F2F200F1F1F1008686860088888800D3D3D300DEDEDE008888
      8800D1D1D1007C7C7C00AFAFAF00434343000D0D0D00575757003C3C3C004242
      420042424200474747005050500050505000575757005D5D5D005D5D5D006262
      62006565650069696900818181002020200000FF00000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000FF0000A4ABB6008392A9007990AC002B37
      4D000602050058759700DFE3E700FFFFFF009BABBC002B374D00060205005875
      97009DAAC10077869E00C2C7CD0000FF00007C7C7C00E6E6E600CFCFCF00CFCF
      CF00F3F3F300A1A1A100FAFAFA008888880088888800EBEBEB008B8B8B00E2E2
      E2007C7C7C007C7C7C00B4B4B400434343001B1B1B0084848400737373007373
      73007A7A7A007A7A7A00818181008484840089898900898989008F8F8F008F8F
      8F009595950095959500A8A8A8004747470000FF0000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF00000000FF0000919BAA0094A3BA007990AC00F8FD
      FF004D47450049628500DFE3E700FFFFFF008A9BB300E4ECF600736D6A00546C
      8F009DAAC1008392A900A4ABB60000FF000083838300EEEEEE00DFDFDF00DFDF
      DF00DFDFDF00E8E8E8008B8B8B00888888008686860088888800D8D8D800D1D1
      D100CBCBCB00C4C4C400E2E2E20068686800D1D1D100F5F5F500F4F4F400F5F5
      F500F6F6F600F8F8F800F8F8F800FAFAFA00FAFAFA00FBFBFB00FCFCFC00FCFC
      FC00FEFEFE00FEFEFE00FEFEFE00EDEDED0000FF0000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF00000000FF0000919BAA0094A0BB0094A3BA008099
      B600516786009BABBC00FFFFFF00EBECED00EBECED008099B600516786007990
      AC00B7C4D40094A3BA00A4ABB60000FF000073737300D8D8D800B8B8B800B8B8
      B800A5A5A50098989800909090008B8B8B008888880088888800868686008686
      86008484840084848400AAAAAA0068686800D1D1D100F5F5F500F3F3F300F4F4
      F400F5F5F500F6F6F600F8F8F800F8F8F800FAFAFA00FAFAFA00FBFBFB00FCFC
      FC00FCFCFC00FEFEFE00FEFEFE00EDEDED0000FF0000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF00000000FF0000818DA00094A3BA009DAAC100B7C4
      D400C5CFDE00E4ECF600FFFFFF00C3C8D200FFFFFF00E4ECF600D2D8EA00BEC9
      DB00A6B3C7008A9BB300818DA00000FF000092929200F0F0F000E2E2E200E2E2
      E200E2E2E200E2E2E200A5A5A50090909000909090009D9D9D00E0E0E000D8D8
      D800D1D1D100CBCBCB00E0E0E00068686800CECECE00F4F4F400F3F3F300F3F3
      F300F4F4F400F5F5F500F6F6F600F8F8F800F8F8F800FAFAFA00FAFAFA00FBFB
      FB00FCFCFC00FCFCFC00FEFEFE00EDEDED0000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000066758C00A4B0D1009DAAC100A6B3
      C700B7C4D400C5CFDE00FFFFFF00C3C8D200ECF1F400C5CFDE00BEC9DB00B7C4
      D400A6B3C700A4B0D10066758C0000FF000081818100EAEAEA00D3D3D300D3D3
      D300F6F6F600C4C4C400F4F4F400A5A5A500C0C0C000F2F2F2009D9D9D00F3F3
      F300AEAEAE00A0A0A000C9C9C9004B4B4B0071717100A0A0A000959595009595
      950099999900999999009D9D9D009D9D9D00A0A0A000A3A3A300A7A7A700A7A7
      A700ACACAC00ACACAC00BABABA008484840000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000066758C00A2A9D300A4B0D1009DAA
      C100A6B3C700B7C4D400F8FDFF00C2C7CD00D3DAE500BEC9DB00B7C4D400A6B3
      C700A4B0D100A8AFD60066758C0000FF000081818100EAEAEA00D3D3D300F3F3
      F300C4C4C400F4F4F400EDEDED00B8B8B800C5C5C500EAEAEA00F2F2F2009D9D
      9D00EEEEEE00AEAEAE00C9C9C9004B4B4B0071717100818181007B7B7B007B7B
      7B007D7D7D007D7D7D0080808000808080008484840084848400868686008686
      8600898989008A8A8A00999999007E7E7E0000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000066758C00A8AFD600A8AFD600A4B0
      D1009DAAC100A6B3C700D3DAE500D3DAE500BEC9DB00B7C4D400A6B3C700A6B3
      C700B0BAD900A8AFD60066758C0000FF000081818100EAEAEA00F9F9F900E0E0
      E000FBFBFB00E6E6E600F6F6F600D8D8D800E0E0E000F6F6F600E4E4E400F9F9
      F900C5C5C500F6F6F600D3D3D300525252007070700081818100818181008383
      83008383830086868600868686008A8A8A008A8A8A008C8C8C00909090009090
      90009494940094949400999999007E7E7E0000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000066758C00B0BAD900C1C8E100D2D8
      EA008392A9008392A9009DAAC100B7C4D40094A3BA008392A9008A9BB300D2D8
      EA00C1C8E100B0BAD90066758C0000FF000081818100A8A8A80075757500A8A8
      A8007C7C7C007C7C7C00A2A2A2007373730075757500A2A2A200787878007878
      7800A8A8A80068686800A3A3A3005A5A5A007070700070707000707070007171
      7100717171007474740074747400747474007878780078787800787878007878
      7800787878007B7B7B007B7B7B007B7B7B0000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000066758C00A6B3C700BEC9DB007786
      9E00C3C8D200B2B9C500B2B9C500B2B9C500B2B9C500C3C8D200C3C8D2007786
      9E00C5CFDE00BAC3D80066758C0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000A1ABBC0066758C00818DA000EBEC
      ED0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000DFE3
      E70066758C0066758C00919BAA0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00003F0000007F0000007F0000007F00
      0000007F7F00007F7F007F0000007F0000007F0000007F0000007F0000007F00
      00007F0000007F0000007F0000003F0000007F0000007F00000000007F000000
      7F0000007F0000007F0000007F0000007F0000007F0000007F0000007F000000
      7F0000007F0000007F0000007F0000007F000038000000380000003800000025
      00000025000000250000000D0000000D0000000D000000000000000000000000
      00000000000000000000000000000000000000FF00000000CC000000CC000000
      CC000000CC000000CC000000CC000000CC000000CC000000CC000000CC000000
      CC000000CC000000CC000000CC0000FF00007F000000FF000000FF000000FF00
      000000FFFF0000FFFF00FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000007F0000007F000000C0000000C00000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F000048000062AD610062AD610054A5
      540054A5540054A554004B9F4B00459E4500409A40003D983D003A963A003494
      3400329033002E8E2E002E8E2E000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00007F000000FF000000FF000000FF00
      000000FFFF0000FFFF00FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000007F0000007F000000C0000000C0000000C000
      00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F000048000062AD6100459E4500409A
      40003A963A00349434002F912F002A8E2A00248B24001F871F00198419001481
      14000E7D0E000E7D0E002E8E2E000000000000FF00000000CC000000CC000000
      CC000000CC000000CC000000CC000000CC000000CC000000CC000000CC000000
      CC000000CC000000CC000000CC0000FF00007F000000FF000000FF000000FF00
      000000FFFF0000FFFF00FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000007F0000007F000000C0000000C0000000C000
      0000C00000000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F00004800006AB36A0049A14900459E
      4500409A40003A963A00349434002F912F002A8E2A00248B24001F871F001984
      1900148114000E7D0E00329033000000000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000007F7F0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF00007F7F007F000000C0000000C0000000C000
      0000C0000000C00000000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F00FDFDFD00FDFDFD00FCFCFC00FBFC
      FB00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F600F5F5F500F4F4
      F400F3F3F300F3F3F300F4F4F400E5E5E50000FF0000DCABAB0094000000DCAB
      AB0094000000DCABAB0094000000DCABAB0094000000DCABAB000000CC000000
      CC000000CC000000CC000000CC0000FF0000007F7F0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF00007F7F007F000000C0000000C0000000C000
      0000C0000000C0000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F00FDFDFD00FEFEFE00FDFDFD00FCFC
      FC00FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F600F5F5
      F500F4F4F400F3F3F300F5F5F400E5E5E50000FF000094000000DCABAB009400
      0000DCABAB0094000000DCABAB0094000000DCABAB009400000000FF000000FF
      000000FF000000FF000000FF000000FF00007F000000FF000000FF000000FF00
      000000FFFF0000FFFF00FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000007F0000007F000000C0000000C0000000C000
      0000C0000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F00FDFDFD00FEFEFE00FEFEFE00FDFD
      FD00FCFCFC00FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6
      F600F5F5F500F4F4F400F5F5F500E5E5E50000FF0000DCABAB0094000000DCAB
      AB0094000000DCABAB0094000000DCABAB0094000000DCABAB000000CC000000
      CC000000CC000000CC000000CC0000FF00007F000000FF000000FF000000FF00
      000000FFFF0000FFFF00FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000007F0000007F000000C0000000C0000000C000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F000000CD007979E9005D5DE4005959
      E4005555E2005151E1004C4CE1004747DF004242DE003D3CDC003737DA003131
      D9002A2AD6002A2AD6004444DB000000AA0000FF000094000000DCABAB009400
      0000DCABAB0094000000DCABAB0094000000DCABAB009400000000FF000000FF
      000000FF000000FF000000FF000000FF00007F000000FF000000FF000000FF00
      000000FFFF0000FFFF00FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF0000007F0000007F000000C0000000C0000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F000000CD007B7BEA005D5DE4005D5D
      E4005959E4005555E2005151E1004C4CE1004747DF004242DE003D3CDC003737
      DA003131D9002A2AD6004747DF000000AA0000FF0000DCABAB0094000000DCAB
      AB0094000000DCABAB0094000000DCABAB0094000000DCABAB000000CC000000
      CC000000CC000000CC000000CC0000FF00003F0000007F0000007F0000007F00
      0000007F7F00007F7F007F0000007F0000007F0000007F0000007F0000007F00
      00007F0000007F0000007F0000003F0000007F0000007F0000007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F000000CD007B7BEA007B7BEA007979
      E9007979E9007474E8007474E8006B6BE6006B6BE6006363E4006363E4005C5C
      E2005555E2005353DF004C4CDD000000AA0000FF000094000000DCABAB009400
      0000DCABAB0094000000DCABAB0094000000DCABAB009400000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00000000CD000000CD000000CD000000
      CD000000CD000000C6000000C6000000C6000000C6000000C6000000BC000000
      BC000000BC000000B5000000B5000000AA0000FF0000DCABAB0094000000DCAB
      AB0094000000DCABAB0094000000DCABAB0094000000DCABAB000000CC000000
      CC000000CC000000CC000000CC0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00002F8AB3002F8AB3002F8AB3002F8A
      B3002F7DA8002F7DA8002F86A8002F86A8002F86A8002F849B002F7DA8002F77
      9D002F7DA8002F779D002F779D002F779D000076000000650000006500000057
      000000570000CDCDCD00C8C8C800C8C8C800C2C2C200C2C2C200C2C2C2000000
      E0000000E0000000DD000000DD000000DD000020000000400000004000000040
      00000040000000203F0000007F0000007F0000007F0000007F0000007F000000
      7F0000007F0000007F0000007F0000003F000000F3000000F3000000F3000000
      EC000000EC000000EC000000EC000000EC000000E5000000E5000000E5000000
      E0000000E0000000DD000000DD000000DD002FA4B60097EBF90097EBF90097EB
      F90097EBF90087E5F60087E5F60087E5F6007AE0F3007AE0F3007AE0F3006EDC
      F0006EDCF0006EDCF0006EDCF0002F779D00006F000061BF60005CBD5C0059BA
      580055B65400F8F8F800F7F7F700F7F7F700F6F6F600F5F5F500F4F4F4003535
      F3003232F3002E2EF2002E2EF2000000DD000040000000800000008000000080
      00000080000000407F000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F000000F9006363FC005C5CFC005C5C
      FC005353FA005353FA004B4BF7004444F7004444F7003B3BF5003B3BF5003333
      F4003333F4002D2DF4002D2DF4000000DD002FA4B600A2F1FB0065E5F80065E5
      F80057E1F50057E1F50048DCF20048DCF2003AD8EE003AD8EE002CD3EA002CD3
      EA0022CFE8001DCDE6006DE0EF002F849B000076000068C2680042AF430042AF
      43003AAA3A00F8F8F800F7F7F700F6F6F600F5F5F500F4F4F400F4F4F4001313
      F2000D0DF1000D0DF1002E2EF2000000E0000040000000800000008000000080
      000000BF7F003FDFBF00007FFF00003FFF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F000000F9006363FC004444FA003D3C
      F9003D3CF9003636F8002D2DF4002D2DF4002121F5002121F5001616F3001616
      F3000D0DF1000D0DF1002D2DF4000000E0002F7DA800A4D5FC0069B2F60069B2
      F60056A6F50056A6F50056A6F500449BF200449BF2003692EF003692EF002789
      EB002789EB001D82E80069B2F6002F3FA500007D000068C2680049B4490042AF
      430042AF4300F9F9F900F8F8F800F7F7F700F6F6F600F5F5F500F4F4F4001919
      F3001313F2001313F2003232F3000000E00000400000008000000080000000BF
      7F0000BF7F003F3FFF00003FFF00007FFF00003FFF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F0000FDFD006DFDFD004CFCFC00A8CE
      C0004BC9EB004AA7E4009DBBB60041F2F0002BF6F60025F5F5001FF4F40019F3
      F30013F2F20013F2F20030F6F60000DFDF003141BD00A9B2FC006C6CFB006666
      FA006060F9005959F7005252F6004747F3004747F3003C3CF1003333EF002929
      ED002929ED001E1EEA007080F2002F3FA500007D000074C674004FB64F0049B4
      490042AF4300FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F600F5F5F5001F1F
      F4001919F3001313F2003636F4000000E60000400000008000000080000000DF
      BF000000FF00BFDFBF007F7FFF00003FFF00007FFF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F0000FDFD006DFDFD004CFCFC00D6F1
      F900518CE0005153EC00E2EAF5004EDFEE0030F6F6002BF6F60025F5F5001FF4
      F40019F3F30013F2F2003BF5F40000E6E6003141BD00A9B2FC007575FC006C6C
      FB006666FA006060F9005959F7005252F6004747F3004747F3003C3CF1003333
      EF002929ED002929ED007080F2002F3FA5000085000074C6740054B954004FB6
      4F004BB34B00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F700F6F6F6002525
      F5001F1FF4001919F3003D3DF5000000E60000400000008000000080000000BF
      7F00003FFF007F7FFF003F7FFF000000FF00007FFF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F0000FDFD0076FEFE0053FDFD00B1C3
      F5005568EC00D4D3EC00B0BDF20042E1EC0036F8F80030F6F6002BF6F60025F5
      F5001FF4F40019F3F3003BF5F40000E6E6003141BD00A9B2FC007575FC007575
      FC006C6CFB006666FA006060F9005959F7005252F6004747F3004747F3003C3C
      F1003333EF002929ED007080F2002F3FA5000085000074C6740058BC580054B9
      54004FB64F00FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F800F7F7F7002B2B
      F6002525F5001F1FF4003D3DF5000000E600004000000080000000800000009F
      3F0000BF7F0000BF7F000000FF0000BFFF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F0000FDFD0076FEFE005AFEFE0055F3
      F200577EF1005568EC008DE0ED0041F2F0003CF9F90036F8F80030F6F6002BF6
      F60025F5F5001FF4F4003BF5F40000E6E6003C496600AFB8CA007C7C9D007C7C
      9D00727295007272950065658C0065658C005B5B83004B4C78004B4C78004B4C
      780039396900393969007D8B99002F3F3F000085000079C879005CBD5C0059BA
      580055B65400FDFDFD00FCFCFC00FBFBFB00FAFAFA00F9F9F900F8F8F8003131
      F7002B2BF6002525F5004444F6000000E6000040000000800000008000000080
      0000009F3F00009FBF00007FFF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F0000FDFD0076FEFE005AFEFE005AFE
      FE0057EEF4004EDFEE004BF4F80045FBFB0045FBFB003CF9F90036F8F80030F6
      F6002BF6F60025F5F5004BF4F80000E6E6003A484A00B1BABA00818180008181
      800078787800787878006968690069686900696869005858580058585800474A
      4A00474A4A003A3F3F007D8B99002F3F3F00008900007BCA7B0061BF60005CBD
      5C0059BA5800FDFDFD00FDFDFD00FCFCFC00FBFBFB00FAFAFA00F9F9F9003737
      F8003131F7002C2CF6004C4CF7000000E6000040000000800000008000000080
      00000080000000407F000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF000000FF000000FF0000007F000000FF007A7AFF005C5CFC005C5C
      FC005C5CFC005353FA005353FA004C4CFC004444FA004444FA003D3CF9003636
      F8003333F4002D2DF4004B4BF7000000EC003A484A00B1BABA00B1BABA00B1BA
      BA00ABB5B500ABB5B500A3ADAD00A3ADAD00A3ADAD0099A4A40099A4A400909C
      9C00909C9C0087949400879494002F3F3F00008500007BCA7B007BCA7B0079C8
      790079C87900FEFEFE00FDFDFD00FDFDFD00FCFCFC00FCFCFC00FBFBFB005C5C
      FA005555F9005555F9004C4CF7000000EC000020000000400000004000000040
      00000040000000203F0000007F0000007F0000007F0000007F0000007F000000
      7F0000007F0000007F0000007F0000003F000000FF007A7AFF007A7AFF007A7A
      FF007A7AFF007372FE007372FE006B6BFD006B6BFD006363FC006363FC005C5C
      FC005353FA005353FA004B4BF7000000EC00474A4A003A484A003A484A003A48
      4A003A484A003A3F3F002F3F3F002F3F3F002F3F3F002F3F3F002F3F3F002F3F
      3F002F3F3F002F3F3F002F3F3F002F3F3F000091000000890000008900000085
      000000850000E5E5E500E2E2E200E2E2E200DEDEDE00DEDEDE00DBDBDB000000
      F3000000F3000000F3000000EC000000EC0000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00000000FF000000FF000000FF000000
      FF000000FD000000FD000000FD000000FD000000F9000000F9000000F9000000
      F3000000F3000000F3000000EC000000EC0000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000FF01FF0000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000FF01FF0000FF000000FF
      000000FF000000FF000000FF0000FF0CFF0000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000A2CAEE0076B2E6003E91
      DB00348CD900348CD900348CD900348CD900348CD900348CD900348CD900348C
      D900348BD900398FDA0085B9E90000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF00004799DD00DEF1FA00A8DD
      F4009EDBF40096DAF3008ED8F30086D7F3007FD4F20079D3F20072D2F1006CD0
      F10069CFF100C2EAF8003F95DB0000FF0000AE7A7000949ABF002F3FB400A3A2
      BA00A7574100A3403F00B8977A002F3FB4002F3FB400A7574100733F3F00733F
      3F004E57B6002F3F8F002F3FB400733F3F006400000064000000640000006400
      0000640000007800000078000000780000007800000087000000870000008700
      000087000000870000008700000087000000BB6C4400B0572C00B0572C00B057
      2C00A5471700BBBBBB00BBBBBB00B0B0B300AAAAAA00AAAAAA009F9F9F000000
      CC000000CC000000C6000000C6000000C60000FF00003B97DB00EFFAFE00A1E9
      F90091E5F80081E1F70072DEF60063DAF50054D7F40047D3F30039D0F2002ECD
      F10026CBF000CAF2FB003B97DB0000FF0000AE7A7000FEE6E000F1F3FE00A7B1
      FE00F6F6FE00FFCEC200FEF5F3007686FD007686FD00FEE3DE00EEB2A700E3E1
      FE007686FD00CFD6FE00E4ADA300733F3F0048000000B14C4C00B6535300B958
      5900BB5C5C00BD606000C0656500C16C6C00C16C6C00C5737300C5737300C97A
      7A00C97A7A00C97A7A00C97A7A0087000000BB6C4400E3BFAF00E1BDAA00DEB9
      A600DDB5A100EDEDED00ECECEC00EAE9E900E8E8E800E6E6E600E6E6E600626E
      EC005D6AEA005A66E9005664ED000000C60000FF00003C9DDB00F2FAFD00B3ED
      FA00A4E9F90095E6F80085E2F70076DEF60065DBF50057D7F40049D4F3003BD1
      F20030CEF100CCF2FB003B9BDB0000FF0000AE7A7000FEE6E000FFCEC200EAEB
      FF007072FF00F1EDFF00FFF0ED002629FF002F32FF00FFD2C700DBD2FF002F32
      FF00BCC0FF00E3766200E4ADA300733F3F0048000000B14C4C00A12C2C00A634
      3400A6343400AD393900AF454500AF454500B14C4C00B6535300B6535300B958
      5900BB5C5C00BD606000C97A7A0087000000C57B5700E5C3B200DDB5A100D9AF
      9A00D9AF9A00ECECEC00EAE9E900E8E8E800E6E6E600E4E4E400E2E2E2004957
      EA004352E8003E4DE6005A66E9000000C60000FF00003BA3DB00F6FCFE00C8F2
      FC00B9EFFB00ACECFA009CE8F9008BE3F7007CE0F6006CDCF6005DD9F5004FD6
      F40044D3F300D0F3FC003BA2DB0000FF0000AE7A7000FEE6E000FFCEC200FFCE
      C200EEEFFF007072FF00F9F7FF002F32FF002F32FF00ECE4FF003D3DFF00D5D8
      FF00E3766200E3766200EEB2A700733F3F0078000000C87E7E00C16C6C00C16C
      6C00C5737300C5737300C97A7A00C87E7E00CB838300CB838300CF8A8A00CF8A
      8A00D2908F00D2908F00DAA4A400AD393900C57B5700E7C8B700DEB9A600DDB5
      A100D9AF9A00EEEEEE00ECECEC00EBEBEB00E8E8E800E6E6E600E4E4E4004F5D
      EB004957EA004352E8005D6AEA000000CC0000FF00003BA8DB00FEFFFF00F8FD
      FF00F6FDFF00F5FCFF00F3FCFE00D8F6FC0094E6F80085E3F70076DFF60068DB
      F5005CD8F400D7F4FC003BA7DB0000FF00005F6BBF00E8E9FF00D3D3FF00D3D3
      FF00D3D3FF00E3E1FE003D3DFF002F32FF002629FF002F32FF00C4CBFF00BCC0
      FF00B5B8FF00ADADFF00D5D8FF002F3FB400CBCBE600F5F5F500F4F4F400F5F5
      F500F6F6F600F8F8F800F8F8F800FAFAFA00FAFAFA00FBFBFB00FCFCFC00FCFC
      FC00FEFEFE00FEFEFE00FEFEFE00E8E8FD00CC876600E7C8B700E1BDAA00DEB9
      A600DDB5A100F1F1F100EEEEEE00ECECEC00EBEBEB00E8E8E800E6E6E6005664
      ED004F5DEB004957EA00626EEC000000CC0000FF000039ADDB00E8F6FB0094D4
      EF0088CEEE0073C1E900C9E9F600F2FCFE00F3FCFE00F2FCFE00F0FCFE00EFFB
      FE00EEFBFE00FEFFFF003CAEDB0000FF00003C4CBE00C4CBFF00989CFF00989C
      FF00767AFF005F61FF00484BFF003D3DFF002F32FF002F32FF002629FF002629
      FF00181CFF00181CFF007686FD002F3FB400CBCBE600F5F5F400F3F3F300F4F4
      F400F5F5F500F6F6F600F8F8F800F8F8F800FAFAFA00FAFAFA00FBFBFB00FCFC
      FC00FCFCFC00FEFEFE00FEFEFE00E8E8FD00CC876600E9CBBC00E4BFAE00E1BD
      AA00E0B9A600F1F1F100EEEEEE00EDEDED00EDEDED00EBEBEB00EAE9E9005C6A
      F0005664ED00505EEC006A76EE000000D80000FF000040AEDC00F1FAFD0094DE
      F50093DCF40081D5F2006ACAED006CCBEA0085D3EF0080D2EF007AD0EF0076CF
      EE0072CFEE00E9F7FB003EB2DC0000FF00007A82BF00EAEBFF00D5D8FF00D5D8
      FF00D5D8FF00D5D8FF00767AFF00484BFF00484BFF00666BFF00CFD6FE00C4CB
      FF00BCC0FF00B5B8FF00CFD6FE002F3FB400C7C7E300F4F4F400F3F3F300F3F3
      F300F4F4F400F5F5F500F6F6F600F8F8F800F8F8F800FAFAFA00FAFAFA00FBFB
      FB00FCFCFC00FCFCFC00FEFEFE00E8E8FD00D18F6F00EBCFC100E5C3B200E4BF
      AE00E1BDAA00EEEEEE00EDEDED00EBEBEC00EAE9E900E8E8E800E6E6E6006470
      F1005C6AF0005664ED006A76EE000000D80000FF000041B4DC00F7FCFE008EE4
      F80091DEF5009FE0F500ACE1F600EFFBFE00F4FDFE00F3FCFE00F1FCFE00EFFB
      FE00EEFBFE00FAFDFF0058BCE00000FF0000B37F7500FEEAE400FFD2C700FFD2
      C700F1F3FE00ADADFF00F4F0FF00767AFF0094A9FF00F1EDFF00666BFF00EEEF
      FF00FCAC9400FC9D8400FEC7BB00A3403F000000E0007878F5006565F2006565
      F2006C6CF4006C6CF4007373F6007373F6007878F5007C7CF8008282FA008282
      FA008A8AFB008A8AFB00A0A0FC002929F900D2927200EBCFC100E7C5B400E5C3
      B200E4C0AE00EEEEEE00EBEBEB00ECECEC00EBEBEB00EAE9E900E6E6E6006B77
      F3006470F1005C6AF000727EF3000000D80000FF00003CB5DB00FDFEFE00FEFF
      FF00FEFEFF00FDFEFF00FEFFFF00EAF7FB006EC8E5006FC9E4006FC9E4006FC9
      E4007DCFE70084D0E800BAE5F20000FF0000B37F7500FEEAE400FFD2C700EEEF
      FF00ADADFF00F4F0FF00FFEDE800989CFF00A7B1FE00FEEAE400F1EDFF00666B
      FF00E8E9FF00FCAC9400FEC7BB00A3403F000000E0002E2EF2000D0DF1000D0D
      F1001616F3001616F3002121F5002121F5002929F9002E2EF7003434F8003B3B
      F5003D3DFA004444F8006464FC000000F800D3957300EDD2C400E7C8B700E7C5
      B400E5C3B200EDEDED00ECECEC00EBEBEB00EAE9E900EAE9E900E6E6E600727E
      F3006B77F3006470F1007E88F4000000D80000FF000059C2E00061C3E20063C4
      E30063C4E30063C4E30062C4E30056C0E000EDF8FC00F3FAFD00F3FAFD00F3FA
      FD00F3FAFD00F3FBFD00FCFEFE0000FF0000B37F7500FEEAE400F6F6FE00CFD6
      FE00FBF9FE00FEE6E000FEF5F300C4CBFF00CFD6FE00FEF5F300FEE3DE00F6F6
      FE00A7B1FE00F1F3FE00FFD2C700A54B3F000000DD002E2EF2002E2EF2003434
      F3003434F3003B3BF5003B3BF5004444F8004444F8004B4BF7005352F9005352
      F9005B5BFA005B5BFA006464FC000000F800D3957300EDD2C400EDD2C400EDD2
      C400EBCFC100F8F8F800F7F7F700F7F7F700F7F7F700F4F4F400F4F4F4008C95
      F8008C95F8007E88F4007E88F4000000E40000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000B37F75009DA1BF004E57B600A3A2
      BA00AE7A7000AE7A7000BAA19C003C4CBE004E57B600BAA19C00AA766D00AA76
      6D00A3A2BA002F3FB400949ABF00A75741000000DD000000DD000000DD000000
      E0000000E0000000E5000000E5000000E5000000EC000000EC000000EC000000
      EC000000EC000000F3000000F3000000F300D3957300D3957300D3957300D395
      7300D2927200DEDEDE00DEDEDE00D4D4D400D4D4D400CFCFCF00CFCFCF000009
      EE000009EE000000E4000000E4000000E40000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000CE9C3100CE9C3100CE9C
      630000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000E2C0AA00CC8D
      6600C0714000BC6B3600BC6B3600BC6B3600BC6A3600BC6A3600BB6A3500BB6A
      3500BB693500BD6E3B00CA8B6300E3C2AE00CE9C6300CE9C310000FF000000FF
      0000CE9C63009C633100636331006363310063633100636331006363310000FF
      000000FF000000FF000000FF000000FF00007AB98000579E5E00619C66004678
      4A0059755B007C7C7C0087878700898989008B8B8B008C8C8C00696969005C7D
      5F0048864E00609964003A7B3E00598A5B0000FF000000FF000000FF000000FF
      000000FF0000D6BAA200B6845A00AC744500AB724300B27E5300D2B59C0000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000C57C4D00F8F2
      EB00F7ECDF00F6EBDE00F6EADE00F6EADC00F6EADC00FAF3EB00FAF3EB00FAF2
      EA00FCF7F300FCF8F400FEFEFD00C37A4D00FF9C31009C63310000FF000000FF
      000063633100CE633100CE9C3100FF9C3100FFCE6300CE9C6300FF9C31006363
      31006363310000FF000000FF000000FF00006AB9730066B4700072BF7D0062B4
      6D005E916200E5E5E50082828200A9A9A900ACACAC0089898900E2E2E20076BC
      7E0084CA8F0074C1800055A45E003376380000FF000000FF000000FF0000E7D5
      C600BA895F00D7BBA300E9DACA00ECE0D100ECE0D100E8D8C800D3B59C00B07A
      4D00E2CFBE0000FF000000FF000000FF000000FF000000FF0000C2774000F5EB
      DF00FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FCE4D100FDFBF800BC6B3700FF9C63009C63310000FF00006363
      3100FF9C3100FF9C3100FF9C3100FF9C3100FF9C3100FFCE6300FFCE6300FFCE
      9C009C6331006363310000FF000000FF000000FF000000FF00007CBA8200528E
      5800A2C1A400F0F0F0007E7E7E00A4A4A400A6A6A60085858500F0F0F000A1D6
      A80059AF62006AAE720000FF000000FF000000FF000000FF0000EAD9CB00BE8C
      6200E7D5C400E5D2BF00C9A68500B88E6700B68A6500C5A18000E0CCBA00E3D0
      BE00AF764800E3D0C00000FF000000FF000000FF000000FF0000C37C4200F7ED
      E300FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FCE4D100FBF7F400BD6C3700CE9C6300CE9C310063633100FF9C
      3100FF9C3100FF9C3100FF9C31006363310063633100CE633100FF9C3100FFCE
      6300FFCE9C009C63310000FF000000FF000000FF000000FF000000FF00008B8B
      8B00F0F0F000EFEFEF007B7B7B009E9E9E00A1A1A10081818100EFEFEF00F4F4
      F4007171710000FF000000FF000000FF000000FF000000FF0000C99D7900EAD8
      C900E3CDBA00C0946B00BA8C6200CFB09400CFB09400B7895F00B2876100DAC0
      AA00E4D1C000B683590000FF000000FF000000FF000000FF0000C77E4400E092
      6000E08C4C00FCE4D100E2964F00E2894100FCE4D100FCE4D100FCE4D100FCE4
      D100FCE4D100FCE4D100FCF9F500C1743C0000FF0000FFCE3100FF9C3100FF9C
      3100CE9C3100CE9C31009C63310000FF000000FF000000FF0000CE633100FF9C
      3100FFCE6300CECE63009C63310000FF000000FF000000FF000000FF00009090
      9000F1F1F100EFEFEF0077777700999999009C9C9C007C7C7C00EFEFEF00F4F4
      F4007676760000FF000000FF000000FF000000FF0000E6CFBC00E4CCB900EAD6
      C500C7997100BF906600BF906600F7F1EC00F6F0EA00B7895F00B7895F00B589
      6300E2CEBB00D9BDA600D9BEA70000FF000000FF000000FF0000D7814000E5A3
      6500E1915800FDE5D300E59D5C00E7A86800E3975F00F9DAC400FCE2CE00FCE2
      CC00FBE0C900FBE1C800FDFAF700C37A410000FF0000CECE6300FFCE3100FF9C
      3100CE9C31009C63310063633100636331006363310063633100636331006363
      310063633100636331006363310000FF000000FF000000FF0000679CC3008D8F
      9100F6F6F600EFEFEF0074747400767676007777770078787800EFEFEF00F4F4
      F4008A8B8D004E618E0000FF000000FF000000FF0000D9B39500EFE1D300D9B5
      9500C7986C00C3956900C1936700BF906600BF906600BB8B6300B98A6300B88A
      6200CBA78600EADCCC00C2956F0000FF0000F2CFB400E6A25A00E8AA6A00E39B
      5D00F9D8C300FDE7D600F9DBC300E5A05D00E8AA6A00E39B5600EEB69400FCE2
      CD00FBE1CB00FBE1C900FBF7F200C780450000FF000000FF0000FFCE3100FF9C
      3100CE9C3100CE633100CE633100CE633100CE633100CE633100CE633100CE63
      3100CE633100CE6331009C63310000FF000000FF00003B85BB005796C2003F80
      B300DCDEE000EDEDED00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00DFE1
      E3002D4B81003A5F900027407A0000FF000000FF0000DAB39300F2E4D900D1A5
      7A00C5996B00C4976A00C4966900FAF6F200F3EAE100C2956D00BE8F6500BE8F
      6400C0956D00EFE3D500C190670000FF0000E8AC6000ECB87900E5A45800F2D8
      C400FEE8D600FEE8D700FDE7D600F6D1B300E6A65A00E9B27500E49D5800FAE0
      C800FADFC700FADFC600FAF2EA00C884480000FF000000FF000000FF0000FFCE
      3100FF9C3100CE9C3100CE9C3100CE9C3100CE9C3100CE9C3100FF9C3100FF9C
      3100FF9C3100FF9C31009C63310000FF0000629BCA005395C6007AAFD3005797
      C4004387BA00CDCFD000EEEEEE00EFEFEF00EFEFEF00EFEFEF00D9DADB003864
      970044709F005C8CB1003C649400566B970000FF0000E1BB9D00F2E5DA00D1A6
      7E00CC9D7100C79A6C00C5986B00E2CCB600F8F3EE00F6EEE800D9BDA100C294
      6800C59B7100F0E2D600C799710000FF0000F4D5B700EAAE6000EAB57100E8A6
      6300FADBC500FEE8D800FBDDC500E9AB6100EAB57100E8A75C00EFBA9300FAE0
      C700F9DDC300F8DCC200FAF4ED00C8864B0000FF0000FFCE9C0000FF0000FFCE
      3100FFCE3100CE9C31006331310000FF000000FF0000CE633100CE9C3100FF9C
      3100FF9C3100FF9C31009C63310000FF000000FF00003F85BE005293C60079AE
      D3005597C4004287BA00CACBCC00EDEDED00EFEFEF00D9DBDC003D76A6004D80
      AE006B9ABD004775A200395D910000FF000000FF0000EACAB000F3E5D900DFBB
      9E00CFA07500CD9E7200F5EBE300E4CBB400E7D3BF00FBF8F600E5D3BF00C498
      6B00D6B49100EEE0D200D3AC8B0000FF000000FF000000FF0000DE984900EBB6
      7200E8A76100FDE7D600ECB26500ECBB7600EAAC6700F9DAC100FADFC700F8DC
      C200F6DABD00F6D8BB00FAF4EF00C8874C0000FF000000FF0000FFCE9C0000FF
      0000FFCE3100CE9C3100636331006331310063633100CE633100FF9C3100FF9C
      3100FF9C31009C63310000FF000000FF000000FF000000FF00003E81BE005091
      C60076ADD3005495C6004189BC00D2D4D500D2D4D5004183B400558DBB0077A5
      C7005084B2003E70A30000FF000000FF000000FF0000F5E4D600F4E3D400EFDC
      CD00D5A87E00D0A07700FBF8F500FCF8F500FCF8F500FBF8F500D1A88100CFA4
      7B00EAD5C300EAD4C200E9D4C20000FF000000FF000000FF0000CA8D4F00E9B1
      6E00E8AE5F00FCE6D400ECB66500ECB26900F9DEC400FAE0C800F8DCC200F5D6
      BB00F3D4B500F1D2B300F8F4F000C6864C0000FF000000FF0000CECE9C00CECE
      9C0000FF0000FFCE9C00CE9C3100CE9C3100CE9C3100CE9C3100CE9C3100FF9C
      3100FF9C31009C63310000FF000000FF000000FF000000FF000000FF00003C80
      BC004D90C40073ABD3005294C6003B83BA003C85B9005695C2007DACCF005591
      BC004380B10000FF000000FF000000FF000000FF000000FF0000F1D3BB00F6E9
      DD00ECD8C600D7AC8100DCBB9A00F6ECE300F5ECE200E4C8AE00D2A77B00E6CE
      BA00F1E2D500DFBB9C0000FF000000FF000000FF000000FF0000C88D5100F8EF
      E600FCE3CF00FBE4D000FCE4CF00FCE3CD00FAE1CA00F9DDC400F6D9BC00F4E9
      DF00F7F2EC00FBF7F300F5EFE900C380480000FF000000FF000000FF0000CECE
      9C00CECE9C00FFCE6300FFCE6300FFCE3100FFCE3100FF9C3100FF9C3100FF9C
      31009C63310000FF0000CECE9C0000FF000000FF000000FF000000FF000000FF
      00003C7EBB004B8DC30070AAD20071AAD20074ACD2007AAFD3005697C4004589
      BB0000FF000000FF000000FF000000FF000000FF000000FF0000FBF1E900F3D4
      BB00F7EADF00EEDED000E3C1A700D8AE8900D7AC8600DDBB9C00EBD6C700F3E6
      D900E4C1A300F5E9DF0000FF000000FF000000FF000000FF0000C88D5200F9F5
      F100FCE3CD00FBE3CE00FBE3CD00FBE2CB00F9E0C800F8DCC200F5D6BA00FDFB
      F800FCE6CD00FAE5C900E2B68400D5A8840000FF000000FF000000FF000000FF
      000000FF0000CECE9C00CECE9C00CECE9C00CECE6300FFCE31009C6331009C63
      310000FF000000FF0000CECE9C0000FF000000FF000000FF000000FF000000FF
      000000FF00003A7BB900488BC2006AA6D0006EA9D1005193C6004389BF0000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000FCF2
      EA00F6DAC300F9E9DC00F6E8DD00F3E5DA00F3E5DA00F5E7DC00F5E4D600EDCD
      B400F8ECE30000FF000000FF000000FF000000FF000000FF0000CA925A00FAF6
      F200FAE0C700FBE1C900FBE2C900FBE0C800F9DFC500F8DBC100F4D6B800FFFB
      F800F6D8B400E1B07D00DC96690000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000CECE9C00CECE9C0000FF
      000000FF000000FF0000CECE9C0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF0000427FBB003577B700367BB9004788C10000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000FCEDE100F8DEC900F6D9C100F5D7BF00F5D9C300F8E8DC0000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000D2A27400F8F3
      ED00F8F4EE00F8F4ED00F8F3ED00F8F3ED00F8F3ED00F8F2EC00F7F2EC00F2E6
      D700E2B27D00DC986B0000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000CECE
      9C00CECE9C00CECE9C0000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000E8CEB900D7AA
      7C00CC945B00CA905500CA905500CA905500CA915500CB905500C98F5500CF9D
      6900DDB1900000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000BE9E890094603D009360
      3C00925F3B00925E3A00915D3900905D3800905C38008F5B37008F5A36008E5A
      3500B18C730000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000A2CAEE0076B2E6003E91DB00348C
      D900348CD900348CD900348CD900348CD900348CD900348CD900348CD900348B
      D900398FDA0085B9E90000FF000000FF000000FF0000A1745600CCAB8500D1AF
      8900D2B08800D1AD8500D0AA8100CFA77F00CEA47B00CDA17A00CB9F7700C799
      710093613E008F7F730000FF000000FF000000FF000000FF000000FF000000FF
      0000F4ECE500D6BAA200B6845A00AC744500AB724300B27E5300D2B59C00F2EA
      E30000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00004799DD00DEF1FA00A8DDF4009EDB
      F40096DAF3008ED8F30086D7F3007FD4F20079D3F20072D2F1006CD0F10069CF
      F100C2EAF8003F95DB0000FF000000FF000000FF0000A2755600CAA98500A378
      5400C69A6700C4986200C2945E00C1905A00C08C5600BE895300BF885500C99D
      750093623F006953410000FF000000FF000000FF000000FF000000FF0000E7D5
      C600BA895F00D7BBA300E9DACA00ECE0D100ECE0D100E8D8C800D3B59C00B07A
      4D00E2CFBE0000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF00003B97DB00EFFAFE00A1E9F90091E5
      F80081E1F70072DEF60063DAF50054D7F40047D3F30039D0F2002ECDF10026CB
      F000CAF2FB003B97DB0000FF000000FF000000FF0000A2765700CBAC8800A67E
      5700C99F6E00C79D6900C6996600C3976100C2925C00C18F5900C18E5B00CAA1
      780094624000573E2A0000FF000000FF000000FF000000FF0000EAD9CB00BE8C
      6200E7D5C400E5D2BF00C9A68500B88E6700B68A6500C5A18000E0CCBA00E3D0
      BE00AF764800E3D0C00000FF000000FF000000FF000000FF0000B07A5800B07A
      5800B07A580000FF0000DD9BD900DD9BD900DD9BD90000FF0000B177FF00B177
      FF00B177FF0000FF000000FF000000FF00003C9DDB00F2FAFD00B3EDFA00A4E9
      F90095E6F80085E2F70076DEF60065DBF50057D7F40049D4F3003BD1F20030CE
      F100CCF2FB003B9BDB0000FF000000FF000000FF0000A3775900CEB08E00AA85
      5B00CBA47500CAA27100C89E6B00C69B6800C5996300C2945E00C4946100CCA5
      7D0094634100573E2A0000FF000000FF000000FF0000F7F1EC00C99D7900EAD8
      C900E3CDBA00C0946B00BA8C6200CFB09400CFB09400B7895F00B2876100DAC0
      AA00E4D1C000B6835900F4ECE60000FF000000FF000000FF0000B07A5800B07A
      5800B07A580000FF0000DD9BD900DD9BD900DD9BD90000FF0000B177FF00B177
      FF00B177FF0000FF000000FF000000FF00003BA3DB00F6FCFE00C8F2FC00B9EF
      FB00ACECFA009CE8F9008BE3F7007CE0F6006CDCF6005DD9F5004FD6F40044D3
      F300D0F3FC003BA2DB0000FF000000FF000000FF0000A4785A00D0B49200AF8B
      6000CEA97C00CCA67700CBA37400C9A06E00C79D6A00C69A6600C69B6800CDA8
      820095644200573E2A0000FF000000FF000000FF0000E6CFBC00E4CCB900EAD6
      C500C7997100BF906600BF906600F7F1EC00F6F0EA00B7895F00B7895F00B589
      6300E2CEBB00D9BDA600D9BEA70000FF000000FF000000FF0000B07A5800B07A
      5800B07A580000FF0000DD9BD900DD9BD900DD9BD90000FF0000B177FF00B177
      FF00B177FF0000FF000000FF000000FF00003BA8DB00FEFFFF00F8FDFF00F6FD
      FF00F5FCFF00F3FCFE00D8F6FC0094E6F80085E3F70076DFF60068DBF5005CD8
      F400D7F4FC003188B9004D7CA300416F960000FF0000A5795B00D2B79600B492
      6500D1AE8300CFAB7F00CDA87A00CBA57600CAA27100C89E6D00C89F6D00D0AE
      860096654400573E2A0000FF000000FF000000FF0000D9B39500EFE1D300D9B5
      9500C7986C00C3956900C1936700BF906600BF906600BB8B6300B98A6300B88A
      6200CBA78600EADCCC00C2956F0000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000039ADDB00E8F6FB0094D4EF0088CE
      EE0073C1E900C9E9F600F2FCFE00F3FCFE00F2FCFE00F0FCFE00EFFBFE00EEFB
      FE00B0C1D100578BB7008CB1D40046759F0000FF0000A57A5C00D5BB9B00B89A
      6900D4B38A00D2AF8700D0AD8200CFAA7D00CDA67800CBA47400CCA47500D2B1
      8A0097674500573E2A0000FF000000FF000000FF0000DAB39300F2E4D900D1A5
      7A00C5996B00C4976A00C4966900FAF6F200F3EAE100C2956D00BE8F6500BE8F
      6400C0956D00EFE3D500C190670000FF000000FF000000FF0000B2EBD000B2EB
      D000B2EBD00000FF00006DCC50006DCC50006DCC500000FF0000EBB06000EBB0
      6000EBB0600000FF000000FF000000FF000040AEDC00F1FAFD0094DEF50093DC
      F40081D5F2006ACAED006CCBEA0087C8DD0098B2B400C7AC9400CDAF9600C8A8
      8D00AB998E0096B1CB005D8CB800B2C3D20000FF0000A67B5D00D7BF9F00BD9F
      6F00D4B59000CBAD8800C7A88100C6A57D00C4A17A00C5A17600CBA77B00D4B4
      900098684600573E2A0000FF000000FF000000FF0000E1BB9D00F2E5DA00D1A6
      7E00CC9D7100C79A6C00C5986B00E2CCB600F8F3EE00F6EEE800D9BDA100C294
      6800C59B7100F0E2D600C799710000FF000000FF000000FF0000B2EBD000B2EB
      D000B2EBD00000FF00006DCC50006DCC50006DCC500000FF0000EBB06000EBB0
      6000EBB0600000FF000000FF000000FF000041B4DC00F7FCFE008EE4F80091DE
      F5009FE0F500ACE1F600EFFBFE00C6B8AA00E2CDBC00F5E0CC00F7E0C700F8E2
      CB00F3D1B300A7998F00B4C5D50000FF000000FF0000A77C5E00D9C2A400C1A4
      7200D2B89400F5EDE400F4ECE200F4ECE100F4EBE000F3EADF00CBA97F00D6B8
      960099694700573E2A0000FF000000FF000000FF0000EACAB000F3E5D900DFBB
      9E00CFA07500CD9E7200F5EBE300E4CBB400E7D3BF00FBF8F600E5D3BF00C498
      6B00D6B49100EEE0D200D3AC8B0000FF000000FF000000FF0000B2EBD000B2EB
      D000B2EBD00000FF00006DCC50006DCC50006DCC500000FF0000EBB06000EBB0
      6000EBB0600000FF000000FF000000FF00003CB5DB00FDFEFE00FEFFFF00FEFE
      FF00FDFEFF00FEFFFF00EAF7FB00C9AC9400F3E3D400F4DAC100F3D8BD00F3D8
      BD00F8E3CC00C4A48B0000FF000000FF000000FF0000A77C5E00DBC5A600C6A7
      7600D9BF9B00D1B79300CBB08E00CAAE8A00C8AB8700CBAB8300D1B08700D8BB
      9B00996A4800573E2A0000FF000000FF000000FF0000F5E4D600F4E3D400EFDC
      CD00D5A87E00D0A07700FBF8F500FCF8F500FCF8F500FBF8F500D1A88100CFA4
      7B00EAD5C300EAD4C200E9D4C20000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000059C2E00061C3E20063C4E30063C4
      E30063C4E30062C4E30056C0E000C8A98D00F8EADC00F4DDC600F4DCC400F3D8
      BD00F8E2CD00CCAD930000FF000000FF000000FF0000A87C5F00DDC8A900D4BD
      9500E6D4B900E6D1B600E4D0B500E3CEB300E2CBB000E0C9AD00DFC7A900DABF
      A0009A6B4A00573E2A0000FF000000FF000000FF0000FDF9F500F1D3BB00F6E9
      DD00ECD8C600D7AC8100DCBB9A00F6ECE300F5ECE200E4C8AE00D2A77B00E6CE
      BA00F1E2D500DFBB9C00FAF4F00000FF000000FF000000FF00006B6FFE006B6F
      FE006B6FFE0000FF000073AAFF0073AAFF0073AAFF0000FF000067D5F00067D5
      F00067D5F00000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF0000CAAE9500F2E3D500F6E0CA00F5DEC600F5DE
      C500F7E5D200C5AA940000FF000000FF000000FF0000A87E6100D9C2A500B591
      7000AB805F00A97E5E00A97E5E00A87D5C00A87C5B00A77B5A00A67959009C6B
      490096644100573E2A0000FF000000FF000000FF000000FF0000FBF1E900F3D4
      BB00F7EADF00EEDED000E3C1A700D8AE8900D7AC8600DDBB9C00EBD6C700F3E6
      D900E4C1A300F5E9DF0000FF000000FF000000FF000000FF00006B6FFE006B6F
      FE006B6FFE0000FF000073AAFF0073AAFF0073AAFF0000FF000067D5F00067D5
      F00067D5F00000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF0000C2B6A800DDC3AB00F4E6DA00F8ECDF00F2DD
      C900E3C9B200C4B4A60000FF000000FF000000FF0000AF886D00BA977800D8C5
      B900E8DED700E7DDD600E6DCD600E4DBD400E3DAD300E2D8D100E1D7D000EBE7
      E500EFEFEF00573E2A0000FF000000FF000000FF000000FF000000FF0000FCF2
      EA00F6DAC300F9E9DC00F6E8DD00F3E5DA00F3E5DA00F5E7DC00F5E4D600EDCD
      B400F8ECE30000FF000000FF000000FF000000FF000000FF00006B6FFE006B6F
      FE006B6FFE0000FF000073AAFF0073AAFF0073AAFF0000FF000067D5F00067D5
      F00067D5F00000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000C2B7A800BFAE9700C9AB8F00CDAF
      9500BEAB980000FF000000FF000000FF000000FF0000C7AC99009D6E4C00BB97
      7800AC826200AC816100AB806000AB7F5F00AA7F5E00A87E5D00A87C5C009D6D
      4C0097664300885C3C0000FF000000FF000000FF000000FF000000FF000000FF
      0000FEFAF700FCEDE100F8DEC900F6D9C100F5D7BF00F5D9C300F8E8DC00FDF8
      F50000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF0000AD846900B38E
      74009D6C4B009C6C4A009C6B49009B6A49009B6A48009A694700996846009867
      4500936443009472570000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF0000C6C6C600828282007D7D7D00BCBCBC0000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF0000CD957000BD734200B768
      3500B5683500B4673400B2663400B0653300AE643300AC633200AA623200A961
      3200A8603100A7613200AB693C00BC86610000FF000000FF000000FF000000FF
      00001313F2000000F1000000F1000000F1000000EF000000EF000000ED001212
      EE0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF0000FEFEFE008B8B8B00BDBDBD00B2B2B20069696900FEFEFE0000FF
      000000FF000000FF000000FF000000FF00000207DB007080ED007DB7FB007EBC
      FC0096E2F90099E6F9007FCF96007CCC8800D2BAA300D6B8A200B179500000FF
      000000FF000000FF000000FF000000FF0000C37D4F00EBC6AD00EAC5AD00FEFB
      F800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFB
      F800FEFBF800C89A7C00C7987900AD6B400000FF000000FF000000FF00001313
      F6001A20F5003C4CF9003A49F8003847F8003545F8003443F7003242F700141B
      F1001717EF0000FF000000FF000000FF000000FF000000FF0000B2B2B2007070
      70007373730000FF00008F8F8F00CBCBCB00C7C7C7007171710000FF00006868
      68004F4F4F009090900000FF000000FF0000060BDC006E7EEC003887F5003797
      FA0057C8F70061D8F60041BC7C0033B14700A7996A00D7BAA500BA87630000FF
      000000FF000000FF000000FF000000FF0000BA6C3800EDCAB300E0A27A00FEFA
      F70062C0880062C0880062C0880062C0880062C0880062C0880062C0880062C0
      8800FDF9F600CA8D6500C99B7C00A761320000FF000000FF00001313F8001D23
      F9004453FA002429F9001212F7000F0FF6000C0CF5000909F500161BF5003343
      F700141BF1001717EF0000FF000000FF000000FF0000D3D3D300BCBCBC00DEDE
      DE00A6A6A6008888880085858500C4C4C400C2C2C2006E6E6E0074747400A6A6
      A600D2D2D20080808000ACACAC0000FF0000151ADE006877EB003D7CF2003797
      FA004DB9F80061D8F6004EC7AD0034B24A0076A35B00D6BAA400CAA48800B179
      500000FF000000FF000000FF000000FF0000BB6C3800EECCB600E1A27A00FEFA
      F700BFDCC200BFDCC200BFDCC200BFDCC200BFDCC200BFDCC200BFDCC200BFDC
      C200FDF9F600CD906800CC9E8100A861320000FF00001313F9001F25FA004A58
      FB004247FB00C9C9FD003B3BF9001313F7001010F6003333F700C5C5FD003035
      F7003444F700141BF2001717EF0000FF000000FF0000D6D6D600A6A6A600D5D5
      D500C5C5C500CBCBCB00D1D1D100C9C9C900C7C7C700CCCCCC00C5C5C500BDBD
      BD00CBCBCB006F6F6F00B4B4B40000FF00003C40E3005663E9007695F2003795
      F90040A5F9005ED4F6005CD4E3003BB7640033B14700A7986A00D7BAA500BF91
      7000B179500000FF000000FF000000FF0000BB6B3800EFCEB800E1A27900FEFA
      F70062C0880062C0880062C0880062C0880062C0880062C0880062C0880062C0
      8800FDF9F600CF936A00CEA38400AA61320000FF00000000FB004F5DFD003237
      FB00CBCBFE00F2F2FF00EBEBFE003B3BF9003939F800EAEAFE00F1F1FE00C5C5
      FD00181DF6003343F7000000EF0000FF000000FF000000FF0000D4D4D400C5C5
      C500C1C1C100C5C5C500C7C7C700AAAAAA00A7A7A700C1C1C100BEBEBE00B5B5
      B500AAAAAA00B1B1B10000FF000000FF00009B9DF1000207DB007084EE003588
      F6003797FA0053C1F70061D8F6004DC6AB0034B24C0054AA5100BCA38000D7BA
      A500CAA48800BA876300B179500000FF0000BA6A3600EFD0BB00E2A27A00FEFB
      F800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFBF800FEFB
      F800FEFBF800D3966D00D2A78A00AB62320000FF00000000FD00525FFD002828
      FC004747FC00ECECFF00F2F2FF00ECECFF00ECECFE00F1F1FF00EAEAFE003434
      F7000B0BF5003545F8000000EF0000FF0000B5B5B5009B9B9B00A6A6A600CFCF
      CF00C6C6C600CCCCCC00B4B4B400E4E4E400E2E2E200A8A8A800C1C1C100BCBC
      BC00B9B9B9006E6E6E006A6A6A007575750000FF0000161BDE006776EB00789D
      F4003795FA0041A7F9005CD0F60061D8F50044BF8B0033B1480054AA5100A798
      6A00D6BAA400D7BAA500D6B8A20000FF0000BB6A3600F0D2BE00E2A37A00E2A3
      7A00E1A37A00E2A37B00E1A37B00E0A17800DE9F7700DD9F7600DC9D7400D99B
      7200D8997100D6997000D5AB8E00AD63330000FF00000000FD005562FE002C2C
      FD002929FC004848FC00EDEDFF00F2F2FF00F2F2FF00ECECFE003A3AF9001212
      F7000F0FF6003848F8000000F10000FF0000C0C0C000E2E2E200D2D2D200C6C6
      C600CDCDCD00B1B1B100E2E2E20000FF000000FF0000E3E3E300A8A8A800C2C2
      C200B7B7B700C0C0C000D2D2D2006262620000FF0000686BEA000106DB007286
      EE003481F4003797FA004AB4F80060D6F6005ED5EA0044BF8B0034B24C0033B1
      470076A35B00A7996A00D2BAA30000FF0000BB6A3600F2D5C200E3A37A00E3A3
      7A00E2A37B00E2A37B00E2A47B00E1A27900E0A17800DEA07700DE9E7500DC9D
      7400DA9B7300D99B7300DAB09500AF64330000FF00000000FD005764FE003030
      FD002D2DFD004B4BFC00EDEDFF00F2F2FF00F2F2FF00ECECFF003D3DF9001616
      F8001313F7003C4BF8000000F10000FF0000C4C4C400E9E9E900D6D6D600C9C9
      C900CECECE00A5A5A500DEDEDE0000FF000000FF0000E4E4E400ACACAC00C4C4
      C400BABABA00C6C6C600DDDDDD006C6C6C0000FF000000FF00001D21DF005865
      E9007694F200358DF8003797FA004EBAF80060D6F60061D8F5004DC6AB003BB7
      640034B24A0033B147007CCC880000FF0000BB6A3600F2D8C500E3A47B00E3A3
      7A00E3A47A00E2A47B00E2A37B00E1A37B00E1A27900DFA07700DE9F7600DD9E
      7400DB9C7200DC9D7400DDB59A00B165340000FF00000000FF005A67FE003333
      FE005050FD00EDEDFF00F3F3FF00EDEDFF00EDEDFF00F2F2FF00ECECFE003E3E
      FA001717F8003F4EF9000000F10000FF0000D3D3D300CACACA00C4C4C400D8D8
      D800CDCDCD00BCBCBC009E9E9E00DBDBDB00DDDDDD00A8A8A800C3C3C300C2C2
      C200CDCDCD0094949400949494009B9B9B0000FF000000FF0000A3A5F200090E
      DC006D7DEC00779BF3003691F9003797FA004AB4F8005CD0F60061D8F6005CD4
      E3004EC7AD0041BC7C007FCF960000FF0000BB6B3600F4D9C700E6A67D00C88C
      6400C98D6500C98E6700CB926C00CB926D00CA906900C88C6500C88C6400C88C
      6400C88C6400DA9C7400E1BA9F00B366340000FF00000000FF005B68FF004347
      FE00CFCFFF00F3F3FF00EDEDFF004C4CFC004A4AFC00ECECFF00F2F2FF00CACA
      FE002A2FFA004251FA000000F30000FF000000FF000000FF0000E1E1E100D4D4
      D400CCCCCC00C9C9C900BABABA009C9C9C00A1A1A100C2C2C200C6C6C600C1C1
      C100B7B7B700C1C1C10000FF000000FF000000FF000000FF000000FF00006265
      E900050ADC006F7FED00779BF300358DF8003797FA0041A7F90053C1F7005ED4
      F60061D8F60061D8F60099E6F90000FF0000BB6C3700F4DCC900E7A77D00F9EC
      E100F9ECE100F9EDE300FCF4EE00FDFAF700FDF7F300FAEDE500F7E7DB00F7E5
      D900F6E5D800DEA07700E4BEA400B467340000FF00001414FF00262BFF005D6A
      FF00585BFF00CFCFFF005252FE002F2FFD002C2CFD004B4BFC00CCCCFE00484C
      FB004957FB001D23F9001414F60000FF000000FF0000E5E5E500C4C4C400DCDC
      DC00D4D4D400D9D9D900DBDBDB00D6D6D600D4D4D400D9D9D900D2D2D200CBCB
      CB00C8C8C8007A7A7A00B9B9B90000FF000000FF000000FF000000FF000000FF
      00005457E700050ADC006D7DEC007694F2003280F4003795FA003797FA0040A5
      F9004DB9F80057C8F70096E2F90000FF0000BD6E3A00F5DDCC00E7A87E00FAF0
      E800FAF0E800C98D6600FAF0E900FDF8F300FEFAF800FCF4EF00F9E9DF00F7E7
      DB00F7E5D900E0A27800E7C2A900B668350000FF000000FF00001414FF00262B
      FF005D6AFF004347FF003434FE003232FE003030FD002D2DFD00383CFC004F5D
      FC001F25FA001414F80000FF000000FF000000FF0000E8E8E800DCDCDC00EDED
      ED00DBDBDB00C5C5C500BEBEBE00D6D6D600D4D4D400B0B0B000B0B0B000CBCB
      CB00E7E7E700B7B7B700C7C7C70000FF000000FF000000FF000000FF000000FF
      000000FF00006265E900090EDC005865E9007387EE004679F0003588F6003795
      F9003797FA003797FA007EBCFC0000FF0000C0744200F6DFD000E8A87E00FCF6
      F100FCF6F100C88C6400FAF1E900FBF4EE00FDFAF700FDF9F600FAF0E800F8E8
      DD00F7E6DB00E1A37A00EFD5C300B76A360000FF000000FF000000FF00001414
      FF00262BFF005C69FF005B68FF005A67FE005865FE005663FE005461FE002227
      FC000D0DFB0000FF000000FF000000FF000000FF000000FF0000E3E3E300CECE
      CE00CFCFCF0000FF0000C8C8C800DEDEDE00DDDDDD00B9B9B90000FF0000B4B4
      B400A8A8A800C7C7C70000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF0000A3A5F2001D21DF002E38E2006776EB007084EE007695
      F2003D7CF2003887F5007DB7FB0000FF0000C6825500F6DFD100E9AA8000FEFA
      F600FDFAF600C88C6400FBF3EE00FBF1EA00FCF6F200FEFBF800FCF6F100F9EC
      E200F8E7DB00EED0BA00ECD0BD00BD74430000FF000000FF000000FF000000FF
      00001313FF000000FF000000FF000000FF000000FD000000FD000000FD001313
      FD0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF0000CCCCCC00E5E5E500E4E4E400B3B3B30000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF0000686BEA00161BDE000207DB005663
      E9006877EB006E7EEC007080ED0000FF0000D6A58500F6E0D100F7E0D100FEFB
      F800FEFBF700FDF9F600FCF5F000FAF0EA00FBF2ED00FDF9F600FDFAF700FBF1
      EB00F8E9DF00ECD1BE00CD926A00E2C5B10000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF0000EBEBEB00D5D5D500D3D3D300E6E6E60000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF00009B9DF1003C40
      E300151ADE00060BDC000207DB0000FF0000E1BDA600D9AB8D00C9895E00C075
      4300BD6E3A00BB6C3700BB6B3600BB6A3600BB6A3600BC6C3900BD6E3B00BB6D
      3A00BF744400C98D6500E7CEBC0000FF0000424D3E000000000000003E000000
      2800000040000000D00000000100010000000000800600000000000000000000
      000000000000000000000000FFFFFF00FFFF0000EFF30000FFFF0000E3C70000
      FFE30000E0070000FFC30000E0070000FF830000E0070000E0070000E0070000
      C00F0000C0030000801F000080010000801F000080000000801F000000000000
      801F000000000000801F0000F81F0000801F0000FC1F0000C03F0000FC3F0000
      E07F0000FE7F0000FFFF0000FE7F0000FC00E007801F8003FC000000001F0003
      C0000000001F000380000000001F000300000000803F000300000000C0000000
      00000000C000000000000000C000000000000000C000000000010000C0010000
      000F8001E0030000000FE007FE03F800000FE007FE03F800000FE007FE03F800
      801FE00FFE03F800E07FE01FFF07F8008001FFFF83C1C0008001F00F0180C000
      8001E0070180C0008001C00383C1C0000001C003C18300000001C003E0078000
      0001C003F00FC0000001C003F81FC0000001C003F81FC0000001C003F81FC000
      0001C003F00FC0000001C003E007C0008001C0038181C0008003E0078181C001
      8007F81F8181C003800FFFFF8181C007FFFFFFFFF01F8001FFFFFFFFC0078001
      FFFFFFFF800380018001800180038001FFFF8001000380018001800100010001
      FFFF8001000100018001800100010001803F8001000100018001800100010001
      803FFFFF000100018001FFFF00010001803FFFFF000180018001FFFF00018003
      FFFFFFFF00018007FFFFFFFF0FE1800FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFF000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFF0000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFF000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF01FFFFFFFFFFFFFC007FFFFFFFF
      FFFF8003FFFFFFFF800180030000000080010003000000008001000100000000
      8001000100000000800100010000000080010001000000008001000100000000
      FFFF000100000000FFFF000100000000FFFF000100000000FFFF000100000000
      FFFF0001FFFFFFFFFFFF0FE1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFF0000000000008001000000000000FFFF0000000000008001
      000000000000FFFF0000000000008001000000000000803F0000000000008001
      000000000000803F0000000000008001000000000000803FFFFFFFFF00008001
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFF000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FFFF0000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FBEFFFF
      8001FFFFFFFFFFFF800100000000000080010000000000008001000000000000
      8001000000000000800100000000000080010000000000008001000000000000
      800100000000000080010000000000008001000000000000FFFF000000000000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8FFFFFFFFFFFC000301F0000F81FC000
      30070000E007C0002003C003C003C0000003E007C003C00081C1E0078001C000
      8001C00380010000C001800180010000E001000080010000A18180018001C000
      D003C0038001C000C803E007C003C000E005F00FC003C000F80DF81FE007C001
      FF9DFC3FF81FC003FFE3FFFFFFFFC007FFFF8007FFFFFFFF00038003F00FFFFF
      00038003E007FFFF00038003C003C447000380038001C447000380038001C447
      000080038001FFFF000080038001C447000080038001C447000180038001C447
      000380038001FFFF000380038001C447FE038003C003C447FE038003E007C447
      FF078003F00FFFFFFFFFC003FFFFFFFFFFFFFC3FFFFF8000F00FF81F001F0000
      E007C423001F0000C0038001000F000080018001000700008001C00300010000
      8001000080010000800101808001000080010180C001000080010000C0010000
      8001C003E001000080018001F0010000C0038001F8010000E007C423FC010000
      F00FFC3FFF010000FFFFFC3FFFC1000100000000000000000000000000000000
      000000000000}
  end
  object odMain: TOpenDialog
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 768
    Top = 2
  end
  object mMainMenu: TMainMenu
    Images = ilToolbar
    Left = 696
    object File1: TMenuItem
      Caption = '.'
      object miScan: TMenuItem
        Caption = '.'
        OnClick = miScanClick
      end
      object N27: TMenuItem
        Caption = '-'
      end
      object miImport: TMenuItem
        Caption = '.'
        OnClick = sbLoadFromReportClick
      end
      object N8: TMenuItem
        Caption = '-'
      end
      object miSaveReports: TMenuItem
        Caption = '.'
        ImageIndex = 3
        ShortCut = 16467
        OnClick = miSaveReportsClick
      end
      object N26: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = '.'
        OnClick = Exit1Click
      end
    end
    object miSearch: TMenuItem
      Caption = '.'
      object miSearchMain: TMenuItem
        Caption = '.'
        Enabled = False
        ImageIndex = 48
        ShortCut = 16454
        OnClick = lTaskID4Click
      end
      object miSearchWizard: TMenuItem
        Caption = '.'
        ShortCut = 32838
        OnClick = miSearchWizardClick
      end
    end
    object View1: TMenuItem
      Caption = '.'
      object miHTMLReport: TMenuItem
        Caption = '.'
        Enabled = False
        ImageIndex = 8
        ShortCut = 121
        OnClick = miHTMLReportClick
      end
      object miXMLReport: TMenuItem
        Caption = '.'
        Enabled = False
        ImageIndex = 11
        ShortCut = 120
        OnClick = miXMLReportClick
      end
      object miCSVReport: TMenuItem
        Caption = '.'
        Enabled = False
        ImageIndex = 39
        ShortCut = 119
        OnClick = miCSVReportClick
      end
      object miTextReport: TMenuItem
        Caption = '.'
        Enabled = False
        ImageIndex = 40
        ShortCut = 120
        OnClick = miTextReportClick
      end
      object miXinorbisReport: TMenuItem
        Caption = 'Xinorbis'
        Enabled = False
        ImageIndex = 42
        ShortCut = 119
        OnClick = miXinorbisReportClick
      end
      object miTreeReport: TMenuItem
        Caption = '.'
        Enabled = False
        ImageIndex = 43
        ShortCut = 118
        OnClick = miTreeReportClick
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object miOpenLastReport: TMenuItem
        Caption = '.'
        Enabled = False
        ShortCut = 16466
        OnClick = miOpenLastReportClick
      end
      object miCopyLastReportToClipboard: TMenuItem
        Caption = '.'
        Enabled = False
        OnClick = miCopyLastReportToClipboardClick
      end
      object N18: TMenuItem
        Caption = '-'
      end
      object miReportBrowser: TMenuItem
        Caption = '.'
        ImageIndex = 4
        OnClick = miReportBrowserClick
      end
      object N15: TMenuItem
        Caption = '-'
      end
      object InformationSection1: TMenuItem
        Caption = '.'
        object miTabTable: TMenuItem
          Caption = '.'
          Enabled = False
          RadioItem = True
          ShortCut = 16433
          OnClick = miTabTableClick
        end
        object miTabTree: TMenuItem
          Tag = 1
          Caption = '.'
          Enabled = False
          RadioItem = True
          ShortCut = 16434
          OnClick = miTabTableClick
        end
        object miTabOther: TMenuItem
          Tag = 2
          Caption = '.'
          Enabled = False
          RadioItem = True
          ShortCut = 16435
          OnClick = miTabTableClick
        end
        object miTabFolders: TMenuItem
          Tag = 3
          Caption = '.'
          Enabled = False
          RadioItem = True
          ShortCut = 16436
          OnClick = miTabTableClick
        end
        object miTabMagnitude: TMenuItem
          Tag = 4
          Caption = '.'
          Enabled = False
          RadioItem = True
          ShortCut = 16437
          OnClick = miTabTableClick
        end
        object miTabFileDates: TMenuItem
          Tag = 5
          Caption = '.'
          Enabled = False
          ShortCut = 16438
          OnClick = miTabTableClick
        end
        object miTabHistory: TMenuItem
          Tag = 6
          Caption = '.'
          Enabled = False
          ShortCut = 16439
          OnClick = miTabTableClick
        end
        object miTabTop50: TMenuItem
          Tag = 7
          Caption = '.'
          Enabled = False
          ShortCut = 16440
          OnClick = miTabTableClick
        end
        object miTabNullFiles: TMenuItem
          Tag = 8
          Caption = '.'
          Enabled = False
          RadioItem = True
          ShortCut = 16441
          OnClick = miTabTableClick
        end
        object miTabUsers: TMenuItem
          Tag = 9
          Caption = '.'
          Enabled = False
          ShortCut = 16432
          OnClick = miTabTableClick
        end
        object miTabTemp: TMenuItem
          Tag = 10
          Caption = '.'
          Enabled = False
          ShortCut = 16468
          OnClick = miTabTableClick
        end
      end
      object N12: TMenuItem
        Caption = '-'
      end
      object miShowSearchSyntax: TMenuItem
        Caption = '.'
        ImageIndex = 5
        ShortCut = 114
      end
      object miShowCategoryColours: TMenuItem
        Caption = '.'
        ImageIndex = 7
        ShortCut = 115
        OnClick = miShowCategoryColoursClick
      end
    end
    object miDetail: TMenuItem
      Caption = '.'
      object miDFileSize: TMenuItem
        Caption = '.'
        Enabled = False
        ShortCut = 16496
        OnClick = miDFileSizeClick
      end
      object miDDuplicatesName: TMenuItem
        Caption = '.'
        Enabled = False
        ShortCut = 16497
        OnClick = miDDuplicatesNameClick
      end
      object miDDuplicatesSize: TMenuItem
        Caption = '.'
        Enabled = False
        ShortCut = 16498
        OnClick = miDDuplicatesSizeClick
      end
      object N29: TMenuItem
        Caption = '-'
      end
      object miMoreFolderDetail: TMenuItem
        Caption = '.'
        Enabled = False
        ImageIndex = 47
        ShortCut = 16499
        OnClick = miMoreFolderDetailClick
      end
    end
    object Edit1: TMenuItem
      Caption = '.'
      object miPreferences: TMenuItem
        Caption = '.'
        ImageIndex = 1
        ShortCut = 117
        OnClick = tbPreferencesClick
      end
      object miCustomiseQuickFolderMenu: TMenuItem
        Caption = '.'
        ImageIndex = 50
        OnClick = miCustomiseQuickFolderMenuClick
      end
      object N24: TMenuItem
        Caption = '-'
      end
      object miFHInfo: TMenuItem
        Caption = '.'
        ImageIndex = 41
        OnClick = miFHInfoClick
      end
      object miBackupData: TMenuItem
        Caption = '.'
        ImageIndex = 44
        OnClick = miBackupDataClick
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object miLanguage: TMenuItem
        Caption = '.'
        ImageIndex = 46
        object miLang1: TMenuItem
          Caption = 'English (UK)'
          ImageIndex = 26
          OnClick = miLang1Click
        end
        object miLang2: TMenuItem
          Tag = 1
          Caption = 'Nederlands'
          ImageIndex = 27
          OnClick = miLang1Click
        end
        object miLang3: TMenuItem
          Tag = 2
          Caption = 'Fran'#231'ais'
          ImageIndex = 28
          OnClick = miLang1Click
        end
        object miLang4: TMenuItem
          Tag = 3
          Caption = 'Deutsch'
          ImageIndex = 29
          OnClick = miLang1Click
        end
        object miLang5: TMenuItem
          Tag = 4
          Caption = 'Italiano'
          ImageIndex = 30
          OnClick = miLang1Click
        end
        object miLang6: TMenuItem
          Tag = 5
          Caption = 'Portuguese'
          ImageIndex = 31
          Visible = False
          OnClick = miLang1Click
        end
        object miLang7: TMenuItem
          Tag = 6
          Caption = 'Espa'#241'ol'
          ImageIndex = 32
          OnClick = miLang1Click
        end
        object miLang8: TMenuItem
          Tag = 7
          Caption = 'Svenska'
          ImageIndex = 33
          Visible = False
          OnClick = miLang1Click
        end
        object miLang9: TMenuItem
          Tag = 8
          Caption = 'Cestina'
          ImageIndex = 34
          Visible = False
          OnClick = miLang1Click
        end
        object miLang10: TMenuItem
          Tag = 9
          Caption = 'Magyar'
          ImageIndex = 35
          OnClick = miLang1Click
        end
        object miLang11: TMenuItem
          Tag = 10
          Caption = 'English (US)'
          ImageIndex = 36
          OnClick = miLang1Click
        end
        object miLang12: TMenuItem
          Tag = 11
          Caption = #1088#1091#1089#1089#1082#1080#1081
          ImageIndex = 37
          OnClick = miLang1Click
        end
        object miLang13: TMenuItem
          Tag = 12
          Caption = 'LOLCat'
          ImageIndex = 38
          OnClick = miLang1Click
        end
      end
      object N35: TMenuItem
        Caption = '-'
      end
      object miAddXinorbistoExplorerToContextMenu: TMenuItem
        Caption = '.'
        OnClick = miAddXinorbistoExplorerToContextMenuClick
      end
    end
    object Help1: TMenuItem
      Caption = '.'
      object miTutorial: TMenuItem
        Caption = '.'
        OnClick = miTutorialClick
      end
      object N34: TMenuItem
        Caption = '-'
      end
      object miDonate: TMenuItem
        Caption = '.'
        OnClick = miDonateClick
      end
      object N33: TMenuItem
        Caption = '-'
      end
      object Help2: TMenuItem
        Caption = '.'
        ImageIndex = 10
        ShortCut = 112
        OnClick = Help2Click
      end
      object miContextHelp: TMenuItem
        Caption = '.'
        ShortCut = 113
        OnClick = miContextHelpClick
      end
      object miUserManual: TMenuItem
        Caption = '.'
        OnClick = miUserManualClick
      end
      object miReference: TMenuItem
        Caption = '.'
        OnClick = miReferenceClick
      end
      object miFAQs: TMenuItem
        Caption = 'FAQs'
        OnClick = miFAQsClick
      end
      object N7: TMenuItem
        Caption = '-'
      end
      object miXinorbisHome: TMenuItem
        Caption = '.'
        ImageIndex = 9
        OnClick = miXinorbisHomeClick
      end
      object witter1: TMenuItem
        Caption = 'Twitter'
        ImageIndex = 49
        OnClick = witter1Click
      end
      object N14: TMenuItem
        Caption = '-'
      end
      object Checkforupdate1: TMenuItem
        Caption = '.'
        OnClick = Checkforupdate1Click
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object About1: TMenuItem
        Caption = '.'
        ImageIndex = 2
        OnClick = About1Click
      end
    end
    object miDebug: TMenuItem
      Caption = 'Debug'
      object ClearLanguage1: TMenuItem
        Caption = 'Clear Language'
        OnClick = ClearLanguage1Click
      end
      object DialogTest1: TMenuItem
        Caption = 'DialogTest'
        object Information1: TMenuItem
          Caption = 'Information'
          OnClick = Information1Click
        end
        object Warning1: TMenuItem
          Caption = 'Warning'
          OnClick = Warning1Click
        end
        object Xinorbis1: TMenuItem
          Caption = 'Xinorbis'
          OnClick = Xinorbis1Click
        end
      end
    end
  end
  object sdMain: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Xinorbis Reports|*.txt'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 808
  end
  object ilBigToolbar: TImageList
    DrawingStyle = dsTransparent
    Height = 32
    Masked = False
    Width = 32
    Left = 944
    Bitmap = {
      494C01010A006403000A20002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      00000000000036000000280000008000000060000000010020000000000000C0
      000000000000000000000000000000000000FFFFFF00E2DEDC008F7F7A00F1EF
      EE00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DEDEDE0080808000EFEF
      EF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000D8D3D1006B564F00604A42007561
      5A00F4F3F2000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000D3D3D300575757004B4B4B006262
      6200F3F3F3000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A7A7400604A4200604A4200604A
      420075625B00F4F3F20000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B004B4B4B004B4B4B004B4B
      4B0063636300F3F3F30000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F1EFEF0081706900604A4200604A
      4200604A420075625B00F4F3F200000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000EFEFEF00717171004B4B4B004B4B
      4B004B4B4B0063636300F3F3F300000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE0081706900604A
      4200604A4200604A420075625B00F4F3F2000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE00717171004B4B
      4B004B4B4B004B4B4B0063636300F3F3F3000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE008170
      6900604A4200604A4200604A420075625B00F4F3F20000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE007171
      71004B4B4B004B4B4B004B4B4B0063636300F3F3F30000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FEFE
      FE0081706900604A4200604A4200604A420075625B00F4F3F200000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FEFE
      FE00717171004B4B4B004B4B4B004B4B4B0063636300F3F3F300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FEFEFE0081706900604A4200604A4200604A420075625B00F4F3F2000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FEFEFE00717171004B4B4B004B4B4B004B4B4B0063636300F3F3F3000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FEFEFE0081706900604A4200604A4200604A420075625B00F4F3
      F200000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FEFEFE00717171004B4B4B004B4B4B004B4B4B0063636300F3F3
      F300000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FEFEFE0081706900604A4200604A4200604A42007562
      5B00F4F3F2000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FEFEFE00717171004B4B4B004B4B4B004B4B4B006363
      6300F3F3F3000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FEFEFE0081706900604A4200604A4200604A
      420075625B00F4F3F20000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FEFEFE00717171004B4B4B004B4B4B004B4B
      4B0063636300F3F3F30000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FEFEFE0081706900604A4200604A
      4200604A420075625B00F4F3F200000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FEFEFE00717171004B4B4B004B4B
      4B004B4B4B0063636300F3F3F300000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE0081706900604A
      4200604A4200604A420075625B00F4F3F2000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE00717171004B4B
      4B004B4B4B004B4B4B0063636300F3F3F3000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE008170
      6900604A4200604A4200604A420075625B00F4F3F20000000000000000000000
      00000000000000000000F6FCFE00F8FDFE000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE007171
      71004B4B4B004B4B4B004B4B4B0063636300F3F3F30000000000000000000000
      00000000000000000000FAFAFA00FBFBFB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FEFE
      FE0081706900604A4200604A4200604A420075625B00F4F3F200000000000000
      000000000000000000004DCAF00076D6F3000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FEFE
      FE00717171004B4B4B004B4B4B004B4B4B0063636300F3F3F300000000000000
      00000000000000000000A7A7A700BBBBBB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FEFEFE0081706900604A4200604A4200604A420075625B00F4F2F2000000
      000000000000000000002EC0EB005ECFF1000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FEFEFE00717171004B4B4B004B4B4B004B4B4B0063636300F2F2F2000000
      0000000000000000000097979700AFAFAF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FEFEFE0081706900604A4200604A4200624B4300665B5600F6F1
      F00000000000000000003CC6F0006BD3F2000000000000000000000000000000
      000074D6F30070D5F30000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FEFEFE00717171004B4B4B004B4B4B004C4C4C005B5B5B00F2F2
      F2000000000000000000A0A0A000B6B6B6000000000000000000000000000000
      0000BABABA00B9B9B90000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FEFEFE0081706900624B430051413A005F494200BB86
      7700F9F4F3000000000012CDFF005CCEEF000000000000000000000000007ED9
      F40016BAEB00A7E5F70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FEFEFE00717171004C4C4C00414141004B4B4B008B8B
      8B00F5F5F5000000000096969600AEAEAE00000000000000000000000000BFBF
      BF008C8C8C00D3D3D30000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FEFEFD007B6D6800614B4200B37C6D00D995
      8300D7836B00FCFCFC0073E1FF0075E3FF00000000000000000076D6F30016BA
      EB00C3EDFA000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FEFEFE006E6E6E004C4C4C00818181009B9B
      9B008A8A8A00FCFCFC00C1C1C100C2C2C2000000000000000000BBBBBB008C8C
      8C00E1E1E1000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FEFDFD00BC8D7F00DB978500BC82
      7200CA897700D58A7500FBFCFC000000000000000000C2F0FD0018B8E800C0EC
      FA00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FDFDFD00919191009D9D9D008787
      87008F8F8F0091919100FCFCFC000000000000000000E3E3E3008B8B8B00E0E0
      E000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE00DE8F7900C988
      7700BB847600CB887600D78A7600FBF7F60000000000EBFAFF00EDFAFE000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE00969696008E8E
      8E00898989008E8E8E0091919100F7F7F70000000000F6F6F600F6F6F6000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000D98D
      7900CA887600BD837300CA897800C98E7E00F7EFED0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009494
      94008E8E8E00888888008F8F8F0093939300F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000EDFDFE0052CCEF0047C6ED0047C9F00034D4FF0071E1FF00FDFD
      FD00D6938200C9887800BE827200CA8A7A00C17B680000000000FCFEFF0047D2
      FB0046C8EF0046C8EF0045C8EF006AD4F3000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F7F7F700A9A9A900A3A3A300A5A5A500A5A5A500C0C0C000FDFD
      FD009A9A9A008F8F8F0088888800909090008181810000000000FEFEFE00ABAB
      AB00A4A4A400A4A4A400A3A3A300B6B6B6000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000EEFDFF0065D4F3005FCCF0005ECFF1005FCDF00071E3FF000000
      000000000000CC958700C7897900BB837400E7A5940000000000FAFEFF005ED4
      F8005DCFF2005ECFF2005DCFF1007DD8F4000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F8F8F800B4B4B400AFAFAF00AFAFAF00AFAFAF00C1C1C1000000
      0000000000009A9A9A008F8F8F0088888800ABABAB0000000000FDFDFD00B3B3
      B300AFAFAF00B0B0B000AFAFAF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FEFCFC00C98B7A00E4A492000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FCFCFC0091919100AAAAAA000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000D1F3
      FE00F4FDFF0000000000000000000000000000000000E2F9FF00DAF4FC000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000EAEA
      EA00FAFAFA0000000000000000000000000000000000F2F2F200EDEDED000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000076D6F30019B8
      E800ECFAFE0000000000000000000000000000000000C5EFFB0018B9E900ACE6
      F800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000BBBBBB008C8C
      8C00F6F6F60000000000000000000000000000000000E3E3E3008C8C8C00D6D6
      D600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080D9F40016BAEB00B8EA
      F900000000000000000044D0FA006FD9F90000000000000000008FDEF50016BA
      EB00AFE7F8000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C0008C8C8C00DCDC
      DC000000000000000000A9A9A900BBBBBB000000000000000000C8C8C8008C8C
      8C00D7D7D7000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000065D1F20016BAEB00C2EDFA000000
      000000000000000000002CC0ED005ECFF10000000000000000000000000095E0
      F60016BAEB0096E0F60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000B3B3B3008C8C8C00E1E1E1000000
      0000000000000000000097979700AFAFAF00000000000000000000000000CBCB
      CB008C8C8C00CBCBCB0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005DCFF100B0E8F800000000000000
      000000000000000000003DC6EE006BD3F2000000000000000000000000000000
      00008BDDF5007BD8F40000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000AFAFAF00D8D8D800000000000000
      000000000000000000009F9F9F00B6B6B6000000000000000000000000000000
      0000C6C6C600BEBEBE0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000027BFEC005BCEF1000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000094949400AEAEAE000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000005BCFF10081DAF4000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000AEAEAE00C1C1C1000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FCF8F100F2DD
      BD00EAC69000E4B57100E0AB5E00DEA65300DEA65300E0AB5E00E4B57100EAC6
      9000F2DDBD00FCF8F10000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CAC2
      C0009787830085746E00735F580069554D0069554D00735F580084726E009F90
      8400C6BEBA000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F9EFE000EAC58F00DEA45100DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DEA45100EAC58F00F9EFE0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CECDCA00D8DEDB00B0AD
      A900543B32005C453D00604A4200604A4200604A4200604A4200604A42006043
      23006160A500687DF9009EA2DB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E4E4E4007C7C7C006A6A
      6A00A7A7A700000000000000000000000000000000000000000000000000A7A7
      A7006A6A6A007C7C7C00E4E4E400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000ECCB9B00DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800ECCB9B0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000D6D4D200D2D7D500D4DBD800CDD1CE00DEE7
      E400867973004C322900614B4300604A4200604A4200604A4300604427006053
      66006177FF006175FD006177FF006174F800A8ACDF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F9F8F800B7ADAA00F0EEED00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000DADADA0012121200000000000000
      0000000000006969690000000000000000000000000000000000696969000000
      0000000000000000000012121200DADADA000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FAF2E700E2B16900DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800E2B16900FAF2E7000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000077635D00A5A09C00DBE3E100C6C9C600C6C9C600DAE2
      DF00B0AEAA00513830005C453D00604A4200604A4200604A4100604326006165
      B900617AFF006170EB006170EA006179FF006170E5007C6C6D00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000ECEAE900604A4200DAD4D300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004040400000000000000000000000
      00000000000000000000BFBFBF000000000000000000BFBFBF00000000000000
      0000000000000000000000000000404040000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F9EEDE00DEA45100DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DEA45100F9EE
      DE00000000000000000000000000000000000000000000000000000000000000
      0000E2DEDD0069544D00594138004B302700ADA9A600D7DDDB00C7CAC700CFD4
      D100C5C8C5005F4840004E332A00604A4300614B450060411A0060442800616F
      E4006175FF006171ED006175FB00616DDA00604734006044290067534F00E2DE
      DD00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000EFEDEC0069554D00DFDAD800000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000C0C0C0000000000000000000000
      000000000000000000007C7C7C0000000000000000007C7C7C00000000000000
      00000000000000000000000000000C0C0C000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FBF5
      EC00DDA34E00DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DDA34D00D7933000D7932F00DDA34D00DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DDA3
      4E00FBF5EC000000000000000000000000000000000000000000000000000000
      000066504900604A4200624C4400482C2300887C7500DBE3E100C7CAC700C7C9
      C700CACECB00CCD0CD00A29D9800594035005D453600615C9100616AC8006172
      F1006171F0006171ED006179FF00615B8D008730510087387300604A42006650
      4900000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000EFEDEC006B564E00DFDAD900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002828280000000000000000000000
      00000000000000000000A9A9A9000000000000000000A9A9A900000000000000
      0000000000000000000000000000282828000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E1AD
      6100DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800D9983800E9C48D00E9C48D00D9983800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800E1AD61000000000000000000000000000000000000000000000000006F59
      5200624C4400604A4200624C4400452A200090868100DCE3E100C7CAC700C9CD
      CA00C9CDCA00A39D990082746E005C4439005E4635006160A4006170E2006172
      F2006171EE006171EE006179FF00615A88008731520087387300604A4200604B
      4500766154000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000EFEEEE006B554E00DCDAD900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BABABA0000000000000000000000
      0000000000003939390000000000000000000000000000000000393939000000
      0000000000000000000000000000BABABA000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000ECCA9A00DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DC9F4600D68E2600FFFFFF00FFFFFF00D68E2600DC9F4600DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800ECCA9A0000000000000000000000000000000000C4BFBC007563
      5C0044281E005239300045281E00614C4400C4C6C300D0D5D300C7CAC700D3D9
      D600BEBEBB004F352C004B302700614C4500614B430060411C00604733006170
      E8006175FD006171ED006176FD00616BCF00604427006043240060493D006043
      2300604B4700A7A3BC0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FEFEFE00574A4500EEEBEA00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000EAEAEA00727272005C5C
      5C00A3A3A300000000000000000000000000000000000000000000000000A3A3
      A3005C5C5C0072727200EAEAEA00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FBF3E900DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DC9F4700D7932F00F3DDBF00F3DDBE00D7932F00DC9F4700DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800FBF3E900000000000000000000000000DDE5E300C7CA
      C7007F706A006B5851007D6F6800C0C1BD00D5DCD900C5C7C400C7C9C600DEE6
      E500938A840041241A00624C4500604A4200604A4200604A420060411A006160
      A4006178FF006171ED006171EE006177FF006166B900604A440060463200604B
      47006169C600617AFF0000000000000000000000000000000000000000000000
      0000E7D1CC00D4ADA700CD9F9600CB9C9200CC9D9400CC9D9400CC9D9400CC9D
      9400CC9D9400CA9C9300D6A39A00C9999000614C4400BF918700DAA59B00CA9C
      9300CC9D9400CC9D9400CC9D9400CC9D9400CB9C9300CC9D9400D0A59E00DFC1
      BC00F9F3F1000000000000000000000000000000000000000000000000000000
      000000000000F8F8F800B3B3B300A9A9A900ABABAB00CACACA00C8C8C800BFBF
      BF00D2D2D200B7B7B700AAAAAA00AAAAAA00AAAAAA00AAAAAA00B7B7B700D2D2
      D200BFBFBF00C8C8C800CACACA00ADADAD00AFAFAF00AAAAAA00F1F1F1000000
      00000000000000000000000000000000000000000000E9C28A00DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA14A00D8963500D8963500DCA14A00DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800E9C28A000000000000000000C4C0BD00D9E1DE00D1D6
      D400D8DFDD00CCD0CE00D7DEDC00D3D9D600C5C7C400C5C8C500CACDCB00DAE2
      E000C7CAC7007D6D6700563D35005F494100604A420060483900604A4100616B
      CF00617CFF006170EB006170EB006171EE006177FF006171EE00616ACD006172
      F0006177FF006179FF00999BCE00000000000000000000000000F2E6E300C693
      8A00C48A7500CE997A00D19E7B00D19E7B00D19E7B00D19E7B00CE9B7900D6A2
      7E00E7AF8600D5A17D00D6A17E00C89676006B514700BC8E7100DBA47F00D39F
      7C00E7AF8600D9A47F00CE9B7900D19E7B00D19E7B00D29F7B00D09C7A00C890
      7700BE827600E5CCC80000000000000000000000000000000000000000000000
      000000000000DCDCDC0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E2E2E2000000
      000000000000000000000000000000000000FDFAF600DCA04900DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DC9F4500DCA14A00DCA14A00DC9F4600DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04900FDFAF60000000000CDD2CE00CDD1CF00C6C9
      C600C8CCC900CBCFCC00C8CCC900C7CAC600C6C8C500CCD0CD00DEE6E4008B7F
      7A009C958F009E9792003F231A00442A2000452A20004C2E11005E61B300636D
      CF006165B9006179FF006171EE006171EB006171EC006174F8006176FF006173
      F7006171EC006174F8006172F0000000000000000000F0E2DF00BC7F7200CF9B
      7A00DEB18100E0B48200DFB28100DEB18100DEB18100DEB18100EABB8700C29B
      730092745A00EBBC8700F2C18B00D0A57A0068504600C39B7400F3C28B00F1C1
      8A0096785D00B8936E00ECBC8800DEB18100DEB18100DEB18100E0B38100E0B4
      8100D5A47D00BF837300E1C6C000000000000000000000000000000000000000
      0000000000000000000000000000EDEDED00ECECEC00EDEDED00EDEDED00EDED
      ED00EDEDED00EDEDED00EDEDED00EDEDED00EDEDED00EDEDED00EDEDED00EDED
      ED00EDEDED00EDEDED00C9C9C9002727270016161600CECECE00000000000000
      000000000000000000000000000000000000F2DDBD00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DC9F4700D7912C00F6E7D000F6E7D100D7912C00DC9F4700DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800F2DDBD00D0CBC900DBE3E000DCE4E200CBD0
      CD00C7CAC700C7C9C600C7CAC700CCD1CE00D9E1DF00CFD3D0008E847D005238
      2F00381A1000442920008B7B7500BAB0AD00BAB0AD00897972004D373A004D2F
      1300644A32006168C2006175FA006173F8006171EE006171EC006171ED006171
      EC006171EC006175FD00617DFF00C4C4D900FDFBFB00BC817600D19D7B00E2B6
      8300DBAD7F00DAAA7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00E5B38400D5A7
      7C004C3A380072584B00FEC89100D8A97E00644D4400C89D7600FFCD95008265
      530043333300CB9F7800E7B68600DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00E1B58200D7A77E00BD807200F5ECE9000000000000000000000000000000
      00000000000000000000A2A2A2006B6B6B006767670069696900696969006969
      6900696969006969690069696900696969006969690069696900696969006969
      690069696900696969003A3A3A00262626000000000000000000000000000000
      000000000000000000000000000000000000E9C48D00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DC9F4600D7922D00FBF3E900FAF1E600D7912C00DC9F4600DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800E9C48D009788820076655F00B0AFAB00D0D5
      D200D5DBD900C9CDCA00D5DBD900CBCFCC00B9B9B500CACECB0069554E003A1D
      1200624C4500E0DBD900FFFFFF00E2DEDD00E2DEDD00FFFFFF00E1DBD300624C
      4200492A0C00644C40006172ED006175FF006178FF006177FF006171EE006177
      FF006179FF006172EF00615D95009C8F8A00DEC0BB00C7907700E0B38200DBAC
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00D7A97E00EAB8
      8700E1B08300523F3B007C605000E5B38500755B4D00DBAC80008F6F59004937
      3600D7A97E00EDBB8900D7A97E00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00E1B58200CD977900D3ABA4000000000000000000000000000000
      0000F8F8F8003F3F3F0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000141414009898980000000000000000000000
      000000000000000000000000000000000000E3B36D00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DC9F4600D7922E00F9EEDF00F8ECDA00D6912B00DCA04700DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800E3B36D00806E68004F342C00523930006A57
      4F008F847F00CFD4D1009289840067524B004D332A00AEABA7008C817B004428
      1F00FCFBFB00EAE7E600634E4600472D2400472E2400634D4600E8E5E400FDFD
      FD005638180055508A00626FE200604C4A0061587D006165B9006173F1006165
      B50061598300604C4C0060422000806C5F00C7948A00D3A17B00DFB38100DAAA
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00D7A9
      7E00EEBA8900E5B3840058433E0067504600876A56006B534800523F3B00DAAB
      7F00F1BD8B00D7A97E00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DEB18100D6A47D00C48D80000000000000000000000000000000
      0000636363000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C600000000000000
      000000000000000000000000000000000000DFA95A00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800D68E2600F5E4CB00FDFAF400D7922E00DB9F4500DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DFA95A00705C5500614B43005E484000492E
      2500553D3400BDBEBA00634E4600492E25005A423A005B443C00442A2100CDC6
      C300FEFEFE00442A2100482F2600604A4200604A4200482F260043292000FEFD
      FD00CDC4BC00412E3E00604F590060432300603E0E00614E4E005F72F9005640
      3800603E0F0060473300604A4300705C5500C2897A00D7A77E00DDAF8000DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00D7A97E00EDBA8900E3B28300624B43002E22290058443E00D9AB7F00F1BD
      8A00D7A97E00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DDAF8000D8A87E00C2877700000000000000000000000000F9F9
      F900050505000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007D7D7D00000000000000
      000000000000000000000000000000000000DEA45100DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800D6912A00E8C08500FFFFFF00E1AD6200D68E2500DDA2
      4C00DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DEA4510067534B00604A4200604B43005F49
      4100624D45006A574F00624C44005F494100614B4300553D350058403800FFFF
      FF009F918D003D221900634D4500604A4200604A4200634D45003D2319009F92
      8D00FFFFFF005B412E00593E2800604B460060493D00614C4B0060577A00624D
      4A005F483D00604B4300604A420067534B00C1887800D8A87E00DDAF8000DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00D7A97D00EDBA8900D8A97E0085675400CFA27900EFBC8A00D7A9
      7E00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DDB08100D7A67E00C28A7C00000000000000000000000000A7A7
      A700000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000045454500000000000000
      000000000000000000000000000000000000DEA45100DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DB9D4200D8943000FDFAF400FCF7F000D6912B00D792
      2D00DDA24C00DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DEA4510067534B00604A4200574037006A56
      4E00E6E2E1007A665F004E362D00614B4300604A4200533C3300715D5600FCFC
      FC007D6B64004E352D00604A4200604A4200604A4200604A42004E352C007D6B
      6400FCFCFC00715E5600543C3300604A4200604B440050372B00836C5200E7E2
      DE0069554F0057403800604A420067534B00C6918600D4A27C00DFB28100DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00D7A97D00E1B18300F2BE8B00E3B28400D7A97E00DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00D9AA7F00E1B58200D09D7B00CB9C94000000000000000000000000004646
      4600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000D0D0D00000000000000
      000000000000000000000000000000000000DFA95A00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DDA14B00D7922D00DFA85700FFFFFF00FBF4E900DB9E
      4400D7922D00DDA24C00DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DFA95A00705C5500604A4200563E36006550
      4800FFFFFF0095868100482F2600604A4200604A4200594139005F484000FFFF
      FF009889840040261C00624D4500604A4200604A4200624D450040251C009889
      8400FFFFFF005F49410059413900604A4200604A4200492F260095868000FFFF
      FF0065504800563E3600604A4200705C5500D9B6B000CA937800E0B48200DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DBAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00D9AA
      7F00DDB18000DDAF8000C2867400EBD8D4000000000000000000EBEBEB000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C6000000
      000000000000000000000000000000000000E3B36D00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DDA24C00D68F2700DEA65400FFFFFF00FDFB
      F700DA9A3D00D9983800DCA14900DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800E3B36D00806E6800644F4700513930003F24
      1B00F0EEED00ABA09C0043292000614B4300604A4200604A4200442B2200CEC6
      C400E9E5E4003C2117004F372E00614B4400614B43004F372E003C221800E9E6
      E500CDC6C400442B2100604A4200604A4200604B4300432A2000AA9E9A00F0EE
      ED003F251B0051393000644F4700806E6800F9F4F200BC7E7200D6A57D00E1B5
      8200DAAA7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00DBAC7F00DCAE8000DBAD8000DCAE8000E0B4
      8200DFB28200C68E7600CD9F9800000000000000000000000000929292000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000008B8B8B000000
      000000000000000000000000000000000000E9C48D00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04700DB9D
      4300DCA04700DCA04800DCA04800DCA04900DDA24C00D58E2400DB9D4200FFFF
      FF00F6E5CE00D68E2500DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800E9C48D009C8E89004F362D007B686200E0DC
      DA00FFFFFF00BEB6B2003F241A00614C4400604A4200644F470040261C00624C
      4400FFFFFF00D9D4D200533B330041261D0041261D00533C3300DBD5D400FFFF
      FF00614C440041261D00644F4700604A4200614C44003E241A00BDB3B000FFFF
      FF00E0DCDA007A6862004F362D009C8E890000000000E5CDC800BF837300D8A9
      7E00E0B48200DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DBAC7F00DAAC7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DBAC7F00D9A97E00D7A77E00D9AA7F00D9AA7F00D3A1
      7C00C3897500CEA09800FFFFFE00000000000000000000000000303030000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000004F4F4F000000
      000000000000000000000000000000000000F2DDBD00DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DDA14A00DB9E4400D998
      3900DB9D4300DDA24B00DCA04800DCA04800DCA04800DDA24C00D3881900EDCE
      A000FFFFFF00DDA44E00DA9A3C00DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800F2DDBD00C6BEBB0050382F0083716B00B5AB
      A800B9AEAB00F4F3F2005841380057403700644E47004D342B004E352D00D9D5
      D300E1DDDB00E1DDDB00FBFBFA00D7D1CF00D7D1CF00FBFBFB00E1DDDC00E1DD
      DB00DAD4D2004E352C004D342B00644E470058403800573F3700F3F1F100BAB0
      AD00B5ABA70083716B0050382F00C6BEBB000000000000000000DFC2BD00BC7F
      7200D19E7B00DCAF8000DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DBAD8000DBAC7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DFB28100CF9B7A00BC7E7200C0857400C0857400C590
      8600E3CAC50000000000000000000000000000000000DBDBDB00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000151515000000
      00000000000000000000000000000000000000000000DCA04900DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800D9983900E1AE6200F6E7
      D100E0AC5F00D9993A00DCA04800DCA04800DCA04800DCA04800D7933000E2B0
      6700FFFFFF00E4B57000D7943100DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA0490000000000000000006650480059423900361A
      100034170D00FFFFFF00B0A5A1003D23190050382F004A312800EEEBEA00FEFE
      FE004D342B00462C23009D8F8A00CCC5C300CCC5C3009D8F8A00462D23004D35
      2B00FEFEFE00EDEBEA004A30270050382F003D231900ADA19D00FFFFFF003519
      0E00361A0F00594239006550480000000000000000000000000000000000E2C7
      C300C2877500DDAF8100DBAC7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DDB0
      8000C8907700CE9A7A00DDB18100DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DBAC7F00D9A97E00D6A47D00D4A17C00C0857300F8F1
      F00000000000000000000000000000000000000000007B7B7B00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000D0D0
      D0000000000000000000000000000000000000000000E9C28A00DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800D8953200E2B16800FFFF
      FF00E7BD7F00D58D2400DCA14A00DCA04800DCA04800DCA14A00D68F2800E5B8
      7700FFFFFF00E2AF6500D8963500DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800E9C28A000000000000000000998B86005B443C005942
      3900B4AAA600FFFFFF00FFFFFF004C332A003A1E1400EEECEB00FEFEFE00543D
      34004A3128005E484000482F260043291F0043291F00482F26005E4840004A31
      2800543D3400FEFEFE00EEECEB003A1F15004A312800FFFFFF00FFFFFF00B4A9
      A600594239005B443C00998B860000000000000000000000000000000000F6EE
      ED00C3887500DCAE8000DCAE8000DAAB7F00DAAB7F00DAAB7F00DBAD8000DDAF
      8000BE817200CD997900DFB28100DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DAAA7F00DBAC7F00E1B58200D9AA7F00C2887B000000
      000000000000000000000000000000000000000000001E1E1E00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009595
      9500000000000000000000000000000000000000000000000000DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DB9D4300D9973600FFFF
      FF00F7E9D400D3861600DB9C4000DCA14A00DCA14A00DA9B3F00D3871700F7EA
      D700FFFFFE00D9963500DB9D4300DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA048000000000000000000000000000000000058413900654F
      4700D8D3D1008A797300D6D0CE00D0CAC700CAC3C000F0EEED0057403800482F
      2500644E4700604A4200604A4200604A4200604A4200604A4200604A4200644E
      4700482F250057403800F1EFEE00CAC3C000CFC9C600D7D1CF008A797300D8D3
      D100654F4700584139000000000000000000000000000000000000000000FFFF
      FE00C1897E00D19D7B00E3B78300DBAD7F00DAAA7F00DBAC7F00E3B88300CE9A
      7A00BD807200DBAC7F00DCAD8000DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00DAAB7F00D9AA7F00E1B48200CD997A00D0A6A0000000
      000000000000000000000000000000000000C6C6C60000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000005959
      5900000000000000000000000000000000000000000000000000ECCA9A00DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA14A00D6902800E8BF
      8400FFFFFF00ECCB9A00D58C2100D58C2100D58C2100D58C2200EDCDA000FFFF
      FF00E6BC7E00D6902900DCA14A00DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800ECCA9A0000000000000000000000000000000000A89C9800604A
      42004C342A002F1208005E473F00FFFFFF00FFFFFF00563F36002D1006006550
      4800614B4300604A4200604A4200604A4200604A4200604A4200604A4200614B
      4300655048002D100600553E3500FFFFFF00FFFFFF005E4840002F1208004C34
      2A00604A4200A89C980000000000000000000000000000000000000000000000
      0000EFE1DD00BD807200D19D7B00DEB18100E0B38100DEB18100D19D7B00BD80
      7200D29F7C00DEB28100DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00DAAB7F00D9AA7F00DEB18100DBAC7F00BF837300F2E7E4000000
      0000000000000000000000000000000000006363630000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001D1D
      1D0000000000000000000000000000000000000000000000000000000000E1AD
      6100DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DC9F4600D58E
      2400EDCC9D00FFFFFF00FAF2E600EDCFA300EED0A400FBF4E900FFFFFF00EBC9
      9700D58D2400DCA04700DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800E1AD61000000000000000000000000000000000000000000000000007663
      5C005A433B00523A3100DEDAD800E1DDDB00D7D2D000D4CECC006F5B54003E24
      1A00482F26005A433A005F4941005F4941005F4941005F49410059423A00482F
      25003E241A00715D5600D4CECC00D7D2D000E1DDDB00DED9D700523A31005A43
      3B0076635C000000000000000000000000000000000000000000000000000000
      000000000000EBD8D400C28B8200C48A7500CA937800C58B7500BA7D7500C185
      7400E0B48200DFB28100D9AA7F00DAAB7F00DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DAAB7F00D9AA7F00DDAF8000E1B48200C68E7600D2A9A300000000000000
      0000000000000000000000000000000000000303030000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000D4D4D4000000000000000000000000000000000000000000000000000000
      0000DDA34E00DCA04800DCA04800DCA04800DCA04800DCA04800DCA14A00DB9D
      4200D68F2700E4B57100F8EBD700FFFFFF00FFFFFF00F7E9D500E3B46E00D68E
      2600DB9D4300DCA14A00DCA04800DCA04800DCA04800DCA04800DCA04800DDA3
      4E00000000000000000000000000000000000000000000000000000000000000
      0000624D4500624C4400ACA19C00644E46003B201600E5E2E100FFFFFF00D1CB
      C8007D6B6500584038004A312800462C2300462D23004B322900584139007F6D
      6700D2CCCA00FFFFFF00E6E2E0003B201600644E4600ACA19C00624C4400624D
      4500000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000EDDDD900E6CFCB00EDDDDA00FBF7F600D4AD
      A500C3897500DAAC8000E0B58200DCAE8000DAAB7F00DAAB7F00DAAB7F00DAAB
      7F00DBAC7F00E0B38100DEB18100C8907700C7938B0000000000000000000000
      0000000000000000000000000000000000003131310000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000E0E
      0E00EDEDED000000000000000000000000000000000000000000000000000000
      000000000000DEA45100DCA04800DCA04800DCA04800DCA04800DCA04800DCA1
      4A00DCA04800D7922D00D7922D00DB9D4200DB9D4200D7922D00D7922E00DCA0
      4900DCA14A00DCA04800DCA04800DCA04800DCA04800DCA04800DEA451000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000E2DFDD0067534C00462D2400482F260066504800FCFBFB00B8AFAB00C5BD
      BA00F9F8F800F1EFEF00EAE7E600C4BCB900C4BCB800EAE7E600F2F0F000F9F8
      F800C4BCB900B8AEAB00FCFBFB0065504800482F2600462D240067534C00E2DF
      DD00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000D6B1AB00BE827300D09C7B00DBAD8000DFB28100DFB28100DFB28100DFB2
      8100DDAF8000D5A37D00C2887500CA9C9300FEFDFC0000000000000000000000
      000000000000000000000000000000000000F1F1F1007D7D7D00676767006666
      6600676767006767670067676700676767006767670067676700676767006767
      6700676767006767670067676700676767006767670067676700676767006767
      670067676700676767006767670067676700686868000C0C0C000B0B0B00EFEF
      EF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E2B16900DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04900DC9F4600DA9C4000DA9C4000DC9F4600DCA04900DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800E2B16900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000007D6B6400553D35007D6B6400B0A5A000452C2200381C
      1200FFFFFF00DDD8D600998B8600FFFFFF00FFFFFF0097898300DBD6D500FFFF
      FF00371C1100462C2300B0A5A0007D6B6400553D35007D6B6400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000ECDAD700CB9C9400C1867400C9917700CC977900CD987900CA93
      7800C48A7500C58F8500E2C8C300000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007D7D7D00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000ECCB9B00DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DCA04800DCA04800DCA04800ECCB9B0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000AA9F9A0059433A00452B2200553E35006954
      4C00D9D4D200725E57000E000000D6D0CE00D6D0CE000E000000725E5700D9D4
      D20069544C00553E3500452B220059433A00AA9F9A0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F5EBE900E4CDC800D9B6B000D7B4AE00E0C4
      BF00EFE0DD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DFDFDF00000000000000
      00000000000000000000000000003B3B3B000000000000000000000000000000
      000000000000000000000000000000000000F9EFE000EAC58F00DEA45100DCA0
      4800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA04800DCA0
      4800DCA04800DEA45100EAC58F00F9EFE0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E4E0DF009E908B0068534C00604A
      4200543C340059423A005A433B007E6C65007E6C65005A433B0059423A00543C
      3400604A420068534C009E908B00E4E0DF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007C7C7C005050
      50004C4C4C004A4A4A004F4F4F00868686000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F2DD
      BD00EAC69000E4B57100E0AB5E00DEA65300DEA65300E0AB5E00E4B57100EAC6
      9000F2DDBD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C6BE
      BB009C8E890083726B0077655E0059433A0059433A0077655E0083726B009C8E
      8900C6BEBB000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009D908B00604A420068534C00634E
      4600624D4500D8D4D000FDFEF900EEEDE800EEEDE800EEEDE800EEEDE800EEED
      E800EEEDE800EEEDE800EEEDE800EEEDE800EEEDE800EEEDE800EEEDE800EEED
      E800EEEDE800EEEDE800EEEDE800EEEDE800F0EFEB00FDFEFA008C7D7600543C
      340068534C0068534C00604A42009C8E8900000000000000000000000000EED5
      CA00CD896A00BE6A4200BB643900BB653C00BB653C00BB653C00BB653C00BB65
      3C00BB653C00BB653C00BB653C00BB653C00BB653C00BB653C00BB653C00BB65
      3C00BB653C00BB653C00BB653C00BB653C00BB653C00BB643900BE6A4200CD89
      6A00EDD5CA000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000097898400604A4200604A42005B44
      3C005A433B00D6D2CD00FDFEF900EDECE700EDECE700EDECE700EDECE700EDEC
      E700EDECE700EDECE700EDECE700EDECE700EDECE700EDECE700EDECE700EDEC
      E700EDECE700EDECE700EDECE700EDECE700EFEEEA00FDFEFA0086766F004B32
      2900604A4200604A4200604A4200968882000000000000000000CB815F00B257
      2900B45A2D00B4592C00B4592B00B4592B00B4592B00B4592B00B4592B00B459
      2B00B4592B00B4592B00B4592B00B4592B00B4592B00B4592B00B4592B00B459
      2B00B4592B00B4592B00B4592B00B4592B00B4592B00B4592B00B4592C00B45A
      2D00B2572900CB815E0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000988A8500604A4200604A42005B44
      3C005A433B00D6D2CD00FDFEF900EDECE700EDECE700EDECE700EDECE700EDEC
      E700EDECE700EDECE700EDECE700EDECE700EDECE700EDECE700EDECE700EDEC
      E700EDECE700EDECE700EDECE700EDECE700EFEEEA00FDFEFA0086766F004B32
      2900604A4200604A4200604A42009788830000000000CC836000B45C2F00B65B
      2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B
      2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B
      2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B2D00B65B
      2D00B65B2D00B45C2F00CC836000000000000000000000000000000000000000
      00000000000000000000ECF6EA00C0E1B700FDFEFD0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000988A8500604A4200604A42005B44
      3C005A433B00D6D2CD00FDFEF900EDECE700EDECE700EDECE700EDECE700EDEC
      E700EDECE700EDECE700EDECE700EDECE700EDECE700EDECE700EDECE700EDEC
      E700EDECE700EDECE700EDECE700EDECE700EFEEEA00FDFEFA0086766F004B32
      2900604A4200604A4200604A420097888300EFD7CC00B65C2D00B85D2F00B85C
      2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C
      2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C
      2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C2F00B85C
      2F00B85C2F00B85D2F00B65C2D00EFD7CC000000000000000000000000000000
      000000000000DCEED70064B44D0073BB5E000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007CDCF30057D2F00059D2F00059D2
      F00059D2F00059D2F00059D2F00059D2F00059D2F00059D2F00059D2F00059D2
      F00059D2F00059D2F00059D2F00059D2F00059D2F00059D2F00059D2F00059D2
      F00059D2F00059D2F00059D2F00059D2F00058D2F0005CD3F100D4F3FB000000
      000000000000000000000000000000000000988A8500604A4200604A42005A44
      3C0059433B00E0D5CD00FFFFF900F9EFE700F9EFE700F9EFE700F9EFE700F9EF
      E700F9EFE700F9EFE700F9EFE700F9EFE700F9EFE700F9EFE700F9EFE700F9EF
      E700F9EFE700F9EFE700F9EFE700F9EFE700FBF2EA00FFFFFA0089766E004931
      2900604A4200604A4200604A420097888300D3927100BA603200BA603000BA60
      3000BA603000BA603000BA603000BA603000BA603000B95F3000B5562300B554
      2200B5542200B5542200B5542200B5542200B5542200B5542200B5542200B554
      2200B5542200B5552300B95E2E00BA603000BA603000BA603000BA603000BA60
      3000BA603000BA603000BA603200D39271000000000000000000000000000000
      0000B5DBAA005CB043005CB0430094CB84000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000044CCEF004FD0EF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF007ADBF3000000
      000000000000000000000000000000000000988A8500604A4200604A42005A44
      3C005A433B00D9D3CD00FFFFF900F0EDE700F0EDE700F0EDE700F0EDE700F0ED
      E700F0EDE700F0EDE700F0EDE700F0EDE700F0EDE700F0EDE700F0EDE700F0ED
      E700F0EDE700F0EDE700F0EDE700F0EDE700F2F0EA00FFFFFA0087766E004A32
      2900604A4200604A4200604A420097888300C8774C00BB633400BB633400BB63
      3400BB633400BB633400BB633400BB633400BB623300B95A2700E4C0AD00E7C8
      B800E7C7B600E7C7B700E7C7B700E7C7B700E7C7B700E7C7B700E7C7B700E7C7
      B600E7C7B700E7C8B700BC643500BB613100BB633400BB633400BB633400BB63
      3400BB633400BB633400BB633400C8774C000000000000000000F3F9F1008DC8
      7C005CB043005CB043005CB043009BCE8B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000003FC9EE0056D2F0004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF000000
      000000000000000000000000000000000000988A8500604A4200604A42006145
      3B0063463C003CB0D2002FCEFD0035C1EB002DBFEA002ABEEA002BBEEA002BBE
      EA002BBEEA002BBEEA002ABEEA002FC0EA0034C1EB002FBFEA0034C1EB0034C1
      EB0034C1EB0034C1EB0034C1EB0034C1EB0033C2ED0030D0FF00566C72006638
      2800604A4200604A4200604A420097888300C8754800BE663600BF663500BF66
      3500BF663500BF663500BF663500BF663500BD633100C4744700FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D1937100BC602E00BF663500BF663500BF663500BF66
      3500BF663500BF663500BE663600C8754A00F9FCF800C1E1B70069B752005CB0
      43005CB043005CB043005CB043007EC06A00C4E2BA00C3E2BA00C3E2BA00C3E2
      BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2
      BA00C3E2BA00C3E2BA00C2E2B900C3E2BA00CDE7C500E9F4E600000000000000
      0000000000000000000000000000000000002EC2ED004DCFEF004CCFEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF00B3EA
      F80000000000000000000000000000000000988A8500604A4200604A42006345
      3B0066473C0011A6D20000C1FD0000B3EB0000AFEA0000B1EA0000B1EA0000B1
      EA0000B1EA0000B1EA0000B1EA0000B0EA0000B1EA0000AEEA0000B4EB0000B6
      EB0000B5EB0000B5EB0000B5EB0000B5EB0000B6ED0000C3FF00486972006E39
      2800604A4200604A4200604A420097888300CB794C00C1693900C1683900C168
      3900C1683900C1683900C1683900C1683900C0653500C5754700FFFFFF00FFFF
      FF00D4987700C97E5500CB815800CB815800CB815800CB815800CA7F5500D191
      6D00FFFFFF00FFFFFF00D2927000BF623100C1683900C1683900C1683900C168
      3900C1683900C1683900C1693900CB794C00EEF7EC005FB146005CB043005CB0
      43005CB043005CB043005CB043005CB043005CB043005CB043005CB043005CB0
      43005CB043005CB043005CB043005CB043005CB043005CB043005CB043005CB0
      43005CB043005CB043005CB043005CB043005CB043005CB0430069B75200BEE0
      B500000000000000000000000000000000001FBCEB0038C8EE0051D1F0004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF006DD7
      F20000000000000000000000000000000000988A8500604A4200604A42006245
      3B0064473C0023AAD20000C1FC0024BEEC00F0FBFE00FFFFFF00FCFEFF00FCFE
      FF00FCFEFF00FCFEFF00FFFFFF00BDECFA004BCAF000E2F7FD0022BEEC0009B6
      EA0016BAEB0016BAEB0016BAEB0016BAEB0014BBED000FC8FF004E6A72006A39
      2800604A4200604A4200604A420097888300CF7D5100C66D3B00C66D3A00C66D
      3A00C66D3A00C66D3A00C66D3A00C66D3A00C46A3600CA784B00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D5957100C3673300C66D3A00C66D3A00C66D3A00C66D
      3A00C66D3A00C66D3A00C66D3B00CF7E510000000000EEF7EC008EC87D005CB0
      43005CB043005CB043005CB043008EC87D00F3F9F200F4FAF200F4FAF200F4FA
      F200F4FAF200F4FAF200F4FAF200F4FAF200F4FAF200F4FAF200F4FAF200F4FA
      F200F4FAF200F4FAF200F4FAF200F3F9F200EAF5E700C9E5C00086C474005CB0
      43007EC06A00FBFDFB00000000000000000017B9EB0029C1ED0050D0F0004CCE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF0000000000000000000000000000000000988A8500604A4200604A42006245
      3B0064473C0023AAD20003C3FC0020BDEC0092DFF6009EE2F70096E0F60096E0
      F60093DFF6009DE2F700C2EDFA0087DCF5003AC5EE009EE2F7001FBCEC000DB7
      EA0016BAEB0016BAEB0016BAEB0016BAEB0014BBED000FC8FF004E6A72006A39
      2800604A4200604A4200604A420097888300D2815400C8703E00C9703E00C970
      3E00C9703E00C86F3D00C6683300C5663000C66A3700CD7B4D00FFFFFF00FFFF
      FF00D89B7800CE7F5300CF825600CF825600CF825600CF825600CF805400D593
      6D00FFFFFF00FFFFFF00D8977300C6683300C5663100C5673200C86F3D00C970
      3E00C9703E00C9703E00C8703E00D2815400000000000000000000000000B7DC
      AC005CB043005CB043005CB0430097CD87000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000DDEF
      D8005CB043006DB8570000000000000000000DB7EB0050CAEE0069D7F00041CC
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF00A1E5F700000000000000000000000000988A8500604A4200604A42006245
      3B0064473C0023AAD2000FC7FD0011B8EB000BB7EA0014BAEB0012B9EB0012B9
      EB0015BBEB000AB6EA0000ACE60005B1E8000EB6EA0000AEE70014B9EB0018BB
      EB0016BAEB0016BAEB0016BAEB0016BAEB0014BBED000FC8FF004E6A72006A39
      2800604A4200604A4200604A420097888300D5845800CB734100CC734100CC73
      4100CB724000C8693200E6B9A000EDCFBC00CF7D4D00CF7D4D00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D99A7600CC744300EDCEBB00E7BFA900C86A3400CB72
      4000CC734100CC734100CB734100D58458000000000000000000000000000000
      0000DDEFD80076BC60005CB043008DC87B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F3F9F2005CB0430088C57600000000000CB5EB0076D3EF009CE1F2002FC8
      EE004BCEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF005ED3F100000000000000000000000000988A8500604A4200604A42006245
      3B0064473C0023AAD20000C0FC0029C0ED00F9FDFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00E0F6FC0011B9EB000AB7EA0016BAEB0016BAEB0016BAEB0016BA
      EB0016BAEB0016BAEB0016BAEB0016BAEB0014BBED000FC8FF004E6A72006A39
      2800604A4200604A4200604A420097888300D7895A00CE764300CF764200CF76
      4200CC713C00DA9B7800FFFFFF00FFFFFF00EECFBD00C7622700EECFBD00F0D5
      C700F0D4C500F0D4C500F0D4C500F0D4C500F0D4C500F0D4C500F0D4C500F0D4
      C500F0D5C600F0D6C700CB6D3700E8BFA800FFFFFF00FFFFFF00E0A98900CC6F
      3900CF764200CF764200CE764300D7895A000000000000000000000000000000
      000000000000FEFEFE0087C575007BBF6700FEFFFE0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D0E8C8005CB04300DEEFD9000DB5EB0075D2EF00D2EDF40037CA
      EE0049CEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF00D5F4FB000000000000000000988A8500604A4200604A42006245
      3B0065473C0023ACD30007C7FF0017BDED0059D0F30066D4F50060D2F40060D2
      F40069D5F50050CDF30011BBED0012BBED0015BCED0015BCED0015BCED0015BC
      ED0015BCED0015BCED0015BCED0015BCED0013BDEF000ECAFF004E6B72006B38
      2800604A4200604A4200604A420097888300DA8C5E00D0784600D0794600D079
      4600CE723C00E5B39700FFFFFF00FFFFFF00F9F2ED00D4855600D4845500D483
      5400D4835400D4835400D4835400D4835400D4835400D4835400D4835400D483
      5400D4835400D4845500D4845500F5E6DD00FFFFFF00FFFFFF00EAC4AE00CD6F
      3A00D0794600D0794600D0784600DA8C5E000000000000000000000000000000
      0000000000000000000000000000E2F1DE00FDFEFD0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000066B54F0080C26D000DB5EB0062CEEE00FCF8F6005DD2
      F00039CAEE004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF008FE1F5000000000000000000988A8500604A4200604A42006345
      3A0065463C001CB6E30004D6FF000CC8FF0000BFFE0000BDFD0000BEFD0000BE
      FD0000BDFD0001C0FE000DC9FF000EC8FF000DC8FF000DC8FF000DC8FF000DC8
      FF000DC8FF000DC8FF000DC8FF000DC8FF000BC9FF0005D8FF004C6F78006C36
      2500604A4200604A4200604A420097888300DC906200D37B4700D47C4800D47C
      4800D1723C00ECC6B000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F1D5C400D071
      3A00D47C4800D47C4800D37B4700DC9062000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000A2D293005CB043000DB5EB0059CCEE00FFFDF60090DE
      F2002BC7EE004BCEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF0052D0F0000000000000000000988A8500604A4200604A42006148
      4000614940004F69700049727E004B6E78004B6E78004B6E78004B6E78004B6E
      78004B6E78004B6E78004B6E78004B6E78004B6E78004B6E78004B6E78004B6E
      78004B6E78004B6E78004B6E78004B6E78004B6E790049737F005B5451006344
      3A00604A4200604A4200604A420097888300DF926500D57E4900D67F4A00D67F
      4A00D2753C00F2D7C800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F6E3D700D273
      3A00D67F4A00D67F4A00D57E4900DF9265000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000B9DDAE005CB043000DB5EB0059CCEE00FFFBF600C4EA
      F3003DCBEE0046CDEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF00C3EFFA0000000000988A8500604A4200604A4200604B
      43005F4B43006A3B2A006D3623006C3826006C3826006C3826006C3826006C38
      26006C3826006C3826006C3826006C3826006C3826006C3826006C3826006C38
      26006C3826006C3826006C3826006C3826006C3826006D36230063453A005E4D
      4600604A4200604A4200604A420097888300E1956700D7804B00D8814C00D881
      4C00D4753B00F7E6DB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F9EDE700D375
      3B00D8814C00D8814C00D7804B00E19567000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E1F0DC00A3D295000DB5EB005ACCEE00FCF7F500EEF3
      F50067D4F00034C9EE004BCEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF007CDCF30000000000988A8500604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A420097888300E3976A00D9824D00DA834E00DA83
      4E00D6773D00FAF0EA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBF6F200D576
      3C00DA834E00DA834E00D9824D00E3976A00A3D29500E1F0DC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000DB5EB005ACCEE00F6F6F500FEF7
      F5009BE0F2002CC7EE004BCEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF0000000000988A8500604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A420097888300E49A6C00DB844F00DC855000DC85
      5000D8793F00FBF5F100FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FDF8F600D878
      3E00DC855000DC855000DB844F00E49A6B005CB04300B9DDAE00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000DB5EB005ACCEE00F7F6F500EFF4
      F500CEECF40046CDEF0042CCEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACEEF004ACE
      EF004ACEEF004ACEEF004ACEEF00B0EAF800988A8500604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A4200604A4200604A4200604A4200604A4200604A
      4200604A4200604A4200604A420097888300E69D6E00DD864F00DE875000DE87
      5000DB7C4200F7E7DD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F8EBE200DB7C
      4100DE875000DE875000DD864F00E69D6E005CB04300A2D29300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000DB5EB005ACCEE00F7F6F500E0F0
      F400F5F4F50072D7F00026C6ED0046CEEF0047CEF00043CCEF0042CCEE0045CE
      F00046CEF00043CCEF0042CCEE0046CEF00046CEF00042CCEE0043CCEF0046CE
      F00045CEF00042CCEE0043CCEF0047CEF00045CDEF0042CCEE0043CCEF0043CC
      EF0042CCEF0048CDEF004BCEEF005CD3F100988A8500604A4200604A4200604A
      4200604A4200614C44005C453D00573F37005841390058413900584139005841
      39005841390058413900584139005841390059423A005B433B005B433B005B43
      3B005B433B005B433B005B433B005B423A005F494100614B4300604A4200604A
      4200604A4200604A4200604A420097888300E79E7100DE885100DE895300DE89
      5300DD854D00E49D7100FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E49D7100DD85
      4D00DE895300DE895300DE885100E79E710080C26D0066B54F00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FDFEFD00E2F1DE0000000000000000000000
      0000000000000000000000000000000000000DB5EB005ACCEE00F7F6F500DDF0
      F400F7F5F500B3E6F30037C9EE0044CDEF0049CFF00046CDEF0046CDEF0048CE
      F00048CEF00046CDEF0046CDEF0049CEF00049CEF00046CDEF0046CDEF0048CE
      F00048CEF00046CDEF0046CDEF0049CFF00048CEEF0046CDEF0046CDEF0047CD
      EF0047CDEF0039CAEE0044CDEF005ED4F100988A8500604A4200604A4200604A
      4200604A4200604A42005F4941005F4941005F4941005F4941005F4941005F49
      41005F4941005F4941005F4941005F494100614B43005E4840005E4840005E48
      40005E4840005E4840005E4840005E484000604A4200604A4200604A4200604A
      4200604A4200604A4200604A420097888300E9A17300E0895300E18B5500E18B
      5500E18B5500DF864F00DD7E4400DE804700DE804700DD804500DB743400DB73
      3300DB733300DB733300DB733300DB733300DB733300DB733300DB733300DB73
      3300DB733300DB743400DD7E4300DE804700DE804700DD7E4300DF864F00E18B
      5500E18B5500E18B5500E0895300E9A17300DEEFD9005CB04300D0E8C8000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FEFFFE007BBF670087C57500FEFEFE000000
      0000000000000000000000000000000000000DB4EA0061CEEF00FFFEFA00EBF8
      FA00E8F5F900E4F1F400D5F1F800A4D8E60082C5D800C8EBF400D5F2F9009AD2
      E20088C8DB00CFEFF700D3F1F90090CCDE0090CCDE00D3F1F900CFEFF70088C8
      DB009AD2E200D5F2F900C8EBF40082C5D800A6D9E700D1F1F800C5EAF300C5EA
      F300D6EEF400D7F3FA00DCF6FC0000000000988A8500604A4200604A4200604A
      4200604A42004A312800A1958E00F0F1EB00DAD7D100DAD7D100DAD7D100DAD7
      D100DAD7D100DAD7D100D9D6D000E2DED800CBC9C400B3B3AF00BCBCB900BDBD
      BA00BDBDBA00BDBDBA00BCBCB800BFC0BC0073615A00553C3300604A4200604A
      4200604A4200604A4200604A420097888300E9A37600E18C5400E18D5500E18D
      5500E18D5500E18D5500E18D5500E18C5500E18B5300E1895200FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00E59A6A00E08A5100E18C5500E18D5500E18D5500E18D
      5500E18D5500E18D5500E18C5400E9A375000000000088C576005CB04300F3F9
      F200000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008DC87B005CB0430076BC6000DDEF
      D800000000000000000000000000000000000DB7EC0053C9EB00EDEAE900CAE4
      EB00C7E5ED00DDEFF400FFFEFD00C1DAE2008ABBCC00F2F5F600FFFFFD00AED0
      DB0092C1D000FBFAFA00FFFEFD009EC7D5009EC7D500FFFEFD00FBFAFA0092C1
      D000AED0DB00FFFFFD00F2F5F6008ABBCC00C0DAE20000000000000000000000
      000000000000000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200442A2100B3AAA400FFFFFF00FCFDF900FCFDF900FCFDF900FCFD
      F900FCFDF900FCFDF900FFFFFC00FCFDF900D5DAD800CED5D300D7DEDB00D7DE
      DB00D7DEDB00D7DEDB00D6DDDB00DAE2E1007868620051382F00604A4200604A
      4200604A4200604A4200604A420097888300EBA47800E38C5600E48D5800E48D
      5800E48D5800E48D5800E48D5800E48D5800E38B5400E5976700FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00ECAE8900E2895100E48D5800E48D5800E48D5800E48D
      5800E48D5800E48D5800E38C5600EBA4780000000000000000006DB857005CB0
      4300DDEFD8000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000097CD87005CB043005CB043005CB0
      4300B7DCAC000000000000000000000000001FBEED000AB8EC0059B9D70091B8
      C50089BFD100D8EEF300E7F5F800CFE8EF00C0DFE900DEF0F500E2F3F700CAE5
      ED00C2E1EA00E0F1F600E2F2F700C6E3EB00C6E3EB00E2F2F700E0F1F600C2E1
      EA00CAE5ED00E2F3F700DEF0F500C0DFE900CFE8EF00E1F2F600DCEFF400DCEF
      F400DAEEF400000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700EDECE700EDEC
      E700EDECE700ECECE700F6F4EE00DADBD700C3C8C600C7CAC7007E706A005E48
      3F005D473E00705E5700BDBEBA00D8DFDD0076655E00533A3100604A4200604A
      4200604A4200604A4200604A420097888300ECA67900E58E5700E6905800E690
      5800E6905800E6905800E6905800E6905800E58D5500E7986600FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00ECAF8800E48B5200E6905800E6905800E6905800E690
      5800E6905800E6905800E58E5700ECA679000000000000000000FBFDFB007EC0
      6A005CB0430086C47400C9E5C000EAF5E700F3F9F200F4FAF200F4FAF200F4FA
      F200F4FAF200F4FAF200F4FAF200F4FAF200F4FAF200F4FAF200F4FAF200F4FA
      F200F4FAF200F4FAF200F4FAF200F3F9F2008EC87D005CB043005CB043005CB0
      43005CB043008EC87D00EEF7EC000000000024BEEC000BB9ED0000B8EF0057B8
      D600A6C3CD00E5F1F300EBF4F600EDF5F700F4F9FA00E6F2F400E4F0F300EFF7
      F800F4F9F900E3F0F400D9EDF300E6F5F800E7F5F800D9EDF300DAEEF300E8F6
      F900E4F4F700D9EDF300DBEFF400E9F6F900E2F2F700DAEEF300DCEFF400DCEF
      F400DCEFF400000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700EDECE700EDEC
      E700EDECE700F0EFEA00EEECE800C7CAC700CACFCC00C7CAC700563E36006B57
      500080726B004A2F2600B7B6B200DBE3E10076655E00533A3100604A4200604A
      4200604A4200604A4200604A420097888300EDA87D00E68F5900E7905B00E790
      5B00E7905B00E7905B00E7905B00E7905B00E68E5700E89B6900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00ECB18B00E58C5400E7905B00E7905B00E7905B00E790
      5B00E7905B00E7905B00E68F5900EDA87D000000000000000000000000000000
      0000BEE0B50069B752005CB043005CB043005CB043005CB043005CB043005CB0
      43005CB043005CB043005CB043005CB043005CB043005CB043005CB043005CB0
      43005CB043005CB043005CB043005CB043005CB043005CB043005CB043005CB0
      43005CB043005CB043005FB14600EEF7EC0022BEEC0018BAEA000BB9ED0000B5
      ED0068C2DE00E9EFF000E5F3F600DEF0F400DEF0F400DEF0F400DEF0F400DEF0
      F400DDEFF400E4F1F400E1F1F400DAEFF400DCEFF400DCEFF400DCEFF400DCEF
      F400DCEFF400DCEFF400DCEFF400DCEFF400DCEFF400DCEFF400DCEFF400DCEF
      F400DCEFF400000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700EDECE700EDEC
      E700ECECE700F6F4EE00DBDCD800BEC2C000CDD1CF00C7CAC600553C3400A8A4
      A000D1D7D50052383000B7B6B200DAE2DF0076655E00533A3100604A4200604A
      4200604A4200604A4200604A420096878200EEA97D00E7915900E8935C00E893
      5C00E8935C00E8935C00E8935C00E8935C00E7915900E7905A00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00EBA27300E7905700E8935C00E8935C00E8935C00E893
      5C00E8935C00E8935C00E7915900EEA97E000000000000000000000000000000
      00000000000000000000E9F4E600CDE7C500C3E2BA00C2E2B900C3E2BA00C3E2
      BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2BA00C3E2
      BA00C3E2BA00C3E2BA00C3E2BA00C4E2BA007EC06A005CB043005CB043005CB0
      43005CB0430069B75200C1E1B700F9FCF80022BEEC0016BAEB0018BAEA000DB9
      ED000EBAEE0035C2EB0034C3EC0033C2EC0033C2EC0033C2EC0033C2EC0033C2
      EC001FBCEB009DE2F50000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700EDECE700EDEC
      E700F0EFE900EEEDE800C8CBC800C3C7C400CDD1CE00C7CAC600584038009C94
      8F00BFC0BD00533A3200B7B7B300DAE2DF0076655E00533A3100604A4200604A
      4200604A4200604A4200604A4200A89C9700EFAF8600E8925A00E8945C00E894
      5C00E8945C00E8945C00E8945C00E8945C00E8945C00E8925A00E7894D00E78B
      5000E78B4F00E78B4F00E78B4F00E78B4F00E78B4F00E78B4F00E78B4F00E78B
      4F00E78B4F00E78A4D00E7915800E8945C00E8945C00E8945C00E8945C00E894
      5C00E8945C00E8945C00E8925A00EFAE85000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009BCE8B005CB043005CB043005CB0
      43008DC87C00F3F9F100000000000000000022BEEC0016BAEB0016BAEB0018BB
      EB0012B9EB0000B4EA0000B4EA0001B4EA0001B4EA0001B4EA0001B4EA0001B4
      EA0030C0EE000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700EDECE700ECEB
      E600F6F4EE00DCDDD900BEC2C000C7CAC700CDD1CE00C7CAC600553C3400A8A3
      9F00D0D5D30052383000B7B6B200DAE2DF0076655E00533A3100604A4200604A
      4200604A4200604A42008F807A0000000000F3C4A700EA925B00EB955F00EB95
      5F00EB955F00EB955F00EB955F00EB955F00EB955F00EB955F00EB945E00EB94
      5E00EB945E00EB945E00EB945E00EB945E00EB945E00EB945E00EB945E00EB94
      5E00EB945E00EB945E00EB955F00EB955F00EB955F00EB955F00EB955F00EB95
      5F00EB955F00EB955F00EA925C00F3C4A6000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000094CB84005CB043005CB04300B5DB
      AA000000000000000000000000000000000016BAEB0016BAEB0016BAEB0016BA
      EB0016BAEB0016BAEB0016BAEB0016BAEB0016BAEB0016BAEB0016BAEB0016BA
      EB00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700EDECE700F0EF
      EA00EEEDE800C8CBC800C3C7C400C7CAC700CDD2CF00C7C9C600583F37007664
      5D008E827C004D322900B7B6B200DBE3E10076655E00533A3100604A4200604A
      4200604A42008D7D77000000000000000000FBECE200EB976000EC955F00EC95
      6000EC956000EC956000EC956000EC956000EC956000EC956000EC956000EC95
      6000EC956000EC956000EC956000EC956000EC956000EC956000EC956000EC95
      6000EC956000EC956000EC956000EC956000EC956000EC956000EC956000EC95
      6000EC956000EC955F00EB976000FBECE2000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000073BB5E0064B44D00DCEED7000000
      00000000000000000000000000000000000059CEF10028BFED0029C0ED0029C0
      ED0029C0ED0029C0ED0029C0ED0029C0ED0029C0ED0028BFED0029C0ED00AEE7
      F800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000988A8500604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700ECECE700F6F4
      EE00DADBD700BEC2C000C8CBC700C7CAC700CCD0CE00C7CAC70076655E00563D
      3500563E360066514A00BCBCB900D9E0DE0076655E00533A3100604A4200604A
      42008E7E780000000000000000000000000000000000F3C4A600EC935C00ED97
      5F00ED986100ED986100ED986100ED986100ED986100ED986100ED986100ED98
      6100ED986100ED986100ED986100ED986100ED986100ED986100ED986100ED98
      6100ED986100ED986100ED986100ED986100ED986100ED986100ED986100ED98
      6100ED975F00EC945C00F3C4A600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FDFEFD00C0E1B700ECF6EA00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000097898400604A4200604A4200604A
      4200604A4200472D2400ABA19A00FFFFFF00EDECE700EDECE700F0EFEA00EDEC
      E700C7CAC700C4C7C400C7CAC700C7CAC700C7CAC700C7CAC700C5C7C400C4C6
      C300C4C6C300C5C7C400CACDCA00CFD4D10076655E00533A3100604A42008F80
      7A00000000000000000000000000000000000000000000000000F4C5A700ED99
      6300EE965E00EE975F00EE975F00EE975F00EE975F00EE975F00EE975F00EE97
      5F00EE975F00EE975F00EE975F00EE975F00EE975F00EE975F00EE975F00EE97
      5F00EE975F00EE975F00EE975F00EE975F00EE975F00EE975F00EE975F00EE96
      5E00ED996400F4C5A70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009D908B00604A420068534C006853
      4C0068534C0050382F00AFA69F00FFFFFF00EEEDE800EEEDE800F5F3EE00DBDC
      D800C2C6C400CACDCA00CACDCA00CACDCA00CACDCA00CACDCA00D0D4D100D1D6
      D300D0D5D200D0D5D200CED1CF00D0D5D2007D6D6600533A31008F7F7A000000
      000000000000000000000000000000000000000000000000000000000000FBED
      E400F5C8AC00F2B58E00F1B08700F1B08900F1B08900F1B08900F1B08900F1B0
      8900F1B08900F1B08900F1B08900F1B08900F1B08900F1B08900F1B08900F1B0
      8900F1B08900F1B08900F1B08900F1B08900F1B08900F1B08700F2B58E00F5C8
      AC00FBEDE4000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000080000000600000000100010000000000000600000000000000000000
      000000000000000000000000FFFFFF000FFFFFFF8FFFFFFF0000000000000000
      07FFFFFF07FFFFFF000000000000000003FFFFFF03FFFFFF0000000000000000
      01FFFFFF01FFFFFF000000000000000080FFFFFF80FFFFFF0000000000000000
      C07FFFFFC07FFFFF0000000000000000E03FFFFFE03FFFFF0000000000000000
      F01FFFFFF01FFFFF0000000000000000F80FFFFFF80FFFFF0000000000000000
      FC07FFFFFC07FFFF0000000000000000FE03FFFFFE03FFFF0000000000000000
      FF01FFFFFF01FFFF0000000000000000FF80FFFFFF80FFFF0000000000000000
      FFC07CFFFFC07CFF0000000000000000FFE03CFFFFE03CFF0000000000000000
      FFF01CFFFFF01CFF0000000000000000FFF80CF3FFF80CF30000000000000000
      FFFC04E3FFFC04E30000000000000000FFFE00C7FFFE00C70000000000000000
      FFFF018FFFFF018F0000000000000000FFFF809FFFFF809F0000000000000000
      FFFFE07FFFFFE07F0000000000000000FFF80040FFF800400000000000000000
      FFF81840FFF818400000000000000000FFFFF8FFFFFFF8FF0000000000000000
      FFFFE79FFFFFE79F0000000000000000FFFFC78FFFFFC78F0000000000000000
      FFFF8CC7FFFF8CC70000000000000000FFFF1CE3FFFF1CE30000000000000000
      FFFF3CF3FFFF3CF30000000000000000FFFFFCFFFFFFFCFF0000000000000000
      FFFFFCFFFFFFFCFF0000000000000000FFC003FFFFE007FFFFFFFFFFFFFFFFFF
      FF0000FFFF8001FFFFFFFFFFFF87E1FFFE00007FFE00007FFFFE3FFFFF03C0FF
      F800001FFC00003FFFFE3FFFFF0180FFF000000FF000000FFFFE3FFFFF0180FF
      E0000007F000000FFFFE3FFFFF0180FFE0000007E0000007FFFE3FFFFF03C0FF
      C0000003C0000003FFFE3FFFFF87E1FF80000001C0000003F0000007F800001F
      8000000180000001C0000003F800001F000000008000000180000001FE00003F
      000000000000000000000000FC0000FF000000000000000000000000F000007F
      000000000000000000000000F000003F000000000000000000000000E000003F
      000000000000000000000000E000003F000000000000000000000000E000003F
      000000000000000000000000C000001F000000000000000000000001C000001F
      000000000000000080000001C000001F0000000000000000C00000078000001F
      8000000180000001E000000F8000000F8000000180000001E000001F8000000F
      C0000003C0000003E000001F0000000FC0000003C0000003F000001F0000000F
      E0000007E0000007F800003F00000007F000000FF000000FFE00007F00000007
      F800001FF000000FFFF0007F0000000FFC00003FFC00003FFFF801FFFFFFFF9F
      FE00007FFE00007FFFFE07FFFFFFFF80FF0000FFFF0000FFFFFFFFFFFFFFFFC0
      FFE007FFFFE007FFFFFFFFFFFFFFFFFF00000000E0000007FFFFFFFFFFFFFFFF
      00000000C0000003FFFFFFFFFFFFFFFF0000000080000001FC7FFFFFFFFFFFFF
      0000000000000000F8FFFFFF0000001F0000000000000000F0FFFFFF0000001F
      0000000000000000C0FFFFFF0000001F00000000000000000000003F0000000F
      00000000000000000000000F0000000F0000000000000000800000030000000F
      0000000000000000E0FFFFE3000000070000000000000000F0FFFFF100000007
      0000000000000000F87FFFF8000000030000000000000000FE7FFFFC00000003
      0000000000000000FFFFFFFC000000030000000000000000FFFFFFFC00000001
      0000000000000000FFFFFFFC0000000100000000000000003FFFFFFF00000001
      00000000000000003FFFFFFF0000000000000000000000003FFFFFFF00000000
      00000000000000003FFFFE7F0000000000000000000000001FFFFE1F00000001
      00000000000000008FFFFF0F0000007F0000000000000000C7FFFF0700000007
      0000000000000000C0000001000000070000000000000000F000000000000007
      0000000000000000FC0000000003FFFF0000000000000000FFFFFF030007FFFF
      0000000100000000FFFFFF0F000FFFFF0000000300000000FFFFFF1F000FFFFF
      0000000780000001FFFFFE3FFFFFFFFF0000000FC0000003FFFFFFFFFFFFFFFF
      0000001FE0000007FFFFFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object puCustomReport: TPopupMenu
    Left = 617
    Top = 65534
    object miCustomReport: TMenuItem
      Caption = '.'
      OnClick = miCustomReportClick
    end
    object N25: TMenuItem
      Caption = '-'
    end
    object miOpenCustomReport: TMenuItem
      Caption = '.'
      OnClick = miOpenCustomReportClick
    end
  end
  object ilNavToolbar_On: TImageList
    Left = 1034
    Top = 52
    Bitmap = {
      494C010107000900280910001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      00000000000000000000000000000000000000000000369DD9003199D8002C94
      D7002890D600238CD5001E88D4001A84D3001580D200117CD1000E79D1000A76
      D0000773CF000470CF00016ECE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003DA3DA00BCEBFA00BCEB
      FC00BFEEFE00C6F4FF00CEF8FF00D3FAFF00D0F8FF00C7F2FF00BAE9FC00B3E4
      F900B0E2F800B0E2F8000571CF00000000000000000000000000000000000000
      0000C5C5C500A5A5A500A1A1A100ABABAB00A7A7A7009595950098989800BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000BFDBFF00A0B7E9009CB3E300A6BEF100A2B9EB0091A5D20093A9D600B9D4
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000043A8DB00BFECFB0059CF
      F50041B0EC004EBAEF005AC2EF0060C6EF005CC4EF004CB6EF0037A5E6002A9A
      E10038B8EE00B1E3F8000975D00000000000000000000000000000000000A9A9
      A900CECECE00EDEDED00F4F4F400F5F5F500F4F4F400EFEFEF00E2E2E200BABA
      BA0095959500000000000000000000000000000000000000000000000000A4BC
      EE00C8E5FF00E6FFFF00EDFFFF00EEFFFF00EDFFFF00E8FFFF00DBFBFF00B4CE
      FF0091A5D2000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000049ADDC00C1EEFB005FD3
      F7006CDBFC007FE5FF008FEDFF0097F2FF0093EDFF007CDFFF005BCCF80046BE
      EF003CBAEE00B3E3F9000E79D100000000000000000000000000B0B0B000DEDE
      DE00F3F3F300DBDBDB00D2D2D200DBDBDB00D6D6D600C0C0C000C9C9C900E6E6
      E600C4C4C4009595950000000000000000000000000000000000ABC3F800D7F6
      FF00ECFFFF00D4F3FF00CCE9FF00D4F3FF00D0EEFF00BAD5FF00C3DFFF00DFFF
      FF00BEDAFF0091A5D20000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000004EB2DD00C3EFFB0065D6
      F8004CB6EC005ABDEF0095EBFF003097DD004D82AB0084E1FF0041A9E900329F
      E10042BEEF00B4E5F900137ED200000000000000000000000000B3B3B300F0F0
      F000DEDEDE00D4D4D400D2D2D200DBDBDB00D6D6D600BFBFBF00B0B0B000B3B3
      B300DEDEDE009999990000000000000000000000000000000000AEC7FC00E9FF
      FF00D7F6FF00CEEBFF00CCE9FF00D4F3FF00D0EEFF00B9D4FF00ABC3F800AEC7
      FC00D7F6FF0094AAD80000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000053B7DE00C6F0FC006AD9
      F8007CE2FD0090E8FF0099E9FF00329FDF00548BB2008AE2FF006AD0F90050C5
      F10046C1F000B6E7F9001883D300000000000000000000000000B5B5B500F2F2
      F200E2E2E200D8D8D800D5D5D500DCDCDC00D8D8D800C0C0C000B3B3B300B7B7
      B700E0E0E0009F9F9F0000000000000000000000000000000000B0C9FF00EBFF
      FF00DBFBFF00D2F0FF00CFECFF00D5F4FF00D2F0FF00BAD5FF00AEC7FC00B2CB
      FF00D9F9FF009AB0E00000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000058BBDF00C7F1FC006FDC
      F90056BBED0061BDEF009BE7FF0035A6E2004BA4E10090E2FF0049ADE90038A4
      E30049C4F000B8E8F9001E88D400000000000000000000000000B7B7B700F3F3
      F300E7E7E700DDDDDD00D9D9D900E0E0E000DBDBDB00C4C4C400B8B8B800BBBB
      BB00E1E1E100A3A3A30000000000000000000000000000000000B2CBFF00ECFF
      FF00E0FFFF00D6F5FF00D2F1FF00D9F9FF00D4F3FF00BEDAFF00B2CCFF00B5D0
      FF00DAFAFF009EB5E60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000005CBFE000C8F3FC0075DF
      F90089E6FD0095E7FF009AE5FF00AAEEFF00A8EDFF0099E3FF0074D5F90059CC
      F3004FC8F100BBE9FA00248DD500000000000000000000000000B8B8B800F4F4
      F400EAEAEA00E1E1E100DDDDDD00E3E3E300DEDEDE00C9C9C900BDBDBD00BFBF
      BF00E2E2E200A6A6A60000000000000000000000000000000000B2CCFF00EDFF
      FF00E3FFFF00DAFAFF00D6F5FF00DCFCFF00D7F6FF00C3DFFF00B7D2FF00B9D4
      FF00DBFBFF00A1B8EA0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000060C2E100C9F3FC00CBF3
      FD00D4F6FE00D7F6FF00D8F4FF00E0F8FF00DFF8FF00DAF5FF00CDF1FC00C2ED
      FA00BDEBFA00BDEBFA002B93D600000000000000000000000000BABABA00F5F5
      F500EEEEEE00E6E6E600E2E2E200E6E6E600E1E1E100CDCDCD00C2C2C200C2C2
      C200E3E3E300A8A8A80000000000000000000000000000000000B4CEFF00EEFF
      FF00E7FFFF00DFFFFF00DBFBFF00DFFFFF00DAFAFF00C7E4FF00BCD7FF00BCD7
      FF00DCFCFF00A3BAED0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000061C3E10088A0A8009191
      91008E8E8E005AB9DC0055B8DF0051B5DE004DB1DD0049ADDC0046A8D7007878
      780076767600657E8D003199D800000000000000000000000000BBBBBB00F6F6
      F600EBEBEB00DEDEDE00D6D6D600D5D5D500D1D1D100C3C3C300BCBCBC00C0C0
      C000E5E5E500ABABAB0000000000000000000000000000000000B5D0FF00EFFF
      FF00E4FFFF00D7F6FF00D0EEFF00CFECFF00CBE8FF00BDD8FF00B6D1FF00BAD5
      FF00DEFEFF00A6BEF10000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B1B1B100C6C6
      C600949494000000000000000000000000000000000000000000000000007D7D
      7D00ABABAB009696960000000000000000000000000000000000BDBDBD00F7F7
      F700E7E7E700EFEFEF00F6F6F600FBFBFB00FAFAFA00F0F0F000DEDEDE00C3C3
      C300E6E6E600ACACAC0000000000000000000000000000000000B7D2FF00F0FF
      FF00E0FFFF00E8FFFF00EFFFFF00F3FFFF00F3FFFF00E9FFFF00D7F6FF00BDD8
      FF00DFFFFF00A7BFF30000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000BCBCBC00C4C4
      C400A1A1A1000000000000000000000000000000000000000000000000008989
      8900A9A9A900A4A4A40000000000000000000000000000000000BFBFBF00F8F8
      F800FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBFB
      FB00EAEAEA00AEAEAE0000000000000000000000000000000000B9D4FF00F1FF
      FF00F6FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F3FF
      FF00E3FFFF00A9C1F50000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000D4D4D400BABA
      BA00BFBFBF00A6A6A6000000000000000000000000000000000093939300A8A8
      A8009E9E9E00C3C3C30000000000000000000000000000000000CBCBCB00E1E1
      E100FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FBFB
      FB00CFCFCF00C9C9C90000000000000000000000000000000000C5E1FF00DAFA
      FF00F6FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F7FFFF00F3FF
      FF00C9E6FF00C3DFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000AEAE
      AE00C4C4C400BEBEBE00A1A1A100969696009393930097979700AEAEAE00AEAE
      AE0095959500000000000000000000000000000000000000000000000000C7C7
      C700D0D0D000E8E8E800F3F3F300FDFDFD00FCFCFC00EDEDED00E0E0E000C2C2
      C200C0C0C000000000000000000000000000000000000000000000000000C1DD
      FF00CAE7FF00E1FFFF00ECFFFF00F5FFFF00F4FFFF00E6FFFF00D9F9FF00BCD7
      FF00BAD5FF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000EEEE
      EE00AEAEAE00BCBCBC00CACACA00CCCCCC00CACACA00C2C2C200ADADAD009B9B
      9B00E9E9E9000000000000000000000000000000000000000000000000000000
      000000000000D0D0D000C3C3C300B8B8B800B8B8B800C3C3C300CDCDCD000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CAE7FF00BDD8FF00B2CCFF00B2CCFF00BDD8FF00C7E4FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D0D0D000BABABA00B1B1B100AEAEAE00B3B3B300C9C9C9000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000AAAAAA00A7A7A700A3A3
      A300A0A0A0009D9D9D009A9A9A00989898009595950092929200909090008E8E
      8E008C8C8C008B8B8B0089898900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007AB98000579E5E00619C66004678
      4A0059755B007C7C7C0087878700898989008B8B8B008C8C8C00696969005C7D
      5F0048864E00609964003A7B3E00598A5B0000000000AEAEAE00ECECEC00EDED
      ED00F0F0F000F5F5F500F8F8F800F9F9F900F8F8F800F3F3F300EBEBEB00E7E7
      E700E5E5E500E5E5E5008B8B8B00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000006AB9730066B4700072BF7D0062B4
      6D005E916200E5E5E50082828200A9A9A900ACACAC0089898900E2E2E20076BC
      7E0084CA8F0074C1800055A45E003376380000000000B2B2B200EEEEEE00D4D4
      D400BCBCBC00C4C4C400CACACA00CDCDCD00CBCBCB00C1C1C100B3B3B300AAAA
      AA00C2C2C200E6E6E6008E8E8E00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E2F3E500C3E3C7007CBA8200528E
      5800A2C1A400F0F0F0007E7E7E00A4A4A400A6A6A60085858500F0F0F000A1D6
      A80059AF62006AAE7200A0C8A400C0D7C20000000000B5B5B500EFEFEF00D8D8
      D800DFDFDF00E7E7E700EEEEEE00F1F1F100EEEEEE00E3E3E300D3D3D300C6C6
      C600C3C3C300E6E6E60090909000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000005F8E
      6100FAFBFA00000000000000000000000000000000000000000000000000FBFD
      FB007AB580000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008B8B
      8B00F0F0F000EFEFEF007B7B7B009E9E9E00A1A1A10081818100EFEFEF00F4F4
      F40071717100E5E5E500000000000000000000000000BABABA00F0F0F000DADA
      DA00C0C0C000C6C6C600ECECEC00A7A7A7008B8B8B00E4E4E400B7B7B700AEAE
      AE00C6C6C600E8E8E80093939300000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000D0E0D1002C6E
      3000427A45000000000000000000000000000000000000000000000000006DB6
      740053A45B00D7E9D80000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009090
      9000F1F1F100EFEFEF0077777700999999009C9C9C007C7C7C00EFEFEF00F4F4
      F40076767600E6E6E600000000000000000000000000BDBDBD00F1F1F100DCDC
      DC00E5E5E500EAEAEA00EBEBEB00ADADAD0093939300E5E5E500D6D6D600CCCC
      CC00C8C8C800E9E9E90097979700000000000000000061BE6D005DB8680058B1
      620053A95C004DA1560047994F00419149003B88420035803B003F88450059A1
      5E00448B49004B804D00000000000000000000000000000000007BC5840071BE
      7B007AC183005BAA640047994F00419149003B88420035803B002F7835002A70
      2F0025692900216324001D5E20000000000000000000C7DBEA00679CC3008D8F
      9100F6F6F600EFEFEF0074747400767676007777770078787800EFEFEF00F4F4
      F4008A8B8D004E618E00C1C9D9000000000000000000C0C0C000F2F2F200DFDF
      DF00C4C4C400C6C6C600EAEAEA00B2B2B200B1B1B100E5E5E500B9B9B900B1B1
      B100CACACA00EAEAEA009A9A9A00000000000000000065C37100A0D7A9009CD5
      A50098D3A10094D09D0090CE98008BCB930087C98E0082C689007EC384007AC1
      800076BE7C00458C4A0054875700000000000000000089D192007BC886009CD5
      A50098D3A10094D09D0090CE98008BCB930087C98E0082C689007EC384007AC1
      800076BE7C0072BD78002163240000000000C7DCEC003B85BB005796C2003F80
      B300DCDEE000EDEDED00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00DFE1
      E3002D4B81003A5F900027407A00C1C9D90000000000C3C3C300F3F3F300E1E1
      E100E8E8E800E9E9E900E8E8E800EFEFEF00EFEFEF00E7E7E700DADADA00D2D2
      D200CDCDCD00EBEBEB009E9E9E00000000000000000068C77400A5DAAE00A2D8
      AB009ED6A7009AD4A30096D29F0093CF9A008ECC950089CA900085C78B0081C5
      87007DC282004A91500053895600000000000000000088D391007FCC8A00A2D8
      AB009ED6A7009AD4A30096D29F0093CF9A008ECC950089CA900085C78B0081C5
      87007DC2820078C07E002569290000000000629BCA005395C6007AAFD3005797
      C4004387BA00CDCFD000EEEEEE00EFEFEF00EFEFEF00EFEFEF00D9DADB003864
      970044709F005C8CB1003C649400566B970000000000C6C6C600F3F3F300F3F3
      F300F6F6F600F7F7F700F6F6F600F9F9F900F9F9F900F6F6F600A6A6A600A6A6
      A600A6A6A600ECECEC00A2A2A200000000000000000068C7740068C7740065C3
      710061BE6D005DB8680058B1620053A95C004DA1560047994F00419149005AA3
      6200559D5C00559059000000000000000000000000000000000083D18D0080CD
      8B007CC987005DB8680058B1620053A95C004DA1560047994F00419149003B88
      420035803B002F7835002A702F0000000000FAFCFD003F85BE005293C60079AE
      D3005597C4004287BA00CACBCC00EDEDED00EFEFEF00D9DBDC003D76A6004D80
      AE006B9ABD004775A200395D9100FAFBFC0000000000C6C6C600939393009191
      91008E8E8E00BEBEBE00BEBEBE00BCBCBC00B9B9B900B5B5B500C8C8C800DDDD
      DD00BFBFBF00A7A7A700A7A7A700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004794
      4F0057995D000000000000000000000000000000000000000000000000007DCF
      88006AC575000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FAFCFD003E81BE005091
      C60076ADD3005495C6004189BC00D2D4D500D2D4D5004183B400558DBB0077A5
      C7005084B2003E70A300FAFBFD0000000000000000000000000097979700B9B9
      B9009A9A9A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000078B4
      7E00FBFCFB00000000000000000000000000000000000000000000000000FBFE
      FC0090D699000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FAFCFD003C80
      BC004D90C40073ABD3005294C6003B83BA003C85B9005695C2007DACCF005591
      BC004380B100FAFCFD000000000000000000000000000000000098989800BCBC
      BC00999999000000000000000000000000000000000098989800939393009A9A
      9A00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FAFC
      FD003C7EBB004B8DC30070AAD20071AAD20074ACD2007AAFD3005697C4004589
      BB00FAFCFD0000000000000000000000000000000000000000009B9B9B00C0C0
      C000ACACAC00000000000000000000000000000000008F8F8F00A2A2A2008D8D
      8D00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FAFCFD003A7BB900488BC2006AA6D0006EA9D1005193C6004389BF00FAFC
      FD00000000000000000000000000000000000000000000000000F0F0F000B1B1
      B100C7C7C700AAAAAA0000000000000000009F9F9F00B4B4B40098989800B7B7
      B700000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FAFCFD00427FBB003577B700367BB9004788C100FAFCFD000000
      000000000000000000000000000000000000000000000000000000000000D9D9
      D900AEAEAE00C8C8C800CACACA00CACACA00BEBEBE009B9B9B00CECECE000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FAFCFD00E9F0F700EAF0F700FAFCFD00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000E7E7E700BEBEBE00A2A2A2009E9E9E00B6B6B600E3E3E300000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF008001FFFFFFFF00008001F00FF00F0000
      8001E007E00700008001C003C00300008001C003C00300008001C003C0030000
      8001C003C00300008001C003C00300008001C003C00300008001C003C0030000
      C7E3C003C0030000C7E3C003C0030000C3C3C003C0030000E007E007E0070000
      E007F81FF81F0000F81FFFFFFFFF0000FFFFFFFFFFFF8001FFFFFFFF00008001
      FFFFFFFF00008001FFFFFFFF00008001FFE7E7FFE0038001FFC7E3FFE0038001
      8003C00180018001800180010000800180018001000080018003C00100008001
      FFE7E7FF8001C7FFFFE7E7FFC003C78FFFFFFFFFE007C78FFFFFFFFFF00FC30F
      FFFFFFFFF81FE01FFFFFFFFFFC3FF03F00000000000000000000000000000000
      000000000000}
  end
  object ilNavToolbar_Off: TImageList
    Left = 946
    Top = 52
    Bitmap = {
      494C010103000400280910001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000ABABAB00909090008F8F8F006E6E
      6E006E6E6E007C7C7C0087878700898989008B8B8B008C8C8C00696969007575
      7500797979008D8D8D006E6E6E007F7F7F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A8A8A800A4A4A400AFAFAF00A4A4
      A40086868600E5E5E50082828200A9A9A900ACACAC0089898900E2E2E200ADAD
      AD00BBBBBB00B1B1B10094949400696969000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000EFEFEF00DCDCDC00ACACAC008282
      8200BABABA00F0F0F0007E7E7E00A4A4A400A6A6A60085858500F0F0F000CACA
      CA009E9E9E00A0A0A000BEBEBE00D2D2D2000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008686
      8600FBFBFB00000000000000000000000000000000000000000000000000FCFC
      FC00AAAAAA000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008B8B
      8B00F0F0F000EFEFEF007B7B7B009E9E9E00A1A1A10081818100EFEFEF00F4F4
      F40071717100E5E5E50000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DDDDDD006161
      610070707000000000000000000000000000000000000000000000000000A7A7
      A70093939300E5E5E50000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009090
      9000F1F1F100EFEFEF0077777700999999009C9C9C007C7C7C00EFEFEF00F4F4
      F40076767600E6E6E60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000ACACAC00A6A6A6009F9F
      9F009898980090909000898989008282820079797900727272007A7A7A009292
      92007C7C7C007777770000000000000000000000000000000000B7B7B700AEAE
      AE00B2B2B2009A9A9A00898989008282820079797900727272006A6A6A006262
      62005C5C5C0057575700525252000000000000000000DEDEDE00A3A3A3008F8F
      8F00F6F6F600EFEFEF0074747400767676007777770078787800EFEFEF00F4F4
      F4008B8B8B006C6C6C00CCCCCC00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000B1B1B100CBCBCB00C9C9
      C900C6C6C600C3C3C300C1C1C100BDBDBD00BBBBBB00B7B7B700B4B4B400B1B1
      B100AEAEAE007D7D7D007E7E7E000000000000000000C3C3C300B8B8B800C9C9
      C900C6C6C600C3C3C300C1C1C100BDBDBD00BBBBBB00B7B7B700B4B4B400B1B1
      B100AEAEAE00ADADAD005757570000000000DFDFDF00919191009F9F9F008B8B
      8B00DFDFDF00EDEDED00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00E2E2
      E200595959006B6B6B0050505000CCCCCC000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000B4B4B400CFCFCF00CDCD
      CD00CACACA00C8C8C800C5C5C500C2C2C200BEBEBE00BCBCBC00B8B8B800B6B6
      B600B3B3B300828282007F7F7F000000000000000000C4C4C400BCBCBC00CDCD
      CD00CACACA00C8C8C800C5C5C500C2C2C200BEBEBE00BCBCBC00B8B8B800B6B6
      B600B3B3B300B0B0B0005C5C5C0000000000A5A5A5009F9F9F00B5B5B500A0A0
      A00092929200CFCFCF00EEEEEE00EFEFEF00EFEFEF00EFEFEF00DADADA007070
      70007B7B7B00939393006F6F6F00767676000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000B4B4B400B4B4B400B1B1
      B100ACACAC00A6A6A6009F9F9F00989898009090900089898900828282009494
      94008E8E8E008585850000000000000000000000000000000000C2C2C200BDBD
      BD00B9B9B900A6A6A6009F9F9F00989898009090900089898900828282007979
      7900727272006A6A6A006262620000000000FCFCFC00929292009D9D9D00B5B5
      B500A0A0A00092929200CBCBCB00EDEDED00EFEFEF00DBDBDB00808080008A8A
      8A00A0A0A0007F7F7F006A6A6A00FBFBFB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008686
      86008C8C8C00000000000000000000000000000000000000000000000000BFBF
      BF00B3B3B3000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FCFCFC008F8F8F009C9C
      9C00B4B4B4009F9F9F0094949400D4D4D400D4D4D4008D8D8D0097979700ABAB
      AB008E8E8E007C7C7C00FCFCFC00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A8A8
      A800FCFCFC00000000000000000000000000000000000000000000000000FDFD
      FD00C8C8C8000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FCFCFC008E8E
      8E009B9B9B00B3B3B3009E9E9E008F8F8F00909090009E9E9E00B2B2B2009999
      99008B8B8B00FCFCFC0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FCFC
      FC008C8C8C0098989800B2B2B200B2B2B200B3B3B300B5B5B500A0A0A0009393
      9300FCFCFC000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FCFCFC008989890097979700AEAEAE00B1B1B1009D9D9D0095959500FCFC
      FC00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FCFCFC008D8D8D00868686008989890095959500FCFCFC000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FCFCFC00F2F2F200F2F2F200FCFCFC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFFFFFF0000FFFFFFFF00000000
      FFFFFFFF00000000FFFFFFFF00000000FFE7E7FFE0030000FFC7E3FFE0030000
      8003C00180010000800180010000000080018001000000008003C00100000000
      FFE7E7FF80010000FFE7E7FFC0030000FFFFFFFFE0070000FFFFFFFFF00F0000
      FFFFFFFFF81F0000FFFFFFFFFC3F000000000000000000000000000000000000
      000000000000}
  end
  object ApplicationEvents1: TApplicationEvents
    OnShowHint = ApplicationEvents1ShowHint
    Left = 424
    Top = 24
  end
end
