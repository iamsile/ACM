#include <stdio.h>
#include <string.h>
int main()
{
	int a[50001], b[50001];
	int i, j, l, r, len, n, mid;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		len = 0;
		memset(b, 0, sizeof(int) * 50001);
		b[0] = -1;
		for (i = 0; i < n; i++)
		{
			if (a[i] > b[len])
				b[++len] = a[i];
			else if (a[i] < b[1] )
				b[1] = a[i]; 
			else
			{
				l = 1; r = len;
				while (l <= r)
				{
					mid = (l + r)>>1;
					if (a[i] > b[mid] && a[i] <= b[mid + 1])
					{
						j = mid;
						break;
					}
					if (b[mid] > a[i])
					{
						r = mid - 1;
					}
					else
					{
						j = mid;
						l = mid + 1;
					}
				}
				b[j + 1] = a[i];
			}
		}
		printf("%d\n", len);
	}
	return 0;
}
/*
#include <iostream>
using namespace::std;

int main()
{
    int n,max,i,j,lab=0,a[1001]={0},b[1001]={0};
    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i];
    for(i=n-1;i>=0;i--)
    {
        max=0;
        for(j=i+1;j<n;j++)
            if(a[i]<a[j]&&b[j]>max)
                max=b[j];
        b[i]=max+1;
        if(b[i]>lab)
            lab=b[i];
    }
    cout << lab << '\n';
    return 0;
}
 */
/*
 Problem description
 A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).
 
 Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
 
 Please notice this problem is different with 10001,^_^.
 
 Input
 The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 100000 each, separated by spaces. 1 <= N <= 50000
 
 
 
 Output
 Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
 
 
 
 Sample Input
 7
 1 7 3 5 9 4 8
 Sample Output
 4
 */
