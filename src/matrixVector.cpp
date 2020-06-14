#include "matrixVector.hpp"

void MatrixVector::push_back(Matrix & matrixToAdd){
    matrixVect_.push_back(matrixToAdd);
}

Matrix & MatrixVector::find(std::string & matrixToFind){
    
//    for(auto current : matrixVect_){
//        if(current.getName() == matrixToFind) return current;
//    }
//    throw 1;
}

std::vector<Matrix> MatrixVector::getVector(){
    return matrixVect_;
}