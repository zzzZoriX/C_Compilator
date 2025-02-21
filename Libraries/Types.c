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