#include <iostream>
using namespace std;
int a[101][101];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        long long i,j,sum=0;
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                cin >> a[i][j];
        for (i=0; i<n; i++)
            for (j=0; j<i; j++)
                sum+=min(a[i][j], a[j][i]);
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 KM city has N sightseeing areas. Currently every pair of area is connected by a bidirectional road.
 However for some reason, Mr. KM, the mayor of this city, decided to make all of these roads one-way . It costs Ci,j dollars to renovate the road between area i and area j to a one-way road from area i to area j. Of course, Mr. KM is economic and wants to minimize the total cost of the renovation.
 On the other hand, because tourism is the most important industry for KM city, there must exists a tour that goes through all the sightseeing areas, visiting each area exactly once. The first and last area of the path need not to be the same. Can you calculate the minimum total cost required for the renovation, given this situation? 
 
 
 Input
 The first line contains the number of sightseeing area N (1 ≤ N ≤ 100). Next N lines describe the integer matrix C, where the j-th element of the i-th row of the input describes Ci,j (0 ≤ Ci,j ≤ 1; 000; 000). For each i, you can assume Ci,i is always zero. 
 
 
 Output
 Output the minimum cost in a line.
 
 
 Sample Input
 3
 0 2 7
 2 0 4
 5 8 0
 Sample Output
 11
*/