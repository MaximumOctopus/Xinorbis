//
// X.Robot 4.0 :: C++ rewrite
//
// (c) Paul Alan Freshney 2019-2020
//     Maximum Octopus Limited
//
// xinorbis.com
// maximumoctopus.com
// 
// twitter.com/maximumoctopus
//
//
// February 13th 2019
//


#pragma once


const static int __HelpSimple = 0;
const static int __HelpHelp   = 1;
const static int __HelpUsage  = 2;
const static int __HelpStats  = 3;
const static int __HelpCat    = 4;


namespace Help
{
	void OutputHelpOption(int option);

    void OutputSimple();
    void OutputHelp();
    void OutputUsage();

	void Stats();

	void Cat();
}