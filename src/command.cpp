#include "command.hpp"

Command::~Command(){}

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

    std::string rawInput;

    std::cout << "Input: ";
    getline(std::cin, rawInput);

    auto matrixToAdd = InputAnalyzer().initiateDecompositon(rawInput);
    
    matrixVect.push_back(DataConverter().fillBlank(matrixToAdd));
}

void SaveCommand::execute(std::vector<Matrix> & matrixVect){

    std::string filename("savefile.txt");
    std::ofstream file;
    file.open(filename, std::ios::out);

    if(file.is_open()){
        for(auto current : matrixVect){
            file << current.getName() << " = ";
            for(auto currentRow : current.getValues()){
                for(auto currentValue : currentRow){
                    file << currentValue << ' ';
                }
                file << ';';
            }
            file << std::endl;
        }
        file.close();
    }
    else throw file_open_error(filename);
}

void LoadCommand::execute(std::vector<Matrix> & matrixVect){
    
    std::string currentlyLoaded, filename("savefile.txt");
    std::ifstream file;
    file.open(filename, std::ios::in);

    if(file.is_open()){
        while(getline(file, currentlyLoaded)){
            matrixVect.push_back(InputAnalyzer().initiateDecompositon(currentlyLoaded));
        }
    }
    else throw file_open_error(filename);
}

void NullCommand::execute(std::vector<Matrix> & matrixVect){
    std::cout << "Undefined command" << std::endl;
}