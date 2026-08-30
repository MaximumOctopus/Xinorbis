object Form5: TForm5
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 121
  ClientWidth = 289
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 273
    Height = 73
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 31
    Height = 15
    Caption = 'From:'
  end
  object Label2: TLabel
    Left = 160
    Top = 24
    Width = 15
    Height = 15
    Caption = 'To:'
  end
  object Label3: TLabel
    Left = 135
    Top = 44
    Width = 23
    Height = 15
    Caption = '--->'
  end
  object cbFrom: TComboBox
    Left = 72
    Top = 40
    Width = 57
    Height = 23
    Style = csDropDownList
    ItemIndex = 2
    TabOrder = 0
    Text = 'MB'
    Items.Strings = (
      'Bytes'
      'K'
      'MB'
      'GB')
  end
  object eFrom: TEdit
    Left = 24
    Top = 40
    Width = 41
    Height = 23
    Alignment = taRightJustify
    TabOrder = 1
    Text = '1'
  end
  object cbTo: TComboBox
    Left = 208
    Top = 40
    Width = 57
    Height = 23
    Style = csDropDownList
    ItemIndex = 2
    TabOrder = 2
    Text = 'MB'
    Items.Strings = (
      'Bytes'
      'K'
      'MB'
      'GB')
  end
  object eTo: TEdit
    Left = 161
    Top = 40
    Width = 41
    Height = 23
    Alignment = taRightJustify
    TabOrder = 3
    Text = '20'
  end
  object bOK: TBitBtn
    Left = 128
    Top = 88
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 4
  end
  object BitBtn2: TBitBtn
    Left = 208
    Top = 88
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 5
  end
end
