#include <iostream>
using namespace::std;
int k,m,lab,temp[10][10],n[10][10],a[10][10];

int cal(int num)
{
	if(num>1)
	{
		cal(num/2);
		memset(temp, 0, sizeof(temp));
		for(int i=0;i<=9;++i)
			for(int j=0;j<=9;++j)
				for(int k=0;k<=9;++k)
					temp[i][j]=(temp[i][j]+(n[i][k]*n[k][j])%m)%m;
		for(int i=0;i<=9;++i)
			for(int j=0;j<=9;++j)
				n[i][j]=temp[i][j];
		if(num%2==1)
		{
			memset(temp, 0, sizeof(temp));
			for(int i=0;i<=9;++i)
				for(int j=0;j<=9;++j)
					for(int k=0;k<=9;++k)
						temp[i][j]=(temp[i][j]+(n[i][k]*a[k][j])%m)%m;
		}
		for(int i=0;i<=9;++i)
			for(int j=0;j<=9;++j)
				n[i][j]=temp[i][j];
	}
	return 0;//去掉return后可以减少1000多kb的内存
}

int main()
{
	
	while(cin >> k >> m)
	{
		memset(a, 0, sizeof(a));
		memset(n, 0, sizeof(n));
		for(int i=0;i<=8;++i)
		{
			a[i+1][i]=1;
			n[i+1][i]=1;
		}
		for(int i=0;i<=9;++i)
		{
			cin >> a[9-i][9];
			n[9-i][9]=a[9-i][9];
		}
		if(k<10) 
			cout << k%m << '\n';
		else
		{
			cal(k-9);
			lab=0;
			for(int i=0;i<=9;++i)
				lab=(lab+(n[i][9]*i)%m)%m;
			cout << lab << '\n';
		}
	}
	return 0;
}
/*
 若一矩阵的列数与另一矩阵的行数相等，则可定义这两个矩阵的乘积。如 A 是 m×n 矩阵和 B 是 n×p矩阵，
 它们是乘积 AB 是一个 m×p 矩阵，其中
 (AB)[i, j] = A[i, 1] * B[1, j] + A[i, 2] * B[2, j] + ... + A[i, n] * B[n, j] 对所有 i 及 j。 
 此乘法有如下性质：
 (AB)C = A(BC) 对所有 k×m 矩阵 A, m×n 矩阵 B 及 n×p 矩阵 C ("结合律"). 
 (A + B)C = AC + BC 对所有 m×n 矩阵 A 及 B 和 n×k 矩阵 C ("分配律")。 
 C(A + B) = CA + CB 对所有 m×n 矩阵 A 及 B 和 k×m 矩阵 C ("分配律")。 
 要注意的是：可置换性不一定成立，即有矩阵 A 及 B 使得 AB ≠ BA。
 
 下面我们研究一下这道题如何运用矩阵。
 假设我们已有一个1*10的矩阵f0 f1 f2...f9 只要将其乘以一下矩阵，就可以推导至矩阵f1 f2 f3 ...f10：
 0 0 0 0 0 0 0 0 0 a(9)
 1 0 0 0 0 0 0 0 0 a(8) 
 0 1 0 0 0 0 0 0 0 a(7) 
 0 0 1 0 0 0 0 0 0 a(6) 
 0 0 0 1 0 0 0 0 0 a(5) 
 0 0 0 0 1 0 0 0 0 a(4)
 0 0 0 0 0 1 0 0 0 a(3)
 0 0 0 0 0 0 1 0 0 a(2)
 0 0 0 0 0 0 0 1 0 a(1) 
 0 0 0 0 0 0 0 0 1 a(0)  
 设这个矩阵为D。
 f1,f2,f3...f10再乘以这个矩阵就可以推导至f2,f3,f4...f11。以此类推，递推的过程就变成了不断乘以
 这个矩阵的过程。这样，如果我们要得到fk，我们就得将初始矩阵（f0,f1,f2...f10）乘以D^(k-9)，从而得出目
 标矩阵（目标矩阵的最后一项即为所求）。而D^(k-9)我们可以用10^3*log(k-9)的时间计算出来，此题圆满解决。
 */
/*
 Problem description
 Lele now is thinking about a simple function f(x).
 
 If x < 10 f(x) = x.
 If x >= 10 f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + …… + a9 * f(x-10);
 And ai(0<=i<=9) can only be 0 or 1 .
 
 Now, I will give a0 ~ a9 and two positive integers k and m ,and could you help Lele to caculate f(k)%m.
 
 
 Input
 The problem contains mutiple test cases.Please process to the end of file.
 In each case, there will be two lines.
 In the first line , there are two positive integers k and m. ( k<2*109 , m < 104 )
 In the second line , there are ten integers represent a0 ~ a9.
 
 
 Output
 For each case, output f(k) % m in one line.
 
 Sample Input
 10 9999
 1 1 1 1 1 1 1 1 1 1
 20 500
 1 0 1 0 1 0 1 0 1 0
 Sample Output
 45
 104
*/