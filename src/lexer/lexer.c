#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lexer.h"
#include "../ds/linkList.h"

// Lexer go to the next char
void lexer_next(Lexer* lexer)
{
    lexer->pos++;
    lexer->current_char = lexer->input[lexer->pos];
}

// Skip whitespaces of the lexer input 
void lexer_skip_whitespace(Lexer* lexer)
{
    while(lexer->current_char == ' ')
    {
        lexer_next(lexer);
    }
}

// Parse all numbers
double lexer_parse_number(Lexer* lexer)
{
    char buffer[50];
    int start_pos = lexer->pos;
    while((lexer->current_char >= '0' && lexer->current_char <= '9') || lexer->current_char == '.')
    {
        lexer_next(lexer);
    }

    size_t lenght = lexer->pos - start_pos;
    strncpy(buffer, lexer->input + start_pos, lenght);
    buffer[lenght] = '\0';
    return atof(buffer);
}

// Get the next Token
Token lexer_get_token(Lexer* lexer)
{
    lexer_skip_whitespace(lexer);

    if(lexer->current_char == '\0')
    {
        return (Token){TOKEN_EOF, 0, {0, 0}};
    }

    if(lexer->current_char >= '0' && lexer->current_char <= '9')
    {
        return (Token){TOKEN_NUMBER, lexer_parse_number(lexer), {0,0}};
    }

    char c = lexer->current_char;
    lexer_next(lexer);
    switch (c)
    {
    case '+': return (Token){TOKEN_PLUS, 0, {1, 1.1}};
    case '-': return (Token){TOKEN_MINUS, 0, {1, 1.1}};
    case '*': return (Token){TOKEN_MULTIPLY, 0, {2, 2.1}};
    case '/': return (Token){TOKEN_DIVIDE, 0, {2, 2.1}};
    case '(': return (Token){TOKEN_LPAREN, 0, {0, 0}};
    case ')': return (Token){TOKEN_RPAREN, 0, {0, 0}};
    default: return (Token){TOKEN_INVALID, 0, {0, 0}};
    }
}

// Tokenising the expression
LinkList* lex_expression(const char* input)
{
    Lexer lexer = {input, 0, input[0]};
    LinkList* head = link_list_init();

    Token tok;
    do
    {
        tok = lexer_get_token(&lexer);
        link_list_append(head, tok);
    } while (tok.tokenType != TOKEN_EOF && tok.tokenType != TOKEN_INVALID);

    return head;
    
}

