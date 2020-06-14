#include "inputAnalyzer.hpp"

Matrix InputAnalyzer::initiateDecompositon(std::string & rawInput){
    
    std::vector<std::string> segmentatedString;

    segmentatedString.push_back(rawInput.substr(0, rawInput.find('=')));
    segmentatedString.push_back(rawInput.substr(rawInput.find('=') + 1));

    return Matrix(segmentatedString.at(0), setValues(segmentatedString.at(1)));
}

data_type InputAnalyzer::setValues(std::string &rawDataString){

    std::vector<std::string> rowString;
    data_type values;
    std::stringstream dataSS(rawDataString);
    std::string temp;

    while(getline(dataSS, temp, ';')) rowString.push_back(temp);

    for(auto current : rowString){
        
        std::vector<double> rowValues;
        std::string::size_type pos = 0;
        double currentValue;

        while(pos != std::string::npos){
            try{
                currentValue = std::stod(current,  &pos);
                rowValues.push_back(currentValue);
                current.erase(0, pos);
                }
            catch(const std::invalid_argument end_of_values){break;}
        }
        values.push_back(rowValues);
    }
    return values;
}