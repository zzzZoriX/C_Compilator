#ifndef STRINGS_H
#define STRINGS_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef long long strsize_t;
typedef unsigned long long symbol_n, length_n;
typedef long line_n, fpos_t;

/**
 * delete all spaces in string
 * 
 * @param str           source string
 * 
 * @return              str without spaces
 */
char*
Delete_spaces(const char* str);

/**
 * read line from file stream until the point symbol is encountered
 * 
 * @param stream        the file stream
 * @param symbol        the symbol up to which need to read
 * 
 * @return              readed line
 */
char*
Read_line_before_symbol_from_file(FILE* stream, char symbol, line_n line);

/**
 * calculate length of line from file stream
 * 
 * @param stream        the file stream
 * @param offset        offset for fseek function
 * 
 * @return              length of readed line
 */
length_n
Get_length_of_line(FILE* stream, fpos_t offset);

#endif