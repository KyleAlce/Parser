#ifndef LINKLIST_H
#define LINKLIST_H

#include "../../include/token.h"

typedef struct LinkList LinkList;

struct LinkList {
    Token value;
    LinkList* next;        
};

// init a head of a list
LinkList* link_list_init();
// append an element at the end
void link_list_append(LinkList* list, Token tok);
// pop the last element
Token link_list_pop(LinkList* list);
// get the element at the index ind
Token link_list_get(LinkList *list, int ind);
//get the first element
Token peek(LinkList *list);
//pop the first element
Token next(LinkList *list);

#endif