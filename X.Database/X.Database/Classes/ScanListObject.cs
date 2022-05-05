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


public class ScanListObject
{
    public string MD5Hash;
    public string Path;
    public string ReportFileName;

    public ScanListObject(string aMD5Hash, string aPath, string aReportFileName)
	{
        MD5Hash = aMD5Hash;
        Path = aPath;

        ReportFileName = aReportFileName;
	}
}