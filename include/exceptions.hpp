#pragma once
#include <exception>
#include <string>
#include <array>


class unmatching_size : public std::exception{
    std::string firstID_;
    std::string secondID_;
    std::array<size_t, 2> firstDimensions_;
    std::array<size_t, 2> secondDimensions_;
    std::string operand_;

public:
    unmatching_size(const std::string &, std::array<size_t, 2> &, const std::string &, std::array<size_t, 2> &, std::string);

    const std::string what();
};


class file_open_error : public std::exception{
    std::string errorFileName_;

public:
    file_open_error(std::string &);
    
    const std::string what();
};

class bad_equals : public std::exception{
private:
    std::ptrdiff_t eq_count_;
public:
    bad_equals(std::ptrdiff_t);
    const std::string what();
};

class matrix_already_in_vector{
private:
    std::string name_;
public:
    matrix_already_in_vector(std::string &);
    const std::string what();
};