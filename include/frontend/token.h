#pragma once

#include <functional>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

enum TokenKind {
#define GARY_TOKEN(X) X,
#include "frontend/token_defs.h"
};

// Mark Hash and KeyEquals types as transparent to allow lookup of strings with string_views.
struct StringHash {
    using is_transparent = void;
    std::size_t operator()(std::string_view sv) const { return std::hash<std::string_view>{}(sv); }
};

struct StringEquals {
    using is_transparent = void;
    bool operator()(std::string_view a, std::string_view b) const { return a == b; }
};

static const std::unordered_map<std::string, TokenKind, StringHash, StringEquals> keywordMap = {
#define GARY_KEYWORD(NAME) {#NAME, kw_##NAME},
#include "frontend/token_defs.h"
};

struct Token {
    TokenKind kind;
    std::optional<std::string_view> str_value;
};
