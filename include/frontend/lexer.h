#pragma once

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

public:
    Lexer(std::string &&input_filename);
    ~Lexer();

    void printFile();
};
