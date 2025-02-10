#include <stdio.h>
#include "c:/c_compilator/libraries/include/Interpritator.h"
#include "c:/c_compilator/libraries/include/Objects.h"

#define TEST_PATH "c:/c_compilator/tests/test1.txt"

int
main(int argc, char** argv){

    /* test something */
    FILE* fpt = fopen(TEST_PATH, "r");

    fclose(fpt);

    HeadObject* h = Init_head_obj();
    Object * a = Init_obj("aa", TYPE_INT, (Value){1}), * b = Init_obj("bb", TYPE_INT, (Value){1});

    Add_obj(a, h);
    Add_obj(b, h);

    printf("%ld\n", h->count_of_objects);

    Delete_obj(b, h);

    printf("%ld\n", h->count_of_objects);
    /* ... */

    return 0;
}