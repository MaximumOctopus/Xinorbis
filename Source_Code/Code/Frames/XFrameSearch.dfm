object FrameSearch: TFrameSearch
  Left = 0
  Top = 0
  Width = 1324
  Height = 651
  TabOrder = 0
  object pcSearch: TPageControl
    Left = 0
    Top = 0
    Width = 1324
    Height = 651
    ActivePage = tsSearch
    Align = alClient
    TabOrder = 0
    object tsSearch: TTabSheet
      object Panel1: TPanel
        Left = 0
        Top = 536
        Width = 1316
        Height = 85
        Align = alBottom
        Caption = 'Panel1'
        TabOrder = 0
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1316
        Height = 536
        Align = alClient
        TabOrder = 1
        object Panel3: TPanel
          Left = 1130
          Top = 1
          Width = 185
          Height = 534
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
            Left = 43
            Top = 452
            Width = 23
            Height = 22
          end
          object sbSCOwner: TSpeedButton
            Left = 72
            Top = 452
            Width = 23
            Height = 22
          end
          object sbSCAttributes: TSpeedButton
            Left = 101
            Top = 452
            Width = 23
            Height = 22
          end
          object sbSaveSearch: TSpeedButton
            Left = 130
            Top = 452
            Width = 23
            Height = 22
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
          Width = 1129
          Height = 534
          Align = alClient
          Caption = 'Panel3'
          TabOrder = 1
          object Panel7: TPanel
            Left = 1
            Top = 1
            Width = 1127
            Height = 56
            Align = alTop
            TabOrder = 0
            DesignSize = (
              1127
              56)
            object sbQuickSearch: TSpeedButton
              Left = 0
              Top = 0
              Width = 23
              Height = 22
              OnClick = sbQuickSearchClick
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
            object Label1: TLabel
              Left = 8
              Top = 35
              Width = 22
              Height = 15
              Caption = 'N/A'
            end
            object eSearch: TEdit
              Left = 58
              Top = 0
              Width = 1064
              Height = 23
              Anchors = [akLeft, akTop, akRight]
              TabOrder = 0
              OnChange = eSearchChange
              OnKeyPress = eSearchKeyPress
            end
          end
          object sgSearchResults: TStringGrid
            Left = 1
            Top = 57
            Width = 1127
            Height = 476
            Align = alClient
            ColCount = 3
            FixedCols = 0
            TabOrder = 1
            ColWidths = (
              116
              118
              224)
          end
        end
      end
    end
    object tsDuplicatesName: TTabSheet
      ImageIndex = 1
    end
    object tsDuplicatesSize: TTabSheet
      ImageIndex = 2
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 1316
        Height = 24
        Align = alTop
        Caption = 'Panel5'
        TabOrder = 0
        object SpeedButton1: TSpeedButton
          Left = 80
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton2: TSpeedButton
          Left = 109
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton3: TSpeedButton
          Left = 138
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton4: TSpeedButton
          Left = 0
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton5: TSpeedButton
          Left = 29
          Top = 1
          Width = 23
          Height = 22
        end
      end
      object StringGrid1: TStringGrid
        Left = 0
        Top = 24
        Width = 1316
        Height = 597
        Align = alClient
        ColCount = 2
        FixedCols = 0
        RowCount = 2
        TabOrder = 1
      end
    end
    object tsProperties: TTabSheet
      ImageIndex = 3
      object StringGrid2: TStringGrid
        Left = 0
        Top = 24
        Width = 1316
        Height = 597
        Align = alClient
        ColCount = 2
        FixedCols = 0
        RowCount = 2
        TabOrder = 0
      end
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 1316
        Height = 24
        Align = alTop
        Caption = 'Panel5'
        TabOrder = 1
        object SpeedButton6: TSpeedButton
          Left = 138
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton7: TSpeedButton
          Left = 109
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton8: TSpeedButton
          Left = 80
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton9: TSpeedButton
          Left = 29
          Top = 1
          Width = 23
          Height = 22
        end
        object SpeedButton10: TSpeedButton
          Left = 0
          Top = 1
          Width = 23
          Height = 22
        end
      end
    end
  end
  object puQuickSearch: TPopupMenu
    Left = 873
    Top = 584
  end
  object puSearch: TPopupMenu
    Left = 954
    Top = 585
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
    object miSSave: TMenuItem
      Caption = '.'
      ImageIndex = 66
    end
  end
end
