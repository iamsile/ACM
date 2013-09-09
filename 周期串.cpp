#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[1001];
    while (scanf("%s",a)!=EOF) {
        int i,j,flag,k=(int)strlen(a);
        for (i=1; i<=k; i++) {
            flag=1;
            if (k%i==0) {
                for (j=i; j<k; j++)
                    if (a[j]!=a[j%i]) {
                        flag=0;
                        break;
                    }
                if (flag==1) {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
/*
 #include<iostream>
 using namespace std;
 char str[100];
 int main()
 {
 cin>>str;
 for(int i=1;i<=strlen(str);i++)
 {
 int flag=1;
 if(strlen(str)%i==0)//求周期
 {
 for(int j=i;j<strlen(str);j++)//在周期内的字符都不一样，所以从比周期大的字符开始
 {
 if(str[j]!=str[j%i])//如果当前字符和去掉周期的字符不相同，那么这个周期则不是一个周期
 {
 flag=0;
 break;
 }
 }
 if(flag==1)
 {
 cout<<i<<endl;
 }
 }
 }
 }
*/
/*
 Problem Description
 如果一个字符串是以一个或者一个以上的长度为k的重复字符串所连接成的，那么这个字符串就被称为周期为k的字符串。
 例如:
 字符串’abcabcabcabc’周期为3，因为它是由4个循环’abc’组成的。它同样是以6为周期（两个重复的’abcabc’）和以12为周期（一个循环’abcabcabcabc’）。
 问题:
 写一个程序，读入一个字符串，并测定它的最小周期。
 Input
 一个最长为100的没有空格的字符串。
 Output
 一个整数表示输入的字符串的最小周期。
 Sample Input
 HoHoHo
 Sample Output
 2
*/