#include "./Include/Objects.h"

Object*
Find_obj(const char* name, HeadObject* head){
    Object* current_obj = head->first_object;
    while(current_obj != NULL && strcmp(current_obj->object_name, name) != 0)
        current_obj = current_obj->next_object;

    if(current_obj == NULL) return NULL;
    return current_obj;
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
    --head->count_of_objects;
}