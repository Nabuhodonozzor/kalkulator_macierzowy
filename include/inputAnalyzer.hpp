#pragma once
#include <sstream>
#include <stdexcept>
#include "matrix.hpp"



class InputAnalyzer{

public:
    Matrix initiateDecompositon(std::string &);
    std::string setID(std::string &);
    data_type setValues(std::string &);
};