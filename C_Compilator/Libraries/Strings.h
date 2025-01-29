#ifndef STRINGS_H
#define STRINGS_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
 * read file line until the point symbol is encountered
 * 
 * @param stream        the file stream
 * @param symbol        the symbol up to which need to read
 * 
 * @return              readed line
 */
char*
Read_line_from_file(FILE* stream, char symbol);

#endif