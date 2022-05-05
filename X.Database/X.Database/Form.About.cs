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
using System.Windows.Forms;

namespace X.Database
{
    public partial class frmAbout : Form
    {
        public frmAbout()
        {
            InitializeComponent();

            lVersion.Text = Constants.xDVersion + " / " + Constants.xDDate;
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            LinkLabel ll = (LinkLabel)sender;

            Utility.OpenWebPage("http://" + ll.Text);
        }
    }
}