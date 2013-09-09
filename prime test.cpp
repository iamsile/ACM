#include <iostream>
#include <cstdlib>
#include <map>
#define gcc 10007          //不同情况有不同的效果
#define MAX ((Int)1<<63)-1
using namespace std;
typedef unsigned __int64 Int;
Int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
map < Int, int > Map;
inline Int Gcd(Int a, Int b)
{
	Int m = 1;
	if(!b)
		return a;
	while(m)
	{
		m = a % b;
		a = b;
		b = m;
	}
	return a;
}
//计算a*b%n
inline Int Produc_Mod(Int a, Int b, Int mod)
{
	Int sum = 0;
	while(b)
	{
		if(b & 1) sum = (sum + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return sum;
}
//计算a^b%n
inline Int Power(Int a, Int b, Int mod)
{
	Int sum = 1;
	while(b)
	{
		if(b & 1) sum = Produc_Mod(sum, a, mod);
		a = Produc_Mod(a, a, mod);
		b >>= 1;
	}
	return sum;
}

//Rabin_Miller判素
bool Rabin_Miller(Int n)
{
	int i, j, k = 0;
	Int u, m, buf;
	//将n-1分解为m*2^k
	if(n == 2)
		return true;
	if(n < 2 || !(n & 1))
		return false;
	m = n-1;
	while(!(m & 1))
		k++, m >>= 1;
	
	for(i = 0; i < 9; i++)
	{
		if(p[i] >= n)
			return true;
		
		u = Power(p[i], m, n);
		if(u == 1)
			continue;
		for(j = 0; j < k; j++)
		{
			buf = Produc_Mod(u, u, n);
			//看是否有非平凡因子存在
			if(buf == 1 && u != 1 && u != n-1)
				return false;
			u = buf;
		}
		//如果p[i]^(n-1) % n != 1 那么 n为合数
		if(u-1)
			return false;
	}
	return true;
}

//寻找n的一个因子
Int Pollard_rho(Int n)
{
	int i = 1;
	Int x = rand() % (n-1) + 1;
	Int y = x;
	Int k = 2;
	Int d;
	do{
		i++;
		d = Gcd(n + y - x, n);
		if(d > 1 && d < n)
			return d;
		if(i == k)
			y = x, k *= 2;
		x = (Produc_Mod(x, x, n) + n - gcc) % n;
	}while(y != x);
	return n;
}

Int Min;
Int Pollard_Min(Int n)
{
	Int p, a, b = MAX;
	if(n == 1) return MAX;
	if(Rabin_Miller(n)) return n;
	p = Pollard_rho(n);
	a = Pollard_Min(p);
	Int y = n / p;
	b = Pollard_Min(y);
	return a < b ? a : b;
}

int main()
{
	int t, i;
	Int n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%I64d", &n);
		Min = MAX;
		if(Rabin_Miller(n))
			printf("Prime\n");
		else
			printf("%I64d\n", Pollard_Min(n));
	}
	return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxTest 100
__int64 Random(__int64 n)
{
    return (__int64)((double)rand()/RAND_MAX*n+0.5);
}

__int64 Modular_Exp(__int64 a, __int64 b, __int64 n) // a^b mod n 
{
    __int64 ans;
	if(b == 0)
        return 1;
    if(b == 1) 
        return a%n;
    ans = Modular_Exp(a, b/2, n);
    ans = ans*ans%n;
    if(b%2)
        ans = ans*a%n;
}

bool Miller_Rabbin(__int64 n)
{
    for(int i=1; i<=maxTest; i++)
    {
        __int64 a = Random(n-2)+1;
        if(Modular_Exp(a, n-1, n) != 1) 
            return false;
    }
    return true;
}
int main()
{
    
    srand(time(NULL));
    __int64 n;
    while(scanf("%I64d", &n)==1)
        if(Miller_Rabbin(n))
            printf("Primer\n\n");
        else 
            printf("Not Prime\n\n");
    return 0;
}*/
