#include <iostream>
#include <deque>
using namespace::std;

int main()
{
	deque<int> a;
	a.push_back(1);
	a.push_back(1);
	int n,top=1;
	cout << "intput n:";
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=top;j++)
			a[j]*=i;
		for(int j=1;j<=top;j++)
		{
			if(a[j]>10)
			{
				for(int r=1;r<=top;r++)
				{
					int tmp=a[r]/10;
					a[r]=a[r]%10;
					if(r+1==a.size())
					{
						if(tmp==0)
							break;
						else 
						{
							a.push_back(tmp);
							top++;
							break;
						}
					}
					a[r+1]+=tmp;
				}
			}
		}
	}
	cout << n << "!=";
	for(int j=top;j>0;j--)
		cout << a[j];
	cout << endl;
	return 0;
}