#include "./Include/Tokens.h"
#include <stdio.h>

Token*
Define_token(Token* last_token, const char* word){
    Token* token = (Token*)malloc(sizeof(Token));
    if(!token) return NULL;

    token = &((Token)NULL_TOKEN);

    if(strcmp(word, "int") == 0)            { token->type = TOK_INT, token->value = strdup(word); }
    else if(strcmp(word, "char") == 0)      { token->type = TOK_CHAR, token->value = strdup(word); }
    else if(strcmp(word, "float") == 0)     { token->type = TOK_FLOAT, token->value = strdup(word); }

    else if(isDataType(last_token->type) && isObjVarName(word)) 
    { token->type = TOK_IDENT, token->value = strdup(word); }

    else if(isDigits(word))                 { token->type = TOK_NUMBER, token->value = strdup(word); }
    else if(*word == '+')                    { token->type = TOK_PLUS, token->value = strdup(word); }
    else if(*word == '-')                    { token->type = TOK_MINUS, token->value = strdup(word); }
    else if(*word == '*')                    { token->type = TOK_MULTI, token->value = strdup(word); }
    else if(*word == '/')                    { token->type = TOK_DIVIDE, token->value = strdup(word); }
    else if(*word == '(')                    { token->type = TOK_LPAREN, token->value = strdup(word); }
    else if(*word == ')')                    { token->type = TOK_RPAREN, token->value = strdup(word); }

    else if(*word == '=')                   { token->type = TOK_ASSIGN, token->value = strdup(word); }
    else if(*word == ';')                   { token->type = TOK_SEMIC, token->value = strdup(word); }

    return token;
}

Type
Define_type(LexerTokenType token_type){
    switch(token_type){
        case TOK_CHAR: return TYPE_CHAR;
        case TOK_FLOAT: return TYPE_FLOAT;
        case TOK_INT: return TYPE_INT;

        default: return TYPE_UNDEF;
    }
}

bool
isDataType(LexerTokenType token_type){
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

bool
isDigits(const char* str){
    for(size_t i = 0; i < strlen(str); ++i)
        if(!isdigit(str[i])) return false;

    return true;
}

bool
isValidSymbol(const char symbol)
{ return (isalnum(symbol) || symbol == '_'); }

bool
isObjVarName(const char* name){
    if(name == NULL || *name == '\0') return false;
    else if(!isalpha(*name) && *name != '_') return false;

    for(size_t i = 0; i < strlen(name); ++i)
        if(!isValidSymbol(name[i])) return false;

    return true;
}