#include <stdio.h>
#include <stdlib.h>
#include "../ds/tree.h"
#include "../ds/linkList.h"

char ope_conv(Token tok)
{
    if(tok.tokenType == TOKEN_PLUS)
    {
        return '+';
    }
    else if(tok.tokenType == TOKEN_MINUS)
    {
        return '-';
    }
    else if(tok.tokenType == TOKEN_MULTIPLY)
    {
        return '*';
    }
    else
    {
        return '/';
    }
}

Tree* parse_expression(LinkList* list, double min_bp)
{
    Token lhs_tok = next(list);
    Tree* lhs = malloc(sizeof(Tree));
    if(lhs_tok.tokenType == TOKEN_NUMBER)
    {
        lhs->ope = 'N';
        lhs->ln =  lhs_tok.value;
    }
    else if(lhs_tok.tokenType == TOKEN_LPAREN)
    {
        lhs->ope = 'L';
        lhs->lop = parse_expression(list, 0.0);
    }

    Token op_tok = peek(list);
    while (op_tok.tokenType != TOKEN_EOF || op_tok.tokenType != TOKEN_RPAREN)
    {
        op_tok = peek(list);
        if(op_tok.tokenType == TOKEN_EOF)
        {
            break;
        }
        next(list);
        double l_bp = op_tok.bindingPower[0];
        double r_bp = op_tok.bindingPower[1];
        if(l_bp < min_bp)
        {
            break;
        }
        Tree* rhs = parse_expression(list, r_bp);
        Tree* lhs_temp = lhs;
        lhs = malloc(sizeof(Tree));
        lhs->ope = ope_conv(op_tok);
        lhs->lop = lhs_temp;
        lhs->rop = rhs;
        op_tok = peek(list);
    }
    return lhs;
    

}