#pragma once 
#include "matrix.hpp"
#include "inputAnalyzer.hpp"

class Command{
public:
    virtual void execute(std::vector<Matrix> &) = 0;
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