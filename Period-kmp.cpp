#include <iostream>
using namespace std;
const int len=1000002;
int next[len];

void compnext(char a[],int n)
{
    int i=0,j=-1;
    next[0]=-1;
    while (i<n) {
        if (a[i]==a[j]||j==-1) {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}

int main()
{
    int i,k,n,lab=1;
    while (cin >> n&&n) {
        char a[len]={0};
        cin >> a;
        compnext(a,n);
        printf("Test case #%d\n",lab++);
        for (i=2; i<=n; i++) {
            k=i-next[i];// 若当前长度为i， i能够整除 (i-next[i])==0 时
            if (i%k==0&&(int)(i/k)>1) // 那么重复的次数就是  i/(i-next[i])
                printf("%d %d\n",i,i/k);// 不能整除，就表示没有
        }
        printf("\n");
    }
    return 0;
}
/*
 Problem Description
 For each prefix of a given string S with N characters (each character has an ASCII code between 97 and 126, inclusive), we want to know whether the prefix is a periodic string. That is, for each i (2 <= i <= N) we want to know the largest K > 1 (if there is one) such that the prefix of S with length i can be written as AK , that is A concatenated K times, for some string A. Of course, we also want to know the period K.
 
 
 Input
 The input file consists of several test cases. Each test case consists of two lines. The first one contains N (2 <= N <= 1 000 000) – the size of the string S. The second line contains the string S. The input file ends with a line, having the number zero on it.
 
 
 Output
 For each test case, output “Test case #” and the consecutive test case number on a single line; then, for each prefix with length i that has a period K > 1, output the prefix size i and the period K separated by a single space; the prefix sizes must be in increasing order. Print a blank line after each test case.
 
 
 Sample Input
 3
 aaa
 12
 aabaabaabaab
 0
 
 
 Sample Output
 Test case #1
 2 2
 3 3
 
 Test case #2
 2 2
 6 2
 9 3
 12 4
*/