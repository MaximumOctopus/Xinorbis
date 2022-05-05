using System;
using System.Diagnostics;
using System.IO;

public static class Utility
{
    public static void OpenWebPage(string aWebSiteURL)
    {
        Process.Start(aWebSiteURL);
    }

    public static string GetFileSize(string aPath)
    {
        if (File.Exists(aPath))
        {
            long length = new FileInfo(aPath).Length;

            length = length / (1024 * 1024); // convert to MB

            return length.ToString() + "MB";
        }
        else
        {
            return "n/a";
        }
    }

    public static string GetFileVersion(string aPath)
    {
        FileVersionInfo myFileVersionInfo = FileVersionInfo.GetVersionInfo(aPath);

        return myFileVersionInfo.FileDescription + " \\ " + myFileVersionInfo.FileVersion;
    }

    public static string FolderIntegrity(string aPath)
    {
        if (Directory.Exists(aPath))
        {
            return "[ OK ] " + aPath;
        }
        else
        {
            return "[ ?? ] " + aPath;
        }        
    }

    public static string FileIntegrity(string aFile)
    {
        if (File.Exists(aFile))
        {
            return "[ OK ] " + aFile;
        }
        else
        {
            return "[ ?? ] " + aFile;
        }
    }

    public static string GetCurrentUserName()
    {
        return Environment.MachineName;
    }
}