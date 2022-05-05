object frmGetFileSize: TfrmGetFileSize
  Left = 586
  Top = 302
  BorderStyle = bsDialog
  Caption = 'Find files....'
  ClientHeight = 121
  ClientWidth = 289
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
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
    Width = 26
    Height = 13
    Caption = 'From:'
  end
  object Label2: TLabel
    Left = 160
    Top = 24
    Width = 16
    Height = 13
    Caption = 'To:'
  end
  object Label3: TLabel
    Left = 135
    Top = 44
    Width = 18
    Height = 13
    Caption = '---->'
  end
  object cbFrom: TComboBox
    Left = 72
    Top = 40
    Width = 57
    Height = 21
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
    Height = 21
    TabOrder = 1
    Text = '1'
  end
  object cbTo: TComboBox
    Left = 208
    Top = 40
    Width = 57
    Height = 21
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
    Left = 160
    Top = 40
    Width = 41
    Height = 21
    TabOrder = 3
    Text = '20'
  end
  object bOK: TBitBtn
    Left = 128
    Top = 88
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 4
  end
  object BitBtn2: TBitBtn
    Left = 208
    Top = 88
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 5
  end
end
