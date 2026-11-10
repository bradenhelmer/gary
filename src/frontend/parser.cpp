
#include "frontend/parser.h"

Parser::Parser(std::string filename) : lexer(std::move(filename)) {}
