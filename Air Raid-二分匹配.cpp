#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n,m,map[130][130],v[1400],flag[1400];

bool dfs(int s)
{
    for(int i=1;i<=n;i++) {
        if(!v[i]&&map[s][i]) {
            v[i]=1;
            if(flag[i]==-1||dfs(i)) {
                flag[i]=s;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%d",&m);
        memset(map,0,sizeof(map));
        memset(v,0,sizeof(v));
        memset(flag,-1,sizeof(flag));
        int i,x,y,sum=0;
        for(i=0;i<m;i++) {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        for(i=1;i<=n;i++) {
            if(dfs(i))
                sum++;
        }
        printf("%d\n",n-sum);
    }
    return 0;
}
/*
 Problem Description
 Consider a town where all the streets are one-way and each street leads from one intersection to another. It is also known that starting from an intersection and walking through town's streets you can never reach the same intersection i.e. the town's streets form no cycles.
 
 With these assumptions your task is to write a program that finds the minimum number of paratroopers that can descend on the town and visit all the intersections of this town in such a way that more than one paratrooper visits no intersection. Each paratrooper lands at an intersection and can visit other intersections following the town streets. There are no restrictions about the starting intersection for each paratrooper.
 
 
 Input
 Your program should read sets of data. The first line of the input file contains the number of the data sets. Each data set specifies the structure of a town and has the format:
 
 no_of_intersections
 no_of_streets
 S1 E1
 S2 E2
 ......
 Sno_of_streets Eno_of_streets
 
 The first line of each data set contains a positive integer no_of_intersections (greater than 0 and less or equal to 120), which is the number of intersections in the town. The second line contains a positive integer no_of_streets, which is the number of streets in the town. The next no_of_streets lines, one for each street in the town, are randomly ordered and represent the town's streets. The line corresponding to street k (k <= no_of_streets) consists of two positive integers, separated by one blank: Sk (1 <= Sk <= no_of_intersections) - the number of the intersection that is the start of the street, and Ek (1 <= Ek <= no_of_intersections) - the number of the intersection that is the end of the street. Intersections are represented by integers from 1 to no_of_intersections.
 
 There are no blank lines between consecutive sets of data. Input data are correct.
 
 
 Output
 The result of the program is on standard output. For each input data set the program prints on a single line, starting from the beginning of the line, one integer: the minimum number of paratroopers required to visit all the intersections in the town.
 
 
 Sample Input
 2
 4
 3
 3 4
 1 3
 2 3
 3
 3
 1 3
 1 2
 2 3
 
 
 Sample Output
 2
 1
*/