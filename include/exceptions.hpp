#pragma once
#include <exception>
#include <string>
#include <vector>


class unmatching_size : public std::exception{
    std::string firstID_;
    std::string secondID_;
    std::vector<unsigned> firstDimensions_;
    std::vector<unsigned> secondDimensions_;
    std::string operand_;
public:
    unmatching_size(const std::string &, std::vector<size_t> &, const std::string &, std::vector<size_t> &, std::string);
    const std::string what();
};


class file_open_error : public std::exception{
    std::string errorFileName_;
public:
    file_open_error(std::string &);
    const std::string what();
};