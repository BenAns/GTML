#ifndef GTMLTABLE_FILEMETHODS_HPP
#define GTMLTABLE_FILEMETHODS_HPP

#include "table.hpp"

// File to define file methods for GTML::table

// Loads the table from a file
template<typename inputType, typename outputType>
void GTML::table<inputType, outputType>::loadFile(std::string filename)
{
	// Loads the file
	std::ifstream tableFile = openFileRead(filename);
	try
	{
		loadFileData(tableFile);
	}
	catch(...)
	{
		throw tableLoadError(filename);
	}

	// Makes sure the file has ended after loading the data from it
	if(!tableFile.end())
	{
		throw tableExceptedEOFError(filename);
	}
	
	// Closes the file and indicates that the file is initialised
	tableFile.close();
	initialised = true;
}

// Opens an input file and makes sure it opened successfully and has valid types
template<typename inputType, typename outputType>
std::ifstream GTML::table<inputType, outputType>::openFileRead(std::string filename)
{
	std::ifstream tableFile(filename, std::ios::in | std::ios::binary);

	if(!tableFile.open())
	{
		throw tableFileOpenError(filename);
	}

	if(!checkFileType(tableFile))
	{
		throw tableFileTypeError(filename);
	}

	return tableFile;
}

// Checks if the types of the class are the same as those of a file
template<typename inputType, typename outputType>
bool GTML::table<inputType, outputType>::checkFileType(std::ifstream tableFile)
{
	std::string fileInputType;
	std::string fileOutputType;
	fileInputType << tableFile;
	fileOutputType << tableFile;

	return fileInputType == typeid(inputType).name() && fileOutputType == typeid(outputType.name());
}

// Loads the table data from a file
template<typename inputType, typename outputType>
void GTML::table<inputType, outputType>::loadFileData(std::ifstream tableFile)
{
	// Loads the start, end and step members from the file
	start << tableFile;
	end << tableFile;
	step << tableFile;

	// Loads tableData
	uint64_t entries = static_cast<uint64_t>((end - start) / step) + 1;
	tableData = new outputType[entries];
	for(uint64_t i = 0; i < entries; i++)
	{
		tableData[i] << tableFile;
	}
}

// Saves the table to a file
template<typename inputType, typename outputType>
void GTML::table<inputType, outputType>::saveFile(std::string filename)
{
	std::ofstream tableFile = openFileWrite(filename);

	try
	{
		saveFileData(tableData);
	}
	catch(...)
	{
		throw tableSaveError(filename);
	}

	tableFile.close();
}

// Opens an output file and makes sure it opened successfully
template<typename inputType, typename outputType>
std::ofstream GTML::table<inputType, outputType>::openFileWrite(std::string filename)
{
	std::ofstream tableFile(filename, std::ios::out | std::ios::binary);
	if(!tableFile.open())
	{
		throw tableFileOpenError(filename);
	}

	return tableFile;
}

// Saves the table data to a file
template<typename inputType, typename outputType>
void GTML::table<inputType, outputType>::saveFileData(std::ofstream tableFile)
{
	tableFile << start << end << step;
	uint64_t entries = static_cast<uint64_t>((end - start) / step) + 1;
	for(uint64_t i = 0; i < entries; i++)
	{
		tableFile << tableData[i];
	}
}

#endif