#pragma once
#include <exception>
#include <string>

class unmatching_size : public std::exception{
public:
    const std::string what();
};