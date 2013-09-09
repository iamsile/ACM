#include <iostream>
using namespace::std;

int main()
{
	int e,f,c;
	while(cin >> e >> f >> c)
	{
		int sum=e+f,lab=0;
		while(sum>=c)
		{
			sum=sum-c+1;
			lab++;
		}
		cout << lab << '\n';
	}
	return 0;
}
/*
 Problem description
 Tim is an absolutely obsessive soda drinker, he simply cannot get enough. Most annoyingly though, he almost never has any money, so his only obvious legal way to obtain more soda is to take the money he gets when he recycles empty soda bottles to buy new ones. In addition to the empty bottles resulting from his own consumption he sometimes find empty bottles in the street. One day he was extra thirsty, so he actually drank sodas until he couldn't afford a new one. 
 
 
 Input
 Three non-negative integers e; f; c, where e < 1000 equals the number of empty soda bottles in Tim's possession at the start of the day, f < 1000 the number of empty soda bottles found during the day, and 1 < c < 2000 the number of empty bottles required to buy a new soda. 
 
 
 Output
 How many sodas did Tim drink on his extra thirsty day? 
 
 
 Sample Input
 9 0 3 
 5 5 2
 Sample Output
 4
 9
*/