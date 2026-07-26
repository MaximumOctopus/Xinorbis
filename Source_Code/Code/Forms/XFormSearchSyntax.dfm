object FormSearchSyntax: TFormSearchSyntax
  Left = 0
  Top = 0
  Caption = 'FormSearchSyntax'
  ClientHeight = 481
  ClientWidth = 767
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
  object wbSearch: TWebBrowser
    Left = 248
    Top = 8
    Width = 513
    Height = 441
    TabOrder = 0
    ControlData = {
      4C00000005350000942D00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 233
    Height = 441
    Caption = 'Panel1'
    TabOrder = 1
    object wbIndex: TWebBrowser
      Left = 1
      Top = 1
      Width = 231
      Height = 439
      Align = alClient
      TabOrder = 0
      OnBeforeNavigate2 = wbIndexBeforeNavigate2
      ControlData = {
        4C000000E01700005F2D00000000000000000000000000000000000000000000
        000000004C000000000000000000000001000000E0D057007335CF11AE690800
        2B2E126208000000000000004C0000000114020000000000C000000000000046
        8000000000000000000000000000000000000000000000000000000000000000
        00000000000000000100000000000000000000000000000000000000}
    end
  end
  object cbStayOnTop: TCheckBox
    Left = 8
    Top = 458
    Width = 97
    Height = 17
    Caption = 'Stay on Top'
    Checked = True
    State = cbChecked
    TabOrder = 2
    OnClick = cbStayOnTopClick
  end
  object bClose: TBitBtn
    Left = 686
    Top = 455
    Width = 75
    Height = 25
    Caption = 'bClose'
    ModalResult = 1
    TabOrder = 3
  end
end
