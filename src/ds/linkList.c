#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"


// init a head of a list
LinkList* link_list_init()
{
    LinkList* head = malloc(sizeof(LinkList));
    head->next = NULL;
    return head;
}

// append an element at the end
void link_list_append(LinkList* list, Token tok)
{
    // element to happend
    LinkList* to_insert = malloc(sizeof(LinkList));
    to_insert->value = tok;
    to_insert->next = NULL;

    // work loop
    LinkList* cur = list;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = to_insert;
}

// pop the last element
Token link_list_pop(LinkList* list)
{
    // Enpty list
    if(list->next == NULL)
    {
        return (Token){TOKEN_INVALID, 0, {0, 0}};
    }

    // work loop
    LinkList* cur = list;
    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }


    Token to_return = cur->value;
    free(cur->next);
    cur->next = NULL;

    return to_return;
}

// get the element at the index ind
Token link_list_get(LinkList *list, int ind)
{
    // Empty list
    if(list->next == NULL || ind < 0)
    {
        return (Token){TOKEN_INVALID, 0.0, {0, 0}};
    }

    //Work loop
    LinkList* cur = list->next;
    while (ind > 0 && cur->next != NULL)
    {
        cur = cur->next;
        ind--;
    }

    // each case ind >len(list)
    if(ind > 0)
    {
        return (Token){TOKEN_INVALID, 0.0, {0, 0}};    
    }

    return cur->value ;
    
}

//get the first element
Token peek(LinkList *list)
{
    //pass the heap and get the first element
    return list->next->value;
}

//pop the first element
Token next(LinkList *list)
{
    //If list is empty
    if(list->next == NULL)
    {
        return (Token){TOKEN_INVALID, 0, {0,0}};
    }

    Token to_return = list->next->value;

    // errase the first element
    LinkList* next_value = list->next->next;
    free(list->next);
    list->next = next_value;

    return to_return;
}