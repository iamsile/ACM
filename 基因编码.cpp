#include <iostream>
using namespace::std;
char a[501];

void cal(int n,char *a)
{
	int i,sum=0;
	for(i=0;i<n;i++)
		if(a[i]=='1')
			sum++;
	if(sum==0)
		cout << 'A';
	else if(sum==n)
		cout << 'B';
	else 
	{
		cout << 'C';
		cal(n/2,a);
		cal(n/2,a+n/2);
	}
}

int main()
{
	while(scanf("%s",a)!=EOF)
	{
		int k=strlen(a);
		cal(k,a);
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 小可可选修了基础生物基因学。教授告诉大家Ｓuper Samuel星球上Kitty猫的基因的长度都是２的正整数次幂 2k (k ≤ 8),全是由两种不同的基因单元组成的。这两种不同的基因单元分别记成 0 和 1，于是Kitty猫的基因可以写成一个 01 串表达式 S 。 为了便于分析和降低数据存储量，教授发明了 ABC 编码规则。该编码规则是不断地按照
 A                 (若S串全是0)
 T（S）=    　　 B                 (若S串全是1)
 　　　　　　　　CT(S1)T(S2)　   (否则把S串分成两个等长的子串S1和S2)
 对Kitty猫基因01串表达式S进行改写，直至最终被改写成只含有字符“A”、“B”、“C”的符号串。
 例如 T(01001011)
 = CT(0100)T(1011)
 = CCT(01)T(00)CT(10)T(11)
 = CCCT(0)T(1)ACCT(1)T(0)B
 = CCCABACCBAB
 请你编写程序帮助小可可求出Kitty猫基因的ABC编码以协助教授开展科研工作。 
 
 Input
 测试数据有多组，每组以一行的形式存放Kitty猫基因的01串表达式, 字符串长度不超过500。
 
 Output
 对应每一组测试数据，以一行的形式输出这个Kitty猫基因的ABC编码。
 
 Sample Input
 00
 01001011
 Sample Output
 A
 CCCABACCBAB
*/