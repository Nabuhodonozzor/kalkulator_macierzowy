#include "command.hpp"

void PrintCommand::execute(std::vector<Matrix> & matrixVect){
    std::cout << std::endl;
    for(auto current : matrixVect){
        std::cout << current.getName() << '=' << std::endl;
        std::cout << std::showpoint;
        for(auto currentRow : current.getValues()){
            for(auto currentValue : currentRow){
                std::cout << std::setprecision(3) << std::setw(5) << currentValue << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void AddToVectorCommand::execute(std::vector<Matrix> & matrixVect){
    matrixVect.push_back(InputAnalyzer().initiateDecompositon());
}

void SaveCommand::execute(std::vector<Matrix> & matrixVect){
    std::cout << "save" << std::endl;
}

void LoadCommand::execute(std::vector<Matrix> & matrixVect){
    std::cout << "load" << std::endl;
}

void NullCommand::execute(std::vector<Matrix> & matrixVect){
    std::cout << "Undefined command" << std::endl;
}