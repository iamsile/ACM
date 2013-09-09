#include <cassert>
#include <cmath>
#include <cstdio>
using namespace std;

double a[1001][1001];
double cal(int x,int y) 
{
	if (a[x][y]>=0.0) 
		return a[x][y];
	double p; 
	if(y==0) 
		p=1.0; 
	else if(x==0)
		p=0.0; 
	else
		p=.1*cal(x,y-1)+.2*cal(x-1,y-1)+.7*cal(x-1,y);
	return a[x][y]=p; 
}

int main() 
{
	for(int x=0;x<=1000;++x) 
		for(int y=0;y<=1000;++y) 
			a[x][y]=-1.0;
	int n; 
	scanf("%d",&n);
	while (n--) 
	{
		int x, y;
		scanf("%d%d",&x, &y);
		double p=cal(x, y);
		printf("%.3lf\n", p);
	}
	return 0;
}
/*
				  1               if  y=0
 p(x,y)=	      0              else if x=0
				 0.1*p(x,y-1)+0.2p(x-1,y-1)+0.7*p(x-1,y)     otherwise
 
 */
/*
 Problem description
 Vampire is a popular roleplaying game. As most roleplaying games, Vampire uses dice to determine random events. The most common use of the dice is to determine if you succeed or fail at a specic task. A task might be shooting another player, avoid falling out of a window, dodge a hit from an opponent etc.
 The dice used in Vampire is 10-sided and the rules are as follows: You are allowed to roll x dice and you need y or more points to succeed. If a dice shows 8, 9 or 10 you get one point. This means that 1 through 7 gives no points. In addition, if you are lucky enough to roll a 10 you get one extra dice roll. This means that it is possible to get 2 or even more points even if you started out with only one dice.
 An example: Truls tries to avoid falling into a trap. To see if she succeeds she has to roll 4 or more successes on 5 dice. The first roll gives her two 10s, one 4, one 6 and one 3. This means she only got two successes, but because she got two 10s she gets to roll two more dice. This time she rolls another 10 and a 2. She now has three successes and one more dice roll. The last roll lands on 5 and Truls falls into a big pit and dies. But how big was Truls' chance of avoding death in the rst place? Truls asks you to device a program that for a given number of dice and a point requirement tells her her chance of surviving.
 
 Input
 The first line gives 1 <= n <= 100, the number of cases. Then follow two numbers x and y on each line, where 0 <= x <= 100 is the number of dice and 0 <= y <= 100 is the number of points needed to succeed.
 
 Output
 The output should consist of one line per case with the chance that the rolls succeed. It should be rounded to three decimal places.
 
 Sample Input
 4
 1 1
 1 2
 6 3
 2 9
 Sample Output
 0.300
 0.030
 0.320
 0.000
*/