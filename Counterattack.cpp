#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int i,j,k,p,n,x,y,dp[2][4],a[4][100010];
        scanf("%d%d%d%d%d",&n,&dp[0][0],&dp[1][0],&x,&y);
        for (i=0; i<4; i++)
            for (j=1; j<n; j++)
                scanf("%d",&a[i][j]);
        for (i=1,p=0; i<n; i++) {
            k=1-p;
            dp[0][k]=min(dp[0][p]+a[1][i], dp[1][p]+a[2][i]);
            dp[1][k]=min(dp[1][p]+a[3][i], dp[0][p]+a[0][i]);
            p=k;
        }
        printf("%d\n",min(dp[0][p]+x, dp[1][p]+y));
    }
    return 0;
}
/*
#include<cstdio>
int t, n, s1, s2;
short inf[4][100010];
int dp[2][2];
int i,j,p,r;
int IMin( int a, int b ){ return a<b?a:b; }
int k; char c;
int main() {
    scanf( "%ld", &t );
    while( t-- ) {
        scanf( "%ld%ld%ld", &n, &dp[0][0], &dp[1][0] );
        scanf( "%ld%ld", &s1, &s2 );
        for( i=0; i<4; ++i )
            for( j=1; j<n; ++j ) {
                while( (c=getchar())<'0' );
                inf[i][j]=c-'0';
                while( (c=getchar())>='0' )inf[i][j]=inf[i][j]*10+c-'0';
            }
        p=0;
        for( int i=1; i<n; ++i ) {
            r=1-p;
            dp[0][r] = IMin( dp[0][p]+inf[1][i] , dp[1][p]+inf[2][i] );
            dp[1][r] = IMin( dp[1][p]+inf[3][i] , dp[0][p]+inf[0][i] );
            p=r;
        }
        printf( "%ld\n", IMin( dp[0][p]+s1, dp[1][p]+s2 ) );
    }
}
 
 At our soccer training camp, we have rehearsed a lot of motion sequences. In case we are defending, all players except the two strikers of our team are in our half. As soon as we are getting the ball, we are starting a counterattack with a long-range pass to one of our strikers. They know each others motion sequences and may pass the ball to the other striker at fixed points.
 There are a lot of decisions: the defender has to select the striker to pass the ball to, and the ball possessing striker has to decide at each of the n fixed points if to pass to the other striker or to run and to dribble. At the last position in the motion sequence of a striker he shoots on the goal. Each of the four actions (long-range pass, dribble, pass, and shoot on the goal) may fail (e.g. because of a defending player of the opposite team) - so our coach has assigned diculties.
 What's the minimal diculty of a goal assuming your team plays optimally?
 
 
 
 
 The defending player (cross in left half) passes the ball to one of the strikers (crosses in right half). The strikers move along fixed paths simultaneously. At each of the fixed positions (circles), the ball possessing striker either dribbles with the ball or passes to the other striker. At the last position, he shoots on the goal.
 
 Input
 The first line of the input consists of the number of test cases c that follow (1 <= c <= 100). Each test case consists of five lines. The first line of each test case contains n (2 <= n <= 100000), the number of xed points in each strikers motion sequence. It is followed by l0, l1, s0 and s1, the diculty of a long-range pass to the corresponding striker and the difficulties of the shoots of the strikers. Each striker is described in two lines (first striker 0, then striker 1): The first line contains n - 1 difficulties, where the ith number stands for passing from point i to the other player at point i + 1. The second line also contains n - 1 diculties, where the ith number stands for dribbling from point i to point i + 1. You may safely assume that each diculty is a non-negative integer less than 1000.
 
 Output
 For each test case in the input, print one line containing the minimal diculty of a move sequence leading to a goal.
 
 Sample Input
 2
 3 3 5 7 999
 9 13
 60 5
 22 6
 5 5
 5 3 5 7 999
 9 13 8 4
 60 5 17 13
 22 6 15 11
 5 5 18 29
 Sample Output
 23
 42
*/