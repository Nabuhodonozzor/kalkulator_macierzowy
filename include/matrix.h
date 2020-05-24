#pragma once 
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using data_type = std::vector<std::vector<double>>;

class Matrix{
private:
    std::string name;
    data_type values;

public:
    Matrix();
    Matrix(std::string, data_type);
    ~Matrix();


    friend std::ostream &operator<<(std::ostream &, Matrix &);
    Matrix & operator+(const Matrix &);
    Matrix & operator-(const Matrix &);
};