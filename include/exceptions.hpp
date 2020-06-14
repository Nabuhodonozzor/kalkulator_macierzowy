#pragma once
#include <exception>
#include <string>
#include <array>

//exception thrown when matrices are not fit to perform certain operations
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

//exception thrown when a file is not opened properly
class file_open_error : public std::exception{
    std::string errorFileName_;

public:
    file_open_error(std::string &);
    
    const std::string what();
};

//exception thrown when wrong number of = is in the input string
class bad_equals : public std::exception{
    std::ptrdiff_t eq_count_;
public:
    bad_equals(std::ptrdiff_t);
    const std::string what();
};

//exception thrown when a matrix with given name is in the vector
class matrix_already_in_vector : public std::exception{
    std::string name_;

public:
    matrix_already_in_vector(std::string &);
    const std::string what();
};

//exception thrown when no matrix with given name is found
class no_such_matrix : public std::exception{
    std::string name_;

public:
    no_such_matrix(std::string &);
    const std::string what();
};