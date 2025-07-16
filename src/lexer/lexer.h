#ifndef LEXER_H
#define LEXER_H

#include "../../include/token.h"
#include "../ds/linkList.h"

typedef struct 
{
    const char* input;
    int pos;
    char current_char;
}Lexer;

// go to the next char
void lexer_next(Lexer* lexer);
// forward to the next non-whitespace char
void lexer_skip_whitespace(Lexer* lexer);
// Return the current number 
double lexer_parse_number(Lexer* lexer);
// return the Token for the current char
Token lexer_get_token(Lexer* lexer);
// Tokenising the expression
LinkList* lex_expression(const char* input);

#endif