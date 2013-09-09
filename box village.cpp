#include <iostream>
using namespace::std;

int main()
{
    int n;
    unsigned int a,b,c,d,e,f;
    cin >> n;
    while(n)
    {
        cin >> a >> b >> c >> d >> e;
        f=(a*b)/(c*d);
        if(e%f==0)
            cout << e/f << '\n';
        else 
            cout << e/f+1 << '\n';
        n--;
    }
    return 0;
}
/*
 Problem description
 Box Village offers storage facilities to the public. Anyone can store their stuff in one or more boxes for a small monthly fee per box. Because people in Western societies usually have lots of stuff, their services are very popular. Potential customers arrive almost daily with cartloads full of stuff they want to get rid of without throwing it away.
 Of course these customers want their stuff safely stored as cheaply as possible. However, nding the optimal way of packing a bunch of stuff into boxes is an NP-Hard problem. This gives Box Village a convenient excuse for not offering such an optimization service.
 Instead only rectangular items of the same size are allowed together in a box. So storing a collection of stray cats is okay (as long as they are rectangular), but storing both apples and bananas is not. Items are never rotated or stacked, and they are placed into the boxes from above.
 
 Input
 On the first line of the input is a positive integer, the number of test cases. Then for each test case:  A line with five positive integers d;w < 109, d1 <= d;w1 <= w and n < 105. The depth and width of each storage box, the depth and width of a single item and the number of items the customer wants to store, respectively.
 
 Output
 For each test case:  One line containing a single integer, the number of storage boxes used to store the cu tomer's stuff.
 
 Sample Input
 4
 100 100 10 10 500
 3 4 3 1 4
 25 25 5 5 25
 25 25 5 5 26
 Sample Output
 5
 1
 1
 2
*/