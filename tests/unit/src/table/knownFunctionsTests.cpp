#include "tableTests.hpp"

// File to define tests for GTML::table on already known functions

// Creates and tests tables that do nothing, addition, subtraction, multiplication and division
testResults knownFunctionsTables()
{
	testResults results = {true, ""};

	std::cout << "Testing known int functions:" << std::endl;
	testKnownFunctions(knownIntFunctions, testIntValues, results, -10000, 10000, 1);

	std::cout << "Testing known double functions" << std::endl;
	testKnownFunctions(knownDoubleFunctions, testDoubleValues, results, -10000.0, 10000.0, 0.1);

	return results;
}

// Tests known functions for given values with GTML::table
template<typename type>
void testKnownFunctions(std::vector<std::function<type(type)>> knownFunctions, std::vector<type> testValues, testResults& results, type start, type end, type step)
{
	for(int i = 0; i < knownFunctions.size(); i++)
	{
		// Creates the table for the current function
		std::function<type(type)> func = knownFunctions[i];
		GTML::table<type> knownFuncTable;
		knownFuncTable.createTable(start, end, step, func);

		// Generates the vector of input/output pairs for the current function
		std::vector<std::tuple<type, type>> pairs;
		pairs.reserve(testValues.size());
		for(type input : testValues)
		{
			pairs.push_back(std::make_tuple(input, func(input)));
		}

		// Tests the tables and writes results if necessary
		std::string output = testGeneratedTable(knownFuncTable, pairs);
		if(output != "")
		{
			results.outcome = false;
			results.message += "\nFunction " + std::to_string(i) + ": " + output;
		}
	}
}

// Tests known values in a generated table
template<typename inputType, typename outputType>
std::string testGeneratedTable(GTML::table<inputType, outputType> generatedTable, std::vector<std::tuple<inputType, outputType>> knownValues)
{
	std::string failures = "";

	for(std::tuple<inputType, outputType> knownPair: knownValues)
	{
		if(generatedTable(std::get<0>(knownPair)) != std::get<1>(knownPair))
		{
			failures += "Failed Test: (" + std::to_string(std::get<0>(knownPair)) + ", " + std::to_string(std::get<1>(knownPair)) + ") -> New Output: " + std::to_string(generatedTable(std::get<0>(knownPair))) + "\n";
		}
	}

	return failures;
}