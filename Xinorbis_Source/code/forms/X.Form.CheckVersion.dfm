object frmCheckVersion: TfrmCheckVersion
  Left = 615
  Top = 395
  BorderStyle = bsDialog
  Caption = 'Xinorbis 8'
  ClientHeight = 213
  ClientWidth = 496
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 496
    Height = 38
    Align = alTop
    Brush.Color = 3355443
    Pen.Color = 3355443
  end
  object lTitle: TLabel
    Left = 8
    Top = 7
    Width = 5
    Height = 24
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object BitBtn1: TBitBtn
    Left = 400
    Top = 182
    Width = 88
    Height = 25
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
    TabOrder = 0
  end
  object bHistory: TBitBtn
    Left = 199
    Top = 182
    Width = 89
    Height = 25
    Enabled = False
    TabOrder = 1
    OnClick = bHistoryClick
  end
  object mHistory: TMemo
    Left = 8
    Top = 272
    Width = 481
    Height = 217
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object bDownload: TBitBtn
    Left = 7
    Top = 182
    Width = 89
    Height = 25
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
      FF00FF9C9C9C7E7E7E7979797474747070708A8A8AFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9C9C9C7E7E7E79797974747470
      70708A8A8AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FF929292D5D3D3E2E0DFDFDCDBE1DFDF767676FF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF929292D3D3D3E0E0E0DCDCDCDF
      DFDF767676FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFCFCFCFA9A9A9C4C2C1D4CFCE808080ACACAC9191917474747070706B6B
      6B676767636363797979FF00FFFF00FFFF00FFCFCFCFA9A9A9C2C2C2CFCFCF80
      8080ACACAC9191917474747070706B6B6B676767636363797979CECECEB5B5B5
      B0B0B0ACACAC9F9F9F9E9E9E9A9A9A858585848484878786878685A2A09FD3CE
      CDD3CECDE8E5E5646464CECECEB5B5B5B0B0B0ACACAC9F9F9F9E9E9E9A9A9A85
      8585848484878787868686A0A0A0CECECECECECEE5E5E5646464AEAEAEE4E2E2
      D7D5D5D5D3D2D1CECDCAC4C3C8C3C2CDC9C8CCCACACCCAC9D8D6D6747373B9B1
      AEB7AFAED3CECD686868AEAEAEE2E2E2D5D5D5D3D3D3CECECEC4C4C4C3C3C3C9
      C9C9CACACACACACAD6D6D6737373B1B1B1B0B0B0CECECE686868B4B4B4E0DDDD
      A7724DA7724DA7724DA7724DA7724DA7724DA7724DA7724DDAD5D4787878BAB2
      B1B9B1AFD4CFCE6D6D6DB4B4B4DDDDDD70707070707070707070707070707070
      7070707070707070D5D5D5787878B3B3B3B1B1B1CFCFCF6D6D6DBABABADEDBDB
      B5805ACE9870D8AE91D9AF91D9AF91DAAF91D6A077A7724DD7D3D17E7E7EBBB4
      B3BBB3B1D4D0CF737373BABABADBDBDB7D7D7D959595ABABABACACACACACACAC
      ACAC9C9C9C707070D3D3D37E7E7EB5B5B5B3B3B3D0D0D0737373C0C0C0DFDCDC
      B47F59CB956ECD976FCF9971D19B72D29C74D49E75A7724DD7D4D38484843BA1
      42379437D6D1D0787878C0C0C0DCDCDC7C7C7C92929294949496969697979799
      99999A9A9A707070D4D4D48484848E8E8E828282D1D1D1787878C5C5C5E1DEDC
      B37D58C7916BC9936DCB956ECD9770CF9971D19B73A7724DD9D5D48B8B8BA0C8
      A450A956D7D3D17E7E7EC5C5C5DEDEDE7B7B7B8E8E8E90909092929294949496
      9696989898707070D5D5D58B8B8BBEBEBE979797D3D3D37E7E7ECACACAE1DFDE
      B17C57C48E68C6906AC8926BCA946DCC966FCE9870A7724DDBD6D6919191C1BB
      B9C0B9B8D7D3D3848484CACACADFDFDF7979798B8B8B8D8D8D8F8F8F91919193
      9393959595707070D6D6D6919191BBBBBBB9B9B9D3D3D3848484CECECEE2DFDF
      B07B56B17B56B17C57B27D58B37E58B47F59B5805AA7724DDCD8D79898988D8D
      8D8A8A8AD9D5D48B8B8BCECECEDFDFDF7878787979797979797A7A7A7B7B7B7C
      7C7C7D7D7D707070D8D8D89898988D8D8D8A8A8AD5D5D58B8B8BD3D3D3F1EFEF
      E2DFDFE2DFDFE1DFDEE1DEDDE0DDDCDFDCDBDEDBDBDEDBD9EDECEB9E9E9EC5BF
      BEC3BDBBDAD6D5919191D3D3D3EFEFEFDFDFDFDFDFDFDFDFDFDEDEDEDDDDDDDC
      DCDCDBDBDBDBDBDBECECEC9E9E9EBFBFBFBDBDBDD6D6D6919191D7D7D7D3D3D3
      D0D0D0CCCCCCC8C8C8C3C3C3BFBFBFBABABAB5B5B5B0B0B0AAAAAAA5A5A59493
      93929191DBD7D6989898D7D7D7D3D3D3D0D0D0CCCCCCC8C8C8C3C3C3BFBFBFBA
      BABAB5B5B5B0B0B0AAAAAAA5A5A5939393919191D7D7D7989898FF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFD1D1D1DFDFDFEAEAEACFCAC9CBC6C5CAC4C3C8C3
      C1C7C1C1DCD9D89E9E9EFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFD1D1D1DF
      DFDFEAEAEACACACAC6C6C6C4C4C4C3C3C3C2C2C2D9D9D99E9E9EFF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFDDDDDDDCDCDCE6E3E3E1DEDCDFDCDCDFDC
      DBDEDBDBEEECECA5A5A5FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFDD
      DDDDDCDCDCE3E3E3DEDEDEDCDCDCDCDCDCDBDBDBECECECA5A5A5FF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFE0E0E0CACACAC4C4C4C0C0C0BBBB
      BBB6B6B6B0B0B0C8C8C8FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
      00FFE0E0E0CACACAC4C4C4C0C0C0BBBBBBB6B6B6B0B0B0C8C8C8}
    NumGlyphs = 2
    TabOrder = 3
    OnClick = bDownloadClick
  end
  object bWebsite: TBitBtn
    Left = 104
    Top = 182
    Width = 89
    Height = 25
    Glyph.Data = {
      36060000424D3606000000000000360000002800000020000000100000000100
      18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
      FF00FFFF00FFFF00FF6DA46F478B49377F3A377F3A438746659C67FF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9797977C7C7C71
      7171717171797979909090FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FF75AF793D8C429BC59DB3C29DBDC19CBEC39DB0D2B17EC09A317C34639B
      65FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA2A2A27C7C7CBBBBBBBABABABA
      BABABBBBBBC9C9C9B5B5B56D6D6D8F8F8FFF00FFFF00FFFF00FFFF00FFFF00FF
      67AD6D70B786AEE8C7C0D2A0C5B381CAB47DCCAF78B9A77880CC95A0DABC66A8
      7A4D8D50FF00FFFF00FFFF00FFFF00FF9E9E9EAAAAAADEDEDEC7C7C7ABABABAB
      ABABA7A7A7A0A0A0BEBEBED1D1D19C9C9C7F7F7FFF00FFFF00FFFF00FF84C38A
      76C08D99D7B379C080BCC27EC6A96AD7B169D6AD65BC9B5E60AD6A59976881C1
      9967A97B639B65FF00FFFF00FFB5B5B5B3B3B3CDCDCDB1B1B1B6B6B6A0A0A0A7
      A7A7A4A4A49393939E9E9E8B8B8BB6B6B69D9D9D8F8F8FFF00FFFF00FF56B060
      B5EAD369BC746EBD71BEB66DC9A35BDFAB5BDDA858C1924E9DA95878B1665A96
      67A6DCC0307B33FF00FFFF00FF9E9E9EE3E3E3ABABABACACACAAAAAA9A9A9AA2
      A2A29F9F9F8A8A8A9B9B9BA1A1A18A8A8AD4D4D46C6C6CFF00FF8CCF9492D7AF
      A0DEB484C670A8D080C5A55CD0A757E0AA56DAA651C7984AB98C47B69B57819F
      6579BF9081BE9C639B65C0C0C0CCCCCCD3D3D3B4B4B4C0C0C09B9B9B9D9D9DA1
      A1A19D9D9D8F8F8F848484919191939393B3B3B3B4B4B48F8F8F6FC67AB0E9CF
      83D490BFDC8AC3CB82CCA256DAAF5CDCAF5BC99A4BBF8643B78443B99A5296A5
      6265A676A2D8BD428644B5B5B5E1E1E1C3C3C3CCCCCCBDBDBD999999A4A4A4A5
      A5A59191918080807E7E7E9090909999999A9A9AD0D0D078787866C572BEEFDD
      73D17D90D16CBCE09EC7A75ED3B05EC69953C6BC6EAFD17AB4C46DAFA95F7BA9
      575AA367B1E3CE37823BB2B2B2E9E9E9BEBEBEBDBDBDD1D1D19D9D9DA5A5A591
      9191AFAFAFC0C0C0B5B5B59D9D9D999999959595DDDDDD73737367C674BEF0DC
      81D88377DB6DBFE59ACCDFA7CAA85DC2BD6CB8DA8BA6D86077D13F6AD04659BC
      5063AB6CB2E4CE3C8640B4B4B4E9E9E9C5C5C5C4C4C4D5D5D5D3D3D39E9E9EB0
      B0B0CACACAC3C3C3B8B8B8B7B7B7A7A7A79C9C9CDDDDDD77777773CB7EB3ECD2
      9BE2A29DEA8DD4EDB7D0EAC7CFB96ECCB166CBC97576DB6766D94D65D74D6CD3
      5D73BB7EA5DBC24C9451B9B9B9E4E4E4D3D3D3D6D6D6E1E1E1E2E2E2AEAEAEA7
      A7A7BBBBBBC4C4C4BFBFBFBEBEBEBCBCBCACACACD3D3D385858594D79D98DEB5
      B5EBCCB1EFA7C9EEA9D1EAC9D5CF8DD9CB8BCDB466BCBC679AD67182DE737ADC
      7191D0A388C8A472AE77C9C9C9D2D2D2E2E2E2DEDEDEDFDFDFE2E2E2C3C3C3C1
      C1C1A9A9A9AEAEAEC2C2C2C8C8C8C6C6C6C4C4C4BDBDBDA1A1A1FF00FF64C571
      C0F3E2B5EFB4B5F0ACC1EDB7D4E3B7D9D89CDAD395CDB56DC7B36DB5CB8494DF
      9AAFE7CD489C4FFF00FFFF00FFB2B2B2EDEDEDE1E1E1E0E0E0E0E0E0DADADACD
      CDCDC8C8C8ABABABA8A8A8BDBDBDCECECEDFDFDF8B8B8BFF00FFFF00FF99D9A1
      87D7A0C0F2DEC7F2D6D5EFD5D0E9CFD5DBA6DCDEABDBCD90D7C88BC9C18EBDD5
      AF7AC7917EBD84FF00FFFF00FFCBCBCBC9C9C9EBEBEBEAEAEAE8E8E8E2E2E2D1
      D1D1D4D4D4C3C3C3BEBEBEB8B8B8CCCCCCB9B9B9AFAFAFFF00FFFF00FFFF00FF
      86D2908CD8A2CDF5E8D4EDDACEEDD3CFDFAFD6DEB5D4D4A2CED0A1C4D0AA87C9
      9172BD7AFF00FFFF00FFFF00FFFF00FFC2C2C2CACACAF0F0F0E8E8E8E6E6E6D5
      D5D5D6D6D6CACACAC7C7C7C8C8C8BBBBBBADADADFF00FFFF00FFFF00FFFF00FF
      FF00FF99D9A265C672A5E1BBBAEACCC5E0BEC5DAB4BDD7B0A6D7AC60BF6B89CE
      92FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFCBCBCBB3B3B3D6D6D6E1E1E1D8
      D8D8D1D1D1CECECECCCCCCACACACBFBFBFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FF96D89E75CB8068C77465C6726FC97B91D69AFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFCACACAB9B9B9B4
      B4B4B3B3B3B7B7B7C7C7C7FF00FFFF00FFFF00FFFF00FFFF00FF}
    NumGlyphs = 2
    TabOrder = 4
    OnClick = bWebsiteClick
  end
  object gbInstalled: TGroupBox
    Left = 8
    Top = 48
    Width = 233
    Height = 81
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    object lDate1: TLabel
      Left = 24
      Top = 24
      Width = 3
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4063255
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lVersion1: TLabel
      Left = 24
      Top = 40
      Width = 3
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4063255
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lIVDate: TLabel
      Left = 80
      Top = 24
      Width = 25
      Height = 13
      Caption = '......'
    end
    object lIVVersion: TLabel
      Left = 80
      Top = 40
      Width = 25
      Height = 13
      Caption = '......'
    end
  end
  object gbOnline: TGroupBox
    Left = 256
    Top = 48
    Width = 233
    Height = 81
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    object lDate2: TLabel
      Left = 24
      Top = 24
      Width = 3
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4063255
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lVersion2: TLabel
      Left = 24
      Top = 40
      Width = 3
      Height = 13
      Caption = '.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4063255
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lLADate: TLabel
      Left = 80
      Top = 24
      Width = 25
      Height = 13
      Caption = '......'
    end
    object lLAVersion: TLabel
      Left = 80
      Top = 40
      Width = 25
      Height = 13
      Caption = '......'
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 135
    Width = 481
    Height = 41
    TabOrder = 7
    object lWhat: TLabel
      Left = 21
      Top = 15
      Width = 12
      Height = 13
      Caption = '....'
    end
  end
  object httpMain: TIdHTTP
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html, */*'
    Request.BasicAuthentication = False
    Request.UserAgent = 
      'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gec' +
      'ko) Chrome/28.0.1468.0 Safari/537.36'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 440
    Top = 8
  end
end