#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>

#include "Tokens.h"
#include "Types.h"
#include "Strings.h"

typedef unsigned long long line_n;

/**
 * function which read code of input file
 * 
 * @param input_file_name           input file name
 */
void
Read_file(const char* input_file_name);

/**
 * the parse function
 * 
 * @param line                      line which need to read
 * 
 * @return                          1 or 0 (true or false). this is result of work
 */
int
Parse(const char* line);

#endif