#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n&&n) {
        int i,j,k,c1[10001],c2[10001];
        for (i=0; i<=n; i++) {
            c1[i]=1;
            c2[i]=0;
        }
        for (i=2; i*i<=n; i++) {
            for (j=0; j<=n; j++)
                for (k=0; j+k<=n; k+=i*i)
                    c2[j+k]+=c1[j];
            for (j=0; j<=n; j++) {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout << c1[n] << '\n';
    }
    return 0;
}
/*
 Problem Description
 People in Silverland use square coins. Not only they have square shapes but also their values are square numbers. Coins with values of all square numbers up to 289 (=17^2), i.e., 1-credit coins, 4-credit coins, 9-credit coins, ..., and 289-credit coins, are available in Silverland. 
 There are four combinations of coins to pay ten credits: 
 
 ten 1-credit coins,
 one 4-credit coin and six 1-credit coins,
 two 4-credit coins and two 1-credit coins, and
 one 9-credit coin and one 1-credit coin. 
 
 Your mission is to count the number of ways to pay a given amount using coins of Silverland.
 
 
 Input
 The input consists of lines each containing an integer meaning an amount to be paid, followed by a line containing a zero. You may assume that all the amounts are positive and less than 300.
 
 
 Output
 For each of the given amount, one line containing a single integer representing the number of combinations of coins should be output. No other characters should appear in the output. 
 
 
 Sample Input
 2
 10
 30
 0
 
 
 Sample Output
 1
 4
 27
*/