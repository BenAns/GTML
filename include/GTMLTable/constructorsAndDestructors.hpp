#ifndef GTMLTABLE_CONSTRUCTORSANDDESTRUCTORS_HPP
#define GTMLTABLE_CONSTRUCTORSANDDESTRUCTORS_HPP

#include "table.hpp"

// File to define constructors and destructors for GTML::table

template<typename inputType, typename outputType>
GTML::table<inputType, outputType>::table()
{
	tableData = nullptr;
	
	start = NULL;
	end = NULL;
	step = NULL;

	initialised = false;
}

template<typename inputType, typename outputType>
GTML::table<inputType, outputType>::~table()
{
	if(initialised)
	{
		delete[] tableData;
	}
}

#endif