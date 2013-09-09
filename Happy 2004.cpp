#include <iostream>  
using namespace std;  

int main()  
{  
    int n,i,f,t,d;  
    while (cin>>n &&n)  
    {  
		f=t=d=1;
		for(i=0;i<=n;++i)
		{
			f=f*(i==n?2:4)%29;  //f表示2^(2n+1)的值 
			t=t*3%29;           //t表示3^(n+1)的值 
			d=d*22%29;          //d表示167^(n+1)的值
		}
		i=(f-1)*(t-1)*(d-1)%29; //S=r/332,r的值
        cout<<i*9%29<<endl;     //S%29=r*9%29
    }  
    return 0;  
}
/*
 首先题目要求的是（2004^x）的因子和 mod 29=? 
 因为不能显示上标，所以不要看成2004X(我也是郁闷了好久才发现的，因为显然20041没有2004的因子) 
 求某个数的因子和，首先将该数分解 
 如：x=(p1^r1)*(p2^r2)*...*(pn^rn) 其中p1,p2,...,pn都是素数 
 则x的任意因子可以表示为：d=(p1^i1)*....(pn^in),其0<=i1<=r1,....0<=in<=rn 
 将其求和，为s=((p1^(r1+1))/(p1-1))*....((pn^(rn+1))/(pn-1)) 
 如：2004=2^2*3*167 
 s=((2^3-1)/(2-1)) * ((3^2-1)/(3-1)) * ((167^2-1)/(167-1))=7*4*168=4704 
 2004^x=2^(2x)*3^x*167^x 
 s=(2^(2x+1)-1) * (3^(x+1)-1) * (167 ^(x+1)-1)/(2*166)=r/332 
 x还很大(1=<x<=10000000)，根据Euler定理,任意素数p,有a^(p-1) mod p=1;a^28 mod 29=1 
 所以首先将x对28取模，x%=28;x就很小了(0<=x<=28)(有了这点，输入的x再大也没关系，呵呵) 
 最后，s=r/332,考虑到：9*332-103*29=1;所以s%29=r*9%29. 
 2004^10000=2^20000*3^10000*167^10000 
 其s=(2^20001-1)*(3^10001-1)*(167^10001-1)/332=r/332 
 20001%28=9,10001%28=5,167%29=22. 
 r=(2^9-1)*(3^5-1)*(22^5-1)%29=18*10*12%29=14 
 s%29=r*9%29=14*9%29=10
*/
/*
 Problem description
 Consider a positive integer X,and let S be the sum of all positive integer divisors of 2004^X. Your job is to determine S modulo 29 (the rest of the division of S by 29).
 
 Take X = 1 for an example. The positive integer divisors of 2004^1 are 1, 2, 3, 4, 6, 12, 167, 334, 501, 668, 1002 and 2004. Therefore S = 4704 and S modulo 29 is equal to 6. 
 
 Input
 The input consists of several test cases. Each test case contains a line with the integer X (1 <= X <= 10000000). 
 
 A test case of X = 0 indicates the end of input, and should not be processed. 
 
 Output
 For each test case, in a separate line, please output the result of S modulo 29.
 
 Sample Input
 1
 10000
 0
 Sample Output
 6
 10
*/