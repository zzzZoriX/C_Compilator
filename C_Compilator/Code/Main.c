#include <stdio.h>
#include "C:/C_Compilator/Libraries/ErrorHandler.h"
#include "C:/C_Compilator/Libraries/Strings.h"

int
main(int argc, char** argv){
    
    /* here i test some function */
    char* str = "H e l l o , w    o r l d !";
    char* new_str = Delete_spaces(str);

    fprintf(stdout, "%s\n%s\n", str, new_str);

    free(new_str);
    /* dont care */

    return 0;
}