#include "../include/matrixVector.hpp"

void MatrixVector::push_back(Matrix & matrixToAdd){
    matrixVect_.push_back(matrixToAdd);
}

Matrix MatrixVector::getCertainMatrix(std::string & matrixToFind){
    
    std::string currentWO_ws;
    matrixToFind.erase(std::remove_if(matrixToFind.begin(), matrixToFind.end(), ::isspace), matrixToFind.end());

    for(auto current : matrixVect_){
        currentWO_ws = current.getName();
        currentWO_ws.erase(std::remove_if(currentWO_ws.begin(), currentWO_ws.end(), ::isspace), currentWO_ws.end());
        if(currentWO_ws == matrixToFind) return current;
    }
    throw no_such_matrix(matrixToFind);
}

bool MatrixVector::isMatrixInVector(std::string & toCheck){

    std::string currentWOwhitespace;
    toCheck.erase(std::remove_if(toCheck.begin(), toCheck.end(), ::isspace), toCheck.end());

    for(auto current : matrixVect_){
        currentWOwhitespace = current.getName();
        currentWOwhitespace.erase(std::remove_if(currentWOwhitespace.begin(), currentWOwhitespace.end(), ::isspace), currentWOwhitespace.end());
        if(currentWOwhitespace == toCheck) return true;
    }
    return false;
}

std::vector<Matrix> MatrixVector::getVector(){
    return matrixVect_;
}

void MatrixVector::clear(){
    matrixVect_.clear();
}