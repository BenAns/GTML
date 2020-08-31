#ifndef GTMLTABLE_CREATETABLEMETHODS_HPP
#define GTMLTABLE_CREATETABLEMETHODS_HPP

#include "table.hpp"

// File to define methods to do creating a table from scratch

// Creates a table from a normal function
template<typename inputType, typename outputType>
void GTML::table<inputType, outputType>::createTable(inputType start, inputType end, inputType step, std::function<outputType(inputType funcInput)> func)
{
	// Allocates the memory for the table
	uint64_t entries = static_cast<uint64_t>((end - start) / step) + 1;
	tableData = new inputType[entries];

	// Defines class members to do with the table data
	this->start = start;
	this->end = end;
	this->step = step;

	// Generates the table
	inputType funcInput = start;
	for(uint64_t i = 0; i < entries; i++)
	{
		tableData[i] = func(funcInput);
		funcInput += step;
	}

	initialised = true;
}

#endif