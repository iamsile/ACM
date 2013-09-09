#include <iostream>
using namespace::std;

int main()
{
	int m,i;
	cin >> m;
	while(m--)
	{
		unsigned int n,a[100]={0};
		char b[100][21];
		cin >> n;
		for(i=0;i<n;i++)
		{
			cin >> a[i];
			getchar();
			cin.getline(b[i],21);
		}
		for(i=0;i<n;i++)
			if(a[i]==*(max_element(a, a+n)))
				break;
		cout << b[i]<< '\n';
	}
	return 0;
}
/*
 Problem description
 When football clubs achieve poor results, there is only one thing to do: Buy new players! This is the most popular strategy among the major football clubs in Europe today, and Rosenborg is an example of a Norwegian club which has used this strategy with success. They have many talent scouts travelling around the earth to find promising young footballers.
 Chelsea struggles in Premier League at the moment, and they have decided to buy another player. But they are sick and tired of waiting around for a talent scout to find a descent player, and employ a way more efficient strategy. They actually put a famous saying from B?rum into practice: "If something is on sale, you can be sure there is a reason why."
 In a football setting, this means that the most expensive player is probably the best one. Hence, looking for a new player only involves calling all football clubs and asking for their most expensive player. Your task is to help Chelsea find the most expensive player from a list.
 
 
 Input
 The input has n ≤ 100 cases, where n is given by the first line of input. The first line of each test case is a single positive integer, p ≤ 100, giving the number of players to consider. Then follow p lines, where each line represents a player. The line starts with a positive integer ci < 2 ≤ 109, the price of player i. Then follows a single space before the name of the player. All player prices are unique. Player names are never more than 20 characters long, and contain no spaces.
 
 
 Output
 For each test case your program should output a single line giving the name of the most expensive player. 
 
 Sample Input
 2
 3
 10 Iversen
 1000000 Nannskog
 2000000 Ronaldinho
 2
 1000000 Maradona
 999999 Batistuta 
 Sample Output
 Ronaldinho
 Maradona
*/