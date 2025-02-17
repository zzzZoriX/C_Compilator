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
    char* value;
} Token;

#define NULL_TOKEN {TOK_NULL, NULL}

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
 * function which define a type by token-type
 * 
 * @param token_type                token-type by which type will be defined
 * 
 * @return                          type
 */
Type
Define_type(TokenType token_type);

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


/* for variables / objects */
/**
 * validate symbol for variable / object name
 * 
 * @param symbol                    symbol which need to validate
 * 
 * @return                          1 or 0 (true of false)
 */
bool
isValidSymbol(const char symbol);

/**
 * checking geted name for can be this a name for object or variable 
 * 
 * @param name                      name which will be checked
 * 
 * @return                          1 or 0 (true or false)
 */
bool
isObjVarName(const char* name);

#endif