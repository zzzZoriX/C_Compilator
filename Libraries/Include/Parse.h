#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <pthread.h>

#include "./Include/Tokens.h"
#include "./Include/Types.h"
#include "./Include/Strings.h"
#include "./Include/ErrorHandler.h"

#define SEPARATOR ' '

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
 * @param tokens_p                  line translated to tokens
 * @param words                     words from parsing line
 * @param count_of_words            count of words in line
 * 
 * @return                          error object. if error was happened - return object, else - return null
 */
ErrorStruct*
Parse(Token** tokens_p, const char** words, length_n count_of_words);


#endif