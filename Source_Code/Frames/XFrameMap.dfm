object FrameMap: TFrameMap
  Left = 0
  Top = 0
  Width = 1102
  Height = 672
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1102
    Height = 58
    Align = alTop
    TabOrder = 0
    object lMapFolder: TLabel
      Left = 260
      Top = 0
      Width = 3
      Height = 15
      Caption = '.'
    end
    object lMapSize: TLabel
      Left = 8
      Top = 32
      Width = 3
      Height = 15
      Caption = '.'
    end
    object shapeMap: TShape
      Left = 222
      Top = 4
      Width = 32
      Height = 46
    end
    object lMapDetails1: TLabel
      Left = 260
      Top = 21
      Width = 3
      Height = 15
      Caption = '.'
    end
    object lMapDetails2: TLabel
      Left = 260
      Top = 42
      Width = 3
      Height = 15
      Caption = '.'
    end
    object cbMapSizeSelect: TComboBox
      Left = 72
      Top = 27
      Width = 38
      Height = 23
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = 'A'
      OnChange = cbMapSizeSelectChange
      Items.Strings = (
        'A'
        'B')
    end
    object cbHighlightMode: TCheckBox
      Left = 152
      Top = 32
      Width = 49
      Height = 17
      TabOrder = 1
      OnClick = cbHighlightModeClick
    end
    object rbBySize: TRadioButton
      Left = 8
      Top = 4
      Width = 106
      Height = 17
      Caption = '.'
      TabOrder = 2
      OnClick = rbBySizeClick
    end
    object rbByQuantity: TRadioButton
      Left = 120
      Top = 4
      Width = 96
      Height = 17
      Caption = '.'
      TabOrder = 3
      OnClick = rbBySizeClick
    end
  end
  object pMap: TPanel
    Left = 0
    Top = 58
    Width = 1102
    Height = 614
    Align = alClient
    TabOrder = 1
    ExplicitLeft = 464
    ExplicitTop = 264
    ExplicitWidth = 185
    ExplicitHeight = 41
  end
end
