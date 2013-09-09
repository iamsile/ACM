#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

inline bool right(int &a,int &b,int &c,int &d )
{
    return a!=d&&a!=c&&b!=c&&b!=d;
}
typedef struct n
{
    int c,d;
    struct n*next;
} node;

int sou[1000],prime;
node pool[1000000],*base[10003],*pp,*p;

inline node* creat(int c,int d,node* next)
{
    pp->c=c;
    pp->d=d;
    pp->next=next;
    return pp++;
}
int main()
{
    int n,i,j,tmp,res;
    bool flag;
    while(scanf("%d",&n)&&n)
    {
        res=-1000000000;
        for(i=0;i<n;++i)
            scanf("%d",sou+i);
        sort(sou,sou+n);
        prime=10003;
        memset(base,0,sizeof(base));
        pp = pool;
        for(i=0;i<n;++i)
        {
            for(j=i+1;j<n;++j)
            {
                if(i!=j)
                {
                    tmp = abs( sou[i] + sou[j] ) % prime;
                    base[tmp] = creat( sou[i], sou[j], base[tmp] );
                }
            }
        }
        for(i=n-1,flag=false;i;--i)
        {
            for(j=i-1;j>=0;--j)
            {
                if(i==j)
					continue;
                tmp=abs(sou[i]-sou[j])%prime;
                if(!base[tmp])
                    continue;
                p=base[tmp];
                while(p)
                {
                    if((sou[i]-sou[j]==p->c+p->d)&&right(p->c,p->d,sou[j],sou[i]))
                    {
                        res=sou[i];
                        flag=true;
                        break;
                    }
                    p=p->next;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(res==-1000000000)
            puts("no solution");
        else
			printf( "%d\n", res );
	}
    return 0;
}
/*
 Problem description
 给出一个包含一些整数的集合S, 请你编程找出最大的d,使得集合中存在三个数a、b、c, 有a+b+c=d。（ a、b、c、d是集合S中的不同的元素）。
 
 Input
 输入若干个s集合，每一个集合由若干行表示，第一行包含一个整数，第一行的整数n(1<=n<=1000)表示集合元素的个数，接下来n个整数表示集合中n的元素.集合中的每一个元素都在-536870912 到+536870911之间（包含边界）并且互不相同。最后一行以0结束。
 
 Output
 对于每一个集合S,输出只包含d的一行，如果无解，输出"no solution".
 
 Sample Input
 5
 2 
 3 
 5 
 7 
 12
 5
 2 
 16 
 64 
 256 
 1024
 0
 Sample Output
 12
 no solution
*/