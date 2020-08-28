#ifndef GTML_TABLE_TESTS
#define GTML_TABLE_TESTS

#include "unitTests.hpp"

// File to declare unit tests for GTML::table

testResults basicOperations();

const testSet tableTests = {"GTML::table tests", {{"Basic Operations", basicOperations}}};

#endif