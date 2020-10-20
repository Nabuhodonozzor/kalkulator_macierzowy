#cmake version
cmake_minimum_required(VERSION 3.10)

# set project name
project(Matrix)

add_compile_options(-Wall)

# adding executables
file(GLOB_RECURSE all_src "src/*.cpp")
add_executable(Matrix ${all_src})

# adding headers
file(GLOB_RECURSE all_hpp "include/*.hpp")
# add_executable(Matrix ${all_hpp})

# C++ standard 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

