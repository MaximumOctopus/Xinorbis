namespace X.Diagnostic
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
            this.rtbMain = new System.Windows.Forms.RichTextBox();
            this.bRun = new System.Windows.Forms.Button();
            this.bCopy = new System.Windows.Forms.Button();
            this.bSave = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.sfdMain = new System.Windows.Forms.SaveFileDialog();
            this.SuspendLayout();
            // 
            // rtbMain
            // 
            this.rtbMain.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.rtbMain.Font = new System.Drawing.Font("Courier New", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rtbMain.Location = new System.Drawing.Point(133, 12);
            this.rtbMain.Name = "rtbMain";
            this.rtbMain.Size = new System.Drawing.Size(859, 404);
            this.rtbMain.TabIndex = 1;
            this.rtbMain.Text = "To get the most from this application, run it from within the Xinorbis install fo" +
    "lder.";
            // 
            // bRun
            // 
            this.bRun.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bRun.Location = new System.Drawing.Point(12, 12);
            this.bRun.Name = "bRun";
            this.bRun.Size = new System.Drawing.Size(115, 26);
            this.bRun.TabIndex = 2;
            this.bRun.Text = "Run Diagnostics";
            this.bRun.UseVisualStyleBackColor = true;
            this.bRun.Click += new System.EventHandler(this.button1_Click);
            // 
            // bCopy
            // 
            this.bCopy.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bCopy.Image = global::X.Diagnostic.Properties.Resources.page_paste;
            this.bCopy.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.bCopy.Location = new System.Drawing.Point(12, 91);
            this.bCopy.Name = "bCopy";
            this.bCopy.Size = new System.Drawing.Size(115, 26);
            this.bCopy.TabIndex = 4;
            this.bCopy.Text = "Copy";
            this.bCopy.UseVisualStyleBackColor = true;
            this.bCopy.Click += new System.EventHandler(this.bCopy_Click);
            // 
            // bSave
            // 
            this.bSave.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bSave.Image = global::X.Diagnostic.Properties.Resources.disk;
            this.bSave.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.bSave.Location = new System.Drawing.Point(12, 59);
            this.bSave.Name = "bSave";
            this.bSave.Size = new System.Drawing.Size(115, 26);
            this.bSave.TabIndex = 3;
            this.bSave.Text = "Save";
            this.bSave.UseVisualStyleBackColor = true;
            this.bSave.Click += new System.EventHandler(this.bSave_Click);
            // 
            // button1
            // 
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Image = global::X.Diagnostic.Properties.Resources.user_orange;
            this.button1.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.button1.Location = new System.Drawing.Point(12, 390);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(115, 26);
            this.button1.TabIndex = 5;
            this.button1.Text = "About";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // sfdMain
            // 
            this.sfdMain.Filter = "txt files (*.txt)|*.txt";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1004, 428);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.bCopy);
            this.Controls.Add(this.bSave);
            this.Controls.Add(this.bRun);
            this.Controls.Add(this.rtbMain);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(1020, 466);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.RichTextBox rtbMain;
        private System.Windows.Forms.Button bRun;
        private System.Windows.Forms.Button bSave;
        private System.Windows.Forms.Button bCopy;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.SaveFileDialog sfdMain;
    }
}

