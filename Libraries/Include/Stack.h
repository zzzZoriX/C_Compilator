#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    /**
     * all FLOAT data in stack store here
     */
    float* data;

    /**
     * current capacity of stack
     */
    long top;
    
    /**
     * total stack size
     */
    long stack_size;
} Stack;

/**
 * initialize the stack object
 * 
 * @param size          size of the initialized stack
 * 
 * @return              initialized stack
 */
Stack*
Init_stack(long size);

/**
 * release stack data
 * 
 * @param s             stack which data need to release
 */
static inline void
Release_stack(Stack* s)
{ free(s->data); }

/**
 * checks current capacity is equal to total stack size 
 * 
 * @param s             stack which current capacity need to check
 * 
 * @return              1 or 0
 */
int
isStackFull(Stack* s);

/**
 * checks current capacity is less than 0
 * 
 * @param s             stack which current capacity need to check
 * 
 * @return              1 or 0
 */
int
isStackEmpty(Stack* s);

/**
 * push data to top on the stack
 * 
 * @param s             stack where need to push a data
 * @param data          data which need to push
 */
void
Push(Stack* s, float data);

/**
 * return a top data on the stack
 * 
 * @param s             stack from which top need to get a data
 * 
 * @return              data from top on the stack
 */
float
Pop(Stack* s);

#endif