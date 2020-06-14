#pragma once
#include <algorithm>
#include "matrix.hpp"

class MatrixVector{
private:
    std::vector<Matrix> matrixVect_;

public:
    void push_back(Matrix &);
    Matrix getCertainMatrix(std::string &);
    bool isMatrixInVector(std::string &);

    std::vector<Matrix> getVector();
};