add_executable(GTMLUnitTests src/main.cpp src/table/knownFunctionsTests.cpp src/table/knownFunctions.cpp src/table/testValues.cpp)

target_include_directories(GTMLUnitTests PRIVATE include)
target_include_directories(GTMLUnitTests PRIVATE ../../include)
