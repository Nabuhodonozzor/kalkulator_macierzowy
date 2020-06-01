#pragma once
#include <exception>
#include <string>
#include <vector>


class unmatching_size : public std::exception{
    std::string firstID_;
    std::string secondID_;
    std::vector<unsigned> firstDimensions_;
    std::vector<unsigned> secondDimensions_;
public:
    unmatching_size(const std::string&, unsigned &, unsigned &, const std::string &, unsigned &, unsigned &);
    const std::string what();
};