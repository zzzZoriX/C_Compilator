#include "./Include/Strings.h"

extern line_n current_parse_line;

ErrorStruct*
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

    *buffer_p = str_wo_space;

    return NULL;
}

ErrorStruct* 
Delete_extra_spaces(char** buffer_p, char* str) {
    if (str == NULL) 
        return NULL;

    char* str_wo_extra_spaces = (char*)malloc((strlen(str) + 1) * sizeof(char));
    if (str_wo_extra_spaces == NULL) return NULL;

    strsize_t i = 0, j = 0;
    bool prev_is_space = 0; 

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

    *buffer_p = str_wo_extra_spaces;

    return NULL;
}

ErrorStruct*
Read_line_before_symbol_from_file(char** line_p, FILE* stream, char symbol){
    length_n length_of_cur_line;
    Get_length_of_line(&length_of_cur_line, stream, symbol);
    
    char* line_buffer = (char*)malloc((length_of_cur_line + 1) * sizeof(char));
    if(!line_buffer){
        ErrorStruct* error = CreateError("Memory allocating failed for read line\n", current_parse_line, -1);
        return error;
    }

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

    fseek(stream, 1, SEEK_CUR);

    *line_p = line_buffer;

    return NULL;
}

ErrorStruct*
Divide_line_into_words(char*** words_buffer_p, char* line, char separator){
    char* save_pointer_position = line;

    /* initialize words array */
    length_n* lengths_of_words;
    length_n count_of_words;
    Count_of_words_in_line(&count_of_words, line, separator);
    Get_lengths_of_words(&lengths_of_words, line, separator);
    char** words = (char**)malloc(count_of_words * sizeof(char*));
    if(!words){
        ErrorStruct* error = CreateError("Memory allocating failed for words\n", current_parse_line, -1);
        return error;
    } 

    strsize_t index = 0;
    for(length_n i = 0; i < count_of_words; ++i){
        words[i] = (char*)malloc((lengths_of_words[index++] + 1) * sizeof(char));
        if(!words[i]){
            ErrorStruct* error = CreateError("Memory allocating failed for word in line\n", current_parse_line, -1);
            free(words[i]);
            free(words);
            return error;
        }
    }

    /* divide */
    length_n i = 0, k = 0;
    length_n length_of_line = strlen(line);
    while(*line != '\0'){
        if(*line != separator && *line != '\n')
            words[i][k++] = *line;
        else{
            words[i][k] = '\0';
            ++i;
            k = 0;
        }
        ++line;
    }

    if(k > 0)
        words[i][k] = '\0';

    free(lengths_of_words);

    *words_buffer_p = words;

    return NULL;
}

ErrorStruct*
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

ErrorStruct*
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

ErrorStruct*
Count_of_words_in_line(length_n* count_p, char* line, char separator){
    char* save_pointer_position = line;
    length_n count_of_words = 1;

    while(*line != '\0'){
        if(*line == separator || *line == '\n')
            ++count_of_words;

        ++line;
    }
    line = save_pointer_position;

    *count_p = count_of_words;

    return NULL;
}

ErrorStruct*
Get_lengths_of_words(strsize_t** lengths_p, char* line, char separator){
    length_n count_of_words;
    Count_of_words_in_line(&count_of_words, line, separator);
    char* save_pointer_position = line;
    strsize_t* lengths_of_words = (strsize_t*)calloc(count_of_words, sizeof(strsize_t));
    if(!lengths_of_words){
        ErrorStruct* error = CreateError("Memory allocating failed for lengths of words", current_parse_line, -1);
        return error;
    }

    strsize_t length_of_word = 0, index = 0;
    while(*line != '\0'){
        if(*line != separator && *line != '\n')
            ++length_of_word;
        else{
            lengths_of_words[index++] = length_of_word;
            length_of_word = 0;
        }
        ++line;
    }
    line = save_pointer_position;
    lengths_of_words[index] = length_of_word;

    *lengths_p = lengths_of_words;

    return NULL;
}