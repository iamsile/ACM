#include <iostream>
#include <string.h>
using namespace::std;

int main()
{
	char a[200],b[200];
	int lab=0,sum=0;
	cin.getline(a,200);
	cin.getline(b,200);
	for(int i=0;i<strlen(b);i++)
		if(b[i]!=a[i])
		{
			a[i]=b[i];
			++lab;
		}
	sum=lab+strlen(a)-strlen(b)-1;
	cout << sum << '\n';
	return 0;
}
/*
 Problem description
 设A和B是两个字符串。我们要用最少的字符操作次数，将字符串A转换为字符串B。这里所说的字符操作共有三种：
 
 1.	删除一个字符；
 2.	插入一个字符；
 3.	将一个字符改为另一个字符。
 对任给的两个字符串A和B，计算出将字符串A变换为字符串B所用的最少字符操作次数。
 
 Input
 第一行为字符串A；第二行为字符串B；字符串A和B的长度均小于200。
 
 Output
 只有一个正整数，为最少字符操作次数。
 
 Sample Input
 sfdxbqw
 gfdgw
 Sample Output
 4
*/