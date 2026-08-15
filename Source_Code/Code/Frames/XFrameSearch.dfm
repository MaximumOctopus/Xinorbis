object FrameSearch: TFrameSearch
  Left = 0
  Top = 0
  Width = 1324
  Height = 651
  TabOrder = 0
  OnResize = FrameResize
  object pcSearch: TPageControl
    Left = 0
    Top = 0
    Width = 1324
    Height = 651
    ActivePage = tsSearch
    Align = alClient
    TabOrder = 0
    OnChange = pcSearchChange
    object tsSearch: TTabSheet
      object Panel1: TPanel
        Left = 0
        Top = 501
        Width = 1316
        Height = 120
        Align = alBottom
        TabOrder = 0
        DesignSize = (
          1316
          120)
        object sbSettings: TSpeedButton
          Left = 1290
          Top = 95
          Width = 23
          Height = 22
          Anchors = [akTop, akRight]
          OnClick = sbSettingsClick
        end
        object sbPagePrevious: TSpeedButton
          Left = 10
          Top = 95
          Width = 44
          Height = 22
          OnClick = sbPagePreviousClick
        end
        object sbPageNext: TSpeedButton
          Left = 100
          Top = 95
          Width = 44
          Height = 22
          OnClick = sbPageNextClick
        end
        object lPageNumber: TLabel
          Left = 60
          Top = 97
          Width = 34
          Height = 15
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
        end
        object lShowing: TLabel
          Left = 150
          Top = 96
          Width = 49
          Height = 15
          Caption = 'lShowing'
        end
        object pICSearch: TPanel
          Left = 10
          Top = 4
          Width = 1303
          Height = 84
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 0
        end
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1316
        Height = 501
        Align = alClient
        TabOrder = 1
        object Panel3: TPanel
          Left = 1148
          Top = 1
          Width = 167
          Height = 499
          Align = alRight
          TabOrder = 0
          object sbSCAccessed: TSpeedButton
            Left = 14
            Top = 452
            Width = 23
            Height = 22
            OnClick = sbSCAccessedClick
          end
          object sbSCModified: TSpeedButton
            Tag = 1
            Left = 43
            Top = 452
            Width = 23
            Height = 22
            OnClick = sbSCAccessedClick
          end
          object sbSCOwner: TSpeedButton
            Tag = 2
            Left = 72
            Top = 452
            Width = 23
            Height = 22
            OnClick = sbSCAccessedClick
          end
          object sbSCAttributes: TSpeedButton
            Tag = 3
            Left = 101
            Top = 452
            Width = 23
            Height = 22
            OnClick = sbSCAccessedClick
          end
          object sbSaveSearch: TSpeedButton
            Left = 130
            Top = 452
            Width = 23
            Height = 22
            OnClick = sbSaveSearchClick
          end
          object lGaugeQuantity: TLabel
            Left = 6
            Top = 160
            Width = 9
            Height = 15
            Caption = '...'
          end
          object lGaugeSize: TLabel
            Left = 6
            Top = 344
            Width = 9
            Height = 15
            Caption = '...'
          end
          object gaugeQuantity: TGauge
            Left = 6
            Top = 9
            Width = 145
            Height = 145
            BorderStyle = bsNone
            Color = 3355443
            ForeColor = clGray
            Kind = gkPie
            ParentColor = False
            Progress = 20
          end
          object gaugeSize: TGauge
            Left = 6
            Top = 193
            Width = 145
            Height = 145
            BorderStyle = bsNone
            Color = 3355443
            ForeColor = clGray
            Kind = gkPie
            ParentColor = False
            Progress = 20
          end
          object cbSearchShowPath: TCheckBox
            Left = 14
            Top = 480
            Width = 97
            Height = 17
            Caption = '.'
            TabOrder = 0
            OnClick = cbSearchShowPathClick
          end
          object cbSearchColourCode: TCheckBox
            Left = 13
            Top = 503
            Width = 97
            Height = 17
            Caption = '.'
            TabOrder = 1
            OnClick = cbSearchColourCodeClick
          end
        end
        object Panel4: TPanel
          Left = 1
          Top = 1
          Width = 1147
          Height = 499
          Align = alClient
          Caption = 'Panel3'
          TabOrder = 1
          object Panel7: TPanel
            Left = 1
            Top = 1
            Width = 1145
            Height = 56
            Align = alTop
            TabOrder = 0
            object sbQuickSearch: TSpeedButton
              Left = 0
              Top = 0
              Width = 23
              Height = 22
              PopupMenu = puQuickSearch
            end
            object sbGoSearch: TSpeedButton
              Left = 29
              Top = 0
              Width = 23
              Height = 22
              OnClick = sbGoSearchClick
            end
            object sbSearchHelp: TSpeedButton
              Left = 1070
              Top = 29
              Width = 23
              Height = 22
              OnClick = sbSearchHelpClick
            end
            object sbSearchSyntax: TSpeedButton
              Left = 1099
              Top = 29
              Width = 23
              Height = 22
              OnClick = sbSearchSyntaxClick
            end
            object lSearchDetails: TLabel
              Left = 8
              Top = 35
              Width = 22
              Height = 15
              Caption = 'N/A'
            end
            object eSearch: TComboBox
              Left = 58
              Top = 0
              Width = 1064
              Height = 23
              TabOrder = 0
            end
          end
          object sgSearchResults: TStringGrid
            Left = 1
            Top = 57
            Width = 1145
            Height = 441
            Align = alClient
            ColCount = 13
            FixedCols = 0
            TabOrder = 1
            ColWidths = (
              116
              118
              224
              64
              64
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
      end
    end
    object tsProperties: TTabSheet
      ImageIndex = 3
    end
  end
  object puQuickSearch: TPopupMenu
    Left = 873
    Top = 584
  end
  object puSearch: TPopupMenu
    OnPopup = puSearchPopup
    Left = 954
    Top = 585
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
    object miSSave: TMenuItem
      Caption = '.'
      ImageIndex = 66
      OnClick = miSSaveClick
    end
  end
end
