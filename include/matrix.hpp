#pragma once 
#include "exceptions.hpp"
#include <string>
#include <vector>
#include <array>

using data_type = std::vector<std::vector<double>>;

class Matrix{
private:
    std::string name_;
    data_type values_;

public:
    Matrix(std::string, data_type);

    //function adding or substracting two mastrices
    //operation = 0 - addition
    //operation = 1 - substraction
    friend Matrix sub_add(const Matrix &, const Matrix &, unsigned);

    data_type getValues();
    std::string getName();
};