#pragma once
#include "include/printer.hpp"

class terminalPrinter : public Printer{
public:
    void print() const override;
};