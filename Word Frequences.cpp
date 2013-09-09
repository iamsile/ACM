#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
char a[10000][50],s;
int i,n,k;
int cmp(const void *p1,const void *p2) 
{
    return strcmpi((char *)p1,(char *)p2);
}

int main()
{
    while((s=getchar())!=EOF)
        if(isalpha(s))
            a[i][k++]=s;
        else if(k)
        {
            i++;
            k=0;
        }
    n=i,k=0;
    qsort(a,n,50,cmp);
    while(i--)
        k=strcmpi(a[i],a[i-1])?k:k+1;
    cout << "different words:" << n-k << '\n';
    cout << "total words:" << n << '\n';
    return 0;
}
/*
 Problem description
 One tool in establishing autorship of text in cases when the text is not signed, or it is attributed to some else, is using word frequences. Regardless of how reliable this method is for literary studies, or interest lies in writing a program that scans a text file and computers the frequence of the occurence. For the sake of simplication, punctuation marks are disregarded and case sensitivity is disabled. Therefore, the word man's is counted as two words man and s. And Man is considered equal to man according to the above rule. 
 
 Input
 The input words will never more than 10000, and the length of one word will not exceed 50 characters. 
 
 Output
 You should output the number of different words by the input, and the number of words total in input. 
 
 Sample Input
 The weather was fine and the journey took only a few minutes.
 Sample Output
 different words:11
 total words:12
*/