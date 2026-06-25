object FrameProperties: TFrameProperties
  Left = 0
  Top = 0
  Width = 1514
  Height = 700
  TabOrder = 0
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1514
    Height = 700
    ActivePage = tsCategories
    Align = alClient
    TabOrder = 0
    object tsCategories: TTabSheet
      object Splitter1: TSplitter
        Left = 497
        Top = 24
        Height = 646
        ExplicitLeft = 592
        ExplicitTop = 296
        ExplicitHeight = 100
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        BevelOuter = bvNone
        Caption = 'Panel1'
        TabOrder = 0
        object sbCategoriesPie: TSpeedButton
          Left = 0
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
        object sbCategoriesBar: TSpeedButton
          Left = 29
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object SpeedButton4: TSpeedButton
          Left = 58
          Top = 0
          Width = 23
          Height = 22
          NumGlyphs = 2
        end
        object RadioButton1: TRadioButton
          Left = 96
          Top = 1
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 0
        end
        object RadioButton2: TRadioButton
          Left = 215
          Top = 1
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 1
        end
      end
      object sgCategories: TStringGrid
        Left = 0
        Top = 24
        Width = 497
        Height = 646
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        TabOrder = 1
        ColWidths = (
          64
          64
          64
          64
          64
          64
          64)
      end
      object vtcCategories: TChart
        Left = 500
        Top = 24
        Width = 1006
        Height = 646
        Title.Text.Strings = (
          'TChart')
        View3DOptions.Elevation = 315
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        View3DOptions.Rotation = 360
        Align = alClient
        TabOrder = 2
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TPieSeries
          HoverElement = []
          Marks.Tail.Margin = 2
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
          OtherSlice.Legend.Visible = False
        end
      end
    end
    object tsTypes: TTabSheet
      ImageIndex = 1
      object Splitter5: TSplitter
        Left = 369
        Top = 24
        Height = 646
        ExplicitLeft = 377
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
      object TreeView3: TTreeView
        Left = 0
        Top = 24
        Width = 369
        Height = 646
        Align = alLeft
        Indent = 19
        TabOrder = 1
        ExplicitLeft = 8
      end
      object Chart4: TChart
        Left = 372
        Top = 24
        Width = 1134
        Height = 646
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 488
        ExplicitTop = 200
        ExplicitWidth = 400
        ExplicitHeight = 250
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsExtensions: TTabSheet
      ImageIndex = 2
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
    end
    object tsFolders: TTabSheet
      ImageIndex = 3
      object Splitter3: TSplitter
        Left = 497
        Top = 24
        Height = 646
        ExplicitLeft = 505
      end
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
      object StringGrid1: TStringGrid
        Left = 0
        Top = 24
        Width = 497
        Height = 646
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        TabOrder = 1
        ExplicitLeft = 8
        ColWidths = (
          64
          64
          64
          64
          64
          64
          64)
      end
      object Chart2: TChart
        Left = 500
        Top = 24
        Width = 1006
        Height = 646
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 488
        ExplicitTop = 200
        ExplicitWidth = 400
        ExplicitHeight = 250
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsMagnitude: TTabSheet
      ImageIndex = 4
      object Splitter4: TSplitter
        Left = 497
        Top = 24
        Height = 646
        ExplicitLeft = 505
      end
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
      object StringGrid2: TStringGrid
        Left = 0
        Top = 24
        Width = 497
        Height = 646
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        TabOrder = 1
        ExplicitLeft = 8
        ColWidths = (
          64
          64
          64
          64
          64
          64
          64)
      end
      object Chart3: TChart
        Left = 500
        Top = 24
        Width = 1006
        Height = 646
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 488
        ExplicitTop = 200
        ExplicitWidth = 400
        ExplicitHeight = 250
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsDates: TTabSheet
      ImageIndex = 5
      object Splitter2: TSplitter
        Left = 369
        Top = 24
        Height = 646
        ExplicitLeft = 216
        ExplicitTop = 21
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
      object TreeView2: TTreeView
        Left = 0
        Top = 24
        Width = 369
        Height = 646
        Align = alLeft
        Indent = 19
        TabOrder = 1
      end
      object Chart1: TChart
        Left = 372
        Top = 24
        Width = 1134
        Height = 646
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 488
        ExplicitTop = 200
        ExplicitWidth = 400
        ExplicitHeight = 250
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsHistory: TTabSheet
      ImageIndex = 6
      object Panel7: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
      object Panel13: TPanel
        Left = 0
        Top = 24
        Width = 233
        Height = 646
        Align = alLeft
        Caption = 'Panel13'
        TabOrder = 1
      end
      object Chart6: TChart
        Left = 233
        Top = 24
        Width = 1273
        Height = 646
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 672
        ExplicitTop = 280
        ExplicitWidth = 400
        ExplicitHeight = 250
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsTop101: TTabSheet
      ImageIndex = 7
      object Panel8: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
    end
    object tsNull: TTabSheet
      ImageIndex = 8
      object Panel9: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
    end
    object tsUsers: TTabSheet
      ImageIndex = 9
      object Splitter6: TSplitter
        Left = 497
        Top = 24
        Height = 646
        ExplicitLeft = 505
      end
      object Panel10: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
      object StringGrid3: TStringGrid
        Left = 0
        Top = 24
        Width = 497
        Height = 646
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        TabOrder = 1
        ExplicitLeft = 8
        ColWidths = (
          64
          64
          64
          64
          64
          64
          64)
      end
      object Chart5: TChart
        Left = 500
        Top = 24
        Width = 1006
        Height = 646
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 488
        ExplicitTop = 200
        ExplicitWidth = 400
        ExplicitHeight = 250
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsTemporary: TTabSheet
      ImageIndex = 10
      object Panel11: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
    end
    object tsLength: TTabSheet
      ImageIndex = 11
      object Panel12: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 24
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        ExplicitTop = 8
      end
    end
  end
  object puCharts: TPopupMenu
    Left = 1399
    Top = 568
    object miChartOptions: TMenuItem
      Caption = '.'
      Enabled = False
    end
    object N9: TMenuItem
      Caption = '-'
    end
    object miCOSave: TMenuItem
      Caption = '.'
      ImageIndex = 49
    end
    object miCOCopy: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
    object miCOAdvanced: TMenuItem
      Caption = '.'
      ImageIndex = 53
    end
  end
  object puType: TPopupMenu
    Left = 1336
    Top = 568
    object miTypeExportContent: TMenuItem
      Caption = '.'
      ImageIndex = 49
    end
    object miTypeZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
    end
    object miTypeExportCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
  end
  object puExtensionsMain: TPopupMenu
    Left = 1080
    Top = 512
    object miOtherAddTo: TMenuItem
      Caption = '.'
      ImageIndex = 0
      object miOA1: TMenuItem
        Tag = 1
        Caption = '.'
        ImageIndex = 7
      end
      object miOA2: TMenuItem
        Tag = 2
        Caption = '.'
        ImageIndex = 9
      end
      object miOA3: TMenuItem
        Tag = 3
        Caption = '.'
        ImageIndex = 11
      end
      object miOA4: TMenuItem
        Tag = 4
        Caption = '.'
        ImageIndex = 13
      end
      object miOA5: TMenuItem
        Tag = 5
        Caption = '.'
        ImageIndex = 15
      end
      object miOA6: TMenuItem
        Tag = 6
        Caption = '.'
        ImageIndex = 17
      end
      object miOA7: TMenuItem
        Tag = 7
        Caption = '.'
        ImageIndex = 19
      end
      object miOA8: TMenuItem
        Tag = 8
        Caption = '.'
        ImageIndex = 21
      end
      object miCustomEM: TMenuItem
        Caption = '.'
        object miOA9: TMenuItem
          Tag = 10
          Caption = '.'
          ImageIndex = 25
        end
        object miOA10: TMenuItem
          Tag = 11
          Caption = '.'
          ImageIndex = 27
        end
        object miOA11: TMenuItem
          Tag = 12
          Caption = '.'
          ImageIndex = 29
        end
        object miOA12: TMenuItem
          Tag = 13
          Caption = '.'
          ImageIndex = 31
        end
        object miOA13: TMenuItem
          Tag = 14
          Caption = '.'
          ImageIndex = 33
        end
        object miOA14: TMenuItem
          Tag = 15
          Caption = '.'
          ImageIndex = 35
        end
        object miOA15: TMenuItem
          Tag = 16
          Caption = '.'
          ImageIndex = 37
        end
        object miOA16: TMenuItem
          Tag = 17
          Caption = '.'
          ImageIndex = 39
        end
        object miOA17: TMenuItem
          Tag = 18
          Caption = '.'
          ImageIndex = 41
        end
        object miOA18: TMenuItem
          Tag = 19
          Caption = '.'
          ImageIndex = 43
        end
      end
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object miShowOtherFiles: TMenuItem
      Caption = '.'
      ImageIndex = 3
    end
    object miExtensionsExportTableCSV: TMenuItem
      Tag = 8
      Caption = '.'
      ImageIndex = 50
    end
    object N37: TMenuItem
      Caption = '-'
    end
    object SaveasCSV2: TMenuItem
      Caption = '.'
    end
  end
  object puFolders: TPopupMenu
    Left = 1193
    Top = 575
    object miFolderMoreDetail: TMenuItem
      Caption = '.'
    end
    object miScanFromDirList: TMenuItem
      Caption = '.'
      ImageIndex = 3
    end
    object miExploreFromDirList: TMenuItem
      Caption = '.'
      ImageIndex = 4
    end
    object miFolderExportSelectedCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
  end
  object puMagnitude: TPopupMenu
    Left = 1169
    Top = 512
    object miMagnitudeExport: TMenuItem
      Caption = '.'
      ImageIndex = 49
    end
    object miMagnitudeZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
    end
    object miMagnitudeExportCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
  end
  object puTreeDate: TPopupMenu
    Left = 1273
    Top = 577
    object MenuItem20: TMenuItem
      Caption = '.'
      ImageIndex = 1
    end
    object MenuItem18: TMenuItem
      Caption = '.'
    end
    object MenuItem19: TMenuItem
      Caption = '-'
    end
    object miFileDatesExploreDir: TMenuItem
      Caption = '.'
      ImageIndex = 4
    end
    object miFileDatesInfo: TMenuItem
      Caption = '.'
      ImageIndex = 2
    end
    object miDGenerateMD5: TMenuItem
      Caption = '.'
      ImageIndex = 48
    end
    object N11: TMenuItem
      Caption = '-'
    end
    object miFileDatesExport: TMenuItem
      Caption = '.'
      ImageIndex = 49
    end
    object miFileDatesExportCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
  end
  object puSearch: TPopupMenu
    Left = 906
    Top = 457
    object miSearchOpen: TMenuItem
      Caption = '.'
      ImageIndex = 1
    end
    object miSearchOpenCustom: TMenuItem
      Caption = '.'
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object miExploreDirectory: TMenuItem
      Caption = '.'
      ImageIndex = 4
    end
    object miSFileProperties: TMenuItem
      Caption = '.'
      ImageIndex = 2
    end
    object miGenerateMD5: TMenuItem
      Caption = '.'
      ImageIndex = 48
    end
    object miHexEdit: TMenuItem
      Caption = '.'
      ImageIndex = 54
    end
    object N21: TMenuItem
      Caption = '-'
    end
    object miCopyMenu: TMenuItem
      Caption = '.'
      ImageIndex = 45
      object miCopySelected: TMenuItem
        Caption = '.'
      end
      object miCopyAll: TMenuItem
        Caption = '.'
      end
    end
    object miMoveMenu: TMenuItem
      Caption = '.'
      ImageIndex = 47
      object miMoveSelected: TMenuItem
        Caption = '.'
      end
      object miMoveAll: TMenuItem
        Caption = '.'
      end
    end
    object miDeleteMenu: TMenuItem
      Caption = '.'
      ImageIndex = 46
      object miDeleteSelected: TMenuItem
        Caption = '.'
      end
      object miDeleteAll: TMenuItem
        Caption = '.'
      end
    end
    object N23: TMenuItem
      Caption = '-'
    end
    object miZIP: TMenuItem
      Caption = '.'
      ImageIndex = 51
    end
    object N22: TMenuItem
      Caption = '-'
    end
    object miSearchExportToCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
    object N36: TMenuItem
      Caption = '-'
    end
    object miSaveAs: TMenuItem
      Caption = '.'
      ImageIndex = 65
    end
  end
  object puUsers: TPopupMenu
    Left = 1232
    Top = 512
    object miUsersExportSelected: TMenuItem
      Caption = '.'
      ImageIndex = 49
    end
    object miUsersZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
    end
    object miUsersExportSelectedCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
  end
  object puFolderConfig: TPopupMenu
    Left = 1297
    Top = 518
    object miFCO: TMenuItem
      Caption = '.'
      Enabled = False
      GroupIndex = 1
    end
    object miFCOShowAll: TMenuItem
      AutoCheck = True
      Caption = '.'
      Checked = True
      GroupIndex = 1
      RadioItem = True
    end
    object N110: TMenuItem
      Tag = 1
      AutoCheck = True
      Caption = '>1%'
      GroupIndex = 1
      RadioItem = True
    end
    object N28: TMenuItem
      Tag = 2
      AutoCheck = True
      Caption = '>2%'
      GroupIndex = 1
      RadioItem = True
    end
    object N31: TMenuItem
      Tag = 3
      AutoCheck = True
      Caption = '>3%'
      GroupIndex = 1
      RadioItem = True
    end
    object N41: TMenuItem
      Tag = 4
      AutoCheck = True
      Caption = '>4%'
      GroupIndex = 1
      RadioItem = True
    end
    object N51: TMenuItem
      Tag = 5
      AutoCheck = True
      Caption = '>5%'
      GroupIndex = 1
      RadioItem = True
    end
    object N101: TMenuItem
      Tag = 6
      AutoCheck = True
      Caption = '>10%'
      GroupIndex = 1
      RadioItem = True
    end
    object N151: TMenuItem
      Tag = 7
      AutoCheck = True
      Caption = '>15%'
      GroupIndex = 1
      RadioItem = True
    end
  end
  object puTableDisplay: TPopupMenu
    Left = 969
    Top = 568
    object miTDShowAll: TMenuItem
      Caption = '.'
      Checked = True
      GroupIndex = 1
      RadioItem = True
    end
    object miTDNonZero: TMenuItem
      Caption = '.'
      GroupIndex = 1
      RadioItem = True
    end
    object miTDUserDefined: TMenuItem
      Caption = '.'
      GroupIndex = 1
      RadioItem = True
    end
    object N13: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object miTD1: TMenuItem
      Tag = 1
      Caption = '.'
      GroupIndex = 1
    end
    object miTD2: TMenuItem
      Tag = 2
      Caption = '.'
      GroupIndex = 1
    end
    object miTD3: TMenuItem
      Tag = 3
      Caption = '.'
      GroupIndex = 1
    end
    object miTD4: TMenuItem
      Tag = 4
      Caption = '.'
      GroupIndex = 1
    end
    object miTD5: TMenuItem
      Tag = 5
      Caption = '.'
      GroupIndex = 1
    end
    object miTD6: TMenuItem
      Tag = 6
      Caption = '.'
      GroupIndex = 1
    end
    object miTD7: TMenuItem
      Tag = 7
      Caption = '.'
      GroupIndex = 1
    end
    object miTD8: TMenuItem
      Tag = 8
      Caption = '.'
      GroupIndex = 1
    end
    object miTD9: TMenuItem
      Tag = 9
      Caption = '.'
      GroupIndex = 1
    end
    object miTDCustom: TMenuItem
      Caption = '.'
      GroupIndex = 1
      object miTD10: TMenuItem
        Tag = 10
        Caption = '.'
      end
      object miTD11: TMenuItem
        Tag = 11
        Caption = '.'
      end
      object miTD12: TMenuItem
        Tag = 12
        Caption = '.'
      end
      object miTD13: TMenuItem
        Tag = 13
        Caption = '.'
      end
      object miTD14: TMenuItem
        Tag = 14
        Caption = '.'
      end
      object miTD15: TMenuItem
        Tag = 15
        Caption = '.'
      end
      object miTD16: TMenuItem
        Tag = 16
        Caption = '.'
      end
      object miTD17: TMenuItem
        Tag = 17
        Caption = '.'
      end
      object miTD18: TMenuItem
        Tag = 18
        Caption = '.'
      end
      object miTD19: TMenuItem
        Tag = 19
        Caption = '.'
      end
    end
  end
  object puTable: TPopupMenu
    Left = 1352
    Top = 512
    object miTableExportSelected: TMenuItem
      Caption = '.'
      ImageIndex = 49
    end
    object miTableZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
    end
    object miTableExportSelectedCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
    end
  end
  object puNullFiles: TPopupMenu
    Left = 1120
    Top = 592
    object miNFExplore: TMenuItem
      Caption = '.'
      ImageIndex = 4
    end
    object miNFProperties: TMenuItem
      Caption = '.'
    end
  end
  object puNullFolders: TPopupMenu
    Left = 976
    Top = 472
    object miNFExploreFolder: TMenuItem
      Caption = '.'
      ImageIndex = 4
    end
    object miNFFolderProperties: TMenuItem
      Caption = '.'
    end
  end
  object puLength: TPopupMenu
    Tag = 3
    Left = 1049
    Top = 584
    object miLengthShowAll: TMenuItem
      Caption = '.'
      Checked = True
      GroupIndex = 1
      RadioItem = True
    end
    object miLengthNonZero: TMenuItem
      Caption = '.'
      GroupIndex = 1
      RadioItem = True
    end
  end
end
