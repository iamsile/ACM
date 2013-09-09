#include <iostream>
#include <string.h>
#include <fstream>
using namespace::std;
int main()
{
    char a[100010],b[500][500];
    int flag=1;
    while (gets(a)) 
    {
		memset(b, 0, sizeof(b));
        unsigned long i,j,k,lab,count=1,len=strlen(a);
        for (k=0; k<len;) 
        {
            if (count%2==0) 
            {
                for (i=1,j=count; j>=1&&k<len; i++,j--)
                    b[i][j]=a[k++];
                count++;
            }
            else 
            {
                for (i=count,j=1; i>=1&&k<len; i--,j++)
                    b[i][j]=a[k++];
                count++;
            }
        }
        cout << "Matrix " << flag++ << ":\n";
        k=0;
        for (i=1; i<=count; i++) 
        {
            lab=1;
            for (j=1; j<=count&&b[i][j]!='\0'; j++)
            {
                if (j>1)
                    cout << ' ';
                cout << b[i][j];
                if (k>=len)
                    break;
                k++;
                lab=0;
            }
            if (lab==0)
                cout << '\n';
        }
    }
    return 0;
}
/*
#include <string.h>
#include <fstream>
using namespace::std;
int main()
{
    char a[100010],b[500][500];
    int flag=1;
    while (gets(a)) 
    {
		for(int i=0;i<500;i++)
			for(int j=0;j<500;j++)
				b[i][j]=0;
        unsigned long i,j,k,lab,count=1,len=strlen(a);
        for (k=0; k<len;) 
        {
            if (count%2==0) 
            {
                for (i=1,j=count; j>=1&&k<len; i++,j--)
                    b[i][j]=a[k++];
                count++;
            }
            else 
            {
                for (i=count,j=1; i>=1&&k<len; i--,j++)
                    b[i][j]=a[k++];
                count++;
            }
        }
        cout << "Matrix " << flag++ << ":\n";
        k=0;
        for (i=1; i<=count; i++) 
        {
            lab=1;
            for (j=1; j<=count&&b[i][j]!='\0'; j++)
            {
                if (j>1)
                    cout << ' ';
                cout << b[i][j];
                if (k>=len)
                    break;
                k++;
                lab=0;
            }
            if (lab==0)
                cout << '\n';
        }
    }
    return 0;
}
*/
/*
 Problem description
 This is a very simple problem. Given an array A[1: n*n](n*n<=100000),your task is to put the n*n elements into a two-dimension array B(1: n, 1: n) with snap shape.
 That is：
 B(1, 1)=A(1),
 B(1, 2)=A(2), B(2, 1)=A(3),
 B(3, 1)=A(4), B(2, 2)=A(5), B(1, 3)=A(6),
 ……
 The rest may be deduced by analogy.
 The array B can be showed as following:
 A[1]    A[2]    A[6]    A[7]     ---
 A[3]    A[5]    A[8]    A[14]    ---
 A[4]    A[9]    A[13]    ---      ---
 A[10]   A[12]    ---      ---     ---
 A[11]    ---      ---      ---     ---
 
 
 Input
 The input consists of several test cases.Each case contains a line with m(m <= 100000) characters,indicating the array A.
 
 Output
 For each test case, output the array B using the exact output format shown below.On each line, two nearby elements should be seperated by a single space. 
 
 Sample Input
 *
 kkd kagak gakg k     j
 Sample Output
 Matrix 1:
 *
 Matrix 2:
 k k a g   k
 d k a g  
 k k  
 a  
 g  
 
 j
*/