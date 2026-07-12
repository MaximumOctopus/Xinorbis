object FormImportCSV: TFormImportCSV
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'FormImportCSV'
  ClientHeight = 737
  ClientWidth = 518
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 497
    Height = 57
    TabOrder = 0
    object lFileName: TLabel
      Left = 3
      Top = 11
      Width = 55
      Height = 15
      Caption = 'lFileName'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lSelectedFileName: TLabel
      Left = 3
      Top = 32
      Width = 3
      Height = 15
      Caption = '.'
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 80
    Width = 497
    Height = 585
    TabOrder = 1
    object lFieldDataType: TLabel
      Left = 19
      Top = 14
      Width = 36
      Height = 15
      Caption = 'Label1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lContentsFirstRecord: TLabel
      Left = 219
      Top = 14
      Width = 36
      Height = 15
      Caption = 'Label1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lContents1: TLabel
      Left = 219
      Top = 38
      Width = 57
      Height = 15
      Caption = 'lContents1'
    end
    object lContents2: TLabel
      Left = 219
      Top = 65
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents3: TLabel
      Left = 219
      Top = 92
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents4: TLabel
      Left = 219
      Top = 119
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents5: TLabel
      Left = 219
      Top = 146
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents6: TLabel
      Left = 219
      Top = 173
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents7: TLabel
      Left = 219
      Top = 200
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents8: TLabel
      Left = 219
      Top = 227
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents9: TLabel
      Left = 219
      Top = 254
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents10: TLabel
      Left = 219
      Top = 281
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents11: TLabel
      Left = 219
      Top = 308
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents12: TLabel
      Left = 219
      Top = 335
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents13: TLabel
      Left = 219
      Top = 362
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents14: TLabel
      Left = 219
      Top = 389
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents15: TLabel
      Left = 219
      Top = 416
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents16: TLabel
      Left = 219
      Top = 443
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents17: TLabel
      Left = 219
      Top = 470
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents18: TLabel
      Left = 219
      Top = 497
      Width = 34
      Height = 15
      Caption = 'Label1'
    end
    object lContents19: TLabel
      Left = 219
      Top = 524
      Width = 57
      Height = 15
      Caption = 'lContents1'
    end
    object lContents20: TLabel
      Left = 219
      Top = 551
      Width = 57
      Height = 15
      Caption = 'lContents1'
    end
    object cbType1: TComboBox
      Left = 19
      Top = 35
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 0
      OnChange = cbType1Change
    end
    object cbType2: TComboBox
      Left = 19
      Top = 62
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 1
      OnChange = cbType1Change
    end
    object cbType3: TComboBox
      Left = 19
      Top = 89
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 2
      OnChange = cbType1Change
    end
    object cbType4: TComboBox
      Left = 19
      Top = 116
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 3
      OnChange = cbType1Change
    end
    object cbType5: TComboBox
      Left = 19
      Top = 143
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 4
      OnChange = cbType1Change
    end
    object cbType6: TComboBox
      Left = 19
      Top = 170
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 5
      OnChange = cbType1Change
    end
    object cbType7: TComboBox
      Left = 19
      Top = 197
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 6
      OnChange = cbType1Change
    end
    object cbType8: TComboBox
      Left = 19
      Top = 222
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 7
      OnChange = cbType1Change
    end
    object cbType9: TComboBox
      Left = 19
      Top = 251
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 8
      OnChange = cbType1Change
    end
    object cbType10: TComboBox
      Left = 19
      Top = 278
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 9
      OnChange = cbType1Change
    end
    object cbType11: TComboBox
      Left = 19
      Top = 305
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 10
      OnChange = cbType1Change
    end
    object cbType12: TComboBox
      Left = 19
      Top = 332
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 11
      OnChange = cbType1Change
    end
    object cbType13: TComboBox
      Left = 19
      Top = 359
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 12
      OnChange = cbType1Change
    end
    object cbType14: TComboBox
      Left = 19
      Top = 386
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 13
      OnChange = cbType1Change
    end
    object cbType15: TComboBox
      Left = 19
      Top = 413
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 14
      OnChange = cbType1Change
    end
    object cbType16: TComboBox
      Left = 19
      Top = 438
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 15
      OnChange = cbType1Change
    end
    object cbType17: TComboBox
      Left = 19
      Top = 467
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 16
      OnChange = cbType1Change
    end
    object cbType18: TComboBox
      Left = 19
      Top = 496
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 17
      OnChange = cbType1Change
    end
    object cbType19: TComboBox
      Left = 19
      Top = 521
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 18
      OnChange = cbType1Change
    end
    object cbType20: TComboBox
      Left = 19
      Top = 548
      Width = 182
      Height = 23
      Style = csDropDownList
      TabOrder = 19
      OnChange = cbType1Change
    end
  end
  object cbIFR: TCheckBox
    Left = 27
    Top = 676
    Width = 97
    Height = 17
    Caption = '.'
    TabOrder = 2
  end
  object bImport: TBitBtn
    Left = 349
    Top = 709
    Width = 75
    Height = 25
    Caption = 'bImport'
    TabOrder = 3
  end
  object bCancel: TBitBtn
    Left = 430
    Top = 709
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'BitBtn1'
    ModalResult = 2
    TabOrder = 4
  end
  object bHelp: TBitBtn
    Left = 8
    Top = 709
    Width = 75
    Height = 25
    Caption = 'BitBtn1'
    TabOrder = 5
    OnClick = bHelpClick
  end
  object bAuto: TBitBtn
    Left = 227
    Top = 709
    Width = 75
    Height = 25
    Caption = 'BitBtn1'
    TabOrder = 6
    OnClick = bAutoClick
  end
end
