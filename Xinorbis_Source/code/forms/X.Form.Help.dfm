object frmHelp: TfrmHelp
  Left = 490
  Top = 221
  Caption = 'Xinorbis Help'
  ClientHeight = 567
  ClientWidth = 844
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 217
    Top = 29
    Height = 538
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 29
    Width = 217
    Height = 538
    ActivePage = TabSheet1
    Align = alLeft
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Contents'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object wbContents: TWebBrowser
        Left = 0
        Top = 0
        Width = 209
        Height = 510
        Align = alClient
        TabOrder = 0
        OnBeforeNavigate2 = wbContentsBeforeNavigate2
        ControlData = {
          4C0000009A150000B63400000000000000000000000000000000000000000000
          000000004C000000000000000000000001000000E0D057007335CF11AE690800
          2B2E126208000000000000004C0000000114020000000000C000000000000046
          8000000000000000000000000000000000000000000000000000000000000000
          00000000000000000100000000000000000000000000000000000000}
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Search'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object tvSearch: TTreeView
        Left = 0
        Top = 41
        Width = 209
        Height = 469
        Align = alClient
        Indent = 19
        TabOrder = 0
        OnDblClick = tvSearchDblClick
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 209
        Height = 41
        Align = alTop
        TabOrder = 1
        object sbSearch: TSpeedButton
          Left = 184
          Top = 2
          Width = 23
          Height = 22
          Glyph.Data = {
            36060000424D3606000000000000360000002800000020000000100000000100
            18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFDFEE7EE
            F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFDFDFDEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFBFD6494BA2267
            9D81A8C6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFCFCFC9B9B9B737373ADADADFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFCFD6F9CC2558DBC89B5
            DD185F97FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFCFCFCA4A4A4979797BDBDBD6C6C6CFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFCFD7BA4CA6497C59DC1E46699
            C73171A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFCFCFCABABABA1A1A1C8C8C8A3A3A37D7D7DFFFFFFFFFFFFFFFFFFFFFFFF
            FFFEFEE8CFBADBB292D3A680D0A17CD2A685AEA19975A2CCABCBE876A4CE407B
            AFDEE8F1FFFFFFFFFFFFFFFFFFFFFFFFFEFEFECDCDCDAFAFAFA2A2A29E9E9EA3
            A3A3A0A0A0ABABABD1D1D1ACACAC878787EAEAEAFFFFFFFFFFFFFFFFFFFFFEFE
            E8CAB0E8C9AEF5E1CDF7E5D3F7E5D1F3DDC8DFBA9CC7A89186AED55087BBE1EA
            F3FFFFFFFFFFFFFFFFFFFFFFFFFEFEFEC7C7C7C6C6C6DEDEDEE3E3E3E2E2E2DA
            DADAB7B7B7A6A6A6B6B6B6939393ECECECFFFFFFFFFFFFFFFFFFFFFFFFF1DBC8
            EDD0B7F8E8D9F5DEC8F3D8BDF3D6BBF4DBC2F7E4D2DFBB9DA09795E3ECF5FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFD9D9D9CDCDCDE6E6E6DBDBDBD4D4D4D2D2D2D8
            D8D8E2E2E2B7B7B7989898EEEEEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEECEB2
            F7E7D7F6E1CCF4DBC2F4DAC0F3D8BDF3D7BBF4DBC2F3DEC9D2A887FFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFCBCBCBE5E5E5DEDEDED8D8D8D7D7D7D4D4D4D3
            D3D3D8D8D8DBDBDBA5A5A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0CEAF
            F9ECDFF5DFC8F5DDC6F4DCC3F4DAC1F3D9BEF3D7BDF8E6D3D3A680FFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFCACACAEAEAEADCDCDCDADADAD9D9D9D7D7D7D5
            D5D5D4D4D4E3E3E3A2A2A2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D3B5
            F9EDE1F6E1CCF5DFC9F5DEC7F4DCC4F4DBC2F4DAC0F8E7D6D7AB87FFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCFECECECDEDEDEDCDCDCDBDBDBD9D9D9D8
            D8D8D7D7D7E5E5E5A8A8A8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8DBC1
            F9EBDEF7E7D6F6E1CCF5E0CAF5DEC8F5DDC5F6E1CBF5E2D0DFB999FFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFD8D8D8E9E9E9E5E5E5DEDEDEDDDDDDDBDBDBDA
            DADADEDEDEE0E0E0B5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCEAD8
            F8E2CCFAEEE3F7E7D6F6E2CEF6E1CBF6E3D0F9EADDECCFB5ECD4BFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8DFDFDFEDEDEDE5E5E5DFDFDFDEDEDEE0
            E0E0E9E9E9CCCCCCD2D2D2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FBE4CEF9E2CDFAECDEF9EEE2F9EDE2F8E9DAF0D5BDEDD0B7FFFEFEFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1DFDFDFEAEAEAEDEDEDECECECE7
            E7E7D2D2D2CDCDCDFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFCEAD9FADDC2F6D6B9F4D3B5F3D4B8F5E0CDFFFFFEFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E8E8D9D9D9D2D2D2CFCFCFD1
            D1D1DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          NumGlyphs = 2
          OnClick = sbSearchClick
        end
        object lSearchResults: TLabel
          Left = 0
          Top = 24
          Width = 6
          Height = 13
          Caption = '0'
        end
        object eSearchQuery: TEdit
          Left = 0
          Top = 2
          Width = 185
          Height = 21
          TabOrder = 0
          OnKeyPress = eSearchQueryKeyPress
        end
      end
    end
  end
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 844
    Height = 29
    AutoSize = True
    Bands = <
      item
        Control = ToolBar1
        ImageIndex = -1
        Width = 843
      end>
    object ToolBar1: TToolBar
      Left = 11
      Top = 0
      Width = 829
      Height = 25
      Caption = 'ToolBar1'
      DisabledImages = ilNavToolbar_Off
      Images = ilNavToolbar_On
      TabOrder = 0
      object tbPrevious: TToolButton
        Left = 0
        Top = 0
        Caption = 'tbPrevious'
        Enabled = False
        ImageIndex = 1
        OnClick = tbPreviousClick
      end
      object tbNext: TToolButton
        Left = 23
        Top = 0
        Caption = 'tbNext'
        Enabled = False
        ImageIndex = 0
        OnClick = tbNextClick
      end
      object ToolButton4: TToolButton
        Left = 46
        Top = 0
        Width = 5
        Caption = 'ToolButton4'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object tbHelp: TToolButton
        Left = 51
        Top = 0
        Caption = 'tbHelp'
        ImageIndex = 2
        OnClick = tbHelpClick
      end
    end
  end
  object wbHelp: TWebBrowser
    Left = 220
    Top = 29
    Width = 624
    Height = 538
    Align = alClient
    TabOrder = 2
    OnCommandStateChange = wbHelpCommandStateChange
    ControlData = {
      4C0000007E4000009B3700000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object ilNavToolbar_On: TImageList
    Left = 122
    Top = 4
    Bitmap = {
      494C010103000400700010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000130020001410300025104000251040001430300013302000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000130020001410300025104000251040001430300013302000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000007675740076767500767675000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000145
      03000145030003780800039C0B00039F0C00039F0C00039D0C00027E0900014D
      0400014D04000000000000000000000000000000000000000000000000000145
      03000145030003780800039C0B00039F0C00039F0C00039D0C00027E0900014D
      0400014D04000000000000000000000000000000000000000000000000000000
      000078767600ABAAAA00E5E5E500C5C5C40076767500767675006D6D6C000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000034F09000365
      090004A30D0003A60C0003A00B00029E0A00039F0C0003A00C0003A50C0003A6
      0C00026906000134020000000000000000000000000000000000034F09000365
      090004A30D0003A60C0003A00B00029E0A00039F0C0003A00C0003A50C0003A6
      0C00026906000134020000000000000000000000000000000000000000007F7E
      7D00B4B4B400FFFFFF00F8F8F800E7E7E700E3E6E700B5A09E007B524D00755B
      5800767675007676750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000044F0900066B11000AAB
      1F0007A41500049E0D00029D0A00039D0A00039E0C00039E0C00039E0C0003A0
      0C0003A70C00026A0600024C04000000000000000000044F0900066B11000AAB
      1F0007A41500049E0D00029D0A00039D0A00039E0C00039E0C00039E0C0003A0
      0C0003A70C00026A0600024C040000000000000000000000000081807F00C4C2
      C200FFFFFF00FFFFFF00FAFAFA00EBEBEB00E9EDED00BAA5A3007E4D47007E4A
      4500AB999800B0B1B200767675005E5E5D000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000044F090010AC30000DAB
      280009A41C00039E0F0016AA2000D5F2D800E9F8EA0048C05200039E0C00039E
      0C00039F0C0003A70C00024C04000000000000000000044F090010AC30000DAB
      280009A41C00039E0F0048C05200E9F8EA00D5F2D80016AA2000039E0C00039E
      0C00039F0C0003A70C00024C0400000000000000000086848300D7D7D700FFFF
      FF00FFFFFF00FFFFFF00FCFCFC00F3F3F300F0F4F400BFAAA9007E4D48007D4B
      4600B19F9E00CACCCC00B2B2B2005C5C5B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000035706000D82230017B641000EA9
      2D0005A01300049F0D0007A0110082D58900FFFFFF00F4FCF60040BC4A00039E
      0C00039E0C0003A50C00037B080001420300035706000D82230017B641000EA9
      2D0005A0130041BD4B00F4FCF600FFFFFF0082D5890007A01000039E0C00039E
      0C00039E0C0003A50C00037B0800014203000000000086848300FCFCFC00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FBFBFB00FAFEFE00C4AFAD007E4D48007D4A
      4500B6A4A300CFD0D000B4B4B2005C5C5B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000357060017A3410018B54A0011AB
      340006A01100039E0C00049F0D00039E0C0074D07D00FCFEFC00F3FBF4003EBC
      4800039E0C0003A10C0003960A00014203000357060017A3410018B54A0011AB
      340041BD4E00F3FBF400FCFEFC0075D07D00039E0C00039E0C00039E0C00039E
      0C00039E0C0003A10C0003960A00014203000000000086848300FEFEFE00FFFF
      FF00B8B1B1008F7F7F00D4D0D000FFFFFF00FFFFFF00C5AFAD0077443F007744
      4000BAA9A700D8D9D900BABABA005B5C5B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000006680D0021B151001EB75100BFED
      CF00BAEAC600B7E9C200B8EAC500B5E9C200B7E9C100F6FCF700FFFFFF00EEFA
      EF0054C55E0003A00C00039F0C00014A040006680D0021B151001EB7510070D3
      9200F0FBF300FFFFFF00F7FCF800B7E9C500B4E7BD00ADE5B200ADE5B200AFE5
      B400B1E6B60003A00C00039F0C00014A04000000000086848300E7E7E9007E6E
      6E00633B3B006B3B3B0053393900CCC9C900FFFFFF00EEE7E600C2ACAA00A380
      7D00C7BAB700DEE0E000C6C7C700565050000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000087412003EBD69002ABA5C00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FCFEFC00FFFFFF00FFFF
      FF00AAE3B00003A00C00039F0C0002520500087412003EBD69002ABA5C00BAEA
      CC00FFFFFF00FFFFFF00FCFFFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0003A00C00039F0C00025205000000000086848300594141008A54
      5400EA969600DA8686007B45450053393900CEC9C900FFFFFF00FFFFFF00F4F6
      F600E9E9E900EEEFEF00A59E9E00503838000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000006780E0054C57A0044C6740052C7
      7D0057CA810056CA800057CA810049C5730079D59200FAFEFA00FFFFFF0097DD
      A5001AAD330007A51800039D0C000146030006780E0054C57A0044C674002CBA
      5C00A4E3BC00FFFFFF00FAFEFB0082D9A0003EBF5E0041C05B0041BF5B0041BF
      580041BF570007A51800039D0C00014603000000000066464600C7868700F8A9
      A900EB989800E78E8E00D0797A007B44440050373700CEC9C900FFFFFF00FCFC
      FC00FFFFFF00B2ABAB00442C2C00724747000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000006780E004CBD690083DDA70022B6
      55001CB24E0022B5540022B5540055CA7F00E1F6E900FFFFFF0088D99D0010AB
      2F000CA6270006A71600038C0A000146030006780E004CBD690083DDA70022B6
      55001DB24F0095DEB000FFFFFF00E2F7EA004FC6750011AB34000FAA30000FAA
      2E000CA6270006A71600038C0A0001460300000000007A4D4D00FFBFBF00F0A3
      A300EA979700E38B8B00E2828300CC7070007841410050383800D0CBCB00FFFF
      FF00A1979700462D2D0072464600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000013992300AAE7C50068D0
      8E0016AF48001BB14C0039BF6800F4FCF700FFFFFF0084D99E0011AA32000EA7
      29000BA4200009AF1C00036B0A00000000000000000013992300AAE7C50068D0
      8E0016AF48001CB14D008EDCAB00FFFFFF00F4FCF7002DB8530010A931000EA7
      29000BA4200009AF1C00036B0A0000000000000000007A4D4D00DA979700F6A7
      A700EA979700E38B8B00DD808100D9767600C466660078414100564040007060
      6000442828007548480000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000001399230056C57300C5F0
      D80066CF8C0020B4520023B55400AAE6C00096DEB10019B1480013AC3C0012AA
      34000FB02D000A991F00036B0A0000000000000000001399230056C57300C5F0
      D80066CF8C0020B452001CB24F0095DEB000ABE6C1001FB44E0013AC3C0012AA
      34000FB02D000A991F00036B0A000000000000000000000000007A4D4D00E096
      9600F09A9A00E38B8B00DC808100DE828300FFBDBD00C15C5C007A4040004829
      2900774A4A000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000139923006ACC
      8800D0F4E3009AE1B60050C77A0038BD67002CBA5D0030BB60002FBC5D0023BC
      4F0011A3300006620F0000000000000000000000000000000000139923006ACC
      8800D0F4E3009AE1B60050C77A0038BD67002CBA5D0030BB60002FBC5D0023BC
      4F0011A3300006620F0000000000000000000000000000000000000000007A4D
      4D00DC8C8C00E98E8E00DE828300E9969600FFBDBD00DA6A6B007A4D4D000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001399
      23001399230098E1B500BDEED400A7E7C40090E0B10078D99F0049C779001B9D
      3D001B9D3D000000000000000000000000000000000000000000000000001399
      23001399230098E1B500BDEED400A7E7C40090E0B10078D99F0049C779001B9D
      3D001B9D3D000000000000000000000000000000000000000000000000000000
      00007A4D4D00E98E8E00E28486007A4D4D007A4D4D00DA6A6B007A4D4D000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000001DA4350013992300139923001399230013992300138C2A000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000001DA4350013992300139923001399230013992300138C2A000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000007A4D4D007A4D4D00000000007A4D4D007A4D4D00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00F81FF81FF8FF0000E007E007F01F0000
      C003C003E003000080018001C000000080018001800000000000000080000000
      0000000080000000000000008000000000000000800000000000000080000000
      0000000080010000800180018003000080018001C0070000C003C003E01F0000
      E007E007F01F0000F81FF81FF93F000000000000000000000000000000000000
      000000000000}
  end
  object ilNavToolbar_Off: TImageList
    Left = 162
    Top = 4
    Bitmap = {
      494C010103000400700010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000747474007B7B7B0081818100818181007B7B7B00757575000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000747474007B7B7B0081818100818181007B7B7B00757575000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000A1A1A100AFAFAF00AFAFAF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007C7C
      7C007C7C7C008E8E8E009A9A9A009B9B9B009B9B9B009A9A9A00909090007F7F
      7F007F7F7F000000000000000000000000000000000000000000000000007C7C
      7C007C7C7C008E8E8E009A9A9A009B9B9B009B9B9B009A9A9A00909090007F7F
      7F007F7F7F000000000000000000000000000000000000000000000000000000
      0000A3A3A300BCBCBC00EBEBEB00D1D1D100AFAFAF00AFAFAF00AFAFAF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000828282008989
      89009C9C9C009D9D9D009B9B9B009A9A9A009B9B9B009B9B9B009C9C9C009D9D
      9D00898989007575750000000000000000000000000000000000828282008989
      89009C9C9C009D9D9D009B9B9B009A9A9A009B9B9B009B9B9B009C9C9C009D9D
      9D0089898900757575000000000000000000000000000000000000000000A9A9
      A900C4C4C400FFFFFF00FAFAFA00EDEDED00EEEEEE00A9A9A900A2A2A200B5B5
      B5009A9A9A00AFAFAF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000828282008D8D8D00A3A3
      A3009F9F9F009B9B9B009A9A9A009A9A9A009A9A9A009A9A9A009A9A9A009B9B
      9B009D9D9D00898989007F7F7F000000000000000000828282008D8D8D00A3A3
      A3009F9F9F009B9B9B009A9A9A009A9A9A009A9A9A009A9A9A009A9A9A009B9B
      9B009D9D9D00898989007F7F7F00000000000000000000000000ABABAB00D0D0
      D000FFFFFF00FFFFFF00FBFBFB00F0F0F000F2F2F200ADADAD009B9B9B009B9B
      9B00A3A3A300C4C4C400AFAFAF008B8B8B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000082828200A7A7A700A5A5
      A500A0A0A0009B9B9B00A9A9A900FDFDFD00FFFFFF00C4C4C4009A9A9A009A9A
      9A009B9B9B009D9D9D007F7F7F00000000000000000082828200A7A7A700A5A5
      A500A0A0A0009B9B9B00C4C4C400FFFFFF00FDFDFD00A9A9A9009A9A9A009A9A
      9A009B9B9B009D9D9D007F7F7F000000000000000000AFAFAF00E0E0E000FFFF
      FF00FFFFFF00FFFFFF00FDFDFD00F6F6F600F8F8F800B2B2B2009B9B9B009A9A
      9A00A9A9A900D8D8D800C3C3C300898989000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008484840098989800ADADAD00A5A5
      A5009D9D9D009C9C9C009E9E9E00DDDDDD00FFFFFF00FFFFFF00C0C0C0009A9A
      9A009A9A9A009C9C9C00909090007B7B7B008484840098989800ADADAD00A5A5
      A5009D9D9D00C0C0C000FFFFFF00FFFFFF00DDDDDD009E9E9E009A9A9A009A9A
      9A009A9A9A009C9C9C00909090007B7B7B0000000000AFAFAF00FDFDFD00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FCFCFC00FDFDFD00B6B6B6009B9B9B009A9A
      9A00AEAEAE00DCDCDC00C3C3C300898989000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000084848400A8A8A800ADADAD00A7A7
      A7009D9D9D009B9B9B009C9C9C009B9B9B00D7D7D700FFFFFF00FFFFFF00BFBF
      BF009A9A9A009C9C9C00989898007B7B7B0084848400A8A8A800ADADAD00A7A7
      A700C1C1C100FFFFFF00FFFFFF00D7D7D7009A9A9A009A9A9A009A9A9A009A9A
      9A009A9A9A009C9C9C00989898007B7B7B0000000000AFAFAF00FEFEFE00FFFF
      FF00BFBFBF00AAAAAA00D9D9D900FFFFFF00FFFFFF00B5B5B500989898009898
      9800B0B0B000E3E3E300C8C8C800898989000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008C8C8C00B0B0B000B1B1B100F6F6
      F600F3F3F300F2F2F200F3F3F300F1F1F100F2F2F200FFFFFF00FFFFFF00FFFF
      FF00C9C9C9009B9B9B009B9B9B007E7E7E008C8C8C00B0B0B000B1B1B100D7D7
      D700FFFFFF00FFFFFF00FFFFFF00F2F2F200F1F1F100EFEFEF00EFEFEF00EFEF
      EF00F0F0F0009B9B9B009B9B9B007E7E7E0000000000AFAFAF00ECECEC00C1C1
      C10093939300969696009C9C9C00D2D2D200FFFFFF00E9E9E900C6C6C6009898
      9800C0C0C000E7E7E700D4D4D400898989000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000091919100C0C0C000B6B6B600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00EDEDED009C9C9C009B9B9B008181810091919100C0C0C000B6B6B600F3F3
      F300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF009C9C9C009B9B9B008181810000000000AFAFAF00A5A5A5009F9F
      9F00B5B5B500B2B2B2009E9E9E009B9B9B00D3D3D300FFFFFF00FFFFFF00F8F8
      F800EEEEEE00F0F0F000CFCFCF00989898000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000091919100C9C9C900C4C4C400C9C9
      C900CCCCCC00CBCBCB00CCCCCC00C6C6C600DADADA00FFFFFF00FFFFFF00E5E5
      E500ACACAC009F9F9F009A9A9A007D7D7D0091919100C9C9C900C4C4C400B7B7
      B700EBEBEB00FFFFFF00FFFFFF00DEDEDE00C0C0C000C2C2C200C1C1C100C1C1
      C100C1C1C1009F9F9F009A9A9A007D7D7D00000000009B9B9B00ACACAC00B7B7
      B700B4B4B400B3B3B300AFAFAF009C9C9C0098989800D2D2D200FFFFFF00FDFD
      FD00FFFFFF00CBCBCB00939393008F8F8F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000091919100C4C4C400E0E0E000B2B2
      B200AEAEAE00B1B1B100B1B1B100CBCBCB00FFFFFF00FFFFFF00E0E0E000A6A6
      A600A3A3A300A0A0A000959595007D7D7D0091919100C4C4C400E0E0E000B2B2
      B200AFAFAF00E5E5E500FFFFFF00FFFFFF00C8C8C800A7A7A700A6A6A600A6A6
      A600A3A3A300A0A0A000959595007D7D7D0000000000A0A0A000B8B8B800B5B5
      B500B4B4B400B2B2B200B1B1B100AEAEAE009B9B9B0099999900D5D5D500FFFF
      FF00A8A8A8008B8B8B0095959500000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000A3A3A300EEEEEE00D3D3
      D300AAAAAA00ADADAD00BEBEBE00FFFFFF00FFFFFF00DFDFDF00A7A7A700A4A4
      A400A1A1A100A3A3A3008B8B8B000000000000000000A3A3A300EEEEEE00D3D3
      D300AAAAAA00AEAEAE00E3E3E300FFFFFF00FFFFFF00B7B7B700A6A6A600A4A4
      A400A1A1A100A3A3A3008B8B8B000000000000000000A0A0A000B0B0B000B6B6
      B600B4B4B400B2B2B200B0B0B000AFAFAF00ACACAC009C9C9C009F9F9F00B0B0
      B000878787009A9A9A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000A3A3A300CACACA00F8F8
      F800D2D2D200B1B1B100B2B2B200EEEEEE00E5E5E500ADADAD00A8A8A800A7A7
      A700A8A8A8009E9E9E008B8B8B000000000000000000A3A3A300CACACA00F8F8
      F800D2D2D200B1B1B100AFAFAF00E5E5E500EEEEEE00B0B0B000A8A8A800A7A7
      A700A8A8A8009E9E9E008B8B8B000000000000000000000000009F9F9F00B3B3
      B300B4B4B400B2B2B200B1B1B100B9B9B900CECECE00ABABAB009C9C9C008D8D
      8D009B9B9B000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A3A3A300D3D3
      D300FDFDFD00E8E8E800C9C9C900BDBDBD00B7B7B700B9B9B900B9B9B900B4B4
      B400A4A4A4008989890000000000000000000000000000000000A3A3A300D3D3
      D300FDFDFD00E8E8E800C9C9C900BDBDBD00B7B7B700B9B9B900B9B9B900B4B4
      B400A4A4A400898989000000000000000000000000000000000000000000A3A3
      A300B1B1B100B3B3B300B2B2B200CDCDCD00CECECE00ACACAC00A1A1A1000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A3A3
      A300A3A3A300E7E7E700F6F6F600EDEDED00E4E4E400DBDBDB00C7C7C700A8A8
      A800A8A8A800000000000000000000000000000000000000000000000000A3A3
      A300A3A3A300E7E7E700F6F6F600EDEDED00E4E4E400DBDBDB00C7C7C700A8A8
      A800A8A8A8000000000000000000000000000000000000000000000000000000
      0000A2A2A200B0B0B000B4B4B400A2A2A200ADADAD00A8A8A800A2A2A2000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000AAAAAA00A3A3A300A3A3A300A3A3A300A3A3A3009F9F9F000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000AAAAAA00A3A3A300A3A3A300A3A3A300A3A3A3009F9F9F000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000A2A2A200A2A2A20000000000A2A2A200A2A2A200000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00F81FF81FF8FF0000E007E007F01F0000
      C003C003E003000080018001C000000080018001800000000000000080000000
      0000000080000000000000008000000000000000800000000000000080000000
      0000000080010000800180018003000080018001C0070000C003C003E01F0000
      E007E007F01F0000F81FF81FF93F000000000000000000000000000000000000
      000000000000}
  end
end
