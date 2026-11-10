#pragma once

enum TokenKind {
#define GARY_TOKEN(X) X,
#include "frontend/token_defs.h"
};

struct Token {
    TokenKind kind;
};
