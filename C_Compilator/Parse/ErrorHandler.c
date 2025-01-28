#include <stdio.h>
#include <stdlib.h>
#include "ErrorHandler.h"

ErrorStruct*
CreateError(const char* error_text, error_line error_line, error_token error_token){
    ErrorStruct* error = (ErrorStruct*)malloc(sizeof(ErrorStruct));
    if(!error){
        fprintf(stdout, "Memory allocate failed for error\n");
        return NULL;
    }
    return error;
}