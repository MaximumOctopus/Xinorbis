object frmShowCalendar: TfrmShowCalendar
  Left = 448
  Top = 293
  BorderStyle = bsDialog
  ClientHeight = 359
  ClientWidth = 923
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lSelected: TLabel
    Left = 7
    Top = 352
    Width = 3
    Height = 13
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lAvailableTimes: TLabel
    Left = 7
    Top = 198
    Width = 3
    Height = 13
    Caption = '.'
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 89
    Height = 318
    Align = alLeft
    BevelEdges = [beLeft, beTop, beBottom]
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    object Shape1: TShape
      Left = 7
      Top = 70
      Width = 16
      Height = 16
      Brush.Color = 13041609
    end
    object Shape2: TShape
      Left = 7
      Top = 90
      Width = 16
      Height = 16
      Brush.Color = 12713983
    end
    object Shape3: TShape
      Left = 7
      Top = 110
      Width = 16
      Height = 16
      Brush.Color = 12706303
    end
    object Shape4: TShape
      Left = 7
      Top = 130
      Width = 16
      Height = 16
      Brush.Color = 11781375
    end
    object Shape5: TShape
      Left = 7
      Top = 151
      Width = 16
      Height = 16
      Brush.Color = 16373759
    end
    object Label1: TLabel
      Left = 31
      Top = 71
      Width = 32
      Height = 13
      Caption = '1 scan'
    end
    object Label2: TLabel
      Left = 31
      Top = 91
      Width = 37
      Height = 13
      Caption = '2 scans'
    end
    object Label3: TLabel
      Left = 31
      Top = 111
      Width = 37
      Height = 13
      Caption = '3 scans'
    end
    object Label4: TLabel
      Left = 31
      Top = 131
      Width = 37
      Height = 13
      Caption = '4 scans'
    end
    object Label5: TLabel
      Left = 31
      Top = 151
      Width = 43
      Height = 13
      Caption = '5+ scans'
    end
    object Bevel2: TBevel
      Left = 7
      Top = 60
      Width = 74
      Height = 5
      Shape = bsTopLine
    end
    object Bevel3: TBevel
      Left = 7
      Top = 177
      Width = 74
      Height = 5
      Shape = bsTopLine
    end
    object SpinEdit1: TSpinEdit
      Left = 7
      Top = 32
      Width = 74
      Height = 22
      MaxValue = 2100
      MinValue = 2000
      TabOrder = 0
      Value = 2015
      OnChange = SpinEdit1Change
      OnEnter = SpinEdit1Enter
      OnExit = SpinEdit1Exit
    end
    object cbTimes: TListBox
      Left = 8
      Top = 195
      Width = 73
      Height = 112
      ItemHeight = 13
      TabOrder = 1
      OnClick = cbTimesClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 318
    Width = 923
    Height = 41
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      923
      41)
    object CheckBox1: TCheckBox
      Left = 8
      Top = 12
      Width = 97
      Height = 17
      Caption = 'Exclude empty'
      TabOrder = 0
    end
    object bUse: TBitBtn
      Left = 760
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'OK'
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFE0EEE08FC0913B8D3F257A292577293B853F8FB991E0EBE0FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBEBEBB7B7B77F7F7F6A
        6A6A686868787878B2B2B2E9E9E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFB5D9B7318F3542A05287CA9A9BD3AB9BD2AB83C7963D974C307C34B5D0
        B6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD3D3D37F7F7F8F8F8FBEBEBEC9
        C9C9C8C8C8BABABA8686866F6F6FCCCCCCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        B5DBBA258F2A6DBE83A8DBB587CC9866BC7D64BA7C86CB98A5D9B466B77D2472
        27B5D1B6FFFFFFFFFFFFFFFFFFFFFFFFD5D5D57D7D7DAFAFAFD1D1D1BFBFBFAD
        ADADABABABBEBEBECFCFCFA9A9A9656565CCCCCCFFFFFFFFFFFFFFFFFFE1F2E4
        33A14472C287A8DBB260BC775CBA7359B87059B56F58B56F5BB774A5D9B369B8
        7F317F35E1ECE1FFFFFFFFFFFFEFEFEF909090B3B3B3D0D0D0ABABABA9A9A9A7
        A7A7A4A4A4A4A4A4A7A7A7CFCFCFAAAAAA727272EAEAEAFFFFFFFFFFFF90D29F
        4CB064AADDB464C1795FBE7175C585D4ECD98ACD9956B66C58B56E5CB774A6DA
        B4419B4E8EBC90FFFFFFFFFFFFC8C8C89F9F9FD2D2D2B0B0B0ACACACB5B5B5E7
        E7E7C0C0C0A5A5A5A4A4A4A7A7A7D0D0D08A8A8AB4B4B4FFFFFFFFFFFF3FB55D
        91D29F8DD49A64C37479C987F2FAF4FFFFFFFDFEFD86CB9657B76D5BB97285CC
        9787C79A3B8B3FFFFFFFFFFFFFA3A3A3C5C5C5C6C6C6B1B1B1B9B9B9F9F9F9FF
        FFFFFEFEFEBEBEBEA6A6A6A8A8A8BFBFBFBBBBBB7D7D7DFFFFFFFFFFFF27B049
        A6DCAF70CA7F73CA80F0F9F1FFFFFFEBF7EDFFFFFFFBFDFC88CD965BB97167BE
        7DA0D7AF237F26FFFFFFFFFFFF9C9C9CD1D1D1B8B8B8B8B8B8F7F7F7FFFFFFF5
        F5F5FFFFFFFDFDFDBFBFBFA8A8A8AEAEAECDCDCD6E6E6EFFFFFFFFFFFF2EB751
        A7DDB172CC8066C773B0E1B7D2EED663C170B8E3BFFFFFFFFBFDFC8CD09969C1
        7EA1D7AE238426FFFFFFFFFFFFA2A2A2D2D2D2BABABAB4B4B4D6D6D6E7E7E7AF
        AFAFDADADAFFFFFFFDFDFDC2C2C2B1B1B1CCCCCC737373FFFFFFFFFFFF4BC56C
        95D7A191D79B69C97664C66F61C46E61C36F61C26FB9E4C0FFFFFFE3F4E68BD1
        998BCE9D3C993FFFFFFFFFFFFFB2B2B2C9C9C9C8C8C8B6B6B6B3B3B3B1B1B1B0
        B0B0AFAFAFDBDBDBFFFFFFF0F0F0C3C3C3C2C2C2898989FFFFFFFFFFFF9BDFAD
        57BF70AFE1B76DCC7A68C87265C77063C56E62C46E63C471B6E3BE6FC77EACDF
        B548A95E8FC894FFFFFFFFFFFFD4D4D4ADADADD6D6D6B9B9B9B5B5B5B4B4B4B2
        B2B2B1B1B1B1B1B1D9D9D9B6B6B6D4D4D4989898BEBEBEFFFFFFFFFFFFE5F7E9
        49C5667FCE90AEE1B56DCC7A6ACA7668C87268C87468C8756BC979ACDFB476C4
        8933A142E1F1E3FFFFFFFFFFFFF4F4F4B1B1B1BFBFBFD6D6D6B9B9B9B7B7B7B5
        B5B5B5B5B5B5B5B5B7B7B7D4D4D4B5B5B58F8F8FEEEEEEFFFFFFFFFFFFFFFFFF
        BFECCB3DC35C7FCE90AFE1B792D89D77CE8377CE8392D89DAEE1B578C88B27A1
        3BB5DFBEFFFFFFFFFFFFFFFFFFFFFFFFE5E5E5AEAEAEBFBFBFD6D6D6CACACABC
        BCBCBCBCBCCACACAD6D6D6B9B9B98E8E8ED9D9D9FFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFC0EDCB4AC86959C27496D7A3A5DCAEA5DCAE95D6A150B96A35B355B6E3
        C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E6B4B4B4B0B0B0CACACAD0
        D0D0D0D0D0C9C9C9A6A6A6A0A0A0DCDCDCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFE5F8E99FE3B055CB723BC05C37BE5A49C36A97DCAAE1F5E7FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5D8D8D8B8B8B8AB
        ABABA9A9A9B0B0B0D1D1D1F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ModalResult = 1
      NumGlyphs = 2
      TabOrder = 1
    end
    object bCancel: TBitBtn
      Left = 841
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1313F20000F10000F100
        00F10000EF0000EF0000ED1212EEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFF1313F61A20F53C4CF93A49F83847F83545F83443F73242F7141BF11717
        EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1313F81D23F94453FA2429F91212F70F
        0FF60C0CF50909F5161BF53343F7141BF11717EFFFFFFFFFFFFFFFFFFF1313F9
        1F25FA4A58FB4247FBC9C9FD3B3BF91313F71010F63333F7C5C5FD3035F73444
        F7141BF21717EFFFFFFFFFFFFF0000FB4F5DFD3237FBCBCBFEF2F2FFEBEBFE3B
        3BF93939F8EAEAFEF1F1FEC5C5FD181DF63343F70000EFFFFFFFFFFFFF0000FD
        525FFD2828FC4747FCECECFFF2F2FFECECFFECECFEF1F1FFEAEAFE3434F70B0B
        F53545F80000EFFFFFFFFFFFFF0000FD5562FE2C2CFD2929FC4848FCEDEDFFF2
        F2FFF2F2FFECECFE3A3AF91212F70F0FF63848F80000F1FFFFFFFFFFFF0000FD
        5764FE3030FD2D2DFD4B4BFCEDEDFFF2F2FFF2F2FFECECFF3D3DF91616F81313
        F73C4BF80000F1FFFFFFFFFFFF0000FF5A67FE3333FE5050FDEDEDFFF3F3FFED
        EDFFEDEDFFF2F2FFECECFE3E3EFA1717F83F4EF90000F1FFFFFFFFFFFF0000FF
        5B68FF4347FECFCFFFF3F3FFEDEDFF4C4CFC4A4AFCECECFFF2F2FFCACAFE2A2F
        FA4251FA0000F3FFFFFFFFFFFF1414FF262BFF5D6AFF585BFFCFCFFF5252FE2F
        2FFD2C2CFD4B4BFCCCCCFE484CFB4957FB1D23F91414F6FFFFFFFFFFFFFFFFFF
        1414FF262BFF5D6AFF4347FF3434FE3232FE3030FD2D2DFD383CFC4F5DFC1F25
        FA1414F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1414FF262BFF5C69FF5B68FF5A
        67FE5865FE5663FE5461FE2227FC0D0DFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF1313FF0000FF0000FF0000FF0000FD0000FD0000FD1313FDFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ModalResult = 2
      TabOrder = 2
    end
  end
  object Panel3: TPanel
    Left = 89
    Top = 0
    Width = 834
    Height = 318
    Align = alClient
    BevelEdges = [beLeft, beTop, beRight]
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 2
    object Label6: TLabel
      Left = 10
      Top = 8
      Width = 302
      Height = 16
      Caption = 'Available Folder History Scans for Selected Folder'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object sgCalendar: TAdvStringGrid
      Left = 10
      Top = 30
      Width = 815
      Height = 277
      Cursor = crDefault
      ColCount = 38
      DefaultRowHeight = 21
      DrawingStyle = gdsClassic
      RowCount = 13
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
      ParentFont = False
      ScrollBars = ssNone
      TabOrder = 0
      OnDrawCell = sgCalendarDrawCell
      GridLineColor = 15527152
      GridFixedLineColor = 13947601
      HoverRowCells = [hcNormal, hcSelected]
      OnClickCell = sgCalendarClickCell
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ActiveCellColor = 16575452
      ActiveCellColorTo = 16571329
      CellNode.TreeColor = clSilver
      ControlLook.FixedGradientMirrorFrom = 16049884
      ControlLook.FixedGradientMirrorTo = 16247261
      ControlLook.FixedGradientHoverFrom = 16710648
      ControlLook.FixedGradientHoverTo = 16446189
      ControlLook.FixedGradientHoverMirrorFrom = 16049367
      ControlLook.FixedGradientHoverMirrorTo = 15258305
      ControlLook.FixedGradientDownFrom = 15853789
      ControlLook.FixedGradientDownTo = 15852760
      ControlLook.FixedGradientDownMirrorFrom = 15522767
      ControlLook.FixedGradientDownMirrorTo = 15588559
      ControlLook.FixedGradientDownBorder = 14007466
      ControlLook.ControlStyle = csWinXP
      ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownHeader.Font.Color = clWindowText
      ControlLook.DropDownHeader.Font.Height = -11
      ControlLook.DropDownHeader.Font.Name = 'Tahoma'
      ControlLook.DropDownHeader.Font.Style = []
      ControlLook.DropDownHeader.Visible = True
      ControlLook.DropDownHeader.Buttons = <>
      ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownFooter.Font.Color = clWindowText
      ControlLook.DropDownFooter.Font.Height = -11
      ControlLook.DropDownFooter.Font.Name = 'MS Sans Serif'
      ControlLook.DropDownFooter.Font.Style = []
      ControlLook.DropDownFooter.Visible = True
      ControlLook.DropDownFooter.Buttons = <>
      Filter = <>
      FilterDropDown.Font.Charset = DEFAULT_CHARSET
      FilterDropDown.Font.Color = clWindowText
      FilterDropDown.Font.Height = -11
      FilterDropDown.Font.Name = 'MS Sans Serif'
      FilterDropDown.Font.Style = []
      FilterDropDownClear = '(All)'
      FilterEdit.TypeNames.Strings = (
        'Starts with'
        'Ends with'
        'Contains'
        'Not contains'
        'Equal'
        'Not equal'
        'Larger than'
        'Smaller than'
        'Clear')
      FixedColWidth = 69
      FixedRowHeight = 22
      FixedFont.Charset = DEFAULT_CHARSET
      FixedFont.Color = clBlack
      FixedFont.Height = -11
      FixedFont.Name = 'Tahoma'
      FixedFont.Style = [fsBold]
      FloatFormat = '%.2f'
      HoverButtons.Buttons = <>
      HoverButtons.Position = hbLeftFromColumnLeft
      HTMLSettings.ImageFolder = 'images'
      HTMLSettings.ImageBaseName = 'img'
      Look = glWin7
      PrintSettings.DateFormat = 'dd/mm/yyyy'
      PrintSettings.Font.Charset = DEFAULT_CHARSET
      PrintSettings.Font.Color = clWindowText
      PrintSettings.Font.Height = -11
      PrintSettings.Font.Name = 'MS Sans Serif'
      PrintSettings.Font.Style = []
      PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
      PrintSettings.FixedFont.Color = clWindowText
      PrintSettings.FixedFont.Height = -11
      PrintSettings.FixedFont.Name = 'MS Sans Serif'
      PrintSettings.FixedFont.Style = []
      PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
      PrintSettings.HeaderFont.Color = clWindowText
      PrintSettings.HeaderFont.Height = -11
      PrintSettings.HeaderFont.Name = 'MS Sans Serif'
      PrintSettings.HeaderFont.Style = []
      PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
      PrintSettings.FooterFont.Color = clWindowText
      PrintSettings.FooterFont.Height = -11
      PrintSettings.FooterFont.Name = 'MS Sans Serif'
      PrintSettings.FooterFont.Style = []
      PrintSettings.PageNumSep = '/'
      SearchFooter.Color = 16645370
      SearchFooter.ColorTo = 16247261
      SearchFooter.FindNextCaption = 'Find &next'
      SearchFooter.FindPrevCaption = 'Find &previous'
      SearchFooter.Font.Charset = DEFAULT_CHARSET
      SearchFooter.Font.Color = clWindowText
      SearchFooter.Font.Height = -11
      SearchFooter.Font.Name = 'MS Sans Serif'
      SearchFooter.Font.Style = []
      SearchFooter.HighLightCaption = 'Highlight'
      SearchFooter.HintClose = 'Close'
      SearchFooter.HintFindNext = 'Find next occurrence'
      SearchFooter.HintFindPrev = 'Find previous occurrence'
      SearchFooter.HintHighlight = 'Highlight occurrences'
      SearchFooter.MatchCaseCaption = 'Match case'
      SearchFooter.ResultFormat = '(%d of %d)'
      SelectionRectangle = True
      ShowDesignHelper = False
      SortSettings.DefaultFormat = ssAutomatic
      SortSettings.Column = 0
      SortSettings.HeaderColor = 16579058
      SortSettings.HeaderColorTo = 16579058
      SortSettings.HeaderMirrorColor = 16380385
      SortSettings.HeaderMirrorColorTo = 16182488
      Version = '8.4.2.5'
      ColWidths = (
        69
        20
        20
        20
        20
        21
        20
        20
        20
        20
        20
        20
        20
        21
        20
        20
        20
        20
        20
        20
        20
        20
        20
        20
        20
        20
        21
        20
        20
        20
        19
        19
        20
        20
        20
        21
        20
        20)
      RowHeights = (
        21
        21
        21
        21
        21
        21
        21
        21
        21
        21
        21
        21
        21)
    end
  end
end
