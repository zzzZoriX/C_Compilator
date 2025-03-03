#include "./Include/Strings.h"
#include "Include/Types.h"

#define DEBUG 1


extern line_n current_parse_line;

struct ErrorStruct*
Delete_spaces(char** buffer_p, const char* str){
    strsize_t str_size = strlen(str);
    strsize_t str_size_wo_space = str_size + 1;

    for(strsize_t i = 0; i < str_size; ++i)
        if(isspace(str[i]))
            --str_size_wo_space;

    char* str_wo_space = (char*)malloc(str_size_wo_space * sizeof(char));
    strsize_t k = 0;
    if(!str_wo_space){
        fprintf(stdout, "Memocy allocation failed\n");
        exit(1);
    }

    for(strsize_t i = 0; i < str_size; ++i)
        if(!isspace(str[i]))    
            str_wo_space[k++] = str[i];

    str_wo_space[k] = '\0';

    free(*buffer_p);
    *buffer_p = str_wo_space;

    return NULL;
}

struct ErrorStruct* 
Delete_extra_spaces(char** buffer_p, char* str) {
    if (str == NULL) 
        return NULL;

    char* str_wo_extra_spaces = (char*)malloc((strlen(str) + 1) * sizeof(char));
    if (str_wo_extra_spaces == NULL) return NULL;

    strsize_t i = 0, j = 0;
    bool_t prev_is_space = 0; 

    while (str[i] != '\0'){
        if (str[i] != ' ' && str[i] != '\n'){
            str_wo_extra_spaces[j++] = str[i++];
            prev_is_space = 0;
        } 
        else if (str[i] == ' ' || str[i] == '\n'){
            if (!prev_is_space){
                str_wo_extra_spaces[j++] = str[i++];
                prev_is_space = 1;
            } 
            else 
                i++;
        }
    }

    str_wo_extra_spaces[j] = '\0';

    free(*buffer_p);
    *buffer_p = str_wo_extra_spaces;

    return NULL;
}

struct ErrorStruct*
Read_line_before_symbol_from_file(char** line_p, FILE* stream, char symbol){
    length_n length_of_cur_line;
    Get_length_of_line(&length_of_cur_line, stream, symbol);
    
    char* line_buffer = (char*)malloc((length_of_cur_line + 1) * sizeof(char));
    if(!line_buffer)
        return CreateError("Memory allocating failed for read line\n", current_parse_line, -1);

    char c;
    strsize_t index = 0;

    while((c = getc(stream)) != EOF && c != symbol){
        line_buffer[index++] = c;
    }

    line_buffer[index] = '\0';

    if(index == 0){
        free(line_buffer);
        *line_p = NULL;
        return NULL;
    }
    
    *line_p = line_buffer;

    return NULL;
}

struct ErrorStruct*
Divide_line_into_words(char*** words_buffer_p, char* line, char separator, bool_t semic){
    char* save_pointer_position = line, ** words;

    /* initialize words array */
    length_n* lengths_of_words, count_of_words;

    Count_of_words_in_line(&count_of_words, line, separator, semic);
    Get_lengths_of_words(&lengths_of_words, line, separator, semic);


    #ifdef DEBUG
    printf("count_of_words = %zu\nline = %s\n\nsizeof(char**) = %zu\nsizeof(char*) = %zu\nmemory for words array = %zu", count_of_words, line, sizeof(char**), sizeof(char*), sizeof(char*) * count_of_words);
    #endif

    words = (char**)calloc(count_of_words, sizeof(char*));
    if(!words)
        return CreateError("Memory allocating failed for words\n", current_parse_line, -1);

    printf("test\n");

    strsize_t index = 0;
    for(length_n i = 0; i < count_of_words; ++i){
        words[i] = (char*)malloc((lengths_of_words[index++] + 1) * sizeof(char));
        if(!words[i]){
            free(words[i]);
            free(words);
            return CreateError("Memory allocating failed for word in line\n", current_parse_line, -1);;
        }
    }

    /* divide */
    length_n i = 0, k = 0;
    while(*line != '\0' && i < count_of_words){
        if(*line != separator && *line != '\n' && (!semic || !isSpecSymbol(*line)))
            words[i][k++] = *line;
        else{
            if(k > 0){
                words[i++][k] = '\0';
                k = 0;
            }

            if (isSpecSymbol(*line) && semic){
                words[i][k++] = *line;
                words[i++][k] = '\0';
                k = 0;
            }
        }
        ++line;
    }
    printf("test\n");

    if(k > 0)
        words[i][k] = '\0';

    free(lengths_of_words);

    *words_buffer_p = words;

    return NULL;
}

struct ErrorStruct*
Get_length_of_line(length_n* length_p, FILE* stream, char symbol){
    strfpos_t save_position = ftell(stream);
    char c;
    length_n length = 0;
    while((c = getc(stream)) != EOF && c != symbol)
        ++length;

    fseek(stream, save_position, SEEK_SET);

    *length_p = length;

    return NULL;
}

struct ErrorStruct*
Get_length_of_word(strsize_t* length_p, char* line, char separator){
    char* save_pointer_position = line;
    strsize_t length_of_word = 0;
    while(*line != separator && *line != '\0' && *line != '\n'){
        ++length_of_word;
        ++line;
    }

    line = save_pointer_position;

    *length_p = length_of_word;

    return NULL;
}

struct ErrorStruct*
Count_of_words_in_line(length_n* count_p, char* line, char separator, bool_t semic){
    char* save_pointer_position = line;
    length_n count_of_words = 1;

    while(*line != '\0'){
        if(*line == separator || *line == '\n' || (semic && isSpecSymbol(*line)))
            ++count_of_words;

        ++line;
    }
    line = save_pointer_position;

    *count_p = count_of_words;

    return NULL;
}

struct ErrorStruct*
Get_lengths_of_words(strsize_t** lengths_p, char* line, char separator, bool_t semic){
    length_n count_of_words;
    Count_of_words_in_line(&count_of_words, line, separator, semic);
    char* save_pointer_position = line;
    strsize_t* lengths_of_words = (strsize_t*)calloc(count_of_words, sizeof(strsize_t));
    if(!lengths_of_words)
        return CreateError("Memory allocating failed for lengths of words", current_parse_line, -1);

    strsize_t length_of_word = 0, index = 0;
    while(*line != '\0'){
        if(*line != separator && *line != '\n' && isSpecSymbol(*line))
            ++length_of_word;
        else{
            lengths_of_words[index++] = length_of_word;
            length_of_word = 0;

            if(isSpecSymbol(*line))
                lengths_of_words[index++] = 1;
        }
        ++line;
    }
    line = save_pointer_position;
    lengths_of_words[index] = length_of_word;

    *lengths_p = lengths_of_words;

    return NULL;
}

int*
Word_to_ascii(const char* word){
    int* ascii_codes = (int*)calloc(strlen(word), sizeof(int));
    if(!ascii_codes){
        fprintf(stderr, "Memory allocating failed for ascii codes\n");
        exit(1);
    }

    for(strsize_t i = 0; i < strlen(word); ++i)
        ascii_codes[i] = (int)word[i];

    return ascii_codes;
}

length_n
Get_length_of_num(int n){
    if(n == 0) return 1;

    int n_copy = n;
    strsize_t length = 0;
    if(n_copy < 0){
        ++length;
        n_copy = -n_copy;
    }
    
    while(n_copy >= 1){
        n_copy /= 10;
        ++length;
    }

    return length;
}

char*
concat(const char* src, const char* str) {
    strsize_t new_string_length = strlen(src) + strlen(str);
    
    char* new_str = (char*)malloc(new_string_length * sizeof(char));
    if(!new_str) return NULL;

    strsize_t i = 0;
    for(; i < strlen(src); ++i)
        new_str[i] = src[i];

    for(strsize_t k = 0; k < strlen(str) && i < new_string_length; ++i, ++k)
        new_str[i] = str[k];

    return new_str;
}

bool_t
isSpecSymbol(char c) {
    return (c == ';' || c == '"' || c == '\'' || c == ')' || c == '(');
}