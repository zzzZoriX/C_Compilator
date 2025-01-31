#include <stdio.h>
#include "C:/C_Compilator/Libraries/ErrorHandler.h"
#include "C:/C_Compilator/Libraries/Strings.h"

int
main(int argc, char** argv){

    FILE* in = stdin;
    
    length_n l = Get_length_of_word(in, -1, ' ');

    printf("%zu", l);

    return 0;
}