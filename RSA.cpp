#include <stdio.h>
__int64 p,q,e,l,n,x,y,ans;

void gcd(__int64 a,__int64 b)
{
    if (!b) {
        x=1;
        y=0;
        return;
    }
    gcd(b, a%b);
    __int64 num=x;
    x=y;
    y=num-(a/b)*y;
}

__int64 qmod(__int64 x,__int64 n,__int64 p)
{
    __int64 sum=1;
    int i=0,j;
    bool f[70];
    while (n) {
        if (n&1)
            f[i++]=1;
        else f[i++]=0;
        n=n>>1;
    }
    for (j=i-1; j>=0; j--) {
        sum=(sum*sum)%p;
        if (f[j])
            sum=(sum*x)%p;
    }
    return sum;
}

int main()
{
    char cc;
    while (scanf("%I64d%I64d%I64d%I64d",&p,&q,&e,&l)!=EOF) {
        n=p*q;
        ans=(p-1)*(q-1);
        gcd(e,ans);
        x=(x+ans)%ans;
        while (l--) {
            scanf("%I64d",&y);
            cc=qmod(y,x,n);
            printf("%c",cc);
        }
        printf("\n");
    }
    return 0;
}

/*
long long qmod(long long x,long long n,long long p)
{
    long long k=1,t=x;
    while (n>0) {
        if (n&0x1)
            k=(k*t)%p;
        n=n>>1;
        t=(t*t)%p;
    }
    return k;
}
*/
/*
 Problem Description
 RSA is one of the most powerful methods to encrypt data. The RSA algorithm is described as follow:
 
 > choose two large prime integer p, q
 > calculate n = p × q, calculate F(n) = (p - 1) × (q - 1)
 > choose an integer e(1 < e < F(n)), making gcd(e, F(n)) = 1, e will be the public key
 > calculate d, making d × e mod F(n) = 1 mod F(n), and d will be the private key
 
 You can encrypt data with this method :
 
 C = E(m) = me mod n
 
 When you want to decrypt data, use this method :
 
 M = D(c) = cd mod n
 
 Here, c is an integer ASCII value of a letter of cryptograph and m is an integer ASCII value of a letter of plain text.
 
 Now given p, q, e and some cryptograph, your task is to "translate" the cryptograph into plain text.
 Input
 Each case will begin with four integers p, q, e, l followed by a line of cryptograph. The integers p, q, e, l will be in the range of 32-bit integer. The cryptograph consists of l integers separated by blanks. 
 Output
 For each case, output the plain text in a single line. You may assume that the correct result of plain text are visual ASCII letters, you should output them as visualable letters with no blank between them.
 Sample Input
 101 103 7 11
 7716 7746 7497 126 8486 4708 7746 623 7298 7357 3239
 Sample Output
 I-LOVE-ACM.
*/