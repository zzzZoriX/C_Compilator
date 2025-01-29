#include "./Libraries/Strings.h"

typedef long long strsize_t;
typedef long fpos_t;

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
Read_line_from_file(FILE* stream, char symbol, fpos_t position){
    fseek(stream, position, SEEK_SET);
    
}