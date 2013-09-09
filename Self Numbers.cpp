#include <iostream>
#define MAX 1000000
using namespace std;

unsigned int Selfsum(unsigned int Integer);
int main()
{
    bool visited[MAX+1];
    unsigned int tempsum;
    unsigned int i;
    for (i=1;i<MAX+1;i++)
        visited[i]=false;     
    for (i=1;i<MAX+1;i++)
    {
        tempsum=i;
        if (!visited[i])
        {
            while (tempsum<=MAX)
            {
                tempsum=tempsum+Selfsum(tempsum);
                if (tempsum<=MAX&&!visited[tempsum])
                    visited[tempsum]=true;
                else
                    break;
            }
        }
    }
	for (i=1;i<MAX+1;i++)
		if(!visited[i])
			cout << i << '\n';
    return 0;
}
unsigned int Selfsum(unsigned int Integer)
{
    unsigned int sum=0;
    while(Integer!=0)
    {
        sum=sum+Integer%10;
        Integer=Integer/10;
    }
    return sum;
}
/*
#include <iostream>
using namespace std;
const int maxm=1000000;
bool m[1000054];

int main()
{
    int i,temp,sum;
    memset(m, 0, sizeof(m));
    for (i=1; i<=maxm; i++) {
        temp=i;
        sum=i;
        while (temp>0) {
            sum+=(temp%10);
            temp/=10;
        }
        m[sum]=1;
    }
    for (i=1; i<=maxm; i++)
        if (!m[i])
            cout << i << '\n';
    return 0;
}
*/
/*
 Problem description
 In 1949 the Indian mathematician D.R. Kaprekar discovered a class of numbers called self-numbers. For any positive integer n, define d(n) to be n plus the sum of the digits of n. (The d stands for digitadition, a term coined by Kaprekar.) For example, d(75) = 75 + 7 + 5 = 87. Given any positive integer n as a starting point, you can construct the infinite increasing sequence of integers n, d(n), d(d(n)), d(d(d(n))), .... For example, if you start with 33, the next number is 33 + 3 + 3 = 39, the next is 39 + 3 + 9 = 51, the next is 51 + 5 + 1 = 57, and so you generate the sequence 33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ... The number n is called a generator of d(n). In the sequence above, 33 is a generator of 39, 39 is a generator of 51, 51 is a generator of 57, and so on. Some numbers have more than one generator: for example, 101 has two generators, 91 and 100. A number with no generators is a self-number. There are thirteen self-numbers less than 100: 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, and 97. 
 
 Input
 No input for this problem.
 
 Output
 Write a program to output all positive self-numbers less than 10000 in increasing order, one per line. 
 
 Sample Input
 no input
 Sample Output
 1
 3
 5
 7
 9
 20
 31
 42
 53
 64
 |
 |       <-- a lot more numbers
 |
 9903
 9914
 9925
 9927
 9938
 9949
 9960
 9971
 9982
 9993
*/