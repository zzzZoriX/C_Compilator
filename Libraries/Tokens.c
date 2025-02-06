#include "./Include/Tokens.h"

TokenType
Define_token_type(TokenType last_token_type, const char* word){
    if(strcmp(word, "int") == 0)            return TOK_INT;
    else if(strcmp(word, "char") == 0)      return TOK_CHAR;
    else if(strcmp(word, "float") == 0)     return TOK_FLOAT;

    else if(isDataType(last_token_type) && isAlpha(word)) return TOK_IDENT;

    else if(word == '=')                    return TOK_ASSIGN;
    else if(word == ';')                    return TOK_SEMIC;
}

bool
isDataType(TokenType token_type){
    if(
        token_type == TOK_INT ||
        token_type == TOK_CHAR ||
        token_type == TOK_FLOAT
    ) return true;
    return false;
}

bool
isAlpha(const char* str){
    for(size_t i = 0; i < strlen(str); ++i)
        if(!isalpha(str[i])) return false;

    return true;
}