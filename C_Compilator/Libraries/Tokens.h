#ifndef TOKENS_H
#define TOKENS_H

#include "Types.h"

typedef enum TokenType {
    TOK_INT,
    TOK_CHAR,
    TOK_FLOAT,

    TOK_IDENT,

    TOK_ASSIGN,
    TOK_SEMIC
} TokenType;

typedef struct Token {
    TokenType type;
    Value value;
} Token;

#endif