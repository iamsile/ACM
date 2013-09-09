#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n--) {
        long long m,k;
        cin >> m;
        k=(long long)pow(2,m)-1;
        cout << k << '\n';
    }
    return 0;
}
/*
 Problem description
 I think most of us must know the Hanoi game.The game is very easy,there are three needle poles in the left,middle and right respectly.At first,some pans are laid in the left needle pole in order of size,the largest at bottom.What you need to do is to move all the pans from left to right.One rule is required,you can not move the big pan to the top of the small one.I think it’s also easy for you to calculate the least operations to done this. 
 
 
 Input
 First line is a number T denotes the testcase,the next T lines have one integer N which denotes the number of pans on the left needle pole. 
 
 
 Output
 For each testcase, output the least operations to move all the pans from left to right. 
 
 
 Sample Input
 2
 1
 2
 Sample Output
 1
 3
*/