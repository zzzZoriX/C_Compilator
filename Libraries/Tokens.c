#include "./Include/Tokens.h"
#include <stdio.h>
#include <string.h>

Token*
Define_token(Token* last_token, const char* word){
    Token* token = (Token*)malloc(sizeof(Token));
    if(!token) return NULL;

    token->type = TOK_NULL;
    token->value = _strdup(word);

    if(strcmp(word, "int") == 0)            token->type = TOK_INT;
    else if(strcmp(word, "char") == 0)      token->type = TOK_CHAR_T;
    else if(strcmp(word, "float") == 0)     token->type = TOK_FLOAT;
    else if(strcmp(word, "double") == 0)    token->type = TOK_DOUBLE;
    else if(strcmp(word, "string") == 0)    token->type = TOK_STRING_T;
    else if(strcmp(word, "bool") == 0)      token->type = TOK_BOOL;

    else if(
        (isDataType(last_token->type) && isObjVarName(word)) ||
        (strcmp(last_token->value, "\"") != 0 && isObjVarName(word))
    ) {
        token->type = TOK_IDENT;
    }

    else if(isDigits(word))                 token->type = TOK_NUMBER;
    else if(
        strcmp(last_token->value, "\"") &&
        isAlpha(word)
    ) {
        token->type = TOK_STRING_T;
    }

    else if(*word == '+')                    token->type = TOK_PLUS;
    else if(*word == '-')                    token->type = TOK_MINUS;
    else if(*word == '*')                    token->type = TOK_MULTI;
    else if(*word == '/')                    token->type = TOK_DIVIDE;
    else if(*word == '(')                    token->type = TOK_LPAREN;
    else if(*word == ')')                    token->type = TOK_RPAREN;

    else if(*word == '=')                   token->type = TOK_ASSIGN;
    else if(*word == ';')                   token->type = TOK_SEMIC;

    return token;
}

Type
Define_type(LexerTokenType token_type){
    switch(token_type){
        case TOK_CHAR_T: return TYPE_CHAR;
        case TOK_FLOAT: return TYPE_FLOAT;
        case TOK_INT: return TYPE_INT;
        case TOK_DOUBLE: return TYPE_DOUBLE;
        case TOK_STRING_T: return TYPE_STRING;
        case TOK_BOOL: return TYPE_BOOL;

        default: return TYPE_UNDEF;
    }
}

Type
Define_type_of_value(Token* token){
    if(strcmp(token->value, "\"")) return TYPE_STRING;
    if(strcmp(token->value, "true") || strcmp(token->value, "false")) return TYPE_BOOL;
    if(isDigits(token->value) || strcmp(token->value, "(") || isObjVarName(token->value)) return TYPE_DIGIT;

    return TYPE_UNDEF;
}

bool_t
isDataType(LexerTokenType token_type){
    if(
        token_type == TOK_INT      ||
        token_type == TOK_CHAR_T   ||
        token_type == TOK_FLOAT    ||
        token_type == TOK_DOUBLE   ||
        token_type == TOK_STRING_T ||
        token_type == TOK_BOOL
    ) return true;
    return false;
}

bool_t
isAlpha(const char* str){
    for(size_t i = 0; i < strlen(str); ++i)
        if(!isalpha(str[i])) return false;

    return true;
}

bool_t
isDigits(const char* str){
    for(size_t i = 0; i < strlen(str); ++i)
        if(!isdigit(str[i])) return false;

    return true;
}

bool_t
isValidSymbol(const char symbol)
{ return (isalnum(symbol) || symbol == '_'); }

bool_t
isObjVarName(const char* name){
    if(name == NULL || *name == '\0') return false;
    else if(!isalpha(*name) && *name != '_') return false;

    for(size_t i = 0; i < strlen(name); ++i)
        if(!isValidSymbol(name[i])) return false;

    return true;
}