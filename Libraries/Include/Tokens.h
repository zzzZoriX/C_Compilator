#ifndef TOKENS_H
#define TOKENS_H

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "Types.h"

typedef enum TokenType {
    TOK_INT,
    TOK_CHAR,
    TOK_FLOAT,

    TOK_IDENT,

    TOK_ASSIGN,
    TOK_SEMIC,

    TOK_NULL
} TokenType;

typedef struct Token {
    TokenType type;
    char* name;
    Value value;
} Token;

Token NULL_TOKEN = {TOK_NULL, NULL, {0}};

/**
 * function which define a token by word
 * 
 * @param last_token                last token
 * @param word                      word according to which will be defined token type
 * 
 * @return                          variable pointer or token pointer
 */
Token*
Define_token(Token* last_token, const char* word);

/**
 * check to token type is data type
 * 
 * @param token_type                token type which will be checked
 * 
 * @return                          1 or 0 (true or false)
 */
bool
isDataType(TokenType token_type);

/**
 * check to string is all char
 * 
 * @param str                       string which need to check
 * 
 * @return                          1 or 0 (true or false)  
 */
bool
isAlpha(const char* str);

#endif