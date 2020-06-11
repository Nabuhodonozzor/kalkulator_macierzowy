#pragma once 
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <array>
#include "exceptions.hpp"

using data_type = std::vector<std::vector<double>>;

class Matrix{
private:
    std::string name_;
    data_type values_;

public:
    Matrix(std::string, data_type);

    friend Matrix & sub_add(const Matrix &, const Matrix &, unsigned);

    data_type getValues();
    std::string getName();
};