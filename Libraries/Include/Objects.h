#ifndef OBJECTS_H
#define OBJECTS_H

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
    Object* next_object;
} Object;

/**
 * struct for better work with objects
 */
typedef struct HeadObject {
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
 * add object to linked list
 * 
 * @param obj                   object which need to add
 * @param head_obj              header of objects
 */
void
Add_obj(Object* obj, HeadObject* head_obj);

#endif