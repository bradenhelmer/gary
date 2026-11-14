// Lexer tests

#include "frontend/lexer.h"
#include "frontend/token.h"
#include <cassert>
#include <iostream>

void test_lexer_init() {
    auto input_filename = "resources/one.gary";
    Lexer lexer(input_filename);
    assert(lexer.getFilename() == input_filename);
}

void test_lexer_dist() {
    auto dist = "resources/dist.gary";
    Lexer dist_lexer(dist);

    constexpr Token dist_expected_tokens[] = {
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
        Token(TokenKind::comma),
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

    for (auto expected_dist_token : dist_expected_tokens) {
        auto actual = dist_lexer.lexToken();
        std::cerr << "Actual: " << actual.kind << " Expected: " << expected_dist_token.kind << "\n";
        assert(actual.kind == expected_dist_token.kind);
    }
}

void test_lexer_saxpy() {
    auto saxpy = "resources/saxpy.gary";
    Lexer saxpy_lexer(saxpy);

    constexpr Token saxpy_expected_tokens[] = {
        // clang-format off
        Token(TokenKind::kw_fn),
        Token(TokenKind::id),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_i32),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_f32),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::l_square),
        Token(TokenKind::kw_f32),
        Token(TokenKind::r_square),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::l_square),
        Token(TokenKind::kw_f32),
        Token(TokenKind::r_square),
        Token(TokenKind::r_paren),
        Token(TokenKind::arrow),
        Token(TokenKind::l_square),
        Token(TokenKind::kw_f32),
        Token(TokenKind::r_square),
        Token(TokenKind::l_brace),
        Token(TokenKind::newline),
        Token(TokenKind::kw_return),
        Token(TokenKind::kw_map),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::id),
        Token(TokenKind::int_literal),
        Token(TokenKind::dotdot),
        Token(TokenKind::id),
        Token(TokenKind::r_paren),
        Token(TokenKind::l_brace),
        Token(TokenKind::id),
        Token(TokenKind::star),
        Token(TokenKind::id),
        Token(TokenKind::l_square),
        Token(TokenKind::id),
        Token(TokenKind::r_square),
        Token(TokenKind::plus),
        Token(TokenKind::id),
        Token(TokenKind::l_square),
        Token(TokenKind::id),
        Token(TokenKind::r_square),
        Token(TokenKind::semi),
        Token(TokenKind::newline),
        Token(TokenKind::r_brace),
        // clang-format on
    };

    for (auto expected_saxpy_token : saxpy_expected_tokens) {
        auto actual = saxpy_lexer.lexToken();
        std::cerr << "Actual: " << actual.kind << " Expected: " << expected_saxpy_token.kind
                  << "\n";
        assert(actual.kind == expected_saxpy_token.kind);
    }
}

void test_lexer_dot() {
    auto dot = "resources/dot.gary";
    Lexer dot_lexer(dot);

    constexpr Token dot_expected_tokens[] = {
        // clang-format off
        Token(TokenKind::kw_fn),
        Token(TokenKind::id),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_i32),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::l_square),
        Token(TokenKind::kw_f32),
        Token(TokenKind::r_square),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::l_square),
        Token(TokenKind::kw_f32),
        Token(TokenKind::r_square),
        Token(TokenKind::r_paren),
        Token(TokenKind::arrow),
        Token(TokenKind::kw_f32),
        Token(TokenKind::l_brace),
        Token(TokenKind::newline),
        Token(TokenKind::kw_return),
        Token(TokenKind::kw_reduce),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::id),
        Token(TokenKind::int_literal),
        Token(TokenKind::dotdot),
        Token(TokenKind::id),
        Token(TokenKind::comma),
        Token(TokenKind::kw_init),
        Token(TokenKind::float_literal),
        Token(TokenKind::r_paren),
        Token(TokenKind::l_brace),
        Token(TokenKind::kw_acc),
        Token(TokenKind::plus),
        Token(TokenKind::id),
        Token(TokenKind::l_square),
        Token(TokenKind::id),
        Token(TokenKind::r_square),
        Token(TokenKind::star),
        Token(TokenKind::id),
        Token(TokenKind::l_square),
        Token(TokenKind::id),
        Token(TokenKind::r_square),
        Token(TokenKind::semi),
        Token(TokenKind::newline),
        Token(TokenKind::r_brace),
        // clang-format on
    };

    for (auto expected_dot_token : dot_expected_tokens) {
        auto actual = dot_lexer.lexToken();
        std::cerr << "Actual: " << actual.kind << " Expected: " << expected_dot_token.kind << "\n";
        assert(actual.kind == expected_dot_token.kind);
    }
}

void test_lexer_mm() {
    auto mm_test = "resources/mm_test.gary";
    Lexer mm_lexer(mm_test);

    constexpr Token mm_expected_tokens[] = {
        // clang-format off
        Token(TokenKind::kw_fn),
        Token(TokenKind::id),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_i32),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_i32),
        Token(TokenKind::r_paren),
        Token(TokenKind::l_brace),
        Token(TokenKind::newline),
        Token(TokenKind::kw_return),
        Token(TokenKind::l_paren),
        Token(TokenKind::kw_min),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::r_paren),
        Token(TokenKind::minus),
        Token(TokenKind::kw_max),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::comma),
        Token(TokenKind::id),
        Token(TokenKind::r_paren),
        Token(TokenKind::r_paren),
        Token(TokenKind::slash),
        Token(TokenKind::int_literal),
        Token(TokenKind::semi),
        Token(TokenKind::newline),
        Token(TokenKind::r_brace),
        // clang-format on
    };

    for (auto expected_mm_token : mm_expected_tokens) {
        auto actual = mm_lexer.lexToken();
        std::cerr << "Actual: " << actual.kind << " Expected: " << expected_mm_token.kind << "\n";
        assert(actual.kind == expected_mm_token.kind);
    }
}

void test_lexer_modulo() {
    auto modulo_test = "resources/modulo_test.gary";
    Lexer modulo_lexer(modulo_test);

    constexpr Token modulo_expected_tokens[] = {
        // clang-format off
        Token(TokenKind::kw_fn),
        Token(TokenKind::id),
        Token(TokenKind::l_paren),
        Token(TokenKind::id),
        Token(TokenKind::colon),
        Token(TokenKind::kw_i32),
        Token(TokenKind::r_paren),
        Token(TokenKind::l_brace),
        Token(TokenKind::newline),
        Token(TokenKind::kw_return),
        Token(TokenKind::id),
        Token(TokenKind::percent),
        Token(TokenKind::int_literal),
        Token(TokenKind::semi),
        Token(TokenKind::newline),
        Token(TokenKind::r_brace),
        // clang-format on
    };

    for (auto expected_modulo_token : modulo_expected_tokens) {
        auto actual = modulo_lexer.lexToken();
        std::cerr << "Actual: " << actual.kind << " Expected: " << expected_modulo_token.kind
                  << "\n";
        assert(actual.kind == expected_modulo_token.kind);
    }
}

void test_lexer_mega_comp() {
    auto mega_comp_test = "resources/mega_comp_test.gary";
    Lexer mega_comp_lexer(mega_comp_test);

    constexpr Token mega_comp_expected_tokens[] = {
        // clang-format off
        Token(TokenKind::comment),
        Token(TokenKind::newline),
        Token(TokenKind::kw_fn),
        Token(TokenKind::id),
        Token(TokenKind::l_paren),
        Token(TokenKind::r_paren),
        Token(TokenKind::l_brace),
        Token(TokenKind::newline),
        Token(TokenKind::kw_return),
        Token(TokenKind::l_paren),
        Token(TokenKind::int_literal),
        Token(TokenKind::equalequal),
        Token(TokenKind::int_literal),
        Token(TokenKind::r_paren),
        Token(TokenKind::plus),
        Token(TokenKind::l_paren),
        Token(TokenKind::int_literal),
        Token(TokenKind::exclaimequal),
        Token(TokenKind::int_literal),
        Token(TokenKind::r_paren),
        Token(TokenKind::plus),
        Token(TokenKind::l_paren),
        Token(TokenKind::int_literal),
        Token(TokenKind::greater),
        Token(TokenKind::int_literal),
        Token(TokenKind::r_paren),
        Token(TokenKind::plus),
        Token(TokenKind::l_paren),
        Token(TokenKind::int_literal),
        Token(TokenKind::greaterequal),
        Token(TokenKind::int_literal),
        Token(TokenKind::r_paren),
        Token(TokenKind::plus),
        Token(TokenKind::l_paren),
        Token(TokenKind::int_literal),
        Token(TokenKind::less),
        Token(TokenKind::int_literal),
        Token(TokenKind::r_paren),
        Token(TokenKind::plus),
        Token(TokenKind::l_paren),
        Token(TokenKind::int_literal),
        Token(TokenKind::lessequal),
        Token(TokenKind::int_literal),
        Token(TokenKind::r_paren),
        Token(TokenKind::semi),
        Token(TokenKind::newline),
        Token(TokenKind::r_brace),
        // clang-format on
    };

    for (auto expected_mega_comp_token : mega_comp_expected_tokens) {
        auto actual = mega_comp_lexer.lexToken();
        std::cerr << "Actual: " << actual.kind << " Expected: " << expected_mega_comp_token.kind
                  << "\n";
        assert(actual.kind == expected_mega_comp_token.kind);
    }
}

void test_lexer_main() {
    test_lexer_init();
    test_lexer_dist();
    test_lexer_saxpy();
    test_lexer_dot();
    test_lexer_mm();
    test_lexer_modulo();
    test_lexer_mega_comp();
}
