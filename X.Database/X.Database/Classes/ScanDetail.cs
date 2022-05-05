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


using System.Collections.Generic;
using System.IO;


public class ScanDetail
{
    private List<ScanDetailObject> ScanDetailObjects;

    public ScanDetail()
    {
        ScanDetailObjects = new List<ScanDetailObject>();
    }

    public int NewReportFile(string aFile)
    {
        if (File.Exists(aFile))
        {
            ScanDetailObjects.Clear();

            return ProcessFile(aFile);
        }
        else
        {
            return 0;
        }
    }
    
    public int ItemCount()
    {
        return ScanDetailObjects.Count;
    }
    
    public ScanDetailObject Item(int aIndex)
    {
        return ScanDetailObjects[aIndex];
    }
    
    private int ProcessFile(string aFileName)
    {
        string lLine;

        ScanDetailObjects.Clear();

        StreamReader file = new StreamReader(aFileName);

        while ((lLine = file.ReadLine()) != null)
        {
            if (lLine.IndexOf("DAX:") == 0)
            {
                ScanDetailObject sdo = new ScanDetailObject(lLine.Substring(4));

                ScanDetailObjects.Add(sdo);
            }
        }

        file.Close();

        return ScanDetailObjects.Count;
    }
}