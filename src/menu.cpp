#include "menu.hpp"

Menu::Menu() : 
    startupCommand_("Matrix Calculator"),
    printCommand_("print all"),
    addCommand_("add"),
    saveCommand_("save"),
    loadCommand_("load"),
    exitCommand_("exit"){
}

Menu::~Menu(){
    delete command_;
}

void Menu::initMenu(std::vector<Matrix> &matrixVector){  //initalising menu and the working loop

    std::string input;
    matrixVect_ = matrixVector;

    while(true){
        std::cout << startupCommand_ << "\n\t>";
        getline(std::cin, input);
        if(input == exitCommand_) break;
        commandDeterminer(input);
        commandPerformer();
    }
}

void Menu::commandPerformer(){
    command_ -> execute(matrixVect_);  //dynamic polymorphism (command pattern)
}

void Menu::commandDeterminer(const std::string &command){                   //determinig what operation to perform
    if(command == printCommand_)        command_ = new PrintCommand;
    else if(command == addCommand_)     command_ = new AddToVectorCommand;
    else if(command == saveCommand_)    command_ = new SaveCommand;
    else if(command == loadCommand_)    command_ = new LoadCommand;
    else                                command_ = new NullCommand;  
}