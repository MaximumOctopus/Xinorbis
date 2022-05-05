object frmDBSelectedFolder: TfrmDBSelectedFolder
  Left = 642
  Top = 327
  BorderIcons = [biSystemMenu]
  ClientHeight = 430
  ClientWidth = 1107
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TAdvSplitter
    Left = 497
    Top = 57
    Height = 332
    Appearance.BorderColor = clNone
    Appearance.BorderColorHot = clNone
    Appearance.Color = clWhite
    Appearance.ColorTo = clSilver
    Appearance.ColorHot = clWhite
    Appearance.ColorHotTo = clGray
    GripStyle = sgDots
    ExplicitLeft = 520
    ExplicitTop = 240
    ExplicitHeight = 100
  end
  object sgDatabase: TAdvStringGrid
    Left = 0
    Top = 57
    Width = 497
    Height = 332
    Cursor = crDefault
    Align = alLeft
    Ctl3D = True
    DefaultRowHeight = 19
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    GridLineWidth = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goRowSelect]
    ParentCtl3D = False
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
    OnDrawCell = sgDatabaseDrawCell
    GridLineColor = 15062992
    HoverRowCells = [hcNormal, hcSelected]
    OnGetCellColor = sgDatabaseGetCellColor
    OnResize = sgDatabaseResize
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = 10344697
    ActiveCellColorTo = 6210033
    CellNode.TreeColor = clSilver
    ControlLook.FixedGradientFrom = 16250871
    ControlLook.FixedGradientTo = 14606046
    ControlLook.FixedGradientHoverFrom = 15000287
    ControlLook.FixedGradientHoverTo = 14406605
    ControlLook.FixedGradientHoverMirrorFrom = 14406605
    ControlLook.FixedGradientHoverMirrorTo = 13813180
    ControlLook.FixedGradientHoverBorder = 12033927
    ControlLook.FixedGradientDownFrom = 14991773
    ControlLook.FixedGradientDownTo = 14991773
    ControlLook.FixedGradientDownMirrorFrom = 14991773
    ControlLook.FixedGradientDownMirrorTo = 14991773
    ControlLook.FixedGradientDownBorder = 14991773
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
    FixedColWidth = 114
    FixedRowHeight = 19
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
    Look = glCustom
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
    SearchFooter.Color = 16250871
    SearchFooter.ColorTo = clNone
    SearchFooter.Font.Charset = DEFAULT_CHARSET
    SearchFooter.Font.Color = clWindowText
    SearchFooter.Font.Height = -11
    SearchFooter.Font.Name = 'MS Sans Serif'
    SearchFooter.Font.Style = []
    SearchFooter.ResultFormat = '(%d of %d)'
    SelectionColor = 6210033
    ShowSelection = False
    SortSettings.DefaultFormat = ssAutomatic
    SortSettings.Column = 0
    Version = '8.4.2.5'
    ColWidths = (
      114
      80
      80
      80
      64)
    RowHeights = (
      19
      19)
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1107
    Height = 57
    Align = alTop
    BevelOuter = bvNone
    Color = 3355443
    ParentBackground = False
    TabOrder = 1
    object Image1: TImage
      Left = 8
      Top = 4
      Width = 16
      Height = 16
      Cursor = crHandPoint
      AutoSize = True
      Picture.Data = {
        07544269746D617036040000424D360400000000000036000000280000001000
        0000100000000100200000000000000400000000000000000000000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00C5C5C500A5A5A500A1A1A100ABAB
        AB00A7A7A7009595950098989800BFBFBF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00A9A9A900CECECE00EDEDED00F4F4F400F5F5
        F500F4F4F400EFEFEF00E2E2E200BABABA0095959500FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00B0B0B000DEDEDE00F3F3F300DBDBDB00D2D2D200DBDB
        DB00D6D6D600C0C0C000C9C9C900E6E6E600C4C4C40095959500FF00FF00FF00
        FF00FF00FF00FF00FF00B3B3B300F0F0F000DEDEDE00D4D4D400D2D2D200DBDB
        DB00D6D6D600BFBFBF00B0B0B000B3B3B300DEDEDE0099999900FF00FF00FF00
        FF00FF00FF00FF00FF00B5B5B500F2F2F200E2E2E200D8D8D800D5D5D500DCDC
        DC00D8D8D800C0C0C000B3B3B300B7B7B700E0E0E0009F9F9F00FF00FF00FF00
        FF00FF00FF00FF00FF00B7B7B700F3F3F300E7E7E700DDDDDD00D9D9D900E0E0
        E000DBDBDB00C4C4C400B8B8B800BBBBBB00E1E1E100A3A3A300FF00FF00FF00
        FF00FF00FF00FF00FF00B8B8B800F4F4F400EAEAEA00E1E1E100DDDDDD00E3E3
        E300DEDEDE00C9C9C900BDBDBD00BFBFBF00E2E2E200A6A6A600FF00FF00FF00
        FF00FF00FF00FF00FF00BABABA00F5F5F500EEEEEE00E6E6E600E2E2E200E6E6
        E600E1E1E100CDCDCD00C2C2C200C2C2C200E3E3E300A8A8A800FF00FF00FF00
        FF00FF00FF00FF00FF00BBBBBB00F6F6F600EBEBEB00DEDEDE00D6D6D600D5D5
        D500D1D1D100C3C3C300BCBCBC00C0C0C000E5E5E500ABABAB00FF00FF00FF00
        FF00FF00FF00FF00FF00BDBDBD00F7F7F700E7E7E700EFEFEF00F6F6F600FBFB
        FB00FAFAFA00F0F0F000DEDEDE00C3C3C300E6E6E600ACACAC00FF00FF00FF00
        FF00FF00FF00FF00FF00BFBFBF00F8F8F800FEFEFE00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FBFBFB00EAEAEA00AEAEAE00FF00FF00FF00
        FF00FF00FF00FF00FF00CBCBCB00E1E1E100FEFEFE00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FBFBFB00CFCFCF00C9C9C900FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00C7C7C700D0D0D000E8E8E800F3F3F300FDFD
        FD00FCFCFC00EDEDED00E0E0E000C2C2C200C0C0C000FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00D0D0D000C3C3C300B8B8
        B800B8B8B800C3C3C300CDCDCD00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00}
      Transparent = True
      OnClick = Image1Click
    end
    object lFolder: TLabel
      Left = 40
      Top = 24
      Width = 13
      Height = 13
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lCount: TLabel
      Left = 32
      Top = 40
      Width = 9
      Height = 13
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lComputerName: TLabel
      Left = 32
      Top = 8
      Width = 13
      Height = 13
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 389
    Width = 1107
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 2
    DesignSize = (
      1107
      41)
    object bHelp: TBitBtn
      Left = 8
      Top = 8
      Width = 107
      Height = 25
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000120B0000120B00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFA393839D7753A3703EA2703F9D7855A39385FF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA39282AB6D31AD6C2DAD6C2DAD
        6C2DAD6C2DAD6C2DAD6C2DAB6E33A49688FF00FFFF00FFFF00FFFF00FFFF00FF
        9C7F62AD6C2DAD6C2DAD6C2DAD6C2DBB8751B8824CAD6C2DAD6C2DAD6C2DAD6C
        2D9D8369FF00FFFF00FFFF00FFA29181AD6C2DAD6C2DAD6C2DAD6C2DB3793FFF
        FFFFFFFFFFAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DA49688FF00FFFF00FFAB6D31
        AD6C2DAD6C2DAD6C2DAD6C2DB07237FFFFFFFFFFFFAD6C2DAD6C2DAD6C2DAD6C
        2DAD6C2DA96C32FF00FFA1907FAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAE6E30AD
        6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DA395869E764FAD6C2D
        AD6C2DAD6C2DAD6C2DAD6C2DAE6F31FCFBF8FFFFFFB3773DAD6C2DAD6C2DAD6C
        2DAD6C2DAD6C2D9D7955A66F3AAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DDE
        C5AEFFFFFFFFFFFFB8814BAD6C2DAD6C2DAD6C2DAD6C2DA27140A56E39AD6C2D
        AD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAF6F32E4D0BCFFFFFFFFFFFFB57C44AD6C
        2DAD6C2DAD6C2DA370409E754DAD6C2DAD6C2DAD6C2DC08F5ECFAA87B67E47AD
        6C2DAD6D2EE5D1BEFFFFFFD6B698AD6C2DAD6C2DAD6C2D9D7752A08D7AAD6C2D
        AD6C2DAD6C2DDCC2A8FFFFFFDEC5ADAD6C2DAD6C2DE0C8B1FFFFFFD9BCA0AD6C
        2DAD6C2DAD6C2DA29281FF00FFAC6D2FAD6C2DAD6C2DBB8753FFFFFFFFFFFFF0
        E4D8F1E6DBFFFFFFFFFFFFBC8854AD6C2DAD6C2DAB6D31FF00FFFF00FF9F8B78
        AD6C2DAD6C2DAD6C2DBF8E5DEADACBFFFFFFFFFFFFEADACBC19162AD6C2DAD6C
        2DAD6C2DA29080FF00FFFF00FFFF00FF9C7B59AD6C2DAD6C2DAD6C2DAD6C2DAD
        6C2EAD6C2DAD6C2DAD6C2DAD6C2DAD6C2D9B7D5FFF00FFFF00FFFF00FFFF00FF
        FF00FF9F8A75AC6C2FAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAD6C2DAC6D2F9F8C
        79FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9F8A75A17347A9
        6D33A86D349F73489F8B78FF00FFFF00FFFF00FFFF00FFFF00FF}
      TabOrder = 0
      OnClick = bHelpClick
    end
    object bCopy: TBitBtn
      Left = 973
      Top = 8
      Width = 32
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFD39570CC8357C87646CA7B4ECB7B4ECA7B4ECA7B
        4ECA7B4ECA8155CD865CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF94949482
        82827575757B7B7B7B7B7B7B7B7B7B7B7B7A7A7A808080848484FF00FF4A80AB
        206398206398206398206398C98F67FCF3ECFAF1E8FAF0E7FBF1E9FBF2EAFBF2
        EAFBF2EBFDF4EECB8358FF00FF8A8A8A6F6F6F6F6F6F6F6F6F6F6F6F8C8C8CF3
        F3F3F0F0F0EFEFEFF0F0F0F1F1F1F1F1F1F2F2F2F4F4F48181815588B174ADD8
        7BB2DD78AEDC75AADA74A9DADAA97DEFF1E7FFE9D9FFEADBFFE9D9FFE7D7FFE5
        D2FFE2CBEFF2E8CE8156919191B6B6B6BBBBBBB7B7B7B4B4B4B3B3B3A4A4A4EF
        EFEFE7E7E7E8E8E8E7E7E7E5E5E5E3E3E3DFDFDFF0F0F080808020639880B9E1
        5395D15092D04E8ECE4D8CCDD6A97DFBF5EEFFE9D9FFEADBFFE9D9FFE7D7FFE5
        D2FFE2CBFBF6EFCC83566F6F6FC0C0C0A2A2A2A0A0A09D9D9D9B9B9BA4A4A4F4
        F4F4E7E7E7E8E8E8E7E7E7E5E5E5E3E3E3DFDFDFF5F5F581818120639884BFE2
        569AD35397D15092CF5091CFD6A97DFFF7F1FFE9D9FFEADBFFE9D9FFE7D7FFE5
        D2FFE2CBFFF7F1CB85566F6F6FC5C5C5A6A6A6A4A4A4A0A0A09F9F9FA4A4A4F7
        F7F7E7E7E7E8E8E8E7E7E7E5E5E5E3E3E3DFDFDFF7F7F782828220639888C4E6
        599FD6569BD35397D15395D1D7AC7FFFF7F0FFE7D5FDE7D6FDE6D4FCE4D0FBE3
        CBFADCC2FEF3E8CC86576F6F6FCACACAAAAAAAA7A7A7A4A4A4A2A2A2A7A7A7F7
        F7F7E5E5E5E5E5E5E4E4E4E1E1E1E0E0E0D9D9D9F2F2F28383832063988BC9E7
        5CA5D759A0D5579CD3569AD3D7AC7FFFF7F2FEE7D5FEE7D5FDE5D1FAE0CAF9DE
        C4F7D9BCFDF2E7CC87586F6F6FCDCDCDAFAFAFABABABA7A7A7A6A6A6A7A7A7F7
        F7F7E5E5E5E5E5E5E2E2E2DDDDDDDBDBDBD5D5D5F1F1F184848420639891CDE9
        5FA9D95DA5D85AA0D6599FD6D8AD81FEF7F1FCE5D2FCE4D1FBE2CCF9DDC4F6D7
        BBF3D1AFFAEFE4CC87596F6F6FD1D1D1B2B2B2AFAFAFABABABAAAAAAA8A8A8F7
        F7F7E3E3E3E2E2E2DFDFDFDADADAD3D3D3CDCDCDEEEEEE84848420639898D2EB
        65AEDA60AAD95DA6D85CA5D7D9AF84FEF6F0FCE2CDFCE3CDFADFC8F7D9BCF5E9
        DDFAF3EBFBF8F3CA83546F6F6FD5D5D5B6B6B6B3B3B3B0B0B0AFAFAFAAAAAAF6
        F6F6E0E0E0E0E0E0DCDCDCD5D5D5E8E8E8F2F2F2F7F7F78080802063989ED6ED
        6BB2DC66AFDC60AADA5FA9D9D9AF84FEF5EDFCDEC5FBE0C7F9DCC2F5D3B4FEF9
        F3FAE2C4ECC193D2986E6F6F6FD9D9D9B9B9B9B7B7B7B3B3B3B2B2B2AAAAAAF4
        F4F4DBDBDBDDDDDDD9D9D9CFCFCFF9F9F9DEDEDEBBBBBB969696206398A5DAEF
        6FB5DE68B0DC60A9D95FA9D9D7AD81FFFFFEFDF3E9FDF3EAFCF2E8FAEFE3FAF2
        E7EABB88D39469FF00FF6F6F6FDDDDDDBCBCBCB8B8B8B2B2B2B2B2B2A8A8A8FF
        FFFFF2F2F2F2F2F2F1F1F1EEEEEEF1F1F1B5B5B5919191FF00FF206398AADDF1
        74B9E070B6DF6CB3DD6BB2DCD9AF84D7AE81D7AC7FD7AC7FCCA070CD9F71B38F
        67D39B71FF00FFFF00FF6F6F6FE0E0E0C0C0C0BDBDBDBABABAB9B9B9AAAAAAA8
        A8A8A7A7A7A7A7A79A9A9A9A9A9A8A8A8A989898FF00FFFF00FF206398B0E1F2
        79BDE24498DD4497DC4396DC4296DC4295DC4195DB539ED489C6E6206398FF00
        FFFF00FFFF00FFFF00FF6F6F6FE3E3E3C3C3C3A8A8A8A7A7A7A6A6A6A6A6A6A6
        A6A6A5A5A5A9A9A9CBCBCB6F6F6FFF00FFFF00FFFF00FFFF00FF3B76A595C9E0
        AEE2F24E9DDFB5EEFD75D4F075D4F0B5EEFD4B9BDE8ECBE993CDE92A6A9DFF00
        FFFF00FFFF00FFFF00FF818181CCCCCCE4E4E4ACACACEFEFEFD7D7D7D7D7D7EF
        EFEFAAAAAACFCFCFD1D1D1767676FF00FFFF00FFFF00FFFF00FFFF00FF6392B7
        2063983775A4B6EFFE80DBF380DBF3B6EFFE2E6EA12063986F9ABCFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FF9A9A9A6F6F6F7F7F7FF0F0F0DDDDDDDDDDDDF0
        F0F07979796F6F6FA2A2A2FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF2063982063982063982063982063982D6C9EFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF6F6F6F6F6F6F6F6F6F6F6F6F6F
        6F6F777777FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      TabOrder = 1
      OnClick = bCopyClick
    end
    object bClose: TBitBtn
      Left = 1011
      Top = 8
      Width = 89
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
      ModalResult = 1
      TabOrder = 2
    end
    object bFiles: TBitBtn
      Left = 818
      Top = 8
      Width = 68
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      TabOrder = 3
      OnClick = BuildGraph
    end
    object bSize: TBitBtn
      Tag = 1
      Left = 892
      Top = 8
      Width = 68
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      TabOrder = 4
      OnClick = BuildGraph
    end
  end
  object vtcSelected: TChart
    Left = 500
    Top = 57
    Width = 607
    Height = 332
    AllowPanning = pmNone
    Gradient.EndColor = 16579071
    Legend.Alignment = laLeft
    MarginBottom = 0
    MarginLeft = 0
    MarginRight = 0
    MarginTop = 0
    Title.Text.Strings = (
      '....')
    Title.Visible = False
    BottomAxis.Axis.Color = clWhite
    BottomAxis.LabelsFormat.Font.Color = clWhite
    BottomAxis.Ticks.Visible = False
    DepthAxis.Automatic = False
    DepthAxis.AutomaticMaximum = False
    DepthAxis.AutomaticMinimum = False
    DepthAxis.Maximum = 0.530000000000000000
    DepthAxis.Minimum = -0.470000000000000000
    DepthTopAxis.Automatic = False
    DepthTopAxis.AutomaticMaximum = False
    DepthTopAxis.AutomaticMinimum = False
    DepthTopAxis.Maximum = 0.530000000000000000
    DepthTopAxis.Minimum = -0.470000000000000000
    LeftAxis.Axis.Color = clWhite
    LeftAxis.LabelsFormat.Font.Color = clWhite
    RightAxis.Automatic = False
    RightAxis.AutomaticMaximum = False
    RightAxis.AutomaticMinimum = False
    View3D = False
    View3DOptions.Elevation = 315
    View3DOptions.Orthogonal = False
    View3DOptions.Perspective = 0
    View3DOptions.Rotation = 360
    Zoom.Allow = False
    Align = alClient
    BevelOuter = bvNone
    Color = 3355443
    TabOrder = 3
    OnMouseMove = vtcSelectedMouseMove
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      2
      15
      2)
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      Legend.Visible = False
      BarPen.Visible = False
      Marks.Visible = False
      ShowInLegend = False
      Dark3D = False
      MultiBar = mbNone
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
end
