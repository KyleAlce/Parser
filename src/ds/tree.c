#include "tree.h"


double eval(Tree* tree)
{
    if(tree->ope == 'N')
    {
        return tree->ln;
    }
    else if(tree->ope == 'L')
    {
        return eval(tree->lop);
    }
    else if(tree->ope == '+')
    {
        return eval(tree->lop) + eval(tree->rop);
    }
    else if(tree->ope == '-')
    {
        return eval(tree->lop) - eval(tree->rop);
    }
    else if(tree->ope == '*')
    {
        return eval(tree->lop) * eval(tree->rop);
    }
    else 
    {
        return eval(tree->lop) / eval(tree->rop);
    }
}