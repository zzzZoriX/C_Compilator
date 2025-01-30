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
Read_file(const char* input_file_name);

#endif