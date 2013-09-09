#include <iostream>
using namespace std;

int main()
{
    int n,m;
    while (cin >> n >> m) {
        int i,j,k,a[101][101],sum=0,num=0;
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                cin >> a[i][j];
        if (m==1||n==1) {
            cout << "0\n";
            continue;
        }
        for (i=0; i<n-1; i++)
            for (j=i+1; j<n; j++) {
                sum=0;
                for (k=0; k<m; k++)
                    if (a[i][k]&&a[j][k])
                        sum++;
                num+=sum*(sum-1)/2;
            }
        cout << num << '\n';
    }
    return 0;
}
/*
 Problem description
  In information theory, a low-density parity-check (LDPC) code is a linear error correcting code, a method of transmitting a message over a noisy transmission channel, and is constructed using a sparse bipartite graph. LDPC codes are capacity-approaching codes, which means that practical constructions exist that allow the noise threshold to be set very close (or even arbitrarily close on the BEC) to the theoretical maximum (the Shannon limit) for a symmetric memory-less channel.
  LDPC codes are defined by a sparse parity-check matrix. This parity-check matrix is often randomly generated and the elements in it are 0 or 1. If we want use LDPC codes, we should make the parity-check matrix have no cycles. When four vertices of the rectangle in the matrix are 1, we say that the matrix has one cycle. Now we want to know how many cycles are in the matrix.
  For a given matrix, you are to count the number of cycles in the matrix. 
 
 Input
  There are several test cases, each test case starts with a line containing two positive integers M and N. M and N is the size of the matrix (1 <= M <= 100, 1 <= N <= 100). Next follow a matrix which contains only number 0 and 1. The input will finish with the end of file.
 
 Output
  For each the case, your program will output the number of cycles in the given matrix on separate line.
 
 Sample Input
 1 3
 1 1 1
 2 3
 1 0 1
 0 1 1
 3 3
 1 0 1
 0 1 1
 1 1 1
 Sample Output
 0
 0
 2
*/