#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int b,i,j,k,m,v,c1[1001],c2[1001],c3[1001];
        memset(c2, 0, sizeof(c2));
        memset(c1, 0, sizeof(c1));
        memset(c3, 0, sizeof(c3));
        cin >> b >> v >> m;
        if (v>m)
            v=m;
        for (i=0; i<=v; i++) {
            c1[i]=1;c2[i]=1;
        }
        for (i=1; i<b; i++) {
            for (j=0; j<=m; j++)
                for (k=0; k<=v; k++)
                    if (j+k<=m)
                        c3[j+k]+=c1[k]*c2[j];
            for (j=0; j<=m; j++) {
                c2[j]=c3[j];
                c3[j]=0;
            }
        }
        cout << c2[m] << '\n';
    }
    return 0;
}/*
#include<iostream>
using namespace std;
int opt[10][30][150];
int main()
{
	int i,t,j,k,a,b,c,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&c,&b);
		for(i=0;i<=a;i++)
			for(j=0;j<=c;j++)
				for(k=0;k<=b;k++)
					opt[i][j][k]=0;
		//for(i=1;i<=a;i++)
        // opt[i][1][1]=i;
		for(i=0;i<=a;i++)
			for(j=0;j<=c;j++)
				opt[i][j][0]=1;
		for(i=1;i<=a;i++)
			for(j=1;j<=c;j++)
				for(k=1;k<=b;k++){
					if(i*j>=k){
						for(m=0;m<=c&&m<=k;m++){
							//if(i==2&&j==1&&k==1)
							//	printf("asd %d %d %d %d\n",i-1,j,k-m,opt[i][j][k]);
							opt[i][j][k]+=opt[i-1][j][k-m];
							
						}//if(i==2&&j==1&&k==1)
						//printf("asd %d %d %d %d\n",i,j,k,opt[i][j][k]);
					}
					else{
						opt[i][j][k]=0;
					}
				}
		printf("%d\n",opt[a][c][b]);
	}
}*/
/*
 Problem description
 You have several identical balls that you wish to place in several baskets. Each basket has the same maximum capacity. You are given an integer baskets, the number of baskets you have. You are given an int capacity, the maximum capacity of each basket. Finally you are given an int balls, the number of balls to sort into baskets.
 Return the number of ways you can divide the balls into baskets. If this cannot be done without exceeding the capacity of the baskets, return 0.
 Each basket is distinct, but all balls are identical. Thus, if you have two balls to place into two baskets, you could have (0, 2), (1, 1), or (2, 0), so there would be three ways to do this.
 
 
 Input
 The input contains several test cases. The first line of the input is the test case number N. For each test case, there are three positive integers separated by spaces, namely indicates the baskets (<=6), the capacity (<=20) and the balls (<=100).
 
 Output
 For each test case, you should output one number in a line, which is the total number of the possibilities.
 
 Sample Input
 5
 2 20 2
 3 20 1
 3 20 2
 1 5 10
 4 5 10
 Sample Output
 3
 3
 6
 0
 146
*/