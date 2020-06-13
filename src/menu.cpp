#include "menu.hpp"

Menu::Menu(std::vector<Matrix> &matrixVector) : 
    matrixVect_(matrixVector),
    startupCommand_("Matrix Calculator"),
    printCommand_("print all"),
    addCommand_("add"),
    saveCommand_("save"),
    loadCommand_("load"),
    exitCommand_("exit"){
}

Menu::~Menu(){
//    delete command_;
}

void Menu::initMenu(){  //initalising menu and the working loop

    std::string input;

    while(true){
        std::cout << startupCommand_ << "\n\t>";
        getline(std::cin, input);
        if(input == exitCommand_) break;
        commandDeterminer(input);
        commandPerformer();
    }
}

void Menu::commandPerformer(){
    try{
        command_ -> execute(matrixVect_);      //dynamic polymorphism (command pattern)
    }
    catch(file_open_error & foe){
        std::cout << foe.what() << std::endl;
    }
}

void Menu::commandDeterminer(const std::string &command){                   //determinig what operation to perform
    if(command == printCommand_)        command_ = std::make_unique<PrintCommand>();
    else if(command == addCommand_)     command_ = std::make_unique<AddToVectorCommand>();
    else if(command == saveCommand_)    command_ = std::make_unique<SaveCommand>();
    else if(command == loadCommand_)    command_ = std::make_unique<LoadCommand>();
    else                                command_ = std::make_unique<NullCommand>();
}