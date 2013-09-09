#include <iostream>
#include <string.h>
using namespace::std;
int main()
{
	int m,i;
	char a[2002]={0},temp;
	cin >> m;
	getchar();
	while(m--)
	{
		cin.getline(a,1000);
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]<0)
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				i++;
			}
		}
		for(i=strlen(a)-1;i>=0;i--)
			cout << a[i];
		cout << '\n';
	}
	return 0;
}//此题代码是对的，但是无法在x-code上运行，编译器的缘故
/*
 Problem description
 The children often play a game like this.When one child say some words like "abc",the other must say "cba" as soon as possible.When we take them in the computer,it will give the correct answer quickly. But in China,there is a big problem when we play the game.The ideogram covers different bits from English letter.That is to say, we will consider that how to give a new string which is read from back to front.Meanwhile,don't change any ideograms.
 
 Input
 Standard input will contain multiple test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow, each string is on a separate line and consists of at most 1,000 letters or ideograms. 
 
 Output
 The output will contain a new string which is read from back to front.
 
 Sample Input
 1
 Acm 程序设计大赛
 Sample Output
 赛大计设序程 mcA
*/