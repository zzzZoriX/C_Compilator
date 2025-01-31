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
    length_n length_of_cur_line = Get_length_of_line(stream, symbol);
    char* line_buffer = (char*)malloc((length_of_cur_line + 1) * sizeof(char));
    char c;
    strsize_t index = 0;

    while(c != EOF && c != symbol){
        c = getc(stream);
        line_buffer[index++] = c;
    }
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
    while(c != EOF && c != symbol){
        c = getc(stream);
        ++length;
    }

    return length;
}

length_n
Get_length_of_word(FILE* stream, strfpos_t offset, char separator){
    if(offset == -1)
        fseek(stream, 0, SEEK_SET);
    else if(offset == -2)
        fseek(stream, 0, SEEK_END);
    else
        fseek(stream, offset, SEEK_CUR);

    char c = getc(stream);;
    length_n length = 0;

    while(c != EOF && c != separator){
        ++length;
        c = getc(stream);
    }

    fseek(stream, -offset, SEEK_CUR);

    return length;
}