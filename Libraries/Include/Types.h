#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

#define true 1
#define false 0

typedef uint8_t bool;

typedef enum {
    TYPE_INT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_BOOL
} Type;

/**
 * the union of value which can be store the value of every type 
 */
typedef union Value {
    int32_t int_value;
    bool bool_value;
    char char_value;
    float float_value;
    double double_value;
} Value;

#endif