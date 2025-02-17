#include "./Include/Compilator.h"

line_n current_parse_line = 0;
Token empty_token = NULL_TOKEN;
extern ErrorStruct* result;

ErrorStruct*
Lexer(Token** tokens_p, FILE* input_file_stream){
    /* divide line into words */
    char** words,* line;
    length_n count_of_words = 0;

    result = Read_line_before_symbol_from_file(&line, input_file_stream, EOF);
    result = Delete_extra_spaces(&line, line);
    result = Divide_line_into_words(&words, line, SEPARATOR, true);

    Count_of_words_in_line(&count_of_words, line, SEPARATOR, true);

    free(line);

    /* lexical analysis */
    Token* tokens = (Token*)calloc(count_of_words, sizeof(Token));
    if(!tokens)
        return CreateError("Memory allocating failed for lexical analysis\n", current_parse_line, -1);

    Token* token;
    size_t word_i = 0, token_i = 0;;
    
    token = Define_token(&empty_token, words[word_i]);
    if(token == &(Token)NULL_TOKEN){
        char* error_text = "Unknown word: ";
        error_text = strcat(error_text, words[word_i]);
        
        return CreateError(error_text, current_parse_line, -1);
    }
    tokens[token_i] = *token;
    
    ++word_i;
    while(word_i < count_of_words){
        token = Define_token(&tokens[token_i], words[word_i]);
        if(token == &(Token)NULL_TOKEN){
            char* error_text = "Unknown word: ";
            error_text = strcat(error_text, words[word_i]);
            return CreateError(error_text, current_parse_line, -1);
        }

        tokens[++token_i] = *token;

        ++word_i;
    }

    
    /* delete all used variables and return data */
    for(length_n i = 0; i < count_of_words; ++i)
    free(words[i]);
    free(words);
    
    *tokens_p = tokens;

    for(length_n i = 0; i < count_of_words; ++i)
        printf("%s\n", tokens[i].value);

    return NULL;
}