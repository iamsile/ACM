#include <iostream>
using namespace::std;
 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b,i,j,n,time[10001]={0},lab=0,num=0;
		cin >> n;
		for(i=0;i<n;i++)
		{
			cin >> a >> b;
			for(j=a;j<=a+b-1;j++)
				time[j]++;
			if(a+b>lab)
				lab=a+b;
		}
		for(i=0;i<lab;i++)
			num=max(time[i], num);
		cout << num << '\n';
	}
	return 0;
}
/*
 Problem description
 Farrefour Hyper Markets is a well established market in the public republic of Mambozia. Their slogan: "Our Customer is our superhero" was selected to reflect how customer satisfaction has the highest priority. During 2009, Farrefour's management received several complaints from their customers about the long time wasted waiting for the cashier to finish other customers. In order to make their customers really happy, Farrefour decided not to only solve this problem but to exceed customer's expectations by reducing the waiting time to zero. To accomplish this task, Farrefour embedded RFID (radio-frequency identification) chips in its shopping carts and installed RFID readers at each cashier. These RFID readers send signals to specially implemented software that calculates the checkout duration for each customer and saves them to a central database. As a highly reputable software engineer, Farrefour has hired you to write them a software program that analyzes their database to determine the minimum number of cashiers required for each branch.
 
 Input
 The first line contains T ≤ 100 the number of Farrefour branches. The first line of each branch data contains an integer (1 ≤ N ≤ 100) the number of customers in the database. Each of the next N lines contains two integers (1 ≤ S, L ≤ 100). S is the exact time the customer arrived at the cashier and L is how long (in time units) the customer consumed till checkout.
 
 Output
 For each branch, print the minimum number of cashiers on a line by itself.
 
 Sample Input
 2
 3
 1 5
 6 3
 6 3
 3
 1 10
 5 15
 8 3
 Sample Output
 2
 3
*/