#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Tokens.h"
#include "Strings.h"
#include "Types.h"
#include "Stack.h"

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
 * do simple math operation
 * 
 * @param a                 first number
 * @param b                 second number
 * @param op                operation
 * 
 * @return                  an answer
 */
float
DoOperation(float a, float b, char op);

/**
 * return priority of operation
 * 
 * @param op                operation which priority need to return
 * 
 * @return                  operation priority
 */
int
OpPriority(char op);

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