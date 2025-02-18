#include "./Include/Stack.h"

Stack*
Init_stack(long size){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (float*)calloc(size, sizeof(float));
    if(!s || !s->data){
        fprintf(stderr, "Memory allocating failed for stack\n");
        exit(1);
    }
    s->top = -1;
    return s;
}


int
isStackFull(Stack* s)
{ return s->top == s->stack_size - 1; }

int
isStackEmpty(Stack* s)
{ return s->top == -1; }

void
Push(Stack* s, float data){
    if(isStackFull(s)){
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = data;
}

float
Pop(Stack* s){
    if(isStackEmpty(s)){
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}