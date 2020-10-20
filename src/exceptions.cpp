#include "../include/exceptions.hpp"

// unmatching_size exception

unmatching_size::unmatching_size(const std::string & firstID, std::size_t & firstRows, std::size_t & firstCols, const std::string & secondID, std::size_t & secondRows, std::size_t & secondCols, std::string operand) :
    firstID_(firstID),
    firstRows_(firstRows),
    firstCols_(firstCols),
    secondID_(secondID),
    secondRows_(secondRows),
    secondCols_(secondCols),
    operand_(operand){

}

const std::string unmatching_size::what(){

    auto firstDimsStr = '[' + std::to_string(firstRows_) + 'x' + std::to_string(firstCols_) + ']';
    auto secondDimsStr = '[' + std::to_string(secondRows_) + 'x' + std::to_string(secondCols_) + ']';
    auto matrixIfno = "Matrices :\n\t" + firstID_ + " " + firstDimsStr + " and " + secondID_ + " " + secondDimsStr;
    auto errorInfo = "\n\tare not fit to perform operation \"" + operand_ + '\"';
    auto returnStr = matrixIfno + errorInfo;

    return returnStr;
}

//=============================================================

//file_open_error

file_open_error::file_open_error(std::string & errorFileName) : errorFileName_(errorFileName){}

const std::string file_open_error::what(){
    return "Error when openieng a file: " + errorFileName_;
}

//===============================================================

//bad_equals

bad_equals::bad_equals(std::ptrdiff_t eq_count) : eq_count_(eq_count){}

const std::string bad_equals::what(){
    return "Invalid number of \'=\' symbol ("+ std::to_string(eq_count_) +"). Only one is allowed.";
}

//=====================================================================

//matrix_already_in_vector

matrix_already_in_vector::matrix_already_in_vector(std::string & name) : name_(name){}

const std::string matrix_already_in_vector::what(){
    return "Matrix with such name: \"" + name_ + "\" already in vector";
}

//===================================================================

//no_such_matrix

no_such_matrix::no_such_matrix(std::string & name) : name_(name){}

const std::string no_such_matrix::what(){
    return "Couldn't find matrix " + name_;
}