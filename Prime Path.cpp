#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define INF 99999999
int prime[1100],map[1100][1100];
int d[1100],v[1100];

int cal(int n, int m)
{
    int num=0;
    while(n) {
        if(n%10==m%10) 
            num++;
        n/=10;
        m/=10;
    }
    if(num==3)
        return 1;
    return 0;
}

int main()
{
    int t,n,m,i,j,k,len=0;
    memset(map, 0, sizeof(map));
    for(i=1001; i<10000; i+=2) {
        k=sqrt(i*1.0);
        for(j=3; j<=k; j+=2)
            if(i%j==0) 
                break;
        if(j>sqrt(i*1.0)) 
            prime[++len]=i;
    }
    for(i=1; i<=len; i++) {
        for(j=i+1; j<=len; j++)
            if(cal(prime[i], prime[j])) 
                map[i][j]=map[j][i]=1;
            else
                map[i][j]=map[j][i]=INF;
    }
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(i=1; i<=len; i++) 
            if(prime[i]==n) {
                n=i;
                break;
            }
        for(i=1; i<=len; i++)
            if(prime[i]==m) {
                m=i;
                break;
            }
        memset(v, 0, sizeof(v));
        for(i=1; i<=len; i++) 
            d[i]=(i==n?0:INF);
        for(i=1; i<=len; i++) {
            int x, z=INF;
            for(int j=1; j<=len; j++)
                if(!v[j] && d[j]<=z)
                    z=d[x=j];
            v[x]=1;
            for(int j=1; j<=len; j++) 
                if(d[j]>=d[x]+map[x][j]) 
                    d[j]=d[x]+map[x][j];
        }
        cout << d[m] << endl;
    }
    return 0;
}
/*
 Problem description
 The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices. 
 — It is a matter of security to change such things every now and then, to keep the enemy in the dark. 
 — But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know! 
 — I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door. 
 — No, it’s not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime! 
 — I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds. 
 — Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime. 
 
 Now, the minister of finance, who had been eavesdropping, intervened. 
 — No unnecessary expenditure, please! I happen to know that the price of a digit is one pound. 
 — Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you? 
 — In fact, I do. You see, there is this programming contest going on... Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above. 
 1033
 1733
 3733
 3739
 3779
 8779
 8179
 The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step ? a new 1 must be purchased.
 
 Input
 One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).
 
 Output
 One line for each case, either with a number stating the minimal cost or containing the word Impossible.
 
 Sample Input
 3
 1033 8179
 1373 8017
 1033 1033
 Sample Output
 6
 7
 0
*/