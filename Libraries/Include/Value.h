#ifndef VALUE_H
#define VALUE_H

#include "Types.h"
#include "Objects.h"
#include "Tokens.h"
#include "Calculator.h"

/**
 * assign function
 * 
 * @param var_head          head of variables
 * @param tokens            all tokens
 * @param token_index       token index in tokens list from which need to start read a value
 * 
 * @param cur_obj_name      current object name
 * @param cur_obj_type      current object type
 */
void
Assign(
        HeadObject* var_head, 
        Token* tokens, 
        size_t token_index, 
        char* cur_obj_name,
        Type cur_obj_type
    );

/**
 * create correct value
 * 
 * @param tokens            all tokens
 * @param token_index       token index in tokens list from which need to start read a value
 * @param var_head          header of variables
 */
Value
Get_value(Token* tokens, size_t token_index, HeadObject* var_head);

/**
 * function which define and change a token-type by token value 
 * 
 * @param token                     token by which value type will be define and change
 */
void
Define_and_change_tok_type(Token* token);

/**
 * the function which transform a object name to it value
 * 
 * @param tokens                    tokens list
 * @param token_index               current token index 
 * @param var_head                  variables header
 */
void
Transform_obj_name_to_it_value(Token* tokens, size_t token_index, HeadObject* var_head);

#endif