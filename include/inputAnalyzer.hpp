#pragma once
#include "matrix.hpp"
#include <sstream>
#include <stdexcept>



class InputAnalyzer{
private:
    Matrix newMatrix_;

public:
    InputAnalyzer();
    Matrix initiateDecompositon();
    std::string setID(std::string &);
    data_type setValues(std::string &);
};