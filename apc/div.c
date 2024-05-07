#include "apc.h"
#include <stdlib.h>
int divi(List **head1, List **tail1, List **tail2, List **head3, List **tail3, int *d_res,char *op1, char *op2)
{
    List *t1 = *tail1;
    List *t2 = *tail2;
    int count = 0, res;
    if(atoi(op1) == 0)
    {
	*d_res = count;
	return S_USS;
    }
    else if(atoi(op2) == 0)
    {
	printf("Error: This operation is not possible\n");
	return F_AIL;
    }
    else if(atoi(op1) == atoi(op2))
    {
	*d_res = 1;
	return S_USS;
    }
    else
    {
	if(atoi(op1) > atoi(op2))
	{
	    while(res != 0)
	    {
		count++;
		sub(tail1,tail2,head3,tail3,0,"1","0");
		
		*head1 = *head3;
		*tail1 = *tail3;
		*head3 = NULL;
		*tail3 = NULL;
		
		List *t3 = *head1;
		res=0;
		while(t3 != NULL)
		{
		    res = (res * 10) + t3->data;
		    t3 = t3->next;
		}

		if(res < atoi(op2))
		{
		    break;
		}

	  }
	}
	*d_res = count;
	return S_USS;
    }
}
