#include "inputAnalyzer.hpp"
#include <iostream>

InputAnalyzer::InputAnalyzer(){
    
}

Matrix InputAnalyzer::initiateDecompositon(){
    std::string rawInput;
    std::vector<std::string> segmentatedString;

    getline(std::cin, rawInput);
    segmentatedString.push_back(rawInput.substr(0, rawInput.find('=')));
    segmentatedString.push_back(rawInput.substr(rawInput.find('=') + 1));

    return Matrix(setID(segmentatedString.at(0)), setValues(segmentatedString.at(1)));
}

std::string InputAnalyzer::setID(std::string &rawIDstring){
    return rawIDstring;
}

data_type InputAnalyzer::setValues(std::string &rawDataString){
    std::vector<std::string> rowString;
    data_type values;
    std::stringstream dataSS(rawDataString);
    std::string temp;

    while(getline(dataSS, temp, ';')) rowString.push_back(temp);

    for(auto current : rowString) std::cout << current << std::endl;

    return {{0}};

}