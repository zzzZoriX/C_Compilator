#include <stdio.h>
#include "c:/c_compilator/libraries/include/Interpritator.h"
#include "c:/c_compilator/libraries/include/Objects.h"

#define TEST_PATH "c:/c_compilator/tests/test1.txt"

int
main(int argc, char** argv){

    /* test something */
    //FILE* fpt = fopen(TEST_PATH, "r");

    Token* t;
    t->type = TOK_FLOAT;
    t->name = "bb";
    t->value = (Value){0};
    Type type = Define_type(t->type);
    printf("%d\n", type);
    /* ... */

    return 0;
}