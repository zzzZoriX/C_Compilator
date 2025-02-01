#include "Strings.h"
#include "ErrorHandler.h"

char*
Delete_spaces(const char* str){
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

    return str_wo_space;
}

char*
Read_line_before_symbol_from_file(FILE* stream, char symbol){
    strfpos_t save_position = ftell(stream);
    length_n length_of_cur_line = Get_length_of_line(stream, symbol);
    fseek(stream, save_position, SEEK_SET);
    
    char* line_buffer = (char*)malloc((length_of_cur_line + 1) * sizeof(char));
    if(!line_buffer){
        fprintf(stderr, "Memory allocating failed for read line\n");
        exit(1);
    }

    char c;
    strsize_t index = 0;

    while((c = getc(stream)) != EOF && c != symbol)
        line_buffer[index++] = c;

    line_buffer[index] = '\0';

    fseek(stream, length_of_cur_line + 1, SEEK_CUR);

    return line_buffer;
}

char**
Read_line_fron_file_before_symbol_and_return_words(FILE* stream, char* symbol);

length_n
Get_length_of_line(FILE* stream, char symbol){
    char c;
    length_n length = 0;
    while((c = getc(stream)) != EOF && c != symbol)
        ++length;

    return length;
}

strsize_t
Get_length_of_word(FILE* stream, strfpos_t offset, char separator){
    if(offset == -1)
        fseek(stream, 0, SEEK_SET);
    else if(offset == -2)
        fseek(stream, 0, SEEK_END);
    else
        fseek(stream, offset, SEEK_CUR);

    char c;
    strsize_t length = 0;

    while((c = getc(stream)) != EOF && c != separator)
        ++length;

    fseek(stream, -offset, SEEK_CUR);

    return length;
}

length_n
Count_of_words_from_stream(FILE* stream, char separator){
    length_n count_of_words = 0;
    char c;

    while((c = getc(stream))){
        if(c == separator || c == '\n')
            ++count_of_words;
        else if(c == EOF){
            ++count_of_words;
            break;
        }
    }

    return count_of_words;
}

length_n*
Get_lengths_of_words(FILE* stream, char separator){
    length_n count_of_words = Count_of_words_from_stream(stream, separator), index = 0;
    length_n* lengths_of_words = (length_n*)calloc(count_of_words, sizeof(strsize_t));
    strsize_t cur_word_length;
    printf("%zu\n", count_of_words);

    while(index != count_of_words){
        cur_word_length = Get_length_of_word(stream, 1, separator);
        lengths_of_words[index++];
        printf("%zu, %zu\n", index, cur_word_length);
    }

    return lengths_of_words;
}