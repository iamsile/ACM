#include <iostream>
#include <algorithm>
using namespace std;
int a[5000000],b[4000];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int i,j,k=0;
        for (i=0; i<n; i++)
            cin >> b[i];
        for (i=0; i<n; i++)
            for (j=i+1; j<n; j++)
                a[k++]=b[i]+b[j];
        sort(a, a+k);
        for (i=k-1; i>=k-m; i--) {
            if (i<k-1)
                cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 还记得Gardon给小希布置的那个作业么？（上次比赛的1005）其实小希已经找回了原来的那张数表，现在她想确认一下她的答案是否正确，但是整个的答案是很庞大的表，小希只想让你把答案中最大的M个数告诉她就可以了。 
 给定一个包含N(N<=3000)个正整数的序列，每个数不超过5000，对它们两两相加得到的N*(N-1)/2个和，求出其中前M大的数(M<=1000)并按从大到小的顺序排列。
 
 
 Input
 输入可能包含多组数据，其中每组数据包括两行： 
 第一行两个数N和M， 
 第二行N个数，表示该序列。
 
 
 
 Output
 对于输入的每组数据，输出M个数，表示结果。输出应当按照从大到小的顺序排列。
 
 
 Sample Input
 4 4
 1 2 3 4
 4 5
 5 3 6 4
 
 
 Sample Output
 7 6 5 5
 11 10 9 9 8
*/