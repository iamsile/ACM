#include <iostream>
using namespace std;
int cal(int a,int b)
{
    int max=a>b?a:b;
    int min=a>b?b:a;
    int t;
    while (min) {
        t=max;
        max=min;
        min=t%max;
    }
    return max;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int i,k,m,a[1001];
        for (i=0; i<n; i++)
            cin >> a[i];
        for (i=1,k=a[0]; i<n; i++) {
            m=cal(k,a[i]);
            k=m;
        }
        cout << k << '\n';
    }
    return 0;
}
/*
 Problem Description
 梦幻城市每年为全市高中生兴办一次运动大会。为促进各校同学之间的交流，采用特别的分队方式：每一个学校的同学，必须被均匀分散到各队，使得每一队中该校的人数皆相同。为增加比赛的竞争性，希望分成越多队越好。你的任务是由各校的人数，决定最多可分成的队数。
 Input
 第一行为一个正整数N，代表学校的个数。接下来有N行，每行为一个正整数，分别代表这N个学校的人数。
 数据约定：学校数不超过500，每个学校人数最多为10000。
 Output
 最多可分成的队数。
 Sample Input
 输入范例1：
 3 12 16 20
 输入范例2：
 4 400 200 150 625
 Sample Output
 输出范例1：4
 输出范例2：25
*/