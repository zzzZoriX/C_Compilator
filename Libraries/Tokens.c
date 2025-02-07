#include "./Include/Tokens.h"

Token*
Define_token(Token* last_token, const char* word){
    Token* token = (Token*)malloc(sizeof(Token));
    if(!token) return NULL;

    if(strcmp(word, "int") == 0)            { token->type = TOK_INT, token->name = NULL, token->value = (Value){0}; }
    else if(strcmp(word, "char") == 0)      { token->type = TOK_CHAR, token->name = NULL, token->value = (Value){0}; }
    else if(strcmp(word, "float") == 0)     { token->type = TOK_FLOAT, token->name = NULL, token->value = (Value){0}; }

    else if(isDataType(last_token->type) && isAlpha(word)) { token->type = TOK_IDENT, token->name = strdup(word), token->value = (Value){0}; }

    else if(*word == '=')                    { token->type = TOK_ASSIGN, token->name = NULL, token->value = (Value){0}; }
    else if(*word == ';')                    { token->type = TOK_SEMIC, token->name = NULL, token->value = (Value){0}; }
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