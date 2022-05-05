object frmUserWizard: TfrmUserWizard
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 444
  ClientWidth = 608
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pSize: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 6
    object Label5: TLabel
      Left = 24
      Top = 24
      Width = 60
      Height = 19
      Caption = 'Include'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object gbSize1: TAdvGlowButton
      Left = 120
      Top = 89
      Width = 377
      Height = 33
      Caption = '0 - 1MB'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 0
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbSize2: TAdvGlowButton
      Tag = 1
      Left = 120
      Top = 128
      Width = 377
      Height = 33
      Caption = '1MB to 10MB'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 1
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbSize3: TAdvGlowButton
      Tag = 2
      Left = 120
      Top = 167
      Width = 377
      Height = 33
      Caption = '10MB to 50MB'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 2
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbSize4: TAdvGlowButton
      Tag = 3
      Left = 120
      Top = 206
      Width = 377
      Height = 33
      Caption = '50MB to 100MB'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 3
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbSize5: TAdvGlowButton
      Tag = 4
      Left = 120
      Top = 245
      Width = 377
      Height = 33
      Caption = '100MB to 1GB'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 4
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbSize6: TAdvGlowButton
      Tag = 5
      Left = 120
      Top = 284
      Width = 377
      Height = 33
      Caption = '1GB and above'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 5
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
  end
  object pPopular: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 7
    object Label6: TLabel
      Left = 24
      Top = 24
      Width = 60
      Height = 19
      Caption = 'Include'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object gbPCreated: TAdvGlowButton
      Left = 120
      Top = 89
      Width = 123
      Height = 33
      Caption = 'Created'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 0
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      Down = True
      GroupIndex = 1
    end
    object gbPAccessed: TAdvGlowButton
      Tag = 1
      Left = 247
      Top = 89
      Width = 123
      Height = 33
      Caption = 'Accessed'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 1
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbPYesterday: TAdvGlowButton
      Tag = 1
      Left = 120
      Top = 182
      Width = 377
      Height = 33
      Caption = 'Yesterday'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 2
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 2
    end
    object gbPThisWeek: TAdvGlowButton
      Tag = 2
      Left = 120
      Top = 221
      Width = 377
      Height = 33
      Caption = 'This Week'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 3
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 2
    end
    object gbPModified: TAdvGlowButton
      Tag = 1
      Left = 374
      Top = 89
      Width = 123
      Height = 33
      Caption = 'Modified'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 4
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object AdvGlowButton1: TAdvGlowButton
      Tag = 3
      Left = 120
      Top = 260
      Width = 377
      Height = 33
      Caption = 'This Month'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 5
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 2
    end
    object AdvGlowButton2: TAdvGlowButton
      Left = 120
      Top = 143
      Width = 377
      Height = 33
      Caption = 'Today'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 6
      OnClick = gbSize1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 2
    end
  end
  object pEnd: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 3
    DesignSize = (
      603
      371)
    object Label4: TLabel
      Left = 24
      Top = 24
      Width = 72
      Height = 19
      Caption = 'Finished!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SpeedButton1: TSpeedButton
      Left = 272
      Top = 217
      Width = 62
      Height = 22
      Anchors = [akTop, akRight]
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF3B8D3F25
        7A292577293B853FFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF318F3542A05287CA9A9BD3AB9BD2AB83C7963D974C307C34FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF258F2A6DBE83A8DBB587CC9866
        BC7D64BA7C86CB98A5D9B466B77D247227FF00FFFF00FFFF00FFFF00FFFF00FF
        33A14472C287A8DBB260BC775CBA7359B87059B56F58B56F5BB774A5D9B369B8
        7F317F35FF00FFFF00FFFF00FFFF00FF4CB064AADDB464C1795FBE7175C585D4
        ECD98ACD9956B66C58B56E5CB774A6DAB4419B4EFF00FFFF00FFFF00FF3FB55D
        91D29F8DD49A64C37479C987F2FAF4FFFFFFFDFEFD86CB9657B76D5BB97285CC
        9787C79A3B8B3FFF00FFFF00FF27B049A6DCAF70CA7F73CA80F0F9F1FFFFFFEB
        F7EDFFFFFFFBFDFC88CD965BB97167BE7DA0D7AF237F26FF00FFFF00FF2EB751
        A7DDB172CC8066C773B0E1B7D2EED663C170B8E3BFFFFFFFFBFDFC8CD09969C1
        7EA1D7AE238426FF00FFFF00FF4BC56C95D7A191D79B69C97664C66F61C46E61
        C36F61C26FB9E4C0FFFFFFE3F4E68BD1998BCE9D3C993FFF00FFFF00FFFF00FF
        57BF70AFE1B76DCC7A68C87265C77063C56E62C46E63C471B6E3BE6FC77EACDF
        B548A95EFF00FFFF00FFFF00FFFF00FF49C5667FCE90AEE1B56DCC7A6ACA7668
        C87268C87468C8756BC979ACDFB476C48933A142FF00FFFF00FFFF00FFFF00FF
        FF00FF3DC35C7FCE90AFE1B792D89D77CE8377CE8392D89DAEE1B578C88B27A1
        3BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF4AC86959C27496D7A3A5
        DCAEA5DCAE95D6A150B96A35B355FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF55CB723BC05C37BE5A49C36AFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      OnClick = sbOkClick
    end
    object SpeedButton2: TSpeedButton
      Left = 228
      Top = 127
      Width = 74
      Height = 22
      Anchors = [akTop, akRight]
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF7AB580FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFAAAAAAFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF6DB67453A45BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA7A7A7939393FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        7BC58471BE7B7AC1835BAA6447994F4191493B884235803B2F78352A702F2569
        292163241D5E20FF00FFFF00FFFF00FFB7B7B7AEAEAEB2B2B29A9A9A89898982
        82827979797272726A6A6A6262625C5C5C575757525252FF00FFFF00FF89D192
        7BC8869CD5A598D3A194D09D90CE988BCB9387C98E82C6897EC3847AC18076BE
        7C72BD78216324FF00FFFF00FFC3C3C3B8B8B8C9C9C9C6C6C6C3C3C3C1C1C1BD
        BDBDBBBBBBB7B7B7B4B4B4B1B1B1AEAEAEADADAD575757FF00FFFF00FF88D391
        7FCC8AA2D8AB9ED6A79AD4A396D29F93CF9A8ECC9589CA9085C78B81C5877DC2
        8278C07E256929FF00FFFF00FFC4C4C4BCBCBCCDCDCDCACACAC8C8C8C5C5C5C2
        C2C2BEBEBEBCBCBCB8B8B8B6B6B6B3B3B3B0B0B05C5C5CFF00FFFF00FFFF00FF
        83D18D80CD8B7CC9875DB86858B16253A95C4DA15647994F4191493B88423580
        3B2F78352A702FFF00FFFF00FFFF00FFC2C2C2BDBDBDB9B9B9A6A6A69F9F9F98
        98989090908989898282827979797272726A6A6A626262FF00FFFF00FFFF00FF
        FF00FF7DCF886AC575FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBFBFBFB3B3B3FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF90D699FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC8C8C8FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbPreviousClick
    end
    object SpeedButton3: TSpeedButton
      Left = 308
      Top = 127
      Width = 74
      Height = 22
      Anchors = [akTop, akRight]
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF5F8E61FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FF868686FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF2C6E30427A
        45FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FF616161707070FF00FFFF00FFFF00FFFF00FF61BE6D
        5DB86858B16253A95C4DA15647994F4191493B884235803B3F884559A15E448B
        494B804DFF00FFFF00FFFF00FFACACACA6A6A69F9F9F98989890909089898982
        82827979797272727A7A7A9292927C7C7C777777FF00FFFF00FFFF00FF65C371
        A0D7A99CD5A598D3A194D09D90CE988BCB9387C98E82C6897EC3847AC18076BE
        7C458C4A548757FF00FFFF00FFB1B1B1CBCBCBC9C9C9C6C6C6C3C3C3C1C1C1BD
        BDBDBBBBBBB7B7B7B4B4B4B1B1B1AEAEAE7D7D7D7E7E7EFF00FFFF00FF68C774
        A5DAAEA2D8AB9ED6A79AD4A396D29F93CF9A8ECC9589CA9085C78B81C5877DC2
        824A9150538956FF00FFFF00FFB4B4B4CFCFCFCDCDCDCACACAC8C8C8C5C5C5C2
        C2C2BEBEBEBCBCBCB8B8B8B6B6B6B3B3B38282827F7F7FFF00FFFF00FF68C774
        68C77465C37161BE6D5DB86858B16253A95C4DA15647994F4191495AA362559D
        5C559059FF00FFFF00FFFF00FFB4B4B4B4B4B4B1B1B1ACACACA6A6A69F9F9F98
        98989090908989898282829494948E8E8E858585FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF47944F5799
        5DFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FF8686868C8C8CFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF78B47EFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFA8A8A8FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbNextClick
    end
    object Label9: TLabel
      Left = 149
      Top = 108
      Width = 312
      Height = 13
      Caption = 'Change your options using the next and previous buttons below:'
    end
    object Label10: TLabel
      Left = 170
      Top = 187
      Width = 252
      Height = 13
      Caption = 'Or, keep your settings and click the "accept" button.'
    end
  end
  object pProductivity: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 5
    object Label2: TLabel
      Left = 24
      Top = 24
      Width = 60
      Height = 19
      Caption = 'Include'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object gbProductivity1: TAdvGlowButton
      Tag = 2
      Left = 120
      Top = 89
      Width = 377
      Height = 33
      Caption = 'Office documents'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 0
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbProductivity2: TAdvGlowButton
      Tag = 2
      Left = 120
      Top = 128
      Width = 377
      Height = 33
      Caption = 'Programming'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 1
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbProductivity3: TAdvGlowButton
      Tag = 2
      Left = 120
      Top = 167
      Width = 377
      Height = 33
      Caption = 'Compressed'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 2
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
  end
  object pMultimedia: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 4
    object Label3: TLabel
      Left = 24
      Top = 24
      Width = 60
      Height = 19
      Caption = 'Include'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object gbMultimedia1: TAdvGlowButton
      Tag = 1
      Left = 120
      Top = 89
      Width = 377
      Height = 33
      Caption = 'Pictures'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 0
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbMultimedia2: TAdvGlowButton
      Tag = 1
      Left = 120
      Top = 128
      Width = 377
      Height = 33
      Caption = 'Video'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 1
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 2
    end
    object gbMultimedia3: TAdvGlowButton
      Tag = 1
      Left = 120
      Top = 167
      Width = 377
      Height = 33
      Caption = 'Music and Audio'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 2
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 3
    end
  end
  object pCompressed: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 9
    object Label7: TLabel
      Left = 24
      Top = 24
      Width = 60
      Height = 19
      Caption = 'Include'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object gbCompressed: TAdvGlowButton
      Tag = 3
      Left = 120
      Top = 89
      Width = 377
      Height = 33
      Caption = 'All compressed files'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 0
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
  end
  object pSystem: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 8
    object Label8: TLabel
      Left = 24
      Top = 24
      Width = 60
      Height = 19
      Caption = 'Include'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object gbSystem1: TAdvGlowButton
      Tag = 4
      Left = 120
      Top = 89
      Width = 377
      Height = 33
      Caption = 'Programs'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 0
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbSystem2: TAdvGlowButton
      Tag = 4
      Left = 120
      Top = 128
      Width = 377
      Height = 33
      Caption = 'System files'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 1
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object gbSystem3: TAdvGlowButton
      Tag = 4
      Left = 120
      Top = 167
      Width = 377
      Height = 33
      Caption = 'All'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 2
      OnClick = MultipleSelectionClick
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
  end
  object pTitle: TPanel
    Left = 1
    Top = 37
    Width = 603
    Height = 371
    TabOrder = 2
    object Label1: TLabel
      Left = 24
      Top = 24
      Width = 227
      Height = 19
      Caption = 'What are you interested in?'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object AdvGlowButton4: TAdvGlowButton
      Tag = 10
      Left = 112
      Top = 260
      Width = 377
      Height = 33
      Caption = 'Popular Files'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 0
      OnClick = AdvGlowButton1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object AdvGlowButton5: TAdvGlowButton
      Tag = 20
      Left = 112
      Top = 299
      Width = 377
      Height = 33
      Caption = 'File Sizes (big or small)'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 1
      OnClick = AdvGlowButton1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object AdvGlowButton6: TAdvGlowButton
      Tag = 1
      Left = 112
      Top = 89
      Width = 377
      Height = 33
      Caption = 'Multimedia files (pictures, music and video)'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 2
      OnClick = AdvGlowButton1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object AdvGlowButton7: TAdvGlowButton
      Tag = 2
      Left = 112
      Top = 128
      Width = 377
      Height = 33
      Caption = 'Productivity files (documents, spreadsheets, code)'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 3
      OnClick = AdvGlowButton1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object AdvGlowButton3: TAdvGlowButton
      Tag = 3
      Left = 112
      Top = 167
      Width = 377
      Height = 33
      Caption = 'Compressed files'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 4
      OnClick = AdvGlowButton1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
    object AdvGlowButton8: TAdvGlowButton
      Tag = 4
      Left = 112
      Top = 206
      Width = 377
      Height = 33
      Caption = 'System files'
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      TabOrder = 5
      OnClick = AdvGlowButton1Click
      Appearance.ColorChecked = 16111818
      Appearance.ColorCheckedTo = 16367008
      Appearance.ColorDisabled = 15921906
      Appearance.ColorDisabledTo = 15921906
      Appearance.ColorDown = 16111818
      Appearance.ColorDownTo = 16367008
      Appearance.ColorHot = 16117985
      Appearance.ColorHotTo = 16372402
      Appearance.ColorMirrorHot = 16107693
      Appearance.ColorMirrorHotTo = 16775412
      Appearance.ColorMirrorDown = 16102556
      Appearance.ColorMirrorDownTo = 16768988
      Appearance.ColorMirrorChecked = 16102556
      Appearance.ColorMirrorCheckedTo = 16768988
      Appearance.ColorMirrorDisabled = 11974326
      Appearance.ColorMirrorDisabledTo = 15921906
      GroupIndex = 1
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 608
    Height = 35
    Align = alTop
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 411
    Width = 608
    Height = 33
    Align = alBottom
    Color = clWhite
    ParentBackground = False
    TabOrder = 1
    DesignSize = (
      608
      33)
    object sbOk: TSpeedButton
      Left = 448
      Top = 4
      Width = 80
      Height = 22
      Anchors = [akTop, akRight]
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF3B8D3F257A292577293B853FFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7F7F7F6A
        6A6A686868787878FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF318F3542A05287CA9A9BD3AB9BD2AB83C7963D974C307C34FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7F7F7F8F8F8FBEBEBEC9
        C9C9C8C8C8BABABA8686866F6F6FFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF258F2A6DBE83A8DBB587CC9866BC7D64BA7C86CB98A5D9B466B77D2472
        27FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF7D7D7DAFAFAFD1D1D1BFBFBFAD
        ADADABABABBEBEBECFCFCFA9A9A9656565FF00FFFF00FFFF00FFFF00FFFF00FF
        33A14472C287A8DBB260BC775CBA7359B87059B56F58B56F5BB774A5D9B369B8
        7F317F35FF00FFFF00FFFF00FFFF00FF909090B3B3B3D0D0D0ABABABA9A9A9A7
        A7A7A4A4A4A4A4A4A7A7A7CFCFCFAAAAAA727272FF00FFFF00FFFF00FFFF00FF
        4CB064AADDB464C1795FBE7175C585D4ECD98ACD9956B66C58B56E5CB774A6DA
        B4419B4EFF00FFFF00FFFF00FFFF00FF9F9F9FD2D2D2B0B0B0ACACACB5B5B5E7
        E7E7C0C0C0A5A5A5A4A4A4A7A7A7D0D0D08A8A8AFF00FFFF00FFFF00FF3FB55D
        91D29F8DD49A64C37479C987F2FAF4FFFFFFFDFEFD86CB9657B76D5BB97285CC
        9787C79A3B8B3FFF00FFFF00FFA3A3A3C5C5C5C6C6C6B1B1B1B9B9B9F9F9F9FF
        FFFFFEFEFEBEBEBEA6A6A6A8A8A8BFBFBFBBBBBB7D7D7DFF00FFFF00FF27B049
        A6DCAF70CA7F73CA80F0F9F1FFFFFFEBF7EDFFFFFFFBFDFC88CD965BB97167BE
        7DA0D7AF237F26FF00FFFF00FF9C9C9CD1D1D1B8B8B8B8B8B8F7F7F7FFFFFFF5
        F5F5FFFFFFFDFDFDBFBFBFA8A8A8AEAEAECDCDCD6E6E6EFF00FFFF00FF2EB751
        A7DDB172CC8066C773B0E1B7D2EED663C170B8E3BFFFFFFFFBFDFC8CD09969C1
        7EA1D7AE238426FF00FFFF00FFA2A2A2D2D2D2BABABAB4B4B4D6D6D6E7E7E7AF
        AFAFDADADAFFFFFFFDFDFDC2C2C2B1B1B1CCCCCC737373FF00FFFF00FF4BC56C
        95D7A191D79B69C97664C66F61C46E61C36F61C26FB9E4C0FFFFFFE3F4E68BD1
        998BCE9D3C993FFF00FFFF00FFB2B2B2C9C9C9C8C8C8B6B6B6B3B3B3B1B1B1B0
        B0B0AFAFAFDBDBDBFFFFFFF0F0F0C3C3C3C2C2C2898989FF00FFFF00FFFF00FF
        57BF70AFE1B76DCC7A68C87265C77063C56E62C46E63C471B6E3BE6FC77EACDF
        B548A95EFF00FFFF00FFFF00FFFF00FFADADADD6D6D6B9B9B9B5B5B5B4B4B4B2
        B2B2B1B1B1B1B1B1D9D9D9B6B6B6D4D4D4989898FF00FFFF00FFFF00FFFF00FF
        49C5667FCE90AEE1B56DCC7A6ACA7668C87268C87468C8756BC979ACDFB476C4
        8933A142FF00FFFF00FFFF00FFFF00FFB1B1B1BFBFBFD6D6D6B9B9B9B7B7B7B5
        B5B5B5B5B5B5B5B5B7B7B7D4D4D4B5B5B58F8F8FFF00FFFF00FFFF00FFFF00FF
        FF00FF3DC35C7FCE90AFE1B792D89D77CE8377CE8392D89DAEE1B578C88B27A1
        3BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFAEAEAEBFBFBFD6D6D6CACACABC
        BCBCBCBCBCCACACAD6D6D6B9B9B98E8E8EFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF4AC86959C27496D7A3A5DCAEA5DCAE95D6A150B96A35B355FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB4B4B4B0B0B0CACACAD0
        D0D0D0D0D0C9C9C9A6A6A6A0A0A0FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF55CB723BC05C37BE5A49C36AFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFB8B8B8AB
        ABABA9A9A9B0B0B0FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbOkClick
    end
    object SpeedButton9: TSpeedButton
      Left = 528
      Top = 4
      Width = 76
      Height = 22
      Anchors = [akTop, akRight]
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF546BC73F59C03A53BF4C67C2FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8888887B
        7B7B777777848484FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF5566CC3C52CC757AE88F92EE8F92EE7178E4334DC1405CBEFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8787877B7B7B9C9C9CAD
        ADADADADAD9999997373737C7C7CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF5160CD5C65E0A1A6F57E86EF5B63E9595DE77D84EE9EA0F4515DD73452
        BAFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF8484848D8D8DBBBBBBA5A5A590
        90908C8C8CA4A4A4B7B7B7858585747474FF00FFFF00FFFF00FFFF00FFFF00FF
        6571D4616BE3A1ACF5545FEC505CEA4D59E94E59E64C56E65056E69EA2F45460
        D6405CBFFF00FFFF00FFFF00FFFF00FF919191919191BFBFBF8F8F8F8D8D8D8B
        8B8B8A8A8A888888888888B8B8B88686867D7D7DFF00FFFF00FFFF00FFFF00FF
        4B56DBA2ABF65664F05266EE4D59E94D59E94D59E94D59E94C58E6525AE69FA3
        F53450C4FF00FFFF00FFFF00FFFF00FF838383BFBFBF9393939393938B8B8B8B
        8B8B8B8B8B8B8B8B8989898A8A8AB9B9B9767676FF00FFFF00FFFF00FF7378DD
        818CEE7E91F75D73F34D59E94D59E94D59E94D59E94D59E94D59E94F5BE97B83
        F0757BE24C64C4FF00FFFF00FF999999A8A8A8AEAEAE9B9B9B8B8B8B8B8B8B8B
        8B8B8B8B8B8B8B8B8B8B8B8C8C8CA4A4A49A9A9A848484FF00FFFF00FF6569DB
        A1ABF77086F86882F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D59E95C66
        EA969CF13956BEFF00FFFF00FF8E8E8EBFBFBFA8A8A8A5A5A5FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF8B8B8B919191B3B3B3787878FF00FFFF00FF696EDC
        AFB9F97F93FA7085F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4D59E95E6A
        EE969DF13D55C0FF00FFFF00FF919191CACACAB0B0B0A4A4A4FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF8B8B8B959595B4B4B4787878FF00FFFF00FF7C7FE3
        A5AFF59DABFA778CF0545FEC545FEC545FEC545FEC545FEC545FEC6377F2818E
        F4787FE9566BC9FF00FFFF00FF9F9F9FC2C2C2C0C0C0A8A8A88F8F8F8F8F8F8F
        8F8F8F8F8F8F8F8F8F8F8F9D9D9DACACAC9F9F9F898989FF00FFFF00FFFF00FF
        7D83EACDD4FC8B9DFA7E93F7758AEE6C84F66C84F66C84F66C84F66379F3A4AF
        F83E4FD0FF00FFFF00FFFF00FFFF00FFA2A2A2DEDEDEB7B7B7AFAFAFA6A6A6A6
        A6A6A6A6A6A6A6A6A6A6A69F9F9FC2C2C27B7B7BFF00FFFF00FFFF00FFFF00FF
        7978E3A3A7F3D4DBFD879AFA7F91F07A8EF17F94F87E92F9768CF8A8B6F8636E
        E35868CDFF00FFFF00FFFF00FFFF00FF9B9B9BBBBBBBE3E3E3B5B5B5ACACACAA
        AAAAB0B0B0AFAFAFABABABC7C7C7939393888888FF00FFFF00FFFF00FFFF00FF
        FF00FF706FE1AAADF2D8DCFDAEBAFA91A3FA8B9DFA9CA9FBBAC7FC707BE95462
        CEFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF959595BFBFBFE4E4E4CACACABB
        BBBBB7B7B7BFBFBFD4D4D49C9C9C858585FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF7979E28E93EDBEC3F8CCD3F9C4CBF9AAB4F46670E2646ED6FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9B9B9BADADADD0D0D0DC
        DCDCD7D7D7C5C5C59393938F8F8FFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FF7D7FE26A6BDE686BDC7479DEFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF9F9F9F90
        90909090909A9A9AFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = SpeedButton9Click
    end
    object sbPrevious: TSpeedButton
      Left = 179
      Top = 4
      Width = 116
      Height = 22
      Anchors = [akTop, akRight]
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF7AB580FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFAAAAAAFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FF6DB67453A45BFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFA7A7A7939393FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        7BC58471BE7B7AC1835BAA6447994F4191493B884235803B2F78352A702F2569
        292163241D5E20FF00FFFF00FFFF00FFB7B7B7AEAEAEB2B2B29A9A9A89898982
        82827979797272726A6A6A6262625C5C5C575757525252FF00FFFF00FF89D192
        7BC8869CD5A598D3A194D09D90CE988BCB9387C98E82C6897EC3847AC18076BE
        7C72BD78216324FF00FFFF00FFC3C3C3B8B8B8C9C9C9C6C6C6C3C3C3C1C1C1BD
        BDBDBBBBBBB7B7B7B4B4B4B1B1B1AEAEAEADADAD575757FF00FFFF00FF88D391
        7FCC8AA2D8AB9ED6A79AD4A396D29F93CF9A8ECC9589CA9085C78B81C5877DC2
        8278C07E256929FF00FFFF00FFC4C4C4BCBCBCCDCDCDCACACAC8C8C8C5C5C5C2
        C2C2BEBEBEBCBCBCB8B8B8B6B6B6B3B3B3B0B0B05C5C5CFF00FFFF00FFFF00FF
        83D18D80CD8B7CC9875DB86858B16253A95C4DA15647994F4191493B88423580
        3B2F78352A702FFF00FFFF00FFFF00FFC2C2C2BDBDBDB9B9B9A6A6A69F9F9F98
        98989090908989898282827979797272726A6A6A626262FF00FFFF00FFFF00FF
        FF00FF7DCF886AC575FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFBFBFBFB3B3B3FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FF90D699FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC8C8C8FF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbPreviousClick
    end
    object sbNext: TSpeedButton
      Left = 309
      Top = 4
      Width = 116
      Height = 22
      Anchors = [akTop, akRight]
      Enabled = False
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF5F8E61FF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FF868686FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF2C6E30427A
        45FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FF616161707070FF00FFFF00FFFF00FFFF00FF61BE6D
        5DB86858B16253A95C4DA15647994F4191493B884235803B3F884559A15E448B
        494B804DFF00FFFF00FFFF00FFACACACA6A6A69F9F9F98989890909089898982
        82827979797272727A7A7A9292927C7C7C777777FF00FFFF00FFFF00FF65C371
        A0D7A99CD5A598D3A194D09D90CE988BCB9387C98E82C6897EC3847AC18076BE
        7C458C4A548757FF00FFFF00FFB1B1B1CBCBCBC9C9C9C6C6C6C3C3C3C1C1C1BD
        BDBDBBBBBBB7B7B7B4B4B4B1B1B1AEAEAE7D7D7D7E7E7EFF00FFFF00FF68C774
        A5DAAEA2D8AB9ED6A79AD4A396D29F93CF9A8ECC9589CA9085C78B81C5877DC2
        824A9150538956FF00FFFF00FFB4B4B4CFCFCFCDCDCDCACACAC8C8C8C5C5C5C2
        C2C2BEBEBEBCBCBCB8B8B8B6B6B6B3B3B38282827F7F7FFF00FFFF00FF68C774
        68C77465C37161BE6D5DB86858B16253A95C4DA15647994F4191495AA362559D
        5C559059FF00FFFF00FFFF00FFB4B4B4B4B4B4B1B1B1ACACACA6A6A69F9F9F98
        98989090908989898282829494948E8E8E858585FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF47944F5799
        5DFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FF8686868C8C8CFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF78B47EFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFA8A8A8FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      NumGlyphs = 2
      OnClick = sbNextClick
      ExplicitLeft = 306
    end
    object sbSearch: TSpeedButton
      Left = 1
      Top = 4
      Width = 23
      Height = 22
      Hint = 'help'
      Anchors = [akTop, akRight]
      Flat = True
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
      OnClick = sbSearchClick
    end
  end
end
