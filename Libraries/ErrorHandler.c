#include "./include/ErrorHandler.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif /* _WIN32 */

line_n lines = 0;

ErrorStruct*
CreateError(const char* error_text, err_line error_line, err_symbol error_symbol){
    ErrorStruct* error = (ErrorStruct*)malloc(sizeof(ErrorStruct));

    error->error_line = error_line;
    error->error_symbol = error_symbol;
    error->error_message = _strdup(error_text);

    if(!error){
        fprintf(stdout, "Memory allocation failed for error\n");
        return NULL;
    }
    return error;
}

void
CheckToError(ErrorStruct* err){
    if(err && err->error_symbol != -9){
        PrintError(err);
        exit(1);
    }
}

void
PrintError(ErrorStruct* error){
    fprintf(stderr, "%lld.%lld | %s\n", error->error_line, error->error_symbol, error->error_message);
    RealeaseError(error);
}

void
RealeaseError(ErrorStruct* error){
    free(error->error_message);
    free(error);
}