#include "./Include/Compilator.h"

#define DEBUG 0

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
        error_text = concat(error_text, words[word_i]);
        
        return CreateError(error_text, current_parse_line, -1);
    }
    tokens[token_i] = *token;
    
    ++word_i;
    while(word_i < count_of_words){
        token = Define_token(&tokens[token_i], words[word_i]);
        if(token == &(Token)NULL_TOKEN){
            char* error_text = "Unknown word: ";
            error_text = concat(error_text, words[word_i]);
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

    return NULL;
}

ErrorStruct*
Parser(Token* tokens, length_n count_of_words){

    HeadObject* var_head = Init_head_obj(); // header of variables
    //HeadObject* cmd_head = Init_head_obj(); // header of commands(functions)

    Type current_data_type = TYPE_UNDEF;
    char* current_object_name = NULL;

    size_t token_index = 0;
    while(token_index < count_of_words){

        #if DEBUG == 1
        printf("%zu | %s | %s\n", token_index, tokens[token_index].value, current_object_name);
        #endif

        if(isDataType(tokens[token_index].type)){
            current_data_type = Define_type(tokens[token_index++].type);
            continue;
        }
        
        switch(tokens[token_index].type){
            
            case TOK_IDENT:
                current_object_name = _strdup(tokens[token_index].value);
                break;

            case TOK_ASSIGN:
                ++token_index;
                if(token_index >= count_of_words){
                    Release_head_obj(var_head);
                    return CreateError("Unexpected end of file after assigment\n", current_parse_line, -1);
                }

                Assign(var_head, tokens, token_index, current_object_name, current_data_type);
                break;

            case TOK_SEMIC:
                break;

            default:
                char* error_msg = "Undefined token: ";
                error_msg = concat(error_msg, tokens[token_index].value);
                return CreateError(error_msg, current_parse_line, -1);
        }

        ++token_index;
    }

    Release_head_obj(var_head);
    //Release_head_obj(cmd_head);

    return NULL;
}