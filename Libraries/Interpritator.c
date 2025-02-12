#include "./Include/Interpritator.h"

line_n current_parse_line = 0;
Token empty_token = NULL_TOKEN;
extern ErrorStruct* result;

void
Interpritator(FILE* input_file_stream, HeadObject* head){
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

    result = Read_line_before_symbol_from_file(&line, input_file_stream, '\n');
    while(line != NULL){
        result = Delete_extra_spaces(&line, line);
        result = Divide_line_into_words(&words, line, SEPARATOR);
        result = Count_of_words_in_line(&count_of_words, line, SEPARATOR);

        result = Lexer(&tokens, (const char**)words, count_of_words);
        result = Parser(tokens, head, count_of_words);

        result = Read_line_before_symbol_from_file(&line, input_file_stream, '\n');
        ++current_parse_line;
    }
}

ErrorStruct*
Lexer(Token** tokens_p, const char** words, length_n count_of_words){
    if(!tokens_p || !words || count_of_words == 0) 
        return CreateError("Invalid lexer input parameters\n", current_parse_line, -1);

    Token* tokens = (Token*)calloc(count_of_words, sizeof(Token));
    size_t token_index = 0, words_index = 0;
    if(!tokens)
        return CreateError("Memory allocating failed for tokens\n", current_parse_line, -1);

    Token* current_token;
    current_token = Define_token(&empty_token, words[words_index++]), ++token_index;
    if(!current_token) return CreateError("Failed to define token\n", current_parse_line, -1);

    while(words_index < count_of_words){
        current_token = Define_token(&(tokens[token_index]), words[words_index]);
        if(!current_token){
            for (size_t i = 0; i < token_index; ++i)
                if(tokens[i].name) free(tokens[i].name);

            free(tokens);
            return CreateError("Failed to define token\n", current_parse_line, -1);
        }

        tokens[token_index] = *current_token;
        ++token_index, ++words_index;
    }

    *tokens_p = tokens;

    return NULL;
}

ErrorStruct*
Parser(Token* tokens, HeadObject* head, length_n count_of_tokens){
    if(!tokens || !head || count_of_tokens == 0) 
        return CreateError("Invalid parser input parameters\n", current_parse_line, -1);

        
    size_t index = 0;
    
    for(length_n index = 0; index < count_of_tokens; ++index){
        Type obj_t = TYPE_UNDEF;
        char* obj_n = NULL;
        Value obj_v = (Value){0};

        if( isDataType(tokens[index].type ))      obj_t = Define_type(tokens[index].type);
        if(isObjVarName(tokens[index].name))      obj_n = strdup(tokens[index].name);

        if(obj_n){
            Object* new_obj = Init_obj(obj_n, obj_t, obj_v);
            if(!new_obj){
                if(obj_n) free(obj_n);
                return CreateError("Failes to initialize object", current_parse_line, -1);
            }

            Add_obj(new_obj, head);

            if(obj_n) free(obj_n);
        }
    }

    return NULL;
}