#include <iostream>
#include <memory.h>
using namespace::std;

int main()
{
	int i,m,n,f[1001]={0},g[1001]={0};
	while (cin >> m&&m) {
		n=m;
		f[1]=1;
		f[2]=2;
		f[3]=2;
		g[1]=1;
		g[2]=0;
		g[3]=1;
		for(i=4;i<=n;i++)
		{
			f[i]=f[i-1]+g[i-1];
			g[i]=g[i-1]+g[i-3];
		}
		cout << f[n] << '\n';
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
	}
	return 0;
}
/*
 Problem description
 
 Recurrence relations are where a function is defined in terms of itself and maybe other functions as well. in this problem, we have two functions of interest:
 F (N) = F (N - 1) + G (N - 1) ; F (1) = 1
 
 G (N) = G (N - 1) + G (N - 3) ; G (1) = 1, G (2) = 0, G (3) = 1
 
 For a given value of N, compute F (N). 
 
 
 Input
 
 Each line of input will have exactly one integer, 57 > = N > 0. 
 
 Output
 
 For each line of input, output F(N).
 
 Sample Input
 1
 4
 57
 Sample Output
 1
 3
 2035586497
*/