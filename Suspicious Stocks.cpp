#include <iostream>

int main()
{
	int d;
	while(scanf("%d",&d)&&d)
	{
		int i,m,a,e,n=0,max=100000;
		scanf("%d",&m);
		for(i=0;i<d;i++)
		{
			scanf("%d",&a);
			e=m/max*a+m%max-m;
			if(e>n)
				n=e;
			if(a<max)
				max=a;
		}
		printf("%d\n",n);
	}
	return 0;
}
/*
 Problem description
 The corruption is always extremely difficult to prove. Even if we know that some people accept bribes, it is almost impossible to punish them, because the only witnesses are them and the people who offered the bribe. Neither of them is likely to testify.
 
 One way to prove that something illegal has happened is to count the money a person has and then give evidence that it was impossible for him/her to earn that money legally. However, this is not so easy. For example, the person may easily claim that the money have been donated by their uncle or earned by trading stocks.
 
 ACM would like to be able to verify these explanations. Since it is impossible to verify the existence of “uncles”, we will concentrate on the stocks. You are given the history of stock prices, and your task is to compute the maximal profit that could possibly be earned by buying and selling the stock.
 
 
 Input
 The input will consist of several test scenarios, each of them consisting of two lines of text. The first line of a scenario contains two positive integers D and M (1 ≤ D ≤ 70000, 1 ≤ M ≤ 40000) separated by a space. D is the number of days when the trading took place, M is the amount of money available at the beginning.
 
 The second line of each scenario contains D positive integers p1, p2, p3, . . . , pD (1 ≤ pi ≤ 40000) separated by a space. The number pi denotes the price of one piece of stock at day i, meaning it is possible to buy or sell one piece for that price on that day.
 
 The last scenario is followed by a line containing single zero.
 
 
 Output
 For each scenario, output one line containing one number: The maximum profit that could be
 achieved by at most one Buy operation followed by one Sell operation. Assume that there is no stock at the beginning and that it is possible to do only one Buy during the whole trading.
 
 For simplicity, assume that it is possible to buy as many pieces of stock as there are money for, but we can only buy and sell whole pieces (integer number) of stock, not fractions. For example, if the stock price is $3 and we have $11, we can only buy 3 pieces.
 
 The Buy operation is followed by exactly one Sell operation on some of the following days. Of course, it is possible (and recommended) to sell all the pieces of stock to maximize profit.
 
 Sample Input
 3 1
 1 2 3
 3 1000
 1200 40 10
 3 10
 3 4 5
 5 10
 2 3 7 1 4
 0 
 Sample Output
 2
 0
 6
 30
*/