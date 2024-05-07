#include "apc.h"
#include <stdlib.h>

int validate_data(List **head1, List **tail1, List **head2, List **tail2,int *sign,char *opr,char *op1,char *op2,char *argv)
{
    int i=0,j=0,k=0,m=0,n=0,f=0,count=0;
    char opr1,opr3;
    while(argv[i] != '\0')
    {
	count++;
	if(argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
	{
	    if(count == 1)
	    {
		opr1 = argv[i];
		f=0;
	    }
	    else
	    {
		*opr = argv[i];
		if(argv[i+1] == '+' || argv[i+1] == '-')
		{
		    opr3 = argv[i+1];
		    i++;
		}
		f=1;
	    }


	}
	if(argv[i] >= 48 && argv[i] <= 57)
	{
	    if(f == 1)
	    {
		op2[k++] = argv[i];
		insert_last(head2,tail2,op2[m++]-48);
	    }
	    else
	    {
		op1[j++] = argv[i];
		insert_last(head1,tail1,op1[n++]-48);
	    }
	}
	i++;

    }
    op1[i] = '\0';
    op2[i] = '\0';
    opr_priority(opr1,opr3,opr,op1,op2,sign);
    return S_USS;
}

void opr_priority(char opr1, char opr3, char *opr2, char *op1, char *op2, int *sign)
{
    if(*opr2 == '+')
    {
	if(opr1 == '-' && opr3 == '-')
	{
	    *opr2 = '+';
	    *sign = 1;
	}
	else if(atoi(op1) > atoi(op2))
	{
	    if(opr1 == '-' && opr3 == '+' || opr1 == '-')
	    {
		*opr2 = '-';
		*sign = 1;
	    }
	    else if(opr1 == '+' && opr3 == '-' || opr3 == '-')
	    {
		*opr2 = '-';
		*sign = 0;
	    }
	}
	else
	{
	    if(opr1 == '-' && opr3 == '+' || opr1 == '-')
	    {
		*opr2 = '-';
		*sign = 0;
	    }
	    else if(opr1 == '+' && opr3 == '-' || opr3 == '-')
	    {
		*opr2 = '-';
		*sign = 1;
	    }

	}
    }
    else if(*opr2 == '-')
    {
	if(atoi(op1) >= atoi(op2))
	{
	    if(opr1 == '-' && opr3 == '-')
	    {
		*opr2 = '-';
		*sign = 1;
	    }
	    else if(opr1 == '-' && opr3 == '+' || opr1 == '-')
	    {
		*opr2 = '+';
		*sign = 1;
	    }
	    else if(opr1 == '+' && opr3 == '+' || opr1 == '+' || opr3 == '+')
	    {
		*opr2 = '-';
		*sign = 0;
	    }
	    else if(opr1 == '+' && opr3 == '-' || opr3 == '-')
	    {
		*opr2 = '+';
		*sign = 0;
	    }
	}
	else
	{
	    if(opr1 == '-' && opr3 == '+')
	    {
		*opr2 = '+';
		*sign = 1;
	    }
	    else if(opr1 == '-' && opr3 == '-')
	    {
		*opr2 = '-';
		*sign = 0;
	    }
	    else if(opr1 == '+' && opr3 == '+' || opr1 == '+' || opr3 == '+')
	    {
		*opr2 = '-';
		*sign = 1;
	    }
	    else if(opr1 == '+' && opr3 == '-' || opr3 == '-')
	    {
		*opr2 = '+';
		*sign = 0;
	    }
	}
    }
    else if(*opr2 == '*')
    {
	if(opr1 == '-' && opr3 == '-')
	{
	    *sign = 0;
	}
	else if(opr1 == '-' || opr3 == '-')
	{
	    *sign = 1;
	}
    }
    else if(*opr2 == '/')
    {
	if(opr1 == '-' && opr3 == '-')
	{
	    *sign = 0;
	}
	else if(opr1 == '-' || opr3 == '-')
	{
	    *sign = 1;
	}
    }
}
