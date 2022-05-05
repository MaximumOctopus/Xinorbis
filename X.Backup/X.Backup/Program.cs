using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("X.Backup " + Constants.Version + " :: " + Constants.Date);

        string XinorbisPath = Utility.GetXinorbisDataPath();

        if (XinorbisPath != string.Empty)
        {
            Console.WriteLine("Found Xinorbis data folder: " + XinorbisPath);

            string lFileName = Utility.GetArchiveFileName();

            Console.WriteLine("Saving backup to: " + lFileName);

            if (Utility.ZipFolder(XinorbisPath, lFileName))
            {
                Console.WriteLine("Finished.");
            }
            else
            {
                Console.WriteLine("Error saving :(");
            }
        }
        else
        {
            Console.WriteLine("Cannot find Xinorbis data folder, exiting.");
        }
    }
}
