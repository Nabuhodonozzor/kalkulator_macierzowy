#pragma once 
#include "matrix.hpp"
#include "inputAnalyzer.hpp"
#include <fstream>
#include <exception>

class Command{
public:
    virtual void execute(std::vector<Matrix> &) = 0;
    ~Command();
};

class PrintCommand : public Command{
    void execute(std::vector<Matrix> &) override;
};

class SaveCommand : public Command{
    void execute(std::vector<Matrix> &);
};

class LoadCommand : public Command{
    void execute(std::vector<Matrix> &);   
};

class AddToVectorCommand : public Command{
    void execute(std::vector<Matrix> &);
};

class NullCommand : public Command{
    void execute(std::vector<Matrix> &);
};