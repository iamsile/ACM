#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[1001],b[1001];
    while (cin >>a&&a[0]!='#') {
        cin >> b;
        char *p=a;
        int n,k=strlen(b);
        for (n=0; p=strstr(p, b); p+=k)
            n++;
        cout << n << '\n';
    }
    return 0;
}
/*
 直接调用库函数strstr()。
 strstr
 语法:
 #include <string.h>
 char *strstr( const char *str1, const char *str2 );
 功能：函数返回一个指针，它指向字符串str2 首次出现于字符串str1中的位置，如果没有找到，返回NULL。
 
 Problem Description
 一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
 
 
 Input
 输入中含有一些数据，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。如果遇见#字符，则不再进行工作。
 
 
 Output
 输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就老老实实输出0，每个结果之间应换行。
 
 
 Sample Input
 abcde a3
 aaaaaa  aa
 #
 
 
 Sample Output
 0
 3
*/