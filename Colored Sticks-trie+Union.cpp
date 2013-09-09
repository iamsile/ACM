#include <iostream>
using namespace std;
#define N 500001

struct node {
    int k;
    node *next[26];
    node() {
        k=-1;
        memset(next, 0, sizeof(next));
    }
};

int num,f[N],r[N],d[N];

int Find(int x)
{
    if (x!=f[x])
        f[x]=Find(f[x]);
    return f[x];
}

void Union(int x,int y)
{
    if (x==y)
        return;
    if (r[x]<r[y])
        f[y]=x;
    else {
        if (r[x]==r[y])
            r[y]++;
        f[x]=y;
    }
}

int build(node *root,char s[])
{
    node *p=root;
    int i,k=strlen(s);
    for (i=0; i<k; i++) {
        if (p->next[s[i]-'a']==NULL)
            p->next[s[i]-'a']=new node();
        p=p->next[s[i]-'a'];
    }
    if (p->k==-1)
        p->k=++num;
    return p->k;
}

int main()
{
    int i,x,y,sum;
    char a[12],b[12];
    for (i=0; i<N; i++) {
        f[i]=i;
        r[i]=0;
        d[i]=0;
    }
    node *root=new node();
    num=0;
    while (~scanf("%s%s",a,b)) {
        x=build(root,a);
        y=build(root,b);
        d[x]++;
        d[y]++;
        Union(Find(x),Find(y));
    }
    for (sum=0,i=1; i<num; i++)
        if (d[i]%2)
            sum++;
    if (sum>2)
        printf("Impossible\n");
    else {
        for (i=2; i<num; i++)
            if (Find(i)!=Find(1)) {
                printf("Impossible\n");
                return 0;
            }
        printf("Possible\n");
    }
    return 0;
}
/*
#include<iostream>
using namespace std;
int color[500002],set[500002];

int Hash(char * str)
{
    int hash = 1;
    while(*str)
        hash = (hash*29 + *str++ - 'a')%9991;
    return hash;
}

int find_set(int x)
{
    int tmp=0;
    int root=x;
    while(set[root]>=0)
    {
        root=set[root];
    }
    while(x!=root)
    {
        tmp=set[x];
        set[x]=root;
        x=tmp;
    }
    return root;
}

void union_set(int root1,int root2)
{
    int sum = set[root1]+set[root2];
    if(set[root1]>set[root2])
    {
        set[root1] = root2;
        set[root2] = sum;
    }
    else
    {
        set[root2] = root1;
        set[root1] = sum;
    }
}
int main()
{
    int n1,n2,n=0,root1,root2,i,no=0;
    char a[11],b[11];
    for(i=0;i<500002;++i)
    {
        set[i]=-1;
        color[i]=0;
    }
    while(scanf("%s%s",a,b)!=EOF)
    {
        ++n;
        n1=Hash(a);
        n2=Hash(b);
        ++color[n1];
        ++color[n2];
        root1=find_set(n1);
        root2=find_set(n2);
        if(root1!=root2)
            union_set(root1,root2);
    }
    int root=1;
    for(int i=0;i<500002;++i)
    {
        if(color[i]>0)
        {
            if(color[i]%2)
            {
                ++no;
                if(no>2)
                {
                    printf("Impossible\n");
                    return 0;
                }
            }
            if(root==1)
                root = find_set(i);
            else
                if(root!=find_set(i)){ printf ("Impossible\n");return 0;}
        }
    }
    printf("Possible\n");
    return 0;
}
*/
/*
 Description
 
 You are given a bunch of wooden sticks. Each endpoint of each stick is colored with some color. Is it possible to align the sticks in a straight line such that the colors of the endpoints that touch are of the same color?
 Input
 
 Input is a sequence of lines, each line contains two words, separated by spaces, giving the colors of the endpoints of one stick. A word is a sequence of lowercase letters no longer than 10 characters. There is no more than 250000 sticks.
 Output
 
 If the sticks can be aligned in the desired way, output a single line saying Possible, otherwise output Impossible.
 Sample Input
 
 blue red
 red violet
 cyan blue
 blue magenta
 magenta cyan
 Sample Output
 
 Possible
*/