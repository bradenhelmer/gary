#pragma once

#include "frontend/lexer.h"
#include <string>
class Parser {

private:
    Lexer lexer;

public:
    Parser(std::string input_filename);

    void printFile() { lexer.printFile(); }
};
