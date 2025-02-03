#include <stdio.h>
#include "C:/C_Compilator/Libraries/ErrorHandler.h"
#include "C:/C_Compilator/Libraries/Strings.h"

int
main(int argc, char** argv){

    /* test something */
    FILE* fpt = fopen("c:/c_compilator/tests/test1.txt", "r");
    
    char* line = Read_line_before_symbol_from_file(fpt, EOF);
    line = Delete_extra_spaces(line);
    length_n c = Count_of_words_in_line(line, ' ');
    length_n* l = Get_lengths_of_words(line, ' ');

    char** words = Divide_line_into_words(line, ' ');

    for(length_n i = 0; i < c; ++i)
        printf("%s\n", words[i]);

    for(length_n i = 0; i < c; ++i)
        free(words[i]);

    free(words);

    fclose(fpt);
    /* ... */

    return 0;
}