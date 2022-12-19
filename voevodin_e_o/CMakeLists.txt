cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD_REQUIRED 20)

project(Gravitation_Test)

add_subdirectory("./geom")


add_executable(Gravitation_Test Gravitaition.cpp)

target_link_libraries(Gravitation_Test Geom)