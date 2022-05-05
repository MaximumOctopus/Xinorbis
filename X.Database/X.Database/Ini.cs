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


namespace X.Database
{
    public class Ini
    {
        private List<string> _Contents;
        public bool Loaded;

        public Ini(string aFileName)
        {
            _Contents = new List<string>();

            Loaded = LoadFile(aFileName);
        }

        private bool LoadFile(string aFileName)
        {
            if (File.Exists(aFileName))
            {
                string line = "";

                using (StreamReader sr = new StreamReader(aFileName))
                {
                    while ((line = sr.ReadLine()) != null)
                    {
                        _Contents.Add(line);
                    }
                }

                return true;
            }

            return false;
        }

        public string ReadString(string aSection, string aKey, string aDefault)
        {
            bool inSection     = false;
            string sectionName = "";

            for (int t = 0; t < _Contents.Count; t++)
            {
                if (_Contents[t] != "")
		        {
                    if (_Contents[t][0] == '[')
			        {
                        if (inSection)
                        {
                            // we were in the right section, but now entered a new one.... which means the key we're looking
                            // for must be missing, so return the default value
                            return aDefault;
                        }
                        else
                        {
                            sectionName = _Contents[t].Substring(1, _Contents[t].Length - 2);

                            if (sectionName.ToUpper() == aSection.ToUpper())
                            {
                                inSection = true;
                            }
                        }
                    }
			        else
			        {
                        if (inSection)
                        {
                            if (_Contents[t] != "")
					        {
                                if ((_Contents[t][0] != ';') && (_Contents[t][0] != '/'))
						        {
                                    if (_Contents[t].StartsWith(aKey + "="))
                                    {
                                        if (_Contents[t].Length > aKey.Length + 1)
                                        {
                                            return _Contents[t].Substring(aKey.Length + 1);
                                        }
                                        else
                                        {
                                            // key is emtpy (key= ) so let's return the default                                
                                            return aDefault;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

	        return aDefault;
        }
    }
}