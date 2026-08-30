object FrameSummary: TFrameSummary
  Left = 0
  Top = 0
  Width = 1032
  Height = 617
  TabOrder = 0
  OnResize = FrameResize
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1032
    Height = 617
    Cursor = crHandPoint
    ActivePage = tsSummary
    Align = alClient
    TabOrder = 0
    object tsSummary: TTabSheet
      DesignSize = (
        1024
        587)
      object SpeedButton1: TSpeedButton
        Left = 5
        Top = 7
        Width = 23
        Height = 22
      end
      object lSNoF: TLabel
        Left = 16
        Top = 60
        Width = 31
        Height = 15
        Caption = 'lSNoF'
      end
      object lSNoD: TLabel
        Left = 16
        Top = 108
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSNoFX: TLabel
        Left = 53
        Top = 81
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSNoFXClick
      end
      object lSNoDX: TLabel
        Left = 48
        Top = 128
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSNoDXClick
      end
      object lSSoF: TLabel
        Left = 168
        Top = 60
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSSoFX: TLabel
        Left = 200
        Top = 80
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSNoFXClick
      end
      object lSSoFoD: TLabel
        Left = 168
        Top = 108
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSSoFODX: TLabel
        Left = 200
        Top = 128
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSNoFXClick
      end
      object lSAFF: TLabel
        Left = 320
        Top = 108
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSAFSX: TLabel
        Left = 352
        Top = 80
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSAFSXClick
      end
      object lSAFS: TLabel
        Left = 320
        Top = 60
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSAFFX: TLabel
        Left = 352
        Top = 128
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSAFSXClick
      end
      object lSLF: TLabel
        Left = 72
        Top = 156
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSLFSoF: TLabel
        Left = 72
        Top = 204
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSULSSoF: TLabel
        Left = 72
        Top = 252
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSEDX: TLabel
        Left = 504
        Top = 128
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSEFXClick
      end
      object lSED: TLabel
        Left = 472
        Top = 108
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSEF: TLabel
        Left = 472
        Top = 60
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSEFX: TLabel
        Left = 504
        Top = 80
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSEFXClick
      end
      object lProcessTime: TLabel
        Left = 64
        Top = 37
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSummaryByQuantity: TLabel
        Left = 80
        Top = 318
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSummaryBySize: TLabel
        Left = 80
        Top = 418
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSLFSoFX: TLabel
        Left = 104
        Top = 224
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSNoDXClick
      end
      object lSLFNoF: TLabel
        Left = 534
        Top = 204
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSLFNoFX: TLabel
        Left = 566
        Top = 224
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSNoDXClick
      end
      object lSULSNoF: TLabel
        Left = 534
        Top = 252
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lScanPath: TLabel
        Left = 48
        Top = 11
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSULSNoFX: TLabel
        Left = 566
        Top = 273
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSULSSoFXClick
      end
      object lSLFX: TLabel
        Left = 104
        Top = 174
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSLFXClick
      end
      object lSULSSoFX: TLabel
        Left = 104
        Top = 273
        Width = 34
        Height = 15
        Cursor = crHandPoint
        Caption = 'Label1'
        OnClick = lSULSSoFXClick
      end
      object g1: TGauge
        Left = 16
        Top = 207
        Width = 45
        Height = 45
        BorderStyle = bsNone
        Color = 3355443
        Kind = gkPie
        ParentColor = False
        Progress = 0
      end
      object g2: TGauge
        Left = 16
        Top = 258
        Width = 45
        Height = 45
        BorderStyle = bsNone
        Color = 3355443
        Kind = gkPie
        ParentColor = False
        Progress = 0
      end
      object Gauge1: TGauge
        Left = 16
        Top = 156
        Width = 45
        Height = 45
        BorderStyle = bsNone
        Color = 3355443
        Kind = gkPie
        ParentColor = False
        Progress = 0
      end
      object pICQuantity: TPanel
        Left = 80
        Top = 339
        Width = 929
        Height = 63
        Anchors = [akLeft, akTop, akRight]
        BevelOuter = bvNone
        Color = 3355443
        ParentBackground = False
        TabOrder = 0
      end
      object pICSize: TPanel
        Left = 80
        Top = 439
        Width = 929
        Height = 63
        Anchors = [akLeft, akTop, akRight]
        BevelOuter = bvNone
        Color = 3355443
        ParentBackground = False
        TabOrder = 1
      end
    end
    object tsDrive: TTabSheet
      ImageIndex = 1
      object gDFolder: TGauge
        Left = 16
        Top = 16
        Width = 121
        Height = 121
        BorderStyle = bsNone
        Color = 3355443
        Kind = gkPie
        ParentColor = False
        Progress = 0
      end
      object gDUsedSpace: TGauge
        Left = 143
        Top = 16
        Width = 121
        Height = 121
        BorderStyle = bsNone
        Color = 3355443
        Kind = gkPie
        ParentColor = False
        Progress = 0
      end
      object lSVolName: TLabel
        Left = 312
        Top = 16
        Width = 9
        Height = 15
        Caption = '...'
      end
      object lSVolNameValue: TLabel
        Left = 336
        Top = 37
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSVolMaxValue: TLabel
        Left = 336
        Top = 93
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSVolMax: TLabel
        Left = 312
        Top = 72
        Width = 9
        Height = 15
        Caption = '...'
      end
      object lSSerial: TLabel
        Left = 472
        Top = 16
        Width = 9
        Height = 15
        Caption = '...'
      end
      object lSSerialValue: TLabel
        Left = 496
        Top = 37
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSFileSystem: TLabel
        Left = 616
        Top = 16
        Width = 9
        Height = 15
        Caption = '...'
      end
      object lSFileSystemValue: TLabel
        Left = 640
        Top = 37
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lSVolFree: TLabel
        Left = 472
        Top = 72
        Width = 12
        Height = 15
        Caption = '....'
      end
      object lSVolFreeValue: TLabel
        Left = 496
        Top = 93
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object lDFolder: TLabel
        Left = 16
        Top = 143
        Width = 44
        Height = 15
        Caption = 'lDFolder'
      end
      object lDUsedSpace: TLabel
        Left = 143
        Top = 143
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
    end
  end
end
