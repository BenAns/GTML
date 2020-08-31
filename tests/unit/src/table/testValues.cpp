#include "tableTests.hpp"

// File to define known values to test with GTML::table

std::vector<int> testIntValues =
{
	// Typical Values
	5,
	20,
	53,
	19845,
	3243,
	-44,
	-6236,
	-232,
	-7,

	// Special Values
	0,
	1,
	-1,
	-10000,
	9999
};

std::vector<double> testDoubleValues =
{
	// Typical Values
	5.4,
	20.8,
	53.3,
	19845.6,
	3243.8,
	-44.4,
	-6236.6,
	-232.8,
	-7.5,

	// Special Values
	0.0,
	1.0,
	-1.0,
	0.5,
	-0.5,
	0.1,
	-0.1,
	-10000.0,
	9999.9
};