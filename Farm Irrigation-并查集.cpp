#include <iostream>
using namespace std;

const int maxn=3000;
struct node {
    int l,r,u,d;
}temp[12],num[maxn];

int p[maxn],r[maxn],map[60][60];

void init()
{
    int i;
    for (i=1; i<=11; i++)
        temp[i].l=temp[i].r=temp[i].u=temp[i].d=0;
    temp[1].l=1;temp[1].u=1;
    temp[2].r=1;temp[2].u=1;
    temp[3].l=1;temp[3].d=1;
    temp[4].r=1;temp[4].d=1;
    temp[5].u=1;temp[5].d=1;
    temp[6].l=1;temp[6].r=1;
    temp[7].l=1;temp[7].r=1;temp[7].u=1;
    temp[8].l=1;temp[8].u=1;temp[8].d=1;
    temp[9].l=1;temp[9].r=1;temp[9].d=1;
    temp[10].u=1;temp[10].r=1;temp[10].d=1;
    temp[11].l=1;temp[11].r=1;temp[11].u=1;temp[11].d=1;
}

int find(int x)
{
    while (x!=p[x])
        x=p[x];
    return x;
}

void Union(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if (x==y)
        return;
    if (r[x]>r[y])
        p[y]=x;
    else {
        p[x]=y;
        if (r[x]==r[y])
            r[y]++;
    }
}

int main()
{
    int n,m;
    init();
    while (~scanf("%d%d",&n,&m)) {
        if (n<0&&m<0)
            break;
        char c;
        int x=1,i,j,k,cnt;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) {
                cin >> c;
                k=c-'A'+1;
                map[i][j]=x;
                num[x].l=temp[k].l;
                num[x].r=temp[k].r;
                num[x].u=temp[k].u;
                num[x].d=temp[k].d;
                x++;
            }
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) {
                p[map[i][j]]=map[i][j];
                r[map[i][j]]=0;
            }
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) {
                if (num[map[i][j]].l==num[map[i][j-1]].r&&num[map[i][j]].l!=0&&j>1)
                    Union(map[i][j],map[i][j-1]);
                if (num[map[i][j]].r==num[map[i][j+1]].l&&num[map[i][j]].r!=0&&j+1<=m)
                    Union(map[i][j],map[i][j+1]);
                if (num[map[i][j]].u==num[map[i-1][j]].d&&num[map[i][j]].u!=0&&i>1)
                    Union(map[i][j],map[i-1][j]);
                if (num[map[i][j]].d==num[map[i+1][j]].u&&num[map[i][j]].d!=0&&i+1<=n)
                    Union(map[i][j],map[i+1][j]);
            }
        cnt=0;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
                if (find(map[i][j])==map[i][j])
                    cnt++;
        cout << cnt << '\n';
    }
}
/*
 Problem Description
 Benny has a spacious farm land to irrigate. The farm land is a rectangle, and is divided into a lot of samll squares. Water pipes are placed in these squares. Different square has a different type of pipe. There are 11 types of pipes, which is marked from A to K, as Figure 1 shows.
 
 
 
 Figure 1
 
 
 Benny has a map of his farm, which is an array of marks denoting the distribution of water pipes over the whole farm. For example, if he has a map 
 
 ADC
 FJK
 IHE
 
 then the water pipes are distributed like 
 
 
 
 Figure 2
 
 
 Several wellsprings are found in the center of some squares, so water can flow along the pipes from one square to another. If water flow crosses one square, the whole farm land in this square is irrigated and will have a good harvest in autumn. 
 
 Now Benny wants to know at least how many wellsprings should be found to have the whole farm land irrigated. Can you help him? 
 
 Note: In the above example, at least 3 wellsprings are needed, as those red points in Figure 2 show.
 
 
 Input
 There are several test cases! In each test case, the first line contains 2 integers M and N, then M lines follow. In each of these lines, there are N characters, in the range of 'A' to 'K', denoting the type of water pipe over the corresponding square. A negative M or N denotes the end of input, else you can assume 1 <= M, N <= 50.
 
 
 Output
 For each test case, output in one line the least number of wellsprings needed.
 
 
 Sample Input
 2 2
 DK
 HF
 
 3 3
 ADC
 FJK
 IHE
 
 -1 -1
 
 
 Sample Output
 2
 3
*/