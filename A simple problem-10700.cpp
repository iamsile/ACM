#include <iostream>
using namespace std;

int main()
{
    int n,m,z;
    cin >> n >> z >> m;
    int i,k,a[1010]={0},front=1,sum=1;
    if (!m) {
        cout << "1\n";
        return 0;
    }
    for (i=1; i<=m; i++) {
        cin >> k;
        a[k]=1;
    }
    while (front!=z) {
        if (a[front]) {
            front=1;
            sum++;
        }
        else {
            front+=sum;
            if (front>n) {
                front-=n;
                if (front==1)
                    sum++;
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,z;
    while (~scanf("%d%d%d",&n,&z,&m)) {
        int i,k,a[1010]={0},front=1,sum=1;
        if (!m) {
            cout << "1\n";
            continue;
        }
        for (i=1; i<=m; i++) {
            cin >> k;
            a[k]=1;
        }
        while (front!=z) {
            if (a[front]) {
                front=1;
                sum++;
            }
            else {
                front+=sum;
                if (front>n) {
                    front-=n;
                    if (front==1)
                        sum++;
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
poj 2657 comfort
*/
/*
 Problem description
 A game-board consists of N fields placed around a circle. Fields are successively numbered from1 to N clockwise. In some fields there may be obstacles.
 
 Player starts on a field marked with number 1. His goal is to reach a given field marked with number Z. The only way of moving is a clockwise jump of length K. The only restriction is that the fields the player may jump to should not contain any obstacle. 
 
 For example, if N = 13, K = 3 and Z = 9, the player can jump across the fields 1, 4, 7, 10, 13, 3, 6 and 9, reaching his goal under condition that none of these fields is occupied by an obstacle. 
 
 Your task is to write a program that finds the smallest possible number K. 
 
 Input
 First line of the input consists of integers N, Z and M, 2 <= N <= 1000, 2 <= Z <= N, 0 <= M <= N - 2. N represents number of fields on the game-board and Z is a given goal-field.
 Next line consists of M different integers that represent marks of fields having an obstacle. It is confirmed that fields marked 1 and Z do not contain an obstacle. 
 
 Output
 Output a line contains the requested number K described above. 
 
 Sample Input
 9 7 2
 2 3
 Sample Output
 3
*/