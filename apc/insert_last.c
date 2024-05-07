#include "apc.h"
#include <stdlib.h>
int insert_last(List **head, List **tail, int data)
{
    //creating node
    List *neww = malloc(sizeof(List));
    //checking node is created
    if(neww == NULL)
        return F_AIL;

    //if list is empty
    if(*head == NULL)
    {
        neww->data = data;
        neww->next = NULL;
        neww->prev = NULL;
        *head = neww;
        *tail = neww;
        return S_USS;
    }

    //adding data
    neww->data = data;
    neww->next = NULL;
    neww->prev = *tail;
    (*tail)->next = neww;
    *tail = neww;
    return S_USS;
}
