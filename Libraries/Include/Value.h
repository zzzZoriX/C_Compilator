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
 */
Value
Get_value(Token* tokens, size_t token_index);

#endif