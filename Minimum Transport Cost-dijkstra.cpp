#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>//stack 是好东西啊
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 0x3ffffff;
const int N = 1005;
int cost[N][N];
int path[N];
int c1[N];
int c2[N];
int dis[N];
int v[N];
bool hash[N];
int n;

void small(int start, int j, int pre)
{//这里差不都是xwc的方法
    stack<int>s;
    int len1 = 0, len2 = 0;
    int tt = j;
    while(tt != start)
    {
        s.push(tt);
        tt = path[tt];
    }
    s.push(start);
    while(!s.empty())
    {
        c1[len1++] = s.top();
        s.pop();
    }
    s.push(j);
    //s.push(pre);
    tt = pre;
    while(tt != start)
    {
        s.push(tt);
        tt = path[tt];
    }
    s.push(start);
    while(!s.empty())
    {
        c2[len2++] = s.top();
        s.pop();
    }
    int min1 = min(len1 ,len2);
    for(int i = 0; i < min1; i++)
    {
        if(c1[i] == c2[i])
            continue;
        else if(c1[i] > c2[i])
            path[j] = pre;
        else 
            break;
    }
    //if()
    
}

void Dijsktra(int start, int end)
{
    int i, j, k;
    memset(hash, false, sizeof(hash));
    for(i = 1; i <= n; i++)
    {
        dis[i] = cost[start][i];
        path[i] = start;
        
    }
    dis[start] = 0;
    hash[start] = true;
    for(i = 1; i <= n; i++)
    {
        int d = MAX;
        k = start;
        for(j = 1; j <= n; j++)
        {
            if(!hash[j] && dis[j] < d)
            {
                k = j;
                d = dis[j];
            }
        }
        hash[k] = true;
        if( MAX == dis[k])
            break;
        for(j = 1; j <= n; j++)
        {
            if(!hash[j] && dis[j] > dis[k] + cost[k][j] + v[k] )
            {
                dis[j] = dis[k] + cost[k][j] + v[k];
                //if(k < path[j])
                path[j] = k;
                
            }//如果路劲相等输出字典序最小的
            else if(!hash[j] && dis[j] == dis[k] + cost[k][j] + v[k])
            {//这里没有加hash[j] 就在hdu oj wrong 在zoj就过了，忒假了
                small(start, j, k);
            }
        }
    }
    
    printf("From %d to %d :\n", start, end);
    stack <int> s;
    //s.push(end);
    //int tt = path[end];
    int tt = end;
    while(tt != start)
    {
        s.push(tt);
        tt = path[tt];
    }
    s.push(start);
    printf("Path: ");
    int e = s.top();
    s.pop();
    printf("%d", e);
    while(!s.empty())
    {
        int e = s.top();
        s.pop();
        printf("-->%d", e);
    }
    
    printf("\n");
    /*
     for(i = len ; i >= 0; i--)
     {
     if(i != 0)
     printf("%d-->", ctrl[i]);
     else
     printf("%d/n", ctrl[i]);
     }
     */
    //for(i = 1; i <= n; i++)
    //printf("%d ", path[i]);
    printf("Total cost : %d\n\n", dis[end]);
    
}

int main()
{
    //int df[N];
    while(scanf("%d", &n) != EOF && n)
    {
        int i, j, k;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &cost[i][j]);
                if(cost[i][j] == -1)
                    cost[i][j] = MAX;
            }
        for(i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        int a, b;
        while(1)
        {
            scanf("%d %d", &a, &b);
            if(a == -1 && b == -1)
                break;
            Dijsktra(a ,b);
        }
        
    }
    return 0;
}
/*#include <iostream>
using namespace std;
int map1[101][101],map2[101][101],tax[101];

int print(int s,int t)
{
    while (map2[s][t]!=t) {
        printf("-->%d",map2[s][t]);
        s=map2[s][t];
    }
    printf("-->%d\n",t);
    return 0;
}

int main()
{
    int n;
    while (cin >> n&&n) {
        int i,j,k,s,t;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++) {
                cin >> map1[i][j];
                map2[i][j]=j;
            }
        for (i=1; i<=n; i++)
            cin >> tax[i];
        for (k=1; k<=n; k++)
            for (i=1; i<=n; i++) {
                if (i==k||map1[k][i]==-1)
                    continue;
                for (j=1; j<=n; j++) {
                    if (map1[k][j]==-1||k==j||i==j)
                        continue;
                    if (map1[k][j]==-1||map1[i][j]>map1[i][k]+map1[k][j]+tax[k]) {
                        map1[i][j]=map1[i][k]+map1[k][j]+tax[k];
                        map2[i][j]=map2[i][k];
                    }
                    if (map1[i][j]==map1[i][k]+map1[k][j]+tax[k]&&map2[i][k]<map2[i][j])
                        map2[i][j]=map2[i][k];
                }
            }
        while (scanf("%d%d",&s,&t)) {
            if (s==-1&&t==-1)
                break;
            printf ("From %d to %d :\n",s,t);
            if (s==t)
                printf("Path: %d\n",s);
            else {
                printf ("Path: %d",s);
                print(s,t);
            }
            printf ("Total cost : %d\n\n",map1[s][t]);
        }
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;
const int inf=99999;
int n,map1[101][101],map2[101][101],tax[101];
int p[101],dis[101],v[101];

void ssort(int start, int j, int pre)
{
    stack<int>s;
    int len1=0, len2=0,path1[101]={0},path2[101]={0};
    int tt=j;
    while(tt!=start) {
        s.push(tt);
        tt=p[tt];
    }
    s.push(start);
    while(!s.empty()) {
        path1[len1++] = s.top();
        s.pop();
    }
    s.push(j);
    tt=pre;
    while(tt != start) {
        s.push(tt);
        tt=p[tt];
    }
    s.push(start);
    while(!s.empty()) {
        path2[len2++]=s.top();
        s.pop();
    }
    int min1=min(len1 ,len2);
    for(int i=0; i<min1; i++) {
        if(path1[i]==path2[i])
            continue;
        else if(path1[i]>path2[i])
            p[j] = pre;
        else 
            break;
    }
}

void dijk(int s)
{
    int i,j,min,lab,mind;
    for (i=1; i<=n; i++) {
        dis[i]=map2[s][i];
        v[i]=0;
        p[i]=s;
    }
    dis[s]=0;
    v[s]=1;
    for (i=2; i<=n; i++) {
        min=inf;
        lab=-1;
        for (j=1; j<=n; j++)
            if (!v[j]&&dis[j]<min) {
                min=dis[j];
                lab=j;
            }
        v[lab]=1;
        if (inf==dis[lab])
            break;
        for (j=1; j<=n; j++)
            if (!v[j]) {
                mind=dis[lab]+map2[lab][j];
                if (mind<dis[j]) {
                    dis[j]=mind;
                    p[j]=lab;
                }
                if (mind==dis[j])
                    ssort(s,j,lab);
            }
    }
}

int main()
{
    while (~scanf("%d",&n)&&n) {
        int i,j,s,t;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++) {
                cin >> map1[i][j];
                if (map1[i][j]==-1)
                    map1[i][j]=inf;
            }
        for (i=1; i<=n; i++)
            cin >> tax[i];
        while (scanf("%d%d",&s,&t)) {
            if (s==-1&&t==-1)
                break;
            memset(map2, 0, sizeof(map2));
            for (i=1; i<=n; i++)
                for (j=1; j<=n; j++)
                    if (j==s||j==t||i==j)
                        map2[i][j]=map1[i][j];
                    else map2[i][j]=map1[i][j]+tax[j];
            dijk(s);
            int sum=1,path[101]={0};
            path[sum]=t;
            int tmp=p[t];
            while (tmp!=s) {
                path[sum++]=tmp;
                tmp=p[tmp];
            }
            path[sum]=s;
            cout << "From " << s << " to " << t << " :\n";
            cout << "Path: ";
            for (i=sum; i>0; i--)
                cout << path[i] << "-->";
            cout << t << '\n';
            cout << "Total cost : " << dis[t] << "\n\n";
        }
    }
    return 0;
}
 Problem Description
 These are N cities in Spring country. Between each pair of cities there may be one transportation track or none. Now there is some cargo that should be delivered from one city to another. The transportation fee consists of two parts: 
 The cost of the transportation on the path between these cities, and
 
 a certain tax which will be charged whenever any cargo passing through one city, except for the source and the destination cities.
 
 You must write a program to find the route which has the minimum cost.
 
 
 Input
 First is N, number of cities. N = 0 indicates the end of input.
 
 The data of path cost, city tax, source and destination cities are given in the input, which is of the form:
 
 a11 a12 ... a1N
 a21 a22 ... a2N
 ...............
 aN1 aN2 ... aNN
 b1 b2 ... bN
 
 c d
 e f
 ...
 g h
 
 where aij is the transport cost from city i to city j, aij = -1 indicates there is no direct path between city i and city j. bi represents the tax of passing through city i. And the cargo is to be delivered from city c to city d, city e to city f, ..., and g = h = -1. You must output the sequence of cities passed by and the total cost which is of the form:
 
 
 Output
 From c to d :
 Path: c-->c1-->......-->ck-->d
 Total cost : ......
 ......
 
 From e to f :
 Path: e-->e1-->..........-->ek-->f
 Total cost : ......
 
 Note: if there are more minimal paths, output the lexically smallest one. Print a blank line after each test case.
 
 
 
 Sample Input
 5
 0 3 22 -1 4
 3 0 5 -1 -1
 22 5 0 9 20
 -1 -1 9 0 4
 4 -1 20 4 0
 5 17 8 3 1
 1 3
 3 5
 2 4
 -1 -1
 0
 
 
 Sample Output
 From 1 to 3 :
 Path: 1-->5-->4-->3
 Total cost : 21
 
 From 3 to 5 :
 Path: 3-->4-->5
 Total cost : 16
 
 From 2 to 4 :
 Path: 2-->1-->5-->4
 Total cost : 17