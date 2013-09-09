#include <iostream>
using namespace std;
int a[2][13]={{0,31,59,90,120,151,181,212,243,273,304,334,365},
	{0,31,60,91,121,152,182,213,244,274,305,335,366}};
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int y,m,d,lab,sum=0;
        cin >> y >> m >> d;
        if (y%400==0||(y%4==0&&y%100!=0))
            lab=1;
        else lab=0;
        if (m>=1&&m<=12) {
            sum=a[lab][m-1];
            if (a[lab][m-1]+d<=a[lab][m]&&d>0)
                sum+=d;
            else sum=0;
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 
 
 输入某年某月某日，判断这一天是这一年的第几天？
 
 Input
 
 第一行输入一个整数T，表示是下面有T行，接下来每一行包含三个整数Y，M，D，分别表示年月日，中间用空格隔开。
 
 Output
 
 针对每一组数据输出一行，该行包含一个整数D，表示对应的日期是该年的第D天，如果不是一个合法的日期，则输出0.
 
 Sample Input
 2
 2009 1 1
 2009 2 30
 Sample Output
 1
 0
*/