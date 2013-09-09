#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n==0)
            cout << "1\n";
        if (n==1)
            cout << "2\n";
        if (n>=2)
            cout << 2*n*n-4*n+5 << '\n';
    }
    return 0;
}
/*
 * First idea:
 * There are three possibilities for the number of positions you can be in, in a reahable square (one direction, three directions, all directions)
 * After the first four moves, the result for n+1 is a linear combination of the result for n.
 * Speed this up using maxtrix exponentiation.
 * Complexity: O(log(n))
 

#include <cstdio>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

ll A[32][4][4];
ll B[2][4][4];

void run() {
	int n; scanf("%d",&n);
	switch(n) {
		case 0: printf("%d\n",1); return;
		case 1: printf("%d\n",2); return;
		case 2: printf("%d\n",5); return;
	}
	
	n-=3;
	int a=0,b=1;
	REP(i,4) REP(j,4) B[a][i][j]=i==j?1:0;
	
	FOR(x,1,32) if(n&(1<<(x-1))) {
		a=1-a; b=1-b;
		REP(i,4) REP(j,4) { B[a][i][j]=0; REP(k,4) B[a][i][j]+=B[b][i][k]*A[x][k][j]; }
	}
	
	ll ret=0;
	FOR(i,1,4) ret+=1*B[a][i][0]+6*B[a][i][1]+3*B[a][i][2]+2*B[a][i][3];
	printf("%lld\n",ret);
}

void precalc() {
	REP(i,4) REP(j,4) A[0][i][j]=i==j?1:0;
	REP(i,4) REP(j,4) A[1][i][j]=0; A[1][0][0]=1; A[1][1][0]=4; A[1][1][1]=1; A[1][2][1]=1; A[1][3][2]=1; A[1][3][3]=1;
	FOR(x,2,32) REP(i,4) REP(j,4) { A[x][i][j]=0; REP(k,4) A[x][i][j]+=A[x-1][i][k]*A[x-1][k][j]; }
}

int main() {
	precalc();
	
	int n; scanf("%d",&n); REP(i,n) run();
	
	return 0;
}
 #include <stdlib.h> 
 #include <string.h> 
 #include <stdio.h> 
 #include <limits.h> 
 #include <ctype.h> 
 #include <set>
 #include <queue>
 using namespace std;
 
 #define min(a, b) ((a) < (b) ? (a) : (b))
 #define max(a, b) ((a) < (b) ? (b) : (a))
 
 int run ()
 {
 long long x, ans=0;
 scanf("%lld\n",&x);
 if(x==0) ans = 1;
 else if(x==1) ans = 2;
 else
 {
 ans += 2*x*x;
 ans += -4*x;
 ans += 5;
 }
 printf("%lld\n",ans);
 return 0;	
 }
 
 int main ()
 {
 int N,i;
 scanf("%d\n", &N);
 
 for(i=0;i<N;i++) run();
 
 exit (0);
 }
 #include <iostream>
 
 long long calc(long long n)
 {
 long long res = 1;
 res += n;                            // ahead (no turns)
 if(n >= 1) res += (n - 1)*2;         // left/right (1 turn)
 if(n >= 2) res += (n - 2);           // back (2 turns)
 if(n >= 2) res += (n - 1)*(n - 2);   // ahead and left/right (1 turn)
 if(n >= 3) res += (n - 2)*(n - 3);   // left/right and back (2 turns)
 return res;
 }
 
 int main()
 {
 int runs;
 std::cin >> runs;
 while(runs--)
 {
 long long n;
 std::cin >> n;
 std::cout << calc(n) << '\n';
 }
 }

*/
/*
 Problem description
 Herbert is a game in which you control a robot on an infinite two-dimensional grid. There are three commands available to you:
 s: Go one square forward in the current direction.
 l: Turn ninety degrees counterclockwise.
 r: Turn ninety degrees clockwise.
 
 After playing this game for a while, you wonder how many squares you can reach within a certain number of moves. Write a program to calculate the answer to this question.
 
 Input
 On the first line an integer t (1 ≤ t ≤ 100): the number of test cases. Then for each test case:
 One line with an integer n (0 ≤ n ≤ 1 000 000 000): the maximum number of moves.
 
 
 Output
 For each test case:
 One line with the number of reachable squares.
 
 
 Sample Input
 4
 0
 1
 2
 3
 Sample Output
 1
 2
 5
 11
*/