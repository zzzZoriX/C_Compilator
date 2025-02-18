#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Tokens.h"
#include "Strings.h"
#include "Types.h"

#include <ctype.h>

/**
 * checks symbol validity for examples
 * 
 * @param tok_type          a symbol token-type by which will be checkedsymbol validity
 * 
 * @return                  true or false 
 */
bool
isValidExmplSymbol(TokenType tok_type);

/**
 * calculate example
 * 
 * @param tokens            tokens
 * @param tok_index         token from which function will start
 * 
 * @return                  an answer of example
 */
float
Calculate(Token* tokens, length_n tok_index);

#endif