#ifndef STRINGS_H
#define STRINGS_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long symbol_n, length_n, strsize_t;
typedef long line_n, strfpos_t;

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
Read_line_before_symbol_from_file(FILE* stream, char symbol);

/**
 * the same as the Read_line_before_symbol_from_file function, but return a list of readed words from this line
 * 
 * @param stream        the file stream
 * @param symbol        the symbol up to which need to read
 * 
 * @return              the list of readed words
 */
char**
Read_line_fron_file_before_symbol_and_return_words(FILE* stream, char* symbol);

/**
 * calculate length of line from file stream
 * 
 * @param stream        the file stream
 * @param symbol        the symbol up to which need to read
 * 
 * @return              length of readed line
 */
length_n
Get_length_of_line(FILE* stream, char symbol);

/**
 * calculate length of word from file stream
 * 
 * @param stream        the file stream
 * @param offset        offset on which place the needed word
 * @param separator     the separators between words
 * 
 * @return              length of readed word
 */
strsize_t
Get_length_of_word(FILE* stream, strfpos_t offset, char separator);

/**
 * calculate words count
 * 
 * @param stream        the file stream
 * @param separator     the separators between words
 * 
 * @return              words count
 */
length_n
Count_of_words_from_stream(FILE* stream, char separator);

/**
 * calculate words count and its length
 * 
 * @param stream
 * @param separator
 * 
 * @return              array with length of every words in stream
 */
length_n*
Get_lengths_of_words(FILE* stream, char separator);

#endif