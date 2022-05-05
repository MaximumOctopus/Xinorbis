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

namespace X.Database
{
    public static class Settings
    {
        public static string ODBCConnectionString;

        public static void LoadSettings()
        {
            Ini IniFile = new Ini("custom.ini");

            if (IniFile.Loaded)
            {
                ODBCConnectionString = IniFile.ReadString("Main", "connectionstringxd", "");
            }
            else
            {
                ODBCConnectionString = "";
            }
        }
    }
}
