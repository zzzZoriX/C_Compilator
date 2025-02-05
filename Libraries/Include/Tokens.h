#ifndef TOKENS_H
#define TOKENS_H

#include <ctype.h>

#include "./Include/Types.h"

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

/**
 * function which define a token type by word
 * 
 * @param last_token_type           last token type
 * @param word                      word according to which will be defined token type
 * 
 * @return                          word token type
 */
TokenType
Define_token_type(TokenType last_token_type, const char* word);

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