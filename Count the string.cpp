#include<iostream>
using namespace std;
char P[200010];
int m;
int pre[200010];

void COMPUTE_PREFIX_FUNCTION(char *P)
{
    pre[1]=0;
    int q=0;
    for(int i=2; i<=m; i++)
    {
        while(q>0&&P[q+1]!=P[i])
            q=pre[q];
        
        if(P[q+1]==P[i])
            q++;        
        pre[i]=q;
    }
}

int main()
{
    int sum[200010];
    int tt,num;
    scanf("%d",&tt);
    getchar();
    for(int t=0; t<tt; t++) {
        
        scanf("%d",&m);
        getchar();
        for(int i=1; i<=m; i++)
            scanf("%c",P+i);
        getchar();
        COMPUTE_PREFIX_FUNCTION(P);                    
        for(int i=1; i<=m; i++) {
            sum[i]=1;
            sum[pre[i]]++;
        }
        num=0;
        for(int i=1; i<=m; i++)
        {
            num+=sum[i];
            num%=10007;
        }
        printf("%d\n",num);
    }
    return 0;
}
/*
 题意是求给定文本T的所有前缀分别出现的次数之和
 这题要用到KMP的求前缀函数的原理……
 让T作为模式P,用COMPUTE_PREFIX_FUNCTION求出P的前缀函数
 Pre[i] 表示P[1..i]的最长真前缀P[1..q] 的长度q (q<i)且这个前缀也是P[1..i]的后缀
 Problem Description
 It is well known that AekdyCoin is good at string problems as well as number theory problems. When given a string s, we can write down all the non-empty prefixes of this string. For example:
 s: "abab"
 The prefixes are: "a", "ab", "aba", "abab"
 For each prefix, we can count the times it matches in s. So we can see that prefix "a" matches twice, "ab" matches twice too, "aba" matches once, and "abab" matches once. Now you are asked to calculate the sum of the match times for all the prefixes. For "abab", it is 2 + 2 + 1 + 1 = 6.
 The answer may be very large, so output the answer mod 10007.
 
 
 Input
 The first line is a single integer T, indicating the number of test cases.
 For each case, the first line is an integer n (1 <= n <= 200000), which is the length of string s. A line follows giving the string s. The characters in the strings are all lower-case letters.
 
 
 Output
 For each case, output only one number: the sum of the match times for all the prefixes of s mod 10007.
 
 
 Sample Input
 1
 4
 abab
 
 
 Sample Output
 6
*/