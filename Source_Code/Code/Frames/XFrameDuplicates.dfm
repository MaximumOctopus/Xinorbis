object Frame2: TFrame2
  Left = 0
  Top = 0
  Width = 1240
  Height = 655
  TabOrder = 0
  OnResize = FrameResize
  object pcDuplicates: TPageControl
    Left = 0
    Top = 0
    Width = 1240
    Height = 655
    ActivePage = tsDuplicatesName
    Align = alClient
    TabOrder = 0
    object tsDuplicatesName: TTabSheet
      Caption = 'tsDuplicatesName'
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 1232
        Height = 24
        Align = alTop
        Caption = 'Panel5'
        TabOrder = 0
        object sbDNSave: TSpeedButton
          Left = 80
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDNSaveClick
        end
        object sbDNCSV: TSpeedButton
          Left = 109
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDNCSVClick
        end
        object sbDNClipboard: TSpeedButton
          Left = 138
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDNClipboardClick
        end
        object sbDNGo: TSpeedButton
          Left = 0
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDNGoClick
        end
        object sbDNHelp: TSpeedButton
          Left = 29
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDNHelpClick
        end
        object lDNStatus: TLabel
          Left = 184
          Top = 3
          Width = 49
          Height = 15
          Caption = 'lDSStatus'
        end
      end
      object sgDuplicatesName: TStringGrid
        Left = 0
        Top = 24
        Width = 1232
        Height = 601
        Align = alClient
        ColCount = 2
        FixedCols = 0
        RowCount = 2
        TabOrder = 1
      end
    end
    object tsDuplicatesSize: TTabSheet
      Caption = 'tsDuplicatesSize'
      ImageIndex = 1
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 1232
        Height = 24
        Align = alTop
        TabOrder = 0
        object sbDSSave: TSpeedButton
          Left = 80
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDSSaveClick
        end
        object sbDSCSV: TSpeedButton
          Left = 109
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDSCSVClick
        end
        object sbDSClipboard: TSpeedButton
          Left = 138
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDSClipboardClick
        end
        object sbDSGo: TSpeedButton
          Left = 0
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDSGoClick
        end
        object sbDSHelp: TSpeedButton
          Left = 29
          Top = 1
          Width = 23
          Height = 22
          OnClick = sbDSHelpClick
        end
        object lDSStatus: TLabel
          Left = 184
          Top = 3
          Width = 49
          Height = 15
          Caption = 'lDSStatus'
        end
      end
      object sgDuplicatesSize: TStringGrid
        Left = 0
        Top = 24
        Width = 1232
        Height = 601
        Align = alClient
        ColCount = 2
        FixedCols = 0
        RowCount = 2
        TabOrder = 1
      end
    end
  end
  object puSearch: TPopupMenu
    OnPopup = puSearchPopup
    Left = 266
    Top = 353
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
    end
    object miMoveMenu: TMenuItem
      Caption = '.'
      ImageIndex = 47
      object miMoveSelected: TMenuItem
        Caption = '.'
        OnClick = miMoveSelectedClick
      end
    end
    object miDeleteMenu: TMenuItem
      Caption = '.'
      ImageIndex = 46
      object miDeleteSelected: TMenuItem
        Caption = '.'
        OnClick = miDeleteSelectedClick
      end
    end
    object N23: TMenuItem
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
