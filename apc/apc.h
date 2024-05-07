#ifndef APC_H
#define APC_H

#define S_USS 0
#define F_AIL 1

#include <stdio.h>
//typedef long uint;

typedef struct node1
{
    int data;
    struct node1 *prev;
    struct node1 *next;
}List;

int validate_data(List **head1, List **tail1, List **head2, List **tail2,int *sign,char *opr,char *op1,char *op2,char *argv);

int adding(List **tail1, List **tail2, List **head3, List **tail3, char *op1, char *op2);

int mul(List **tail1, List **tail2, List **head3, List **tail3);

int sub(List **tail1, List **tail2, List **head3, List **tail3, int *sign,char *op1, char *op2);

int divi(List **head1,List **tail1, List **tail2, List **head3, List **tail3, int *d_res,char *op1, char *op2);

int insert_last(List **head, List **tail, int data);

int insert_first(List **head, List **tail, int data);

int print_res(List *head, int sign);

void opr_priority(char opr1, char opr3, char *opr2, char *op1, char *op2, int *sign);

#endif
