#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
    float a,b,x,y;
    while(cin >> a >> b >> x >> y)
    {
        int temp;
        if(a==0&&b==0&&x==0&&y==0)
            return 0;
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        if(x<y)
        {
            temp=x;
            x=y;
            y=temp;
        }
        if(a>x&&b>y)
        {
            cout << "Escape is possible.\n";
            continue;
        }
        if(y>=b||x*x+y*y>a*a+b*b)
        {
            cout << "Box cannot be dropped.\n";
            continue;
        }
        else
        {
            float l,h;
            l=(a-sqrt(x*x+y*y-b*b))/2;
            h=(b-sqrt(x*x+y*y-a*a))/2;
            if(l*l+h*h>y*y)
                cout << "Escape is possible.\n";
            else
                cout << "Box cannot be dropped.\n";
        }
    }
    return 0;
}
/*
 Problem description
 金字塔中有一个房间名叫“无归之室”。房间地面完全由相同的矩形瓷砖覆盖。房间里布满无数的机关和陷阱，这正是其名字的由来。考古队花了几年时间研究对策，最后他们想出了一个方案。一台遥控的机器人将被送入房间，解除所有机关，然后返回。为了不触动机关，机器人必须走在瓷砖的中心区域上，绝对不能碰到瓷砖的边缘。如果走错一步，机器人会被落下的岩石砸成薄饼。
 
 当考古队正准备行动的时候，他们发现了一件可怕的事情：他们没有考虑到机器人携带的工具箱。由于机器人必须将工具箱放在地面上才能开始解除机关，工具箱不可碰到瓷砖的边缘。现在他们急需你编程判断工具箱可否放下。
 
 
 Input
 输入文件有多组数据组成。每组数据仅含一行A, B, X, Y (1<=A, B, X, Y<=50000，均为实数)。A, B为瓷砖的长和宽，X, Y为工具箱底面的长和宽（工具箱为长方体）。最后一组数据A=B=X=Y=0，标志文件结束，不需要处理。(长可以小于宽) 
 
 Output
 若工具箱能以某种方式放在地上，则输出”Escape is possible.”，否则输出”Box cannot be dropped.”。
 
 Sample Input
 10 10 8 8
 8 8 10 10
 4 4 4 5
 0 0 0 0
 Sample Output
 Escape is possible.
 Box cannot be dropped.
 Box cannot be dropped.
*/