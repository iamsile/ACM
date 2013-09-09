#include <iostream>
using namespace std;
int n,m,a[110],v[110],sum,maxn,len;

int dfs(int s)
{
    if (sum>maxn&&sum<=m&&!len) {
        maxn=sum;
    }
    for (int i=s; i>=0; i--) {
        if (!v[i]&&a[i]<=m&&len) {
            sum+=a[i];
            v[i]=1;
            len--;
            dfs(s-1);
            v[i]=0;
            sum-=a[i];
            len++;
        }
    }
    return maxn;
}

int main()
{
    
    while (~scanf("%d%d",&n,&m)) {
        int i;
        for (i=0; i<n; i++)
            scanf("%d",&a[i]);  
        sum=0;
        len=3;
        maxn=0;
        printf("%d\n",dfs(n-1));
    }
    return 0;
}
/*
 Problem Description
 In “Blackjack”, a popular card game, the goal is to have cards which sum up to largest number not exceeding 21. Mirko came up with his own version of this game. In Mirko's game, cards have positive integers written on them. The player is given a set of cards and an integer M. He must choose three cards from this set so that their sum comes as close as possible to M without exceeding it. This is not always easy since there can be a hundred of cards in the given set. Help Mirko by writing a program that finds the best possible outcome of given game.
 Input
 The input consists of multiple test cases.The first line of input contains an integer N (3 ≤ N ≤ 100), the number of cards, and M (10 ≤ M ≤ 300 000), the number that we must not exceed. 
 The following line contains numbers written on Mirko‘s cards: N distinct space-separated positive integers less than 100 000. There will always exist some three cards whose sum is not greater than M.
 Output
 The first and only line of output should contain the largest possible sum we can obtain.
 Sample Input
 5 21
 5 6 7 8 9
 10 500
 93 181 245 214 315 36 185 138 216 295
 Sample Output
 21
 497
*/