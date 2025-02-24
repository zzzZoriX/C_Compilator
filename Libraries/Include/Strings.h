#ifndef STRINGS_H
#define STRINGS_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ErrorHandler.h"

typedef unsigned long long symbol_n, length_n, strsize_t;
typedef long line_n, strfpos_t;

/**
 * release words
 * 
 * @param words         words which need to release
 * @param count_of_words    count of pointed words
 */
static inline void
Release_words(char** words, length_n count_of_words){
    for(size_t index = 0; index < count_of_words; ++index)
        free(words[index]);
}

/**
 * delete all spaces in string
 * 
 * @param buffer_p      buffer where will be writed line without spaces
 * @param str           source string
 * 
 * @return              error object. if error was happened - return object, else - return null
 */
struct ErrorStruct*
Delete_spaces(char** buffer_p, const char* str);

/**
 * delete extra space. it need for accurate count of words
 * 
 * @param buffer_p        buffer where will be writed line without extra spaces
 * @param str           the string where need to delete extra spaces
 * 
 * @return              error object. if error was happened - return object, else - return null 
 */
struct ErrorStruct*
Delete_extra_spaces(char** buffer_p, char* str);

/**
 * read line from file stream until the point symbol is encountered
 * 
 * @param line_p        buffer where will be writed readed line
 * @param stream        the file stream
 * @param symbol        the symbol up to which need to read
 * 
 * @return              error object. if error was happened - return object, else - return null
 */
struct ErrorStruct*
Read_line_before_symbol_from_file(char** line_p, FILE* stream, char symbol);

/**
 * the same as the Read_line_before_symbol_from_file function, but return a list of readed words from this line
 * 
 * @param words_buffer_p  buffer where need to write words
 * @param line          line which need to divide
 * @param separator     the separators between words
 * @param semic         specifies whether semic should be counted as a word
 * 
 * @return              error object. if error was happened - return object, else - return null
 */
struct ErrorStruct*
Divide_line_into_words(char*** words_buffer_p, char* line, char separator, bool semic);

/**
 * calculate length of line from file stream
 * 
 * @param length_p      variable where will be writed length of line
 * @param stream        the file stream
 * @param symbol        the symbol up to which need to read
 * 
 * @return              error object. if error was happened - return object, else - return null
 */
struct ErrorStruct*
Get_length_of_line(length_n* length_p, FILE* stream, char symbol);

/**
 * calculate length of word from file stream
 * 
 * @param length_p      variable where will be writed length of word
 * @param line          line where need to read a word
 * @param separator     separators between words
 * 
 * @return              error object. if error was happened - return object, else - return null
 */
struct ErrorStruct*
Get_length_of_word(strsize_t* length_p, char* line, char separator);

/**
 * calculate words count
 * 
 * @param count_p       variable where will be writed count of words
 * @param line          line where need to count a words
 * @param separator     separators between words
 * @param semic         specifies whether semic should be counted as a word
 * 
 * @return              error object. if error was happened - return object, else - return null
 */
struct ErrorStruct*
Count_of_words_in_line(length_n* count_p, char* line, char separator, bool semic);

/**
 * calculate words count and its length
 * 
 * @param lengths_p     array where need to write lengths
 * @param line          line where need read words and count its lengths
 * @param separator     separators between words
 * @param semic         specifies whether semic should be counted as a word
 * 
 * @return              error object. if error was happened - return object, else - return null
 */
struct ErrorStruct*
Get_lengths_of_words(strsize_t** lengths_p, char* line, char separator, bool semic);

/**
 * translate word to ascii code for each char
 * 
 * @param word          word which need to translate
 * 
 * @return              ascii code for each char
 */
int*
Word_to_ascii(const char* word);

#endif