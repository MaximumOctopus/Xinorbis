using System;
using System.Windows.Forms;

namespace X.Diagnostic
{
    public partial class Form1 : Form
    {
        Xinorbis XData;

        public Form1()
        {
            InitializeComponent();

            XData = new Xinorbis();

            Text = "X.Diagnostics " + Constants.xDVersion + " / " + Constants.xDDate + " :: (c) Paul Alan Freshney 2020";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            rtbMain.Clear();

            rtbMain.AppendText("==== System Details =================" + Environment.NewLine);
            rtbMain.AppendText(Environment.NewLine);

            rtbMain.AppendText("User Name: " + Utility.GetCurrentUserName() + Environment.NewLine);

            rtbMain.AppendText(Environment.NewLine);
            rtbMain.AppendText("==== Xinorbis System ================" + Environment.NewLine);
            rtbMain.AppendText(Environment.NewLine);

            rtbMain.AppendText(XData.GetExeNameVersion("32") + Environment.NewLine);
            rtbMain.AppendText(XData.GetExeNameVersion("64") + Environment.NewLine);

            rtbMain.AppendText("");
            //rtbMain.AppendText(XData.GetRegistrationDetails() + Environment.NewLine);

            rtbMain.AppendText(XData.GetDatabaseDetails() + Environment.NewLine);            

            CheckFolderIntegrity();

            rtbMain.AppendText(Environment.NewLine);
            rtbMain.AppendText("=====================================");
        }

        private void CheckFolderIntegrity()
        {
            string lName = Utility.GetCurrentUserName();

            rtbMain.AppendText(Environment.NewLine);
            rtbMain.AppendText("==== Xinorbis System Integrity ======" + Environment.NewLine);
            rtbMain.AppendText(Environment.NewLine);

            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\_custom.ini") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\Be.HexEditor.exe") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\Be.Windows.Forms.HexBox.dll") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\custom.ini") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\DelZip192.dll") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\DelZip192x64.dll") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\sqlite3.dll") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\x8.32.exe") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\x8.64.exe") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\X8Updater.exe") + Environment.NewLine);
            rtbMain.AppendText(Utility.FileIntegrity(Application.StartupPath + "\\Xinorbis8 User Manual.pdf") + Environment.NewLine);

            rtbMain.AppendText(Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\help") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\cat") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\cz") + Environment.NewLine);			
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\de") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\es") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\fr") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\hu") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\it") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\nl") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\ru") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\uk") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\languages\\us") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\layouts") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\data\\system") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(Application.StartupPath + "\\system") + Environment.NewLine);

            rtbMain.AppendText(Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\FolderHistory\\Database") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Saves\\Custom Reports") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName) + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\CSV\\autosaves") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\CSV\\quick") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\HTML\\data") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\HTML\\autosaves\\data") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\HTML\\quick\\data") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\HTML_Compare\\data") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\HTML_Compare\\autosaves\\data") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\HTML_Compare\\quick\\data") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Xinorbis\\autosaves") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Xinorbis\\quick") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Summary\\autosaves") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Summary\\quick") + Environment.NewLine);
            
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Text\\autosaves") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Text\\quick") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Tree\\autosaves") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\Tree\\quick") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\XML\\autosaves") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\XML\\quick") + Environment.NewLine);

            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\XML_Compare\\autosaves") + Environment.NewLine);
            rtbMain.AppendText(Utility.FolderIntegrity(XData.XinorbisDataPath + "\\Reports\\" + lName + "\\XML_Compare\\quick") + Environment.NewLine);
        }

        private void bSave_Click(object sender, EventArgs e)
        {
            if (sfdMain.ShowDialog() == DialogResult.OK)
            {
                rtbMain.SaveFile(sfdMain.FileName, RichTextBoxStreamType.PlainText);
            }
        }

        private void bCopy_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(rtbMain.Text);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            frmAbout aboutBox = new frmAbout();

            aboutBox.ShowDialog(this);

            aboutBox.Dispose();
        }
    }
}