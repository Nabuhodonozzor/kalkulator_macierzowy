#pragma once
#include "matrix.hpp"
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
    const std::string exitCommand_;
    const std::string saveCommand_;
    const std::string loadCommand_;
    std::unique_ptr<Command> command_;
    std::vector<Matrix> matrixVect_;

public:
    Menu(std::vector<Matrix> &);
    void initMenu();
    void commandPerformer();
    void commandDeterminer(const std::string &);
};