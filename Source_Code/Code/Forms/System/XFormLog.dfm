object FormLog: TFormLog
  Left = 0
  Top = 0
  Caption = 'FormLog'
  ClientHeight = 569
  ClientWidth = 962
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 541
    Width = 962
    Height = 28
    Align = alBottom
    TabOrder = 0
    object bSave: TBitBtn
      Left = 0
      Top = 2
      Width = 97
      Height = 25
      TabOrder = 0
    end
    object bClose: TBitBtn
      Left = 864
      Top = 2
      Width = 98
      Height = 25
      ModalResult = 1
      TabOrder = 1
    end
    object bRefresh: TBitBtn
      Left = 103
      Top = 2
      Width = 97
      Height = 25
      TabOrder = 2
      OnClick = bRefreshClick
    end
  end
  object mLog: TMemo
    Left = 0
    Top = 0
    Width = 962
    Height = 541
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      'mLog')
    ParentFont = False
    TabOrder = 1
  end
end
