#pragma once
#include "matrix.hpp"

class MatrixVector{
private:
    std::vector<Matrix> matrixVect_;

public:
    void push_back(Matrix &);
    Matrix & find(std::string &);

    std::vector<Matrix> getVector();
};