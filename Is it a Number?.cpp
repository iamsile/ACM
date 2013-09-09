#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--) {
        char a[200];
        gets(a);
        int i,j,flag=0,k=strlen(a);
        for(i=0;i<k&&isspace(a[i]);i++) ;
        for(j=k;isspace(a[j-1])&&j>i;)
            a[--j]=0;
        if(i==j)
            flag=1;
        for(k=i;k<j&&!flag;k++)
            if(!isdigit(a[k])) {
                flag=1;
                break;
            }
        while(i<j-1&&a[i]=='0'&&!flag)
            i++;
        if(flag)
            puts("invalid input");
        else
            puts(a+i);
    }
    return 0;
}
/*
 Problem description
 This is it! You've finally graduated and started working.Looking forward to some really cool tasks now. While you're skipping around in the eagerness of getting started, you're told what your first task is - Input Validation! You should check whether the typed input is an integer number.Time to get going! Given a sequence of characters, check whether they describe an integer number. Whitespace is allowed both before and after the number, but the rest of the input must consist of a single, non-negative integer number. Only digits will be accepted as the relevant part of the input (+ is not allowed, for instance).
 
 Input
 The first line of input contains a single number T, the number of test cases to follow. Then follow a single line for each test case; the input to be validated.
 
 Output
 For each test case, output a line containing the value of the number if the input is a valid integer number, or invalid input (all lowercase) if the input is not.
 
 Sample Input
 4
 23 456
 -36
 0045
 44.3
 Sample Output
 invalid input
 invalid input
 45
 invalid input
*/