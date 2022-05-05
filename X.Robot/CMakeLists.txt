cmake_minimum_required(VERSION 3.9)
project(X_Console)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DUNICODE)

add_executable(X_Console main.cpp FileObject.h UserData.h Constants.h UserData.cpp FileExtension.h FileExtension.cpp SystemGlobal.cpp Settings.h Settings.cpp SystemGlobal.h LanguageHandler.h LanguageHandler.cpp ScanDetails.cpp ScanDetails.h Utility.cpp WindowsUtility.h WindowsUtility.cpp GlobalObjects.cpp Utility.h GlobalObjects.h Help.cpp Help.h ParameterHandler.h ParameterHandler.cpp)