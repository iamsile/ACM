#include<iostream>
using namespace::std;

int trans(int k)
{
	int sum=0;
	int p=1;
    while (k)   //这里是关键可以把一个数转换成任意的进制
    {
		sum=sum+(k%10)*p;
		k/=10;
		p*=9;
    }
    return sum;
}

void add(int m,int n)
{
	int sum,s,k;
	sum=m+n;
	s=0;
	k=1;
	while (sum)
	{
		s=s+k*(sum%9);
		sum/=9;
		k*=10;
	}
	cout << s << '\n';
}

int main()
{
	int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
		add(trans(m),trans(n));
    return 0;
}
/*
 Problem description
 
 Normally, you use base 10 to do arithmetic. In computer science, you also deal with binary (base 2), octal (base 8), and hex (base 16). In this problem, we'll worry about base 9, which uses the digits 0..8. 
 
 Input
 
 each line of input will contain two numbers separated by a space. Each number is in base 9. If converted to base 10, the numbers would be greater than 0(include 0), and smaller than 65000(include 65000). 
 
 Output
 
 For each input, your program should add the two numbers together and print the result (in base 9).
 
 Sample Input
 148 765
 111 888
 8734 8345
 Sample Output
 1024
 1110
 18180
*/