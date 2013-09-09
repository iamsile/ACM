#include <iostream>
using namespace::std;

int main()
{
	int i,m,n,k,lab,j=1,sum,a[1001]={0};
	while(cin >> n >> m&&n&&m)
	{
		lab=0;//lab是用来就对方可以大你的次数。只有lab=0的时候，才说明你可以大了
		sum=0;
		memset(a, 0, sizeof(a));
		for(i=0;i<m;i++)
		{
			cin >> k;
			a[k]=1;//拥有的牌
		}
		for(i=m*n;i>=0;i--)//从最大的往前数
		{
			if(a[i])
			{
				if(lab==0)
					sum++;
				else 
					lab--;
			}
			else 
				lab++;////代表到数字为i的牌为止对方有比你大的牌的次数   
		}
		cout << "Case " << j++ << ": " << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 
 Suppose there are M people, including you, playing a special card game. At the beginning, each player receives N cards. The pip of a card is a positive integer which is at most N*M. And there are no two cards with the same pip. During a round, each player chooses one card to compare with others. The player whose card with the biggest pip wins the round, and then the next round begins. After N rounds, when all the cards of each player have been chosen, the player who has won the most rounds is the winner of the game. Given your cards received at the beginning, write a program to tell the maximal number of rounds that you may at least win during the whole game.
 
 Input
 
 The input consists of several test cases. The first line of each case contains two integers m (2m20) and n (1n50), representing the number of players and the number of cards each player receives at the beginning of the game, respectively. This followed by a line with n positive integers, representing the pips of cards you received at the beginning. Then a blank line follows to separate the cases. The input is terminated by a line with two zeros. 
 
 Output
 
 For each test case, output a line consisting of the test case number followed by the number of rounds you will at least win during the game.
 
 Sample Input
 2 5
 1 7 2 10 9
 6 11
 62 63 54 66 65 61 57 56 50 53 48
 0 0
 Sample Output
 Case 1: 2
 Case 2: 4
*/