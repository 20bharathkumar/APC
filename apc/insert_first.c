#include "apc.h"
#include <stdlib.h>
int insert_first(List **head, List **tail, int data)
{
    //creating node
    List *neww = malloc(sizeof(List));

    if(neww == NULL)
        return F_AIL;

    //if list is empty
    if(*head == NULL)
    {
        neww->data = data;
        neww->prev = NULL;
        neww->next = NULL;
        *head = neww;
        *tail = neww;
        return S_USS;
    }
    //adding data and link
    neww->data = data;
    neww->next = *head;
    neww->prev = NULL;
    (*head)->prev = neww;
    *head = neww;

    return S_USS;
}
