#include<iostream>
using namespace std;
bool d[101][101];
int n,m,ans,a[101],b[101];

bool find(int x)
{
	int i,temp;
	for(i=1;i<=m;++i)
	{
		if((d[x][i])&&(!b[i]))
		{
            b[i]=true;
			temp=a[i];
            a[i]=x;
            if((temp==0)||(find(temp)))
            {
                return(true);
                break;
            }
            a[i]=temp;
		}
	}
	return(false);
}

int main()
{
	int i,j;
	char x;
    cin >> n;
    while(n)
    {
		cin >> m;
		memset(d,false,sizeof(d));
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
			{
				cin >> x;
				if(x=='1') d[i][j]=true;                  
			}
		ans=0;
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;++i)
		{
			memset(b,false,sizeof(b));
			if (find(i)) ++ans;
		}
		cout << ans << '\n';
		cin >> n;
    }    
    return(0);
}/*
#include <cstdio>
#include <cstdlib>
#include <memory>

const int N = 105;
int match[N];
char map[N][N];
bool vst[N];
int n, m;

bool dfs( int pos )
{
    for(int i = 0; i < m; i++)
    {
        if( map[pos][i] == '1' && !vst[i] )
        {
            vst[i] = 1;
            if( match[i] == -1 || dfs( match[i] ) )   
            { 
                match[i] = pos;            
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int i;
    while( scanf( "%d", &n ), n )
    {
        scanf( "%d", &m );
        for( i = 0; i < n; i++ )
            scanf( "%s", map[i] );
        int cnt = 0;
        for( i = 0; i < m; i++ )
            match[i] = -1;
        for( i = 0; i < n; i++ )
        {
            memset( vst, 0, sizeof( vst ) );
            if( dfs( i ) ) cnt++;    
        }
        printf( "%d\n", cnt );    
    }
    //system( "pause" );
    return 0;    
}*/
/*
 个人理解   0 [1] 0 1     [1]代表找到的点，然后以1为连接点，相邻之间的连线不能
		   ／ ［\］／       共用一个点，所以最后找到的线为[]的线，也就是最大匹配
		 [1] 0  1 0      而[1]就是找到最大匹配时所需要的最小的点
		  ［\］  
          0 1  0  0
                \
          0  1［-］[1]
 */
//我们以行和列做点，每扫描到一个1，就将其行与列的点连一条变。那么问题就转化成了二分图的最小覆盖的问题。可以证明最小覆盖等于最大匹配，所以，此题就非常简单了，用匈牙利算法就能轻松解决。
/*
 Problem description
 给定一个01矩阵(即矩阵中的元素仅为0或1)，每次操作可以选择某一行或某一列，将其中的1全部删除。 问最少必须进行多少次操作，才可以将01矩阵中所有的1全部删除。 
 
 Input
 输入可能包含多个测试数据，每个数据的第一行是两个用空格隔开的正整数m,n，其中2≤m,n≤100。 接下来的m行是一个m*n的01矩阵。 最后一行单独的一个0表示输入的结束。 
 
 Output
 对于每一组测试数据，输出一行只包含一个正整数，即删除所有的1所需的最少操作次数。 
 
 Sample Input
 4 4
 0101
 1010
 0100
 0101
 0
 Sample Output
 3
 *
 解题报告：
 二分图的最大匹配有两种求法，第一种是最大流（我在此假设读者已有网络流的知识）；
 第二种就是匈牙利算法。这个算法说白了就是最大流的算法，但是它跟据二分图匹配这
 个问题的特点，把最大流算法做了简化，提高了效率。匈牙利算法其实很简单。说穿了，
 就是你从二分图中找出一条路径来，让路径的起点和终点都是还没有匹配过的点，并且
 路径经过的连线是一条没被匹配、一条已经匹配过，再下一条又没匹配这样交替地出现。
 找到这样的路径后，显然路径里没被匹配的连线比已经匹配了的连线多一条，于是修改
 匹配图，把路径里所有匹配过的连线去掉匹配关系，把没有匹配的连线变成匹配的，这
 样匹配数就比原来多1个。不断执行上述操作，直到找不到这样的路径为止。 
 对于增广路径还可以用一个递归的方法来描述。这个描述不一定最准确，但是它揭示了
 寻找增广路径的一般方法： 
 “从点A出发的增广路径”一定首先连向一个在原匹配中没有与点A配对的点B。如果点B
 在原匹配中没有与任何点配对，则它就是这条增广路径的终点；反之，如果点B已与
 点C配对，那么这条增广路径就是从A到B，再从B到C，再加上“从点C出发的增广路径”。
 并且，这条从C出发的增广路径中不能与前半部分的增广路径有重复的点。
*/
/*
 Problem description
 给定一个01矩阵(即矩阵中的元素仅为0或1)，每次操作可以选择某一行或某一列，将其中的1全部删除。 问最少必须进行多少次操作，才可以将01矩阵中所有的1全部删除。 
 
 Input
 输入可能包含多个测试数据，每个数据的第一行是两个用空格隔开的正整数m,n，其中2≤m,n≤100。 接下来的m行是一个m*n的01矩阵。 最后一行单独的一个0表示输入的结束。 
 
 Output
 对于每一组测试数据，输出一行只包含一个正整数，即删除所有的1所需的最少操作次数。 
 
 Sample Input
 4 4
 0101
 1010
 0100
 0101
 0
 Sample Output
 3
*/