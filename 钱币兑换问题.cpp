#include <iostream>
using namespace std;

int main()
{
    int n,i,j,k,c1[40000],c2[40000];
    for (i=0; i<=32768; i++) {
        c1[i]=1;
        c2[i]=0;
    }
    for (i=2; i<=3; i++) {
        for (j=0; j<=32768; j++)
            for (k=0; k+j<=32768; k+=i)
                c2[j+k]+=c1[j];
        for (j=0; j<=32768; j++) {
            c1[j]=c2[j];
            c2[j]=0;
        }
    }
    while (cin >> n) {
        cout << c1[n] << '\n';
    }
    return 0;
}
/*
 Font Size: ← →
 Problem Description
 在一个国家仅有1分，2分，3分硬币，将钱N兑换成硬币有很多种兑法。请你编程序计算出共有多少种兑法。
 Input
 每行只有一个正整数N，N小于32768。
 Output
 对应每个输入，输出兑换方法数。
 Sample Input
 2934
 12553
 Sample Output
 718831
 13137761
*/