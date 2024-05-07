/*
NAME: BHARATHKUMAR K
DATE: 19/12/2024
DESCRIPTION: ARBITRARY PRECISION CALCULATOR(APC)
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include <stdio.h>
#include <stdlib.h>
#include "apc.h"
int main(int argc,char *argv[])
{
    List *head1 = NULL;
    List *tail1 = NULL;
    List *head2 = NULL;
    List *tail2 = NULL;
    List *head3 = NULL;
    List *tail3 = NULL;

    int sign,res = 0,div_res = 0;
    char op1[100], op2[100], opr;
    if(argc == 2)
    {
	if(validate_data(&head1,&tail1,&head2,&tail2,&sign,&opr,op1,op2,argv[1]) == S_USS)
	{
	    if(opr == '+')
	    {
		if(adding(&tail1,&tail2,&head3,&tail3,op1,op2) == S_USS)
		{
		    printf("sign %d", sign);
		    printf("THE RESULT IS ");
		    print_res(head3,sign);
		    printf("\n");
		}
		else
		{
		    printf("Error: addition failed\n");
		}
	    }
	    else if(opr == '-')
	    {
		if(sub(&tail1,&tail2,&head3,&tail3,&sign,op1,op2) == S_USS)
		{
		    
		    printf("THE RESULT IS ");
		    print_res(head3,sign);
		    printf("\n");
		}
		else
		{
		    printf("Error: subtraction failed\n");
		}
	    }
	    else if(opr == '*')
	    {
		if(mul(&tail1,&tail2,&head3,&tail3) == S_USS)
		{
		    printf("THE RESULT IS ");
		    print_res(head3,sign);
		    printf("\n");
		}
		else
		{
		    printf("Error: multiplication failed\n");
		}
	    }
	    else if(opr == '/')
	    {
		if((divi(&head1,&tail1,&tail2,&head3,&tail3,&div_res,op1,op2)) == S_USS)
		{
		    printf("THE RESULT IS ");
		    if(sign == 1)
			printf("-");
		    printf("%d",div_res);
		    //print_res(head3,sign);
		    printf("\n");
		}
		else
		{
		    printf("Error: division failed\n");
		}
	    }
	}
	else
	{
	    printf("Error: validation failed\n");
	}

    }
    else
    {
	printf("Error: pass valid argument without space\n");
    }

    return 0;
}

