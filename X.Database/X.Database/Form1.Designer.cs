namespace X.Database
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miExit = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lastSQLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miGatherStats = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripSeparator();
            this.xinorbisHomeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.panel2 = new System.Windows.Forms.Panel();
            this.dgMain = new System.Windows.Forms.DataGridView();
            this.panel3 = new System.Windows.Forms.Panel();
            this.bExportText = new System.Windows.Forms.Button();
            this.bExportXML = new System.Windows.Forms.Button();
            this.bExportCSV = new System.Windows.Forms.Button();
            this.pLastSQL = new System.Windows.Forms.Panel();
            this.tbLastSQL = new System.Windows.Forms.TextBox();
            this.tcFilter = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.rbFilterOther = new System.Windows.Forms.RadioButton();
            this.rbFilterAttributes = new System.Windows.Forms.RadioButton();
            this.rbFilterDates = new System.Windows.Forms.RadioButton();
            this.rbFilterSizes = new System.Windows.Forms.RadioButton();
            this.rbFilterAll = new System.Windows.Forms.RadioButton();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.tbFilterSQL = new System.Windows.Forms.TextBox();
            this.cbFilterSQL = new System.Windows.Forms.CheckBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.cbSQLQuerySelect = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.tbSQLQueryWhere = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.tcFormatSelect = new System.Windows.Forms.TabControl();
            this.tabPage5 = new System.Windows.Forms.TabPage();
            this.label1 = new System.Windows.Forms.Label();
            this.tbFHPath = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.cbAvailablePCs = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.lTableName = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cbScanDateList = new System.Windows.Forms.ComboBox();
            this.cbScanPathList = new System.Windows.Forms.ComboBox();
            this.bSelect = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.tbXFODBCConnectionString = new System.Windows.Forms.TextBox();
            this.rbXFODBC = new System.Windows.Forms.RadioButton();
            this.rbXFSQlite = new System.Windows.Forms.RadioButton();
            this.tabPage6 = new System.Windows.Forms.TabPage();
            this.dgASSystem = new System.Windows.Forms.DataGridView();
            this.bASSelect = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.tbASSystemTableName = new System.Windows.Forms.TextBox();
            this.tbASODBCConnectionString = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.rbASODBC = new System.Windows.Forms.RadioButton();
            this.rbASSQlite = new System.Windows.Forms.RadioButton();
            this.statusStrip.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgMain)).BeginInit();
            this.panel3.SuspendLayout();
            this.pLastSQL.SuspendLayout();
            this.tcFilter.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.panel1.SuspendLayout();
            this.tcFormatSelect.SuspendLayout();
            this.tabPage5.SuspendLayout();
            this.tabPage6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgASSystem)).BeginInit();
            this.SuspendLayout();
            // 
            // statusStrip
            // 
            this.statusStrip.BackColor = System.Drawing.Color.White;
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.toolStripStatusLabel2});
            this.statusStrip.Location = new System.Drawing.Point(0, 793);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(1164, 22);
            this.statusStrip.TabIndex = 2;
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.AutoSize = false;
            this.toolStripStatusLabel1.ImageTransparentColor = System.Drawing.SystemColors.Window;
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(400, 17);
            this.toolStripStatusLabel1.Text = ".";
            this.toolStripStatusLabel1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // toolStripStatusLabel2
            // 
            this.toolStripStatusLabel2.Name = "toolStripStatusLabel2";
            this.toolStripStatusLabel2.Size = new System.Drawing.Size(10, 17);
            this.toolStripStatusLabel2.Text = ".";
            this.toolStripStatusLabel2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1164, 24);
            this.menuStrip1.TabIndex = 11;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miExit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // miExit
            // 
            this.miExit.Name = "miExit";
            this.miExit.Size = new System.Drawing.Size(92, 22);
            this.miExit.Text = "Exit";
            this.miExit.Click += new System.EventHandler(this.miExit_Click);
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.lastSQLToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "View";
            // 
            // lastSQLToolStripMenuItem
            // 
            this.lastSQLToolStripMenuItem.Checked = true;
            this.lastSQLToolStripMenuItem.CheckOnClick = true;
            this.lastSQLToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.lastSQLToolStripMenuItem.Name = "lastSQLToolStripMenuItem";
            this.lastSQLToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.lastSQLToolStripMenuItem.Text = "Last SQL";
            this.lastSQLToolStripMenuItem.Click += new System.EventHandler(this.lastSQLToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miGatherStats});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(48, 20);
            this.toolsToolStripMenuItem.Text = "Tools";
            // 
            // miGatherStats
            // 
            this.miGatherStats.CheckOnClick = true;
            this.miGatherStats.Name = "miGatherStats";
            this.miGatherStats.Size = new System.Drawing.Size(136, 22);
            this.miGatherStats.Text = "Gather stats";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.helpToolStripMenuItem1,
            this.toolStripMenuItem2,
            this.xinorbisHomeToolStripMenuItem,
            this.toolStripMenuItem1,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // helpToolStripMenuItem1
            // 
            this.helpToolStripMenuItem1.Name = "helpToolStripMenuItem1";
            this.helpToolStripMenuItem1.Size = new System.Drawing.Size(153, 22);
            this.helpToolStripMenuItem1.Text = "Help";
            this.helpToolStripMenuItem1.Click += new System.EventHandler(this.helpToolStripMenuItem1_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(150, 6);
            // 
            // xinorbisHomeToolStripMenuItem
            // 
            this.xinorbisHomeToolStripMenuItem.Name = "xinorbisHomeToolStripMenuItem";
            this.xinorbisHomeToolStripMenuItem.Size = new System.Drawing.Size(153, 22);
            this.xinorbisHomeToolStripMenuItem.Text = "Xinorbis Home";
            this.xinorbisHomeToolStripMenuItem.Click += new System.EventHandler(this.xinorbisHomeToolStripMenuItem_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(150, 6);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(153, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.dgMain);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel2.Location = new System.Drawing.Point(0, 368);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1164, 361);
            this.panel2.TabIndex = 12;
            // 
            // dgMain
            // 
            this.dgMain.AllowUserToAddRows = false;
            this.dgMain.AllowUserToDeleteRows = false;
            this.dgMain.BackgroundColor = System.Drawing.SystemColors.ControlLight;
            this.dgMain.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgMain.Location = new System.Drawing.Point(0, 0);
            this.dgMain.MultiSelect = false;
            this.dgMain.Name = "dgMain";
            this.dgMain.ReadOnly = true;
            this.dgMain.Size = new System.Drawing.Size(1164, 361);
            this.dgMain.TabIndex = 3;
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.bExportText);
            this.panel3.Controls.Add(this.bExportXML);
            this.panel3.Controls.Add(this.bExportCSV);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel3.Location = new System.Drawing.Point(0, 757);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1164, 36);
            this.panel3.TabIndex = 12;
            // 
            // bExportText
            // 
            this.bExportText.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bExportText.Image = global::X.Database.Properties.Resources.ascii;
            this.bExportText.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.bExportText.Location = new System.Drawing.Point(84, 6);
            this.bExportText.Name = "bExportText";
            this.bExportText.Size = new System.Drawing.Size(75, 25);
            this.bExportText.TabIndex = 2;
            this.bExportText.Text = "Text";
            this.bExportText.UseVisualStyleBackColor = true;
            this.bExportText.Click += new System.EventHandler(this.button1_Click_2);
            // 
            // bExportXML
            // 
            this.bExportXML.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bExportXML.Image = global::X.Database.Properties.Resources.tag;
            this.bExportXML.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.bExportXML.Location = new System.Drawing.Point(165, 6);
            this.bExportXML.Name = "bExportXML";
            this.bExportXML.Size = new System.Drawing.Size(75, 25);
            this.bExportXML.TabIndex = 1;
            this.bExportXML.Text = "XML";
            this.bExportXML.UseVisualStyleBackColor = true;
            this.bExportXML.Click += new System.EventHandler(this.button2_Click);
            // 
            // bExportCSV
            // 
            this.bExportCSV.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bExportCSV.Image = global::X.Database.Properties.Resources.excel;
            this.bExportCSV.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.bExportCSV.Location = new System.Drawing.Point(3, 6);
            this.bExportCSV.Name = "bExportCSV";
            this.bExportCSV.Size = new System.Drawing.Size(75, 25);
            this.bExportCSV.TabIndex = 0;
            this.bExportCSV.Text = "CSV";
            this.bExportCSV.UseVisualStyleBackColor = true;
            this.bExportCSV.Click += new System.EventHandler(this.button1_Click);
            // 
            // pLastSQL
            // 
            this.pLastSQL.Controls.Add(this.tbLastSQL);
            this.pLastSQL.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pLastSQL.Location = new System.Drawing.Point(0, 729);
            this.pLastSQL.Name = "pLastSQL";
            this.pLastSQL.Size = new System.Drawing.Size(1164, 28);
            this.pLastSQL.TabIndex = 13;
            // 
            // tbLastSQL
            // 
            this.tbLastSQL.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbLastSQL.BackColor = System.Drawing.SystemColors.Window;
            this.tbLastSQL.Location = new System.Drawing.Point(3, 4);
            this.tbLastSQL.Name = "tbLastSQL";
            this.tbLastSQL.ReadOnly = true;
            this.tbLastSQL.Size = new System.Drawing.Size(1158, 20);
            this.tbLastSQL.TabIndex = 0;
            // 
            // tcFilter
            // 
            this.tcFilter.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tcFilter.Controls.Add(this.tabPage1);
            this.tcFilter.Controls.Add(this.tabPage2);
            this.tcFilter.Location = new System.Drawing.Point(9, 227);
            this.tcFilter.Name = "tcFilter";
            this.tcFilter.SelectedIndex = 0;
            this.tcFilter.Size = new System.Drawing.Size(1143, 105);
            this.tcFilter.TabIndex = 21;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.groupBox2);
            this.tabPage1.Controls.Add(this.groupBox3);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1135, 79);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Simple Filter";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.rbFilterOther);
            this.groupBox2.Controls.Add(this.rbFilterAttributes);
            this.groupBox2.Controls.Add(this.rbFilterDates);
            this.groupBox2.Controls.Add(this.rbFilterSizes);
            this.groupBox2.Controls.Add(this.rbFilterAll);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(6, 6);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(297, 65);
            this.groupBox2.TabIndex = 20;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Simple Field Filter";
            // 
            // rbFilterOther
            // 
            this.rbFilterOther.AutoSize = true;
            this.rbFilterOther.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbFilterOther.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbFilterOther.Location = new System.Drawing.Point(238, 29);
            this.rbFilterOther.Name = "rbFilterOther";
            this.rbFilterOther.Size = new System.Drawing.Size(50, 17);
            this.rbFilterOther.TabIndex = 4;
            this.rbFilterOther.Text = "Other";
            this.rbFilterOther.UseVisualStyleBackColor = true;
            this.rbFilterOther.CheckedChanged += new System.EventHandler(this.cbScanDateList_SelectedIndexChanged);
            this.rbFilterOther.Click += new System.EventHandler(this.rbXFSQlite_Click);
            // 
            // rbFilterAttributes
            // 
            this.rbFilterAttributes.AutoSize = true;
            this.rbFilterAttributes.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbFilterAttributes.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbFilterAttributes.Location = new System.Drawing.Point(163, 29);
            this.rbFilterAttributes.Name = "rbFilterAttributes";
            this.rbFilterAttributes.Size = new System.Drawing.Size(68, 17);
            this.rbFilterAttributes.TabIndex = 3;
            this.rbFilterAttributes.Text = "Attributes";
            this.rbFilterAttributes.UseVisualStyleBackColor = true;
            this.rbFilterAttributes.CheckedChanged += new System.EventHandler(this.cbScanDateList_SelectedIndexChanged);
            this.rbFilterAttributes.Click += new System.EventHandler(this.rbXFSQlite_Click);
            // 
            // rbFilterDates
            // 
            this.rbFilterDates.AutoSize = true;
            this.rbFilterDates.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbFilterDates.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbFilterDates.Location = new System.Drawing.Point(107, 29);
            this.rbFilterDates.Name = "rbFilterDates";
            this.rbFilterDates.Size = new System.Drawing.Size(52, 17);
            this.rbFilterDates.TabIndex = 2;
            this.rbFilterDates.Text = "Dates";
            this.rbFilterDates.UseVisualStyleBackColor = true;
            this.rbFilterDates.CheckedChanged += new System.EventHandler(this.cbScanDateList_SelectedIndexChanged);
            this.rbFilterDates.Click += new System.EventHandler(this.rbXFSQlite_Click);
            // 
            // rbFilterSizes
            // 
            this.rbFilterSizes.AutoSize = true;
            this.rbFilterSizes.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbFilterSizes.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbFilterSizes.Location = new System.Drawing.Point(51, 29);
            this.rbFilterSizes.Name = "rbFilterSizes";
            this.rbFilterSizes.Size = new System.Drawing.Size(49, 17);
            this.rbFilterSizes.TabIndex = 1;
            this.rbFilterSizes.Text = "Sizes";
            this.rbFilterSizes.UseVisualStyleBackColor = true;
            this.rbFilterSizes.CheckedChanged += new System.EventHandler(this.cbScanDateList_SelectedIndexChanged);
            this.rbFilterSizes.Click += new System.EventHandler(this.rbXFSQlite_Click);
            // 
            // rbFilterAll
            // 
            this.rbFilterAll.AutoSize = true;
            this.rbFilterAll.Checked = true;
            this.rbFilterAll.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbFilterAll.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbFilterAll.Location = new System.Drawing.Point(9, 29);
            this.rbFilterAll.Name = "rbFilterAll";
            this.rbFilterAll.Size = new System.Drawing.Size(35, 17);
            this.rbFilterAll.TabIndex = 0;
            this.rbFilterAll.TabStop = true;
            this.rbFilterAll.Text = "All";
            this.rbFilterAll.UseVisualStyleBackColor = true;
            this.rbFilterAll.Click += new System.EventHandler(this.rbXFSQlite_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox3.Controls.Add(this.tbFilterSQL);
            this.groupBox3.Controls.Add(this.cbFilterSQL);
            this.groupBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox3.Location = new System.Drawing.Point(309, 6);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(816, 65);
            this.groupBox3.TabIndex = 20;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Filter with SQL (WHERE)";
            // 
            // tbFilterSQL
            // 
            this.tbFilterSQL.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbFilterSQL.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbFilterSQL.Location = new System.Drawing.Point(30, 28);
            this.tbFilterSQL.Name = "tbFilterSQL";
            this.tbFilterSQL.Size = new System.Drawing.Size(780, 20);
            this.tbFilterSQL.TabIndex = 1;
            this.tbFilterSQL.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.cbSQLQuerySelect_KeyPress);
            // 
            // cbFilterSQL
            // 
            this.cbFilterSQL.AutoSize = true;
            this.cbFilterSQL.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cbFilterSQL.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbFilterSQL.Location = new System.Drawing.Point(8, 30);
            this.cbFilterSQL.Name = "cbFilterSQL";
            this.cbFilterSQL.Size = new System.Drawing.Size(12, 11);
            this.cbFilterSQL.TabIndex = 0;
            this.cbFilterSQL.UseVisualStyleBackColor = true;
            this.cbFilterSQL.CheckedChanged += new System.EventHandler(this.cbScanPathList_SelectedIndexChanged);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.cbSQLQuerySelect);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.tbSQLQueryWhere);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.tabPage2.Size = new System.Drawing.Size(1135, 79);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "SQL Query";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // cbSQLQuerySelect
            // 
            this.cbSQLQuerySelect.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.cbSQLQuerySelect.FormattingEnabled = true;
            this.cbSQLQuerySelect.Items.AddRange(new object[] {
            "*",
            "FilePath, FileName, FileSize, FileSizeDisk",
            "FilePath, FileName, Directory, FileDateC, FileDateA, FileDateM",
            "FilePath, FileName, Directory, Readonly, Hidden, System, Archive, Temp",
            "FilePath, FileName, Directory, Category, Owner"});
            this.cbSQLQuerySelect.Location = new System.Drawing.Point(68, 14);
            this.cbSQLQuerySelect.Name = "cbSQLQuerySelect";
            this.cbSQLQuerySelect.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.cbSQLQuerySelect.Size = new System.Drawing.Size(1308, 21);
            this.cbSQLQuerySelect.TabIndex = 7;
            this.cbSQLQuerySelect.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.cbSQLQuerySelect_KeyPress);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(14, 44);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(48, 13);
            this.label7.TabIndex = 6;
            this.label7.Text = "WHERE";
            // 
            // tbSQLQueryWhere
            // 
            this.tbSQLQueryWhere.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbSQLQueryWhere.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbSQLQueryWhere.Location = new System.Drawing.Point(68, 41);
            this.tbSQLQueryWhere.Name = "tbSQLQueryWhere";
            this.tbSQLQueryWhere.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.tbSQLQueryWhere.Size = new System.Drawing.Size(1308, 20);
            this.tbSQLQueryWhere.TabIndex = 5;
            this.tbSQLQueryWhere.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.cbSQLQuerySelect_KeyPress);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(14, 18);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(48, 13);
            this.label6.TabIndex = 4;
            this.label6.Text = "SELECT";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.tcFormatSelect);
            this.panel1.Controls.Add(this.tcFilter);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 24);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1164, 344);
            this.panel1.TabIndex = 10;
            // 
            // tcFormatSelect
            // 
            this.tcFormatSelect.Controls.Add(this.tabPage5);
            this.tcFormatSelect.Controls.Add(this.tabPage6);
            this.tcFormatSelect.Location = new System.Drawing.Point(9, 14);
            this.tcFormatSelect.Name = "tcFormatSelect";
            this.tcFormatSelect.SelectedIndex = 0;
            this.tcFormatSelect.Size = new System.Drawing.Size(1143, 207);
            this.tcFormatSelect.TabIndex = 23;
            this.tcFormatSelect.SelectedIndexChanged += new System.EventHandler(this.tabControl2_SelectedIndexChanged);
            // 
            // tabPage5
            // 
            this.tabPage5.Controls.Add(this.label1);
            this.tabPage5.Controls.Add(this.tbFHPath);
            this.tabPage5.Controls.Add(this.label4);
            this.tabPage5.Controls.Add(this.cbAvailablePCs);
            this.tabPage5.Controls.Add(this.label5);
            this.tabPage5.Controls.Add(this.lTableName);
            this.tabPage5.Controls.Add(this.label3);
            this.tabPage5.Controls.Add(this.label2);
            this.tabPage5.Controls.Add(this.cbScanDateList);
            this.tabPage5.Controls.Add(this.cbScanPathList);
            this.tabPage5.Controls.Add(this.bSelect);
            this.tabPage5.Controls.Add(this.label9);
            this.tabPage5.Controls.Add(this.tbXFODBCConnectionString);
            this.tabPage5.Controls.Add(this.rbXFODBC);
            this.tabPage5.Controls.Add(this.rbXFSQlite);
            this.tabPage5.Location = new System.Drawing.Point(4, 22);
            this.tabPage5.Name = "tabPage5";
            this.tabPage5.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage5.Size = new System.Drawing.Size(1135, 181);
            this.tabPage5.TabIndex = 0;
            this.tabPage5.Text = "Xinorbis Format";
            this.tabPage5.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 57);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(147, 13);
            this.label1.TabIndex = 39;
            this.label1.Text = "Path to \"Folder History\" folder";
            // 
            // tbFHPath
            // 
            this.tbFHPath.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbFHPath.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbFHPath.Location = new System.Drawing.Point(15, 74);
            this.tbFHPath.Name = "tbFHPath";
            this.tbFHPath.Size = new System.Drawing.Size(849, 20);
            this.tbFHPath.TabIndex = 38;
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(866, 57);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 13);
            this.label4.TabIndex = 37;
            this.label4.Text = "Computer";
            // 
            // cbAvailablePCs
            // 
            this.cbAvailablePCs.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.cbAvailablePCs.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbAvailablePCs.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cbAvailablePCs.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbAvailablePCs.FormattingEnabled = true;
            this.cbAvailablePCs.Location = new System.Drawing.Point(869, 73);
            this.cbAvailablePCs.Name = "cbAvailablePCs";
            this.cbAvailablePCs.Size = new System.Drawing.Size(167, 21);
            this.cbAvailablePCs.TabIndex = 36;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(650, 105);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(64, 13);
            this.label5.TabIndex = 35;
            this.label5.Text = "Using Table";
            // 
            // lTableName
            // 
            this.lTableName.AutoSize = true;
            this.lTableName.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lTableName.Location = new System.Drawing.Point(650, 124);
            this.lTableName.Name = "lTableName";
            this.lTableName.Size = new System.Drawing.Size(19, 13);
            this.lTableName.TabIndex = 34;
            this.lTableName.Text = "....";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(504, 105);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(109, 13);
            this.label3.TabIndex = 33;
            this.label3.Text = "Available Scan Dates";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(11, 105);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(108, 13);
            this.label2.TabIndex = 32;
            this.label2.Text = "Available Scan Paths";
            // 
            // cbScanDateList
            // 
            this.cbScanDateList.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbScanDateList.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cbScanDateList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbScanDateList.FormattingEnabled = true;
            this.cbScanDateList.Location = new System.Drawing.Point(507, 121);
            this.cbScanDateList.Name = "cbScanDateList";
            this.cbScanDateList.Size = new System.Drawing.Size(130, 21);
            this.cbScanDateList.TabIndex = 31;
            this.cbScanDateList.SelectedValueChanged += new System.EventHandler(this.cbScanDateList_SelectedIndexChanged);
            // 
            // cbScanPathList
            // 
            this.cbScanPathList.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbScanPathList.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cbScanPathList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbScanPathList.FormattingEnabled = true;
            this.cbScanPathList.Location = new System.Drawing.Point(14, 121);
            this.cbScanPathList.Name = "cbScanPathList";
            this.cbScanPathList.Size = new System.Drawing.Size(487, 21);
            this.cbScanPathList.TabIndex = 30;
            this.cbScanPathList.SelectedValueChanged += new System.EventHandler(this.cbScanPathList_SelectedIndexChanged);
            // 
            // bSelect
            // 
            this.bSelect.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.bSelect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bSelect.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bSelect.Location = new System.Drawing.Point(1041, 73);
            this.bSelect.Name = "bSelect";
            this.bSelect.Size = new System.Drawing.Size(83, 23);
            this.bSelect.TabIndex = 29;
            this.bSelect.Text = "Select";
            this.bSelect.UseVisualStyleBackColor = true;
            this.bSelect.Click += new System.EventHandler(this.bSelect_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(132, 8);
            this.label9.Name = "label9";
            this.label9.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label9.Size = new System.Drawing.Size(124, 13);
            this.label9.TabIndex = 21;
            this.label9.Text = "ODBC Connection String";
            // 
            // tbXFODBCConnectionString
            // 
            this.tbXFODBCConnectionString.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbXFODBCConnectionString.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbXFODBCConnectionString.Location = new System.Drawing.Point(135, 25);
            this.tbXFODBCConnectionString.Name = "tbXFODBCConnectionString";
            this.tbXFODBCConnectionString.Size = new System.Drawing.Size(992, 20);
            this.tbXFODBCConnectionString.TabIndex = 20;
            // 
            // rbXFODBC
            // 
            this.rbXFODBC.AutoSize = true;
            this.rbXFODBC.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbXFODBC.Location = new System.Drawing.Point(71, 25);
            this.rbXFODBC.Name = "rbXFODBC";
            this.rbXFODBC.Size = new System.Drawing.Size(54, 17);
            this.rbXFODBC.TabIndex = 1;
            this.rbXFODBC.Text = "ODBC";
            this.rbXFODBC.UseVisualStyleBackColor = true;
            this.rbXFODBC.Click += new System.EventHandler(this.rbXFSQlite_Click);
            // 
            // rbXFSQlite
            // 
            this.rbXFSQlite.AutoSize = true;
            this.rbXFSQlite.Checked = true;
            this.rbXFSQlite.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbXFSQlite.Location = new System.Drawing.Point(11, 25);
            this.rbXFSQlite.Name = "rbXFSQlite";
            this.rbXFSQlite.Size = new System.Drawing.Size(52, 17);
            this.rbXFSQlite.TabIndex = 0;
            this.rbXFSQlite.TabStop = true;
            this.rbXFSQlite.Text = "SQlite";
            this.rbXFSQlite.UseVisualStyleBackColor = true;
            this.rbXFSQlite.Click += new System.EventHandler(this.rbXFSQlite_Click);
            // 
            // tabPage6
            // 
            this.tabPage6.Controls.Add(this.dgASSystem);
            this.tabPage6.Controls.Add(this.bASSelect);
            this.tabPage6.Controls.Add(this.label10);
            this.tabPage6.Controls.Add(this.tbASSystemTableName);
            this.tabPage6.Controls.Add(this.tbASODBCConnectionString);
            this.tabPage6.Controls.Add(this.label8);
            this.tabPage6.Controls.Add(this.rbASODBC);
            this.tabPage6.Controls.Add(this.rbASSQlite);
            this.tabPage6.Location = new System.Drawing.Point(4, 22);
            this.tabPage6.Name = "tabPage6";
            this.tabPage6.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage6.Size = new System.Drawing.Size(1135, 181);
            this.tabPage6.TabIndex = 1;
            this.tabPage6.Text = "Alternative Structure";
            this.tabPage6.UseVisualStyleBackColor = true;
            // 
            // dgASSystem
            // 
            this.dgASSystem.AllowUserToAddRows = false;
            this.dgASSystem.AllowUserToDeleteRows = false;
            this.dgASSystem.BackgroundColor = System.Drawing.SystemColors.ControlLight;
            this.dgASSystem.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgASSystem.Location = new System.Drawing.Point(280, 57);
            this.dgASSystem.Name = "dgASSystem";
            this.dgASSystem.ReadOnly = true;
            this.dgASSystem.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgASSystem.Size = new System.Drawing.Size(839, 106);
            this.dgASSystem.TabIndex = 43;
            this.dgASSystem.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgASSystem_CellDoubleClick);
            // 
            // bASSelect
            // 
            this.bASSelect.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.bASSelect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bASSelect.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bASSelect.Location = new System.Drawing.Point(172, 71);
            this.bASSelect.Name = "bASSelect";
            this.bASSelect.Size = new System.Drawing.Size(83, 23);
            this.bASSelect.TabIndex = 42;
            this.bASSelect.Text = "Select";
            this.bASSelect.UseVisualStyleBackColor = true;
            this.bASSelect.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(12, 57);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(112, 13);
            this.label10.TabIndex = 41;
            this.label10.Text = "\"System\" Table Name";
            // 
            // tbASSystemTableName
            // 
            this.tbASSystemTableName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbASSystemTableName.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbASSystemTableName.Location = new System.Drawing.Point(15, 74);
            this.tbASSystemTableName.Name = "tbASSystemTableName";
            this.tbASSystemTableName.Size = new System.Drawing.Size(151, 20);
            this.tbASSystemTableName.TabIndex = 40;
            this.tbASSystemTableName.Text = "XinorbisSystem";
            // 
            // tbASODBCConnectionString
            // 
            this.tbASODBCConnectionString.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbASODBCConnectionString.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbASODBCConnectionString.Location = new System.Drawing.Point(135, 25);
            this.tbASODBCConnectionString.Name = "tbASODBCConnectionString";
            this.tbASODBCConnectionString.Size = new System.Drawing.Size(992, 20);
            this.tbASODBCConnectionString.TabIndex = 23;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(132, 8);
            this.label8.Name = "label8";
            this.label8.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label8.Size = new System.Drawing.Size(124, 13);
            this.label8.TabIndex = 22;
            this.label8.Text = "ODBC Connection String";
            // 
            // rbASODBC
            // 
            this.rbASODBC.AutoSize = true;
            this.rbASODBC.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbASODBC.Location = new System.Drawing.Point(71, 25);
            this.rbASODBC.Name = "rbASODBC";
            this.rbASODBC.Size = new System.Drawing.Size(54, 17);
            this.rbASODBC.TabIndex = 2;
            this.rbASODBC.Text = "ODBC";
            this.rbASODBC.UseVisualStyleBackColor = true;
            // 
            // rbASSQlite
            // 
            this.rbASSQlite.AutoSize = true;
            this.rbASSQlite.Checked = true;
            this.rbASSQlite.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rbASSQlite.Location = new System.Drawing.Point(11, 25);
            this.rbASSQlite.Name = "rbASSQlite";
            this.rbASSQlite.Size = new System.Drawing.Size(52, 17);
            this.rbASSQlite.TabIndex = 1;
            this.rbASSQlite.TabStop = true;
            this.rbASSQlite.Text = "SQlite";
            this.rbASSQlite.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(1164, 815);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.pLastSQL);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.statusStrip);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(1180, 800);
            this.Name = "Form1";
            this.Text = ".";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgMain)).EndInit();
            this.panel3.ResumeLayout(false);
            this.pLastSQL.ResumeLayout(false);
            this.pLastSQL.PerformLayout();
            this.tcFilter.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.tcFormatSelect.ResumeLayout(false);
            this.tabPage5.ResumeLayout(false);
            this.tabPage5.PerformLayout();
            this.tabPage6.ResumeLayout(false);
            this.tabPage6.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgASSystem)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem miExit;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.DataGridView dgMain;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Button bExportCSV;
        private System.Windows.Forms.Button bExportXML;
        private System.Windows.Forms.ToolStripMenuItem xinorbisHomeToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem2;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel2;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem miGatherStats;
        private System.Windows.Forms.Panel pLastSQL;
        private System.Windows.Forms.TextBox tbLastSQL;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lastSQLToolStripMenuItem;
        private System.Windows.Forms.TabControl tcFilter;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton rbFilterOther;
        private System.Windows.Forms.RadioButton rbFilterAttributes;
        private System.Windows.Forms.RadioButton rbFilterDates;
        private System.Windows.Forms.RadioButton rbFilterSizes;
        private System.Windows.Forms.RadioButton rbFilterAll;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox tbFilterSQL;
        private System.Windows.Forms.CheckBox cbFilterSQL;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.ComboBox cbSQLQuerySelect;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox tbSQLQueryWhere;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TabControl tcFormatSelect;
        private System.Windows.Forms.TabPage tabPage5;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbFHPath;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox cbAvailablePCs;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lTableName;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbScanDateList;
        private System.Windows.Forms.ComboBox cbScanPathList;
        private System.Windows.Forms.Button bSelect;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox tbXFODBCConnectionString;
        private System.Windows.Forms.RadioButton rbXFODBC;
        private System.Windows.Forms.RadioButton rbXFSQlite;
        private System.Windows.Forms.TabPage tabPage6;
        private System.Windows.Forms.DataGridView dgASSystem;
        private System.Windows.Forms.Button bASSelect;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox tbASSystemTableName;
        private System.Windows.Forms.TextBox tbASODBCConnectionString;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.RadioButton rbASODBC;
        private System.Windows.Forms.RadioButton rbASSQlite;
        private System.Windows.Forms.Button bExportText;
    }
}

