#include "frontend/lexer.h"
#include <cctype>
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

Token Lexer::lexIdOrKeyword() {
    // Here we assume curr is at the second position of the identifier.
    char *start = curr - 1;
    auto isIdChar = [&](char c) { return isdigit(c) || isalpha(c) || c == '_'; };
    while (isIdChar(*curr)) {
        curr++;
    }
    std::string_view lexeme(start, curr - start);
    auto it = keywordMap.find(lexeme);
    if (it != keywordMap.end()) {
        return Token(it->second, lexeme);
    }
    return Token(TokenKind::id, lexeme);
}

Token Lexer::lexIntOrFloatLiteral() { return Token(TokenKind::int_literal); }

Token Lexer::lexComment() {
    // Here we assume curr is at the first character after the '//'
    while (*curr != '\n') {
        curr++;
    }
    return Token(TokenKind::comment);
}

Token Lexer::lexToken() {
    eatWhitespace();

    const char peek = *(curr + 1);
    curr_col++;
    switch (*(curr++)) {
    // Punctuator/start of punctuator cases.
    case '[':
        return Token(TokenKind::l_brace);
    case ']':
        return Token(TokenKind::r_square);
    case '(':
        return Token(TokenKind::l_paren);
    case ')':
        return Token(TokenKind::r_paren);
    case '{':
        return Token(TokenKind::l_brace);
    case '}':
        return Token(TokenKind::r_brace);
    case '*':
        return Token(TokenKind::star);
    case '+':
        return Token(TokenKind::plus);
    case '-':
        if (*curr == '>') {
            curr++;
            curr_col++;
            return Token(TokenKind::arrow);
        }
        return Token(TokenKind::minus);
    case '/':
        if (*curr == '/') {
            curr++;
            curr_col++;
            return lexComment();
        }
        return Token(TokenKind::slash);
    case '%':
        return Token(TokenKind::percent);
    case '<':
        if (*curr == '=') {
            curr++;
            curr_col++;
            return Token(TokenKind::lessequal);
        }
        return Token(TokenKind::less);
    case '>':
        if (*curr == '=') {
            curr++;
            curr_col++;
            return Token(TokenKind::greaterequal);
        }
        return Token(TokenKind::greater);
    case '!':
        if (*curr == '=') {
            curr++;
            curr_col++;
            return Token(TokenKind::exclaimequal);
        }
        throwLexError();
    case '=':
        if (*curr == '=') {
            curr++;
            curr_col++;
            return Token(TokenKind::equalequal);
        }
        throwLexError();
    case ':':
        return Token(TokenKind::colon);
    case ';':
        return Token(TokenKind::semi);
    case ',':
        return Token(TokenKind::comma);
    case '.':
        if (*curr == '.') {
            curr++;
            curr_col++;
            return Token(TokenKind::dotdot);
        }
        throwLexError();
    // Newline
    case '\n':
        curr_line++;
        return Token(TokenKind::newline);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return lexIntOrFloatLiteral();
    // Identifiers/Keywords
    // clang-format off
    case 'A': case 'B': case 'C': case 'D': case 'E':
    case 'F': case 'G': case 'H': case 'I': case 'J':
    case 'K': case 'L': case 'M': case 'N': case 'O':
    case 'P': case 'Q': case 'R': case 'S': case 'T':
    case 'U': case 'V': case 'W': case 'X': case 'Y':
    case 'Z':
    case 'a': case 'b': case 'c': case 'd': case 'e':
    case 'f': case 'g': case 'h': case 'i': case 'j':
    case 'k': case 'l': case 'm': case 'n': case 'o':
    case 'p': case 'q': case 'r': case 's': case 't':
    case 'u': case 'v': case 'w': case 'x': case 'y':
    case 'z':
    case '_':  
        return lexIdOrKeyword();
        // clang-format on
    }
}
