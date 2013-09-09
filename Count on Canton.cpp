#include <iostream>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int k=0,raw=n;
        while (n>k)
        {
            n-=k;
            k++;
        }
        if (k%2==0)
            printf("TERM %d IS %d/%d\n",raw,n,k-n+1);
        else
            printf("TERM %d IS %d/%d\n",raw,k-n+1,n);
    }
    return 0;
}
/*
 以斜列来看，列从下往上，分子分母依次递减和递增
 但奇数列是从下往上数，而偶数列则相反
 */
/*
 Problem description
 One of the famous proofs of modern mathematics is Georg Cantor's demonstration that the set of rational numbers is enumerable. The proof works by using an explicit enumeration of rational numbers as shown in the diagram below. 
 1/1 1/2 1/3 1/4 1/5 ...
 
 2/1 2/2 2/3 2/4
 
 3/1 3/2 3/3
 
 4/1 4/2
 
 5/1
 
 
 In the above diagram, the first term is 1/1, the second term is 1/2, the third term is 2/1, the fourth term is 3/1, the fifth term is 2/2, and so on.
 
 
 Input
 The input list contains a single number per line and will be terminated by endof-file.
 Output
 
 You are to write a program that will read a list of numbers in the range from 1 to 10^7 and will print for each number the corresponding term in Cantor's enumeration as given below.
 
 
 Output
 You are to write a program that will read a list of numbers in the range from 1 to 10^7 and will print for each number the corresponding term in Cantor's enumeration as given below.
 
 Sample Input
 3
 14
 7
 Sample Output
 TERM 3 IS 2/1
 TERM 14 IS 2/4
 TERM 7 IS 1/4
*/