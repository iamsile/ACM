#include <iostream>
using namespace::std;

int main()
{
    int m, r;
    while (cin >> m&&m){
        r = 1;
        while(m){
            if ((m&1)==1) break;
            m >>= 1;
            r <<= 1;
        }
        cout << r << '\n';
    }
    return 0;
}
/*
 Problem description
 Given an positive integer A (1 <= A <= 109), output the lowest bit of A. For example, given A = 26, we can write A in binary form as 11010, so the lowest bit of A is 10, so the output should be 2. Another example goes like this: given A = 88, we can write A in binary form as 1011000, so the lowest bit of A is 1000, so the output should be 8.
 
 Input
 Each line of input contains only an integer A (1 <= A <= 109). A line containing "0" indicates the end of input, and this line is not a part of the input data.
 
 Output
 For each A in the input, output a line containing only its lowest bit.
 
 Sample Input
 26
 8
 0
 Sample Output
 2
 8
*/