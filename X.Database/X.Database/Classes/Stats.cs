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
using System.Windows.Forms;

public static class Stats
{
    private static long fsizeoffiles;
    private static long faveragefilesize;
    private static int ffilecount;
    private static int ffoldercount;
    private static bool fhasrealdata;

    static Stats()
    {
        fsizeoffiles = 0;
        faveragefilesize = 0;
        ffilecount = 0;
        ffoldercount = 0;
    }

    public static long SizeOfFiles
    {
        get
        {
            return fsizeoffiles;
        }
        set
        {
            fsizeoffiles = value;
        }
    }

    public static long AverageFileSize
    {
        get
        {
            return faveragefilesize;
        }
        set
        {
            faveragefilesize = value;
        }

    }

    public static int FileCount
    {
        get
        {
            return ffilecount;
        }
        set
        {
            ffilecount = value;
        }
    }

    public static int FolderCount
    {
        get
        {
            return ffoldercount;
        }
        set
        {
            ffoldercount = value;
        }
    }

    public static bool HasRealData
    {
        get
        {
            return fhasrealdata;
        }
        set
        {
            fhasrealdata = value;
        }
    }

    public static void GenerateStats(ref DataGridView adataGridView)
    {
        long lSizeOfFiles = 0;
        int lFileCount = 0;
        int lFolderCount = 0;

        int i = 0;
        int indexFileSize = -1;

        foreach (DataGridViewColumn column in adataGridView.Columns)
        {
            if (column.HeaderText == "FileSize")
            {
                indexFileSize = i;
            }

            i++;
        }

        if (indexFileSize != -1)
        {
            long lValue;

            foreach (DataGridViewRow row in adataGridView.Rows)
            {
                if (row.Cells[indexFileSize].Value != null)
                {
                    lValue = (long)row.Cells[indexFileSize].Value;

                    if (lValue == -1)
                    {
                        lFolderCount++;
                    }
                    else
                    {
                        lFileCount++;

                        lSizeOfFiles += lValue;
                    }
                }
            }

            fsizeoffiles     = lSizeOfFiles;
            faveragefilesize = Convert.ToInt64((double)lSizeOfFiles / lFileCount);

            fhasrealdata     = true;
        }
        else
        {
            fsizeoffiles     = 0;
            faveragefilesize = 0;
            ffilecount       = 0;
            ffoldercount     = 0;

            fhasrealdata     = false;
        }
    }
}