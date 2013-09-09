#include <iostream>
using namespace::std;

int main()
{
	int s,p,y,j,tmp,z, x1, x2;
	while(scanf("%d%d%d%d",&s,&p,&y,&j)!=EOF)
	{
		x1=0;
		x2=0;
		tmp=12+j-p-y;
		if(tmp%3==0)
			z=tmp/3;
		else if((tmp-1)%3==0)
		{
			z=(tmp-1)/3;
			if(p+s==y)
				x1=1;
			else
				x2=1;
		}
		else 
		{
			z=(tmp-2)/3;
			x1=1;
			x2=1;
		}
		printf("%d %d %d\n",z+y+x1,z+p+x2,z);
	}
	return 0;
}

/*
 Sa代表Spot's age, Pa ......x1,x2,x3分别代表多出来的月份（或天或小时或分钟秒钟毫秒微妙纳秒)
 
 Sa=Pa+s+x1  ------------------------(1)
 Pa=Ya+p+x2  ------------------------(2)
 Sa=Ya+y+x3  ------------------------(3)
 [Sa]+[Pa]+[Ya]=d+j ---------------(4)
 (1) and (2) =>
 Sa=Ya+p+s+x1+x2  ---------------(5)
 with (3) => p+s+x1+x2=y+3
 [Ya+y+x3]+[Ya+p+x2]+[Ya]=d+j
 [Ya+x3]+[Ya+x2]+[Ya]=d+j-y-p
 
 when p+s==y
 then x1+x2==x3=>x3>x2
 if [Ya+x2]=[Ya]+1,then [Ya+x3]=[Ya]+1
 so [Ya]=(d+j-p-y-2)/3
 ***if [Ya+x3]=[Ya]+1,and [Ya+x2]=[Ya]
 ***so [Ya]=(d+j-y-p-1)/3
 else [Ya]=(d+j-y-p-1)/3
 
 when p+s==y-1,x1+x2=1+x3=>x2>x3
 if [Ya+x2]=[Ya]+1,then [Ya+x3]=[Ya]+1
 so [Ya]=(d+j-p-y-2)/3
 ***if [Ya+x2]=[Ya]+1,and[Ya+x3]=[Ya]
 ***so [Ya]=(d+j-y-p-1)/3
 else [Ya]=(d+j-y-p-1)/3
 
 注意两种情况中，只有前面加了***的两组不同。*/
/*
 Problem description
 Dick is 12 years old. When we say this, we mean that it is at least twelve and not yet thirteen years since Dick was born. 
 
 Dick and Jane have three pets: Spot the dog, Puff the Cat, and Yertle the Turtle. Spot was s years old when Puff was born; Puff was p years old when Yertle was born; Spot was y years old when Yertle was born. The sum of Spot's age, Puff's age, and Yertle's age equals the sum of Dick's age (d) and Jane's age (j). How old are Spot, Puff, and Yertle? 
 
 Input
 Each input line contains four non-negative integers: s, p, y, j.
 
 Output
 For each input line, print a line containing three integers: Spot's age, Puff's age, and Yertle's age. Ages are given in years, as described in the first paragraph.
 
 Sample Input
 5 5 10 9
 5 5 10 10
 5 5 11 10
 Sample Output
 12 7 2
 13 7 2
 13 7 2
*/