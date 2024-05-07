#include "apc.h"
#include <stdlib.h>

int mul(List **tail1, List **tail2, List **head3, List **tail3)
{
   List *t1 = *tail1;
   List *t2 = *tail2;
   List *res1_head = NULL,*res1_tail = NULL;
   List *res3_head = NULL,*res3_tail = NULL;
   int res,carry = 0,count = 0;

   while(t2 != NULL)
   {
       res1_head = NULL,res1_tail = NULL;
       res3_head = NULL,res3_tail = NULL;
       t1 = *tail1;
       for(int i=0; i < count; i++)
	   insert_last(&res1_head,&res1_tail, 0);
       while(t1 != NULL)
       {
	   res = t1->data * t2->data;
	   if(carry > 0)
	   {
	       res = res+carry;
	       carry = 0;
	   }
	   if(res > 9)
	   {
	       carry = res/10;
	       res = res%10;
	   }
	   insert_first(&res1_head,&res1_tail,res);
	   t1 = t1->prev;
       }
       if(carry > 0)
       {
	   insert_first(&res1_head,&res1_tail,carry);
	   carry = 0;
       }
       adding(&res1_tail,tail3,&res3_head,&res3_tail,"1","0");
       *head3 = res3_head;
       *tail3 = res3_tail;
       count++;
       t2 = t2->prev;
   }
   return S_USS;
}
