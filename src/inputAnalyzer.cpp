#include "inputAnalyzer.hpp"

Matrix InputAnalyzer::initiateDecompositon(){
    std::string rawInput;
    std::vector<std::string> segmentatedString;

    getline(std::cin, rawInput);
    segmentatedString.push_back(rawInput.substr(0, rawInput.find('=')));
    segmentatedString.push_back(rawInput.substr(rawInput.find('=') + 1));

    Matrix newMatrix(setID(segmentatedString.at(0)), setValues(segmentatedString.at(1)));
    return newMatrix;
}