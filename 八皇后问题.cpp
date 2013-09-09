#include <iostream>
#include <math.h>
using namespace::std;

int sum=0;
int n;
int *x;

bool place(int k)
{
	for(int j=1;j<k;j++)
		if(abs(k-j)==abs(x[j]-x[k])||x[j]==x[k])
			return false;
	return true;
}

void backtract_queen(int t)
{
	if(t>n)
	{
		sum++;
		for(int i=1;i<=n;i++)
			cout << x << ' ';
		cout << '\n';
	}
	else 
		for(int i=1;i<=n;i++)
		{
			x[t]=i;
			if(place(t))
				backtract_queen(t+1);
		}
}

int main()
{
	cout << "input the number of queen:";
	cin >> n;
	x=new int[n];
	backtract_queen(1);
	cout << "sum=" << sum << '\n';
	cout << "end\n";
}