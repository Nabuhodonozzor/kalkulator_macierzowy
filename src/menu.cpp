#include "menu.hpp"

Menu::Menu(MatrixVector &matrixVector) : 
    startupCommand_("Matrix Calculator"),
    printCommand_("print"),
    addCommand_("add"),
    saveCommand_("save"),
    loadCommand_("load"),
    additionCommand_("addition"),
    substractionCommand_("substraction"),
    exitCommand_("exit"),
    matrixVect_(matrixVector){
}

void Menu::initMenu(){                                      

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
    try {command_ -> execute(matrixVect_);}                 

    catch(file_open_error & foe)            {std::cout << foe.what() << std::endl;}

    catch(bad_equals & be)                  {std::cout << be.what() << std::endl;}

    catch(matrix_already_in_vector & maiv)  {std::cout << maiv.what() << std::endl;}

    catch(unmatching_size & us_add)         {std::cout << us_add.what() << std::endl;}

    catch(no_such_matrix & nsm)             {std::cout << nsm.what() << std::endl;}
}

void Menu::commandDeterminer(const std::string &command){   
    if     (command == printCommand_)           command_ = std::make_unique<PrintCommand>();
    else if(command == addCommand_)             command_ = std::make_unique<AddToVectorCommand>();
    else if(command == saveCommand_)            command_ = std::make_unique<SaveCommand>();
    else if(command == loadCommand_)            command_ = std::make_unique<LoadCommand>();
    else if(command == additionCommand_)        command_ = std::make_unique<AdditionCommand>();
    else if(command == substractionCommand_)    command_ = std::make_unique<SubstractionCommand>();
    else                                        command_ = std::make_unique<NullCommand>();
}