#ifndef GTML_UNIT_TESTS
#define GTML_UNIT_TESTS

#include <iostream>
#include <functional>
#include <vector>
#include <GTML.hpp>

// File to declare unit test procedures, declare testing-related structs and define the unitTests array

struct testResults
{
	bool outcome;
	std::string message;
};

struct testProcedure
{
	std::string name;
	std::function<testResults()> procedure;
};

struct testSet
{
	std::string title;
	std::vector<testProcedure> tests;
};

#include "tableTests.hpp"

#endif