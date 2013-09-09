#include<stdio.h>

int gcd(int a,int b)
{
    int temp;
    while(a%b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return b;
}

int main()
{
    int i,ncase,ans,p,q,t,m,n,x,y,k,l;
    char ch[25];
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%s",ch);
        x=0;
        t=0;
        p=0;
        q=0;
        k=1;l=1;
        for(i=2;ch[i]!=0;i++)
        {
            if(t==0 && ch[i]!='(')
            {
                p++;
                x*=10;
                x+=ch[i]-'0';
            }
            if(t==1&& ch[i]!=')')
            {
                q++;
                y*=10;
                y+=ch[i]-'0';
            }
            if(ch[i]=='(') {t=1;y=x;q=p;}
        }
        if(q==0)
        {
            while(p--)
                k*=10;
                ans=gcd(x,k);
                x/=ans;
                k/=ans;
                printf("%d/%d\n",x,k);
                }
        else
        {
            m=y-x;
            while(p--)
                k*=10;
                while(q--)
                    l*=10;
                    n=l-k;
                    ans=gcd(m,n);
                    m/=ans;
                    n/=ans;
                    printf("%d/%d\n",m,n);
                    }
    }
    return 0;
}
/*
 Problem Description
 Ray 在数学课上听老师说，任何小数都能表示成分数的形式，他开始了化了起来，很快他就完成了，但他又想到一个问题，如何把一个循环小数化成分数呢?
 请你写一个程序不但可以将普通小数化成最简分数，也可以把循环小数化成最简分数。
 
 
 Input
 第一行是一个整数N，表示有多少组数据。
 每组数据只有一个纯小数，也就是整数部分为0。小数的位数不超过9位，循环部分用()括起来。
 
 
 Output
 对每一个对应的小数化成最简分数后输出，占一行。
 
 
 Sample Input
 3
 0.(4)
 0.5
 0.32(692307)
 
 
 Sample Output
 4/9
 1/2
 17/52
*/