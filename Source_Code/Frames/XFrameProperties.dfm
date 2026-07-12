object FrameProperties: TFrameProperties
  Left = 0
  Top = 0
  Width = 1514
  Height = 700
  TabOrder = 0
  object SpeedButton7: TSpeedButton
    Left = 24
    Top = 8
    Width = 23
    Height = 22
  end
  object pcProperties: TPageControl
    Left = 0
    Top = 0
    Width = 1514
    Height = 700
    ActivePage = tsDates
    Align = alClient
    Images = ilTabs
    TabOrder = 0
    object tsCategories: TTabSheet
      object Splitter1: TSplitter
        Left = 497
        Top = 27
        Height = 643
        ExplicitLeft = 592
        ExplicitTop = 296
        ExplicitHeight = 100
      end
      object TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object sbCategoriesPie: TSpeedButton
          Tag = 1
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
          Tag = 1
          Left = 29
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object sbCategoriesConfig: TSpeedButton
          Left = 58
          Top = 0
          Width = 23
          Height = 22
          NumGlyphs = 2
          OnClick = sbCategoriesConfigClick
        end
        object rbCategoriesBySize: TRadioButton
          Left = 96
          Top = 2
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 0
        end
        object rbCategoriesByQuantity: TRadioButton
          Left = 215
          Top = 2
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 1
        end
      end
      object sgCategories: TStringGrid
        Left = 0
        Top = 27
        Width = 497
        Height = 643
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        PopupMenu = puTable
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
        Top = 27
        Width = 1006
        Height = 643
        Title.Text.Strings = (
          'TChart')
        View3DOptions.Elevation = 315
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        View3DOptions.Rotation = 360
        Align = alClient
        PopupMenu = puCharts
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
        Left = 265
        Top = 27
        Height = 643
        ExplicitLeft = 232
        ExplicitTop = 30
        ExplicitHeight = 646
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        object SpeedButton18: TSpeedButton
          Tag = 2
          Left = 1
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
        object SpeedButton19: TSpeedButton
          Tag = 2
          Left = 30
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object SpeedButton20: TSpeedButton
          Left = 59
          Top = 0
          Width = 23
          Height = 22
          NumGlyphs = 2
          OnClick = sbCategoriesConfigClick
        end
        object rbTypesBySize: TRadioButton
          Left = 97
          Top = 5
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 0
          OnClick = rbTypesBySizeClick
        end
        object rbTypesByQuantity: TRadioButton
          Left = 216
          Top = 5
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 1
          OnClick = rbTypesBySizeClick
        end
      end
      object vtcTypes: TChart
        Left = 268
        Top = 27
        Width = 1238
        Height = 643
        Title.Text.Strings = (
          'TChart')
        View3DOptions.Elevation = 315
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        View3DOptions.Rotation = 360
        Align = alClient
        PopupMenu = puCharts
        TabOrder = 1
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series2: TPieSeries
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
      object Panel14: TPanel
        Left = 0
        Top = 27
        Width = 265
        Height = 643
        Align = alLeft
        Caption = 'Panel14'
        TabOrder = 2
        object Splitter12: TSplitter
          Left = 1
          Top = 401
          Width = 263
          Height = 3
          Cursor = crVSplit
          Align = alTop
          ExplicitWidth = 241
        end
        object tvTypes: TTreeView
          Left = 1
          Top = 1
          Width = 263
          Height = 400
          Align = alTop
          Indent = 19
          PopupMenu = puType
          TabOrder = 0
          OnClick = tvTypesClick
        end
        object sgDates: TStringGrid
          Left = 1
          Top = 404
          Width = 263
          Height = 238
          Align = alClient
          TabOrder = 1
        end
      end
    end
    object tsExtensions: TTabSheet
      ImageIndex = 2
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        object cbExtensionsAll: TCheckBox
          Left = 0
          Top = 2
          Width = 97
          Height = 17
          TabOrder = 0
        end
        object cbExtensionsOther: TCheckBox
          Left = 128
          Top = 2
          Width = 97
          Height = 17
          TabOrder = 1
        end
        object cbExtensionsCustom: TCheckBox
          Left = 248
          Top = 4
          Width = 97
          Height = 17
          TabOrder = 2
        end
        object cbExtensionsColourCode: TCheckBox
          Left = 368
          Top = 2
          Width = 97
          Height = 17
          TabOrder = 3
        end
      end
      object sgExtensions: TStringGrid
        Left = 0
        Top = 27
        Width = 1506
        Height = 643
        Align = alClient
        ColCount = 8
        FixedCols = 0
        RowCount = 2
        PopupMenu = puExtensionsMain
        TabOrder = 1
        ColWidths = (
          64
          64
          64
          64
          64
          64
          64
          64)
      end
    end
    object tsFolders: TTabSheet
      ImageIndex = 3
      object Splitter3: TSplitter
        Left = 497
        Top = 27
        Height = 643
        ExplicitLeft = 505
        ExplicitTop = 24
        ExplicitHeight = 646
      end
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        object SpeedButton10: TSpeedButton
          Tag = 3
          Left = 0
          Top = -1
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
        object SpeedButton11: TSpeedButton
          Tag = 3
          Left = 29
          Top = -1
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object sbFoldersConfig: TSpeedButton
          Left = 58
          Top = -1
          Width = 23
          Height = 22
          NumGlyphs = 2
          OnClick = sbFoldersConfigClick
        end
        object sbFoldersMoreDetail: TSpeedButton
          Left = 434
          Top = -1
          Width = 127
          Height = 22
          NumGlyphs = 2
          OnClick = sbFoldersMoreDetailClick
        end
        object rbFoldersBySize: TRadioButton
          Left = 96
          Top = 4
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 0
        end
        object rbFoldersByQuantity: TRadioButton
          Left = 215
          Top = 4
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 1
        end
      end
      object sgFolders: TStringGrid
        Left = 0
        Top = 27
        Width = 497
        Height = 643
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        TabOrder = 1
        OnDblClick = sgFoldersDblClick
        ColWidths = (
          64
          64
          64
          64
          64
          64
          64)
      end
      object vtcFolders: TChart
        Left = 500
        Top = 27
        Width = 1006
        Height = 643
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        PopupMenu = puCharts
        TabOrder = 2
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsMagnitude: TTabSheet
      ImageIndex = 4
      object Splitter4: TSplitter
        Left = 497
        Top = 27
        Height = 643
        ExplicitLeft = 505
        ExplicitTop = 24
        ExplicitHeight = 646
      end
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        object SpeedButton16: TSpeedButton
          Tag = 4
          Left = 0
          Top = -1
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
        object SpeedButton17: TSpeedButton
          Tag = 4
          Left = 29
          Top = -1
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object rbMagnitudeBySize: TRadioButton
          Left = 96
          Top = 4
          Width = 113
          Height = 17
          Caption = 'rbCategoriesBySize'
          TabOrder = 0
        end
        object rbMagnitudeByQuantity: TRadioButton
          Left = 215
          Top = 4
          Width = 113
          Height = 17
          Caption = 'rbCategoriesByQuantity'
          TabOrder = 1
        end
        object ComboBox3: TComboBox
          Left = 400
          Top = 0
          Width = 145
          Height = 23
          Style = csDropDownList
          TabOrder = 2
        end
      end
      object sgMagnitude: TStringGrid
        Left = 0
        Top = 27
        Width = 497
        Height = 643
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        RowCount = 14
        PopupMenu = puMagnitude
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
      object vtcMagnitude: TChart
        Left = 500
        Top = 27
        Width = 1006
        Height = 643
        Title.Text.Strings = (
          'TChart')
        View3DOptions.Elevation = 315
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        View3DOptions.Rotation = 360
        Align = alClient
        PopupMenu = puCharts
        TabOrder = 2
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series3: TPieSeries
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
    object tsDates: TTabSheet
      ImageIndex = 5
      object Splitter2: TSplitter
        Left = 369
        Top = 27
        Height = 643
        ExplicitLeft = 216
        ExplicitTop = 21
        ExplicitHeight = 646
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        TabOrder = 0
        object SpeedButton1: TSpeedButton
          Tag = 8
          Left = 0
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
        object SpeedButton2: TSpeedButton
          Tag = 8
          Left = 29
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object sbDatesCollapseNodes: TSpeedButton
          Left = 630
          Top = -1
          Width = 147
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object rbDatesBySize: TRadioButton
          Left = 72
          Top = 2
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 0
        end
        object rbDatesByQuantity: TRadioButton
          Left = 191
          Top = 2
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 1
        end
        object ComboBox1: TComboBox
          Left = 328
          Top = 0
          Width = 145
          Height = 23
          Style = csDropDownList
          TabOrder = 2
        end
        object ComboBox2: TComboBox
          Left = 479
          Top = 0
          Width = 145
          Height = 23
          Style = csDropDownList
          TabOrder = 3
        end
      end
      object tvDates: TTreeView
        Left = 0
        Top = 27
        Width = 369
        Height = 643
        Align = alLeft
        Indent = 19
        PopupMenu = puTreeDate
        TabOrder = 1
      end
      object vtcFileDates: TChart
        Left = 372
        Top = 27
        Width = 1134
        Height = 643
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        PopupMenu = puCharts
        TabOrder = 2
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
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
      end
      object Panel13: TPanel
        Left = 0
        Top = 27
        Width = 193
        Height = 643
        Align = alLeft
        TabOrder = 1
        object lHistoryFrom: TLabel
          Left = 9
          Top = 6
          Width = 3
          Height = 15
          Caption = '.'
        end
        object lHistoryInterval: TLabel
          Left = 9
          Top = 120
          Width = 3
          Height = 15
          Caption = '.'
        end
        object lHistoryTo: TLabel
          Left = 9
          Top = 56
          Width = 3
          Height = 15
          Caption = '.'
        end
        object Label4: TLabel
          Left = 9
          Top = 504
          Width = 3
          Height = 15
          Caption = '.'
        end
        object sbHistoryRefresh: TSpeedButton
          Left = 9
          Top = 413
          Width = 178
          Height = 22
        end
        object lHistoryUser: TLabel
          Left = 9
          Top = 336
          Width = 3
          Height = 15
          Caption = '.'
        end
        object DateTimePicker1: TDateTimePicker
          Left = 9
          Top = 27
          Width = 178
          Height = 23
          Date = 46202.000000000000000000
          Time = 0.636775069448049200
          DateFormat = dfLong
          TabOrder = 0
        end
        object DateTimePicker2: TDateTimePicker
          Left = 9
          Top = 77
          Width = 178
          Height = 23
          Date = 46202.000000000000000000
          Time = 0.636775069448049200
          DateFormat = dfLong
          TabOrder = 1
        end
        object ComboBox7: TComboBox
          Left = 9
          Top = 141
          Width = 178
          Height = 23
          Style = csDropDownList
          TabOrder = 2
        end
        object ComboBox8: TComboBox
          Left = 9
          Top = 170
          Width = 178
          Height = 23
          Style = csDropDownList
          TabOrder = 3
        end
        object gbHistoryOptions: TGroupBox
          Left = 9
          Top = 216
          Width = 178
          Height = 105
          Caption = '.'
          TabOrder = 4
          object rbHistoryQuantity: TRadioButton
            Left = 11
            Top = 24
            Width = 113
            Height = 17
            Caption = '.'
            TabOrder = 0
          end
          object rbHistorySize: TRadioButton
            Left = 11
            Top = 47
            Width = 113
            Height = 17
            Caption = '.'
            TabOrder = 1
          end
          object cbHistoryCumulative: TCheckBox
            Left = 11
            Top = 80
            Width = 97
            Height = 17
            Caption = '.'
            TabOrder = 2
          end
        end
        object cbHistoryAutoRefresh: TCheckBox
          Left = 9
          Top = 441
          Width = 97
          Height = 17
          Caption = '.'
          TabOrder = 5
        end
        object cbHistoryUsers: TComboBox
          Left = 9
          Top = 357
          Width = 178
          Height = 23
          Style = csDropDownList
          TabOrder = 6
        end
      end
      object vtcHistory: TChart
        Left = 193
        Top = 27
        Width = 1313
        Height = 643
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        PopupMenu = puCharts
        TabOrder = 2
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
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
      end
      object pcTop101: TPageControl
        Left = 0
        Top = 27
        Width = 1506
        Height = 643
        ActivePage = TabSheet1
        Align = alClient
        TabOrder = 1
        object TabSheet1: TTabSheet
          Caption = 'TabSheet1'
          object Splitter8: TSplitter
            Left = 881
            Top = 27
            Height = 586
            ExplicitLeft = 944
            ExplicitTop = 184
            ExplicitHeight = 100
          end
          object Panel1: TPanel
            Left = 0
            Top = 0
            Width = 1498
            Height = 27
            Align = alTop
            Caption = 'Panel1'
            TabOrder = 0
            object cbTop101SizeUser: TComboBox
              Left = 1
              Top = -1
              Width = 176
              Height = 23
              Cursor = crAppStart
              Style = csDropDownList
              TabOrder = 0
            end
            object cbTop101SizeColourCode: TCheckBox
              Left = 183
              Top = 5
              Width = 97
              Height = 17
              Caption = 'cbTop101SizeColourCode'
              TabOrder = 1
            end
          end
          object Panel15: TPanel
            Left = 884
            Top = 27
            Width = 614
            Height = 586
            Align = alClient
            Caption = 'Panel15'
            TabOrder = 1
            object sgTop101Small: TStringGrid
              Left = 1
              Top = 1
              Width = 612
              Height = 584
              Align = alClient
              ColCount = 2
              FixedCols = 0
              RowCount = 2
              PopupMenu = puSearch
              TabOrder = 0
            end
          end
          object Panel16: TPanel
            Left = 0
            Top = 27
            Width = 881
            Height = 586
            Align = alLeft
            Caption = 'Panel15'
            TabOrder = 2
            object Panel17: TPanel
              Left = 1
              Top = 1
              Width = 879
              Height = 24
              Align = alTop
              TabOrder = 0
            end
            object sgTop101Big: TStringGrid
              Left = 1
              Top = 25
              Width = 879
              Height = 560
              Align = alClient
              ColCount = 3
              FixedCols = 0
              RowCount = 2
              PopupMenu = puSearch
              TabOrder = 1
            end
          end
        end
        object TabSheet2: TTabSheet
          Caption = 'TabSheet2'
          ImageIndex = 1
          object Splitter9: TSplitter
            Left = 881
            Top = 27
            Height = 586
            ExplicitLeft = 889
          end
          object Panel18: TPanel
            Left = 0
            Top = 0
            Width = 1498
            Height = 27
            Align = alTop
            Caption = 'Panel1'
            TabOrder = 0
            object cbTop101DateUser: TComboBox
              Left = 1
              Top = -2
              Width = 176
              Height = 23
              Cursor = crAppStart
              Style = csDropDownList
              TabOrder = 0
            end
            object cbTop101DateColourCode: TCheckBox
              Left = 359
              Top = 4
              Width = 97
              Height = 17
              Caption = 'CheckBox1'
              TabOrder = 1
            end
            object cbTop101DateDate: TComboBox
              Left = 177
              Top = -1
              Width = 176
              Height = 23
              Cursor = crAppStart
              Style = csDropDownList
              TabOrder = 2
            end
          end
          object Panel19: TPanel
            Left = 0
            Top = 27
            Width = 881
            Height = 586
            Align = alLeft
            Caption = 'Panel15'
            TabOrder = 1
            object Panel20: TPanel
              Left = 1
              Top = 1
              Width = 879
              Height = 24
              Align = alTop
              TabOrder = 0
            end
            object sgTop101BigDate: TStringGrid
              Left = 1
              Top = 25
              Width = 879
              Height = 560
              Align = alClient
              ColCount = 4
              FixedCols = 0
              RowCount = 2
              PopupMenu = puSearch
              TabOrder = 1
            end
          end
          object sgTop101SmallDate: TStringGrid
            Left = 884
            Top = 27
            Width = 614
            Height = 586
            Align = alClient
            ColCount = 4
            FixedCols = 0
            RowCount = 2
            PopupMenu = puSearch
            TabOrder = 2
          end
        end
      end
    end
    object tsNull: TTabSheet
      ImageIndex = 8
      object Splitter11: TSplitter
        Left = 0
        Top = 329
        Width = 1506
        Height = 3
        Cursor = crVSplit
        Align = alTop
        ExplicitLeft = -3
        ExplicitTop = 326
      end
      object Panel9: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        object SpeedButton8: TSpeedButton
          Left = 0
          Top = 2
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
      end
      object sgNullFolders: TStringGrid
        Left = 0
        Top = 359
        Width = 1506
        Height = 311
        Align = alClient
        ColCount = 1
        FixedCols = 0
        RowCount = 2
        PopupMenu = puNullFolders
        TabOrder = 1
      end
      object sgNullFiles: TStringGrid
        Left = 0
        Top = 27
        Width = 1506
        Height = 302
        Align = alTop
        ColCount = 1
        FixedCols = 0
        RowCount = 2
        PopupMenu = puNullFiles
        TabOrder = 2
      end
      object Panel21: TPanel
        Left = 0
        Top = 332
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 3
        object SpeedButton9: TSpeedButton
          Left = 0
          Top = 2
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
      end
    end
    object tsUsers: TTabSheet
      ImageIndex = 9
      object Splitter6: TSplitter
        Left = 497
        Top = 27
        Height = 643
        ExplicitLeft = 505
        ExplicitTop = 24
        ExplicitHeight = 646
      end
      object Panel10: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        TabOrder = 0
        object SpeedButton3: TSpeedButton
          Tag = 11
          Left = 0
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
        object SpeedButton5: TSpeedButton
          Tag = 11
          Left = 29
          Top = 0
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object SpeedButton21: TSpeedButton
          Left = 539
          Top = -1
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object rbUsersBySize: TRadioButton
          Left = 72
          Top = 2
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 0
        end
        object rbUsersByQuantity: TRadioButton
          Left = 191
          Top = 2
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 1
        end
        object ComboBox6: TComboBox
          Left = 568
          Top = 0
          Width = 185
          Height = 23
          TabOrder = 2
          Text = 'ComboBox6'
        end
      end
      object sgUsers: TStringGrid
        Left = 0
        Top = 27
        Width = 497
        Height = 643
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        PopupMenu = puUsers
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
      object vtcUsers: TChart
        Left = 500
        Top = 27
        Width = 1006
        Height = 643
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 2
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsTemporary: TTabSheet
      ImageIndex = 10
      object Splitter7: TSplitter
        Left = 777
        Top = 27
        Height = 643
        ExplicitLeft = 944
        ExplicitTop = 208
        ExplicitHeight = 100
      end
      object Panel11: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        object SpeedButton6: TSpeedButton
          Left = 0
          Top = 2
          Width = 23
          Height = 22
          NumGlyphs = 2
        end
        object rbTempBySize: TRadioButton
          Left = 38
          Top = 5
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 0
        end
        object rbTempByQuantity: TRadioButton
          Left = 157
          Top = 5
          Width = 113
          Height = 17
          Caption = 'RadioButton1'
          TabOrder = 1
        end
      end
      object sgTemporary: TStringGrid
        Left = 0
        Top = 27
        Width = 777
        Height = 643
        Align = alLeft
        ColCount = 2
        FixedCols = 0
        RowCount = 2
        PopupMenu = puSearch
        TabOrder = 1
      end
      object vtcTemporary: TChart
        Left = 780
        Top = 27
        Width = 726
        Height = 643
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        PopupMenu = puCharts
        TabOrder = 2
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
    object tsLength: TTabSheet
      ImageIndex = 11
      object Splitter10: TSplitter
        Left = 433
        Top = 27
        Height = 643
        ExplicitLeft = 592
        ExplicitTop = 224
        ExplicitHeight = 100
      end
      object Panel12: TPanel
        Left = 0
        Top = 0
        Width = 1506
        Height = 27
        Align = alTop
        Caption = 'Panel2'
        TabOrder = 0
        object SpeedButton13: TSpeedButton
          Tag = 12
          Left = 0
          Top = -1
          Width = 23
          Height = 22
          GroupIndex = 1
          Down = True
          NumGlyphs = 2
          OnClick = sbCategoriesPieClick
        end
        object SpeedButton14: TSpeedButton
          Tag = 12
          Left = 29
          Top = -1
          Width = 23
          Height = 22
          GroupIndex = 1
          NumGlyphs = 2
          OnClick = sbCategoriesBarClick
        end
        object SpeedButton15: TSpeedButton
          Left = 58
          Top = -1
          Width = 23
          Height = 22
          NumGlyphs = 2
          OnClick = SpeedButton15Click
        end
        object rbLengthBySize: TRadioButton
          Left = 96
          Top = 4
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 0
        end
        object rbLengthByQuantity: TRadioButton
          Left = 215
          Top = 4
          Width = 113
          Height = 17
          Caption = '.'
          TabOrder = 1
        end
      end
      object sgLengths: TStringGrid
        Left = 0
        Top = 27
        Width = 433
        Height = 643
        Align = alLeft
        ColCount = 7
        FixedCols = 0
        RowCount = 2
        PopupMenu = puTable
        TabOrder = 1
      end
      object vtcLengths: TChart
        Left = 436
        Top = 27
        Width = 1070
        Height = 643
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        PopupMenu = puCharts
        TabOrder = 2
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
  end
  object puCharts: TPopupMenu
    Left = 1151
    Top = 240
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
      OnClick = miCOSaveClick
    end
    object miCOCopy: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miCOCopyClick
    end
    object miCOAdvanced: TMenuItem
      Caption = '.'
      ImageIndex = 53
      OnClick = miCOAdvancedClick
    end
  end
  object puType: TPopupMenu
    Left = 1384
    Top = 176
    object miTypeExportContent: TMenuItem
      Caption = '.'
      ImageIndex = 49
      OnClick = miTypeExportContentClick
    end
    object miTypeZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
      OnClick = miTypeZipClick
    end
    object miTypeExportCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miTypeExportCBClick
    end
  end
  object puExtensionsMain: TPopupMenu
    Left = 1048
    Top = 104
    object miOtherAddTo: TMenuItem
      Caption = '.'
      ImageIndex = 0
      object miOA1: TMenuItem
        Tag = 1
        Caption = '.'
        ImageIndex = 7
        OnClick = miOA1Click
      end
      object miOA2: TMenuItem
        Tag = 2
        Caption = '.'
        ImageIndex = 9
        OnClick = miOA1Click
      end
      object miOA3: TMenuItem
        Tag = 3
        Caption = '.'
        ImageIndex = 11
        OnClick = miOA1Click
      end
      object miOA4: TMenuItem
        Tag = 4
        Caption = '.'
        ImageIndex = 13
        OnClick = miOA1Click
      end
      object miOA5: TMenuItem
        Tag = 5
        Caption = '.'
        ImageIndex = 15
        OnClick = miOA1Click
      end
      object miOA6: TMenuItem
        Tag = 6
        Caption = '.'
        ImageIndex = 17
        OnClick = miOA1Click
      end
      object miOA7: TMenuItem
        Tag = 7
        Caption = '.'
        ImageIndex = 19
        OnClick = miOA1Click
      end
      object miOA8: TMenuItem
        Tag = 8
        Caption = '.'
        ImageIndex = 21
        OnClick = miOA1Click
      end
      object miCustomEM: TMenuItem
        Caption = '.'
        object miOA9: TMenuItem
          Tag = 10
          Caption = '.'
          ImageIndex = 25
          OnClick = miOA1Click
        end
        object miOA10: TMenuItem
          Tag = 11
          Caption = '.'
          ImageIndex = 27
          OnClick = miOA1Click
        end
        object miOA11: TMenuItem
          Tag = 12
          Caption = '.'
          ImageIndex = 29
          OnClick = miOA1Click
        end
        object miOA12: TMenuItem
          Tag = 13
          Caption = '.'
          ImageIndex = 31
          OnClick = miOA1Click
        end
        object miOA13: TMenuItem
          Tag = 14
          Caption = '.'
          ImageIndex = 33
          OnClick = miOA1Click
        end
        object miOA14: TMenuItem
          Tag = 15
          Caption = '.'
          ImageIndex = 35
          OnClick = miOA1Click
        end
        object miOA15: TMenuItem
          Tag = 16
          Caption = '.'
          ImageIndex = 37
          OnClick = miOA1Click
        end
        object miOA16: TMenuItem
          Tag = 17
          Caption = '.'
          ImageIndex = 39
          OnClick = miOA1Click
        end
        object miOA17: TMenuItem
          Tag = 18
          Caption = '.'
          ImageIndex = 41
          OnClick = miOA1Click
        end
        object miOA18: TMenuItem
          Tag = 19
          Caption = '.'
          ImageIndex = 43
          OnClick = miOA1Click
        end
      end
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object miShowOtherFiles: TMenuItem
      Caption = '.'
      ImageIndex = 3
      OnClick = miShowOtherFilesClick
    end
    object miExtensionsExportTableCSV: TMenuItem
      Tag = 8
      Caption = '.'
      ImageIndex = 50
      OnClick = miExtensionsExportTableCSVClick
    end
    object N37: TMenuItem
      Caption = '-'
    end
    object SaveasCSV2: TMenuItem
      Caption = '.'
      OnClick = SaveasCSV2Click
    end
  end
  object puFolders: TPopupMenu
    Left = 1145
    Top = 167
    object miFolderMoreDetail: TMenuItem
      Caption = '.'
      OnClick = miFolderMoreDetailClick
    end
    object miScanFromDirList: TMenuItem
      Caption = '.'
      ImageIndex = 3
      OnClick = miScanFromDirListClick
    end
    object miExploreFromDirList: TMenuItem
      Caption = '.'
      ImageIndex = 4
      OnClick = miExploreFromDirListClick
    end
    object miFolderExportSelectedCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miFolderExportSelectedCBClick
    end
  end
  object puMagnitude: TPopupMenu
    Left = 1049
    Top = 168
    object miMagnitudeExport: TMenuItem
      Caption = '.'
      ImageIndex = 49
      OnClick = miMagnitudeExportClick
    end
    object miMagnitudeZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
      OnClick = miMagnitudeZipClick
    end
    object miMagnitudeExportCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miMagnitudeExportCBClick
    end
  end
  object puTreeDate: TPopupMenu
    Left = 1049
    Top = 241
    object MenuItem20: TMenuItem
      Caption = '.'
      ImageIndex = 1
      OnClick = MenuItem20Click
    end
    object MenuItem18: TMenuItem
      Caption = '.'
      OnClick = MenuItem18Click
    end
    object MenuItem19: TMenuItem
      Caption = '-'
    end
    object miFileDatesExploreDir: TMenuItem
      Caption = '.'
      ImageIndex = 4
      OnClick = miFileDatesExploreDirClick
    end
    object miFileDatesInfo: TMenuItem
      Caption = '.'
      ImageIndex = 2
      OnClick = miFileDatesInfoClick
    end
    object miDGenerateMD5: TMenuItem
      Caption = '.'
      ImageIndex = 48
      OnClick = miDGenerateMD5Click
    end
    object N11: TMenuItem
      Caption = '-'
    end
    object miFileDatesExport: TMenuItem
      Caption = '.'
      ImageIndex = 49
      OnClick = miFileDatesExportClick
    end
    object miFileDatesExportCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miFileDatesExportCBClick
    end
  end
  object puSearch: TPopupMenu
    Left = 1242
    Top = 97
    object miSearchOpen: TMenuItem
      Caption = '.'
      ImageIndex = 1
      OnClick = miSearchOpenClick
    end
    object miSearchOpenCustom: TMenuItem
      Caption = '.'
      OnClick = miSearchOpenCustomClick
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object miExploreDirectory: TMenuItem
      Caption = '.'
      ImageIndex = 4
      OnClick = miExploreDirectoryClick
    end
    object miSFileProperties: TMenuItem
      Caption = '.'
      ImageIndex = 2
      OnClick = miSFilePropertiesClick
    end
    object miGenerateMD5: TMenuItem
      Caption = '.'
      ImageIndex = 48
      OnClick = miGenerateMD5Click
    end
    object miHexEdit: TMenuItem
      Caption = '.'
      ImageIndex = 54
      OnClick = miHexEditClick
    end
    object N21: TMenuItem
      Caption = '-'
    end
    object miCopyMenu: TMenuItem
      Caption = '.'
      ImageIndex = 45
      object miCopySelected: TMenuItem
        Caption = '.'
        OnClick = miCopySelectedClick
      end
      object miCopyAll: TMenuItem
        Caption = '.'
        OnClick = miCopyAllClick
      end
    end
    object miMoveMenu: TMenuItem
      Caption = '.'
      ImageIndex = 47
      object miMoveSelected: TMenuItem
        Caption = '.'
        OnClick = miMoveSelectedClick
      end
      object miMoveAll: TMenuItem
        Caption = '.'
        OnClick = miMoveAllClick
      end
    end
    object miDeleteMenu: TMenuItem
      Caption = '.'
      ImageIndex = 46
      object miDeleteSelected: TMenuItem
        Caption = '.'
        OnClick = miDeleteSelectedClick
      end
      object miDeleteAll: TMenuItem
        Caption = '.'
        OnClick = miDeleteAllClick
      end
    end
    object N23: TMenuItem
      Caption = '-'
    end
    object miZIP: TMenuItem
      Caption = '.'
      ImageIndex = 51
      OnClick = miZIPClick
    end
    object N22: TMenuItem
      Caption = '-'
    end
    object miSearchExportToCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miSearchExportToCBClick
    end
    object N36: TMenuItem
      Caption = '-'
    end
    object miSaveAs: TMenuItem
      Caption = '.'
      ImageIndex = 65
      OnClick = miSaveAsClick
    end
  end
  object puUsers: TPopupMenu
    Left = 1312
    Top = 168
    object miUsersExportSelected: TMenuItem
      Caption = '.'
      ImageIndex = 49
      OnClick = miUsersExportSelectedClick
    end
    object miUsersZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
      OnClick = miUsersZipClick
    end
    object miUsersExportSelectedCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miUsersExportSelectedCBClick
    end
  end
  object puFolderConfig: TPopupMenu
    Left = 1145
    Top = 102
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
      OnClick = miFCOShowAllClick
    end
    object N110: TMenuItem
      Tag = 1
      AutoCheck = True
      Caption = '>1%'
      GroupIndex = 1
      RadioItem = True
      OnClick = miFCOShowAllClick
    end
    object N28: TMenuItem
      Tag = 2
      AutoCheck = True
      Caption = '>2%'
      GroupIndex = 1
      RadioItem = True
      OnClick = miFCOShowAllClick
    end
    object N31: TMenuItem
      Tag = 3
      AutoCheck = True
      Caption = '>3%'
      GroupIndex = 1
      RadioItem = True
      OnClick = miFCOShowAllClick
    end
    object N41: TMenuItem
      Tag = 4
      AutoCheck = True
      Caption = '>4%'
      GroupIndex = 1
      RadioItem = True
      OnClick = miFCOShowAllClick
    end
    object N51: TMenuItem
      Tag = 5
      AutoCheck = True
      Caption = '>5%'
      GroupIndex = 1
      RadioItem = True
      OnClick = miFCOShowAllClick
    end
    object N101: TMenuItem
      Tag = 6
      AutoCheck = True
      Caption = '>10%'
      GroupIndex = 1
      RadioItem = True
      OnClick = miFCOShowAllClick
    end
    object N151: TMenuItem
      Tag = 7
      AutoCheck = True
      Caption = '>15%'
      GroupIndex = 1
      RadioItem = True
      OnClick = miFCOShowAllClick
    end
  end
  object puTableDisplay: TPopupMenu
    Left = 1233
    Top = 248
    object miTDShowAll: TMenuItem
      Caption = '.'
      Checked = True
      GroupIndex = 1
      RadioItem = True
      OnClick = miTDShowAllClick
    end
    object miTDNonZero: TMenuItem
      Caption = '.'
      GroupIndex = 1
      RadioItem = True
      OnClick = miTDNonZeroClick
    end
    object miTDUserDefined: TMenuItem
      Caption = '.'
      GroupIndex = 1
      RadioItem = True
      OnClick = miTDUserDefinedClick
    end
    object N13: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object miTD1: TMenuItem
      Tag = 1
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD2: TMenuItem
      Tag = 2
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD3: TMenuItem
      Tag = 3
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD4: TMenuItem
      Tag = 4
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD5: TMenuItem
      Tag = 5
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD6: TMenuItem
      Tag = 6
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD7: TMenuItem
      Tag = 7
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD8: TMenuItem
      Tag = 8
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTD9: TMenuItem
      Tag = 9
      Caption = '.'
      GroupIndex = 1
      OnClick = miTD1Click
    end
    object miTDCustom: TMenuItem
      Caption = '.'
      GroupIndex = 1
      object miTD10: TMenuItem
        Tag = 10
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD11: TMenuItem
        Tag = 11
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD12: TMenuItem
        Tag = 12
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD13: TMenuItem
        Tag = 13
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD14: TMenuItem
        Tag = 14
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD15: TMenuItem
        Tag = 15
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD16: TMenuItem
        Tag = 16
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD17: TMenuItem
        Tag = 17
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD18: TMenuItem
        Tag = 18
        Caption = '.'
        OnClick = miTD1Click
      end
      object miTD19: TMenuItem
        Tag = 19
        Caption = '.'
        OnClick = miTD1Click
      end
    end
  end
  object puTable: TPopupMenu
    Left = 1328
    Top = 248
    object miTableExportSelected: TMenuItem
      Caption = '.'
      ImageIndex = 49
      OnClick = miTableExportSelectedClick
    end
    object miTableZip: TMenuItem
      Caption = '.'
      ImageIndex = 51
      OnClick = miTableZipClick
    end
    object miTableExportSelectedCB: TMenuItem
      Caption = '.'
      ImageIndex = 50
      OnClick = miTableExportSelectedCBClick
    end
  end
  object puNullFiles: TPopupMenu
    Left = 1424
    Top = 96
    object miNFExplore: TMenuItem
      Caption = '.'
      ImageIndex = 4
      OnClick = miNFExploreClick
    end
    object miNFProperties: TMenuItem
      Caption = '.'
      OnClick = miNFPropertiesClick
    end
  end
  object puNullFolders: TPopupMenu
    Left = 1328
    Top = 96
    object miNFExploreFolder: TMenuItem
      Caption = '.'
      ImageIndex = 4
      OnClick = miNFExploreFolderClick
    end
    object miNFFolderProperties: TMenuItem
      Caption = '.'
      OnClick = miNFFolderPropertiesClick
    end
  end
  object puLength: TPopupMenu
    Tag = 3
    Left = 1233
    Top = 168
    object miLengthShowAll: TMenuItem
      Caption = '.'
      Checked = True
      GroupIndex = 1
      RadioItem = True
      OnClick = miLengthShowAllClick
    end
    object miLengthNonZero: TMenuItem
      Caption = '.'
      GroupIndex = 1
      RadioItem = True
      OnClick = miLengthNonZeroClick
    end
  end
  object ilTabs: TImageList
    DrawingStyle = dsTransparent
    ShareImages = True
    Left = 1344
    Top = 362
    Bitmap = {
      494C01010D00A402040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000004000000001002000000000000040
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E8E8E800E8E8E800E8E8E800E8E8
      E800E8E8E800E8E8E800E8E8E800E8E8E800E8E8E800E8E8E800E8E8E800E8E8
      E800E8E8E800E8E8E800E8E8E800E8E8E8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9C9C900FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00E8E8E8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9C9C900FCFCFC00C9C9C900FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00E8E8E8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9C9C900FCFCFC00C9C9C900FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00E8E8E8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9C9C900FCFCFC00C9C9C900FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00E8E8E8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9C9C900FCFCFC00C9C9C900FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00E8E8E8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9C9C900FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFCFC00FCFC
      FC00FCFCFC00FCFCFC00FCFCFC00E8E8E8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9C9C900C9C9C900C9C9C900C9C9
      C900C9C9C900C9C9C900C9C9C900C9C9C900C9C9C900C9C9C900C9C9C900C9C9
      C900C9C9C900C9C9C900C9C9C900C9C9C9000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C08A7500CB70
      3400D27E4100D37E4100D17C4100CD7A3F00B45F3F00B1B9C900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E2C0AA00CC8D
      6600BC6B3600BC6B3600BC6A3600BC6A3600BB6A3500BB6A3500BB693500BD6E
      3B00CA8B6300E3C2AE000000000000000000529CE2007185AC00C87E5900FFBA
      6600FFB76100FFB05E00FFB25D00FFB45C00DE88570087737E004C9BE6000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C57C4D00F8F1
      EA00F8F3ED00F8F3ED00F8F3ED00F8F3ED00FAF3EB00FAF2EA00F8F3ED00F8F3
      ED00F8F3ED00C37A4D0000000000000000003685D30093ACCC00E7AF7300FFB8
      5F00FEB05F00FEA75B00FDA05500FF974D00FD934D00B39FA2004E96DE000000
      00000000000000000000000000000000000000000000000000004DA3EA00469E
      E8003E9AE7003595E6001E8CE200208CE200218DE4001989E3001283E3000A81
      E100037DE0000079DF00000000000000000000000000E8D1D100D2BDBD00B5A3
      A300B09F9F00B09F9F00B09F9F00B09F9F00B09F9F00B09F9F00B09F9F00B09F
      9F00AF9E9E00B3A1A100D8C3C300000000000000000000000000C6804600F7F0
      E600F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3
      ED00F8F3ED00C1743C000000000000000000DDC3B500B7755C00FDD7B200FFD6
      8400FFCA6500FFC05E00FFB45600FFA75700FFC59200D67D5B00B7907F000000
      000000000000000000000000000000000000000000000000000055A7EB00B6E6
      F90095D1F1004BA7E8005AAFEB007DC2EE00BBEEFB00BAEEF900B7EDF900B3ED
      F900B2EDF900017DE200000000000000000000000000BAA8A800FFF2F200F9E0
      E000F6DEDE00F5DDDD00F3DBDB00F2DADA00F0D8D800EFD7D700EED6D600EBD4
      D400EAD3D300FFECEC00B7A5A500000000000000000000000000C7844800F8F1
      E800F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3
      ED00F8F3ED00C37A4100000000000000000000000000DDB29B00CF7A5A00FFE8
      C000ADAA8600A79E7D00A0927500F7CA9C00E4947500C8836500000000000000
      00000000000000000000000000000000000000000000000000005DABEB00B4E3
      F800329FE6003BABE900A8E9F8004EBAEB005AD6F30050D4F30048D2F20042D1
      F200B4EDF9000881E300000000000000000000000000B9A7A700FFFBFB00FFEA
      EA00FFE6E600FBE2E200F8DFDF00F4DCDC00F2DADA00EED6D600EAD3D300E8D1
      D100E6CFCF00FFF2F200B9A7A700000000000000000000000000C7864B00F8F2
      EB00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3
      ED00F8F3ED00C780450000000000000000000000000000000000CB9E8700707C
      960073ADE70081B1E3007DB2E7006C98C40074552C005CA4640059A8680059A7
      670056A3640054935600BFB2BA000000000000000000000000005DACEC0055AD
      EB0047AFEB00ACE9F900ADEAFA0056BBEB0062D9F4005AD6F30050D4F30049D2
      F300B7EDF9001185E400000000000000000000000000BEABAB00FFFBFB00FFEE
      EE00FFEAEA00FFE7E700FCE3E300F9E0E000F5DDDD00F2DADA00EFD7D700EBD4
      D400E9D2D200FFF2F200BCA9A900000000000000000000000000C8884D00F9F3
      EC00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3
      ED00F8F3ED00C884480000000000000000000000000000000000BBB7BA0073A4
      D600ACD1F200AED7FD00B0D4F50092C0E7005483890079CF940077CE8E0076CE
      8F0076CE91006BB474005A8F5A004C9BE60000000000000000005EADEB0083C3
      F000D3F3FC00D1F3FC00B2EDFA005BBCED006CDAF40062D9F4005AD6F30051D4
      F300BAEEFB001A8AE500000000000000000000000000C1AEAE00FFFDFD00FFF3
      F300FFEFEF00FFECEC00FFE9E900FDE4E400FAE1E100F6DEDE00F3DBDB00F1D9
      D900EED6D600FFF3F300C1AEAE00000000000000000000000000C88C4F00F9F4
      ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3
      ED00F8F3ED00C8864B00000000000000000000000000000000006B8EB700A7BF
      DB0096C5F100A1D0FB0096C6F300B6CFE400417AA70078CE8F0075CD890070CB
      83006ACB7B006AC97900609661004E96DE00000000000000000071B6EE009ED1
      F40078CAF00072C7F0006EC6F00060BEED0076DDF5006CDBF40064D9F4005BD6
      F300BEEFFB00238FE800000000000000000000000000C6B2B200FFFFFF00FFFE
      FE00FFFEFE00FFFDFD00FFFCFC00FFF6F600FFE7E700FDE4E400F9E0E000F5DD
      DD00F2DADA00FFF5F500C4B1B100000000000000000000000000C88C5000F8F3
      ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3
      ED00FAF4EF00C8874C0000000000000000000000000000000000617EA9005069
      9A006380AE007CA6D6005573A500435D9200446798007CD09F0077CE970071CD
      8E0072CD88009DD8AB006DB0700088A78B00000000000000000079B9F000DBF6
      FC009CE7F80095E5F8008FE3F70086E1F7007EDFF50076DDF5006DDBF40064D9
      F400C0F0FB002C94E900000000000000000000000000C9B5B500FFF7F700F0D8
      D800EAD3D300DEC8C800FFEBEB00FFFCFC00FFFCFC00FFFCFC00FFFCFC00FFFB
      FB00FFFBFB00FFFFFF00C9B5B500000000000000000000000000C88D5100F8F3
      ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3
      ED00F8F4F000C6864C0000000000000000000000000000000000000000004562
      9600415B9000415B9000415B9000415B90006F8F9E00849993007D948900758C
      7F00A4D5B10082BF850077AE7B000000000000000000000000008CC5F400DDF7
      FD00A2E8F8009DE7F80095E5F8008FE3F70087E1F7007FDFF60077DDF5006DDB
      F400C4F0FB003798EA00000000000000000000000000CAB6B600FFFBFB00F9E0
      E000F6DEDE00F1D9D900E6CFCF00E6CFCF00EED6D600EED6D600EBD4D400EAD3
      D300EAD3D300FFF7F700CCB8B800000000000000000000000000C88D5100F8F3
      ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F7F2EC00FBF7
      F300F5EFE900C380480000000000000000000000000000000000000000000000
      00004C6A9B00415D920046629800577987006E7A940073ADE70081B1E3007DB2
      E7006C98C40068916A000000000000000000000000000000000093C8F500E1F7
      FD00AAEAF900A3E8F9009DE7F80096E5F80090E3F70088E1F70080DFF60077DD
      F500C8F1FB00409EEB00000000000000000000000000CEBABA00FFFDFD00FEE5
      E500F9E0E000FBE2E200FDE4E400FFFBFB00FFFDFD00FFFCFC00FFFCFC00FFFB
      FB00FFFBFB00FFFEFE00D6C1C100000000000000000000000000C88D5200F9F5
      F100F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00FCE6CD00FAE5
      C900E2B68400D5A8840000000000000000000000000000000000000000000000
      0000000000000000000000000000BBB7BA0073A4D600ACD1F200AED7FD00B0D4
      F50092C0E7007D92AA000000000000000000000000000000000097CCF600F9FD
      FF00F0FBFE00F0FBFE00F0FCFE00EEFBFD00EFFBFD00EFFBFD00F0FBFD00F0FB
      FD00F7FDFE004AA3ED00000000000000000000000000CEBABA00FFFEFE00FFFF
      FF00FFFEFE00FFFEFE00FFFFFF00FFF8F800E1CBCB00E2CCCC00E2CCCC00E2CC
      CC00E8D1D100EAD3D300FFE6E600000000000000000000000000CA925A00FAF6
      F200F8F3ED00F8F3ED00F8F3ED00F8F3ED00F8F3ED00FFFBF800F6D8B400E1B0
      7D00DC9669000000000000000000000000000000000000000000000000000000
      00000000000000000000000000007AA0C500B8D0E70096C5F100A1D0FB0096C6
      F300B6CFE4004B93C70000000000000000000000000000000000B2DCFD00FAFE
      FF00FAFEFF00FAFEFF00FAFEFF00FAFEFF00FAFDFE00FAFDFF00FAFEFF00FAFE
      FF00FAFDFF0053A8EE00000000000000000000000000DBC5C500DDC7C700DEC8
      C800DEC8C800DEC8C800DEC8C800DAC4C4000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000D2A27400F8F3
      ED00F8F3ED00F8F3ED00F8F3ED00F8F2EC00F7F2EC00F2E6D700E2B27D00DC98
      6B00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000079A3C70034AEE50065B8E6008DC8F6003BAD
      E6001DA7E500319ED70000000000000000000000000000000000B6DFFE00A2D2
      FA009CD1F90097CDF80092CAF7008CC6F60085C2F5007EBFF40076BAF4006EB6
      F10065B2F0005DADF00000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E8CEB900D7AA
      7C00CA905500CA905500CA915500CB905500C98F5500CF9D6900DDB190000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000023A4DF0019A6E50019A6E50019A6
      E50019A6E50083ABC50000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000319DD5001BA5E40024A1
      DF0077A6C4000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000DFB49300D59D7400D1966800CE926300C7875600C3845200C384
      5200C3845200C3845200C3845200D0A17D000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B0B0B000A4A4
      A400000000000000000000000000000000000000000000000000000000000000
      0000A7A7A700ABABAB0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D7A17500F8F2ED00F7F0EA00F6EDE600F1E4DB00F0E2D800F0E2
      D800F0E2D800F0E2D800F0E2D800C58B5E0000000000DFB49300D59D7400D196
      6800CE926300CB8E5E00C98A5B00C7875600C3845200C3845200C3845200C384
      5200C3845200C3845200D0A17D00000000000000000000000000B8B8B800DBDB
      DB00B8B8B700BDAC96009C81600084643B0084643B009C816000BDAB9500B7B7
      B600D9D9D900B5B5B50000000000000000000000000000000000000000000000
      0000000000000000000000000000938EFF007C76FF00F0EDFF00000000000000
      000000000000000000000000000000000000000000000000000000000000E3BC
      9D00D9A78200E1AE8700FAF4F000EACBB200EACCB300E8C7AC00E8C7AC00E8C7
      AC00E8C8B000E8C8AE00F0E2D800C486540000000000D7A17500F8F2ED00F7F0
      EA00F6EDE600F4EAE200F3E7DE00F1E4DB00F0E2D800EAD6C800F2E5DC00FAF4
      F100F9F3F000FAF5F200C58B5E0000000000000000000000000000000000D3D3
      D300C3C0BE009C6B3B00A66C3500AE6F3700AE6F3700A66C3500A1764A00C5C4
      C300C6C6C5000000000000000000000000000000000000000000000000000000
      000000000000000000008F8BFF00A9A7FF00A7A5FF006B64FF00ECEAFF000000
      000000000000000000000000000000000000000000000000000000000000DBAA
      8300F9F3EF00E3B18C00FAF6F100EAC9AE00FFFFFF00E8C7AC00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F1E5DB00C686550000000000D9A47A00F9F3EE00EBD2
      BE00FFFFFF00EBD3BF00FFFFFF00EBD3C000FFFFFF00EAC7AD00ECD9CD00F1E4
      DB00F9F3F000F9F2EF00C68C5F00000000000000000000000000D1C1AE00A78D
      6F00AF784400BB8C5E00C2937100C4917400C38F7100BF906C00B88A5D00B486
      5900A58A6A00D1C1AE0000000000000000000000000000000000000000000000
      000000000000B1AFFF00B2B0FF00DDDDFF00BEBEFF00A7A5FF006C65FF00F2EF
      FF000000000000000000000000000000000000000000E6C3A800DDB19000E1AE
      8700F7ECE600E5B48F00FAF6F200E9C6AA00E9C6AC00E8C7AC00E8C7AC00E9C9
      B000E8C8B000E8CCB500F2E7DE00C88A590000000000DDA87E00F9F3EF00EBD0
      BA00EBD0BB0075B57A0075B57A0075B57A00EBD1BD00EACDB500FAF4F000EBD9
      CC00F1E4DB00FAF4F100C68A5C00000000000000000000000000A7855B00B37D
      4600C2997100D8AA8900EFDFCF00FAF6F300FAF5F300EFDFD100D7A78500BE94
      6C00B37D4600A7855B0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A4A2FF000000
      00000000000000000000000000000000000000000000DFB49100F9F5F100E6B7
      9500FAF5F000E7B79400FBF7F400E9C3A600FFFFFF00E8C7AC00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F7F1EB00CB8F5F0000000000DFAA8200F9F3EF00EACE
      B700FFFFFF0075B57A0094D49B0074B57900FFFFFF00EACFBA00FBF6F200FAF3
      F000EBD8CB00F2E6DD00C88D5F000000000000000000D0BAA000B0804A00C69B
      6F00D9AA8800FFFEEB00FFFAEE00FFFDF200FFFEF200FFFCEF00FFFDEB00D9A3
      7A00C2996C00B0804A00D0BAA00000000000000000000000000000000000C5C5
      FF0000000000FCFCFF0000000000000000007A7AFF0000000000BFBFFF009996
      FF000000000000000000000000000000000000000000E7BE9F00FBF6F300E6B7
      9400F9F3ED00E9BA9800FBF7F400E9C3A600E9C3A600E9C3A600E9C3A600E9C3
      A600E9C3A600E9C3A600FBF7F400CE93640000000000E1AE8700FAF4F000EACB
      B200EACCB30075B57A0074B5790073B47800EACEB70070B375006FB274006EB1
      7200E8C8AE00EAD7C900C48654000000000000000000C19E7500BF8F5800CDA3
      8100F0DBC100FFF7E600FAF2E300C5C0B600F1EDDE00FFFCE800FFF5DF00EFD4
      AF00C8997200BF8F5800C19E7500000000000000000000000000CACCFF00B4B5
      FF00000000000000000000000000000000007F7FFF00000000007D7DFF00BBBB
      FF0000000000847FFF00000000000000000000000000E9C1A300FBF8F400E7B9
      9800FBF8F500EBBD9B00FBF7F400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FBF7F400D1976A0000000000E3B18C00FAF6F100EAC9
      AE00FFFFFF00EAC9B000FFFFFF00E9CBB300FFFFFF006FB173008ED295006BAF
      6F00FFFFFF00F1E5DB00C68655000000000000000000BC8F5A00C99C6600CF9F
      8000FAF3E200FDF6E900F2F0E3008D8C8400817F7700D2CFC200FFFBEB00FAEC
      CC00C7906D00C99C6600BC8F5A000000000000000000C4C7FF00BBBEFF000000
      00000000000000000000F6F6FF00000000008080FF00000000007F7FFF000000
      0000000000009B99FF007E78FF00EFECFF0000000000EAC3A500FBF8F500E9BC
      9B00FAF3EE00ECBF9E00FBF7F4009CD5A50098D3A1008BCB930082C689007EC3
      84007AC1800076BE7C00FBF7F400D49B6F0000000000E5B48F00FAF6F200E9C6
      AA00E9C6AC00EAC7AC00E9C7AD00E9C9AE00E9C9B0006CB071006AAF6E0068AD
      6D00E8CCB500F2E7DE00C88A59000000000000000000C6986000CEA67100D1A5
      8900FAF6E900FDF8EE00FFFFF90081807900B1AEA400817F7700C9C6BA00FAF0
      D300C9967200CEA67100C698600000000000C5C8FF00D0D2FF00E8E8FF00E0E0
      FF000000000000000000E2E2FF000000000000000000000000009898FF009191
      FF0000000000BDBDFF00A6A4FF00827DFF0000000000ECC5A900FCF9F600EBBE
      9E00FBF8F500EFC6A800FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7
      F400FBF7F400FBF7F400FBF7F400D8A3780000000000E7B79400FBF7F400E9C3
      A600FFFFFF00E8C4A900FFFFFF00E9C6AA00FFFFFF00E8C7AC00FFFFFF00E8C8
      B000FFFFFF00F7F1EB00CB8F5F000000000000000000D9B28400D3AC7500D9B7
      9800F1E3D600FEFBF500F5F5F3009F9E9500F0F0E900F8F8F200BEB9AD00F0DA
      C200D2AA8700D3AC7500D9B284000000000000000000AFB3FF00EDEEFF00FBFB
      FF00000000000000000000000000F4F5FF00DADAFF00D7D7FF00D5D5FF00CFCE
      FF00C5C5FF00B4B3FF00807BFF00F8F6FF0000000000EDC8AD00FCF9F600ECC0
      A100FAF3EE00CACCA500E6C3A200EDC09F00EBBE9D00E7B79300E4B28C00E2AF
      8800E0AC8400DDA98000DCA57D00E2B6960000000000E9BA9800FBF7F40065A4
      FF0064A3FF0062A2FF0061A1FF005F9FFF005C9DFF005A9AFF005798FF005495
      FF005294FF00FBF7F400CE9364000000000000000000D6CAB300D3AD7700DFC4
      9A00DEBDAA00FFFFFF00F0F0EE00E7E5DA00FFFFF700FFFFF700FFFEF300DCB4
      9800DBC09600C2AA7E00E1CDB100000000000000000000000000B3B7FF000000
      0000B1B5FF00AFB2FF00000000000000000000000000A1A2FF00000000009897
      FF009392FF00918EFF00F2F1FF000000000000000000EFCAAF00FCF9F600F1CC
      B100FBF8F500FBF8F500FBF8F500FBF8F500FBF8F500FBF8F500FBF7F400F8EF
      E900FBF8F500DCAC8500000000000000000000000000EBBD9B00FBF7F40064A4
      FF0079BDFF0075BBFF0071B9FF006DB8FF0068B3FF0061B0FF005AABFF0054A7
      FF003B7DFF00FBF7F400D1976A0000000000000000002FA9DE0036A0C700DEBF
      8A00E2C9A700DFBFAE00F1E3DC00F3F1EC00F4F1EB00F1E2D900DCBAA300DFC3
      9E008CB1A9003DA8D2003CADDE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F0CCB100FCF9F600CCD1
      AE00E2C6A600E6C2A000E4C09D00E0B99400DDB48D00DBB28900E3B48F00DDAA
      8200DFAE8A00E5BDA000000000000000000000000000ECBF9E00FBF7F40065A4
      FF0064A3FF0060A0FF005D9EFF005899FF005496FF004D90FF00478BFF004284
      FF003D7FFF00FBF7F400D49B6F000000000082D0F10085D4F3006BC7E9003DA5
      C700E2C79200E6D1A900E0C2A600D5AE9600D5AB9200DEBDA000E4CFA600BFC1
      9E0048B3D700ACE3F60049BCEB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F2D1BA00FCF9F600FCF9
      F600FCF9F600FCF9F600FCF9F600FCF9F600FCF9F600FCF9F600FCF9F600E0B5
      93000000000000000000000000000000000000000000EFC6A800FBF7F400FBF7
      F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7
      F400FBF7F400FBF7F400D8A378000000000084D5F4006ECFF200B5E8F9006BCB
      EC0043AECE00ECC48800E9CB9400E7D09D00E7D09D00E9CB9400DEC28E003AAD
      D20086D5F1007FD4F40032B8ED00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F9E7DB00F4D3BD00F1CD
      B200EFCBB100ECC5A900E9C1A300E8BFA000E6BD9D00E4BA9900E3B79700E7C5
      AB000000000000000000000000000000000000000000F7E1D200F1C8AC00EDC0
      9F00EBBE9D00EBBC9A00E9BA9600E7B79300E6B59000E4B28C00E2AF8800E0AC
      8400DDA98000DCA57D00E2B69600000000000000000075D3F6006CD1F500BFEC
      FA006ACFF20076C4D500FBCD9600FAC17E00FAC17E00FBCD96007BC4D50074D3
      F30085D9F70036BFF20000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007FDAF9002EC2
      F60035C4F6000000000000000000000000000000000000000000000000002EC2
      F60036C5F6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000DDF2
      FB0055BEEA0044B5E700DDF1FA000000000000000000AAD6EE0044A0D70088C0
      E300EEF6FB000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DFB49300D59D7400D196
      6800CE926300CB8E5E00C98A5B00C7875600C3845200C3845200C3845200C384
      5200C3845200C3845200D0A17D0000000000C6A18C00C38E6800C08B6600BE88
      6400BB856100B9835F00B47E5C00B27C5A00B17B5800AE795700AE795700AD76
      5600AB755400A9735300A9715100C6A18C000000000000000000AAE1F70011A8
      E70051C6F20044BEEF0088D0F000000000000000000033A1DA0060C6F2003CAA
      E2001183C800AAD1EA0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D7A17500F8F2ED00F7F0
      EA00F6EDE600F4EAE200F3E7DE00F1E4DB00F0E2D800F0E2D800F0E2D800F0E2
      D800F0E2D800F0E2D800C58B5E0000000000C8926C00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00A97251000000000000000000AAE2F80033BB
      EF0082E0FE0077DAFC0011A4E300EEF8FD00BBE3F60024A6E2006AD7FF0067D0
      F9001992D400CCE5F300000000000000000000000000A2CAEE0076B2E6003E91
      DB00348CD900348CD900348CD900348CD900348CD900348CD900348CD900348C
      D900348BD900398FDA0085B9E9000000000000000000D9A47A00F9F3EE00EBD2
      BE0000000000EBD3BF00000000000000000000000000EAC7AD00000000000000
      000000000000F0E2D800C68C5F0000000000C8926C00FFFFFF00FFBF6800FFFF
      FF00C7C7C700C6C6C600C3C3C300C1C1C100BFBFBF00BDBDBD00BDBDBD00BBBB
      BB00B9B9B900B9B9B900FFFFFF00A972510000000000000000000000000077D1
      F4003EC1F10085E2FF003ABBEE0099D8F30066C3EC004DC2F1006CD8FF0036AE
      E50088C7E800000000000000000000000000000000004799DD00DEF1FA00A8DD
      F4009EDBF40096DAF3008ED8F30086D7F3007FD4F20079D3F20072D2F1006CD0
      F10069CFF100C2EAF8003F95DB000000000000000000DDA87E00F9F3EF00EBD0
      BA00EBD0BB00EBD0BB00EBD0BB00EBD0BB00EBD1BD00EACDB500EACDB500EACD
      B500EACDB500F0E2D800C68A5C0000000000CA946E00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00AA7353000000000000000000000000000000
      000044C0F00048C5F30072D8FA0022AEE80052C6F30073DBFF0041BBED0066BE
      E80000000000000000000000000000000000000000003B97DB00EFFAFE00A1E9
      F90091E5F80081E1F70072DEF60063DAF50054D7F40047D3F30039D0F2002ECD
      F10026CBF000CAF2FB003B97DB000000000000000000DFAA8200F9F3EF00EACE
      B70000000000EBD0BB00000000000000000000000000EACFBA00FBF6F2000000
      000000000000F0E2D800C88D5F0000000000CC976F00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFB95E00FFFFFF00C1C1C100BEBEBE00BABABA00B7B7
      B700FFFFFF00FFFFFF00FFFFFF00AC7554000000000000000000000000000000
      0000EEF9FE0011AFEB007DDEFD0063D5FC0067DAFF005ED0F90033B0E600EEF8
      FD0000000000000000000000000000000000000000003C9DDB00F2FAFD00B3ED
      FA00A4E9F90095E6F80085E2F70076DEF60065DBF50057D7F40049D4F3003BD1
      F20030CEF100CCF2FB003B9BDB000000000000000000E1AE8700FAF4F000EACB
      B200EACCB300EACCB300EACCB300EACCB300EACEB700E8C7AC00E8C7AC00E8C8
      B000E8C8AE00F0E2D800C486540000000000D19C7300FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00B07A580044CAF80000B5F40000B3F20033C1
      F30044C4F30044C2F2005DD2FA0061D9FF005BD7FF005CD0FA0033B2E80044B7
      E80022A7E2000095DB00008FD60044A8DD00000000003BA3DB00F6FCFE00C8F2
      FC00B9EFFB00ACECFA009CE8F9008BE3F7007CE0F6006CDCF6005DD9F5004FD6
      F40044D3F300D0F3FC003BA2DB000000000000000000E3B18C00FAF6F100EAC9
      AE0000000000EAC9B000000000000000000000000000E8C7AC00000000000000
      000000000000F1E5DB00C686550000000000D49E7500FFFFFF00FFFFFF00FFFF
      FF00FFB95E00FFFFFF00C1C1C100BEBEBE00BABABA00B7B7B700FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00B27C5A0044CCFA007ADFFD00A4ECFF0081E0
      FD0075DBFB0072DAFB0079E0FF0061DAFF005CD8FF006BDBFF006FD5FA0065D0
      F80075D7FB0085DEFF005FCBF50044AEE100000000003BA8DB00FEFFFF00F8FD
      FF00F6FDFF00F5FCFF00F3FCFE00D8F6FC0094E6F80085E3F70076DFF60068DB
      F5005CD8F400D7F4FC003BA7DB000000000000000000E5B48F00FAF6F200E9C6
      AA00E9C6AC00EAC7AC00E9C7AD00E9C9AE00E9C9B000E8C7AC00E9C9B000E8C8
      B000E8CCB500F2E7DE00C88A590000000000D5A07600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FEFEFE00FEFEFE00FEFEFE00FDFDFD00FDFDFD00FDFDFD00FDFD
      FD00FDFDFD00FCFCFC00FFFFFF00B57E5C0044CEFB0022C4F90000B8F60011BB
      F60044C8F60033C1F40067D9FC0064DBFF0060D9FF005FD3FB0033B7EC0044BC
      EC0022ADE700009DE1001AA8E50044B3E5000000000039ADDB00E8F6FB0094D4
      EF0088CEEE0073C1E900C9E9F600F2FCFE00F3FCFE00F2FCFE00F0FCFE00EFFB
      FE00EEFBFE00FEFFFF003CAEDB000000000000000000E7B79400FBF7F400E9C3
      A60000000000E8C4A900000000000000000000000000E8C7AC00000000000000
      000000000000F7F1EB00CB8F5F0000000000D8A27900FFFFFF00FFFFFF00FFFF
      FF00FFB95E00FFFFFF00C1C1C100BEBEBE00BABABA00B7B7B700FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00B7815E00CCF2FE00CCF2FE00000000000000
      0000EEFAFE0011B9F40083E2FE0070DEFE0071DDFF0066D5FB0033B9EE00EEF9
      FD000000000000000000CCECF900CCEBF9000000000040AEDC00F1FAFD0094DE
      F50093DCF40081D5F2006ACAED006CCBEA0085D3EF0080D2EF007AD0EF0076CF
      EE0072CFEE00E9F7FB003EB2DC000000000000000000E9BA9800FBF7F400E9C3
      A600E9C3A600E9C3A600E9C3A600E9C3A600E9C3A600E9C3A600E9C3A600E9C3
      A600E9C3A600FBF7F400CE93640000000000D9A37900FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00FEFEFE00FEFEFE00FEFE
      FE00FDFDFD00FDFDFD00FFFFFF00BA8560000000000000000000000000000000
      000044CCF9004DD0FA0089E5FE0011B7F30058D0F90081E1FF0046C7F50066CB
      F200000000000000000000000000000000000000000041B4DC00F7FCFE008EE4
      F80091DEF5009FE0F500ACE1F600EFFBFE00F4FDFE00F3FCFE00F1FCFE00EFFB
      FE00EEFBFE00FAFDFF0058BCE0000000000000000000EBBD9B00FBF7F4000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FBF7F400D1976A0000000000DBA47A00FFFFFF00FFBF6800FFFF
      FF00C7C7C700C6C6C600C3C3C300C1C1C100BFBFBF00BDBDBD00BDBDBD00BBBB
      BB00B9B9B900B9B9B900FFFFFF00BD87630000000000000000000000000088E0
      FD0044D0FB0091E8FF0057D3FA0066D3F80066D1F70056D0F9007EE0FF003AC2
      F40099DDF700000000000000000000000000000000003CB5DB00FDFEFE00FEFF
      FF00FEFEFF00FDFEFF00FEFFFF00EAF7FB006EC8E5006FC9E4006FC9E4006FC9
      E4007DCFE70084D0E800BAE5F2000000000000000000ECBF9E00FBF7F4009CD5
      A50098D3A10094D09D0090CE98008BCB930087C98E0082C689007EC384007AC1
      800076BE7C00FBF7F400D49B6F0000000000DCA77B00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00C08B66000000000000000000BBEEFE002DCC
      FC0087E5FE0091E9FF0015C0F800DDF5FE00BBEBFC0029C1F50080E1FF0072D9
      FC0011B2EE00CCEEFB0000000000000000000000000059C2E00061C3E20063C4
      E30063C4E30063C4E30062C4E30056C0E0000000000000000000000000000000
      00000000000000000000000000000000000000000000EFC6A800FBF7F400FBF7
      F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7F400FBF7
      F400FBF7F400FBF7F400D8A3780000000000DDAD8600E8B99200E8B99200E8B9
      9200E8B99200E8B99200E8B99200E8B99200E8B99200E8B99200E8B99200E8B9
      9200E8B99200E8B99200E8B99200C1917000000000000000000099E7FF0022C9
      FD0067DCFE0079E0FE0044CDFB00000000000000000033C5F6007ADDFD0051CE
      F90011B4F000AAE3F90000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F7E1D200F1C8AC00EDC0
      9F00EBBE9D00EBBC9A00E9BA9600E7B79300E6B59000E4B28C00E2AF8800E0AC
      8400DDA98000DCA57D00E2B6960000000000DBC3B600DEB49200DCA77B00DCA6
      7A00DAA47A00D8A27900D5A07600D49E7500D29D7300CF9A7200CF9A7200CE99
      7000CB966F00C9946C00C79E8000DBC3B600000000000000000000000000CCF3
      FF0044D2FE0000BFFC00AAE9FE00000000000000000099E3FB0000B6F50044C8
      F600DDF5FD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000400000000100010000000000000200000000000000000000
      000000000000000000000000FFFFFF00FFFF000000000000FFFF000000000000
      FFFF000000000000FFFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFF000000000000FFFF000000000000
      FFFF000000000000FFFF000000000000FFFFC03FFFFFFFFFC003001FFFFFFFFF
      C003001FC0038001C003001FC0038001C003803FC0038001C003C001C0038001
      C003C000C0038001C003C000C0038001C003C000C0038001C003E001C0038001
      C003F003C0038001C003FE03C0038001C007FE03C00380FFC00FFE03C003FFFF
      C01FFF03FFFFFFFFFFFFFF87FFFFFFFFF800FFFFCFF3FFFFF8008001C003FE3F
      E0008001E007FC1FE0008001C003F80F80008001C003E203800080018001E207
      800080018001C603800080018001840080008001800104008000800180018E00
      800080018001C001800380018001ED5F800380010001ED47800F80010001ED57
      800F80018003C447FFFFFFFFC7E7FFFFFFFFFFFFE187FFFF80010000C183FFFF
      80010000C00380018BB90000E007800180010000F00F80018B990000F00F8001
      80010000000080018BB900000000800180010000000080018BB90000300C8001
      80010000F00F80019FF90000E007800180010000C00380FF80010000C183FFFF
      80010000E187FFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
end
