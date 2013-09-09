#include <iostream>
using namespace std;

typedef struct  {
    int x,y;
}tree;
tree a[3];

int main()
{
    int n,m;
    while (cin >> n >> m) {
        if (n==1&&m==1)
            return 0;
        a[0].x=0;a[0].y=1;
        a[1].x=1;a[1].y=1;
        a[2].x=1;a[2].y=0;
        while (a[1].x!=n||a[1].y!=m) {
            if (n*a[1].y-m*a[1].x>0) {
                cout << 'R';
                a[0]=a[1];
                a[1].x+=a[2].x;
                a[1].y+=a[2].y;
            }
            else {
                cout << 'L';
                a[2]=a[1];
                a[1].x+=a[0].x;
                a[1].y+=a[0].y;
            }
        }
        cout << '\n';
    }
    return 0;
}
/*
 The Stern-Brocot tree is a beautiful way for constructing the set of all non-negative fractions  where m and n are relatively prime. The idea is to start with two fractions  , and then repeat the following operation as many times as desired:
 
 Insert   between two adjacent fractions   and   .
 For example, the first step gives us one new entry between   and  ,
 
 ,,
 and the next gives two more:
 ,,,,
 The next gives four more:
 
 ,,,,,,,,
 The entire array can be regarded as an infinite binary tree structure whose top levels look like this-
 
 This construction preserves order, and thus we cannot possibly get the same fraction in two different places.
 
 We can, in fact, regard the Stern-Brocot tree as a number system for representing rational numbers, because each positive, reduced fraction occurs exactly once. Let us use the letters ``L'' and ``R'' to stand for going down the left or right branch as we proceed from the root of the tree to a particular fraction; then a string of L's and R's uniquely identifies a place in the tree. For example, LRRL means that we go left from   down to  , then right to  , then right to  , then left to  . We can consider LRRL to be a representation of  . Every positive fraction gets represented in this way as a unique string of L's and R's.
 
 Well, almost every fraction. The fraction   corresponds to the empty string. We will denote it by I, since that looks something like 1 and stands for ``identity."
 
 In this problem, given a positive rational fraction, represent it in the Stern-Brocot number system.
 
 Input
 
 The input file contains multiple test cases. Each test case consists of a line containing two positive integers m and n, where m and n are relatively prime. The input terminates with a test case containing two 1's for m and n, and this case must not be processed.
 Output
 
 For each test case in the input file, output a line containing the representation of the given fraction in the Stern-Brocot number system.
 Sample Input
 
 5 7
 878 323
 1 1
 Sample Output
 
 LRRL
 RRLRRLRLLLLRLRRR
*/