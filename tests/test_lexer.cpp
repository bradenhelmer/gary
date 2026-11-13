// Lexer tests

#include "frontend/lexer.h"
#include <cassert>

void test_lexer_init() {
    auto input_filename = "resources/lexer_init_test.gary";
    Lexer lexer(input_filename);
    assert(lexer.getFilename() == input_filename);
}

void test_lexer_main() { test_lexer_init(); }
