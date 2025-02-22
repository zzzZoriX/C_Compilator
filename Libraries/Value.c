#include "./Include/Value.h"

void
Assign(HeadObject* var_head, Token* tokens, size_t token_index, char* cur_obj_name, Type cur_obj_type){
    Value new_value = Get_value(tokens, token_index);

    if(isThere(cur_obj_name, var_head)){
        Object* cur_obj = Find_obj(cur_obj_name, var_head);

        if(Validate_value(cur_obj->object_type, new_value))
            cur_obj->object_value = new_value;
    }
    else{
        if(Validate_value(cur_obj_type, new_value)){
            Object* new_obj = Init_obj(cur_obj_name, cur_obj_type, new_value);
            Add_obj(new_obj, var_head);
        }
    }
}

Value
Get_value(Token* tokens, size_t token_index){
    Value new_value = (Value){0};
    new_value.string_value = NULL;
    new_value.bool_value = 2;

    switch(Define_type_of_value(&tokens[token_index])){

        case TYPE_DIGIT:
            new_value.float_value = Calculate(tokens, token_index);
            break;

        case TYPE_STRING:
            new_value.string_value = strdup(tokens[token_index].value);
            break;

        case TYPE_BOOL:
            if(strcmp(tokens[token_index].value, "true") == 0) new_value.bool_value = true;
            else if(strcmp(tokens[token_index].value, "false") == 0) new_value.bool_value = false;
            break;
    }

    return new_value;
}