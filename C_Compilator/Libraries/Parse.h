#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>

#include "C:\\C_Compilator\\Libraries\\Tokens.h"
#include "C:\\C_Compilator\\Libraries\\Types.h"

typedef unsigned long long line_n;

/**
 * function which read code of input file
 * 
 * @param input_file_name           input file name
 */
void
Read_file(const char* input_file_name){
    FILE* input_file_stream = fopen(input_file_name, "r");
    char* line;
    line_n line_number = 0;
    while(1){
        line = 
    }
}

#endif