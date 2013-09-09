#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct add
{
	unsigned a;
	unsigned b;
	char sign;
	unsigned int c;
	int no;
};
struct add stu[10005];  
int cmp( const void *a , const void *b )
{
	struct add *x = (struct add *)a;
	struct add *y = (struct add *)b;
    
	if(x->c == y->c  && y->sign == x->sign) 
		return  ((x->no)-(y->no));
    
	else if(x->c > y->c) return -1;
	else if(x->c < y->c) return 1;
    
	else return y->sign - x->sign;
}    
int main()
{
	int n,t,i;
	scanf("%d",&t);
	while(t--) 
	{
		scanf("%d",&n);
		if(n == 0) continue;
		for(i = 0;i < n;i ++)
		{
			scanf("%u %u",&stu[i].a,&stu[i].b);
			stu[i].no = i +1;
			stu[i].c = stu[i].a + stu[i].b;
            
			if(stu[i].a > stu[i].b)
                stu[i].sign = '>';
			else if(stu[i].a == stu[i].b)
                stu[i].sign = '=';
			else
                stu[i].sign = '<';
		} 
		qsort(stu,n,sizeof(stu[0]),cmp);
		for(i = 0;i < n;i ++)
			printf("%u+%u=[%c%u]\n",stu[i].a,stu[i].b,stu[i].sign,stu[i].c);
		printf("\n");
	}
	return 0;
}
/*
 Problem Description
 We all know a+b=c,but now there is a new rule in equations: 
 if a>b,then it's equal to [>c];
 if a=b,then it's equal to [=c];
 if a<b,then it's equal to [<c];
 a sample: 
 
 1+1=[=2] 
 2+0=[>2]
 0+2=[<2]
 1+2=[<3]
 
 and [>c] > [=c] > [<c].
 For every [n],
 [n+1] > [n] >[n-1].
 Input
 The input consists of T cases.The first line of the input contains only positive integer T (0<T<=100).Then follows the cases.Each case begins with a line containing exactly one integer N (0<N<=10000).Then there are N lines, each with two integers a and b (0<a,b<2^31-1).
 Output
 For each case, calculate each value of a+b(as a+b=[?]) and output a+b=[?] in descending order sorted by [?]. If there exists some pair of a,b whose order can not be determined by the rules above, output them with the order of the input. A blank line should be printed after each case. 
 Sample Input
 2
 5
 1 5
 5 1
 3 3
 4 5
 5 6
 5
 1 6
 6 1
 2 4
 4 2
 3 3
 Sample Output
 5+6=[&lt;11]
 4+5=[&lt;9]
 5+1=[>6]
 3+3=[=6]
 1+5=[&lt;6]
 
 6+1=[>7]
 1+6=[&lt;7]
 4+2=[>6]
 3+3=[=6]
 2+4=[&lt;6]
*/