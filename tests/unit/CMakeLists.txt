add_executable(GTMLUnitTests src/main.cpp src/table/basicOperationsTests.cpp)

target_include_directories(GTMLUnitTests PRIVATE include)
target_include_directories(GTMLUnitTests PRIVATE ../../include)
