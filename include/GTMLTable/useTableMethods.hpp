#ifndef GTMLTABLE_USETABLEMETHODS_HPP
#define GTMLTABLE_USETABLEMETHODS_HPP

#include "table.hpp"

// File to define methods to do with using GTML::table

// Retrieves a value of the function from the table
template<typename inputType, typename outputType>
outputType GTML::table<inputType, outputType>::operator()(inputType funcInput) const
{
	uint64_t index = static_cast<uint64_t>((funcInput - start) / end);
	return tableData[index];
}

#endif