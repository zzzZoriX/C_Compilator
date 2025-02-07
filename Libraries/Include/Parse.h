#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <pthread.h>

#include "Tokens.h"
#include "Types.h"
#include "Strings.h"
#include "ErrorHandler.h"

#define SEPARATOR ' '

/**
 * function which read code of input file
 * 
 * @param input_file_name           input file name
 */
void
Read_file(const char* input_file_name);

/**
 * the lexer function
 * 
 * @param tokens_p                  line translated to tokens
 * @param words                     words from parsing line
 * @param count_of_words            count of words in line
 * 
 * @return                          error object. if error was happened - return object, else - return null
 */
ErrorStruct*
Lexer(Token** tokens_p, const char** words, length_n count_of_words);


#endif