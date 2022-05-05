//
// X.Database
//
// www.Xinorbis.com
// www.MaximumOctopus.com
//
// Download the latest source code from: www.MaximumOctopus.com/sourcecode.htm
//
// May 17th 2018
//


using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

public static class ExportToCSV
{
    public static void Export(ref System.Windows.Forms.DataGridView adataGridView, string aFileName)
    {
        var sb = new StringBuilder();

        var headers = adataGridView.Columns.Cast<DataGridViewColumn>();
        sb.AppendLine(string.Join(",", headers.Select(column => "\"" + column.HeaderText + "\"").ToArray()));

        foreach (DataGridViewRow row in adataGridView.Rows)
        {
            var cells = row.Cells.Cast<DataGridViewCell>();
            sb.AppendLine(string.Join(",", cells.Select(cell => "\"" + cell.Value + "\"").ToArray()));
        }

        System.IO.StreamWriter file = new System.IO.StreamWriter(aFileName);

        file.WriteLine(sb.ToString()); // "sb" is the StringBuilder

        file.Close();
    }
}