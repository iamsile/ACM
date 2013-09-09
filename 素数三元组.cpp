#include <iostream>
using namespace std;

int main()
{
    long long n;
    while (cin >> n) {
        if (n>=7)
            printf("3 5 7\n");
        else printf("No triple\n");
    }
    return 0;
}
/*
 描述
 相邻三个奇数都是素数是一种非常少见的情形，也就是三个奇数p-2, p, p+2都是素数，这样就形成了一个素数三元组。请找出三个数都不超过n的所有这样的素数三元组。
 输入
 输入只有一个正整数n，n <= 10000000000。
 输出
 输出大小不超过n的所有的素数三元组，每行按照从小到大的顺序输出一个三元组中的三个数，两个数之间用空格间隔。如果不存在这样的素数三元组，请输出"No triple"。
 样例输入
 1
 样例输出
 No triple
*/