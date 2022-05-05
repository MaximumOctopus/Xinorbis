object frmFileAges: TfrmFileAges
  Left = 532
  Top = 262
  BorderIcons = [biSystemMenu]
  ClientHeight = 580
  ClientWidth = 837
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  Scaled = False
  OnCanResize = FormCanResize
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 177
    Height = 580
    Align = alLeft
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    object bGo: TBitBtn
      Left = 8
      Top = 255
      Width = 161
      Height = 25
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FF874480833F7E7F387D7C337C792E7BC63A13C63712C4
        3112C02E11C02A10BF270F7C4F257A4A2177461E75421B733F19413DF3999BFE
        9698FE9395FE9193FEC94315E0935DDF8F59DF8D55DE8A51C02E11A2C99E9DC6
        9998C39594C091276D2C4A47F59EA0FE5B5EFE5659FE9597FECD4C16E19763DA
        8041D97D3BDF8F58C63512A8CDA477B07170AB6A9AC4962E76335351F6A2A4FE
        6266FE5D61FE999BFECF5518E39C6CDC864ADB8344E0945EC63C13AFD1AB80B7
        7A79B273A0C89C35803C5B5BF8A8AAFE6B6FFE6569FE9EA0FED1601AE5A274DE
        8C53DD894DE29966C94515B5D5B08ABD8383B87DA7CDA33D8B446364FAACAFFE
        7276FE6D71FEA2A4FED6691EE7A77BE0925CDF8F56E49E6ECD4E16BAD9B5B7D6
        B1B3D3AEAED1A945964D6A6CFCB0B3FE797EFE7579FEA8AAFED8742AE8AD83E2
        9865E19560E5A376CF571860BC6C5CB66757B06152A85C4DA1557073FDB4B7FE
        8185FE7C81FEACAFFED97B39EAB28AE49F6EE39C6AE7A87DD1621AFF00FFFF00
        FFFF00FFFF00FFFF00FF7478FEB8BBFEB6B9FEB3B6FEB0B3FEDF8445ECB792E6
        A578E6A273E9AD85D66B1EFF00FFFF00FFFF00FFFF00FFFF00FF7478FE7478FE
        7276FE6E71FD6A6CFCE18D52EDBB99E9AC81E7A87CEAB38DD8742CFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFE2925CEEC1A0EA
        B189E9AE85EDB794DB7C3AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFE69B67F0C5A6ECB691EBB38CEEBC9BDF8547FF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFE8A070F2C8ACF0
        C6A8F0C5A6EFC2A2E18E53FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFEAA677E8A474E8A06EE69D6BE49965E2955EFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      TabOrder = 0
      OnClick = bGoClick
    end
    object bHelp: TBitBtn
      Left = 8
      Top = 319
      Width = 161
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
      TabOrder = 1
      Visible = False
    end
    object BitBtn1: TBitBtn
      Left = 8
      Top = 287
      Width = 81
      Height = 25
      Caption = 'CSV'
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        20000000000000040000120B0000120B00000000000000000000FF00FF00E2C0
        AA00CC8D6600C0714000BC6B3600BC6B3600BC6B3600BC6A3600BC6A3600BB6A
        3500BB6A3500BB693500BD6E3B00CA8B6300E3C2AE00FF00FF00FF00FF00C57C
        4D00F8F2EB00F7ECDF00F6EBDE00F6EADE00F6EADC00F6EADC00FAF3EB00FAF3
        EB00FAF2EA00FCF7F300FCF8F400FEFEFD00C37A4D00FF00FF00FF00FF00C277
        4000F5EBDF00FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
        D100FCE4D100FCE4D100FCE4D100FDFBF800BC6B3700FF00FF00FF00FF00C37C
        4200F7EDE300FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
        D100FCE4D100FCE4D100FCE4D100FBF7F400BD6C3700FF00FF00FF00FF00C680
        4600F7F0E600FCE4D100FCE4D100E5D9C200689E700057966500599766006CA0
        7300FCE4D100FCE4D100FCE4D100FCF9F500C1743C00FF00FF00328449001A75
        33001975330019743300448A5200619B6B00BBD6C30078BB840061AB6A005796
        6400FCE2CC00FBE0C900FBE1C800FDFAF700C37A4100FF00FF00A3C8AD001B75
        33005BA06E0049965C0047905B00C7DDCD005DB6710067AE7500448D58001B75
        3300FCE2CD00FBE1CB00FBE1C900FBF7F200C7804500FF00FF00FF00FF008281
        43001F78370048915D00C7DDCD006AC0840071B68200448E5900B1C1A100FBE4
        D000FBE3CC00FADFC700FADFC600FAF2EA00C8844800FF00FF00FF00FF00C48C
        4F00619E7100C5DCCC0076C9970073BC8700438D580055936000F5E0CC00FBE1
        CC00FAE0C700F9DDC300F8DCC200FAF4ED00C8864B00FF00FF00FF00FF00718C
        5500C0D9C80082D3A3006DC18A00549563004B96600051976400679A6800F4DC
        C300F8DCC200F6DABD00F6D8BB00FAF4EF00C8874C00FF00FF0080B28E00B5D3
        BE009CDAB50074C89500549563004A935F005DA4740059A16E00509764006297
        6200E9D1B400F3D4B500F1D2B300F8F4F000C6864C00FF00FF005B9C6E00568C
        57005396660054956300A1B995008DAE83002E7F42002E7F41003A8448003682
        450090B49000F7F2EC00FBF7F300F5EFE900C3804800FF00FF00FF00FF00C88D
        5200F9F5F100FCE3CD00FBE3CE00FBE3CD00FBE2CB00F9E0C800F8DCC200F5D6
        BA00FDFBF800FCE6CD00FAE5C900E2B68400D5A88400FF00FF00FF00FF00CA92
        5A00FAF6F200FAE0C700FBE1C900FBE2C900FBE0C800F9DFC500F8DBC100F4D6
        B800FFFBF800F6D8B400E1B07D00DC966900FF00FF00FF00FF00FF00FF00D2A2
        7400F8F3ED00F8F4EE00F8F4ED00F8F3ED00F8F3ED00F8F3ED00F8F2EC00F7F2
        EC00F2E6D700E2B27D00DC986B00FF00FF00FF00FF00FF00FF00FF00FF00E8CE
        B900D7AA7C00CC945B00CA905500CA905500CA905500CA915500CB905500C98F
        5500CF9D6900DDB19000FF00FF00FF00FF00FF00FF00FF00FF00}
      TabOrder = 2
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 88
      Top = 287
      Width = 81
      Height = 25
      Caption = 'XML'
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00E2C0AA00CC8D6600C0714000BC6B3600BC6B3600BC6B3600BC6A3600BC6A
        3600BB6A3500BB6A3500BB693500BD6E3B00CA8B6300E3C2AE00FF00FF00FF00
        FF00C57C4D00F8F2EB00F7ECDF00F6EBDE00F6EADE00F6EADC00F6EADC00FAF3
        EB00FAF3EB00FAF2EA00FCF7F300FCF8F400FEFEFD00C37A4D00FF00FF00FF00
        FF00C2774000F5EBDF00FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
        D100FCE4D100FCE4D100FCE4D100FCE4D100FDFBF800BC6B3700FF00FF00FF00
        FF00C37C4200F7EDE300FCE4D100FCE4D100FCE4D100FCE4D100FCE4D100FCE4
        D100FCE4D100FCE4D100FCE4D100FCE4D100FBF7F400BD6C3700FF00FF00FF00
        FF00C77E4400E0926000E08C4C00FCE4D100E2964F00E2894100FCE4D100FCE4
        D100FCE4D100FCE4D100FCE4D100FCE4D100FCF9F500C1743C00FF00FF00FF00
        FF00D7814000E5A36500E1915800FDE5D300E59D5C00E7A86800E3975F00F9DA
        C400FCE2CE00FCE2CC00FBE0C900FBE1C800FDFAF700C37A4100F2CFB400E6A2
        5A00E8AA6A00E39B5D00F9D8C300FDE7D600F9DBC300E5A05D00E8AA6A00E39B
        5600EEB69400FCE2CD00FBE1CB00FBE1C900FBF7F200C7804500E8AC6000ECB8
        7900E5A45800F2D8C400FEE8D600FEE8D700FDE7D600F6D1B300E6A65A00E9B2
        7500E49D5800FAE0C800FADFC700FADFC600FAF2EA00C8844800F4D5B700EAAE
        6000EAB57100E8A66300FADBC500FEE8D800FBDDC500E9AB6100EAB57100E8A7
        5C00EFBA9300FAE0C700F9DDC300F8DCC200FAF4ED00C8864B00FF00FF00FF00
        FF00DE984900EBB67200E8A76100FDE7D600ECB26500ECBB7600EAAC6700F9DA
        C100FADFC700F8DCC200F6DABD00F6D8BB00FAF4EF00C8874C00FF00FF00FF00
        FF00CA8D4F00E9B16E00E8AE5F00FCE6D400ECB66500ECB26900F9DEC400FAE0
        C800F8DCC200F5D6BB00F3D4B500F1D2B300F8F4F000C6864C00FF00FF00FF00
        FF00C88D5100F8EFE600FCE3CF00FBE4D000FCE4CF00FCE3CD00FAE1CA00F9DD
        C400F6D9BC00F4E9DF00F7F2EC00FBF7F300F5EFE900C3804800FF00FF00FF00
        FF00C88D5200F9F5F100FCE3CD00FBE3CE00FBE3CD00FBE2CB00F9E0C800F8DC
        C200F5D6BA00FDFBF800FCE6CD00FAE5C900E2B68400D5A88400FF00FF00FF00
        FF00CA925A00FAF6F200FAE0C700FBE1C900FBE2C900FBE0C800F9DFC500F8DB
        C100F4D6B800FFFBF800F6D8B400E1B07D00DC966900FF00FF00FF00FF00FF00
        FF00D2A27400F8F3ED00F8F4EE00F8F4ED00F8F3ED00F8F3ED00F8F3ED00F8F2
        EC00F7F2EC00F2E6D700E2B27D00DC986B00FF00FF00FF00FF00FF00FF00FF00
        FF00E8CEB900D7AA7C00CC945B00CA905500CA905500CA905500CA915500CB90
        5500C98F5500CF9D6900DDB19000FF00FF00FF00FF00FF00FF00}
      TabOrder = 3
      OnClick = BitBtn2Click
    end
    object gbUsers: TGroupBox
      Left = 8
      Top = 160
      Width = 161
      Height = 49
      TabOrder = 4
      object cbUsers: TComboBox
        Left = 8
        Top = 16
        Width = 145
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = cbAttributeChange
      end
    end
    object cbFiles: TAdvOfficeCheckBox
      Left = 9
      Top = 5
      Width = 163
      Height = 20
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = cbAttributeChange
      Alignment = taLeftJustify
      Caption = '.'
      ReturnIsTab = False
      State = cbChecked
      Version = '1.5.0.9'
    end
    object cbFolders: TAdvOfficeCheckBox
      Left = 8
      Top = 30
      Width = 163
      Height = 20
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = cbAttributeChange
      Alignment = taLeftJustify
      Caption = '.'
      ReturnIsTab = False
      State = cbChecked
      Version = '1.5.0.9'
    end
    object cbAutoRefresh: TAdvOfficeCheckBox
      Left = 9
      Top = 350
      Width = 163
      Height = 20
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      Alignment = taLeftJustify
      Caption = '.'
      ReturnIsTab = False
      State = cbChecked
      Version = '1.5.0.9'
    end
    object cbAttribute: TComboBox
      Left = 8
      Top = 56
      Width = 163
      Height = 21
      Style = csDropDownList
      TabOrder = 8
      OnChange = cbAttributeChange
    end
    object cbFileAgeType: TComboBox
      Left = 8
      Top = 83
      Width = 163
      Height = 21
      Style = csDropDownList
      TabOrder = 9
      OnChange = cbAttributeChange
    end
    object cbInterval: TComboBox
      Left = 64
      Top = 110
      Width = 107
      Height = 21
      Style = csDropDownList
      TabOrder = 10
      OnChange = cbAttributeChange
    end
    object eCount: TEdit
      Left = 8
      Top = 110
      Width = 50
      Height = 21
      TabOrder = 11
      Text = '30'
      OnEnter = eCountEnter
      OnExit = eCountExit
      OnKeyPress = eCountKeyPress
    end
  end
  object Panel2: TPanel
    Left = 177
    Top = 0
    Width = 660
    Height = 580
    Align = alClient
    BevelEdges = [beTop, beRight, beBottom]
    TabOrder = 1
    object sgResults: TAdvStringGrid
      Tag = 1
      Left = 1
      Top = 25
      Width = 658
      Height = 554
      Cursor = crDefault
      Align = alClient
      BevelInner = bvNone
      BevelOuter = bvNone
      ColCount = 6
      DefaultRowHeight = 17
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
      ParentFont = False
      ScrollBars = ssBoth
      TabOrder = 0
      GridLineColor = 15062992
      HoverRowCells = [hcNormal, hcSelected]
      OnGetCellColor = sgResultsGetCellColor
      OnGetAlignment = sgResultsGetAlignment
      OnCanSort = sgResultsCanSort
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
      FixedColWidth = 223
      FixedRowHeight = 17
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
      ShowDesignHelper = False
      SortSettings.DefaultFormat = ssAutomatic
      SortSettings.Column = 0
      SortSettings.Show = True
      Version = '8.4.2.5'
      ColWidths = (
        223
        64
        64
        64
        60
        64)
      RowHeights = (
        17
        17)
    end
    object Panel23: TPanel
      Left = 1
      Top = 1
      Width = 658
      Height = 24
      Align = alTop
      BevelEdges = [beTop, beRight, beBottom]
      BevelOuter = bvNone
      Color = clWhite
      FullRepaint = False
      ParentBackground = False
      TabOrder = 1
      object lStatus: THTMLabel
        Left = 0
        Top = 0
        Width = 658
        Height = 24
        Align = alClient
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        HTMLText.Strings = (
          ' ')
        ParentColor = False
        ParentFont = False
        Transparent = True
        Version = '2.1.0.0'
        ExplicitLeft = 6
        ExplicitTop = 51
        ExplicitWidth = 1549
        ExplicitHeight = 66
      end
    end
  end
end
