#pragma once
#include "matrix.hpp"
#include "inputAnalyzer.hpp"
#include <string>
#include <iostream>
#include <vector>



class Menu{
private:
    const std::string startupCommand_;
    const std::string printCommand_;
    const std::string addCommand_;
    const std::string exitCommand_;

public:
    Menu();
    void initMenu(std::vector<Matrix> &);
    void commandPerformer(std::vector<Matrix> &, const unsigned short &);
    unsigned short commandDeterminer(const std::string &);
};