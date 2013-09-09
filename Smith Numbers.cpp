#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n--) {
        long long m,i,num,lab,flag,sum1=1,sum2=0;
        cin >> m;
        if (m==1) {
            cout << "4\n";
            continue;
        }
        long k=(long)sqrt(m);
        for (m++; sum1!=sum2; m++) {
            sum1=0;sum2=0;
            for (lab=m; lab; lab/=10)
                sum1+=lab%10;
            for (i=2,lab=m; i<=k+1&&lab; i++)
                while (lab%i==0) {
                    if (i>9) {
                        num=i;
                        while (num) {
                            sum2+=num%10;
                            num/=10;
                        }
                    }
                    else sum2+=i;
                    lab/=i;
                }
            if (lab==m)
                continue;
            flag=lab;
            while (lab>1&&flag) {
                sum2+=flag%10;
                flag/=10;
            }
            
        }
        cout << m-1 << '\n';
    }
    return 0;
}
/*hdu-ac
#include<iostream>  
#include<cmath>  
using namespace std;  
int prime(int n)  
{  
    int i,t=sqrt(n)+1;  
    if(n==2)   return 1;    //素数的判断函数竟然写错了，导致跳不出去   
    for(i=2;i<=t;i++)  
    {  
        if(n%i==0)  
            return 0;                   
    }  
    return 1;  
}  
int find(int n)  
{  
    int t,k,sum1,sum2,i;  
    while(1)  
    {  
        n++;  
        if(prime(n))   continue;   //遇到素数跳过   
        sum1=sum2=0;  
        t=k=n;  
        while(k){sum1+=k%10;k/=10;}  
        while(!prime(t))  
        {  
            i=2;  
            while(!prime(i)||t%i!=0)  
                i++;  
            t=t/i;  
            while(i)   
            {sum2+=i%10;i=i/10;}  
        }  
        while(t){sum2+=t%10;t/=10;}  
        if(sum1==sum2) return n;  
    }  
}  
int main()  
{
    int n;  
    while(cin>>n&&n)  
        cout<<find(n)<<endl;  
    return 0;  
}  
*/
/*
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define SIZE 10002
int pNum=0,p[SIZE]={0},prim[1230]={0};
void FindPrime()//筛法
{
    int i,j;
    for(i=2;i<SIZE;i++)
    {
        if(!p[i])
        {
            prim[pNum++]=i;
            for(j=i+i;j<SIZE;j+=i)
            {
                p[j]=1;
            }
        }
    }
}
bool SmithNumber(int n)//判断是不是Smith数
{
    int k;
    int sum1=0,sum2=0;
    int z=n,x=n;
    while(z!=0)//求n的各位之和
    {
        sum2+=z;
        z/=10;
    }
    for(k=0;prim[k]*prim[k]<=n&&n!=1;k++)//计算n的质因子的各位之和
    {
        while(n%prim[k]==0)
        {
            int pp=prim[k];
            while(pp!=0)
            {
                sum1+=pp;
                pp/=10;
            }
            n/=prim[k];
        }
    }
    if(x==n)//n没有小于根号n的素因子
    {
        return false;
    }
    if(n!=1)//n有大于根号n的素因子
    {
        while(n!=0)
        {
            sum1+=n;
            n/=10;
        }
    }
    if(sum1==sum2) return true;//相等则为Smith数
    else return false;
}

int main()
{
    int n;
    FindPrime();
    while(scanf("%d",&n),n)
    {
        n++;
        while(!SmithNumber(n))
        {
            n++;
        }
        printf("%d\n",n);
    }
    return 0;
}
*/
/*
 While skimming his phone directory in 1982, mathematician Albert Wilansky noticed that the telephone number of his brother-in-law H. Smith had the following peculiar property: The sum of the digits of that number was equal to the sum of the digits of the prime factors of that number. Got it? Smith's telephone number was 493-7775. This number can be written as the product of its prime factors in the following way:
 
 4937775 = 3 . 5 . 5 . 65837
 The sum of all digits of the telephone number is 4 + 9 + 3 + 7 + 7 + 7 + 5 = 42, and the sum of the digits of its prime factors is equally 3 + 5 + 5 + 6 + 5 + 8 + 3 + 7 = 42. Wilansky named this type of number after his brother-in-law: the Smith numbers.
 As this property is true for every prime number, Wilansky excluded them from the definition. Other Smith numbers include 6,036 and 9,985.
 
 Wilansky was not able to find a Smith number which was larger than the telephone number of his brother-in-law. Can you help him out?
 
 Input
 
 The input consists of several test cases, the number of which you are given in the first line of the input. Each test case consists of one line containing a single positive integer smaller than 109.
 Output
 
 For every input value n, compute the smallest Smith number which is larger than n and print it on a single line. You can assume that such a number exists.
 Sample Input
 
 1
 4937774
 Sample Output
 
 4937775
*/