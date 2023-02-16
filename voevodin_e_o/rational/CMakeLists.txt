# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("RationalLibrary1")

set(CMAKE_CXX_STANDARD_REQUIRED 20)
# Include sub-projects.
add_subdirectory ("RationalLibrary")

# не уверен, как это точно делать, но вроде работает? Хотелось бы больше с смейком поработать.

add_executable("RationalLibrary1", "Test.cpp")