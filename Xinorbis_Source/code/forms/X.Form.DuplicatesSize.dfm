object frmDuplicateSize: TfrmDuplicateSize
  Left = 554
  Top = 319
  ClientHeight = 388
  ClientWidth = 477
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
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 477
    Height = 25
    Align = alTop
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    DesignSize = (
      477
      25)
    object sbGo: TSpeedButton
      Left = 1
      Top = 1
      Width = 23
      Height = 22
      Hint = 'show all duplicates'
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFDFB493D59D74D19668CE9263CB8E5EC98A5BC7
        8756C38452C38452C38452C38452C38452C38452D0A17DFFFFFFFFFFFFD7A175
        F8F2EDF7F0EAF6EDE6F4EAE2F3E7DEF1E4DBF0E2D8F0E2D8F0E2D8F0E2D8F0E2
        D8F0E2D8C58B5EFFFFFFFFFFFFD9A47AF9F3EEEBD2BEFFFFFFEBD3BFFFFFFFFF
        FFFFFFFFFFEAC7ADFFFFFFFFFFFFFFFFFFF0E2D8C68C5FFFFFFFFFFFFFDDA87E
        F9F3EFEBD0BAEBD0BBEBD0BBEBD0BBEBD0BBEBD1BDEACDB5EACDB5EACDB5EACD
        B5F0E2D8C68A5CFFFFFFFFFFFFDFAA82F9F3EFEACEB7FFFFFFEBD0BBFFFFFFFF
        FFFFFFFFFFEACFBAFBF6F2FFFFFFFFFFFFF0E2D8C88D5FFFFFFFFFFFFFE1AE87
        FAF4F0EACBB2EACCB3EACCB3EACCB3EACCB3EACEB7E8C7ACE8C7ACE8C8B0E8C8
        AEF0E2D8C48654FFFFFFFFFFFFE3B18CFAF6F1EAC9AEFFFFFFEAC9B0FFFFFFFF
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
      OnClick = sbGoClick
    end
    object sbSave: TSpeedButton
      Left = 59
      Top = 1
      Width = 23
      Height = 22
      Hint = 'save the results to a file'
      Enabled = False
      Flat = True
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000D8AB8ECD9570
        BD7342B76835B56835B46734B26634B06533AE6433AC6332AA6232A96132A860
        31A76132AB693CBC8661A8A8A893939371717167676766666666666665656564
        64646363636262626161616060605F5F5F606060676767838383C37D4FEBC6AD
        EAC5ADFEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFB
        F8C89A7CC79879AD6B407B7B7BC4C4C4C3C3C3FBFBFBFBFBFBFBFBFBFBFBFBFB
        FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFB989898969696696969BA6C38EDCAB3
        E0A27AFEFAF762C08862C08862C08862C08862C08862C08862C08862C088FDF9
        F6CA8D65C99B7CA761326A6A6AC8C8C89F9F9FFAFAFAB1B1B1B1B1B1B1B1B1B1
        B1B1B1B1B1B1B1B1B1B1B1B1B1B1F9F9F98A8A8A989898606060BB6C38EECCB6
        E1A27AFEFAF7BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2BFDCC2FDF9
        F6CD9068CC9E81A861326B6B6BCACACA9F9F9FFAFAFAD6D6D6D6D6D6D6D6D6D6
        D6D6D6D6D6D6D6D6D6D6D6D6D6D6F9F9F98D8D8D9C9C9C606060BB6B38EFCEB8
        E1A279FEFAF762C08862C08862C08862C08862C08862C08862C08862C088FDF9
        F6CF936ACEA384AA61326A6A6ACCCCCC9F9F9FFAFAFAB1B1B1B1B1B1B1B1B1B1
        B1B1B1B1B1B1B1B1B1B1B1B1B1B1F9F9F9909090A0A0A0606060BA6A36EFD0BB
        E2A27AFEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFBF8FEFB
        F8D3966DD2A78AAB6232696969CECECE9F9F9FFBFBFBFBFBFBFBFBFBFBFBFBFB
        FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFB939393A4A4A4616161BB6A36F0D2BE
        E2A37AE2A37AE1A37AE2A37BE1A37BE0A178DE9F77DD9F76DC9D74D99B72D899
        71D69970D5AB8EAD6333696969D0D0D0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A09E
        9E9E9C9C9C9C9C9C9A9A9A989898979797969696A8A8A8626262BB6A36F2D5C2
        E3A37AE3A37AE2A37BE2A37BE2A47BE1A279E0A178DEA077DE9E75DC9D74DA9B
        73D99B73DAB095AF6433696969D3D3D3A0A0A0A0A0A0A0A0A0A0A0A0A1A1A19F
        9F9F9E9E9E9D9D9D9B9B9B9A9A9A999999989898AEAEAE636363BB6A36F2D8C5
        E3A47BE3A37AE3A47AE2A47BE2A37BE1A37BE1A279DFA077DE9F76DD9E74DB9C
        72DC9D74DDB59AB16534696969D6D6D6A1A1A1A0A0A0A1A1A1A1A1A1A0A0A0A0
        A0A09F9F9F9D9D9D9C9C9C9B9B9B9999999A9A9AB2B2B2646464BB6B36F4D9C7
        E6A67DC88C64C98D65C98E67CB926CCB926DCA9069C88C65C88C64C88C64C88C
        64DA9C74E1BA9FB366346A6A6AD7D7D7A3A3A38989898A8A8A8B8B8B8F8F8F90
        90908D8D8D8A8A8A898989898989898989999999B7B7B7656565BB6C37F4DCC9
        E7A77DF9ECE1F9ECE1F9EDE3FCF4EEFDFAF7FDF7F3FAEDE5F7E7DBF7E5D9F6E5
        D8DEA077E4BEA4B467346B6B6BDADADAA4A4A4EBEBEBEBEBEBECECECF4F4F4FA
        FAFAF7F7F7EDEDEDE6E6E6E4E4E4E4E4E49D9D9DBBBBBB666666BD6E3AF5DDCC
        E7A87EFAF0E8FAF0E8C98D66FAF0E9FDF8F3FEFAF8FCF4EFF9E9DFF7E7DBF7E5
        D9E0A278E7C2A9B668356C6C6CDBDBDBA5A5A5EFEFEFEFEFEF8B8B8BF0F0F0F8
        F8F8FAFAFAF4F4F4E8E8E8E6E6E6E4E4E49F9F9FC0C0C0676767C07442F6DFD0
        E8A87EFCF6F1FCF6F1C88C64FAF1E9FBF4EEFDFAF7FDF9F6FAF0E8F8E8DDF7E6
        DBE1A37AEFD5C3B76A36727272DDDDDDA5A5A5F6F6F6F6F6F6898989F0F0F0F4
        F4F4FAFAFAF9F9F9EFEFEFE7E7E7E5E5E5A0A0A0D3D3D3686868C68255F6DFD1
        E9AA80FEFAF6FDFAF6C88C64FBF3EEFBF1EAFCF6F2FEFBF8FCF6F1F9ECE2F8E7
        DBEED0BAECD0BDBD7443808080DEDEDEA7A7A7FAFAFAFAFAFA898989F3F3F3F1
        F1F1F6F6F6FBFBFBF6F6F6EBEBEBE6E6E6CDCDCDCECECE727272D6A585F6E0D1
        F7E0D1FEFBF8FEFBF7FDF9F6FCF5F0FAF0EAFBF2EDFDF9F6FDFAF7FBF1EBF8E9
        DFECD1BECD926AE2C5B1A3A3A3DEDEDEDEDEDEFBFBFBFBFBFBF9F9F9F5F5F5F0
        F0F0F2F2F2F9F9F9FAFAFAF1F1F1E8E8E8CFCFCF8F8F8FC3C3C3E1BDA6D9AB8D
        C9895EC07543BD6E3ABB6C37BB6B36BB6A36BB6A36BC6C39BD6E3BBB6D3ABF74
        44C98D65E7CEBCFFFFFFBBBBBBA8A8A88686867373736C6C6C6B6B6B6A6A6A69
        69696969696B6B6B6D6D6D6B6B6B7373738A8A8ACCCCCCFFFFFF}
      NumGlyphs = 2
      OnClick = sbSaveClick
    end
    object sbCopy: TSpeedButton
      Left = 107
      Top = 1
      Width = 23
      Height = 22
      Hint = 'copy the results to the clipboard'
      Enabled = False
      Flat = True
      Glyph.Data = {
        36060000424D3606000000000000360000002800000020000000100000000100
        18000000000000060000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFD39570CC8357C87646CA7B4ECB7B4ECA7B4ECA7B
        4ECA7B4ECA8155CD865CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF94949482
        82827575757B7B7B7B7B7B7B7B7B7B7B7B7A7A7A808080848484BED2E14A80AB
        206398206398206398206398C98F67FCF3ECFAF1E8FAF0E7FBF1E9FBF2EAFBF2
        EAFBF2EBFDF4EECB8358D5D5D58A8A8A6F6F6F6F6F6F6F6F6F6F6F6F8C8C8CF3
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
        E7EABB88D39469FBF8F66F6F6FDDDDDDBCBCBCB8B8B8B2B2B2B2B2B2A8A8A8FF
        FFFFF2F2F2F2F2F2F1F1F1EEEEEEF1F1F1B5B5B5919191F8F8F8206398AADDF1
        74B9E070B6DF6CB3DD6BB2DCD9AF84D7AE81D7AC7FD7AC7FCCA070CD9F71B38F
        67D39B71FCFAF8FFFFFF6F6F6FE0E0E0C0C0C0BDBDBDBABABAB9B9B9AAAAAAA8
        A8A8A7A7A7A7A7A79A9A9A9A9A9A8A8A8A989898FAFAFAFFFFFF206398B0E1F2
        79BDE24498DD4497DC4396DC4296DC4295DC4195DB539ED489C6E6206398FFFF
        FFFFFFFFFFFFFFFFFFFF6F6F6FE3E3E3C3C3C3A8A8A8A7A7A7A6A6A6A6A6A6A6
        A6A6A5A5A5A9A9A9CBCBCB6F6F6FFFFFFFFFFFFFFFFFFFFFFFFF3B76A595C9E0
        AEE2F24E9DDFB5EEFD75D4F075D4F0B5EEFD4B9BDE8ECBE993CDE92A6A9DFFFF
        FFFFFFFFFFFFFFFFFFFF818181CCCCCCE4E4E4ACACACEFEFEFD7D7D7D7D7D7EF
        EFEFAAAAAACFCFCFD1D1D1767676FFFFFFFFFFFFFFFFFFFFFFFFD3E0EB6392B7
        2063983775A4B6EFFE80DBF380DBF3B6EFFE2E6EA12063986F9ABCB6CCDDFFFF
        FFFFFFFFFFFFFFFFFFFFE3E3E39A9A9A6F6F6F7F7F7FF0F0F0DDDDDDDDDDDDF0
        F0F07979796F6F6FA2A2A2D0D0D0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        DAE5EE2063982063982063982063982063982D6C9EFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE7E7E76F6F6F6F6F6F6F6F6F6F6F6F6F
        6F6F777777FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      NumGlyphs = 2
      OnClick = sbCopyClick
    end
    object SpeedButton1: TSpeedButton
      Left = 450
      Top = 1
      Width = 23
      Height = 22
      Hint = 'copy the results to the clipboard'
      Anchors = [akTop, akRight]
      Flat = True
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
      OnClick = SpeedButton1Click
    end
    object sbPrint: TSpeedButton
      Left = 25
      Top = 1
      Width = 23
      Height = 22
      Hint = 'print'
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C21E0000C21E00000000000000000000FFFFFFFFFFFF
        FFFFFFC89662CA9865CA9765CA9765CA9765CA9764C99764C99764CA9865C895
        62FFFFFFFFFFFFFFFFFFA1A1A17A7A7A585858C79561F9F7F6F9F1ECF9F1EBF8
        F0E9F7EDE6F4EAE1F2E8DEFAF8F6C794612424244B4B4B9696966B6B6BA7A7A7
        B5B5B5818181AFACAAC5C0BDC5C0BDC5C0BDC5C0BDC5C0BDC5C0BDADAAA82C2C
        2CB5B5B59B9B9B232323707070B5B5B5B5B5B59595958181818181817979796E
        6E6E6161615252524343434242426E6E6EB5B5B5B5B5B5252525757575BBBBBB
        BBBBBB8D8D8DD4D4D4B9B9B9B9B9B9B9B9B9B9B9B9B9B9B9B9B9B9D3D3D38383
        83BBBBBBBBBBBB2A2A2A7A7A7AD7D7D7D7D7D7979797D8D8D8BFBFBFBFBFBFBF
        BFBFBFBFBFBFBFBFBFBFBFD7D7D78E8E8ED7D7D7D7D7D73F3F3F7E7E7EF9F9F9
        F9F9F9ABABABDFDFDFCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBCBDFDFDFA3A3
        A3F9F9F9F9F9F9616161848484FCFCFCFCFCFCCBCBCBF2F2F2F2F2F2F2F2F2F2
        F2F2F2F2F2F2F2F2F2F2F2F2F2F2C6C6C6FCFCFCFCFCFC717171979797D2D2D2
        E8E8E87D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D
        7DE8E8E8C4C4C46D6D6DDDDDDD9A9A9ACCCCCCC78B4EF9F4EDFEE8D8FEE8D7FD
        E5D3FCE4D1FAE0C7F9DDC3FAF4EDC7854AC3C3C3747474CDCDCDFFFFFFCECECE
        878787C5894CF9F4EFFEE7D7FDE7D5FCE6D2FBE1CCF8DCC2F6DABDFAF4EFC483
        48616161BCBCBCFFFFFFFFFFFFFFFFFFFBFBFBC68C4FF9F4F0FCE6D3FDE7D3FB
        E3CDFAE0C8F5D6BBF3D4B5F8F4F0C4854AF9F9F9FFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFC88D51F9F5F1FCE3CFFCE4CFFAE1CAF9DDC4F4E9DFF7F2ECF5EFE9C380
        48FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC88D52F9F5F1FCE3CDFBE3CDF9
        E0C8F8DCC2FDFBF8FCE6CDE2B684D5A884FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFC5884DF7F2ECF8F4EEF8F3EDF8F3EDF8F2ECF2E6D7E2B27DDB9569FDFB
        FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8CEB9D7AA7CC88C50C88C4FCA
        9155CB9055C5894DDDAF8DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      OnClick = sbPrintClick
    end
    object lDCount: THTMLabel
      Left = 136
      Top = 7
      Width = 308
      Height = 17
      Anchors = [akLeft, akTop, akRight]
      HTMLText.Strings = (
        '...')
      Transparent = True
      Version = '1.9.2.8'
    end
    object sbCopyCSV: TSpeedButton
      Left = 83
      Top = 1
      Width = 23
      Height = 22
      Hint = 'save in CSV format'
      Enabled = False
      Flat = True
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
      OnClick = sbCopyCSVClick
    end
  end
  object sgDuplicates: TAdvStringGrid
    Left = 0
    Top = 25
    Width = 477
    Height = 363
    Cursor = crDefault
    Hint = 'double click to see all files belonging to the category'
    Align = alClient
    ColCount = 2
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
    PopupMenu = puSearch
    ScrollBars = ssBoth
    TabOrder = 1
    OnDrawCell = sgDuplicatesDrawCell
    GridLineColor = 15527152
    GridFixedLineColor = 13947601
    HoverRowCells = [hcNormal, hcSelected]
    OnGetCellColor = sgDuplicatesGetCellColor
    OnCanSort = sgDuplicatesCanSort
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = 16575452
    ActiveCellColorTo = 16571329
    Bands.PrimaryColor = 16381426
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
    FixedColWidth = 396
    FixedRowHeight = 17
    FixedRowAlways = True
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
    SearchFooter.Font.Charset = DEFAULT_CHARSET
    SearchFooter.Font.Color = clWindowText
    SearchFooter.Font.Height = -11
    SearchFooter.Font.Name = 'MS Sans Serif'
    SearchFooter.Font.Style = []
    SearchFooter.ResultFormat = '(%d of %d)'
    ShowSelection = False
    ShowDesignHelper = False
    SortSettings.DefaultFormat = ssAutomatic
    SortSettings.Column = 0
    SortSettings.Show = True
    SortSettings.HeaderColor = 16579058
    SortSettings.HeaderColorTo = 16579058
    SortSettings.HeaderMirrorColor = 16380385
    SortSettings.HeaderMirrorColorTo = 16182488
    Version = '8.2.9.1'
    ColWidths = (
      396
      64)
    RowHeights = (
      17
      17)
  end
  object puSearch: TPopupMenu
    OnPopup = puSearchPopup
    Left = 417
    Top = 9
    object miSearchOpen: TMenuItem
      Caption = '.'
      ImageIndex = 1
      OnClick = miSearchOpenClick
    end
    object miSearchOpenCustom: TMenuItem
      Caption = '.'
      OnClick = miSearchOpenCustomClick
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object miExploreDirectory: TMenuItem
      Caption = '.'
      ImageIndex = 4
      OnClick = miExploreDirectoryClick
    end
    object miSFileProperties: TMenuItem
      Caption = '.'
      ImageIndex = 2
      OnClick = miSFilePropertiesClick
    end
    object miGenerateMD5: TMenuItem
      Caption = '.'
      OnClick = miGenerateMD5Click
    end
    object N21: TMenuItem
      Caption = '-'
    end
  end
end
