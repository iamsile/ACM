#include <iostream>
using namespace::std;

int main()
{
	char a[76],b[76];
	while(cin >> a >> b&&a[0]!='E'&&b[0]!='E')
	{
		int i,j=0,k=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]==b[i])
				continue;
			if(a[i]=='R')
			{
				if(b[i]=='S')
					j++;
				else if(b[i]=='P')
					k++;
				continue;
			}
			if(a[i]=='P')
			{
				if(b[i]=='R')
					j++;
				else if(b[i]=='S')
					k++;
				continue;
			}
			if(a[i]=='S')
			{
				if(b[i]=='P')
					j++;
				else if(b[i]=='R')
					k++;
				continue;
			}
		}
		printf("P1: %d\nP2: %d\n",j,k);
	}
	return 0;
}
/*
 Problem description
 Rock, Paper, Scissors is a classic hand game for two people. Each participant holds out either a fist (rock), open hand (paper), or two-finger V (scissors). If both players show the same gesture, they try again. They continue until there are two different gestures. The winner is then determined according to the table below:
 
 Rock	beats	Scissors
 Paper	beats	Rock
 Scissors	beats	Paper
 Your task is to take a list of symbols representing the gestures of two players and determine how many games each player wins.
 
 In the following example:
 
 Turn     : 1 2 3 4 5
 Player 1 : R R S R S
 Player 2 : S R S P S
 
 Player 1 wins at Turn 1 (Rock beats Scissors), Player 2 wins at Turn 4 (Paper beats Rock), and all the other turns are ties.
 
 
 
 Input
 The input contains between 1 and 20 pairs of lines, the first for Player 1 and the second for Player 2. Both player lines contain the same number of symbols from the set {'R', 'P', 'S'}.  The number of symbols per line is between 1 and 75, inclusive.  A pair of lines each containing the single character 'E' signifies the end of the input.
 
 Output
 For each pair of input lines, output a pair of output lines as shown in the sample output, indicating the number of games won by each player
 
 Sample Input
 RRSRS
 SRSPS
 PPP
 SSS
 SPPSRR
 PSPSRS
 E
 E
 Sample Output
 P1: 1
 P2: 1
 P1: 0
 P2: 3
 P1: 2
 P2: 1
*/