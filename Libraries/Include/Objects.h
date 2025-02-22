#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Types.h"

/**
 * type of object
 */
typedef struct Object {
    /**
     * object name
     * if object is cell in array - name equal NULL
     */
    char* object_name;

    /**
     * object type
     */
    Type object_type;

    /**
     * object value
     * selected by type
     */
    Value object_value;

    /**
     * pointer to next object
     */
    struct Object* next_object;
} Object;

/**
 * struct for better work with objects
 */
typedef struct HeadOfObject {
    /**
     * pointer to first object
     */
    Object* first_object;

    /**
     * pointer to last object
     */
    Object* last_object;

    /**
     * count of objects
     */
    unsigned long count_of_objects;
} HeadObject;


/**
 * release object
 * 
 * @param obj                   object which need to release
 */
static inline void
Release_obj(Object* obj){
    if(!obj) return;
    if(obj->object_name) free(obj->object_name);
    free(obj);
}

/**
 * release head of objects
 * 
 * @param head                  head of objects which need to release
 */
static inline void
Release_head_obj(HeadObject* head){
    if(!head) return;
    if(head->count_of_objects == 1){
        Release_obj(head->first_object);
        free(head);
        return;
    }

    Object* current_obj = head->first_object;
    Object* next_obj = NULL;
    
    while(current_obj != NULL){
        next_obj = current_obj->next_object;
        Release_obj(current_obj);
        current_obj = next_obj;
    }
    free(head);
}

/**
 * checks for the presence of an object
 * 
 * @param name                  name by which will be search an object
 * @param head                  head of objects
 */
bool
isThere(const char* name, HeadObject* head);

/**
 * searching the object by name
 * 
 * @param name                  name by which will be search object
 * @param head                  head of objects
 * 
 * @return                      found object
 */
Object*
Find_obj(const char* name, HeadObject* head);


/**
 * initialize head of objects
 * 
 * @return                      initialized head of objects
 */
HeadObject*
Init_head_obj();

/**
 * initialize object
 * 
 * @param obj_name              name of creating object
 * @param obj_type              type of creating object
 * @param obj_value             value of the creating object
 * 
 * @return                      initialized object
 */
Object*
Init_obj(const char* obj_name, Type obj_type, Value obj_value);


/**
 * add object to linked list
 * 
 * @param obj                   object which need to add
 * @param head_obj              header of objects
 */
void
Add_obj(Object* obj, HeadObject* head_obj);

/**
 * delete object from linked list
 * 
 * @param obj                   object which need to delete
 * @param head                  head of objects
 */
void
Delete_obj(Object* obj, HeadObject* head);

#endif