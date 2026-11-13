// Lexer tests

#include "frontend/lexer.h"
#include "frontend/token.h"
#include <cassert>
#include <vector>

void test_lexer_init() {
    auto input_filename = "resources/lexer_init_test.gary";
    Lexer lexer(input_filename);
    assert(lexer.getFilename() == input_filename);
}

void test_lexer_full() {
    auto input_filename = "resources/lexer_full_test.gary";
    Lexer lexer(input_filename);

    constexpr Token expected_tokens[] = {
        // clang-format off
        Token(TokenKind::kw_fn),
        Token(TokenKind::id),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_f32),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_f32),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_f32),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_f32),
        Token(TokenKind::r_paren),
        Token(TokenKind::arrow),
        Token(TokenKind::kw_f32),
        Token(TokenKind::l_brace),
        Token(TokenKind::newline),
        Token(TokenKind::kw_return),
        Token(TokenKind::kw_sqrt),
        Token(TokenKind::l_paren),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::minus),
        Token(TokenKind::id),
        Token(TokenKind::r_paren),
        Token(TokenKind::star),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::minus),
        Token(TokenKind::id),
        Token(TokenKind::r_paren),
        Token(TokenKind::plus),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::minus),
        Token(TokenKind::id),
        Token(TokenKind::r_paren),
        Token(TokenKind::star),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::minus),
        Token(TokenKind::id),
        Token(TokenKind::r_paren),
        Token(TokenKind::r_paren),
        Token(TokenKind::semi),
        Token(TokenKind::newline),
        Token(TokenKind::r_brace),
        // clang-format on
    };

    for (auto expected_token : expected_tokens) {
        auto actual = lexer.lexToken();
        assert(actual.kind == expected_token.kind);
    }
}

void test_lexer_main() {
    test_lexer_init();
    test_lexer_full();
}
