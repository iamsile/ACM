#include <iostream>
using namespace std;
int a[15];

bool cal(int n,int m)//n代表每一边的人数,m代表所报的数
{
    int start=0,end=n-1,k,i;
    bool flag=true;
    for (i=2*n; i>n; i--) {//从头进行模拟
        k=(m-1)%i;//i代表剩余的人数
        if ((k<=end)&&(k>=start)) {
            flag=false;
            break;
        }
        start=((start-m)%i+i)%i;//按照那个编号变化公式重新进行赋值
        end=((end-m)%i+i)%i;//加上i，再%i的目的是保证它非零
    }
    return flag;
}

int main()
{
    int i,j,k,m,n;
    for (i=1; i<14; i++)
        for (j=i; ; j++)
            if (cal(i, j)) {
                a[i]=j;
                break;
            }
    while (cin >> n&&n) {
        cout << a[n] << '\n';
    }
    return 0;
}
/*
 Problem Description
 The Joseph\\\\\\\'s problem is notoriously known. For those who are not familiar with the original problem: from among n people, numbered 1, 2, . . ., n, standing in circle every mth is going to be executed and only the life of the last remaining person will be saved. Joseph was smart enough to choose the position of the last remaining person, thus saving his life to give us the message about the incident. For example when n = 6 and m = 5 then the people will be executed in the order 5, 4, 6, 2, 3 and 1 will be saved.
 
 Suppose that there are k good guys and k bad guys. In the circle the first k are good guys and the last k bad guys. You have to determine such minimal m that all the bad guys will be executed before the first good guy.
 
 
 Input
 The input file consists of separate lines containing k. The last line in the input file contains 0. You can suppose that 0 < k < 14.
 
 
 Output
 
 The output file will consist of separate lines containing m corresponding to k in the input file.
 
 
 Sample Input
 3
 4
 0
 
 
 Sample Output
 5
 30
*/