#pragma once
#include "matrix.hpp"
#include <sstream>
#include <stdexcept>



class InputAnalyzer{

public:
    Matrix initiateDecompositon(std::string &);
    data_type setValues(std::string &);
};