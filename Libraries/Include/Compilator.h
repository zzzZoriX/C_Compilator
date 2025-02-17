#ifndef INTERPRITATOR_H
#define INTERPRITATOR_H

#include <stdio.h>
#include <pthread.h>

#include "Tokens.h"
#include "Types.h"
#include "Strings.h"
#include "ErrorHandler.h"
#include "Objects.h"

#define SEPARATOR ' '

/**
 * interpritator function
 * 
 * @param input_file_strem          a file stream
 * @param head                      a head of objects
 */
void
Compilator(FILE* input_file_stream, HeadObject* head);

/**
 * the lexer function
 * 
 * @param tokens_p                  line translated to tokens
 * @param input_file_stream         a file stream 
 * 
 * @return                          error object. if error was happened - return object, else - return null
 */
ErrorStruct*
Lexer(Token** tokens_p, FILE* input_file_stream);

/**
 * the parser function
 * 
 * @param tokens                    tokens by which parser will be does something
 * @param head                      a head of objects
 * @param count_of_tokens           you can pass the number of words as this argument
 * 
 * @return                          error object. if error was happened - return object, else - return null
 */
ErrorStruct*
Parser(Token* tokens, HeadObject* head, length_n count_of_tokens);

#endif