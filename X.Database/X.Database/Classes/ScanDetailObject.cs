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


public class ScanDetailObject
{
    public string dateOutput;
    public string dateSystem;

	public ScanDetailObject(string adateSystem)
	{
        dateSystem = adateSystem;

        if (dateSystem.Length == 14)
        {
            string year = adateSystem.Substring(0, 4);
            string month = adateSystem.Substring(4, 2);
            string day = adateSystem.Substring(6, 2);

            string hour = adateSystem.Substring(8, 2);
            string minute = adateSystem.Substring(10, 2);
            string second = adateSystem.Substring(12, 2);

            dateOutput = year + '/' + month + '/' + day + ' ' + hour + ':' + minute + '.' + second;
        }
        else
        {
            dateOutput = adateSystem;
        }
    }
}