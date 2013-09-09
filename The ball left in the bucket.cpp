#include <iostream>
using namespace std;

int main()
{
    int t,m,n;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n%2)
            cout << "WhiteBall\n";
        else
            cout << "BlackBall\n";
    }
    return 0;
}
/*
 Problem description
 There is a bucket, and there are two kinds of balls in it.One is white, the other is black. 
 Now we define the rules: 
 1. You must take two but only two from the bucket unless the number of balls less than two; 
 2. If you take the two balls are the same color,you must put another black ball in the bucket; 
 3. If you take the two balls aren’t the same color, you must put another white ball in the bucket. 
 Now the question is simple,give you the number of the balls,after the above rules what kind of colors left in the bucket? 
 
 
 Input
 First line is a number T denotes the testcase,the next T lines have two numbers W and B each denotes the number of white balls and black balls in the bucket. 
 
 
 Output
 For each testcase, print a line that contains which color of balls will left in the bucket.If white ball lefts just puts WhiteBall, otherwise puts BlackBall. 
 
 
 Sample Input
 2
 1 1
 2 0
 Sample Output
 WhiteBall
 BlackBall
*/