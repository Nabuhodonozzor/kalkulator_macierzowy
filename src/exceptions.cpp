#include "exceptions.hpp"

unmatching_size::unmatching_size(const std::string & firstID, std::vector<size_t> & firstDimensions, const std::string & secondID, std::vector<size_t> & secondDimensions, char operand) :
    firstID_(firstID),
    firstDimensions_(firstDimensions),
    secondID_(secondID),
    secondDimensions_(secondDimensions),
    operand_(operand){

}


const std::string unmatching_size::what(){

    auto firstDimsStr = '[' + std::to_string(firstDimensions_.at(0)) + 'x' + std::to_string(firstDimensions_.at(1)) + ']';
    auto secondDimsStr = '[' + std::to_string(secondDimensions_.at(0)) + 'x' + std::to_string(secondDimensions_.at(1)) + ']';
    auto matrixIfno = "Matrices :\n\t" + firstID_ + ' ' + firstDimsStr + "\n\t" + secondID_ + ' ' + secondDimsStr;
    auto errorInfo = " are not fit to perform operation \"" + operand_ + '\"';

    return matrixIfno + errorInfo;
}