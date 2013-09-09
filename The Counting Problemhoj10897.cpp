#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> cal(int k)
{
    int i,j,t=1,temp,lab;
    vector<int> c(10,0);
    while (k>=t) {
        lab=k/(t*10);
        for (i=0; i<10; i++)
            c[i]+=lab*t;
        if (lab)
            c[0]-=t;
        temp=(k/t)%10;
        if (k>=t*10)
            j=0;
        else j=1;
        for (i=j; i<temp; i++)
            c[i]+=t;
        c[temp]+=k%t+1;
        t*=10;
    }
    return c;
}

int main()
{
    int i,n,m;
    while (cin >> n >> m) {
        if (!n&&!m)
            break;
        if (n>m)
        {
            int tmp=n;
            n=m;
            m=tmp;
        }
        vector<int> a,b;
        a=cal(n-1);
        b=cal(m);
        for (i=0; i<10; i++)
            b[i]-=a[i];
        for (i=0; i<10; i++) {
            if (i)
                cout << ' ';
            cout << b[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem description
 Given two integers a and b, we write the numbers between a and b, inclusive, in a list. Your task is to calculate the number of occurrences of each digit. For example, if a = 1024 and b = 1032, the list will be 
 
 
 1024 1025 1026 1027 1028 1029 1030 1031 1032 
 
 there are ten 0's in the list, ten 1's, seven 2's, three 3's, and etc.
 
 
 Input
 The input consists of up to 500 lines. Each line contains two numbers a and b where 0 < a, b < 100000000. The input is terminated by a line `0 0', which is not considered as part of the input. 
 
 Output
 For each pair of input, output a line containing ten numbers separated by single spaces. The first number is the number of occurrences of the digit 0, the second is the number of occurrences of the digit 1, etc. 
 
 Sample Input
 1 10
 44 497
 346 542
 1199 1748
 1496 1403
 1004 503
 1714 190
 1317 854
 1976 494
 1001 1960
 0 0
 
 Sample Output
 1 2 1 1 1 1 1 1 1 1
 85 185 185 185 190 96 96 96 95 93
 40 40 40 93 136 82 40 40 40 40
 115 666 215 215 214 205 205 154 105 106
 16 113 19 20 114 20 20 19 19 16
 107 105 100 101 101 197 200 200 200 200
 413 1133 503 503 503 502 502 417 402 412
 196 512 186 104 87 93 97 97 142 196
 398 1375 398 398 405 499 499 495 488 471
 294 1256 296 296 296 296 287 286 286 247
*/