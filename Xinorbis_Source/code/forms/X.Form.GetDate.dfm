object Form2: TForm2
  Left = 361
  Top = 189
  BorderStyle = bsDialog
  Caption = 'frmGetDate'
  ClientHeight = 183
  ClientWidth = 344
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object cMain: TMonthCalendar
    Left = 8
    Top = 8
    Width = 233
    Height = 169
    Date = 39691.014815474540000000
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 256
    Top = 16
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 1
  end
  object BitBtn2: TBitBtn
    Left = 256
    Top = 48
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
end
