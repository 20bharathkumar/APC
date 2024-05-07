#include "apc.h"

int print_res(List *head,int sign)
{
    /* Cheking the list is empty or not */
    int count = 0;
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	List *hd = head;
	if(sign == 1)
	{
	    printf("%c",'-');
	    sign = 0;
	}
	/*while(head->data == 0)
	{
	    head = head->next;
	    //count++;
	}*/
	while(head != NULL)
	{
	    /* Printing the list */
	    printf("%d", head -> data);

	    /* Travering in forward direction */
	    head = head -> next;
	    //if (head)
	    //  printf("> ");
	    //count++;
	}
	//printf(" Tail\n");
    }
}
