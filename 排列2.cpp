#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int a[4],flag=0;
    while (cin >> a[0] >> a[1] >> a[2]>> a[3]) {
        if (!a[0]&&!a[1]&&!a[2]&&!a[3])
            break;
        if (flag)
            cout << '\n';
        qsort(a, 4, sizeof(int), cmp);
        while (a[0]==0)
            next_permutation(a, a+4);
        int a0=a[0],a1=a[1],a2=a[2],a3=a[3],temp=a[0];
        while (1) {
            cout << a[0] << a[1] << a[2] << a[3];
            next_permutation(a, a+4);
            if (a[0]==a0&&a[1]==a1&&a[2]==a2&&a[3]==a3||a[0]==0)
                break;
            if (a[0]==temp)
                cout << ' ';
            else {
                temp=a[0];
                cout << '\n';
            }   
        }
        cout << '\n';
        flag=1;
    }
    return 0;
}
/*
 Problem Description
 Ray又对数字的列产生了兴趣：
 现有四张卡片，用这四张卡片能排列出很多不同的4位数，要求按从小到大的顺序输出这些4位数。
 
 
 Input
 每组数据占一行，代表四张卡片上的数字（0<=数字<=9），如果四张卡片都是0，则输入结束。
 
 
 Output
 对每组卡片按从小到大的顺序输出所有能由这四张卡片组成的4位数，千位数字相同的在同一行，同一行中每个四位数间用空格分隔。
 每组输出数据间空一行，最后一组数据后面没有空行。
 
 
 Sample Input
 1 2 3 4
 1 1 2 3
 0 1 2 3
 0 0 0 0
 
 
 Sample Output
 1234 1243 1324 1342 1423 1432
 2134 2143 2314 2341 2413 2431
 3124 3142 3214 3241 3412 3421
 4123 4132 4213 4231 4312 4321
 
 1123 1132 1213 1231 1312 1321
 2113 2131 2311
 3112 3121 3211
 
 1023 1032 1203 1230 1302 1320
 2013 2031 2103 2130 2301 2310
 3012 3021 3102 3120 3201 3210
 
 
 Source
 2007省赛集训队练习赛（2）
 
*/