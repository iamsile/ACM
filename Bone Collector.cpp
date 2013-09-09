#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,n,b,av[1001],ab[1001],r[1001];
        cin >> n >> b;
        memset(r, 0, sizeof(r));
        for (i=0; i<n; i++)
            cin >> av[i];
        for (i=0; i<n; i++)
            cin >> ab[i];
        for (i=0; i<n; i++)
            for (j=b; j>=ab[i]; j--)
                if (r[j-ab[i]]+av[i]>r[j])
                    r[j]=r[j-ab[i]]+av[i];
        cout << r[b] << '\n';
    }
}
/*
 Problem Description
 Many years ago , in Teddy’s hometown there was a man who was called “Bone Collector”. This man like to collect varies of bones , such as dog’s , cow’s , also he went to the grave …
 The bone collector had a big bag with a volume of V ,and along his trip of collecting there are a lot of bones , obviously , different bone has different value and different volume, now given the each bone’s value along his trip , can you calculate out the maximum of the total value the bone collector can get ?
 
 
 
 
 Input
 The first line contain a integer T , the number of cases.
 Followed by T cases , each case three lines , the first line contain two integer N , V, (N <= 1000 , V <= 1000 )representing the number of bones and the volume of his bag. And the second line contain N integers representing the value of each bone. The third line contain N integers representing the volume of each bone.
 
 
 Output
 One integer per line representing the maximum of the total value (this number will be less than 231).
 
 
 Sample Input
 1
 5 10
 1 2 3 4 5
 5 4 3 2 1
 
 
 Sample Output
 14
*/