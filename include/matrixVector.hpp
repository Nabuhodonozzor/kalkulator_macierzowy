#pragma once
#include <algorithm>
#include "matrix.hpp"

class MatrixVector{
private:
    std::vector<Matrix> matrixVect_;

public:
    void push_back(Matrix &);
    bool isMatrixInVector(std::string &);
    void clear();

    Matrix getCertainMatrix(std::string &);
    std::vector<Matrix> getVector();
};