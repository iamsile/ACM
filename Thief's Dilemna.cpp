#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct value{
    int v,s;
    double ave;
    char a;
}num[1001];

int cmp(const void *x,const void *y)
{
    struct value *c=(value *)x;
    struct value *d=(value *)y;
    if (c->ave != d->ave)
        return d->ave - c->ave;
    else 
        return d->v - c->v;
}
int main()
{
    int m,j,i=0;
    char n[20],str[5]="$END",b[1001];
    while(cin >> n&&strcmp(n,str))
    {
        num[i].v=atoi(n);
        cin >> m;
        num[i].s=m;
        num[i].ave=(double)(num[i].v/m);
        num[i].a=(char)(65+i);
        i++;
    }    
    qsort(num,i,sizeof(num[0]),cmp);
    while(scanf("%d",&m)!=EOF)
    {
        int k=0,flag=1,sum=0;
        memset(b,0,sizeof(b));
        for(j=0,k=0;m&&j<i;j++)
            if(m>=num[j].s)
            {
                m-=num[j].s;
                sum+=num[j].v;
                b[k++]=num[j].a;
                flag=0;
            }
        if(flag)
        {
            cout << "0\n";
            continue;
        }
        sort(b+0,b+k);
        cout << sum << ' ';
        for (j=0;j<k;j++)
        {
            if(j>0)
                cout << ',';
            cout << b[j];
        }
        cout << '\n';
    }
    return 0;
}
/*
我的做法是开两个二维的数组
opt[i][j]  表示i个物品剩余容量为j时所能得到的最大值
x[i][j]表示 第i个物品在容量为j达到最优值时，i是否被选取了，x[i][j]=1表示选了  否者 x[i][j]=0;未选

那么求路径的时候就简单了
输入背包的容量c
void findPath(int c)
{
    for(int i=n;i>=1;i--)
    {
        path[i]=x[i][c];
        if(x[i][c])c-=w[i];
    }
} 
只要顺序的输出path数组就是所要的路径
超越   09:32:39
代码也发给你看看吧 
写的很长 主要是读数据的时候没优化
# include<iostream>
# define MAX 100000
int opt[11][MAX];
bool x[11][MAX],path[12];
int n,w[12],v[12];//w保存物品的重量，v保存价值,n保存物品个数
void dp()
{
    int c=MAX-1,i,j;
    for(i=1;i<=n;i++)
    {
        for(j=c;j>=0;j--)
        {
            opt[i][j]=opt[i-1][j];
            int temp=-1;
            if(j-w[i]>=0)temp=opt[i-1][j-w[i]]+v[i];
            if(temp>opt[i][j])
            {
                opt[i][j]=temp;
                x[i][j]=1;
            }
            else
                x[i][j]=0;
        }
    }
}
//任意找一条路径
void findPath(int c)
{
    for(int i=n;i>=1;i--)
    {
        path[i]=x[i][c];
        if(x[i][c])c-=w[i];
    }
}
//这部分是读数据的别管
void init()
{
    char s[100];
    int i,j;
    while(gets(s))
    {
        if(!strcmp(s,"$END"))break;
        else
        {
            n++;
            int len=strlen(s);
            bool flag=0;
            for(i=0;i<len;i++)
            {
                if(s[i]!=' ')
                {
                    if(!flag)
                    {
                        v[n]*=10;
                        v[n]+=s[i]-'0';
                    }
                    else
                    {
                        w[n]*=10;
                        w[n]+=s[i]-'0';
                    }
                }
                else flag=1;
            }
        }
    }
}
int main()
{
    memset(opt,0,sizeof(opt));
    n=0;
    int i;
    init();
    dp();
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        printf("%d",opt[n][a]);
        if(opt[n][a])
        {
            printf(" ");
            findPath(a);
            //输出路径
            bool flag=0;
            for(i=1;i<=n;i++)
                if(path[i])
                {
                    if(!flag)
                    {
                        flag=1;
                        printf("%c",i+64);
                    }
                    else printf(",%c",i+64);
                }
        }
        printf("\n");
    }
    return 0;
}
*/
/*
#include <iostream>
#include <string.h>
using namespace std;
char a[9]="$END",s[1000001];
long int n,i,j,l,v[40],b[40],r[1000001],x[40][1000001],p[40];
int main()
{
    l=0;
    while (cin >> s&&strcmp(s, a)) {
        v[l]=atoi(s);
        cin >> n;
        b[l]=n;
        l++;
    }
    while (cin >> n) {
        memset(r, 0, sizeof(r));
        for (i=0;i<l;i++)
            for (j=n;j>=b[i];j--)
                if (r[j-b[i]]+v[i]>r[j]) {
                    r[j]=r[j-b[i]]+v[i];
                    x[i][j]=1;
                }
                else x[i][j]=0;
        cout << r[n] << ' ';
        j=n;
        for (i=n; i>=0; i--) {
            p[i]=x[i][n];
            if (x[i][n])
                n-=b[i];
        }
        for (i=0; i<=j; i++)
            if (p[i])
            {
                if (i>0)
                    cout << ',';
                cout << (char)(i+65);
            }
        cout << '\n';
    }
    return 0;
}
*/
/*
 Problem description
 A thief is trying to steal some items from a rich palace. The thief wants to maximize what he takes out, but he only has a limited amount of space to carry things with. your mission is to help him maximize the amount he takes out. 
 
 Input
 the first couple of lines will describe the items he can take. Each line is of the form: 
 
 value space
 
 where value is the value of the item, and space is the number of spaces it takes up in the thief's bag. (For simplicity, we'll assume everything is one dimensional). The first item is item 'A', the second 'B', and so on. This section is ended by a line containing only $END There will be no more than 10 items. 
 
 Following the $END will be a number of cases. Each case is just a number representing the number of spaces the thief has available in his bag. 
 
 Output
 For each test case, you have to print the maximum value the thief can take out, and what items to grab. The format should be:
 
 max item,item,...
 
 where max is the max value the thief can get, and item,item,... are the names of the items to be taken. The list should be sorted alphabetically. The last item should not be followed by a comma. If no items can be taken, then just print a 0 and list no items. For obvious reasons, no item can be included more than once. 
 
 Sample Input
 15 10
 3 30
 5 4
 100 3
 90 100
 5 3
 5 6
 5 9
 $END
 2
 50
 300
 Sample Output
 0 
 135 A,C,D,F,G,H 
 228 A,B,C,D,E,F,G,H
*/