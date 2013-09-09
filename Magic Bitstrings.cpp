#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    while (cin >> n&&n) {
        if (n==2) {
            cout << "Impossible\n";
            continue;
        }
        vector<int> a(n,1);
        long long i;
        for (i=1; i<n; i++)
            a[i*i%n]=0;
        for (i=1; i<n; i++)
            cout << a[i];
        cout << '\n';
    }
    return 0;
}
/*
 把矩阵列出来
 
 a[1%n], a[2%n], a[3%n], ..., a[n-1]                  (1)
 
 a[2%n], a[4%n], a[6%n], ..., a[2(n-1)%n]       (2)
 
 a[3%n], a[6%n], a[9%n], ..., a[3(n-1)%n]       (3)
 
 ...
 
 
 比较 (1), (2)
 
 发现：
 
 如果 a[1%n] != a[2%n]，那么 a[2%n] != a[4%n]，那么 a[1%n] == a[4%n]；
 
 如果 a[1%n] == a[2%n]，那么 a[2%n] == a[4%n]，那么 a[1%n] == a[4%n]。
 
 所以 a[1%n] == a[4%n]
 
 同样的方法得到：
 
 a[1%n] == a[9%n],
 
 a[1%n] == a[16%n],
 
 ....
 
 所有下标是 i 平方 mod n 都相等。
 
 下标不是 i 平方 mod n 都相等。
 
 
 为了字典顺序最小，并且避免整个数列都是同一个数（题目要求 non-constant），令 a[1%n] = a[4%n] = a[9%n] = ... = 0，其他数都是 1，这样符合题意。
 Problem Description
 A bitstring, whose length is one less than a prime, might be magic. 1001 is one such string. In order to see the magic in the string let us append a non-bit x to it, regard the new thingy as a cyclic string, and make this square matrix of bits 
 
 each bit 1001 
 every 2nd bit 0110 
 every 3rd bit 0110 
 every 4th bit 1001 
 
 This matrix has the same number of rows as the length of the original bitstring. The m-th row of the matrix has every m-th bit of the original string starting with the m-th bit. Because the enlarged thingy has prime length, the appended x never gets used. 
 
 If each row of the matrix is either the original bitstring or its complement, the original bitstring is magic. 
 
 Each line of input (except last) contains a prime number p ≤ 100000. The last line contains 0 and this line should not be processed. For each prime number from the input produce one line of output containing the lexicographically smallest, non-constant magic bitstring of length p-1, if such a string exists, otherwise output Impossible. 
 
 
 Sample Input
 5
 3
 17
 47
 2
 79
 0
 
 
 Sample Output
 0110
 01
 0010111001110100
 0000100001101010001101100100111010100111101111
 Impossible
 001001100001011010000001001111001110101010100011000011011111101001011110011011
*/