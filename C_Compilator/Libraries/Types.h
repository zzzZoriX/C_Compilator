#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef enum {
    TYPE_INT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_BOOL
} Type;

typedef union Value {
    int32_t int_value;
    uint8_t bool_value;
    char char_value;
    char* string_value;
    float float_value;
    double double_value;
} Value;


typedef struct Variable {
    char* variable_name;
    Type variable_type;
    Value variable_value;
} Variable;

#endif