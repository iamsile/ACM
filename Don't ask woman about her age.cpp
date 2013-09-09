#include <iostream>
using namespace::std;
char a[1000001];

int main()
{
    scanf("%s",a);
    unsigned long i,len,lab,sum=0,max=0,flag=0;
    len=strlen(a);
    for (i=0; i<len; i++) 
    {
        if (a[i]>='0'&&a[i]<='9')
            lab=a[i]-48;
        else 
            lab=a[i]-55;
        sum+=lab;
        if (lab>max)
            max=lab;
    }
    if (max==0)
    {
        cout << "2\n";
        return 0;
    }
    for (i=max+1; i<=36; i++)
        if (sum%(i-1)==0) 
        {
            flag=1;
            break;
        }
    if (flag==0)
        cout << "No solution.\n";
    else 
        cout << i << '\n';
    return 0;
}
/*
 Problem description
 Mrs Little likes digits most of all. Every year she tries to make the best number of the year. She tryes to become more and more intelligent and every year studies a new digit. And the number she makes is written in numeric system which base equals to her age. To make her life more beautiful she writes only numbers that are divisible by her age minus one. Mrs Little wants to hold her age in secret.
 
 You are given a number consisting of digits 0, …, 9 and latin letters A, …, Z, where A equals 10, B equals 11 etc. Your task is to find the minimal number k satisfying the following condition: the given number, written in k-based system is divisible by k−1. 
 
 Input
 Input consists of one string containing no more than 106 digits or uppercase latin letters. 
 
 Output
 Output file should contain the only number k, or "No solution." if for all 2 ≤ k ≤ 36 condition written above can't be satisfyed. By the way, you should write your answer in decimal system. 
 
 Sample Input
 A1A
 Sample Output
 22
*/