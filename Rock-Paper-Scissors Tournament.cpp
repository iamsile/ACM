#include <iostream>
#include <stdio.h>

int main()
{
	int n,m,f=0,w[102],num[102];//w[102]为统计赢的次数，另一个是总的个数
	while(scanf("%d",&n)&&n)
	{
		if(f)
			printf("\n");
		f=1;
		scanf("%d",&m);
		int i,a,c,l=m*n*(n-1)/2;
		char b[9]={0},d[9]={0};
		memset(w, 0, sizeof(w));
		memset(num, 0, sizeof(num));
		for(i=1;i<=l;i++)
		{
			scanf("%d%s%d%s",&a,b,&c,d);
			if((b[0]=='r'&&d[0]=='p')||(b[0]=='p'&&d[0]=='s')||(b[0]=='s'&&d[0]=='r'))
			{
				w[c]++;
				num[c]++;
				num[a]++;
			}
			else if((d[0]=='r'&&b[0]=='p')||(d[0]=='p'&&b[0]=='s')||(d[0]=='s'&&b[0]=='r'))
			{
				w[a]++;
				num[a]++;
				num[c]++;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(w[i]==0&&num[i]==0)
				printf("-\n");
			else 
			{
				double r=(double)w[i]/num[i];
				printf("%.3f\n",r);
			}
		}
	}
	return 0;
}
/*
 Problem description
 Rock-Paper-Scissors is game for two players, A and B, who each choose, independently of the other, one of rock, paper, or scissors. A player chosing paper wins over a player chosing rock; a player chosing scissors wins over a player chosing paper; a player chosing rock wins over a player chosing scissors. A player chosing the same thing as the other player neither wins nor loses. A tournament has been organized in which each of n players plays k rock-scissors-paper games with each of the other players - k*n*(n-1)/2 games in total. Your job is to compute the win average for each player, defined as w / (w + l) where w is the number of games won, and l is the number of games lost, by the player. 
 
 Input
 Input consists of several test cases. The first line of input for each case contains 1 <= n <= 100 1 <= k <= 100 as defined above. For each game, a line follows containing p1, m1, p2, m2. 1 <= p1 <= n and 1 <= p2 <= n are distinct integers identifying two players; m1 and m2 are their respective moves ("rock", "scissors", or "paper"). A line containing 0 follows the last test case.
 
 Output
 Output one line each for player 1, player 2, and so on, through player n, giving the player's win average rounded to three decimal places. If the win average is undefined, output "-". Output an empty line between cases.
 
 Sample Input
 2 4
 1 rock 2 paper
 1 scissors 2 paper
 1 rock 2 rock
 2 rock 1 scissors
 2 1
 1 rock 2 paper
 0
 Sample Output
 0.333
 0.667
 
 0.000
 1.000
*/