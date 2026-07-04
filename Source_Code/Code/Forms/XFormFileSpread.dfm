object FormFileSpread: TFormFileSpread
  Left = 0
  Top = 0
  Caption = 'FormFileSpread'
  ClientHeight = 729
  ClientWidth = 1303
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnConstrainedResize = FormConstrainedResize
  OnShow = FormShow
  TextHeight = 15
  object pBottom: TPanel
    Left = 0
    Top = 705
    Width = 1303
    Height = 24
    Align = alBottom
    Caption = '0'
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 209
    Height = 705
    Align = alLeft
    TabOrder = 1
    object Panel3: TPanel
      Left = 1
      Top = 201
      Width = 207
      Height = 503
      Align = alClient
      TabOrder = 0
      object sbShow: TSpeedButton
        Left = 7
        Top = 225
        Width = 195
        Height = 22
        OnClick = sbShowClick
      end
      object sbHelp: TSpeedButton
        Left = 7
        Top = 253
        Width = 195
        Height = 22
        OnClick = sbHelpClick
      end
      object sbCSVReport: TSpeedButton
        Left = 7
        Top = 337
        Width = 195
        Height = 22
        Caption = 'CSV'
        OnClick = sbCSVReportClick
      end
      object gbUsers: TGroupBox
        Left = 7
        Top = 6
        Width = 195
        Height = 59
        TabOrder = 0
        object cbUsers: TComboBox
          Left = 16
          Top = 24
          Width = 172
          Height = 23
          Style = csDropDownList
          TabOrder = 0
          OnChange = rbMulticolouredClick
        end
      end
      object gbChart: TGroupBox
        Left = 7
        Top = 71
        Width = 195
        Height = 74
        TabOrder = 1
        object rbMulticoloured: TRadioButton
          Left = 19
          Top = 24
          Width = 169
          Height = 17
          Caption = '.'
          TabOrder = 0
          OnClick = rbMulticolouredClick
        end
        object rbGradient: TRadioButton
          Left = 19
          Top = 47
          Width = 169
          Height = 17
          Caption = '.'
          TabOrder = 1
          OnClick = rbMulticolouredClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 7
        Top = 151
        Width = 195
        Height = 58
        TabOrder = 2
        object cbLogarithmic: TCheckBox
          Left = 19
          Top = 24
          Width = 169
          Height = 17
          Caption = '.'
          TabOrder = 0
          OnClick = cbLogarithmicClick
        end
      end
      object cbAutoRefresh: TCheckBox
        Left = 7
        Top = 281
        Width = 195
        Height = 17
        Caption = '.'
        TabOrder = 3
      end
    end
    object pcFileSpread: TPageControl
      Left = 1
      Top = 1
      Width = 207
      Height = 200
      ActivePage = tsFileSize
      Align = alTop
      TabOrder = 1
      OnChange = pcFileSpreadChange
      object tsFileSize: TTabSheet
        object lBGR: TLabel
          Left = 3
          Top = 3
          Width = 3
          Height = 15
          Caption = '.'
        end
        object Label2: TLabel
          Left = 35
          Top = 119
          Width = 3
          Height = 15
          Caption = '.'
        end
        object eResolution: TEdit
          Left = 22
          Top = 26
          Width = 62
          Height = 23
          Alignment = taRightJustify
          TabOrder = 0
          Text = '512'
          OnEnter = eResolutionEnter
          OnExit = eResolutionExit
          OnKeyPress = eResolutionKeyPress
        end
        object cbResolutionUnits: TComboBox
          Left = 90
          Top = 26
          Width = 108
          Height = 23
          Style = csDropDownList
          TabOrder = 1
        end
        object cbRange: TCheckBox
          Left = 3
          Top = 67
          Width = 97
          Height = 17
          Caption = '.'
          TabOrder = 2
        end
        object eRangeFrom: TEdit
          Left = 22
          Top = 90
          Width = 62
          Height = 23
          Alignment = taRightJustify
          TabOrder = 3
          Text = '0'
          OnEnter = eResolutionEnter
          OnExit = eResolutionExit
          OnKeyPress = eResolutionKeyPress
        end
        object cbRangeFromUnits: TComboBox
          Left = 90
          Top = 90
          Width = 108
          Height = 23
          Style = csDropDownList
          TabOrder = 4
        end
        object eRangeTo: TEdit
          Left = 22
          Top = 140
          Width = 62
          Height = 23
          Alignment = taRightJustify
          TabOrder = 5
          Text = '512'
          OnEnter = eResolutionEnter
          OnExit = eResolutionExit
          OnKeyPress = eResolutionKeyPress
        end
        object cbRangeToUnits: TComboBox
          Left = 90
          Top = 140
          Width = 108
          Height = 23
          Style = csDropDownList
          TabOrder = 6
        end
      end
      object tsBenford: TTabSheet
        Caption = 'Benford'#39's Law'
        ImageIndex = 1
        object sbMoreDetail: TSpeedButton
          Left = 0
          Top = 139
          Width = 196
          Height = 22
          OnClick = sbMoreDetailClick
        end
        object cbNormalDistribution: TCheckBox
          Left = 11
          Top = 11
          Width = 166
          Height = 17
          Caption = '.'
          TabOrder = 0
          OnClick = rbMulticolouredClick
        end
      end
    end
  end
  object vtcSpread: TChart
    Left = 209
    Top = 0
    Width = 1094
    Height = 705
    Title.Text.Strings = (
      'TChart')
    Align = alClient
    TabOrder = 2
    OnMouseMove = vtcSpreadMouseMove
    ExplicitTop = -6
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      HoverElement = []
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Series2: TBarSeries
      HoverElement = []
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object puChart: TPopupMenu
    Left = 82
    Top = 617
    object miOptions: TMenuItem
      Caption = '.'
      Enabled = False
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object miSaveChart: TMenuItem
      Caption = '.'
      OnClick = miSaveChartClick
    end
    object miCopyToClipboard: TMenuItem
      Caption = '.'
      OnClick = miCopyToClipboardClick
    end
    object miSaveData: TMenuItem
      Caption = '.'
      OnClick = miSaveDataClick
    end
  end
end
