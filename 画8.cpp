#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        char a;
        int b,j,k,w;
        cin >> a >> b;
        w=b/6+1;
        for (j=0; j<b; j++)
            if (j==0||j==(b+1)/2-1||j==b-1) {
                for (k=0; k<w; k++)
                    cout << ' ';
                for (k=0; k<b/2-1; k++)
                    cout << a;
                cout << '\n';
            }
            else {
                for (k=0; k<w; k++)
                    cout << a;
                for (k=0; k<b/2-1; k++)
                    cout << ' ';
                for (k=0; k<w; k++)
                    cout << a;
                cout << '\n';
            }
        if (n)
            cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 谁画8画的好,画的快,今后就发的快,学业发达,事业发达,祝大家发,发,发.
 
 
 Input
 输入的第一行为一个整数N,表示后面有N组数据.
 每组数据中有一个字符和一个整数,字符表示画笔,整数(>=5)表示高度.
 
 
 Output
 画横线总是一个字符粗,竖线随着总高度每增长6而增加1个字符宽.当总高度从5增加到6时,其竖线宽度从1增长到2.下圈高度不小于上圈高度,但应尽量接近上圈高度,且下圈的内径呈正方形.
 每画一个"8"应空一行,但最前和最后都无空行.
 
 
 Sample Input
 2
 A 7
 B 8
 
 
 Sample Output
 AA
 AA  AA
 AA  AA
 AA
 AA  AA
 AA  AA
 AA
 
 BBB
 BB   BB
 BB   BB
 BBB
 BB   BB
 BB   BB
 BB   BB
 BBB
*/