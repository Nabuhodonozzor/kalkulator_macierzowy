#pragma once
#include "matrix.hpp"



class InputAnalyzer{
private:
    Matrix newMatrix_;

public:
    InputAnalyzer();
    Matrix initiateDecompositon();
    std::string setID(std::string &);
    data_type setValues(std::string &);
};