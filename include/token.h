#ifndef TOKEN_H
#define TOKEN_H

// Librairy of Token types
typedef enum
{
    TOKEN_EOF,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_INVALID
} TokenType;

// Token Structur
typedef struct 
{
    TokenType tokenType;
    double value;
    double bindingPower[2];
} Token;

#endif