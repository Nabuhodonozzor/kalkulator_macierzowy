#include "command.hpp"

void PrintCommand::execute(std::vector<Matrix> & matrixVect){
    for(auto current : matrixVect) std::cout << current << std::endl;
}

void AddToVectorCommand::execute(std::vector<Matrix> & matrixVect){
    matrixVect.push_back(InputAnalyzer().initiateDecompositon());
}

void NullCommand::execute(std::vector<Matrix> & matrixVect){
    std::cout << "Undefined command" << std::endl;
}