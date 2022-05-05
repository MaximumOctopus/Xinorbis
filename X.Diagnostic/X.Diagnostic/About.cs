using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace X.Diagnostic
{
    public partial class frmAbout : Form
    {
        public frmAbout()
        {
            InitializeComponent();

            lVersion.Text = Constants.xDVersion + " :: " + Constants.xDDate;
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            LinkLabel ll = (LinkLabel)sender;

            Utility.OpenWebPage("http://" + ll.Text);
        }
    }
}