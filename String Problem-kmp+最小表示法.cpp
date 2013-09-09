#include <iostream>
using namespace std;
char a[1000010];
int nex[1000010];

void nexts()
{
    int i=0,j=-1,k=strlen(a);
    nex[0]=-1;
    while (i<k) {
        if (j==-1||a[i]==a[j]) {
            i++;
            j++;
            if (a[i]==a[j])
                nex[i]=nex[j];
            else nex[i]=j;
        }
        else j=nex[j];
    }
}

int minstr(int flag)
{
    int i=0,j=1,k=0,t,len=strlen(a);
    while (i<len&&j<len&&k<len) {
        t=a[(i+k)%len]-a[(j+k)%len];
        if (!t)
            k++;
        else {
            if (flag) {
                if (t>0)
                    i+=k+1;
                else j+=k+1;
            }
            else {
                if (t>0)
                    j+=k+1;
                else i+=k+1;
            }
            if (i==j)
                j++;
            k=0;
        }
    }
    return min(i,j);
}

int main()
{
    
    while (~scanf("%s",a)) {
        int t,k=strlen(a);
        int mins=minstr(1)+1;
        int maxs=minstr(0)+1;
        nexts();
        int j=k-nex[k];
        if (k%j==0)
            t=k/j;
        else t=1;
        printf("%d %d %d %d\n",mins,t,maxs,t);
    }
    return 0;
}
/*
 Problem Description
 Give you a string with length N, you can generate N strings by left shifts. For example let consider the string “SKYLONG”, we can generate seven strings:
 String Rank
 SKYLONG 1
 KYLONGS 2
 YLONGSK 3
 LONGSKY 4
 ONGSKYL 5
 NGSKYLO 6
 GSKYLON 7
 and lexicographically first of them is GSKYLON, lexicographically last is YLONGSK, both of them appear only once.
 Your task is easy, calculate the lexicographically fisrt string’s Rank (if there are multiple answers, choose the smallest one), its times, lexicographically last string’s Rank (if there are multiple answers, choose the smallest one), and its times also.
 
 
 Input
 Each line contains one line the string S with length N (N <= 1000000) formed by lower case letters.
 
 
 Output
 Output four integers separated by one space, lexicographically fisrt string’s Rank (if there are multiple answers, choose the smallest one), the string’s times in the N generated strings, lexicographically last string’s Rank (if there are multiple answers, choose the smallest one), and its times also.
 
 
 Sample Input
 abcder
 aaaaaa
 ababab
 
 
 Sample Output
 1 1 6 1
 1 6 1 6
 1 3 2 3
*/