#include "./Include/Calculator.h"

bool_t
isValidExmplSymbol(LexerTokenType tok_type){
    if(
        tok_type == TOK_NUMBER ||
        tok_type == TOK_DIVIDE ||
        tok_type == TOK_MINUS  || 
        tok_type == TOK_PLUS   ||
        tok_type == TOK_MULTI  ||
        tok_type == TOK_LPAREN ||
        tok_type == TOK_RPAREN
    ) return true;
    return false;
}

float
DoOperation(float a, float b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:
            fprintf(stderr, "Invalid operation\n");
            exit(1);
    }
}

int
OpPriority(char op){
    switch(op){
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 2;

        default: return 0;
    }
}

float
Calculate(Token* tokens, length_n tok_index){
    float result;
    long ops_count = 0, nums_count = 0;

    length_n token_index = tok_index;
    while(isValidExmplSymbol(tokens[token_index].type)){
        if(tokens[token_index].type != TOK_NUMBER) ++ops_count;
        else ++nums_count;

        ++token_index;
    }

    Stack* value_stack,* operation_stack;
    value_stack = Init_stack(nums_count);
    operation_stack = Init_stack(ops_count);

    while(isValidExmplSymbol(tokens[tok_index].type)){

        if(tokens[tok_index].type == TOK_NUMBER){
            float value = atof(tokens[tok_index].value);
            Push(value_stack, value);
        }
        
        else if(tokens[tok_index].type == TOK_LPAREN)
            Push(operation_stack, '(');

        else if(tokens[tok_index].type == TOK_RPAREN){
            while(!isStackEmpty(operation_stack) && Peek(operation_stack) != '('){
                float a = Pop(value_stack);
                float b = Pop(value_stack);
                char op = (char)Pop(operation_stack);
                
                float value = DoOperation(a, b, op);
                Push(value_stack, value);
            }
            Pop(operation_stack);
        }

        else if(
            tokens[tok_index].type == TOK_PLUS || 
            tokens[tok_index].type == TOK_MINUS ||
            tokens[tok_index].type == TOK_MULTI ||
            tokens[tok_index].type == TOK_DIVIDE
        ) {
            char op = *(tokens[tok_index].value);
            while(!isStackEmpty(operation_stack) && OpPriority(Peek(operation_stack)) >= OpPriority(*(tokens[tok_index].value))){
                float a = Pop(value_stack);
                float b = Pop(value_stack);
                char stack_op = (char)Pop(operation_stack);
                
                float value = DoOperation(a, b, stack_op);
                Push(value_stack, value);
            }
            Push(operation_stack, op);
        }

        ++tok_index;
    }

    while(!isStackEmpty(operation_stack)){
        float a = Pop(value_stack);
        float b = Pop(value_stack);
        char op = (char)Pop(operation_stack);
        
        float value = DoOperation(a, b, op);
        Push(value_stack, value);
    }

    result = Pop(value_stack);

    Release_stack(value_stack);
    Release_stack(operation_stack);

    return result;
}