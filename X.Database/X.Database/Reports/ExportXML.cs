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

public static class ExportToXML
{
    public static void Export(ref DataGridView adataGridView, string aFileName)
    {
        var sb = new StringBuilder();

        List<String>  ViewHeaders = new List<String>();

        var headers = adataGridView.Columns.Cast<DataGridViewColumn>();

        foreach (DataGridViewColumn column in adataGridView.Columns)
        {
            ViewHeaders.Add(column.HeaderText);
        }

        // ===========================================================================================
        // ===========================================================================================

        sb.AppendLine("<?xml version=\"1.0\"?>");
        sb.AppendLine("<-- Generated with X.Database " + Constants.xDVersion + " -->");
        sb.AppendLine("<-- Paul Alan Freshney 2019 www.MaximumOctopus.com  www.xinorbis.com -->");
        sb.AppendLine("<x.database.report>");

        if (Stats.HasRealData)
        {
            sb.AppendLine("<stats>");

            sb.AppendLine("<sizeoffiles>" + Stats.SizeOfFiles.ToString() + "</sizeoffiles>");
            sb.AppendLine("<averagefilesize>" + Stats.AverageFileSize.ToString() + "</averagefilesize>");
            sb.AppendLine("<filecount>" + Stats.FileCount.ToString() + "</filecount>");
            sb.AppendLine("<foldercount>" + Stats.FolderCount.ToString() + "</foldercount>");

            sb.AppendLine("</stats>");
        }

        sb.AppendLine("<files>");

        foreach (DataGridViewRow row in adataGridView.Rows)
        {
            var cells = row.Cells.Cast<DataGridViewCell>();

            int i = 0;

            sb.AppendLine("<fileitem>");

            foreach (DataGridViewCell cell in cells)
            {
                sb.AppendLine("<" + ViewHeaders[i] + ">" + cell.Value + "</" + ViewHeaders[i] + ">");

                i++;
            }

            sb.AppendLine("</fileitem>");
        }

        sb.AppendLine("</files>");

        sb.AppendLine("</x.database.report>");

        // ===========================================================================================
        // ===========================================================================================

        System.IO.StreamWriter file = new System.IO.StreamWriter(aFileName);

        file.WriteLine(sb.ToString()); // "sb" is the StringBuilder

        file.Close();
    }
}