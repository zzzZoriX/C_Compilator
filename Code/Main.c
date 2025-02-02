#include <stdio.h>
#include "C:/C_Compilator/Libraries/ErrorHandler.h"
#include "C:/C_Compilator/Libraries/Strings.h"

int
main(int argc, char** argv){

    /* test something */
    char* str = "Hello  w orl\n\nd!";
    char* s = Delete_extra_space(str);
    printf("%s", s);
    free(s);
    /* ... */

    return 0;
}