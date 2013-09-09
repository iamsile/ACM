#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int y,m,d,mm,n;
    int m1[13]={0,0,3,3,6,1,4,6,2,5,0,3,5};
             //   1 2 3 4 5 6 7 8 9 10 11 12
    while (cin >> y >> m >> d) {
        int y1=y-1+(y-1)/4-(y-1)/100+(y-1)/400;
        if (((y%4==0&&y%100!=0)||(y%400==0))&&m>2)
            mm=m1[m]+1;
        n=(y1+mm+d)%7;
        if (n==0)
            cout << "Sunday\n";
        else if (n==1)
            cout << "Monday\n";
        else if (n==2)
            cout << "Tuesday\n";
        else if (n==3)
            cout << "Wednesday\n";
        else if (n==4)
            cout << "Thursday\n";
        else if (n==5)
            cout << "Friday\n";
        else if (n==6)
            cout << "Saturday\n";
    }
    return 0;
}
/*按照年月日的格式输入今天的日期，计算和输出今天是星期几的信息
 计算公元0000至y-1年对7的余数y1；闰年的天数为366,对7的余数为2；
 平年的天数为365,对7的余数为1，公元0000至y-1年对7的余数总和为
 y1=y-1+(y-1)/4-(y-1)/100+(y-1)/400；
 计算今年1月至上月（m－1）的总天数对7的余数m1：
 0 上月1、10月；1上月为5月；2上月为8月；3上月为2,3,11月；
 4上月为6月；5上月为9,12月；6上月为4,7月;
*/