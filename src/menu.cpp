#include "menu.hpp"

Menu::Menu() : 
    startupCommand_("Matrix Calculator"),
    printCommand_("print all"),
    addCommand_("add"),
    exitCommand_("exit"){
}

Menu::~Menu(){
    delete command_;
}

void Menu::initMenu(std::vector<Matrix> &matrixVector){

    std::string input;
    matrixVect_ = matrixVector;

    while(true){
        std::cout << startupCommand_ << std::endl;
        getline(std::cin, input);
        if(input == exitCommand_) break;
        commandDeterminer(input);
        commandPerformer();
    }
}

void Menu::commandPerformer(){
    command_ -> execute(matrixVect_);
}

void Menu::commandDeterminer(const std::string &command){
    if(command == printCommand_) command_ = new PrintCommand;
    else if(command == addCommand_) command_ = new AddToVectorCommand;
    else command_  = new NullCommand;  
}