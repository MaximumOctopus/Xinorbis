object FrameSelect: TFrameSelect
  Left = 0
  Top = 0
  Width = 1013
  Height = 639
  TabOrder = 0
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1013
    Height = 639
    ActivePage = tsSelectFolder
    Align = alClient
    TabOrder = 0
    object tsSelectFolder: TTabSheet
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
      object eScanPath: TEdit
        Left = 82
        Top = 4
        Width = 839
        Height = 23
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 9
        Text = 'eScanPath'
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
    end
  end
  object puScanHistory: TPopupMenu
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
