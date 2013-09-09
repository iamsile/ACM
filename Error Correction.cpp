#include <iostream>
using namespace::std;

int main()
{
    int n, i, j;
    short a[100][100];
    int row[100],col[100],r,r_i,c,c_i;
    while (cin >> n&&n)
	{
        for(i=1;i<=n;i++)
            col[i]=0;
        for(i=1;i<=n;i++)
		{
            row[i]=0;
            for(j=1;j<=n;j++)
			{
                cin >> a[i][j];
                row[i]+=a[i][j];
                col[j]+=a[i][j];
            }
        }
        r=0;
        for(i=1;i<=n;i++)
            if(row[i]&1)
			{
                r_i=i;
                r++;
            }
        c=0;
        for(i=1;i<=n;i++)
            if(col[i]&1)
			{
                c_i=i;
                c++;
            }
        if(r==0&&c==0)
            cout << "OK\n";
        else if(r==1&&c==1)
            printf("Change bit (%d,%d)\n", r_i, c_i);
        else
            cout << "Corrupt\n";
    }
    return 0;
}
//解题思路：先计算出每一行、每一列的和，如果全为偶数就OK；
//如果仅有一行和一列两个和是奇数，则Change bit 这一行和这一列的交点；
//其余情况，例如有两行（以上）的和为奇数，或者两列（以上）的和为奇数，就Corrupt。
/*
 Problem description
 A boolean matrix has the parity property when each row and each column has an even sum, i.e. contains an even number of bits which are set. Here's a 4 x 4 matrix which has the parity property:
 1 0 1 0
 
 0 0 0 0
 
 1 1 1 1
 
 0 1 0 1
 
 The sums of the rows are 2, 0, 4 and 2. The sums of the columns are 2, 2, 2 and 2. 
 Your job is to write a program that reads in a matrix and checks if it has the parity property. If not, your program should check if the parity property can be established by changing only one bit. If this is not possible either, the matrix should be classified as corrupt. 
 
 Input
 The input will contain one or more test cases. The first line of each test case contains one integer n (n<100), representing the size of the matrix. On the next n lines, there will be n integers per line. No other integers than 0 and 1 will occur in the matrix. Input will be terminated by a value of 0 for n. 
 
 Output
 For each matrix in the input file, print one line. If the matrix already has the parity property, print "OK". If the parity property can be established by changing one bit, print "Change bit (i,j)" where i is the row and j the column of the bit to be changed. Otherwise, print "Corrupt". 
 
 Sample Input
 4
 1 0 1 0
 0 0 0 0
 1 1 1 1
 0 1 0 1
 4
 1 0 1 0
 0 0 1 0
 1 1 1 1
 0 1 0 1
 4
 1 0 1 0
 0 1 1 0
 1 1 1 1
 0 1 0 1
 0
 Sample Output
 OK
 Change bit (2,3)
 Corrupt
 
*/