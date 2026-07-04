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
    Height = 54
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 1064
    object lMapFolder: TLabel
      Left = 260
      Top = 4
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
      Top = 2
      Width = 32
      Height = 46
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
      Items.Strings = (
        'A'
        'B')
    end
  end
end
