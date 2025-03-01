#include "./Include/Types.h"
#include <stdio.h>

void
Select_correct_digit_value(Type type, Value* value, float new_value){
    if(!value) return;

    switch(type){
        case TYPE_INT:      value->int_value = (int)new_value; break;
        case TYPE_DOUBLE:   value->double_value = (double)new_value; break;
        case TYPE_FLOAT:    value->float_value = new_value; break;
    }
}

bool_t
Validate_value(Type type, Value value){
    if(type == TYPE_STRING && value.string_value) return true;
    if(type == TYPE_BOOL && value.bool_value != 2) return true;
    if(type == TYPE_INT || type == TYPE_DOUBLE || type == TYPE_FLOAT) return true;
    
    fprintf(stderr, "incompatible types");
    exit(1);
}