#include <iostream>
using namespace::std;
unsigned a[1000000];

int main()
{
    long long  i,j,n,lab;
    for(i=1;i<=1000000;i++)
		a[i]=1;
	for(i=2;i<=1000000;i++)
		if(a[i])
			for(j=i;i*j<=1000000;j++)
				a[j*i]=0;
    while (cin >> n)
    {
        if (n==-1)
            return 0;
        if (a[n]&&n%10==3)
            cout << n << " YES\n";
        else if (a[n]&&n%10!=3)
            cout << n << " NO\n";
        else if (n%2==0)
            cout << n << " NO\n";
        else 
        {
            lab=n;
            for(i=2;i<=n;i++)
                if(n%i==0&&i%10==3&&a[i])
                {
                    n/=i;
                    i=1;
                }
            if (n==1)
                cout << lab << " YES\n";
            else 
                cout << lab << " NO\n";
        }
    }
    return 0;
}
/*
 Problem description
 Consider the series of numbers whose all prime factors have 3 as their least (right-most) digit. For example, the first 10 numbers in this series are:
 
 3 9 13 23 27 39 43 53 69 73
 
 
 The numbers 3, 13, 23, 43, 53, and 73 are in this series since they're all primes whose least digit is a 3. Whereas 9(3 * 3), 27(3 * 3 * 3), 39(3 * 13) , and 69(23 * 3) are in since all their prime factors have a 3 as their least digit. Write a program that takes a list of positive integers and determines if each integer is in this series or not. 
 
 
 Input
 The input file contains a list of one or more positive integers, each given on a separate line. Each integer is less than a million. The last line of the file contains a `-1' (which is not part of the list.)
 
 Output
 For each number in the input, write, on a separate line, the number itself followed by the word ``YES" if the number is in the series described above, or ``NO" if it isn't. Separate the number from the answer by a single space. 
 
 Sample Input
 3 
 13 
 33 
 -1
 Sample Output
 3 YES 
 13 YES 
 33 NO
*/