#include "./Include/Interpritator.h"

line_n current_parse_line = 0;
Token empty_token = NULL_TOKEN;
extern ErrorStruct* result;

void
Read_file(const char* input_file_name){
    FILE* input_file_stream = fopen(input_file_name, "r");
    char * line, ** words;
    pthread_t error_check_thread;
    Token* tokens;
    length_n count_of_words;

    pthread_create(
        &error_check_thread,
        NULL,
        CheckToError,
        NULL
    );

    result = Read_line_before_symbol_from_file(&line, input_file_stream, SEPARATOR);
    while(line != NULL){
        result = Delete_extra_spaces(&line, line);
        result = Divide_line_into_words(&words, line, SEPARATOR);
        result = Count_of_words_in_line(&count_of_words, line, SEPARATOR);

        result = Lexer(&tokens, words, count_of_words);

        result = Read_line_before_symbol_from_file(&line, input_file_stream, SEPARATOR);
        ++current_parse_line;
    }
}

ErrorStruct*
Lexer(Token** tokens_p, const char** words, length_n count_of_words){
    Token* tokens = (Token*)calloc(count_of_words, sizeof(Token));
    size_t token_index = 0, words_index = 0;
    if(!tokens)
        return CreateError("Memory allocating failed for tokens\n", current_parse_line, -1);

    Token* current_token;
    current_token = Define_token(&empty_token, words[words_index++]), ++token_index;
    while(words_index != count_of_words){
        tokens[token_index] = *current_token;
        current_token = Define_token(&(tokens[token_index++]), words[words_index++]);
    }

    *tokens_p = tokens;

    return NULL;
}

ErrorStruct*
Parser(Token* tokens){
    

    return NULL;
}