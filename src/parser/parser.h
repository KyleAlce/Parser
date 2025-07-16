#ifndef PARSER_H
#define PARSER_H
#include "../ds/tree.h"
#include "../ds/linkList.h"

char ope_conv(Token tok);
Tree* parse_expression(LinkList* list, double min_bp);

#endif 