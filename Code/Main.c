#include <stdio.h>
#include "C:/C_Compilator/Libraries/ErrorHandler.h"
#include "C:/C_Compilator/Libraries/Strings.h"

int
main(int argc, char** argv){

    /* test something */
    FILE* fpt = fopen("c:/c_compilator/tests/test1.txt", "r");

    length_n s = ftell(fpt);
    length_n ll = Get_length_of_word(fpt, 0, ' ');
    fseek(fpt, s, SEEK_SET);
    printf("%zu\n", ll);

    length_n* l = Get_lengths_of_words(fpt, ' ');
    fseek(fpt, s, SEEK_SET);
    length_n lll = Count_of_words_in_stream(fpt, ' ');
    printf("%zu\n", lll);
    for(length_n i = 0; i < lll; ++i)
        printf("%zu ", l[i]);

    free(l);
    fclose(fpt);
    /* ... */

    return 0;
}