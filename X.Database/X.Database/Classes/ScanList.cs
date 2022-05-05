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


public class ScanList
{
    private List<ScanListObject> ScanListObjects;

    public ScanList()
    {
        ScanListObjects = new List<ScanListObject>();
    }

    public void NewReportFolder(string aFolder)
    {
        if (Directory.Exists(aFolder))
        {
            ScanListObjects.Clear();

            ProcessFolder(aFolder);
        }
        else
        {

        }
    }

    public int ItemCount()
    {
        return ScanListObjects.Count;
    }


    public ScanListObject Item(int aIndex)
    {
        if ((aIndex >= 0) && (aIndex < ScanListObjects.Count))
        {
            return ScanListObjects[aIndex];
        }
        else
        {
            return null;
        }    
    }


    private void ProcessFolder(string aFolder)
    {
        DirectoryInfo diReportFolder = new DirectoryInfo(aFolder);

        try
        {
            foreach (var lFile in diReportFolder.EnumerateFiles())
            {
                try
                {
                    var lFileNameNoExt = Path.GetFileNameWithoutExtension(lFile.Name);
                    var lScanPath = ProcessFile(lFile.FullName);

                    if ((lFileNameNoExt != "") && (lScanPath != ""))
                    {
                        ScanListObjects.Add(new ScanListObject(lFileNameNoExt, lScanPath, lFile.FullName));
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

    private string ProcessFile(string aFileName)
    {
        string lFirstLine;
        string lScanPath;

        StreamReader file = new StreamReader(aFileName);

        if ((lFirstLine = file.ReadLine()) != null)
        {
            lScanPath = lFirstLine;
        }
        else
        {
            lScanPath = "";
        }

        file.Close();

        return lScanPath;
    }
}