#include "Parse.h"

void
Read_file(const char* input_file_name){
    FILE* input_file_stream = fopen(input_file_name, 'r');

    char* lines;
    line_n current_parse_line = 0;
    while((lines = Read_line_before_symbol_from_file(input_file_stream, '\n')) != NULL){
        ++current_parse_line;
    }
}

int
Parse(const char* line){
    
}