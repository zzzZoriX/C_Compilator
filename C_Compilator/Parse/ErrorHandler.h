#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "C:\\C_Compilator\\Libraries\\Tokens.h"


typedef unsigned long long error_line;
typedef Token error_token;


/**
 * the struct of error which will be print when the error occured 
 */
typedef struct ErrorStruct {
    /**
     * store error message
     */
    char* error_message;

    /**
     * store line on which error has been occured
     */
    error_line error_line;

    /**
     * store token on which error has been occured
     */
    error_token error_token;
} ErrorStruct;


/**
 * create error (ErrorStruct object)
 * 
 * @param
 * @return ErrorStruct object 
 */
ErrorStruct*
CreateError(const char* error_text, error_line error_line, error_token error_token);

#endif