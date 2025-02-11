#include <stdio.h>
#include "c:/c_compilator/libraries/include/Interpritator.h"

#define TEST_PATH "c:/c_compilator/tests/test1.txt"

int
main(int argc, char** argv){

    HeadObject* head_of_objects = Init_head_obj();

    /* test something */
    //FILE* fpt = fopen(TEST_PATH, "r");

    Token* t;
    t->type = TOK_FLOAT;
    t->name = "bb";
    t->value = (Value){0};
    Type type = Define_type(t->type);
    printf("%d\n", type);
    /* ... */

    Release_head_obj(head_of_objects);

    return 0;
}