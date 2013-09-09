#include <iostream>
using namespace::std;

int main()
{
	int n,m,i,j,lab=0,a[5001];
	cin >> n >> m;
	for(i=1;i<=n;i++)
		cin >> a[i];
	for(i=2;i<=n;i++)
		for(j=i;j<n;j++)
			if(a[i-1]+a[j]==m)
			{
				cout << i-1 << '\n' << j << '\n';
				lab++;
				break;
			}
	if(lab==0)
		cout << "0\n";
	return 0;
}
/*
 Problem description
 某组织欲破获一个外星人的密码，密码由一定长度的字串组成。此组织拥有一些破译此密码的长度不同的钥匙，若两个钥匙的长度之和恰好为此密码的长度，则此密码被成功破译。现在就请你编程找出能破译此密码的两个钥匙。 
 
 Input
 输入文件第一行为钥匙的个数N（1≤N≤5000） 
 输入文件第二行为密码的长度 
 以下N行为每个钥匙的长度 
 
 
 Output
 若无法找到破译此密码的钥匙，则输出文件仅1行0 。
 若找到两把破译的钥匙，则输出文件有两行，分别为两把钥匙的编号。
 若有多种破译方案，则只输出一种即可。 
 
 
 Sample Input
 10 
 80 
 27 
 9 
 4 
 73 
 23 
 68 
 12 
 64 
 92 
 24 
 Sample Output
 6     
 7
*/