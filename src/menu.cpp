#include "menu.hpp"

Menu::Menu() : 
    startupCommand_("Matrix Calculator"),
    printCommand_("print all"),
    addCommand_("add"),
    exitCommand_("exit"){
}

void Menu::initMenu(std::vector<Matrix> &matrixVector){

    std::string input;

    while(true){
        std::cout << startupCommand_ << std::endl;
        getline(std::cin, input);
        if(input == exitCommand_) break;
        commandPerformer(matrixVector, commandDeterminer(input));
    }
}


void Menu::commandPerformer(std::vector<Matrix> &matrixVector, const unsigned short &intcommand){
    InputAnalyzer analyzer;
    switch(intcommand){
        case 1:
            for(auto current : matrixVector) std::cout << current << std::endl;
        break;
        case 2:
            matrixVector.push_back(analyzer.getNewMatrix());
        break;
        case 0: 
            std::cout << "Invalid input" << std::endl;
        break; 
    }
    
}

unsigned short Menu::commandDeterminer(const std::string &command){
    if(command == printCommand_) return 1;
    else if(command == addCommand_) return 2;
    else return 0;  
}