#include <iostream>
#include <queue>
using namespace std;

typedef struct node
{
    int data;
    friend bool operator<(node a,node b)
    {
        return a.data > b.data;
    }
    
}Point;

int main()
{
    priority_queue<node> Q;
	int n , sum;
    Point v , a , b , x;
    while(scanf("%d" ,&n)!=EOF)
    {
		sum=0;
		while(n--)
		{
			scanf("%d",&v.data);
			Q.push(v);
		}
		while(!Q.empty())
		{
            a=Q.top();
            Q.pop();
            b=Q.top();
            Q.pop();
            x.data=a.data+b.data;
            sum+=x.data;
            if(!Q.empty())
				Q.push(x);
		}
		printf ("%d\n" ,sum);
		while (!Q.empty())
		{
			Q.pop();
		}
    }
    return 0;
}
/*#include <iostream>
 using namespace::std;
 
 int cmp(const void *a,const void *b)
 {
 return *(int *)a-*(int *)b;
 }
 
 int main()
 {
 long int n,i,k,a[100010]={0},sum=0;
 cin >> n;
 for(i=0;i<n;i++)
 cin >> a[i];
 qsort(a, n, sizeof(a[0]), cmp);
 for(i=1;i<n;i++)
 {
 k=a[i]+a[i-1];
 a[i]=k;
 if(a[i]>a[i+1])
 sort(a+i,a+n);
 sum+=k;
 }
 cout << sum << '\n';
 return 0;
 }超时的算法
 */
/*
 Problem description
 在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。 
 每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过n-1次合并之后，就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
 
 因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为1，并且已知果子的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
 
 例如有3种果子，数目依次为1，2，9。可以先将 1、2堆合并，新堆数目为3，耗费体力为3。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为12，耗费体力为 12。所以多多总共耗费体力=3+12=15。可以证明15为最小的体力耗费值。
 
 Input
 输入包括两行，第一行是一个整数n（1 <= n <= 10000），表示果子的种类数。第二行包含n个整数，用空格分隔，第i个整数ai（1 <= ai <= 20000）是第i种果子的数目。
 
 Output
 输出包括一行，这一行只包含一个整数，也就是最小的体力耗费值。输入数据保证这个值小于2的31次方。
 
 Sample Input
 3
 1 2 9
 Sample Output
 15
*/