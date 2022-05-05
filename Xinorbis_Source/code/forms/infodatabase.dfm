object frmDatabaseInfo: TfrmDatabaseInfo
  Left = 541
  Top = 343
  BorderIcons = [biSystemMenu]
  Caption = '.'
  ClientHeight = 315
  ClientWidth = 864
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
  object sgDatabase: TAdvStringGrid
    Left = 0
    Top = 43
    Width = 864
    Height = 232
    Cursor = crDefault
    Align = alClient
    ColCount = 6
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
    OnClick = sgDatabaseClick
    HoverRowCells = [hcNormal, hcSelected]
    OnResize = sgDatabaseResize
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    Bands.Active = True
    Bands.PrimaryColor = 16381426
    CellNode.TreeColor = clSilver
    ControlLook.FixedGradientHoverFrom = clGray
    ControlLook.FixedGradientHoverTo = clWhite
    ControlLook.FixedGradientDownFrom = clGray
    ControlLook.FixedGradientDownTo = clSilver
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
    FixedColWidth = 99
    FixedRowHeight = 19
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = [fsBold]
    FloatFormat = '%.2f'
    HoverButtons.Buttons = <>
    HoverButtons.Position = hbLeftFromColumnLeft
    HTMLSettings.ImageFolder = 'images'
    HTMLSettings.ImageBaseName = 'img'
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
    SearchFooter.Font.Charset = DEFAULT_CHARSET
    SearchFooter.Font.Color = clWindowText
    SearchFooter.Font.Height = -11
    SearchFooter.Font.Name = 'MS Sans Serif'
    SearchFooter.Font.Style = []
    SearchFooter.ResultFormat = '(%d of %d)'
    ShowDesignHelper = False
    SortSettings.DefaultFormat = ssAutomatic
    SortSettings.Column = 0
    Version = '8.2.2.0'
    ColWidths = (
      99
      147
      101
      320
      64
      50)
    RowHeights = (
      19
      19)
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 864
    Height = 43
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    DesignSize = (
      864
      43)
    object Image1: TImage
      Left = 8
      Top = 8
      Width = 16
      Height = 16
      AutoSize = True
      Picture.Data = {
        07544269746D617036050000424D360500000000000036040000280000001000
        000010000000010008000000000000010000C21E0000C21E0000000100000000
        0000000000000101010002020200030303000404040005050500060606000707
        070008080800090909000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F
        0F00101010001111110012121200131313001414140015151500161616001717
        170018181800191919001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F
        1F00202020002121210022222200232323002424240025252500262626002727
        270028282800292929002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F
        2F00303030003131310032323200333333003434340035353500363636003737
        370038383800393939003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F
        3F00404040004141410042424200434343004444440045454500464646004747
        470048484800494949004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F
        4F00505050005151510052525200535353005454540055555500565656005757
        570058585800595959005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F
        5F00606060006161610062626200636363006464640065656500666666006767
        670068686800696969006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F
        6F00707070007171710072727200737373007474740075757500767676007777
        770078787800797979007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F
        7F00808080008181810082828200838383008484840085858500868686008787
        870088888800898989008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F
        8F00909090009191910092929200939393009494940095959500969696009797
        970098989800999999009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F
        9F00A0A0A000A1A1A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7
        A700A8A8A800A9A9A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAF
        AF00B0B0B000B1B1B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7
        B700B8B8B800B9B9B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBF
        BF00C0C0C000C1C1C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7
        C700C8C8C800C9C9C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCF
        CF00D0D0D000D1D1D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7
        D700D8D8D800D9D9D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDF
        DF00E0E0E000E1E1E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7
        E700E8E8E800E9E9E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEF
        EF00F0F0F000F1F1F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7
        F700F8F8F800F9F9F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFF
        FF00FFFFFFFFFFFFFAEBEBFCFFFFFFFFFFFFFFFFFFF3C5A5A1ABA79598BFF5FF
        FFFFFFFFE5A9CEEDF4F5F4EFE2BA95E6FFFFFFFFB0DEF3DBD2DBD6C0C9E6C495
        FFFFFFFFB3F0DED4D2DBD6BFB0B3DE99FFFFFFFFB5F2E2D8D5DCD8C0B3B7E09F
        FFFFFFFFB7F3E7DDD9E0DBC4B8BBE1A3FFFFFFFFB8F4EAE1DDE3DEC9BDBFE2A6
        FFFFFFFFBAF5EEE6E2E6E1CDC2C2E3A8FFFFFFFFBBF6EBDED6D5D1C3BCC0E5AB
        FFFFFFFFBDF7E7EFF6FBFAF0DEC3E6ACFFFFFFFFBFF8FEFFFFFFFFFFFFFBEAAE
        FFFFFFFFCBE1FEFFFFFFFFFFFFFBCFC9FFFFFFFFF4C7D0E8F3FDFCEDE0C2C0F6
        FFFFFFFFFFFDE8D0C3B8B8C3CDEAFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF}
    end
    object lSize: TLabel
      Left = 32
      Top = 8
      Width = 5
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lTables: TLabel
      Left = 32
      Top = 24
      Width = 5
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lDatabaseSize: THTMLabel
      Left = 88
      Top = 8
      Width = 760
      Height = 17
      Anchors = [akLeft, akTop, akRight]
      HTMLText.Strings = (
        '...')
      Transparent = True
      Version = '1.9.2.6'
    end
    object lTableCount: THTMLabel
      Left = 88
      Top = 24
      Width = 760
      Height = 17
      Anchors = [akLeft, akTop, akRight]
      HTMLText.Strings = (
        '...')
      Transparent = True
      Version = '1.9.2.6'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 275
    Width = 864
    Height = 40
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    DesignSize = (
      864
      40)
    object Bevel2: TBevel
      Left = 240
      Top = 8
      Width = 9
      Height = 25
      Shape = bsLeftLine
    end
    object Bevel3: TBevel
      Left = 320
      Top = 8
      Width = 9
      Height = 25
      Shape = bsLeftLine
    end
    object sbShowNames: TBitBtn
      Left = 4
      Top = 8
      Width = 113
      Height = 25
      Caption = '.'
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7272725C5C5CFFFF
        FFFFFFFFFFFFFFFFFFFFDFB493D59D74D19668CE9263CB8E5EC98A5BC787569F
        8672696969AE815EA2A2A28B8B8BA379585E5E5E878787FFFFFFD7A175F8F2ED
        F7F0EAF6EDE6F4EAE2F3E7DEF1E4DBA0A0A0C9C9C9A5A5A5CACACAC2C2C2A1A1
        A1C4C4C46D6D6DFDFDFDD9A47AF9F3EEEBD2BEFFFFFFEBD3BFFFFFFFF9F9F9CD
        CDCDC9C9C9BDBDBD9C9C9C9A9A9AB5B5B5C2C2C2A6A6A6F4F4F4DDA87EF9F3EF
        EBD0BAEBD0BBEBD0BBEBD0BBA5A5A5B7B7B7E1E1E19C9C9CEACDB5EACDB59A9A
        99D5D5D5999999656565DFAA82F9F3EFEACEB7FFFFFFEBD0BBFFFFFFB4B4B4CA
        CACAE8E8E8868686FFFFFFFFFFFF9A9999E2E2E2B6B6B6878787E1AE87FAF4F0
        EACBB2EACCB3EACCB3EACCB3EACCB3CEC1B6D2D2D2ABABAB8181818A8A8AB4B4
        B4CACACABCBCBCFFFFFFE3B18CFAF6F1EAC9AEFFFFFFEAC9B0FFFFFFFFFFFFBA
        BABADADADABFBFBFD6D6D6D8D8D8B8B8B8D4D4D4888888FAFAFAE5B48FFAF6F2
        E9C6AAE9C6ACEAC7ACE9C7ADE9C9AED5C4B7BDBBBADFC5B1C0C0C0BEBEBEE0D7
        D1ABA39EC8C8C8FFFFFFE7B794FBF7F4E9C3A6FFFFFFE8C4A9FFFFFFFFFFFFFF
        FFFFE8C7ACFFFFFFBABABAB4B4B4F7F1EBCB8F5FFFFFFFFFFFFFE9BA98FBF7F4
        E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6FBF7
        F4CE9364FFFFFFFFFFFFEBBD9BFBF7F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBF7F4D1976AFFFFFFFFFFFFECBF9EFBF7F4
        9CD5A598D3A194D09D90CE988BCB9387C98E82C6897EC3847AC18076BE7CFBF7
        F4D49B6FFFFFFFFFFFFFEFC6A8FBF7F4FBF7F4FBF7F4FBF7F4FBF7F4FBF7F4FB
        F7F4FBF7F4FBF7F4FBF7F4FBF7F4FBF7F4D8A378FFFFFFFFFFFFF7E1D2F1C8AC
        EDC09FEBBE9DEBBC9AE9BA96E7B793E6B590E4B28CE2AF88E0AC84DDA980DCA5
        7DE2B696FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      TabOrder = 0
      OnClick = sbShowNamesClick
    end
    object sbDeleteTable: TBitBtn
      Left = 120
      Top = 8
      Width = 113
      Height = 25
      Caption = '.'
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF95B0E3235CC20543
        BC1F59C186A6DDFFFFFFFFFFFFDFB493D59D74D19668CE9263CB8E5EC98A5BC7
        8756C384526E6D8B2765C72177E60579EA0164DD064EBC86A6DDFFFFFFD7A175
        F8F2EDF7F0EAF6EDE6F4EAE2F3E7DEF1E4DBF0E2D81D56BC639DF4187FFF0076
        F80076EE0368E11E59C0FFFFFFD9A47AF9F3EEEBD2BEFFFFFFEBD3BFFFFFFFFF
        FFFFFFFFFF0543BCAECDFEFFFFFFFFFFFFFFFFFF187FEF0543BCFFFFFFDDA87E
        F9F3EFEBD0BAEBD0BBEBD0BBEBD0BBEBD0BBEBD1BD2256B88DB5F64D92FF1177
        FF2186FF408AEB245CC2FFFFFFDFAA82F9F3EFEACEB7FFFFFFEBD0BBFFFFFFFF
        FFFFFFFFFF8B97BF3D76D28DB5F7B8D6FE72A8F52F6BCA94AFE2FFFFFFE1AE87
        FAF4F0EACBB2EACCB3EACCB3EACCB3EACCB3EACEB7E8C7AC8993B7285BBE0543
        BC1E57BD696784FFFFFFFFFFFFE3B18CFAF6F1EAC9AEFFFFFFEAC9B0FFFFFFFF
        FFFFFFFFFFE8C7ACFFFFFFFFFFFFFFFFFFF1E5DBC68655FFFFFFFFFFFFE5B48F
        FAF6F2E9C6AAE9C6ACEAC7ACE9C7ADE9C9AEE9C9B0E8C7ACE9C9B0E8C8B0E8CC
        B5F2E7DEC88A59FFFFFFFFFFFFE7B794FBF7F4E9C3A6FFFFFFE8C4A9FFFFFFFF
        FFFFFFFFFFE8C7ACFFFFFFFFFFFFFFFFFFF7F1EBCB8F5FFFFFFFFFFFFFE9BA98
        FBF7F4E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3A6E9C3
        A6FBF7F4CE9364FFFFFFFFFFFFEBBD9BFBF7F4FFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBF7F4D1976AFFFFFFFFFFFFECBF9E
        FBF7F49CD5A598D3A194D09D90CE988BCB9387C98E82C6897EC3847AC18076BE
        7CFBF7F4D49B6FFFFFFFFFFFFFEFC6A8FBF7F4FBF7F4FBF7F4FBF7F4FBF7F4FB
        F7F4FBF7F4FBF7F4FBF7F4FBF7F4FBF7F4FBF7F4D8A378FFFFFFFFFFFFF7E1D2
        F1C8ACEDC09FEBBE9DEBBC9AE9BA96E7B793E6B590E4B28CE2AF88E0AC84DDA9
        80DCA57DE2B696FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      TabOrder = 1
      OnClick = sbDeleteTableClick
    end
    object bSave: TBitBtn
      Left = 248
      Top = 8
      Width = 65
      Height = 25
      Caption = 'ASCII'
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFE2C0AA
        CC8D66C07140BC6B36BC6B36BC6B36BC6A36BC6A36BB6A35BB6A35BB6935BD6E
        3BCA8B63E3C2AEFFFFFFFFFFFFBEBEBE8B8B8B7070706A6A6A6A6A6A6A6A6A69
        69696969696969696969696868686D6D6D898989C0C0C0FFFFFFFFFFFFC57C4D
        F8F1EAF7ECDFF6EBDEF6EADEF6EADCF6EADCFAF3EBFAF3EBFAF2EAFCF7F3FCF8
        F4FEFEFDC37A4DFFFFFFFFFFFF7A7A7AF0F0F0EAEAEAE9E9E9E9E9E9E8E8E8E8
        E8E8F2F2F2F2F2F2F1F1F1F7F7F7F8F8F8FEFEFE797979FFFFFFFFFFFFC27740
        F5EBDFFCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FDFBF8BC6B37FFFFFFFFFFFF757575EAEAEAE2E2E2E2E2E2E2E2E2E2E2E2E2
        E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2FBFBFB6A6A6AFFFFFFFFFFFFC37C42
        F7EDE3FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FBF7F4BD6C37FFFFFFFFFFFF797979ECECECE2E2E2E2E2E2E2E2E2E2E2E2E2
        E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2F7F7F76B6B6BFFFFFFFFFFFFC68046
        F7F0E6FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FCF9F5C1743CFFFFFFFFFFFF7D7D7DEFEFEFE2E2E2E2E2E2E2E2E2E2E2E2E2
        E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2F9F9F9727272FFFFFFFFFFFFC78448
        F8F1E8FEE5D5FDE5D3FDE5D3FCE5D3FCE5D3FCE4D1FCE2CEFCE2CCFBE0C9FBE1
        C8FDFAF7C37A41FFFFFFFFFFFF808080F0F0F0E3E3E3E3E3E3E3E3E3E3E3E3E3
        E3E3E2E2E2E0E0E0DFDFDFDDDDDDDEDEDEFAFAFA777777FFFFFFFFFFFFC7864B
        F8F2EBFEE7D6FDE7D6FDE7D6FDE7D6FDE6D5FDE5D3FCE4D1FCE2CDFBE1CBFBE1
        C9FBF7F2C78045FFFFFFFFFFFF828282F1F1F1E5E5E5E5E5E5E5E5E5E5E5E5E4
        E4E4E3E3E3E2E2E2E0E0E0DEDEDEDEDEDEF7F7F77C7C7CFFFFFFFFFFFFC8884D
        F9F3ECFEE8D6FEE8D7FDE7D6FDE7D6FDE7D5FDE5D3FBE4D0FBE3CCFADFC7FADF
        C6FAF2EAC88448FFFFFFFFFFFF838383F2F2F2E6E6E6E6E6E6E5E5E5E5E5E5E5
        E5E5E3E3E3E1E1E1E0E0E0DCDCDCDCDCDCF1F1F1808080FFFFFFFFFFFFC88C4F
        F9F4EDFEE8D8FEE8D8FEE8D7FEE7D6FDE5D3FCE4D1FBE1CCFAE0C7F9DDC3F8DC
        C2FAF4EDC8864BFFFFFFFFFFFF868686F3F3F3E6E6E6E6E6E6E6E6E6E5E5E5E3
        E3E3E2E2E2DFDFDFDDDDDDDADADAD9D9D9F3F3F3828282FFFFFFFFFFFFC88C50
        F9F4EFFEE7D7FDE7D6FDE7D5FDE6D4FCE6D2FBE1CCFADFC7F8DCC2F6DABDF6D8
        BBFAF4EFC8874CFFFFFFFFFFFF878787F4F4F4E5E5E5E5E5E5E5E5E5E4E4E4E3
        E3E3DFDFDFDCDCDCD9D9D9D6D6D6D4D4D4F4F4F4838383FFFFFFFFFFFFC88D51
        F9F4F0FCE6D3FCE6D4FDE7D3FCE4D1FBE3CDFAE0C8F8DCC2F5D6BBF3D4B5F1D2
        B3F8F4F0C6864CFFFFFFFFFFFF878787F4F4F4E3E3E3E4E4E4E4E4E4E2E2E2E0
        E0E0DDDDDDD9D9D9D2D2D2D0D0D0CECECEF4F4F4828282FFFFFFFFFFFFC88D51
        F9F5F1FCE3CFFBE4D0FCE4CFFCE3CDFAE1CAF9DDC4F6D9BCF4E9DFF7F2ECFBF7
        F3F5EFE9C38048FFFFFFFFFFFF878787F5F5F5E1E1E1E1E1E1E1E1E1E0E0E0DE
        DEDEDADADAD5D5D5E8E8E8F1F1F1F7F7F7EEEEEE7D7D7DFFFFFFFFFFFFC88D52
        F9F5F1FCE3CDFBE3CEFBE3CDFBE2CBF9E0C8F8DCC2F5D6BAFDFBF8FCE6CDFAE5
        C9E2B684D5A884FFFFFFFFFFFF878787F5F5F5E0E0E0E0E0E0E0E0E0DFDFDFDD
        DDDDD9D9D9D2D2D2FBFBFBE2E2E2E1E1E1B0B0B0A5A5A5FFFFFFFFFFFFCA925A
        FAF6F2FAE0C7FBE1C9FBE2C9FBE0C8F9DFC5F8DBC1F4D6B8FFFBF8F6D8B4E1B0
        7DDC9669FDFBFAFFFFFFFFFFFF8D8D8DF6F6F6DDDDDDDEDEDEDFDFDFDDDDDDDC
        DCDCD8D8D8D2D2D2FBFBFBD3D3D3AAAAAA939393FBFBFBFFFFFFFFFFFFD2A274
        F8F3EDF8F4EEF8F4EDF8F3EDF8F3EDF8F3EDF8F2ECF7F2ECF2E6D7E2B27DDC98
        6BFDFBFAFFFFFFFFFFFFFFFFFF9D9D9DF2F2F2F3F3F3F3F3F3F2F2F2F2F2F2F2
        F2F2F1F1F1F1F1F1E4E4E4ACACAC959595FBFBFBFFFFFFFFFFFFFFFFFFE8CEB9
        D7AA7CCC945BCA9055CA9055CA9055CA9155CB9055C98F55CF9D69DDB190FDFB
        FAFFFFFFFFFFFFFFFFFFFFFFFFCCCCCCA5A5A58E8E8E8A8A8A8A8A8A8A8A8A8B
        8B8B8A8A8A898989979797AEAEAEFBFBFBFFFFFFFFFFFFFFFFFF}
      NumGlyphs = 2
      TabOrder = 2
      OnClick = bSaveClick
    end
    object bExportCSV: TBitBtn
      Left = 328
      Top = 8
      Width = 65
      Height = 25
      Caption = 'CSV'
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFE2C0AA
        CC8D66C07140BC6B36BC6B36BC6B36BC6A36BC6A36BB6A35BB6A35BB6935BD6E
        3BCA8B63E3C2AEFFFFFFFFFFFFC0C0C08D8D8D7171716B6B6B6B6B6B6B6B6B6A
        6A6A6A6A6A6969696969696969696E6E6E8B8B8BC2C2C2FFFFFFFFFFFFC57C4D
        F8F2EBF7ECDFF6EBDEF6EADEF6EADCF6EADCFAF3EBFAF3EBFAF2EAFCF7F3FCF8
        F4FEFEFDC37A4DFFFFFFFFFFFF7C7C7CF1F1F1EAEAEAE9E9E9E9E9E9E8E8E8E8
        E8E8F2F2F2F2F2F2F1F1F1F7F7F7F8F8F8FEFEFE7A7A7AFFFFFFFFFFFFC27740
        F5EBDFFCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FDFBF8BC6B37FFFFFFFFFFFF757575EAEAEAE2E2E2E2E2E2E2E2E2E2E2E2E2
        E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2FBFBFB6B6B6BFFFFFFFFFFFFC37C42
        F7EDE3FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FBF7F4BD6C37FFFFFFFFFFFF797979ECECECE2E2E2E2E2E2E2E2E2E2E2E2E2
        E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2F7F7F76C6C6CFFFFFFFFFFFFC68046
        F7F0E6FCE4D1FCE4D1E5D9C2689E705796655997666CA073FCE4D1FCE4D1FCE4
        D1FCF9F5C1743CFFFFFFFFFFFF7D7D7DEFEFEFE2E2E2E2E2E2D5D5D59393938A
        8A8A8B8B8B959595E2E2E2E2E2E2E2E2E2F9F9F9727272FFFFFF3284491A7533
        197533197433448A52619B6BBBD6C378BB8461AB6A579664FCE2CCFBE0C9FBE1
        C8FDFAF7C37A41FFFFFF7777776767676767676666667D7D7D8F8F8FD1D1D1AD
        ADAD9C9C9C8A8A8ADFDFDFDDDDDDDEDEDEFAFAFA777777FFFFFFA3C8AD1B7533
        5BA06E49965C47905BC7DDCD5DB67167AE75448D581B7533FCE2CDFBE1CBFBE1
        C9FBF7F2C78045FFFFFFC2C2C2676767939393888888838383D8D8D8A6A6A6A0
        A0A0808080676767E0E0E0DEDEDEDEDEDEF7F7F77D7D7DFFFFFFFFFFFF828143
        1F783748915DC7DDCD6AC08471B682448E59B1C1A1FBE4D0FBE3CCFADFC7FADF
        C6FAF2EAC88448FFFFFFFFFFFF7777776A6A6A848484D8D8D8B1B1B1A9A9A981
        8181BABABAE1E1E1E0E0E0DCDCDCDCDCDCF1F1F1808080FFFFFFFFFFFFC48C4F
        619E71C5DCCC76C99773BC87438D58559360F5E0CCFBE1CCFAE0C7F9DDC3F8DC
        C2FAF4EDC8864BFFFFFFFFFFFF868686939393D7D7D7BBBBBBAEAEAE80808087
        8787DDDDDDDFDFDFDDDDDDDADADAD9D9D9F3F3F3828282FFFFFFFAFCFA718C55
        C0D9C882D3A36DC18A5495634B9660519764679A68F4DCC3F8DCC2F6DABDF6D8
        BBFAF4EFC8874CFFFFFFFCFCFC818181D4D4D4C6C6C6B3B3B38989898989898A
        8A8A8E8E8ED9D9D9D9D9D9D6D6D6D4D4D4F4F4F4838383FFFFFF80B28EB5D3BE
        9CDAB574C8955495634A935F5DA47459A16E509764629762E9D1B4F3D4B5F1D2
        B3F8F4F0C6864CFFFFFFA9A9A9CDCDCDD0D0D0BABABA89898986868698989894
        94948A8A8A8B8B8BCDCDCDD0D0D0CECECEF4F4F4828282FFFFFF5B9C6E568C57
        539666549563A1B9958DAE832E7F422E7F413A844836824590B490F7F2ECFBF7
        F3F5EFE9C38048FFFFFF9090908080808A8A8A898989B1B1B1A4A4A471717171
        7171767676747474ABABABF1F1F1F7F7F7EEEEEE7D7D7DFFFFFFFFFFFFC88D52
        F9F5F1FCE3CDFBE3CEFBE3CDFBE2CBF9E0C8F8DCC2F5D6BAFDFBF8FCE6CDFAE5
        C9E2B684D5A884FFFFFFFFFFFF888888F5F5F5E0E0E0E0E0E0E0E0E0DFDFDFDD
        DDDDD9D9D9D2D2D2FBFBFBE2E2E2E1E1E1B0B0B0A6A6A6FFFFFFFFFFFFCA925A
        FAF6F2FAE0C7FBE1C9FBE2C9FBE0C8F9DFC5F8DBC1F4D6B8FFFBF8F6D8B4E1B0
        7DDC9669FDFBFAFFFFFFFFFFFF8D8D8DF6F6F6DDDDDDDEDEDEDFDFDFDDDDDDDC
        DCDCD8D8D8D2D2D2FBFBFBD3D3D3AAAAAA949494FBFBFBFFFFFFFFFFFFD2A274
        F8F3EDF8F4EEF8F4EDF8F3EDF8F3EDF8F3EDF8F2ECF7F2ECF2E6D7E2B27DDC98
        6BFDFBFAFFFFFFFFFFFFFFFFFF9E9E9EF2F2F2F3F3F3F3F3F3F2F2F2F2F2F2F2
        F2F2F1F1F1F1F1F1E4E4E4ACACAC959595FBFBFBFFFFFFFFFFFFFFFFFFE8CEB9
        D7AA7CCC945BCA9055CA9055CA9055CA9155CB9055C98F55CF9D69DDB190FDFB
        FAFFFFFFFFFFFFFFFFFFFFFFFFCDCDCDA6A6A68E8E8E8A8A8A8A8A8A8A8A8A8B
        8B8B8B8B8B8A8A8A999999AFAFAFFBFBFBFFFFFFFFFFFFFFFFFF}
      NumGlyphs = 2
      TabOrder = 3
      OnClick = bExportCSVClick
    end
    object bExportXML: TBitBtn
      Left = 400
      Top = 8
      Width = 65
      Height = 25
      Caption = 'XML'
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        E2C0AACC8D66C07140BC6B36BC6B36BC6B36BC6A36BC6A36BB6A35BB6A35BB69
        35BD6E3BCA8B63E3C2AEFFFFFFFFFFFFC0C0C08D8D8D7171716B6B6B6B6B6B6B
        6B6B6A6A6A6A6A6A6969696969696969696E6E6E8B8B8BC2C2C2FFFFFFFFFFFF
        C57C4DF8F2EBF7ECDFF6EBDEF6EADEF6EADCF6EADCFAF3EBFAF3EBFAF2EAFCF7
        F3FCF8F4FEFEFDC37A4DFFFFFFFFFFFF7C7C7CF1F1F1EAEAEAE9E9E9E9E9E9E8
        E8E8E8E8E8F2F2F2F2F2F2F1F1F1F7F7F7F8F8F8FEFEFE7A7A7AFFFFFFFFFFFF
        C27740F5EBDFFCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FCE4D1FDFBF8BC6B37FFFFFFFFFFFF757575EAEAEAE2E2E2E2E2E2E2E2E2E2
        E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2FBFBFB6B6B6BFFFFFFFFFFFF
        C37C42F7EDE3FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FCE4D1FBF7F4BD6C37FFFFFFFFFFFF797979ECECECE2E2E2E2E2E2E2E2E2E2
        E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2F7F7F76C6C6CFFFFFFFFFFFF
        C77E44E09260E08C4CFCE4D1E2964FE28941FCE4D1FCE4D1FCE4D1FCE4D1FCE4
        D1FCE4D1FCF9F5C1743CFFFFFFFFFFFF7B7B7B909090888888E2E2E291919186
        8686E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2F9F9F9727272FFFFFFFCF4EF
        D78140E5A365E19158FDE5D3E59D5CE7A868E3975FF9DAC4FCE2CEFCE2CCFBE0
        C9FBE1C8FDFAF7C37A41FFFFFFF4F4F47E7E7E9E9E9E8E8E8EE3E3E3989898A2
        A2A2949494D8D8D8E0E0E0DFDFDFDDDDDDDEDEDEFAFAFA777777F2CFB4E6A25A
        E8AA6AE39B5DF9D8C3FDE7D6F9DBC3E5A05DE8AA6AE39B56EEB694FCE2CDFBE1
        CBFBE1C9FBF7F2C78045CECECE9C9C9CA4A4A4969696D6D6D6E5E5E5D8D8D89A
        9A9AA4A4A4969696B3B3B3E0E0E0DEDEDEDEDEDEF7F7F77D7D7DE8AC60ECB879
        E5A458F2D8C4FEE8D6FEE8D7FDE7D6F6D1B3E6A65AE9B275E49D58FAE0C8FADF
        C7FADFC6FAF2EAC88448A4A4A4B0B0B09D9D9DD6D6D6E6E6E6E6E6E6E5E5E5CD
        CDCD9F9F9FABABAB989898DDDDDDDCDCDCDCDCDCF1F1F1808080F4D5B7EAAE60
        EAB571E8A663FADBC5FEE8D8FBDDC5E9AB61EAB571E8A75CEFBA93FAE0C7F9DD
        C3F8DCC2FAF4EDC8864BD3D3D3A6A6A6ADADADA0A0A0D9D9D9E6E6E6DADADAA3
        A3A3ADADADA0A0A0B6B6B6DDDDDDDADADAD9D9D9F3F3F3828282FFFFFFFDF6F0
        DE9849EBB672E8A761FDE7D6ECB265ECBB76EAAC67F9DAC1FADFC7F8DCC2F6DA
        BDF6D8BBFAF4EFC8874CFFFFFFF6F6F6919191AEAEAEA0A0A0E5E5E5A9A9A9B2
        B2B2A5A5A5D7D7D7DCDCDCD9D9D9D6D6D6D4D4D4F4F4F4838383FFFFFFFFFFFF
        CA8D4FE9B16EE8AE5FFCE6D4ECB665ECB269F9DEC4FAE0C8F8DCC2F5D6BBF3D4
        B5F1D2B3F8F4F0C6864CFFFFFFFFFFFF888888A9A9A9A6A6A6E4E4E4ADADADAA
        AAAADBDBDBDDDDDDD9D9D9D2D2D2D0D0D0CECECEF4F4F4828282FFFFFFFFFFFF
        C88D51F8EFE6FCE3CFFBE4D0FCE4CFFCE3CDFAE1CAF9DDC4F6D9BCF4E9DFF7F2
        ECFBF7F3F5EFE9C38048FFFFFFFFFFFF888888EEEEEEE1E1E1E1E1E1E1E1E1E0
        E0E0DEDEDEDADADAD5D5D5E8E8E8F1F1F1F7F7F7EEEEEE7D7D7DFFFFFFFFFFFF
        C88D52F9F5F1FCE3CDFBE3CEFBE3CDFBE2CBF9E0C8F8DCC2F5D6BAFDFBF8FCE6
        CDFAE5C9E2B684D5A884FFFFFFFFFFFF888888F5F5F5E0E0E0E0E0E0E0E0E0DF
        DFDFDDDDDDD9D9D9D2D2D2FBFBFBE2E2E2E1E1E1B0B0B0A6A6A6FFFFFFFFFFFF
        CA925AFAF6F2FAE0C7FBE1C9FBE2C9FBE0C8F9DFC5F8DBC1F4D6B8FFFBF8F6D8
        B4E1B07DDC9669FDFBFAFFFFFFFFFFFF8D8D8DF6F6F6DDDDDDDEDEDEDFDFDFDD
        DDDDDCDCDCD8D8D8D2D2D2FBFBFBD3D3D3AAAAAA949494FBFBFBFFFFFFFFFFFF
        D2A274F8F3EDF8F4EEF8F4EDF8F3EDF8F3EDF8F3EDF8F2ECF7F2ECF2E6D7E2B2
        7DDC986BFDFBFAFFFFFFFFFFFFFFFFFF9E9E9EF2F2F2F3F3F3F3F3F3F2F2F2F2
        F2F2F2F2F2F1F1F1F1F1F1E4E4E4ACACAC959595FBFBFBFFFFFFFFFFFFFFFFFF
        E8CEB9D7AA7CCC945BCA9055CA9055CA9055CA9155CB9055C98F55CF9D69DDB1
        90FDFBFAFFFFFFFFFFFFFFFFFFFFFFFFCDCDCDA6A6A68E8E8E8A8A8A8A8A8A8A
        8A8A8B8B8B8B8B8B8A8A8A999999AFAFAFFBFBFBFFFFFFFFFFFF}
      NumGlyphs = 2
      TabOrder = 4
      OnClick = bExportXMLClick
    end
    object bCancel: TBitBtn
      Left = 775
      Top = 8
      Width = 81
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
      TabOrder = 5
    end
  end
  object sdInfoDatabase: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Text files (*.txt)|*.txt'
    Left = 784
    Top = 8
  end
end