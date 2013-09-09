#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[100];
    while (gets(s)) {
        int i,x,y,j,a=0,b=0,c=0,k=strlen(s);
        char s1[100]={0};
        char s2[100]={0};
        for (i=0; i<k; i++)
            if (s[i]=='"') {
                x=i;
                break;
            }
        for (i=k-1; i>=0; i--)
            if (s[i]=='"') {
                y=i;
                break;
            }
        for (i=x+1,j=0; i<y; i++)
                s1[j++]=s[i];
        s1[j]='\0';
        for (i=y+1,j=0; i<k; i++)
            if (s[i]==' ')
                continue;
            else 
                s2[j++]=s[i];
        s2[j]='\0';
        sscanf(s2, ",%d,%d,%d);",&a,&b,&c);
        printf(s1,a,b,c);
        printf("\n");
    }
    return 0;
}
/*
 Description
 学习C语言的时候，printf五花八门的输出方式一定让大家纠结过。但后来做题的时候，如此丰富的使用方法却也给了我们很多惊喜。
 在这里一起复习一下吧。
 Input
 每行一个合法的printf语句，格式为printf("输出方法的内容", a, b, c);
a,b,c为三个int型十进制整数。数据保证引号内没有转义字符，且可以合法使用a,b,c三个参数。
每行输入不超过80个字符。
Output
每组数据对应一行输出这个printf语句应该输出的内容。
Sample Input
printf("%*d%d", 1, 5, 3);
printf(  "%x%.2d%d", 11, 3, 2) ;
Sample Output
53
b032
*/