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
Read_line_before_symbol_from_file(FILE* stream, char symbol, line_n line){
    line_n read_line = 0;
    fpos_t position = 0;
    char c;
    while(read_line != line && (c = getc(stream)) != EOF){
        if(c == '\n')
            ++read_line;

        ++position;
    }

    if(read_line != line){
        ErrorStruct* error = CreateError("Readed lines not equal point lines", -1);
        PrintError(error);
        exit(1);
    }

    fseek(stream, position, SEEK_SET);

    length_n length_of_cur_line = Get_length_of_line(stream, position);
    char* buffer = (char*)malloc((length_of_cur_line + 1) * sizeof(char));
    length_n index = 0;

    while((c = getc(stream)) != EOF && (c != getc(stream)) != '\n')
        buffer[index++] = c;

    return buffer;
}

length_n
Get_length_of_line(FILE* stream, fpos_t offset){
    fseek(stream, offset, SEEK_SET);
    length_n length_of_line = 0;
    char c;

    while((c = getc(stream)) != EOF && (c != getc(stream)) != '\n')
        ++length_of_line;
    
    return length_of_line;
}