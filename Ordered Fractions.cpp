#include <iostream>
#include <math.h>
using namespace std;
int n;

void frac(int n1, int d1, int n2, int d2) {
    if (d1 + d2 > n) return;
    frac(n1, d1, n1 + n2, d1 + d2);
    printf("%d/%d\n", n1 + n2, d1 + d2);
    frac(n1 + n2, d1 + d2, n2, d2);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        printf("0/1\n");
        frac(0, 1, 1, 1);
        printf("1/1\n");
    }
    return 0;
}
/*
 Problem Description
 输入一个自然数N　
 请写一个程序来增序输出分母小于等于N的既约真分数
 Input
 首先是数据组数。
 对于每组数据：单独的一行　一个自然数N(1..160)
 Output
 对于每组数据：每个分数单独占一行
 Sample Input
 1
 5
 Sample Output
 0/1
 1/5
 1/4
 1/3
 2/5
 1/2
 3/5
 2/3
 3/4
 4/5
 1/1
*/