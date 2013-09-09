#include <iostream>
using namespace::std;

int main()
{
	char a[20];
	while(cin >> a)
	{
		int i,n=strlen(a),b[20];
		for(i=0;i<n;i++)
		{
			if(a[i]=='B'||a[i]=='F'||a[i]=='P'||a[i]=='V')
				b[i]=1;
			else if(a[i]=='C'||a[i]=='G'||a[i]=='J'||a[i]=='K'||a[i]=='Q'||a[i]=='S'||a[i]=='X'||
					a[i]=='Z')
				b[i]=2;
			else if(a[i]=='D'||a[i]=='T')
				b[i]=3;
			else if(a[i]=='L')
				b[i]=4;
			else if(a[i]=='M'||a[i]=='N')
				b[i]=5;
			else if(a[i]=='R')
				b[i]=6;
			else b[i]=0;
		}
		for(i=0;i<n;i++)
		{
			while(b[i]==b[i+1])
				i++;
			if(b[i])
				cout << b[i];
		}
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 SDEX是SDEX公司推出的，按照单词的形状进行的编码。比如"can" 和"khawn"， "con" 和"gone" 在SDEX编码后会被认为相同。 
 SDEX编码将一串字符转化为一串数字，一个数字代替一个字符。
 1 代表B, F, P, or V
 2 代表C, G, J, K, Q, S, X, or Z
 3 代表D or T
 4 代表L
 5 代表M or N
 6 代表R
 
 字符 A, E, I, O, U, H, W, 和Y 在该编码中不代表任何数字，重复的代表数字相同的字符只用一个数字来表示。如果两个字符串的SDEX编码相同，就认为这两个字符串相同。 
 
 Input
 每行一个单词，全部由大写字母组成，最长20个字符
 
 Output
 对于每一个输入值，输出对应的SDEX编码的结果，一个结果一行。
 
 Sample Input
 KHAWN
 PFISTER
 BOBBY
 Sample Output
 25
 1236
 11
*/