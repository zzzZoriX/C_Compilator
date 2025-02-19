#include <stdio.h>
#include "c:/c_compilator/libraries/include/Compilator.h"

extern ErrorStruct* result;

#define DEBUG 0

/*
    compile command
    gcc ./code/main.c ./libraries/types.c ./libraries/calculator.c ./libraries/stack.c ./libraries/compilator.c ./libraries/tokens.c ./libraries/strings.c ./libraries/objects.c ./libraries/errorhandler.c -o output_file
*/

int
main(int argc, char** argv){

    if(argc < 2){
        fprintf(stderr, "Don't point input file. correct use: %s <input_file_name>", argv[0]);
        exit(1);
    }

    #if DEBUG == 1
    fprintf(stdout, "Program start\n");
    #endif

    FILE* input_file_stream = fopen(argv[1], "r");
    if(!input_file_stream){
        fprintf(stderr, "Error occured while opening input file");
        exit(1);
    }

    result = CreateError("NullErr", -2, -9);

    #if DEBUG == 1
    fprintf(stdout, "Error tracker thread create...\n");
    #endif
    pthread_t error_thread;
    pthread_create(
        &error_thread,
        NULL,
        CheckToError,
        NULL
    );

    char* buffer;
    length_n count_of_words;

    #if DEBUG == 1
    fprintf(stdout, "Get count of words...\n");
    #endif

    result = Read_line_before_symbol_from_file(&buffer, input_file_stream, EOF);
    result = Count_of_words_in_line(&count_of_words, buffer, SEPARATOR, true);

    fseek(input_file_stream, 0, SEEK_SET);

    Token* tokens;

    #if DEBUG == 1
    fprintf(stdout, "Lexer...\n");
    #endif
    
    result = Lexer(&tokens, input_file_stream);

    #if DEBUG == 1
    fprintf(stdout, "Parser...\n");
    #endif
    
    result = Parser(tokens, count_of_words);

    free(tokens);

    #if DEBUG == 1
    fprintf(stdout, "Program end\n");
    #endif

    fclose(input_file_stream);

    return 0;
}