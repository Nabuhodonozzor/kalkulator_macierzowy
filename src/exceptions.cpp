#include "exceptions.hpp"

// unmatching_size exception

unmatching_size::unmatching_size(const std::string & firstID, std::array<size_t, 2> & firstDimensions, const std::string & secondID, std::array<size_t, 2> & secondDimensions, std::string operand) :
    firstID_(firstID),
    firstDimensions_(firstDimensions),
    secondID_(secondID),
    secondDimensions_(secondDimensions),
    operand_(operand){

}

const std::string unmatching_size::what(){

    auto firstDimsStr = '[' + std::to_string(firstDimensions_.at(0)) + 'x' + std::to_string(firstDimensions_.at(1)) + ']';
    auto secondDimsStr = '[' + std::to_string(secondDimensions_.at(0)) + 'x' + std::to_string(secondDimensions_.at(1)) + ']';
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

const std::string bad_equals::what(){
    return "Couldn't find \'=\' symbol.";
}