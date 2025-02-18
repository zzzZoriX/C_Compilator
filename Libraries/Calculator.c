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

float
Calculate(Token* tokens, length_n tok_index){
    float result = atof(tokens[tok_index++].value);

    while(isValidExmplSymbol(tokens[tok_index].type)){
        switch(tokens[tok_index].type){
            case TOK_PLUS:
                ++tok_index;
                result += atof(tokens[tok_index].value);
                break;
            case TOK_MINUS:
                ++tok_index;
                result -= atof(tokens[tok_index].value);
                break;
            case TOK_MULTI:
                ++tok_index;
                result *= atof(tokens[tok_index].value);
                break;
            case TOK_DIVIDE:
                ++tok_index;
                result /= atof(tokens[tok_index].value);
                break;
        }
        ++tok_index;
    }

    return result;
}