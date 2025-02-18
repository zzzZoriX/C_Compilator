#include "./Include/Calculator.h"

bool
isValidExmplSymbol(TokenType tok_type){
    if(
        tok_type == TOK_NUMBER ||
        tok_type == TOK_DIVIDE ||
        tok_type == TOK_MINUS  || 
        tok_type == TOK_PLUS   ||
        tok_type == TOK_MULTI  ||
        tok_type == TOK_LPAREN ||
        tok_type == TOK_RPAREN
    ) return true;
    return false;
}

char*
Convert_tokens_to_example(Token* tokens, length_n tok_index){
    size_t total_length = 0;
    length_n current_index = tok_index;
    while(isValidExmplSymbol(tokens[current_index].type)){
        total_length += strlen(tokens[current_index].value);
        ++current_index;
    }

    char* exmpl = (char*)malloc(total_length + 1);
    exmpl[0] = '\0';

    while(isValidExmplSymbol(tokens[tok_index].type)){
        switch(tokens[tok_index].type){
            case TOK_PLUS: strcat(exmpl, tokens[tok_index].value); break;     // +
            case TOK_MINUS: strcat(exmpl, tokens[tok_index].value); break;    // -
            case TOK_MULTI: strcat(exmpl, tokens[tok_index].value); break;    // *
            case TOK_DIVIDE: strcat(exmpl, tokens[tok_index].value); break;   // /
            case TOK_LPAREN: strcat(exmpl, tokens[tok_index].value); break;   // (
            case TOK_RPAREN: strcat(exmpl, tokens[tok_index].value); break;   // )
            case TOK_NUMBER: strcat(exmpl, tokens[tok_index].value); break;   // 1, 2, ...
        }
        ++tok_index;
    }

    return exmpl;
}