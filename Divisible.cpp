#include <iostream>
#include <string.h>
using namespace std;
char a[500010];
int main()
{
    int n;
    while (scanf("%d %s",&n,a)!=EOF) {
        long long i,j,k=strlen(a),sum=0;
        for (i=0; i<k; i++) {
            if (a[i]>='A'&&a[i]<='Z')
                j=a[i]-'A'+10;
            else if (a[i]>='a'&&a[i]<='z')
                j=a[i]-'a'+37;
            else j=a[i]-'0';
            sum+=j;
        }
        if (sum%(n-1))
            puts("No");
        else puts("Yes");
    }
    return 0;
}
/*
 Problem description
 Give a number n base b,you are asked to judge the number n base b whether it can be divided by b-1.The number n consisting of digits 0, …, 9 and latin letters A, …, Z, a, ... ,z,where A equals 10, B equals 11,..,z equals 61.
 
 
 Input
 there are several test cases,each case contains two elements.
 first element is the base b(2 < b < 62 ),following is the number n(its length is less than 500000).
 
 
 Output
 if the interger n base b can be divided by b - 1, output "Yes".
 else output "No".
 
 
 Sample Input
 3 2
 Sample Output
 Yes
*/