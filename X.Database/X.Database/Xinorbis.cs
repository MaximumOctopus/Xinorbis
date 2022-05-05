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
using System.IO;
using System.Windows.Forms;


public class Xinorbis
{
    private List<String> AvailablePC;
    public string XinorbisDataPath;
    public string XinorbisDatabasePath;

    public Xinorbis()
    {
        AvailablePC = new List<String>();

        XinorbisDataPath = GetXinorbisDataPath();

        if (XinorbisDataPath != "")
        {
            PopulatePCList(XinorbisDataPath + "FolderHistory");

            XinorbisDatabasePath = XinorbisDataPath + "FolderHistory\\Database\\Xinorbis.db";
        }
        else
        {
            XinorbisDatabasePath = "";
        }
    }

    public int GetPCCount()
    {
        return AvailablePC.Count;
    }

    public string GetPCItem(int aIndex)
    {
        return AvailablePC[aIndex];
    }

    private string GetXinorbisDataPath()
    {
        // =====================================================================================================
        // == first see if this is a portable installation, database will be "near" exe ========================
        // =====================================================================================================

        if (Directory.Exists(System.IO.Path.GetDirectoryName(Application.ExecutablePath) + "\\System\\"))
        {
            if (File.Exists(System.IO.Path.GetDirectoryName(Application.ExecutablePath) + "\\System\\FolderHistory\\Database\\Xinorbis.db"))
            {
                return System.IO.Path.GetDirectoryName(Application.ExecutablePath) + "\\System\\";
            }
        }

        // =====================================================================================================
        // == first see if this is a portable installation, database will be "near" exe ========================
        // =====================================================================================================

        string lDataPath = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + "\\xinorbis\\";

        if (Directory.Exists(lDataPath))
        {
            return lDataPath;
        }
        else
        {
            return "";
        }
    }

    private void PopulatePCList(string aFolder)
    {
        DirectoryInfo diReportFolder = new DirectoryInfo(aFolder);

        try
        {
            foreach (var lFolder in diReportFolder.EnumerateDirectories())
            {
                try
                {
                    if (lFolder.Name != "Database")
                    {
                        AvailablePC.Add(lFolder.Name);
                    }
                }
                catch (UnauthorizedAccessException UnAuthTop)
                {
                    Console.WriteLine("{0}", UnAuthTop.Message);
                }
            }
        }
        catch (UnauthorizedAccessException UnAuthDir)
        {
            Console.WriteLine("UnAuthDir: {0}", UnAuthDir.Message);
        }
    }
}