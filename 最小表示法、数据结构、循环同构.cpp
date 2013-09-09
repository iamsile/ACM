/*
 最小表示法
 难点：
 证明为何是最小表示
 失配后为什么这样跳跃（经典）
 优化
 */

#include <stdio.h>
#include <string.h>
const int MaxN = 101;
char a[MaxN] , b[MaxN];
//判断两字符串是否循环同构
bool Same(char *a , char *b)
{
	int la = strlen(a) , lb = strlen(b);
	int p1 = 0 , p2 = 0 , k = 0;
	if (la != lb) return false;
	while (p1 < la && p2 < la && k < la)	{
		int tmp = a[(p1 + k) % la] - b[(p2 + k) % la];
		if (tmp == 0)	{
			k ++;
			continue;
		}
		if (tmp > 0)	{
			p1 += k + 1;
		}	else	{
			p2 += k + 1;
		}
	}
	return (k >= la);
}
//寻找字符串的最小表示
int minS(char *s , int l)
{
	int p1 = 0 , p2 = 1 , k = 0;
	while (p1 < l && p2 < l && k < l)	{
		if (s[p1 + k] == s[p2 + k])	{
			k ++;
		}	else if (s[p1 + k] > s[p2 + k])	{
			p1 += k + 1;
			k = 0;
		}	else	{
			p2 += k + 1;
			k = 0;
		}
		if (p1 == p2)	{
			p1 ++;
		}
	}
	if (p1 >= l)	return p2;
	return p1;
}

void __test()
{
	scanf("%s" , a);
	strcpy(b , a);
	strcat(b , a);
	printf("%d/n" , minS(b , strlen(a)));
	scanf("%s %s" , a , b);
	if (Same(a , b))	{
		puts("Same");
	}	else	{
		puts("Different");
	}
}
int main()
{
	__test();
}

/*
 jjakkab
 hhhabcdeffffh
 abcdeffffhhhh
 */