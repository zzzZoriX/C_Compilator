#include <stdio.h>
#include "c:/c_compilator/libraries/include/Compilator.h"

int
main(void){
    char* a = "hello ",* b = "world!";

    char* c = concat(a, b);
    printf("%s\n", c);
}