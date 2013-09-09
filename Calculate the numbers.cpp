#include <iostream>
#include <memory.h>
using namespace::std;
const int Max=100005;
int tree[Max],n;

int lowbit(int t)
{
	return t&(t^(t-1));
}
void insert(int p,int k)
{
	while(p<=n)
	{
		tree[p]+=k;
		p+=lowbit(p);
	}
}

int sum(int end)
{
	int s=0;
	while(end>0)
	{
		s+=tree[end];
		end-=lowbit(end);
	}
	return s;
}

int main()
{
	int i,j;
	char c;
	scanf("%d",&n);
	memset(tree,0,Max*sizeof(int));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		insert(i,j);
	}
	getchar();
	while(scanf("%c",&c)&&c!='e')
	{
		scanf("%d%d",&i,&j);
		if(c=='a')
			insert(i,j);
		else
			printf("%d\n",sum(j)-sum(i-1));
		getchar();
	}
	return 0;
}
/*
 Problem description
 Xnby likes to play games with other children.One of the games is : giving a sequence of integers, calculate the sum from the i'th integer to the j'th integer.One day he plays the game and feeling really exhausted. Can you help him?
 
 Input
 The first line is the integer n( 1 <= n <= 100000) indicates the number of integers.
 This is followwed by the n integers.
 The following lines each starts with a letter.
 The letter a is followed by two integers i (1 <= i <= n), x ,indicates that the i'th number is added by x; (The number of a is at most 100000)
 The letter q is followed by two integers i, j (1 <= i <= j <= n),require the sum from the i'th number to the j'th number; (The number of q is at most 30000)
 The letter e indicates the end of input.
 
 
 Output
 For each q ,output the sum from the i'th number to the j'th number.
 The sum will be less than 231.
 
 Sample Input
 5
 1 2 3 4 5
 a 1 2
 a 4 4
 q 1 1
 q 1 4
 a 5 5
 q 5 5
 e
 Sample Output
 3
 16
 10
*/