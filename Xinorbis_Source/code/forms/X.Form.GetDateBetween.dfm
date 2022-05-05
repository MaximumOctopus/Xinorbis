object Form2: TForm2
  Left = 491
  Top = 309
  BorderStyle = bsDialog
  Caption = 'Search between...'
  ClientHeight = 257
  ClientWidth = 522
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
    Width = 505
    Height = 209
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
    Left = 272
    Top = 21
    Width = 16
    Height = 13
    Caption = 'To:'
  end
  object BitBtn1: TBitBtn
    Left = 357
    Top = 223
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 0
  end
  object BitBtn2: TBitBtn
    Left = 438
    Top = 223
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object mcFrom: TMonthCalendar
    Left = 24
    Top = 40
    Width = 225
    Height = 161
    Date = 39691.014815694440000000
    TabOrder = 2
  end
  object mcTo: TMonthCalendar
    Left = 272
    Top = 40
    Width = 225
    Height = 161
    Date = 39691.014815694440000000
    TabOrder = 3
  end
end
