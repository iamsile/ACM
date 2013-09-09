#include <iostream>
using namespace::std;

int main()
{
	double a,r,t;
	while(cin >> a >> r >> t)
	{
		int y=0;
		while(a<=t)
		{
			a=a*r/100+a;
			y++;
		}
		cout << y << '\n';
	}
	return 0;
}
/*
 Problem description
 Suppose you open a savings account with a certain initial balance. You will not make any withdrawals or further deposits for a number of years. The bank will compound your balance (add the annual interest) once a year, on the anniversary of the opening of the account. Your goal is to achieve a certain target amount in your savings account. In how may years will the target amount be achieved? 
 
 Input
 The input file will contain data for one or more test cases, one test case per line. Each line will contain three numbers: the initial balance, the annual interest rate (as a percentage of the balance), and the target amount, separated by blank spaces. These will be positive numbers; they may or may not contain a decimal point. The target amount will be greater than the initial balance. The input is terminated by end-of-file
 
 Output
 For each line of input, your program will produce exactly one line of output: This line will contain one positive integer value: the number of years required to achieve the target amount.
 
 Sample Input
 200.00 6.5 300
 500 4 1000.00
 Sample Output
 7
 18
*/