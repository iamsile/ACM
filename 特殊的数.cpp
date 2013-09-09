#include <iostream>
#include <bitset>
using namespace std;

bitset<1000001> bits;
bitset<1000001> bits_assit;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        bits.reset();
        bits_assit.reset();
        int i,temp,count=0;
        for (i=0; i<n; i++) {
            cin >> temp;
            if (!bits_assit[temp]) {
                bits.set(temp);
                bits_assit.set(temp);
                count++;
            } else if (bits_assit[temp]) {
                if (bits[temp]) {
                    bits.reset(temp);
                    count--;
                }
            }
        }
        bool first_time=true;
        cout << count << '\n';
        if (!count)
            continue;
        for (i=1; i<=1000000; i++) {
            if (bits[i]) {
                if (first_time)
                    first_time=false;
                else putchar(' ');
            }
            count << i;
        }
        cout << '\n';
    }
    return 0;
}
/*
 题目描述：
 现在有n个数，其中有一些出现了一次，一些出现了两次，一些出现了很多次。现在要求你找出那些只出现一次的数，并按升序输出。
 输入：
 本题有多组case。
 每个case有两行，第一行输入一个n，表示有n个数，1<= n <= 1000000。
 第二行有n个数字。每个数字的大小范围[1, 1000000]。
 输出：
 每次输出有两行。
 第一行输出一个整数，表示出现一次的数的个数。
 第二行按升序输出出现次数为一次的数字，两个数字之间用空格隔开。
 样例输入：
 5
 1 2 2 3 3
 7
 1 2 2 3 4 4 2
 2
 2 2
 样例输出：
 1
 1
 2
 1 3
 0
*/