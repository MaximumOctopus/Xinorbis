using System;
using System.IO;
using System.IO.Compression;

static class Utility
{
    static public string GetArchiveFileName()
    {
        return GetXinorbisBackupPath() + "xinorbisbackup_" + String.Format("{0:yyyyMMddHHmmss}", DateTime.Now) + ".zip";
    }
    
    static public string GetXinorbisDataPath()
    {
        // =====================================================================================================
        // == first see if this is a portable installation, database will be "near" exe ========================
        // =====================================================================================================

        if (Directory.Exists(System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location + "\\System\\")))
        {
            if (File.Exists(System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location) + "\\System\\FolderHistory\\Database\\Xinorbis.db"))
            {
                return System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location) + "\\System\\";
            }
        }

        // =====================================================================================================
        // == it's not portable, probably, so lets look for the the standard folder location in \users\
        // =====================================================================================================

        string lDataPath = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + "\\xinorbis\\";

        if (Directory.Exists(lDataPath))
        {
            return lDataPath;
        }
        else
        {
            return string.Empty;
        }
    }

    static public string GetXinorbisBackupPath()
    {
        string lDataPath = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + "\\xinorbisbackup\\";

        if (!Directory.Exists(lDataPath))
        {
            Directory.CreateDirectory(lDataPath);
        }

        return lDataPath;
    }

    static public bool ZipFolder(string aFolderName, string aFilePath)
    {
        try
        {
            ZipFile.CreateFromDirectory(aFolderName, aFilePath);

            return true;
        }
        catch
        {
            return false;
        }
    }
}