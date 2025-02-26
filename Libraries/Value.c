#include "./Include/Value.h"

void
Assign(HeadObject* var_head, Token* tokens, size_t token_index, char* cur_obj_name, Type cur_obj_type){
    Value new_value = Get_value(tokens, token_index, var_head);

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
Get_value(Token* tokens, size_t token_index, HeadObject* var_head){
    Value new_value = (Value){0};

    switch(Define_type_of_value(&tokens[token_index])){

        case TYPE_DIGIT:
            Transform_obj_name_to_it_value(tokens, token_index, var_head);

            float result = Calculate(tokens, token_index);
            
            new_value.float_value = result;
            new_value.double_value = (double)result;
            new_value.int_value = (int)result;
            break;

        case TYPE_STRING:
            char* str_copy = strdup(tokens[token_index].value);
            if(!str_copy){
                fprintf(stderr, "Memory allocating failed for line\n");
                exit(1);
            }

            new_value.string_value = str_copy;
            break;

        case TYPE_BOOL:
            if(strcmp(tokens[token_index].value, "true") == 0) new_value.bool_value = true;
            else if(strcmp(tokens[token_index].value, "false") == 0) new_value.bool_value = false;
            else new_value.bool_value = false;
            break;

        case TYPE_UNDEF:
            fprintf(stderr, "Unknown data type");
            exit(1);
        
        default:
            fprintf(stderr, "Unknown data type");
            exit(1);
    }

    return new_value;
}

void
Define_and_change_tok_type(Token* token){
    switch(Define_type_of_value(token)){
        case TYPE_DIGIT:
            token->type = TOK_NUMBER;
    }
}

void
Transform_obj_name_to_it_value(Token* tokens, size_t token_index, HeadObject* var_head){
    size_t index = token_index;
    do{
        if(isObjVarName(tokens[index].value)){
            Object* obj = Find_obj(tokens[index].value, var_head);
            if(!obj){
                fprintf(stderr, "Undefined object\n");
                exit(1);
            }
            float obj_value = Get_value_obj(obj);
        
            length_n length_of_num = Get_length_of_num((int)obj_value) + 1;
            char buffer[length_of_num];
            snprintf(buffer, length_of_num, "%d", (int)obj_value);
        
            if(tokens[index].value) free(tokens[index].value);
        
            tokens[index].value = strdup(buffer);
            Define_and_change_tok_type(&tokens[index]);
            
            ++index;
            continue;
        }
        else if(!isValidExmplSymbol(tokens[index].type)) break;
        
        ++index;
    }
    while(isValidExmplSymbol(tokens[index].type));
}