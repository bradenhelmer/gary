#pragma once

#include "frontend/token.h"
#include <format>
#include <string>

// Lexer class definition.
//
// As well as lexical analysis, the Lexer is also resonsible for source file management.
// This includes opening and closing the input file, and tracking line and column information.
class Lexer {

private:
    std::string input_filename;
    int input_fd;
    size_t input_file_size;

    char *start;
    char *curr;

    int curr_line;
    int curr_col;

    void init();
    void eatWhitespace();
    Token lexComment();
    Token lexIdOrKeyword();
    Token lexIntOrFloatLiteral();
    void throwLexError(int offset = 1) const {
        throw std::runtime_error(std::format("Unknown token starting with '{}', at {}:{}:{}",
                                             *(curr - offset), input_filename, curr_line,
                                             curr_col - offset));
    }

public:
    Lexer(std::string &&input_filename);
    ~Lexer();

    void printFile();
    const std::string &getFilename() const { return input_filename; }
    Token lexToken();
};
