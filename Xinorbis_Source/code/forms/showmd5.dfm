object frmMD5: TfrmMD5
  Left = 546
  Top = 244
  BorderStyle = bsDialog
  Caption = 'MD5 Checksum'
  ClientHeight = 119
  ClientWidth = 375
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 56
    Width = 26
    Height = 13
    Caption = 'MD5:'
  end
  object lMD5: TLabel
    Left = 40
    Top = 56
    Width = 9
    Height = 13
    Caption = '...'
  end
  object Bevel1: TBevel
    Left = 8
    Top = 78
    Width = 363
    Height = 4
    Shape = bsTopLine
  end
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 375
    Height = 38
    Align = alTop
    Pen.Color = clWhite
  end
  object lFilename: TLabel
    Left = 8
    Top = 13
    Width = 3
    Height = 13
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object bCancel: TBitBtn
    Left = 288
    Top = 88
    Width = 83
    Height = 25
    Cancel = True
    TabOrder = 0
    OnClick = bCancelClick
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
  end
  object bCopy: TBitBtn
    Left = 200
    Top = 88
    Width = 83
    Height = 25
    TabOrder = 1
    OnClick = bCopyClick
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFD39570CC8357C87646CA7B4ECB7B4ECA7B4ECA7B
      4ECA7B4ECA8155CD865CBED2E14A80AB206398206398206398206398C98F67FC
      F3ECFAF1E8FAF0E7FBF1E9FBF2EAFBF2EAFBF2EBFDF4EECB83585588B174ADD8
      7BB2DD78AEDC75AADA74A9DADAA97DEFF1E7FFE9D9FFEADBFFE9D9FFE7D7FFE5
      D2FFE2CBEFF2E8CE815620639880B9E15395D15092D04E8ECE4D8CCDD6A97DFB
      F5EEFFE9D9FFEADBFFE9D9FFE7D7FFE5D2FFE2CBFBF6EFCC835620639884BFE2
      569AD35397D15092CF5091CFD6A97DFFF7F1FFE9D9FFEADBFFE9D9FFE7D7FFE5
      D2FFE2CBFFF7F1CB855620639888C4E6599FD6569BD35397D15395D1D7AC7FFF
      F7F0FFE7D5FDE7D6FDE6D4FCE4D0FBE3CBFADCC2FEF3E8CC86572063988BC9E7
      5CA5D759A0D5579CD3569AD3D7AC7FFFF7F2FEE7D5FEE7D5FDE5D1FAE0CAF9DE
      C4F7D9BCFDF2E7CC875820639891CDE95FA9D95DA5D85AA0D6599FD6D8AD81FE
      F7F1FCE5D2FCE4D1FBE2CCF9DDC4F6D7BBF3D1AFFAEFE4CC875920639898D2EB
      65AEDA60AAD95DA6D85CA5D7D9AF84FEF6F0FCE2CDFCE3CDFADFC8F7D9BCF5E9
      DDFAF3EBFBF8F3CA83542063989ED6ED6BB2DC66AFDC60AADA5FA9D9D9AF84FE
      F5EDFCDEC5FBE0C7F9DCC2F5D3B4FEF9F3FAE2C4ECC193D2986E206398A5DAEF
      6FB5DE68B0DC60A9D95FA9D9D7AD81FFFFFEFDF3E9FDF3EAFCF2E8FAEFE3FAF2
      E7EABB88D39469FBF8F6206398AADDF174B9E070B6DF6CB3DD6BB2DCD9AF84D7
      AE81D7AC7FD7AC7FCCA070CD9F71B38F67D39B71FCFAF8FFFFFF206398B0E1F2
      79BDE24498DD4497DC4396DC4296DC4295DC4195DB539ED489C6E6206398FFFF
      FFFFFFFFFFFFFFFFFFFF3B76A595C9E0AEE2F24E9DDFB5EEFD75D4F075D4F0B5
      EEFD4B9BDE8ECBE993CDE92A6A9DFFFFFFFFFFFFFFFFFFFFFFFFD3E0EB6392B7
      2063983775A4B6EFFE80DBF380DBF3B6EFFE2E6EA12063986F9ABCB6CCDDFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDAE5EE20639820639820639820639820
      63982D6C9EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
  end
end
