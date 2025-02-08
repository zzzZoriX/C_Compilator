#include <stdio.h>
#include "c:/c_compilator/libraries/include/parse.h"

#define TEST_PATH "c:/c_compilator/tests/test1.txt"

int
main(int argc, char** argv){

    /* test something */
    FILE* fpt = fopen(TEST_PATH, "r");
    
    char* words[] = {"int", "a", ";", "char", "float", "="};
    Token* tokens;
    Lexer(&tokens, (const char**)words, 6);

    free(tokens[1].name);
    free(tokens);

    fclose(fpt);
    /* ... */

    return 0;
}