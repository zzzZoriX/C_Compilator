#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "C:\\C_Compilator\\Libraries\\Tokens.h"


typedef unsigned long long err_line, err_symbol;


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
    err_line error_line;

    /**
     * store symbol on which error has been occured
     */
    err_symbol error_symbol;
} ErrorStruct;


/**
 * create error (ErrorStruct object)
 * 
 * @param error_text    error text
 * @param error_line    line on which error has been occured
 * @param error_symbol  symbol on which error has been occured
 * 
 * @return ErrorStruct object 
 */
ErrorStruct*
CreateError(const char* error_text, err_line error_line, err_symbol error_symbol);

/**
 * print the error
 * 
 * @param error         error which must be print
 */
void
PrintError(ErrorStruct* error);

/**
 * release error object
 * 
 * @param error         error object which must be released
 */
void
RealeaseError(ErrorStruct* error);


#endif