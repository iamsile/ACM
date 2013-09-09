#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    while (cin >> n&&n) {
        long long i,j,l,lab,k=(int)sqrt(n/4);
        if (n%4)
            continue;
        for (i=1; i<=k; i++)
            if ((n/4)%i==0)
                lab=i;
        j=(n/(4*lab))-lab;
        l=(n/(4*lab))+lab;
        j=j*j;
        l=l*l;
        cout << l << " - " << j << " = " << n << '\n';
    }
    return 0;
}
/*
 Problem description
 A perfect square is a positive integer of which the square root is also an integer, for example, 36 = 6 * 6.
 There exists a mathematical theorem stating that every multiple of 4 (greater than 4) can be decomposed into the difference of two perfect squares, that is, for every integer j≥2, let k = 4 * j. There then exists two perfect squares a and b such that k = 4 * j = a - b
 
 Note that there may be more than one pair a and b whose difference yields the desired value of k. Your task will be to find the first such pair, that is, the pair with the smallest possible value of a (subject, of course, to a and b being perfect squares).
 
 
 Your task is to, given a positive integer greater than or equal to 8,
 
 determine if it is a multiple of four
 if it is, print out the smallest pair of perfect squares such that their difference yields the desired number.
 For example, note that the number 40 can be decomposed as follows:
 
 49 - 9 = 40
 where, of course, 49 = 7 * 7, and 9 = 3 * 3. 
 
 Input
 Your input will be a list of line seperated positive integers. Some of them may not be multiples of 4. These should be ignored without generating any output.
 Note that the smallest input number will be 8, and your largest input number will be 232 - 1, or 4294967295. Input will be terminated by a value of 0. 
 
 
 Output
 Your output must be the equation listing the solution, of the form
 < a > - < b > = < k >
 where a, b are the two perfect squares, and k is the input value. 
 
 Sample Input
 40 
 0
 
 Sample Output
 49 - 9 = 40
*/