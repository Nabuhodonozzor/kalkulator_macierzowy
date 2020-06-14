#pragma once 
#include "matrixVector.hpp"
#include "inputAnalyzer.hpp"
#include "dataConverter.hpp"
#include "exceptions.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>

//interface for commands
class Command{
public:
    virtual void execute(MatrixVector &) = 0;
    ~Command();

    //method getting names of two matrices
    std::array<Matrix, 2> getMatricesToOperation(MatrixVector &);
};

//command printing the whole vector
class PrintCommand : public Command{
    void execute(MatrixVector &);
};

//command saving whole vector to a file
class SaveCommand : public Command{
    void execute(MatrixVector &);
};

//command loading from a file
class LoadCommand : public Command{
    void execute(MatrixVector &);   
};

//command adding matrix to a vector
class AddToVectorCommand : public Command{
    void execute(MatrixVector &);
};

//command adding two matrices
class AdditionCommand : public Command{
    void execute(MatrixVector &);
};

//command substracting two matrices
class SubstractionCommand : public Command{
    void execute(MatrixVector &);
};

//command called when no other command is recognised
class NullCommand : public Command{
    void execute(MatrixVector &);
};