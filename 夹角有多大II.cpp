#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double k=180*acos((x1*x1+y1*y1+x2*x2+y2*y2-
                           (x1-x2)*(x1-x2)-(y1-y2)*(y1-y2))/(2*sqrt(x1*x1+y1*y1)*
                                                             sqrt(x2*x2+y2*y2)))/3.1415926;
        printf("%.2f\n",k);
    }
    return 0;
    
}
/*
 p=360*acos((a*a+b*b-c*c)/(2*a*b))/2/3.1415926;
cosA=(b^2+C^2-a^2)/2bc 　　cosb=(a^2+c^2-b^2)/2ac 　　cosC=(a^2+b^2-C^2)/2ab
 Problem Description
 这次xhd面临的问题是这样的：在一个平面内有两个点，求两个点分别和原点的连线的夹角的大小。
 
 注：夹角的范围[0，180]，两个点不会在圆心出现。
 
 
 Input
 输入数据的第一行是一个数据T，表示有T组数据。
 每组数据有四个实数x1,y1,x2,y2分别表示两个点的坐标,这些实数的范围是[-10000,10000]。
 
 
 Output
 对于每组输入数据，输出夹角的大小精确到小数点后两位。
 
 
 Sample Input
 2
 1 1 2 2
 1 1 1 0
 
 
 Sample Output
 0.00
 45.00

*/