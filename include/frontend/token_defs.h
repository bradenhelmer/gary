// Token Macros
//
// Macro structure borrowed from Clang's Token defs.

#ifndef GARY_TOKEN
#define GARY_TOKEN(NAME)
#endif

#ifndef GARY_KEYWORD
#define GARY_KEYWORD(NAME, SYMBOL) GARY_TOKEN(kw_##NAME)
#endif

#ifndef GARY_PUNCTUATOR
#define GARY_PUNCTUATOR(NAME, SYMBOL) GARY_TOKEN(NAME)
#endif

GARY_TOKEN(comment)
GARY_TOKEN(id)
GARY_TOKEN(newline)
GARY_TOKEN(int_literal)
GARY_TOKEN(float_literal)

GARY_KEYWORD(f32, "f32")
GARY_KEYWORD(i32, "i32")
GARY_KEYWORD(fn, "fn")
GARY_KEYWORD(return, "return")
GARY_KEYWORD(init, "in")
GARY_KEYWORD(map, "map")
GARY_KEYWORD(reduce, "reduce")
GARY_KEYWORD(acc, "acc")
GARY_KEYWORD(sqrt, "sqrt")
GARY_KEYWORD(min, "min")
GARY_KEYWORD(max, "max")

GARY_PUNCTUATOR(l_square, "[")
GARY_PUNCTUATOR(r_square, "]")
GARY_PUNCTUATOR(l_paren, "(")
GARY_PUNCTUATOR(r_paren, ")")
GARY_PUNCTUATOR(l_brace, "{")
GARY_PUNCTUATOR(r_brace, "}")
GARY_PUNCTUATOR(star, "*")
GARY_PUNCTUATOR(plus, "+")
GARY_PUNCTUATOR(minus, "-")
GARY_PUNCTUATOR(slash, "/")
GARY_PUNCTUATOR(percent, "%")
GARY_PUNCTUATOR(colon, ":")
GARY_PUNCTUATOR(semi, ";")
GARY_PUNCTUATOR(comma, ",")
GARY_PUNCTUATOR(dotdot, "..")
GARY_PUNCTUATOR(less, "<")
GARY_PUNCTUATOR(lessequal, "<=")
GARY_PUNCTUATOR(greater, ">")
GARY_PUNCTUATOR(greaterequal, ">=")
GARY_PUNCTUATOR(exclaimequal, "!=")
GARY_PUNCTUATOR(equalequal, "==")
GARY_PUNCTUATOR(arrow, "->")

#undef GARY_TOKEN
#undef GARY_KEYWORD
#undef GARY_OPERATOR
#undef GARY_PUNCTUATOR
