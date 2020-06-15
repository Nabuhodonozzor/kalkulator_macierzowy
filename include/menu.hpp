#pragma once
#include "matrixVector.hpp"
#include "inputAnalyzer.hpp"
#include "command.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <memory>




class Menu{
private:
    const std::string startupCommand_;
    const std::string printCommand_;
    const std::string addCommand_;
    const std::string saveCommand_;
    const std::string loadCommand_;
    const std::string additionCommand_;
    const std::string substractionCommand_;
    const std::string helpCommand_;
    const std::string exitCommand_;
    std::unique_ptr<Command> command_;
    MatrixVector matrixVect_;

public:
    Menu(MatrixVector &);

    //initialisig menu and the working loop
    void initMenu();

    //performing commands (dynamic polymorphism)
    void commandPerformer();

    //determininig which command to perform
    void commandDeterminer(const std::string &);
};