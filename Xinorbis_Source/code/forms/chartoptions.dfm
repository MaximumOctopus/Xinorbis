object frmChartOptions: TfrmChartOptions
  Left = 545
  Top = 358
  BorderStyle = bsDialog
  ClientHeight = 335
  ClientWidth = 862
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
  object Bevel2: TBevel
    Left = 463
    Top = 8
    Width = 394
    Height = 289
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 486
    Top = 13
    Width = 3
    Height = 13
    Caption = '.'
  end
  object Label2: TLabel
    Left = 486
    Top = 69
    Width = 3
    Height = 13
    Caption = '.'
  end
  object lZoom: TLabel
    Left = 818
    Top = 38
    Width = 3
    Height = 13
    Caption = '.'
  end
  object lExplodeBiggest: TLabel
    Left = 818
    Top = 96
    Width = 3
    Height = 13
    Caption = '.'
  end
  object Label3: TLabel
    Left = 510
    Top = 176
    Width = 3
    Height = 13
    Caption = '.'
  end
  object sLabelColour: TShape
    Left = 510
    Top = 192
    Width = 49
    Height = 18
    Cursor = crHandPoint
    OnMouseDown = sLabelColourMouseDown
  end
  object lTitleColour: TLabel
    Left = 487
    Top = 260
    Width = 52
    Height = 13
    Caption = 'Title colour'
  end
  object sTitleColour: TShape
    Left = 566
    Top = 256
    Width = 49
    Height = 21
    Cursor = crHandPoint
    OnMouseDown = sTitleColourMouseDown
  end
  object bSave: TBitBtn
    Left = 663
    Top = 303
    Width = 105
    Height = 25
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000C21E0000C21E00000000000000000000D8AB8ECD9570
      BD7342B76835B56835B46734B26634B06533AE6433AC6332AA6232A96132A860
      31A76132AB693CBC8661C37D4FEBC6ADEAC5ADFEFBF8FEFBF8FEFBF8FEFBF8FE
      FBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8C89A7CC79879AD6B40BA6C38EDCAB3
      E0A27AFEFAF762C08862C08862C08862C08862C08862C08862C08862C088FDF9
      F6CA8D65C99B7CA76132BB6C38EECCB6E1A27AFEFAF7BFDCC2BFDCC2BFDCC2BF
      DCC2BFDCC2BFDCC2BFDCC2BFDCC2FDF9F6CD9068CC9E81A86132BB6B38EFCEB8
      E1A279FEFAF762C08862C08862C08862C08862C08862C08862C08862C088FDF9
      F6CF936ACEA384AA6132BA6A36EFD0BBE2A27AFEFBF8FEFBF8FEFBF8FEFBF8FE
      FBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8D3966DD2A78AAB6232BB6A36F0D2BE
      E2A37AE2A37AE1A37AE2A37BE1A37BE0A178DE9F77DD9F76DC9D74D99B72D899
      71D69970D5AB8EAD6333BB6A36F2D5C2E3A37AE3A37AE2A37BE2A37BE2A47BE1
      A279E0A178DEA077DE9E75DC9D74DA9B73D99B73DAB095AF6433BB6A36F2D8C5
      E3A47BE3A37AE3A47AE2A47BE2A37BE1A37BE1A279DFA077DE9F76DD9E74DB9C
      72DC9D74DDB59AB16534BB6B36F4D9C7E6A67DC88C64C98D65C98E67CB926CCB
      926DCA9069C88C65C88C64C88C64C88C64DA9C74E1BA9FB36634BB6C37F4DCC9
      E7A77DF9ECE1F9ECE1F9EDE3FCF4EEFDFAF7FDF7F3FAEDE5F7E7DBF7E5D9F6E5
      D8DEA077E4BEA4B46734BD6E3AF5DDCCE7A87EFAF0E8FAF0E8C98D66FAF0E9FD
      F8F3FEFAF8FCF4EFF9E9DFF7E7DBF7E5D9E0A278E7C2A9B66835C07442F6DFD0
      E8A87EFCF6F1FCF6F1C88C64FAF1E9FBF4EEFDFAF7FDF9F6FAF0E8F8E8DDF7E6
      DBE1A37AEFD5C3B76A36C68255F6DFD1E9AA80FEFAF6FDFAF6C88C64FBF3EEFB
      F1EAFCF6F2FEFBF8FCF6F1F9ECE2F8E7DBEED0BAECD0BDBD7443D6A585F6E0D1
      F7E0D1FEFBF8FEFBF7FDF9F6FCF5F0FAF0EAFBF2EDFDF9F6FDFAF7FBF1EBF8E9
      DFECD1BECD926AE2C5B1E1BDA6D9AB8DC9895EC07543BD6E3ABB6C37BB6B36BB
      6A36BB6A36BC6C39BD6E3BBB6D3ABF7444C98D65E7CEBCFFFFFF}
    ModalResult = 1
    TabOrder = 0
  end
  object bCancel: TBitBtn
    Left = 774
    Top = 303
    Width = 83
    Height = 25
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
    TabOrder = 1
  end
  object bSaveAll: TBitBtn
    Left = 552
    Top = 303
    Width = 105
    Height = 25
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCA8A61C38458D3
      8B68E18F70DC8D6CDA8B6DD78A6ECD8B6CAB6D44A65F2EFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFC68355EFCEBADDFFFF87EEC7A2F4D7A2F6D78CEEC7E0FF
      FFDDA285AB6A3EFFFFFFFFFFFFFFFFFFFFFFFFD09975CB946EC37F51EFB69AEA
      F3E851BF846FC99871C99954BF84E4F4E9DD9C7BAA693AFFFFFFFFFFFFFFFFFF
      FFFFFFCD936BF1D4C3C48154EAB697F3F3EAEDF1E6EFF1E6EFF0E6EDF1E5F3F5
      EDD59C79B07044FFFFFFFFFFFFD5A383D09E7BC78358EEB499C98B61E6B592E2
      A781E1A781DEA37DDCA17BDB9F79D99E77D49A73BB7E57FFFFFFFFFFFFD29D79
      F2D8C9C9916AE1BE9FCA8D65EAB899DDA57EDDA680DBA37CD9A07AD9A079D89F
      78D89E78BF845DFFFFFFFFFFFFD09A76F2C5AFCD9973D7B894C8885DEFBFA1FD
      FCFAFEFCFBFEFDFDFEFDFCFDFBFAFDFCFBDDA885C17F53FFFFFFFFFFFFD09C78
      EEC5ADCF9B77EBC0A4C7865BEFC09EFFFFFFCC936EFFFFFFFFFFFFFFFBF7FFF8
      F1E4AF8CC78A61FFFFFFFFFFFFD4A482EBC5A9CC8E65EEBEA1CC8D65F3CDB0FF
      FFFFE3C7B3FFFFFFFFFFFFFFFFFFFFFFFFEABFA1C98960FFFFFFFFFFFFD5A586
      EEC7AFCA8C63EDBF9ED4976ED49E7BD09871D6A482CD8E68CD9069D09A75D199
      73C88B62EEDCD0FFFFFFFFFFFFD4A17FF2CDB5D29C79F4D3BAFFFFFFE7CEBDFF
      FFFEFFFFFFFBF6F2F8F1EDEDC7ADD09875FFFFFFFFFFFFFFFFFFFFFFFFD3A07E
      F2CDB3DAA581D4A07ED6A683DBB092D39D7BD39E7BD39F7BD19A75CF9A76F0E1
      D6FFFFFFFFFFFFFFFFFFFFFFFFD7A586F6D8C1FFFFFFE9D3C3FFFFFFFFFFFFFF
      FFFFFFFFFFEECDB5D4A282FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDAD8D
      DDB397DAAE8FDFB79CD8A688D8A889DAAF92DBAF91D4A483F1E3D9FFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    ModalResult = 8
    TabOrder = 2
  end
  object vtcOptions: TChart
    Tag = 2
    Left = 8
    Top = 8
    Width = 449
    Height = 289
    AllowPanning = pmNone
    BackWall.Brush.Style = bsClear
    BackWall.Pen.Visible = False
    Gradient.Direction = gdBottomTop
    Gradient.EndColor = 15719898
    Gradient.Visible = True
    LeftWall.Color = clGray
    Legend.Alignment = laLeft
    Legend.TextStyle = ltsPlain
    MarginBottom = 0
    MarginLeft = 1
    MarginRight = 1
    MarginTop = 0
    Title.Font.Style = [fsItalic]
    Title.Text.Strings = (
      'xinorbis')
    AxisVisible = False
    ClipPoints = False
    Frame.Visible = False
    View3DOptions.Elevation = 315
    View3DOptions.Orthogonal = False
    View3DOptions.Perspective = 0
    View3DOptions.Rotation = 360
    View3DWalls = False
    Zoom.Allow = False
    BevelOuter = bvLowered
    TabOrder = 3
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TPieSeries
      Marks.BackColor = clWhite
      Marks.Color = clWhite
      XValues.Order = loAscending
      YValues.Name = 'Pie'
      YValues.Order = loNone
      Frame.InnerBrush.BackColor = clRed
      Frame.InnerBrush.Gradient.EndColor = clGray
      Frame.InnerBrush.Gradient.MidColor = clWhite
      Frame.InnerBrush.Gradient.StartColor = 4210752
      Frame.InnerBrush.Gradient.Visible = True
      Frame.MiddleBrush.BackColor = clYellow
      Frame.MiddleBrush.Gradient.EndColor = 8553090
      Frame.MiddleBrush.Gradient.MidColor = clWhite
      Frame.MiddleBrush.Gradient.StartColor = clGray
      Frame.MiddleBrush.Gradient.Visible = True
      Frame.OuterBrush.BackColor = clGreen
      Frame.OuterBrush.Gradient.EndColor = 4210752
      Frame.OuterBrush.Gradient.MidColor = clWhite
      Frame.OuterBrush.Gradient.StartColor = clSilver
      Frame.OuterBrush.Gradient.Visible = True
      Frame.Width = 4
      Gradient.Balance = 10
      Gradient.Direction = gdDiagonalUp
      Gradient.EndColor = 919731
      Gradient.StartColor = 919731
      Gradient.Visible = True
      OtherSlice.Legend.Visible = False
      OtherSlice.Text = 'Other'
      PiePen.Visible = False
    end
  end
  object tbZoom: TTrackBar
    Left = 479
    Top = 32
    Width = 338
    Height = 25
    Max = 150
    TabOrder = 4
    OnChange = tbZoomChange
  end
  object tbExplodeBiggest: TTrackBar
    Left = 479
    Top = 88
    Width = 338
    Height = 25
    Max = 150
    TabOrder = 5
    OnChange = tbExplodeBiggestChange
  end
  object bHelp: TBitBtn
    Left = 8
    Top = 303
    Width = 107
    Height = 25
    Glyph.Data = {
      36030000424D3603000000000000360000002800000010000000100000000100
      18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4ECE5D6BAA2B6845AAC
      7445AB7243B27E53D2B59CF2EAE3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFE7D5C6BA895FD7BBA3E9DACAECE0D1ECE0D1E8D8C8D3B59CB07A4DE2CF
      BEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAD9CBBE8C62E7D5C4E5D2BFC9A685B8
      8E67B68A65C5A180E0CCBAE3D0BEAF7648E3D0C0FFFFFFFFFFFFFFFFFFF7F1EC
      C99D79EAD8C9E3CDBAC0946BBA8C62CFB094CFB094B7895FB28761DAC0AAE4D1
      C0B68359F4ECE6FFFFFFFFFFFFE6CFBCE4CCB9EAD6C5C79971BF9066BF9066F7
      F1ECF6F0EAB7895FB7895FB58963E2CEBBD9BDA6D9BEA7FFFFFFFFFFFFD9B395
      EFE1D3D9B595C7986CC39569C19367BF9066BF9066BB8B63B98A63B88A62CBA7
      86EADCCCC2956FFFFFFFFFFFFFDAB393F2E4D9D1A57AC5996BC4976AC49669FA
      F6F2F3EAE1C2956DBE8F65BE8F64C0956DEFE3D5C19067FFFFFFFFFFFFE1BB9D
      F2E5DAD1A67ECC9D71C79A6CC5986BE2CCB6F8F3EEF6EEE8D9BDA1C29468C59B
      71F0E2D6C79971FFFFFFFFFFFFEACAB0F3E5D9DFBB9ECFA075CD9E72F5EBE3E4
      CBB4E7D3BFFBF8F6E5D3BFC4986BD6B491EEE0D2D3AC8BFFFFFFFFFFFFF5E4D6
      F4E3D4EFDCCDD5A87ED0A077FBF8F5FCF8F5FCF8F5FBF8F5D1A881CFA47BEAD5
      C3EAD4C2E9D4C2FFFFFFFFFFFFFDF9F5F1D3BBF6E9DDECD8C6D7AC81DCBB9AF6
      ECE3F5ECE2E4C8AED2A77BE6CEBAF1E2D5DFBB9CFAF4F0FFFFFFFFFFFFFFFFFF
      FBF1E9F3D4BBF7EADFEEDED0E3C1A7D8AE89D7AC86DDBB9CEBD6C7F3E6D9E4C1
      A3F5E9DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF2EAF6DAC3F9E9DCF6E8DDF3
      E5DAF3E5DAF5E7DCF5E4D6EDCDB4F8ECE3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFEFAF7FCEDE1F8DEC9F6D9C1F5D7BFF5D9C3F8E8DCFDF8F5FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    TabOrder = 6
    OnClick = bHelpClick
  end
  object cbShowLegend: TAdvOfficeCheckBox
    Left = 488
    Top = 127
    Width = 232
    Height = 20
    TabOrder = 7
    OnClick = cbShowLegendClick
    Alignment = taLeftJustify
    Caption = 'Legend'
    ReturnIsTab = False
    Version = '1.4.1.1'
  end
  object cbShowLabels: TAdvOfficeCheckBox
    Left = 488
    Top = 153
    Width = 120
    Height = 20
    TabOrder = 8
    OnClick = cbShowLabelsClick
    Alignment = taLeftJustify
    Caption = '.'
    ReturnIsTab = False
    Version = '1.4.1.1'
  end
  object cbLabelOptions: TComboBox
    Left = 565
    Top = 216
    Width = 154
    Height = 21
    Style = csDropDownList
    TabOrder = 9
  end
  object cbMarksType: TComboBox
    Left = 566
    Top = 189
    Width = 154
    Height = 21
    Style = csDropDownList
    TabOrder = 10
  end
  object cdMain: TColorDialog
    Left = 128
    Top = 304
  end
end
