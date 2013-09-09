#include <iostream>
using namespace::std;

int main()
{
	int n,i,j,k;
	while(cin >> n)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				k=((i+j+(n-3)/2)%n)*n+(i-j+(3*n-1)/2)%n+1;
				if(j>1)
					cout << ' ';
				cout << k;
			}
		cout << "\n";
	}
	cout << "\n";
	}
	return 0;
}
/*公式：N(I,J)=((I+J+(N-3)/2) MOD N)*N+(I-J+(3*N-1)/2) MOD N +1 
建立幻方矩阵的公式，i代表行，j代表列，可以算一个输出一个，这样就不会出现问题了*/