#include <iostream>
using namespace std;
char a[90],b[100][100];
int len;
bool judge(int x,int y)
{
    char c[90];
    int n=0,s1=x,s2=y;
    while (s1<=s2) {
        if (a[s1]!=a[s2])
            return false;
        s1++;
        s2--;
    }
    s1=x;
    s2=y;
    while (s1<=s2) {
        c[n++]=a[s1++];
    }
    c[n]='\0';
    for (n=0; n<len; n++)
        if (strcmp(c, b[n])==0)
            return false;
    strcpy(b[len], c);
    len++;
    return true;
}

int main()
{

    while (~scanf("%s",a)) {
        int i,j,k=strlen(a),sum=0;
        len=0;
        for (i=0; i<k; i++)
            for (j=i; j<k; j++)
                if (judge(i,j))
                    sum++;
        printf("The string '%s' contains %d palindromes.\n",a,sum);
    }
}
/*
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define pb push_back
#define file { freopen(“input.txt”,”r”,stdin);}

using namespace std;

char test[10000][81];

void reverse(char *from, char *to ){
    int len=strlen(from);
    int l;
    for(l=0;l<len;l++)
        to[l]=from[len-l-1];
    to[len]=”;
}

int main()
{
    
    char ch[81];
    char sec[81];
    
    test[0][0]=’\x0′;
    sec[0]=’\x0′;
    ch[0]=’\x0′;
    int ct=0,diff=0;
    //file
    while(scanf(“%s”,&ch)==1){
        long int i,j,len,k=0;
        len=strlen(ch);
        ch[len]=’\x0′;
        long int m=0;
        for(m=0;m<len;m++){
            for(i=m;i<len;i++){
                for(j=m;j<=i;j++){
                    test[k][ct]=ch[j];
                    ct++;
                }
                test[k][ct]=’\x0′;
                ct=0;
                k++;
            }
            
        }
        ct=0;
        diff=0;
        
        for(i=0;i<k;i++){
            for(j=i+1;j<k;j++){
                if(!strcmp(test[i],test[j])){
                    test[j][0]=’\x0′;
                }
            }
        }
        
        for(i=0;i<k;i++){
            if(test[i][0]!=’\x0′){
                reverse(test[i],sec);
                if(!strcmp(test[i],sec))
                    ct++;
            }
        } 
        printf(“The string ‘%s’ contains %ld palindromes.\n”,ch,ct);
        
        for(i=0;i<k;i++)
            test[i][0]=’\x0′;
        sec[0]=’\x0′;
        ct=0;
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
char str[100];
int len,palid[100];
int cklen,result;
char IsPalid(int p){
    char *i,*j;
    for(i=str+p,j=str+p+cklen-1;i<j;++i,--j)
        if(*i!=*j)
            return 0;
    return 1;
}
char IsSame(int si,int sj){
    int i,l=(cklen>>1)+1;
    for(i=0;i<l;++i)
        if(str[si+i]!=str[sj+i])
            return 0;
    return 1;
}
void GetNow(){
    int i,j,flag;
    cout << palid[0] << endl;
    for(i=1;i<=palid[0];++i){
        flag=1;
        for(j=i+1;j<=palid[0];++j)
            if(IsSame(palid[i],palid[j])){
                flag=0;
                break;
            }
        result+=flag;
    }
}
void Deal(){
    int i;
    len=strlen(str);
    for(cklen=1;cklen<=len;++cklen){
        palid[0]=0;
        for(i=0;i+cklen<=len;++i)
            if(IsPalid(i))
                palid[++palid[0]]=i;
        GetNow();
    }
}
int main(){
    while(EOF!=scanf("%s",str)){
        result=0;
        Deal();
        printf("The string '%s' contains %d palindromes.\n",str,result);
    }
    return 0;
}
*/
/*
 Problem description
 A palindrome is a sequence of one or more characters that reads the same from the left as it does from the right. For example, Z, TOT and MADAM are palindromes, but ADAM is not.
 Your job, should you choose to accept it, is to write a program that reads a sequence of strings and for each string determines the number of UNIQUE palindromes that are substrings. 
 
 
 Input
 The input file consists of a number of strings (one per line), of at most 80 characters each, starting in column 1. 
 
 
 
 Output
 For each non-empty input line, the output consists of one line containing the message:
 The string 'input string' contains nnnn palindromes.
 
 where input string is replaced by the actual input string and nnnn is replaced by the number of UNIQUE palindromes that are substrings.
 
 For input string ADAM, the UNIQUE palindromes are A, D, M and ADA so the correct output would be
 
 The string 'ADAM' contains 4 palindromes. 
 
 
 Sample Input
 boy 
 adam 
 madam 
 tot
 Sample Output
 The string 'boy' contains 3 palindromes. 
 The string 'adam' contains 4 palindromes.
 The string 'madam' contains 5 palindromes.
 The string 'tot' contains 3 palindromes.
*/