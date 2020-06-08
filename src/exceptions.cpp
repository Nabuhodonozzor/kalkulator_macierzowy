#include "exceptions.hpp"

unmatching_size::unmatching_size(const std::string & firstID, std::vector<size_t> & firstDimensions, const std::string & secondID, std::vector<size_t> & secondDimensions, std::string operand) :
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