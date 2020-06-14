#pragma once 
#include "matrixVector.hpp"
#include "inputAnalyzer.hpp"
#include "dataConverter.hpp"
#include "exceptions.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>

class Command{
public:
    virtual void execute(MatrixVector &) = 0;
    ~Command();

    std::array<Matrix, 2> getMatricesToOperation(MatrixVector &);
};

class PrintCommand : public Command{
    void execute(MatrixVector &);
};

class SaveCommand : public Command{
    void execute(MatrixVector &);
};

class LoadCommand : public Command{
    void execute(MatrixVector &);   
};

class AddToVectorCommand : public Command{
    void execute(MatrixVector &);
};

class AdditionCommand : public Command{
    void execute(MatrixVector &);
};

class SubstractionCommand : public Command{
    void execute(MatrixVector &);
};

class NullCommand : public Command{
    void execute(MatrixVector &);
};