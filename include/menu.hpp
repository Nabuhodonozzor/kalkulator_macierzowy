#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "matrix.hpp"


class Menu{
private:
    const std::string startupCommand;
    const std::string printCommand;
    const std::string exitCommand;

public:
    Menu();
    void initMenu(std::vector<Matrix> &);
    void commandPerformer(std::vector<Matrix> &, const unsigned short &);
    unsigned short commandDeterminer(const std::string &);
};