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
 * delete extra space. it need for accurate count of words
 * 
 * @param str           the string where need to delete extra spaces
 * 
 * @return              string without extra spaces 
 */
char*
Delete_extra_spaces(char* str);

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
 * @param line          line which need to divide
 * @param separator     the separators between words
 * 
 * @return              the list of readed words
 */
char**
Divide_line_into_words(char* line, char separator);

/**
 * calculate length of line from file stream
 * 
 * @param stream        the file stream
 * @param symbol        the symbol up to which need to read
 * 
 * @return              length of readed line
 */
length_n
Get_length_of_line_from_stream(FILE* stream, char symbol);

/**
 * calculate length of line
 * 
 * @param line          line whose length need to calculate
 * 
 * @return              length of line
 */
length_n
Get_length_of_line(char* line);

/**
 * calculate length of word from file stream
 * 
 * @param line          line where need to read a word
 * @param separator     separators between words
 * 
 * @return              length of readed word
 */
strsize_t
Get_length_of_word(char* line, char separator);

/**
 * calculate words count
 * 
 * @param line          line where need to count a words
 * @param separator     separators between words
 * 
 * @return              words count
 */
length_n
Count_of_words_in_line(char* line, char separator);

/**
 * calculate words count and its length
 * 
 * @param line          line where need read words and count its lengths
 * @param separator     separators between words
 * 
 * @return              array with length of every words in stream
 */
strsize_t*
Get_lengths_of_words(char* line, char separator);

#endif