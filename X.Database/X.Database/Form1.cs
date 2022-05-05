//
// X.Database
//
// www.Xinorbis.com
// www.MaximumOctopus.com
//
// Download the latest source code from: www.MaximumOctopus.com/sourcecode.htm
//
// January 31st 2019
//


using System;
using System.IO;
using System.Data;
using System.Data.Odbc;
using System.Data.SQLite;
using System.Windows.Forms;

namespace X.Database
{
    public partial class Form1 : Form
    {

        private Xinorbis GXinorbisSystem;
        private ScanList GScanList;
        private ScanDetail GScanDetail;

        public Form1()
        {
            InitializeComponent();

            GXinorbisSystem = new Xinorbis();

            Settings.LoadSettings();

            tbASODBCConnectionString.Text = Settings.ODBCConnectionString;
            tbXFODBCConnectionString.Text = Settings.ODBCConnectionString;

            UpdateFolderHistoryDisplay();

            GScanList = new ScanList();
            GScanDetail = new ScanDetail();

            Text = "X.Database :: " + Constants.xDVersion + " / " + Constants.xDDate;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            FormState lFormState = new FormState();

            lFormState.Top    = Top;
            lFormState.Left   = Left;
            lFormState.Width  = Width;
            lFormState.Height = Height;

            Utility.SaveFormState(lFormState);
        }

        public void UpdateFolderHistoryDisplay()
        {
            tbFHPath.Text = GXinorbisSystem.XinorbisDataPath + "FolderHistory\\";

            if (GXinorbisSystem.GetPCCount() != 0)
            {
                for (int i = 0; i < GXinorbisSystem.GetPCCount(); i++)
                {
                    cbAvailablePCs.Items.Add(GXinorbisSystem.GetPCItem(i));
                }

                cbAvailablePCs.SelectedIndex = 0;
            }
            else
            {
                MessageBox.Show("Error location a Folder History database.",
                                "X.Database",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);

                DisableApplicationUI();
            }
        }

        private void SetApplicationUserLogic(bool aAvailable)
        {
            bExportCSV.Enabled = aAvailable;
            bExportXML.Enabled = aAvailable;
        }

        private void DisableApplicationUI()
        {
            bSelect.Enabled = false;

            cbScanPathList.Enabled = false;
            cbScanDateList.Enabled = false;

            rbFilterAll.Enabled = false;
            rbFilterSizes.Enabled = false;
            rbFilterDates.Enabled = false;
            rbFilterAttributes.Enabled = false;
            rbFilterOther.Enabled = false;

            cbFilterSQL.Enabled = false;
            tbFilterSQL.Enabled = false;

            cbSQLQuerySelect.Enabled = false;
            tbSQLQueryWhere.Enabled = false;
        }

        private void bSelect_Click(object sender, EventArgs e)
        {
            GScanList.NewReportFolder(tbFHPath.Text + cbAvailablePCs.SelectedItem + "\\");

            cbScanPathList.Items.Clear();

            if (GScanList.ItemCount() != 0)
            {
                for (int t = 0; t < GScanList.ItemCount(); t++)
                {
                    ScanListObject slo = GScanList.Item(t);

                    cbScanPathList.Items.Add(slo.Path);
                }

                cbScanPathList.SelectedIndex = 0;
            }
            else
            {
                SetApplicationUserLogic(false);
            }
        }

        private void cbScanPathList_SelectedIndexChanged(object sender, EventArgs e)
        {
            ScanListObject slo = GScanList.Item(cbScanPathList.SelectedIndex);

            if (slo != null)
            {
                if (GScanDetail.NewReportFile(slo.ReportFileName) != 0)
                {
                    cbScanDateList.Items.Clear();

                    if (GScanDetail.ItemCount() != 0)
                    {
                        for (int t = 0; t < GScanDetail.ItemCount(); t++)
                        {
                            ScanDetailObject sdo = GScanDetail.Item(t);

                            cbScanDateList.Items.Add(sdo.dateOutput);
                        }

                        cbScanDateList.SelectedIndex = 0;
                    }
                    else
                    {
                        SetApplicationUserLogic(false);
                    }
                }
            }
        }

        private void rbXFSQlite_Click(object sender, EventArgs e)
        {
            DatabaseUpdate();
        }

        private void cbScanDateList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tcFormatSelect.SelectedIndex == 0)
            {
                DatabaseUpdate();
            }
            else
            {
                dgASSystem_CellDoubleClick(null, null);
            }
        }

        private void DatabaseUpdate()
        {
            if (bSelect.Enabled && cbScanDateList.SelectedIndex != -1)
            {
                string pathMD5    = GScanList.Item(cbScanPathList.SelectedIndex).MD5Hash;
                string dateString = GScanDetail.Item(cbScanDateList.SelectedIndex).dateSystem;
                string scanPC     = cbAvailablePCs.SelectedItem.ToString();

                string tableName  = pathMD5 + dateString + scanPC;

                if (tableName != "")
                {
                    BuildViewFromTableName(tableName);
                }
            }
        }

        private void BuildViewFromTableName(string aTableName)
        {
            lTableName.Text = aTableName;

            Stats.HasRealData = false;

            if (rbXFSQlite.Checked)
            {
                BuildViewFromTableNameSQlite(aTableName);
            }
            else
            {
                if (tbXFODBCConnectionString.Text != "")
                {
                    BuildViewFromTableNameODBC(aTableName);
                }
                else
                {
                    toolStripStatusLabel1.Text = "Missing connection string";
                    toolStripStatusLabel2.Text = "";
                }
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmAbout aboutBox = new frmAbout();

            aboutBox.ShowDialog(this);

            aboutBox.Dispose();
        }

        private string GetSql(string aTableName, string aScanDate)
        {
            string lSQL;

            if (tcFormatSelect.SelectedIndex == 0)
            {
                if (tcFilter.SelectedIndex == 0)
                {
                    if (rbFilterSizes.Checked)
                    {
                        lSQL = "SELECT FilePath, FileName, FileSize, FileSizeDisk FROM \"" + aTableName + "\"";
                    }
                    else if (rbFilterDates.Checked)
                    {
                        lSQL = "SELECT FilePath, FileName, Directory, FileDateC, FileDateA, FileDateM FROM \"" + aTableName + "\"";
                    }
                    else if (rbFilterAttributes.Checked)
                    {
                        lSQL = "SELECT FilePath, FileName, Directory, Readonly, Hidden, System, Archive, Temp FROM \"" + aTableName + "\"";
                    }
                    else if (rbFilterOther.Checked)
                    {
                        lSQL = "SELECT FilePath, FileName, Directory, Category, Owner FROM \"" + aTableName + "\"";
                    }
                    else
                    {
                        lSQL = "SELECT * FROM \"" + aTableName + "\"";
                    }

                    if ((cbFilterSQL.Checked) && (tbFilterSQL.Text != ""))
                    {
                        return lSQL + " WHERE " + tbFilterSQL.Text + ";";
                    }
                    else
                    {
                        return lSQL + ";";
                    }
                }
                else
                {
                    string lSelect;

                    if (cbSQLQuerySelect.Text == "")
                    {
                        lSelect = "*";
                    }
                    else
                    {
                        lSelect = cbSQLQuerySelect.Text;
                    }

                    if (tbSQLQueryWhere.Text == "")
                    {
                        return "SELECT " + cbSQLQuerySelect.Text + " FROM \"" + aTableName + "\";";
                    }
                    else
                    {
                        return "SELECT " + cbSQLQuerySelect.Text + " FROM \"" + aTableName + "\" WHERE " + tbSQLQueryWhere.Text + ";";
                    }
                }
            }
            else
            {
                if (tcFilter.SelectedIndex == 0)
                {
                    return "SELECT * FROM \"" + aTableName + "\" WHERE ScanDate=" + aScanDate;
                }
                else
                {
                    string lSelect;

                    if (cbSQLQuerySelect.Text == "")
                    {
                        lSelect = "*";
                    }
                    else
                    {
                        lSelect = cbSQLQuerySelect.Text;
                    }

                    if (tbSQLQueryWhere.Text == "")
                    {
                        return "SELECT " + cbSQLQuerySelect.Text + " FROM \"" + aTableName + "\" WHERE ScanDate=" + aScanDate + ";";
                    }
                    else
                    {
                        return "SELECT " + cbSQLQuerySelect.Text + " FROM \"" + aTableName + "\" WHERE " + tbSQLQueryWhere.Text + " AND ScanDate=" + aScanDate + ";";
                    }
                }
            }
        }

        private void miExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void tabControl2_SelectedIndexChanged(object sender, EventArgs e)
        {
            dgMain.DataSource          = null;
            dgASSystem.DataSource      = null;

            toolStripStatusLabel1.Text = "";
            toolStripStatusLabel2.Text = "";

            SetApplicationUserLogic(false);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();

            saveFileDialog.Filter = "CSV files (*.csv|*.csv|All files (*.*)|*.*";
            saveFileDialog.FilterIndex = 1;
            saveFileDialog.RestoreDirectory = true;

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                ExportToCSV.Export(ref dgMain, saveFileDialog.FileName);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();

            saveFileDialog.Filter = "XML files (*.xml|*.xml|All files (*.*)|*.*";
            saveFileDialog.FilterIndex = 1;
            saveFileDialog.RestoreDirectory = true;

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                ExportToXML.Export(ref dgMain, saveFileDialog.FileName);
            }
        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();

            saveFileDialog.Filter = "Text files (*.txt|*.txt|All files (*.*)|*.*";
            saveFileDialog.FilterIndex = 1;
            saveFileDialog.RestoreDirectory = true;

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                ExportToText.Export(ref dgMain, saveFileDialog.FileName);
            }
        }

        private void xinorbisHomeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Utility.OpenWebPage("http://www.xinorbis.com");
        }

        private void helpToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(Path.GetDirectoryName(Application.ExecutablePath) + "\\data\\x.database.help.txt");
        }

        private void cbSQLQuerySelect_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r')
            {
                cbScanDateList_SelectedIndexChanged(null, null);
            }
        }

        private void lastSQLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            pLastSQL.Visible = lastSQLToolStripMenuItem.Checked;
        }

        private void BuildViewFromTableNameSQlite(string aTableName)
        {
            if (File.Exists(GXinorbisSystem.XinorbisDatabasePath))
            {
                string sql = GetSql(aTableName, "");

                tbLastSQL.Text = sql;

                var conn = new SQLiteConnection("Data Source=" + GXinorbisSystem.XinorbisDatabasePath + ";Version=3;");

                try
                {
                    conn.Open();

                    DataSet ds = new DataSet();
                    var da = new SQLiteDataAdapter(sql, conn);

                    da.Fill(ds);

                    if (ds.Tables.Count != 0)
                    {
                        dgMain.DataSource = ds.Tables[0].DefaultView;

                        SetApplicationUserLogic(true);

                        Stats.GenerateStats(ref dgMain);

                        toolStripStatusLabel1.Text = "Found " + ds.Tables[0].Rows.Count.ToString() + " records.";

                        if (Stats.HasRealData && miGatherStats.Checked)
                        {
                            toolStripStatusLabel2.Text = "Size of files: " + Utility.ConvertToUsefulUnit(Stats.SizeOfFiles) + ". " +
                                                         "Average size: " + Utility.ConvertToUsefulUnit(Stats.AverageFileSize) + ".";
                        }
                        else
                        {
                            toolStripStatusLabel2.Text = "";
                        }
                    }

                    conn.Close();
                }
                catch (Exception)
                {
                    dgMain.DataSource = null;

                    toolStripStatusLabel1.Text = "Cannot find table: \"" + aTableName + "\"";

                    SetApplicationUserLogic(false);
                }
            }
            else
            {
                toolStripStatusLabel1.Text = "Cannot find database: \"" + GXinorbisSystem.XinorbisDatabasePath + "\"";

                MessageBox.Show("Error location a Folder History database.",
                                "X.Database",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);

                DisableApplicationUI();
            }
        }

        private void BuildViewFromTableNameODBC(string aTableName)
        {
            string sql = GetSql(aTableName, "");

            tbLastSQL.Text = sql;

            var conn = new OdbcConnection(tbXFODBCConnectionString.Text);

            try
            {
                conn.Open();

                DataSet ds = new DataSet();
                var da = new OdbcDataAdapter(sql, conn);

                da.Fill(ds);

                if (ds.Tables.Count != 0)
                {
                    dgMain.DataSource = ds.Tables[0].DefaultView;

                    SetApplicationUserLogic(true);

                    Stats.GenerateStats(ref dgMain);

                    toolStripStatusLabel1.Text = "Found " + ds.Tables[0].Rows.Count.ToString() + " records.";

                    if (Stats.HasRealData && miGatherStats.Checked)
                    {
                        toolStripStatusLabel2.Text = "Size of files: " + Utility.ConvertToUsefulUnit(Stats.SizeOfFiles) + ". " +
                                                     "Average size: " + Utility.ConvertToUsefulUnit(Stats.AverageFileSize) + ".";
                    }
                    else
                    {
                        toolStripStatusLabel2.Text = "";
                    }
                }

                conn.Close();
            }
            catch (Exception)
            {
                dgMain.DataSource = null;

                toolStripStatusLabel1.Text = "Cannot find table: \"" + aTableName + "\"";

                SetApplicationUserLogic(false);
            }
        }

        // ===============================================================================================================================
        // ===============================================================================================================================
        // == Alternative Structure ======================================================================================================
        // ===============================================================================================================================
        // ===============================================================================================================================

        private void button1_Click_1(object sender, EventArgs e)
        {
            if (tbASSystemTableName.Text != "")
            {
                if (rbASSQlite.Checked)
                {
                    BuildSystemTableSQlite();
                }
                else
                {
                    BuildSystemTableODBC();
                }
            }
        }

        private void BuildSystemTableSQlite()
        {
            if (File.Exists(GXinorbisSystem.XinorbisDatabasePath))
            {
                string sql = "SELECT * FROM \"" + tbASSystemTableName.Text + "\";";

                tbLastSQL.Text = sql;

                var conn = new SQLiteConnection("Data Source=" + GXinorbisSystem.XinorbisDatabasePath + ";Version=3;");

                try
                {
                    conn.Open();

                    DataSet ds = new DataSet();
                    var da = new SQLiteDataAdapter(sql, conn);

                    da.Fill(ds);

                    if (ds.Tables.Count != 0)
                    {
                        dgASSystem.DataSource = ds.Tables[0].DefaultView;

                        SetApplicationUserLogic(true);

                        Stats.GenerateStats(ref dgASSystem);

                        toolStripStatusLabel1.Text = "Found " + ds.Tables[0].Rows.Count.ToString() + " records.";

                        if (Stats.HasRealData && miGatherStats.Checked)
                        {
                            toolStripStatusLabel2.Text = "Size of files: " + Utility.ConvertToUsefulUnit(Stats.SizeOfFiles) + ". " +
                                                         "Average size: " + Utility.ConvertToUsefulUnit(Stats.AverageFileSize) + ".";
                        }
                        else
                        {
                            toolStripStatusLabel2.Text = "";
                        }
                    }

                    conn.Close();
                }
                catch (Exception)
                {
                    dgMain.DataSource = null;

                    toolStripStatusLabel1.Text = "Cannot find table: \"" + tbASSystemTableName.Text + "\"";

                    SetApplicationUserLogic(false);
                }
            }
            else
            {
                toolStripStatusLabel1.Text = "Cannot find database: \"" + GXinorbisSystem.XinorbisDatabasePath + "\"";

                MessageBox.Show("Error location a Folder History database.",
                                "X.Database",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);

                DisableApplicationUI();
            }
        }

        private void BuildSystemTableODBC()
        {
            string sql = "SELECT * FROM \"" + tbASSystemTableName.Text + "\";";

            var conn = new OdbcConnection(tbASODBCConnectionString.Text);

            try
            {
                conn.Open();

                DataSet ds = new DataSet();
                var da = new OdbcDataAdapter(sql, conn);

                da.Fill(ds);

                if (ds.Tables.Count != 0)
                {
                    dgASSystem.DataSource = ds.Tables[0].DefaultView;

                    SetApplicationUserLogic(true);

                    //Stats.GenerateStats(ref dgASSystem);

                    toolStripStatusLabel1.Text = "Found " + ds.Tables[0].Rows.Count.ToString() + " records.";

                    if (Stats.HasRealData && miGatherStats.Checked)
                    {
                    }
                    else
                    {
                        toolStripStatusLabel2.Text = "";
                    }
                }

                conn.Close();
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);

                dgASSystem.DataSource = null;

                toolStripStatusLabel1.Text = "Cannot find table: \"" + tbASSystemTableName.Text + "\"";

                SetApplicationUserLogic(false);
            }
        }

        private void dgASSystem_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            int rowIndex = dgASSystem.CurrentCell.RowIndex;

            if (rbASSQlite.Checked)
            {
                BuildViewFromTableNameSQlite(dgASSystem.Rows[rowIndex].Cells[0].Value.ToString(), dgASSystem.Rows[rowIndex].Cells[6].Value.ToString());
            }
            else
            { 
                BuildViewFromTableNameODBC(dgASSystem.Rows[rowIndex].Cells[0].Value.ToString(), dgASSystem.Rows[rowIndex].Cells[6].Value.ToString());
            }
        }

        private void BuildViewFromTableNameODBC(string aTableName, string aScanDate)
        {
            string sql = GetSql(aTableName, aScanDate);

            tbLastSQL.Text = sql;

            var conn = new OdbcConnection(tbXFODBCConnectionString.Text);

            try
            {
                conn.Open();

                DataSet ds = new DataSet();
                var da = new OdbcDataAdapter(sql, conn);

                da.Fill(ds);

                if (ds.Tables.Count != 0)
                {
                    dgMain.DataSource = ds.Tables[0].DefaultView;

                    SetApplicationUserLogic(true);

                    Stats.GenerateStats(ref dgMain);

                    toolStripStatusLabel1.Text = "Found " + ds.Tables[0].Rows.Count.ToString() + " records.";

                    if (Stats.HasRealData && miGatherStats.Checked)
                    {
                        toolStripStatusLabel2.Text = "Size of files: " + Utility.ConvertToUsefulUnit(Stats.SizeOfFiles) + ". " +
                                                     "Average size: " + Utility.ConvertToUsefulUnit(Stats.AverageFileSize) + ".";
                    }
                    else
                    {
                        toolStripStatusLabel2.Text = "";
                    }
                }

                conn.Close();
            }
            catch (Exception)
            {
                dgMain.DataSource = null;

                toolStripStatusLabel1.Text = "Cannot find table: \"" + aTableName + "\"";

                SetApplicationUserLogic(false);
            }
        }

        private void BuildViewFromTableNameSQlite(string aTableName, string aScanDate)
        {
            if (File.Exists(GXinorbisSystem.XinorbisDatabasePath))
            {
                string sql = GetSql(aTableName, aScanDate);

                tbLastSQL.Text = sql;

                var conn = new SQLiteConnection("Data Source=" + GXinorbisSystem.XinorbisDatabasePath + ";Version=3;");

                try
                {
                    conn.Open();

                    DataSet ds = new DataSet();
                    var da = new SQLiteDataAdapter(sql, conn);

                    da.Fill(ds);

                    if (ds.Tables.Count != 0)
                    {
                        dgMain.DataSource = ds.Tables[0].DefaultView;

                        SetApplicationUserLogic(true);

                        Stats.GenerateStats(ref dgMain);

                        toolStripStatusLabel1.Text = "Found " + ds.Tables[0].Rows.Count.ToString() + " records.";

                        if (Stats.HasRealData && miGatherStats.Checked)
                        {
                            toolStripStatusLabel2.Text = "Size of files: " + Utility.ConvertToUsefulUnit(Stats.SizeOfFiles) + ". " +
                                                         "Average size: " + Utility.ConvertToUsefulUnit(Stats.AverageFileSize) + ".";
                        }
                        else
                        {
                            toolStripStatusLabel2.Text = "";
                        }
                    }

                    conn.Close();
                }
                catch (Exception)
                {
                    dgMain.DataSource = null;

                    toolStripStatusLabel1.Text = "Cannot find table: \"" + aTableName + "\"";

                    SetApplicationUserLogic(false);
                }
            }
            else
            {
                toolStripStatusLabel1.Text = "Cannot find database: \"" + GXinorbisSystem.XinorbisDatabasePath + "\"";

                MessageBox.Show("Error location a Folder History database.",
                                "X.Database",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);

                DisableApplicationUI();
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {

        }
    }
}