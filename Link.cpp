#include <iostream>
using namespace std;
int a[1021][1021];
int main()
{
    int n,m,i,j,x,y;
    while (cin >> n&&n) {
        int sum=0,flag;
        cin >> m;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                a[i][j]=0;
        for(i=1;i<=m;i++)
        {
            cin >> x >> y;
            a[y][x]=1;
            a[x][y]=1;
        }
        for (i=1; i<=n; i++) {
            flag=0;
            for (j=1; j<i; j++)
                if (a[i][j]) {
                    flag=1;
                    break;
                }
            if (!flag)
                sum++;
        }
        cout << sum-1 << '\n';
    }
    return 0;
}
/*
 Problem description
 Investigating the traffic condition,the province gets a table, which lists the road and two city the road connect. Their goal is to connect evety two road(the roads might not be linked to directly, so long as can be reached each other through the road indirectly). The question is how many roads are still needed to build at least?
 
 Input
 Standard input will contain multiple test cases.The first line of each test case contains two integers: N(1 <= N <= 1000), and M.N stands for city and M for road. M lines follow,each of which presents which two city is connected.To be simple,the city is named from 1 to N. When N is zero , input is over , the example should not be dealt with.
 
 Output
 For each test case, print the minimum roads needed to be build on each line.
 
 Sample Input
 4 2
 1 3
 4 3
 
 3 3
 1 2
 1 3
 2 3
 
 5 2
 1 2
 3 5
 
 999 0
 0
 Sample Output
 1
 0
 2
 998
*/