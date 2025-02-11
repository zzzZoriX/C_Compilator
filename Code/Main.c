#include <stdio.h>
#include "c:/c_compilator/libraries/include/Interpritator.h"

#define DEBUG 1

/*
    compile command
    gcc ./code/main.c ./libraries/interpritator.c ./libraries/tokens.c ./libraries/strings.c ./libraries/objects.c ./libraries/errorhandler.c -o output_file
*/

int
main(int argc, char** argv){

    if(argc < 2){
        fprintf(stderr, "Don't point input file. correct use: %s <input_file_name>", argv[0]);
        exit(1);
    }

    #ifdef DEBUG
    fprintf(stdout, "Program start\n");
    #endif

    HeadObject* head_of_objects = Init_head_obj();

    FILE* input_file_stream = fopen(argv[1], "r");
    if(!input_file_stream){
        fprintf(stderr, "Error occured while opening input file");
        exit(1);
    }

    Interpritator(input_file_stream, head_of_objects);

    Release_head_obj(head_of_objects);

    #ifdef DEBUG
    fprintf(stdout, "Program end\n");
    #endif

    return 0;
}