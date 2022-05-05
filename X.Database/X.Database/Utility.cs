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

using System.IO;
using System.Windows.Forms;
using System.Xml.Serialization;

public static class Utility
{
	public static void OpenWebPage(string aWebSiteURL)
    {
        System.Diagnostics.Process.Start(aWebSiteURL);
    }

    public static string ConvertToUsefulUnit(long aValue)
    {
        if (aValue < 1024)
        {
            return aValue.ToString() + " bytes";
        }
        else if (aValue < (1024 * 1024))
        {
            return ((float)aValue / 1024).ToString("0.00") + " K";
        }
        else if (aValue < (1024 * 1024 * 1024))
        {
            return ((float)aValue / (1024 * 1024)).ToString("0.00") + " MB";
        }
        else if (aValue < 1099511627776)
        {
            return ((float)aValue / (1024 * 1024 * 1024)).ToString("0.00") + " GB";
        }
        else
        {
            return ((float)aValue / (1099511627776)).ToString("0.00") + " TB";
        }
    }

    public static FormState LoadFormState()
    {
        if (File.Exists(Path.GetDirectoryName(Application.ExecutablePath) + "\\config.xml"))
        {
            XmlSerializer serializer = new XmlSerializer(typeof(FormState));

            try
            { 
                using (FileStream fs = File.OpenRead(Path.GetDirectoryName(Application.ExecutablePath) + "\\config.xml"))
                {
                    return (FormState)serializer.Deserialize(fs);
                }
            }
            catch
            {
                FormState lFormState = new FormState();

                return lFormState;
            }
        }
        else
        {
            FormState lFormState = new FormState();

            return lFormState;
        }
    }

    public static void SaveFormState(FormState aFormState)
    {
        XmlSerializer serializer = new XmlSerializer(typeof(FormState));

        try
        {
            using (TextWriter textWriter = new StreamWriter(Path.GetDirectoryName(Application.ExecutablePath) + "\\config.xml"))
            {
                serializer.Serialize(textWriter, aFormState);
            }
        }
        catch
        {
            MessageBox.Show("Error while saving Window state!",
                            "X.Database",
                            MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
    }
}