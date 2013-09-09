#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
union type{
	char exp[12];
	int  value;
};
struct node{ 
	char isnb;
	union type op;
	struct node *next;
}stk[84];

int main()
{ 
	int i;
	struct node *ptop,*psave,*popr;
	char *p1,*p2,temp[100];
	while(gets(temp)!=NULL)
	{
		p1=temp;
		memset(stk,0,sizeof(struct node)*80);
		for(i=0;p1;p1=p2,i++)
		{
			p2=strchr(p1,' ');
			if(p2!=NULL)
			{
				*p2 ='\0';
				p2++;
			}
			stk[i].next=&stk[i+1];
			strcpy(stk[i].op.exp,p1);
			if(isdigit(stk[i].op.exp[0]))
			{
				stk[i].isnb=1;
				stk[i].op.value=atoi(stk[i].op.exp);
			}
		}
		stk[i-1].next=NULL;
		for(ptop=&stk[0];ptop->next;)
		{
			psave=ptop;
			while(1)
			{
				if(!ptop->next->next->isnb)
				{
					popr=ptop->next;
					if(popr->next->op.exp[0]=='+')
						ptop->op.value=ptop->op.value+popr->op.value;
					else if(popr->next->op.exp[0]=='-')
						ptop->op.value=ptop->op.value-popr->op.value;
					else
						ptop->op.value=ptop->op.value*popr->op.value;
					ptop->next=popr->next->next;
					break;
				}
				else
					ptop=ptop->next;
			}
			ptop = psave;
		}
		printf("%d\n",ptop->op.value);
	}                         
	return 0;
}
/*
 Problem description
 Postfix expressions are arithmetical expressions where the operators come after anything they operate on. Postfix is important because it maintains precedence without the use of (), and they're "easy" to evaluate. In this problem, you get to see how "easy" postfix expressions are to evaluate. 
 
 Input
 Each line of the input will be no more than 80 characters and will contain one expression to be evaluated. All expressions will be correct postfix expressions. There will be one space between each number/operator. The only operators we're interested in is + (addition), - (subtraction), and * (multiplication). There is no division. All numbers are non-negative integers. 
 
 Output
 Your program is to output the result of evaluting the epxression. Note that while the input numbers will not be negative, the answer may be negative. 
 
 Sample Input
 3 5 *
 6 4 * 2 +
 10 25 + 3 * 100 50 * - 85 + 10 13 - 4 * 36 * +
 Sample Output
 15
 26
 -5242
*/