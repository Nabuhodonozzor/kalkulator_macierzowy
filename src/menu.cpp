#include "menu.hpp"

Menu::Menu() : 
    startupCommand("Matrix Calculator"),
    printCommand("print all"),
    exitCommand("exit"){
}

void Menu::initMenu(std::vector<Matrix> &matrixVector){

    std::string input;

    while(true){
        std::cout << startupCommand << std::endl;
        getline(std::cin, input);
        if(input == exitCommand) break;
        commandPerformer(matrixVector, commandDeterminer(input));
    }
}


void Menu::commandPerformer(std::vector<Matrix> &matrixVector, const unsigned short &intcommand){
    switch(intcommand){
        case 1:
            for(auto current : matrixVector){
                std::cout << current << std::endl;
            }
        break;
    }
    
}

unsigned short Menu::commandDeterminer(const std::string &command){
    if(command == printCommand){
        return 1;
    }
    else{
        return 0;
    }
}