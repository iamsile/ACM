#include <iostream>
#include <functional>
using namespace std;

int a[101];
int b[101][1001];

int main(){
    int n,m,i,j,k;
    while(cin >> n&&n)
	{
		memset(b,0,sizeof(b));
		a[0]=m=0;
        for(i=1;i<=n;i++)
		{
			cin >> a[i];
			m+=a[i];
		}
		b[0][0]=1;
        for(k=1;k<=n;k++)
            for(i=1;i<=n/2;i++)
                for(j=m/2;j>=0;j--)
                    if(b[i-1][j])
						b[i][j+a[k]]=1;
        for(i=m/2,j=m/2+1;i>=0;i--,j++){
            if(b[n/2][i])
			{
				printf("%d %d\n",i,m-i);
                break;
			}
            if(b[n/2][j]){
				printf("%d %d\n",m-j,j);
                break;
			}
		}
	}
    return 0;
}
/*
 Problem description
 A tug of war is to be arranged at the local office picnic. For the tug of war, the picnickers must be divided into two teams. Each person must be on one team or the other; the number of people on the two teams must not differ by more than 1; the total weight of the people on each team should be as nearly equal as possible. 
 
 Input
 The first line of input contains n the number of people at the picnic. n lines follow. The first line gives the weight of person 1; the second the weight of person 2; and so on. Each weight is an integer between 1 and 450. There are at most 100 people at the picnic.
 
 Output
 Your output will be a single line containing 2 numbers: the total weight of the people on one team, and the total weight of the people on the other team. If these numbers differ, give the lesser first.
 
 Sample Input
 3
 100
 90
 200
 Sample Output
 190 200
*/