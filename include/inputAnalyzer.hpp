#pragma once
#include "matrix.hpp"



class InputAnalyzer{
private:
    Matrix newMatrix_;

public:
    InputAnalyzer();
    Matrix getNewMatrix();
    Matrix initiateDecompositon();
    void setID(std::string);
    void setValues(std::string);
};