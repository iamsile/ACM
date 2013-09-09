#include<iostream>
using namespace std;
const int MAX = 100000000 ; 

int add(const int*b ,const int*c ,int*t)
{
    int k = 0,m=0;
    while(1)
    {
        t[k] = b[k]+c[k]+m;
        if(t[k]>MAX)
        {
            m = t[k]/MAX;
            t[k] %= MAX;
        } 
        else
            m=0;
        
        if(t[k]>0)   
            ++k;
        else
            break;      
    }
    return k-1;   
}              

void fenduan(long long s, int*c)
{
    int i=0;    
    while(s>MAX)
    {
        c[i] = s%MAX;
        i++;
        s /= MAX;     
    } 
    c[i]= s;
} 

int main()
{
    int n,pi;
    long long a[1001]={0,1};
    for(int i=2;i<93;++i)
        a[i]=a[i-1]+a[i-2];
    cin >> n;
    while(n--)
    {
        int b[1000]={0};
        int c[1000]={0};
        int t[1000]={0};
        fenduan(a[91],b);
        fenduan(a[92],c);
        int* t1=t;
        int* b1=b;
        int* c1=c;
        int l;
        cin>>pi;
        if(pi<=92)
        {
            cout<<a[pi]<<endl;
            continue;
        }
        else
        {
            for(int k = 93; k <= pi; ++k)
            {     
                l = add(b1,c1,t1);
                if(k!=pi)
                {    
                    int *temp = b1;
                    b1 = c1;  
                    c1 = t1;   
                    t1 = temp;   
                }
            }
        }
        cout<<t1[l];
        while(--l,l>-1)
            printf("%08d",t1[l]);
        cout<<"\n";    
    } 
    return 0;
}
/*
 Problem Description
 Fibonacci数列，定义如下：
 f(1)=f(2)=1
 f(n)=f(n-1)+f(n-2) n>=3。
 计算第n项Fibonacci数值。
 
 
 Input
 输入第一行为一个整数N，接下来N行为整数Pi（1<=Pi<=1000）。
 
 
 Output
 输出为N行，每行为对应的f(Pi)。
 
 
 Sample Input
 5
 1
 2
 3
 4
 5
 
 
 Sample Output
 1
 1
 2
 3
 5
*/