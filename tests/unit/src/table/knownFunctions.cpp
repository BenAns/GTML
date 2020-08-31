#include "tableTests.hpp"

// File to define known functions to test with GTML::table

extern std::vector<std::function<int(int)>> knownIntFunctions =
{
	// Nothing Function
	[](int x) {return x;},

	// Four Basic Operations
	[](int x) {return x + 1;},
	[](int x) {return x + 5000;},
	[](int x) {return x - 1;},
	[](int x) {return x - 5000;},
	[](int x) {return x * 2;},
	[](int x) {return x * 5000;},
	[](int x) {return x / 2;},
	[](int x) {return x / 5000;}
};


extern std::vector<std::function<double(double)>> knownDoubleFunctions =
{
	// Nothing Function
	[](double x) {return x;},

	// Four Basic Operations
	[](double x) {return x + 1;},
	[](double x) {return x + 5000;},
	[](double x) {return x - 1;},
	[](double x) {return x - 5000;},
	[](double x) {return x * 2;},
	[](double x) {return x * 5000;},
	[](double x) {return x / 2;},
	[](double x) {return x / 5000;}

	// Trigonometric Functions
};