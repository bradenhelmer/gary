#include "frontend/lexer.h"
#include <fcntl.h>
#include <iostream>
#include <stdexcept>
#include <sys/mman.h>
#include <unistd.h>

Lexer::Lexer(std::string &&input_filename) : input_filename(std::move(input_filename)) { init(); }

void Lexer::init() {

    input_fd = open(input_filename.c_str(), O_RDONLY);
    if (input_fd == -1) {
        throw std::runtime_error(std::format("Error opening file {}\n", input_filename));
    }

    input_file_size = lseek(input_fd, 0, SEEK_END);
    start =
        static_cast<char *>(mmap(nullptr, input_file_size, PROT_READ, MAP_PRIVATE, input_fd, 0));

    if (start == MAP_FAILED) {
        close(input_fd);
        throw std::runtime_error(
            std::format("Error mapping input file {} to memory.\n", input_filename));
    }

    curr = start;

    curr_line = 1;
    curr_col = 1;
}

Lexer::~Lexer() {
    munmap(start, input_file_size);
    close(input_fd);
}

void Lexer::printFile() {
    for (int i = 0; i < input_file_size; i++) {
        std::cout << start[i];
    }
}

void Lexer::eatWhitespace() {
    while (*curr == ' ' || *curr == '\t' || *curr == '\r') {
        curr++;
        curr_col++;
    }
}

Token Lexer::lexToken() {
    eatWhitespace();

    Token token;

    switch (*curr) {
    case '[':
        token.kind = TokenKind::l_brace;
        break;
    case ']':
        token.kind = TokenKind::r_square;
        break;
    case '(':
        token.kind = TokenKind::l_paren;
        break;
    case ')':
        token.kind = TokenKind::r_paren;
        break;
    case '*':
        token.kind = TokenKind::star;
        break;
    case '+':
        token.kind = TokenKind::plus;
        break;
    case '-':
        token.kind = TokenKind::minus;
        break;
    case '/':
        token.kind = TokenKind::slash;
        break;
    case '%':
        token.kind = TokenKind::percent;
        break;
    case ':':
        token.kind = TokenKind::colon;
        break;
    case ';':
        token.kind = TokenKind::semi;
    case ',':
        token.kind = TokenKind::comma;
        break;
    }
}
