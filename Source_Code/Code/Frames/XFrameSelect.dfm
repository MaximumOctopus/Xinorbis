object FrameSelect: TFrameSelect
  Left = 0
  Top = 0
  Width = 1013
  Height = 639
  TabOrder = 0
  object pcSelect: TPageControl
    Left = 0
    Top = 0
    Width = 1013
    Height = 639
    ActivePage = tsScan
    Align = alClient
    TabOrder = 0
    object tsScan: TTabSheet
      DesignSize = (
        1005
        609)
      object bScanNow: TBitBtn
        Left = 3
        Top = 3
        Width = 75
        Height = 25
        TabOrder = 0
        OnClick = bScanNowClick
      end
      object dcbSelect: TDriveComboBox
        Left = 3
        Top = 34
        Width = 594
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        DirList = dlbSelect
        TabOrder = 1
      end
      object dlbSelect: TDirectoryListBox
        Left = 0
        Top = 65
        Width = 1005
        Height = 544
        Align = alBottom
        Anchors = [akLeft, akTop, akRight, akBottom]
        TabOrder = 2
        OnChange = dlbSelectChange
      end
      object bSelect: TBitBtn
        Left = 603
        Top = 34
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        TabOrder = 3
        OnClick = bSelectClick
      end
      object bExcludeFiles: TBitBtn
        Left = 846
        Top = 34
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        TabOrder = 4
        OnClick = bExcludeFilesClick
      end
      object bExcludeFolders: TBitBtn
        Left = 765
        Top = 34
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        TabOrder = 5
        OnClick = bExcludeFoldersClick
      end
      object bCombine: TBitBtn
        Left = 927
        Top = 34
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        TabOrder = 6
        OnClick = bCombineClick
      end
      object bFavourites: TBitBtn
        Left = 684
        Top = 34
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        TabOrder = 7
        OnClick = bFavouritesClick
      end
      object bExplore: TBitBtn
        Left = 927
        Top = 3
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        TabOrder = 8
        OnClick = bExploreClick
      end
      object cbScanPath: TComboBox
        Left = 84
        Top = 4
        Width = 837
        Height = 23
        TabOrder = 9
      end
    end
    object tsImport: TTabSheet
      ImageIndex = 1
      DesignSize = (
        1005
        609)
      object mImport: TMemo
        Left = 191
        Top = 51
        Width = 811
        Height = 555
        Anchors = [akLeft, akTop, akRight, akBottom]
        Lines.Strings = (
          'mImport')
        TabOrder = 0
      end
      object bSelectImport: TBitBtn
        Left = 3
        Top = 3
        Width = 182
        Height = 25
        TabOrder = 1
        OnClick = bSelectImportClick
      end
      object bOpenImport: TBitBtn
        Left = 3
        Top = 51
        Width = 182
        Height = 25
        TabOrder = 2
        OnClick = bOpenImportClick
      end
      object eImportFileName: TEdit
        Left = 191
        Top = 3
        Width = 811
        Height = 23
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 3
      end
    end
    object tsScanHistory: TTabSheet
      ImageIndex = 2
      OnResize = tsScanHistoryResize
      object Panel1: TPanel
        Left = 0
        Top = 568
        Width = 1005
        Height = 41
        Align = alBottom
        TabOrder = 0
        object bShowAll: TBitBtn
          Left = 8
          Top = 8
          Width = 97
          Height = 25
          TabOrder = 0
          OnClick = bShowAllClick
        end
        object bShowYesterday: TBitBtn
          Tag = 1
          Left = 111
          Top = 8
          Width = 97
          Height = 25
          TabOrder = 1
          OnClick = bShowAllClick
        end
        object bShowThisWeek: TBitBtn
          Tag = 2
          Left = 216
          Top = 8
          Width = 97
          Height = 25
          TabOrder = 2
          OnClick = bShowAllClick
        end
        object bShowThisMonth: TBitBtn
          Tag = 3
          Left = 319
          Top = 6
          Width = 97
          Height = 25
          TabOrder = 3
          OnClick = bShowAllClick
        end
        object bShowLastWeek: TBitBtn
          Tag = 4
          Left = 422
          Top = 8
          Width = 97
          Height = 25
          TabOrder = 4
          OnClick = bShowAllClick
        end
        object bShowLastMonth: TBitBtn
          Tag = 5
          Left = 525
          Top = 6
          Width = 97
          Height = 25
          TabOrder = 5
          OnClick = bShowAllClick
        end
      end
      object sgScanHistory: TStringGrid
        Left = 0
        Top = 0
        Width = 1005
        Height = 568
        Align = alClient
        DefaultDrawing = False
        FixedCols = 0
        TabOrder = 1
        OnDrawCell = sgScanHistoryDrawCell
      end
    end
  end
  object puScanHistory: TPopupMenu
    OnPopup = puScanHistoryPopup
    Left = 674
    Top = 296
    object miExploreFromScanHistory: TMenuItem
      Caption = '.'
      ImageIndex = 4
    end
    object N20: TMenuItem
      Caption = '-'
    end
    object miShowInFolderHistory: TMenuItem
      Caption = '.'
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object miSaveAs: TMenuItem
      Caption = '.'
    end
  end
  object puQuickFolder: TPopupMenu
    Left = 785
    Top = 272
    object miQFTitle: TMenuItem
      Caption = '.'
      Enabled = False
    end
    object N16: TMenuItem
      Caption = '-'
    end
    object miQFAdd: TMenuItem
      Caption = '.'
      ImageIndex = 0
    end
    object N17: TMenuItem
      Caption = '-'
    end
  end
end
