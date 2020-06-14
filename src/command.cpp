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
    auto eq_count = std::count(rawInput.begin(), rawInput.end(), '=');

    if(eq_count != 1) throw bad_equals(eq_count);

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
    
    auto matrixArray = getMatricesToOperation(matrixVect);
    auto product = sub_add(matrixArray.at(0), matrixArray.at(1), 0);
    auto productName = product.getName();

    if(matrixVect.isMatrixInVector(productName)) throw matrix_already_in_vector(productName);
    else matrixVect.push_back(product);
}

void SubstractionCommand::execute(MatrixVector & matrixVect){

    auto matrixArray = getMatricesToOperation(matrixVect);
    auto product = sub_add(matrixArray.at(0), matrixArray.at(1), 1);
    auto productName = product.getName();

    if(matrixVect.isMatrixInVector(productName)) throw matrix_already_in_vector(productName);
    else matrixVect.push_back(product);
}

void NullCommand::execute(MatrixVector & matrixVect){
    std::cout << "Undefined command" << std::endl;
}

std::array<Matrix, 2> Command::getMatricesToOperation(MatrixVector & matrixVect){

    std::string leftName, rightName;

    std::cout << "Give left matrix name: ";
    getline(std::cin, leftName);
    leftName.erase(std::remove_if(leftName.begin(), leftName.end(), ::isspace), leftName.end());

    std::cout << "Give right matrix name:";
    getline(std::cin, rightName);
    rightName.erase(std::remove_if(rightName.begin(), rightName.end(), ::isspace), rightName.end());

    auto leftMatrix  = matrixVect.getCertainMatrix(leftName);
    auto rightMatrix = matrixVect.getCertainMatrix(rightName);

    std::array<Matrix, 2> arrayToReturn = {leftMatrix, rightMatrix};
    return arrayToReturn;
}