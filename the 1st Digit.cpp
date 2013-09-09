#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
    int lab;
	cin >> lab;
	while (lab--) {
        double l,num;
		double k,a;
        double n,m;
        cin >> n >> m;
		k=m*log10(n);
		l=(int)k;
		a=k-l;
		num=(int)pow(10, a);
		cout << num << '\n';
		
	}
	return 0;
}
/*
 Problem description
 For two given non-negative integers a and p, calculate the first digit of ap counting from leftmost. For example, 212 = 4096, and the first digit is 4. It is guaranteed that the total length of ap never exceeds 200.
 
 Input
 The first line contains an integer t (0 < t < 500) which indicates the number of testcases, then followed t lines, each line contains two non-negative integers n, p.
 
 Output
 For each testcase, output the first digit of ap counting from leftmost in separate lines.
 
 Sample Input
 3
 2 12
 3 2
 125829111258291112582911 2
 Sample Output
 4
 9
 1
*/