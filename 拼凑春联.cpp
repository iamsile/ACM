#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
int myCompare(const int *a,const int *b)
{
	if(*a>*b)
		return -1;
	else if(*a<*b)
		return 1;
	return 0;
}
int main()
{
	int  i,j,n,set,count,sum,*p;
	int  meter[]={1,2,4,8,16,32,64,128}; 
	char str[10],c;
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	memset(p,0,n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		for(set=1,c=str[0],j=0;j<7;j++)
		{
			if(c!=str[j])
				set=(set?0:1);
			if(set)
				p[i]|=meter[j];
			c=str[j];
		}
	}
	qsort(p,n,sizeof(int),myCompare);
	for(count=sum=0,i=1;i<n;i++)
	{
		if(p[i]==p[i-1])
		{
			count++;
			sum+=count;
		}
		else
			count=0;
	}
	printf("%d\n",sum);
	free(p);
	return 0;
}
/*
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 int main()
 {
 int count[64];
 int n,i,j,c;
 char s[10];
 __int64 ans;
 memset(count,0,sizeof(count));
 scanf("%d",&n);
 for(i=0;i<n;i++){
 scanf("%s",s);
 c=0;
 for(j=1;j<7;j++ )
 c=c*2+(s[j]!=s[j-1]);
 count[c]++;
 }
 ans=0;
 for(i=0;i<64;i++)
 ans=ans+((__int64)(count[i])*(count[i]-1))/2;
 printf("%I64d\n",ans);
 return 0;
 }
 *//*
  Problem description
  春节到了，春联是必不可少的东西^_^。
  众所周知，一幅对联的“上联”和“下联”是对偶（也叫对仗）的。例如：
  上联：九州雨顺千山绿
  下联：六合风调万户丰
  
  BluePoint不喜欢已有的春联组合，所以此人想从已知的佳句中找出两句对偶的，组合出一些新的春联^_*。图书馆有一个“名句文库”，BluePoint想知道其中的名句一共可以拼凑出多少组不同的春联，请您帮帮忙，好吗？
  为了简化问题，BluePoint只选择七个字的佳句，并把它们的形式化成了字母（按意群将句子分组、断开）。例如“鲲鹏展翅乾坤大”可化为“AABBCCD”，也可以化为“YYQQZZH”，即字母只起显示结构的作用，与句子内容无关。
  两个句子按照字母的连续性分段后，如果各成分的字数依次相同，则这两个句子对偶。例如：例如“QBLLLDE”和“DEZZZBF”，将第一句按照字母的连续性分为5段：Q、B、LLL、D、E，每段长度分别为1、1、3、1、1，而第二句经过断句后，各段的长度也分别为1、1、3、1、1，因此这两个句子对偶。
  注：“AABCCCD”和“EEFBBBE”这类句子也算作对偶：第二个句子中两次出现“E”，但“E”是断开的，所以断句情况仍为：2、1、3、1。由于字母只用来突出结构，所以如果出现两次同样的字母串，则它们表示的春联内容不相同，当然，它们是对偶的。 
  
  Input
  第一行，一个整数N，2≤N≤100000 以下N行，每行都有一个由七个大写字母组成的字符串，代表一个佳句。 
  
  Output
  一个整数：这些佳句可以拼凑成的对联的种类数。 这个整数占一行。 
  
  Sample Input
  5
  ABCCCDA
  LLLMNNO
  DEZZZBF
  AAABCCD
  KKKXPPQ
  Sample Output
  4
*/