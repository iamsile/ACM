#include <iostream>
#include <iomanip.h>
using namespace std;

int main()
{
    bool a[1000000];
    int i,j;
    char b[10];
    memset(a, 1, sizeof(a));
    a[0]=false;
    a[1]=false;
    for (i=2; i<=1000; i++)
        if (a[i])
            for (j=2; i*j<=1000000; j++)
                a[j*i]=false;
    while (scanf("%s",b)&&b[0]!='0') {
        int k,sum=0,flag=0,lab=atoi(b);
        if (a[lab])
            printf("%7s%8d\n",b,lab);
        else 
        {
            for (i=0; i<strlen(b); i++)
                sum+=b[i]-'0';
            while (sum) {
                if (a[sum]) {
                    flag=1;
                    break;
                }
                if (sum>9) {
                    k=sum/10;
                    sum=sum%10+k;
                }
                else sum/=10;
            }
            if (flag)
                printf("%7s%8d\n",b,sum);
            else
                printf("%7s    none\n",b);
        }
    }
    return 0;
}
/*
 Problem description
 The digital root of a number is found by adding together the digits that make up the number. If the resulting number has more than one digit, the process is repeated until a single digit remains.
 
 Your task in this problem is to calculate a variation on the digital root - a prime digital root. The addition process described above stops when there is only one digit left, but will also stop if the original number, or any of the intermediate numbers (formed by addition) are prime numbers. If the process continues and results in a single digit that is not a prime number, then the original number has no prime digital root.
 
 EXAMPLES OF PRIME DIGITAL ROOTS
 
 1 This is not a prime number, so 1 has no prime digital root.
 3 This is a prime number, so the prime digital root of 3 is 3.
 4 This not a prime number, so 4 has no prime digital root.
 11 This is a prime number, so the prime digital root of 11 is 11.
 642 This is not a prime number, so adding its digits gives 6 + 4 + 2 = 12. This is not a prime number, so adding again gives 1 + 2 = 3. This is a prime number, so the prime digital root of 642 is 3.
 128 This is not a prime number, so adding its digits gives 1 + 2 + 8 = 11. This is a prime number, so the prime digital root of 128 is 11.
 886 This is not a prime number, so adding its digits gives 8 + 8 + 6 = 22. This is not a prime number, so adding again gives 2 + 2 = 4. This is not a prime number, so 886 has no prime digital root.
 
 
 Input
 The input will contain a single integer on each line in the range 0 to 999999 inclusive. The end of the input will be indicated by the value 0. 
 
 Output
 If the input number has a prime digital root, then the input number must be output right aligned with a field width of 7. It must be followed by a single space, and then by the calculated prime digital root also right aligned with a field width of 7.
 
 If the input number has no prime digital root, then the input number should be output as defined above followed by 4 spaces followed by the word none (in lowercase). The terminating zero should not be output. 
 
 Sample Input
 1
 3
 4
 11
 642
 128
 886
 0
 Sample Output
 1    none
 3       3
 4    none
 11      11
 642       3
 128      11
 886    none
*/