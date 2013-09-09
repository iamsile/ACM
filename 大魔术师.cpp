#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,n,j,k,x,y,a[1010],b[1010];
        cin >> n;
        for (i=1; i<=n; i++) {
            cin >> a[i];
            b[i]=-100;
        }
        for (i=1,j=1,k=n; i<=n; i++,k--) {
            x=i%k;
            y=0;
            if (!x)
                x=k;
            while (1) {
                if (j>n)
                    j=1;
                if (b[j]<0)
                    y++;
                if (x==y) {
                    b[j]=a[i];
                    break;
                }
                j++;
            }
        }
        for (i=1; i<=n; i++) {
            if (i>1)
                cout << ' ';
            cout << b[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
#include<stdio.h>
#include<string.h>
int as[1005],bs[1005],n;
int fun(int k,int x)
{
    int i=x,j=1;
    while(j<k){
        ++i;
        if( i>n ) i=1;
        if(!as[i]) j++;
    }
    return i;
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for( i=1; i<=n; i++ )scanf("%d",bs+i);
        memset(as,0,sizeof(as));
        j=1; k=n;
        for( i=1; i<n; i++,k-- ){
            int tp=i%k; //tp为从j开始的空位后，第tp个就是i要插入的值了。
            if( !tp ) tp=k;
            j=fun(tp,j);//从j开始，找第tp个空位
            as[j]=i;
            
            while(1){//寻找下一个空位
                if(!as[j])break;
                j++;
                if(j>n)j=1;
            }
        }
        as[j]=i;
        for(i=1; i<n; i++ )printf("%d ",bs[as[i]]);
        printf("%d\n",bs[as[i]]);
    }return 0;
}
*/
/*
 Problem description
 
 LittleMing刚刚看了《大魔术师》这部电影，他对魔术产生了浓厚的兴趣。于是，他决定向大魔术师BigMing学习魔术。
 今天，BigMing要教给LittleMing的魔术是这样的：道具是13张黑桃扑克A,2,3,4,5,6,7,8,9,10,J,Q,K。这13张牌预先排好，正面朝下，拿在魔术师的手里，从上面开始，第一次数一张牌翻过来放在桌面上，正好是A；第二次数两张牌，数1的那张放在手中扑克的下面，数2的那张翻过来放在桌面上正好是2；……如此下去，放在桌面上的牌最后正好是A,2,3,4,5,6,7,8,9,10,J,Q,K的顺序（从下往上）。
 LittleMing立马发现这个魔术的关键就在预先必须安排好13张牌的顺序，所以他很快掌握的这个魔术。现在他想把这个魔术的难度加大：假设有N张牌，这N张牌依次标有1~N这N个数。魔术师表演时，将挑选一位观众随便写下1~N的一个排列（假设为x[1..n]）。这时魔术师应该通过安排这N张牌的顺序，使得
 （1）第一次数一张牌翻过来放在桌面上，正好是x[1] ；
 （2）第二次数两张牌，数1的那张放在手中扑克下面，数2的那张翻过来放在桌面上正好是x[2];
 ……
 （3）第i次数i张牌，数1的放在手中扑克下面，数2的放在手中扑克下面，……，数i-1的放在手中扑克下面，数i的那张翻过来放在桌面上正好是x[i];
 ……
 最终，魔术师亮出的牌的顺序将和x[1..n]这个排列相同。
 现在，关键的问题是，魔术师应怎样安排这N张牌的顺序，才能使亮他出的牌的顺序将和x[1..n]这个排列相同? 
 
 Input
 第一行一个数CaseNumber，表示测试数据的组数。
 对每组测试数据：
 第一行一个整数N（N<=1000）。
 接下来一行表示有N个数，表示一个排列。
 
 Output
 对每个测试数据，输出魔术师应该安排的N张牌的排列，使得他按上述规则亮出的牌的顺序将和x[1..n]这个排列相同，每个两个数之间一个空格，最后一个数后没有空格。
 
 Sample Input
 3
 13
 1 2 3 4 5 6 7 8 9 10 11 12 13
 3
 1 2 3
 3
 3 2 1
 Sample Output
 1 8 2 5 10 3 12 11 9 4 7 6 13
 1 3 2
 3 1 2
*/