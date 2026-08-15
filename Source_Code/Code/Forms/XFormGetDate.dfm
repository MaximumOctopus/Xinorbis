object Form7: TForm7
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Form7'
  ClientHeight = 211
  ClientWidth = 250
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object cMain: TMonthCalendar
    Left = 8
    Top = 8
    Width = 233
    Height = 169
    Date = 39691.000000000000000000
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 88
    Top = 183
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 1
  end
  object BitBtn2: TBitBtn
    Left = 169
    Top = 183
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
end
