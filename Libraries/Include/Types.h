#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef uint8_t bool_t;

typedef enum {
    TYPE_DIGIT,
    TYPE_INT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_BOOL,
    TYPE_UNDEF
} Type;

/**
 * the union of value which can be store the value of every type 
 */
typedef union Value {
    int32_t int_value;
    bool_t bool_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
} Value;

/**
 * write new value to suitable digit type variable
 * 
 * @param type                  type of new value
 * @param value                 value variable where need to write new value
 * @param new_value             new value for "value"
 */
void
Select_correct_digit_value(Type type, Value* value, float new_value);

/**
 * validate a value by type
 * 
 * @param type                  a type by which value will be validate
 * @param value                 a value which need to validate
 * 
 * @return                      true or false
 */
bool_t
Validate_value(Type type, Value value);

#endif