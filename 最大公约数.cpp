/*#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef unsigned __int64 u64;
const int MAX = 100;
const int MAXN = 30;
u64 len, dig, limit;
u64 mod(u64 a, u64 b, u64 n) {
	if(! a) return 0;
	return (((a & dig) * b) % n + (mod(a >> len, b, n) << len) % n) % n;
}
u64 by(u64 a, u64 b, u64 n) {
	u64 p;
	p = 8, len = 61;
	while(p < n) {
		p <<= 4;
		len -= 4;
	}
	dig = ((limit / p) << 1) - 1;
	return mod(a, b, n);
}
u64 random() {
	u64 a;
	a = rand();
	a *= rand();
	a *= rand();
	a *= rand();
	return a;
}
u64 square_multiply(u64 x, u64 c, u64 n) {
	u64 z = 1;
	while(c) {
		if(c & 1) z = by(z, x, n);
		x = by(x, x, n);
		c >>= 1;
	}
	return z;
}
bool Miller_Rabin(u64 n) {
	if(n < 2) return false;
	if(n == 2) return true;
	if(! (n & 1)) return false;
	u64 i, j, k, m, a;
	m = n - 1;
	k = 0;
	while(m % 2 == 0) {
		m >>= 1; k ++;
	}
	for(i = 0; i < MAX; i ++) {
		a = square_multiply(random() % (n - 1) + 1, m, n);
		if(a == 1) continue;
		for(j = 0; j < k; j ++) {
			if(a == n - 1) break;
			a = by(a, a, n);
		}
		if(j == k) return false;
	}
	return true;
}
u64 gcd(u64 a, u64 b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}
u64 f(u64 x, u64 n) {
	return (by(x, x, n) + 1) % n;
}
u64 Pollard_Rho(u64 n) {
	if(n <= 2) return 0;
	if(! (n & 1)) return 2;
	u64 i, p, x, xx;
	for(i = 1; i < MAX; i ++) {
		x = random() % n;
		xx = f(x, n);
		p = gcd((xx + n - x) % n, n);
		while(p == 1) {
			x = f(x, n);
			xx = f(f(xx, n), n);
			p = gcd((xx + n - x) % n, n) % n;
		}
		if(p) return p;
	}
	return 0;
}
u64 factor[MAXN], m;
u64 Prime(u64 a) {
	if(Miller_Rabin(a)) return 0;
	u64 t = Pollard_Rho(a);
	u64 p = Prime(t);
	if(p) return p;
	return t;
}
int main() {
#ifdef JUDGE_ONLINE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	u64 a, t;
	limit = 1;
	limit = limit << 63;
	int casn;
	scanf("%d", &casn);
	while(casn --) {
		scanf("%I64d", &a);
		m = 0;
		while(a > 1) {
			if(Miller_Rabin(a)) break;
			t = Prime(a);
			factor[m ++] = t;
			a /= t;
		}
		if(a > 0) factor[m ++] = a;
		if(m == 1) printf("Prime\n"); //所有素约数保存于factor[]中，m为其个数
		else {
			int k = 0;
			for(int i = 1; i < m; i ++) {
				if(factor[k] > factor[i])
					k = i;
			}
			printf("%I64d\n", factor[k]);
		}
	}
	return(0);
}*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

typedef unsigned long long llu;

int p[] = { 2,3,5,7,11, 13,17,19,23,29 };
int k = 10;

// 不适合时限较低的题目。常数非常大！！！ 
llu mol_mult( llu a, llu b, llu n)
{
    if( !b ) return 0;
    return ( mol_mult( a, b >> 1 , n ) * 2 + a * ( b & 1 ) ) % n;
}
/* 
 // 代码量大，但常数低 
 llu mol_mult( llu a,llu b,const llu &mol)
 {
 llu c = a >> 30 , d = b >> 30 , tmp , t;
 tmp = 1ll << 30;
 a %= tmp ; b %= tmp;
 
 llu ans = a * b;
 if( ans > mol )
 ans %= mol;
 
 tmp = c * b ;
 if( tmp > mol ) tmp %= mol;
 t = 30;
 while( t -- ){
 tmp <<= 1;
 if( tmp > mol ) tmp -= mol;
 }
 ans += tmp;
 if( ans > mol )
 ans -= mol;
 
 
 tmp = d * a ;
 if( tmp > mol ) tmp %= mol;
 t = 30;
 while( t -- ){
 tmp <<= 1;
 if( tmp > mol ) tmp -= mol;
 }
 ans += tmp;
 if( ans > mol )
 ans -= mol;
 
 tmp = d * c ;
 if( tmp > mol ) tmp %= mol;
 t = 60;
 while( t -- ){
 tmp <<= 1;
 if( tmp > mol ) tmp -= mol;
 }
 ans += tmp;
 
 ans %= mol;
 
 return ans;
 }
 */
llu mol_exp( llu a,llu b,llu n)
{
    llu t = a % n , ans = 1;
    while( b )
    {
        if( b & 1 )
        {
            ans = mol_mult( ans, t, n);//1ll * ans * t % n;
        }
        t = mol_mult( t, t, n );//1ll * t * t % n;
        b >>= 1;
    }
    return ans;
}

int witness( llu a,llu n )
{
    llu t = 0, tmp = n - 1;
    while( tmp % 2 == 0 ){
        t ++ ;
        tmp >>= 1 ;
    }
    
    llu x0 = mol_exp( a, tmp, n ), x1, i;
    for ( i = 1 ; i <= t ; i ++ )
    {
        x1 = mol_mult( x0, x0 , n);//1ll * x0 * x0 % n;
		if( x1 == 1 && x0 != 1&& x0 != n - 1 )
			return 1;
        x0 = x1;
    }
    
    if( x1 != 1 )
        return 1;
    return 0;
}

inline llu my_rand(llu b,llu e )
{
    return (llu)((1. * rand() / ( 1. + RAND_MAX ) * (e - b + 1))) + b;
}

int miller_rabin( llu n,llu s )
{
    llu i, a;
    for ( i = 1 ; i <= s ; i ++ )
    {
        a = my_rand( 2, n - 1);
        if( witness ( a, n ) ) return 0;
    }
    return 1;
}

llu gcd(llu a,llu b){
    llu t ;
    while( b ){
        t = a % b; a = b; b = t;
    }
    return a;
}

llu pollard_rho( llu n, llu c )
{
    llu i = 1;
    llu x = my_rand( 1, n - 1 ), d;
    llu y = x;
    llu k = 2;
    while( 1 ){
        i ++;
        x = ( mol_mult( x , x, n ) + n - c ) % n;
        if( x == y )
            break;
        if ( x > y )
            d = gcd( x - y, n );
        else
            d = gcd( y - x, n );
        if( d != 1 && d != n )
            return d;
        if( i == k ){
            y = x;
            k <<= 1 ;
        }
    }
    return n;
}

llu minfactor;

void make(llu n)
{
    llu d, c;
    if( miller_rabin( n, 20 ) ){
        minfactor = min( minfactor , n );
        return ;
    }
    do{
        c = my_rand( 1, n - 1 );
        d = pollard_rho( n, c );
    }while( d >= n );
    make( d );
    make( n/d );
}

int main()
{
    llu n, i;
    srand( n );
    int test;
    cin>>test;
    while( test--)
    {
        cin>>n;
        if( n == 1 ){ puts("1"); continue; }
        for ( i = 0 ; i < k ; i ++ )
            if( n % p[i] == 0 ){
                if( n == p[i] ) 
                    puts("Prime");
                else 
                    printf("%d\n",p[i]);
                break;
            }
        if( i < k ) continue;
        minfactor = n;
        if( miller_rabin( n, 20 ) )
            printf("Prime\n");
        else{
            make( n );
            printf("%llu\n",minfactor);
        }
    }
    return 0;
}