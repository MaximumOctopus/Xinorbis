object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 468
  ClientWidth = 859
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object mResults: TMemo
    Left = 0
    Top = 73
    Width = 859
    Height = 395
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      '')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object pcReference: TPageControl
    Left = 0
    Top = 0
    Width = 859
    Height = 73
    ActivePage = TabSheet1
    Align = alTop
    TabOrder = 1
    object TabSheet1: TTabSheet
      DesignSize = (
        851
        43)
      object sbFileExtensions: TSpeedButton
        Left = 3
        Top = 14
        Width = 23
        Height = 22
        OnClick = sbFileExtensionsClick
      end
      object eFileExtension: TEdit
        Left = 32
        Top = 15
        Width = 121
        Height = 23
        TabOrder = 0
        OnChange = eFileExtensionChange
        OnKeyPress = eFileExtensionKeyPress
      end
      object bHelp: TBitBtn
        Left = 773
        Top = 14
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        TabOrder = 1
        OnClick = bHelpClick
      end
    end
    object TabSheet2: TTabSheet
      ImageIndex = 1
      object sbWindowsFile: TSpeedButton
        Left = 3
        Top = 14
        Width = 23
        Height = 22
        OnClick = sbWindowsFileClick
      end
      object eWindowsFile: TEdit
        Left = 32
        Top = 14
        Width = 121
        Height = 23
        TabOrder = 0
        OnChange = eWindowsFileChange
        OnKeyPress = eWindowsFileKeyPress
      end
      object rbXP: TRadioButton
        Left = 168
        Top = 17
        Width = 49
        Height = 17
        Caption = 'XP'
        TabOrder = 1
      end
      object rbW7: TRadioButton
        Left = 223
        Top = 17
        Width = 90
        Height = 17
        Caption = 'Windows 7'
        TabOrder = 2
      end
    end
  end
end
