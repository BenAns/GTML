#include "unitTests.hpp"

// File to call unit tests for GTML

const std::vector<testSet> unitTests = {tableTests};

int main()
{
	for(testSet currentSet: unitTests)
	{
		std::cout << currentSet.title << ":" << std::endl;

		for(testProcedure currentTest : currentSet.tests)
		{
			std::cout << currentTest.name << " - " << std::flush;
			testResults results = currentTest.procedure();

			std::cout << (results.outcome ? "Passed" : "Failed: " + results.message) << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;
}