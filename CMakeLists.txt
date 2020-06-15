#cmake version
cmake_minimum_required(VERSION 3.10)

# set project name
project(Matrix)

# adding executables
file(GLOB_RECURSE all_src "src/*.cpp")
add_executable(Matrix ${all_src})

#adding headers
include_directories(include)

# C++ standard 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

