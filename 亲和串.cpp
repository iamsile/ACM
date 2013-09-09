#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[100000],b[100000];
    while (scanf("%s%s",a,b)!=EOF) {
        int i,j,k=0,k1=strlen(a),k2=strlen(b);
        if (k2>k1)
            puts("no");
        else {
            while (k<k1) {
                i=k;
                j=0;
                while (a[i]==b[j]) {
                    i++;
                    j++;
                    if (i>=k1)
                        i=0;
                }
                if (j==k2) {
                    puts("yes");
                    break;
                }
                else k++;
            }
            if (k>=k1)
                puts("no");
        }
    }
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
char str[200001],str1[100001],str2[100001];
int main()
{
    while(~scanf("%s %s",str1,str2))
    {  
        strcpy(str,str1);
        strcat(str,str1);
        if(strstr(str, str2)==0)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
    return 0;
}
*/
/*
 Problem Description
 人随着岁数的增长是越大越聪明还是越大越笨，这是一个值得全世界科学家思考的问题,同样的问题Eddy也一直在思考，因为他在很小的时候就知道亲和串如何判断了，但是发现，现在长大了却不知道怎么去判断亲和串了，于是他只好又再一次来请教聪明且乐于助人的你来解决这个问题。
 亲和串的定义是这样的：给定两个字符串s1和s2,如果能通过s1循环移位，使s2包含在s1中，那么我们就说s2 是s1的亲和串。
 
 
 Input
 本题有多组测试数据，每组数据的第一行包含输入字符串s1,第二行包含输入字符串s2，s1与s2的长度均小于100000。
 
 
 Output
 如果s2是s1的亲和串，则输出"yes"，反之，输出"no"。每组测试的输出占一行。
 
 
 Sample Input
 AABCD
 CDAA
 ASD
 ASDF
 
 
 Sample Output
 yes
 no
*/