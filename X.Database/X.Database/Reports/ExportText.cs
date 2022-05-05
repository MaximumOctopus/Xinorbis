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


using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

public static class ExportToText
{
    public static void Export(ref DataGridView adataGridView, string aFileName)
    {
        var sb = new StringBuilder();

        int filenameHeader = -1;
        int sizeHeader     = -1;

        List<String> ViewHeaders = new List<String>();

        var headers = adataGridView.Columns.Cast<DataGridViewColumn>();

        foreach (DataGridViewColumn column in adataGridView.Columns)
        {
            ViewHeaders.Add(column.HeaderText);

            if (column.HeaderText == "FileName")
                filenameHeader = column.Index;

            if (column.HeaderText == "FileSize")
                sizeHeader = column.Index;
        }

        // ===========================================================================================
        // ===========================================================================================

        for (int i = 0; i < adataGridView.Rows.Count; i++)
        {
            string output = "";

            if (filenameHeader != -1)
            {
                output = adataGridView.Rows[i].Cells[filenameHeader].Value.ToString();
            }

            if (sizeHeader != -1)
            {
                output += "  (" + adataGridView.Rows[i].Cells[sizeHeader].Value.ToString() + ")";
            }

            if (output != "")
            {
                sb.AppendLine(output);
            }
        }

        // ===========================================================================================
        // ===========================================================================================

        System.IO.StreamWriter file = new System.IO.StreamWriter(aFileName);

        file.WriteLine(sb.ToString()); // "sb" is the StringBuilder

        file.Close();
    }
}