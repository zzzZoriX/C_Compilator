#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ErrorHandler.h"

ErrorStruct*
CreateError(const char* error_text, err_line error_line, err_symbol error_symbol){
    ErrorStruct* error = (ErrorStruct*)malloc(sizeof(ErrorStruct));

    error->error_line = error_line;
    error->error_symbol = error_symbol;
    error->error_message = strdup(error_text);

    if(!error){
        fprintf(stdout, "Memory allocation failed for error\n");
        return NULL;
    }
    return error;
}

void
PrintError(ErrorStruct* error){
    fprintf(stderr, "%lld.%lld: %s\nToken - %d\n", error->error_line, error->error_symbol ,error->error_message);
    RealeaseError(error);
}

void
RealeaseError(ErrorStruct* error){
    free(error->error_message);
    free(error);
}