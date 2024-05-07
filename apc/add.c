#include "apc.h"
#include <stdlib.h>

int adding(List **tail1, List **tail2, List **head3, List **tail3, char *op1, char *op2)
{
    int carry=0,res;
    List *t1 = *tail1;
    List *t2 = *tail2;
    if(t1 == NULL)
    {
	while(t2 != NULL)
	{
	    insert_first(head3,tail3,t2->data);
	    t2 = t2->prev;
	}

    }
    else if(t2 == NULL)
    {
	while(t1 != NULL)
	{
	    insert_first(head3,tail3,t1->data);
	    t1 = t1->prev;
	}
    }
    else
    {
	if(atoi(op1) >= atoi(op2))
	{
	    while(t1 != NULL)
	    {
		if(t2 != NULL)
		{
		    if(carry > 0)
		    {
			carry--;
			res = ((t1->data)+1) + t2->data;
		    }
		    else
		    {   
			res = t1->data + t2->data;
		    }
		    if(res >= 10)
		    {
			res = res%10;
			carry++;
		    }
		    t2 = t2->prev;
		}
		else
		{
		    res = t1->data;
		    if(carry == 1)
		    {
			res = (t1->data) + 1;
			carry--;
		    }
		    if(res > 9)
		    {
			carry++;
			res = res%10;
		    }
		}
		insert_first(head3,tail3,res);
		t1 = t1->prev;

	    }
	    if(carry == 1)
		insert_first(head3,tail3,carry);
	}
	else
	{
	    while(t2 != NULL)
	    {
		if(t1 != NULL)
		{
		    if(carry > 0)
		    {
			carry--;
			res = ((t1->data)+1) + t2->data;
		    }
		    else
		    {
			res = t1->data + t2->data;
		    }
		    if(res >= 10)
		    {
			res = res%10;
			carry++;
		    }
		    t1 = t1->prev;
		}
		else
		{
		    res = t2->data;
		    if(carry == 1)
		    {
			res = (t2->data) + 1;
			carry--;
		    }
		    if(res > 9)
		    {
			carry++;
			res = res%10;
		    }
		}
		insert_first(head3,tail3,res);
		t2 = t2->prev;

	    }
	    if(carry == 1)
		insert_first(head3,tail3,carry);
	}
    }
    return S_USS;
}
