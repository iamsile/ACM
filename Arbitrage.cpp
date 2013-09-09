#include <iostream>
#include <string.h>
using namespace std;
char s[40][101],a[101],b[101];
int n;

int judge(char c[])
{
    for (int i=0; i<n; i++)
        if (strcmp(c, s[i])==0)
            return i;
}

int main()
{
    int lab=1;
    while (cin >> n&&n) {
        int i,j,k,m,x,y;
        double t,map[50][50]={0};
        for (i=0; i<n; i++)
            cin >> s[i];
        cin >> m;
        while (m--) {
            cin >> a >> t >> b;
            x=judge(a);
            y=judge(b);
            map[x][y]=t;
        }
        for (k=0; k<n; k++)
            for (i=0; i<n; i++)
                for (j=0; j<n; j++)
                    if (map[i][k]*map[k][j]>map[i][j]) {
                        map[i][j]=map[i][k]*map[k][j];
                        if (map[0][0]>1)
                            break;
                    }
        if (map[0][0]>1)
            cout << "Case " << lab++ << ": Yes\n";
        else cout << "Case " << lab++ << ": No\n";
    }
    return 0;
}
/*
 Problem Description
 Arbitrage is the use of discrepancies in currency exchange rates to transform one unit of a currency into more than one unit of the same currency. For example, suppose that 1 US Dollar buys 0.5 British pound, 1 British pound buys 10.0 French francs, and 1 French franc buys 0.21 US dollar. Then, by converting currencies, a clever trader can start with 1 US dollar and buy 0.5 * 10.0 * 0.21 = 1.05 US dollars, making a profit of 5 percent. 
 
 Your job is to write a program that takes a list of currency exchange rates as input and then determines whether arbitrage is possible or not.
 
 
 Input
 The input file will contain one or more test cases. Om the first line of each test case there is an integer n (1<=n<=30), representing the number of different currencies. The next n lines each contain the name of one currency. Within a name no spaces will appear. The next line contains one integer m, representing the length of the table to follow. The last m lines each contain the name ci of a source currency, a real number rij which represents the exchange rate from ci to cj and a name cj of the destination currency. Exchanges which do not appear in the table are impossible.
 Test cases are separated from each other by a blank line. Input is terminated by a value of zero (0) for n. 
 
 
 Output
 For each test case, print one line telling whether arbitrage is possible or not in the format "Case case: Yes" respectively "Case case: No". 
 
 
 Sample Input
 3
 USDollar
 BritishPound
 FrenchFranc
 3
 USDollar 0.5 BritishPound
 BritishPound 10.0 FrenchFranc
 FrenchFranc 0.21 USDollar
 
 3
 USDollar
 BritishPound
 FrenchFranc
 6
 USDollar 0.5 BritishPound
 USDollar 4.9 FrenchFranc
 BritishPound 10.0 FrenchFranc
 BritishPound 1.99 USDollar
 FrenchFranc 0.09 BritishPound
 FrenchFranc 0.19 USDollar
 
 0
 
 
 Sample Output
 Case 1: Yes
 Case 2: No
*/