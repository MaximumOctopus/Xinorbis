// =====================================================================
//
//   Xinorbis 10.0
//
// (c) Paul Alan Freshney 2002-2026
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/Xinorbis
// 
// =====================================================================

#include "Convert.h"
#include "FileObject.h"
#include "Formatting.h"
#include "LanguageHandler.h"


extern LanguageHandler* GLanguageHandler;


FileObject::FileObject()
{
	Size       = 0;
	SizeOnDisk = 0;
	Owner      = 0;
}


std::wstring FileObject::ToCSV(const std::wstring folder, const std::wstring user, int units)
{
	std::wstring output = L"";

	if (Attributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		output = L"\"" + Name + L"\","
			L"\"" + folder + Name + L"\"" + L"," +
			L"\"" + folder + L"\"" + L"," +

			GLanguageHandler->Text[kFolder] + L"," +
			L"-1" + L"," +
			L"-1" + L"," +

			Convert::IntDateToString(DateCreated) + L"," +
			Convert::IntDateToString(DateAccessed) + L"," +
			Convert::IntDateToString(DateModified) + L"," +

			std::to_wstring(DateCreated) + L"," +
			std::to_wstring(DateAccessed) + L"," +
			std::to_wstring(DateModified) + L"," +

			std::to_wstring(TimeCreated) + L"," +
			std::to_wstring(TimeAccessed) + L"," +
			std::to_wstring(TimeModified) + L"," +

			GLanguageHandler->Text[kFolder] + L"," +

			L"99" + L"," +

			user + L"," +

			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_READONLY) + L"," +
			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_HIDDEN) + L"," +
			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_SYSTEM) + L"," +
			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_ARCHIVE) + L"," +
			Convert::BoolToString(Temp) + L"," +
			std::to_wstring(Attributes);
	}
	else
	{
		output = L"\"" + Name + L"\"" + L"," +
			L"\"" + folder + Name + L"\"" + L"," +
			L"\"" + folder + L"\"" + L"," +

			L"\"" + Convert::GetSizeString(units, Size) + L"\"" + L"," +
			L"\"" + std::to_wstring(Size) + L"\"" + L"," +
			L"\"" + std::to_wstring(SizeOnDisk) + L"\"" + L"," +

			Convert::IntDateToString(DateCreated) + L"," +
			Convert::IntDateToString(DateAccessed) + L"," +
			Convert::IntDateToString(DateModified) + L"," +

			std::to_wstring(DateCreated) + L"," +
			std::to_wstring(DateAccessed) + L"," +
			std::to_wstring(DateModified) + L"," +

			std::to_wstring(TimeCreated) + L"," +
			std::to_wstring(TimeAccessed) + L"," +
			std::to_wstring(TimeModified) + L"," +

			GLanguageHandler->TypeDescriptions[Category] + L"," +

			std::to_wstring(Category) + L"," +

			user + L"," +

			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_READONLY) + L"," +
			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_HIDDEN) + L"," +
			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_SYSTEM) + L"," +
			Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_ARCHIVE) + L"," +
			Convert::BoolToString(Temp) + L"," +
			std::to_wstring(Attributes);
	}

	return output;
}


std::wstring FileObject::ToJSON(const std::wstring folder, const std::wstring user)
{
	std::wstring output = L"{";

	output += L"\"FileName\":\"" + Name + L"\", ";
	output += L"\"Path\":\"" + Formatting::ReplaceForJSON(folder) + L"\", ";

	if (Attributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		output += L"\"SizeWords\":\"-1\", ";
		output += L"\"SizeBytes\":\"-1\", ";
		output += L"\"SizeOnDiskWords\":\"-1\", ";
		output += L"\"SizeOnDiskBytes\":\"-1\", ";
	}
	else
	{
		output += L"\"SizeWords\":\"" + Convert::ConvertToUsefulUnit(Size) + L"\", ";
		output += L"\"SizeBytes\":\"" + std::to_wstring(Size) + L"\", ";
		output += L"\"SizeOnDiskWords\":\"" + Convert::ConvertToUsefulUnit(SizeOnDisk) + L"\", ";
		output += L"\"SizeOnDiskBytes\":\"" + std::to_wstring(SizeOnDisk) + L"\", ";
	}

	output += L"\"Owner\":\"" + user + L"\", ";

	output += L"\"TimeCreated\":\"" + std::to_wstring(TimeCreated) + L"\", ";
	output += L"\"TimeModified\":\"" + std::to_wstring(TimeModified) + L"\", ";
	output += L"\"TimeAccessed\":\"" + std::to_wstring(TimeAccessed) + L"\", ";

	output += L"\"DateCreated\":\"" + Convert::IntDateToString(DateCreated) + L"\", ";
	output += L"\"DateModified\":\"" + Convert::IntDateToString(DateModified) + L"\", ";
	output += L"\"DateAccessed\":\"" + Convert::IntDateToString(DateAccessed) + L"\", ";

	output += L"\"DateCreatedYYYYMMDD\":\"" + std::to_wstring(DateCreated) + L"\", ";
	output += L"\"DateModifiedYYYYMMDD\":\"" + std::to_wstring(DateModified) + L"\", ";
	output += L"\"DateAccessedYYYYMMDD\":\"" + std::to_wstring(DateAccessed) + L"\", ";

	output += L"\"Category\":\"" + std::to_wstring(Category) + L"\", ";
	output += L"\"Folder\":\"" + Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_DIRECTORY) + L"\", ";
	output += L"\"Readonly\":\"" + Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_READONLY) + L"\", ";
	output += L"\"Hidden\":\"" + Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_HIDDEN) + L"\", ";
	output += L"\"System\":\"" + Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_SYSTEM) + L"\", ";
	output += L"\"Archive\":\"" + Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_ARCHIVE) + L"\", ";
	output += L"\"Temp\":\"" + Convert::BoolToString(Temp) + L"\", ";
	output += L"\"Attributes\":\"" + std::to_wstring(Attributes) + L"\"";

	return output + L"}";
}


std::wstring FileObject::ToXml(const std::wstring folder, const std::wstring user)
{
	std::wstring output = L"";

	output = L"<item>\n" +
		Formatting::InsertElement(L"name", Formatting::ReplaceEntitiesForXML(Name), 2) + L"\n" +
		Formatting::InsertElement(L"path", Formatting::ReplaceEntitiesForXML(folder), 2) + L"\n";

	if (Attributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		output += Formatting::InsertElement(L"sizewords", L"-1", 2) + L"\n" +
			Formatting::InsertElement(L"sizebytes", L"-1", 2) + L"\n" +
			Formatting::InsertElement(L"sizeondiskwords", L"-1", 2) + L"\n" +
			Formatting::InsertElement(L"sizeondiskbytes", L"-1", 2) + L"\n";
	}
	else
	{
		output += Formatting::InsertElement(L"sizewords", Convert::ConvertToUsefulUnit(Size), 2) + L"\n" +
			Formatting::InsertElement(L"sizebytes", std::to_wstring(Size), 2) + L"\n" +
			Formatting::InsertElement(L"sizeondiskwords", Convert::ConvertToUsefulUnit(SizeOnDisk), 2) + L"\n" +
			Formatting::InsertElement(L"sizeondiskbytes", std::to_wstring(SizeOnDisk), 2) + L"\n";
	}

	output += Formatting::InsertElement(L"owner", user, 2) + L"\n" +
	    Formatting::InsertElement(L"timecreated", std::to_wstring(TimeCreated), 2) + L"\n" +
	    Formatting::InsertElement(L"timemodified", std::to_wstring(TimeModified), 2) + L"\n" +
	    Formatting::InsertElement(L"timeaccessed", std::to_wstring(TimeAccessed), 2) + L"\n" +
	    Formatting::InsertElement(L"datecreated", Convert::IntDateToString(DateCreated), 2) + L"\n" +
	    Formatting::InsertElement(L"datemodified", Convert::IntDateToString(DateModified), 2) + L"\n" +
	    Formatting::InsertElement(L"dateaccessed", Convert::IntDateToString(DateAccessed), 2) + L"\n" +
	    Formatting::InsertElement(L"datecreatedyyyymmdd", std::to_wstring(DateCreated), 2) + L"\n" +
	    Formatting::InsertElement(L"datemodifiedyyyymmdd", std::to_wstring(DateModified), 2) + L"\n" +
	    Formatting::InsertElement(L"dateaccessedyyyymmdd", std::to_wstring(DateAccessed), 2) + L"\n" +
	    Formatting::InsertElement(L"category", std::to_wstring(Category), 2) + L"\n" +
	    Formatting::InsertElement(L"folder", Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_DIRECTORY), 2) + L"\n" +
	    Formatting::InsertElement(L"readonly", Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_READONLY), 2) + L"\n" +
	    Formatting::InsertElement(L"hidden", Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_HIDDEN), 2) + L"\n" +
	    Formatting::InsertElement(L"system", Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_SYSTEM), 2) + L"\n" +
	    Formatting::InsertElement(L"archive", Convert::AttributeToIntAsString(Attributes, FILE_ATTRIBUTE_ARCHIVE), 2) + L"\n" +
	    Formatting::InsertElement(L"temp", Convert::BoolToString(Temp), 2) + L"\n" +
        Formatting::InsertElement(L"attributes", std::to_wstring(Attributes), 2) + L"\n" +
		L"</item>\n";

	return output;
}