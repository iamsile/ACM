#include <iostream>
#include <string.h>

int main()
{
    char a[1001];
    while (scanf("%s",a)!=EOF) {
        int i,j=strlen(a),sum=0,b[1001];
        if (a[0]=='0')
            return 0;
        for (i=0; i<j; i++)
            if (a[i]>='0'&&a[i]<='9')
                b[i]=a[i]-'0';
            else b[i]=a[i]-55;
        for (i=0; i<j/2; i++)
            sum+=b[i]-b[j-i-1];
        if (sum)
            printf("N\n");
        else printf("Y\n");
    }
    return 0;
}
/*
 Problem description
 If a hexadecimal integer (without leading 0),the sum of the former half number is equal to the sum of the latter half number,we call it a fair number. If the integer contains the odd numbers,then the middle of the integer neither fall within the first half,nor fall within the latter half.
 For example,hexadecimal number 1DE77 is a fair number,since 1 + D = 7 + 7,while the number of E is not involved in the calculation.
 All single-digit hexadecimal numbers (ie 0 ~ F) are fair numbers,but not F0 (F0 can not be written in 0F0).
 Input a hexadecimal integer to determine whether this number is a fair number.
 
 
 Input
 There will be multiple test cases.Each line of input contains a hexadecimal integer n (the number of bits is less than 1000).And the last line of 0 means the end of input which should not be processed.
 
 
 Output
 For each test case output a line,if the input hexadecimal number n is a fair number then output "Y",otherwise output "N".
 
 
 Sample Input
 F0
 1DE77
 0
 Sample Output
 N
 Y
*/