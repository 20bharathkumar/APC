#include "apc.h"
#include <stdlib.h>
int sub(List **tail1, List **tail2, List **head3, List **tail3, int *sign,char *op1, char *op2)
{
    int barrow = 0,res;

    List *t1 = *tail1;
    List *t2 = *tail2;
    if(atoi(op1) == atoi(op2))
    {
	insert_first(head3,tail3,0);
	*sign = 0;
	return S_USS;
    }
    else if(t1 == NULL)
    {
	*sign = 1;
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
	if(atoi(op1) > atoi(op2))
	{
	    while(t1 != NULL)
	    {
		if(t2 != NULL)
		{
		    if(t1->data < t2->data)
		    {
			if(barrow > 0)
			{
			    t1->data = t1->data-1;
			    barrow--;
			}
			if(t1->data < t2->data)
			{
			    t1->data = t1->data + 10;
			    barrow++;
			}
			res = t1->data - t2->data;
		    }
		    else
		    {
			if(barrow > 0)
			{
			    t1->data = t1->data - 1;
			    barrow--;
			}
			
			if(t1->data < t2->data)
			{
			    t1->data = t1->data + 10;
			    barrow++;
			}
			
			res = t1->data - t2->data;
			
		    }
		    t2 = t2->prev;
		}
		else
		{
		    res = t1->data;
		    if(barrow > 0)
		    {
			if(res == 0)
			{
			    res = res+10;
			    barrow++;
			}
			res = res - 1;
			barrow--;
		    }
		}
		insert_first(head3,tail3,res);
		t1 = t1->prev;
	    }
	}
	else
	{
	    //*sign = 1;
	    while(t2 != NULL)
	    {
		if(t1 != NULL)
		{
		    if(t2->data < t1->data)
		    {
			if(barrow > 0)
			{
			    t2->data = t2->data-1;
			    barrow--;
			}
			if(t2->data < t1->data)
			{
			    t2->data = t2->data + 10;
			    barrow++;
			}
			res = t2->data - t1->data;
		    }
		    else
		    {
			if(barrow > 0)
			{
			    res = ((t2->data)-1) - t1->data;
			    barrow--;
			}
			if(t2->data < t1->data)
			{
			    t2->data = t2->data + 10;
			    barrow++;
			}
			
			res = t2->data - t1->data;
			
		    }
		    t1 = t1->prev;
		}
		else
		{
		    res = t2->data;
		    if(barrow > 0)
		    {
			if(res == 0)
			{
			    res = res+10;
			    barrow++;
			}
			res = res - 1;
			barrow--;
		    }
		}
		insert_first(head3,tail3,res);
		t2 = t2->prev;
	    }
	}
    }
    return S_USS;
}
