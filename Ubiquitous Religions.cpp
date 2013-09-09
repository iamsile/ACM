#include <iostream>
using namespace std;
#define max 50000
int cnt,f[max],r[max];

void init()
{
    for (int i=0; i<max; i++) {
        f[i]=i;
        r[i]=0;
    }
}

int find(int a)
{
    if (f[a]!=a)
        f[a]=find(f[a]);
    return f[a];
}

void Union(int a,int b)
{
    int k1=find(a),k2=find(b);
    if (k1==k2)
        return;
    cnt--;
    if (r[k1]>r[k2])
        f[k2]=k1;
    else {
        f[k1]=k2;
        if (r[k1]==r[k2])
            r[k2]++;
    }
}

int main()
{
    int n,m,lab=1;
    while (cin >> n >> m) {
        if (!n&&!m)
            break;
        init();
        int i,x,y;
        cnt=n;
        for (i=0; i<m; i++) {
            cin >> x >> y;
            Union(x,y);
        }
        cout << "Case " << lab++ << ": " << cnt << '\n';
    }
    return 0;
}
/*
 Description
 
 There are so many different religions in the world today that it is difficult to keep track of them all. You are interested in finding out how many different religions students in your university believe in. 
 
 You know that there are n students in your university (0 < n <= 50000). It is infeasible for you to ask every student their religious beliefs. Furthermore, many students are not comfortable expressing their beliefs. One way to avoid these problems is to ask m (0 <= m <= n(n-1)/2) pairs of students and ask them whether they believe in the same religion (e.g. they may know if they both attend the same church). From this data, you may not know what each person believes in, but you can get an idea of the upper bound of how many different religions can be possibly represented on campus. You may assume that each student subscribes to at most one religion.
 Input
 
 The input consists of a number of cases. Each case starts with a line specifying the integers n and m. The next m lines each consists of two integers i and j, specifying that students i and j believe in the same religion. The students are numbered 1 to n. The end of input is specified by a line in which n = m = 0.
 Output
 
 For each test case, print on a single line the case number (starting with 1) followed by the maximum number of different religions that the students in the university believe in.
 Sample Input
 
 10 9
 1 2
 1 3
 1 4
 1 5
 1 6
 1 7
 1 8
 1 9
 1 10
 10 4
 2 3
 4 5
 4 8
 5 8
 0 0
 Sample Output
 
 Case 1: 1
 Case 2: 7
*/