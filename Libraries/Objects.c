#include "./Include/Objects.h"

bool_t
isThere(const char* name, HeadObject* head){
    Object* current_obj = head->first_object;
    
    if(head->count_of_objects == 1)
        return strcmp(current_obj->object_name, name) == 0;

    while(current_obj != NULL){
        if(strcmp(current_obj->object_name, name) == 0) return true;

        current_obj = current_obj->next_object;
    }
    return false;
}

Object*
Find_obj(const char* name, HeadObject* head){
    Object* current_obj = head->first_object;

    if(head->count_of_objects == 1 && strcmp(current_obj->object_name, name) == 0)
        return current_obj;

    while(current_obj != NULL){
        if(strcmp(current_obj->object_name, name) == 0) return current_obj;

        current_obj = current_obj->next_object;
    }

    return NULL;
}

HeadObject*
Init_head_obj(){
    HeadObject* head = (HeadObject*)malloc(sizeof(HeadObject));
    if(!head) return NULL;

    head->count_of_objects = 0;
    head->first_object = NULL;
    head->last_object = NULL;

    return head;
}

Object*
Init_obj(const char* obj_name, Type obj_type, Value obj_value){
    Object* obj = (Object*)malloc(sizeof(Object));
    if(!obj) return NULL;

    obj->object_name = strdup(obj_name);
    if(!obj->object_name){
        free(obj);
        fprintf(stderr, "Invalid object name\n");
        return NULL;
    }
    obj->object_type = obj_type;
    obj->object_value = obj_value;
    obj->next_object = NULL;

    return obj;
}


void
Add_obj(Object* obj, HeadObject* head_obj){
    if(head_obj->count_of_objects == 0){
        head_obj->first_object = obj;
        head_obj->last_object = obj;
        head_obj->first_object->next_object = obj;
    }
    else{
        head_obj->last_object->next_object = obj;
        head_obj->last_object = obj;
    }
    ++head_obj->count_of_objects;
}

void
Delete_obj(Object* obj, HeadObject* head){
    Object* current_obj = head->first_object;
    while(current_obj != NULL && strcmp(current_obj->next_object->object_name, obj->object_name) != 0)
        current_obj = current_obj->next_object;
    
    Object* delete_obj = current_obj->next_object;
    current_obj->next_object = current_obj->next_object->next_object;

    Release_obj(delete_obj);
    //--head->count_of_objects;
}

float
Get_value_obj(Object* obj){
    switch(obj->object_type){
        case TYPE_INT:    return (float)obj->object_value.int_value;
        case TYPE_FLOAT:  return obj->object_value.float_value;
        case TYPE_DOUBLE: return (float)obj->object_value.double_value;

        case TYPE_STRING:
            int* ascii_for_word = Word_to_ascii(obj->object_value.string_value);
            int result = ascii_for_word[0];
            
            for(size_t i = 1; i < strlen(obj->object_value.string_value); ++i)
                result = result * 10 + ascii_for_word[i];

            free(ascii_for_word);
            return (float)result;

        case TYPE_CHAR: return (float)(int)obj->object_value.char_value;
        case TYPE_BOOL: return obj->object_value.bool_value;
    }
}