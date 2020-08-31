#ifndef GTML_TABLE_TESTS
#define GTML_TABLE_TESTS

#include "unitTests.hpp"

// File to declare unit tests for GTML::table

// Tests to call
testResults knownFunctionsTables();

const testSet tableTests = {"GTML::table tests", {{"Known Functions", knownFunctionsTables}}};

// Subroutines used in tests
template<typename type>
void testKnownFunctions(std::vector<std::function<type(type)>> knownFunctions, std::vector<type> testValues, testResults& results, type start, type end, type step);
template<typename inputType, typename outputType = inputType>
std::string testGeneratedTable(GTML::table<inputType, outputType> generatedTable, std::vector<std::tuple<inputType, outputType>> knownValues);

// Data to test with
extern std::vector<std::function<int(int)>> knownIntFunctions;
extern std::vector<std::function<double(double)>> knownDoubleFunctions;

extern std::vector<int> testIntValues;
extern std::vector<double> testDoubleValues;

#endif