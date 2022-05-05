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

    // aVersion:
    //  32 or 64
    public string GetExeNameVersion(string aVersion)
    {
        if (File.Exists(Application.StartupPath + "\\x8." + aVersion + ".exe"))
        {
            string lFileName = Application.StartupPath + "\\x8." + aVersion + ".exe";

            return aVersion + " bit, " + Utility.GetFileSize(lFileName) + ", " + Utility.GetFileVersion(lFileName);
        }
        else
        {
            return "Xinorbis " + aVersion + " bit executable not found.";
        }
    }

    public string GetDatabaseDetails()
    {
        if (XinorbisDatabasePath != "")
        {
            if (File.Exists(XinorbisDatabasePath))
            {
                return XinorbisDatabasePath + " {" + Utility.GetFileSize(XinorbisDatabasePath) + "}";
            }
            else
            {
                return "Database file does not exist.";
            }
        }
        else
        {
            return "No database path file found.";
        }
    }

    public string GetRegistrationDetails()
    {
        if (File.Exists(XinorbisDataPath + "\\registration.data"))
        {
            return "Pro version: " + GetRegistrationUser(XinorbisDataPath + "\\registration.data");
        }
        else
        {
            return "Free version.";
        }
    }

    public string GetRegistrationUser(string aFileName)
    {
        string lName;
        string lEmail;
        string lCode;

        StreamReader file = new StreamReader(aFileName);

        lName  = file.ReadLine();
        lEmail = file.ReadLine();
        lCode  = file.ReadLine();
        
        file.Close();

        return lName + " \\ " + lEmail + " \\ " + lCode;
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