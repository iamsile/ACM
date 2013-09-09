#include <iostream>
#include <stdio.h>
using namespace std;

__int64 f[30];

__int64 cal(char a[],int s)
{
    __int64 i,j,k=strlen(a),v[30]={0},flag=a[s]-'A';
    for (i=s; i<k; i++)
        v[a[i]-'A']++;
    __int64 cnt=0,n,lab=f[k-s-1];
    for (i=0; i<26; i++)
        if (v[i]&&i<flag) {
            n=1;
            for (j=0; j<26; j++)
                if (v[j])
                    n*=f[v[j]-(i==j?1:0)];
            cnt+=(__int64)((lab+0.5)/n);
        }
    return cnt;
}

int main()
{
    __int64 t,i;
    f[0]=1;f[1]=1;
    for (i=2; i<=21; i++)
        f[i]=f[i-1]*i;
    scanf("%I64d\n",&t);
    while (t--) {
        char a[30]={0};
        gets(a);
        __int64 sum=0,k=strlen(a);
        for (i=0; i<k-1; i++)
            sum+=cal(a,i);
        printf("%I64d\n",sum);
    }
    return 0;
}
/*
 Problem description
 Mikey is playing with his favorite toy blocks, each depicting one letter of the alphabet. He is trying to make words using all his blocks, but as he does not know valid words from invalid ones, he goes by all possible orderings of the letters in alphabetical order and asks Albert, his genius brother, if the word he made is a valid one. Mikey can make one word (including asking a question and getting an answer) every sixty seconds, and he never makes the same word twice.
 Albert is delighted about Mikey's activity, but would rather not teach Mikey certain words. Help Albert by predicting when Mikey will start making a certain forbidden word, so he can set the alarm clock indicating Mikey's bedtime to just before this moment.
 
 Input
 On the first line of the input is a positive integer, the number of test cases. Then for each test case:
 A line containing the forbidden word to look for, consisting of at most 20 upper case characters. This word can be formed exactly using all of Mikey's blocks.
 
 
 Output
 For each test case:
 One line containing the number of minutes it will take until the forbidden word is reached, assuming Mikey has just started making the first possible word.
 
 
 Sample Input
 4
 ABC
 FSCK
 OMGWFTBBQ
 BANANA
 Sample Output
 0
 10
 112293
 34
*/