#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ErrorHandler.h"

ErrorStruct*
CreateError(const char* error_text, err_line error_line){
    ErrorStruct* error = (ErrorStruct*)malloc(sizeof(ErrorStruct));

    error->error_line = error_line;
    error->error_message = strdup(error_text);

    if(!error){
        fprintf(stdout, "Memory allocation failed for error\n");
        return NULL;
    }
    return error;
}

void
PrintError(ErrorStruct* error){
    fprintf(stderr, "%lld: %s\nToken - %d\n", error->error_line, error->error_message);
}

void
RealeaseError(ErrorStruct* error){
    free(error->error_message);
    free(error);
}