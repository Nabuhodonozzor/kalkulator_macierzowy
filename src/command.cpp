#include "command.hpp"

Command::~Command(){}

void PrintCommand::execute(MatrixVector & matrixVect){

    auto matrixVector = matrixVect.getVector();

    std::cout << std::endl;
    for(auto current : matrixVector){
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

void AddToVectorCommand::execute(MatrixVector & matrixVect){

    std::string rawInput;

    std::cout << "Input: ";
    getline(std::cin, rawInput);

    if(rawInput.find('=') == std::string::npos) throw bad_equals();

    auto matrixToAdd = InputAnalyzer().initiateDecompositon(rawInput);
    auto nameToCheck = matrixToAdd.getName();

    if(matrixVect.isMatrixInVector(nameToCheck)) throw matrix_already_in_vector(nameToCheck);

    auto ajustedMatrix = DataConverter().fillBlank(matrixToAdd);
    
    matrixVect.push_back(ajustedMatrix);
}

void SaveCommand::execute(MatrixVector & matrixVect){

    auto matrixVector = matrixVect.getVector();

    std::string filename("savefile.txt");
    std::ofstream file;
    file.open(filename, std::ios::out);

    if(file.is_open()){
        for(auto current : matrixVector){
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

void LoadCommand::execute(MatrixVector & matrixVect){
     
    std::string currentlyLoaded, filename("savefile.txt");
    std::ifstream file;
    file.open(filename, std::ios::in);

    if(file.is_open()){
        while(getline(file, currentlyLoaded)){
            auto currentMatrix = InputAnalyzer().initiateDecompositon(currentlyLoaded);
            matrixVect.push_back(currentMatrix);
        }
    }
    else throw file_open_error(filename);
}

void AdditionCommand::execute(MatrixVector & matrixVect){
    std::cout << "addition" << std::endl;
}

void SubstractionCommand::execute(MatrixVector & matrixVect){
    std::cout << "substraction" << std::endl;
}

void NullCommand::execute(MatrixVector & matrixVect){
    std::cout << "Undefined command" << std::endl;
}