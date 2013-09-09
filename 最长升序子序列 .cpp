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
 对于num[n]来说，由于它是最后一个数，所以当从num[n]开始查找时，只存在长度为1的不下降
 子序列；
 若从num[n-1]开始查找，则存在下面的两种可能性:
 1.若num[n-1]<num[n],则存在长度为2的不下降子序列num[n-1],num[n];
 2.若num[n-1]>num[n]，则存在长度为1的不下降子序列num[n-1]或者num[n];
 一般若从num[j]开始，此时最长不下降子序列应该是按下列方法求出：
 在a[j+1],a[j+2],....a[n]中，找出一个比a[t]大的且最长不下降子序列，作为它的后继 
 */