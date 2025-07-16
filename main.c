#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "include/lexer.h"
#include "include/linkList.h"
#include "src/ds/tree.h"
#include "src/parser/parser.h"

int main()
{
    const char* input = "   (1*4) + (1+1) * (1+1*4)";
    LinkList* tok_tab = lex_expression(input);

    for(int i=0; i<10; i++)
    {
        Token tok = link_list_get(tok_tab, i);
        printf("Token type: %d", tok.tokenType);
        if(tok.tokenType == TOKEN_NUMBER)
        {
            printf(", value: %lf", tok.value);
        }
        printf("\n");
    }

    Tree* tr = parse_expression(tok_tab, 0.0);

    printf("--------------------------\n");
    printf("%f\n", eval(tr));


    

    return EXIT_SUCCESS;
}

