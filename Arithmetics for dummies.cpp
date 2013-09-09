#include <iostream>
using namespace std;

int main()
{
    int t,n,sum;
    cin >> t;
    while (t--) {
        if (t>=0)
            cout << '\n';
        char c;
        cin >> n;
        sum=n;
        while (1) {
            cin >> c;
            if (c=='=')
                break;
            cin >> n;
            if (c=='+')
                sum+=n;
            if (c=='-')
                sum-=n;
            if (c=='*')
                sum*=n;
            if (c=='/')
                sum/=n;
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 While browsing aimlessly, Peter stumbled upon an old riddle he used to solve on his calculator when he was still young. It was the kind of a riddle where you punch in a bunch of numbers and operators into a simple pocket calculator and then turn it upside down to get the answer: 
 These come in many different sizes but they are always exactly one foot long. Answer: 103 × 103 × 5.
 What are made of ice to keep people warm? Answer: 50 × 40 × 250 + 791.
 After a few minutes he found a large amount of such riddles and full of excitement he went to solve them. He turned his computer screen upside down…
 … only to find out that he does not have a reasonable calculator program installed on his computer. 
 You are given multiple sequences of button presses of a simple pocket calculator that consist of digits and arithmetic operators. For each such sequence find the number it would produce on a pocket calculator’s display.
 Note that the pocket calculator evaluates the operators in the order in which they are given. (I.e., there is no operator precedence.) Assume that the display of the calculator is large enough to show the result, and that its memory is sufficient to store all intermediate results. 
 
 Input
 The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.
 Each test case represents one sequence of button presses for a pocket calculator. The sequence consists of non-negative integers and arithmetic operators and ends with an equal sign. It may also contain spaces to improve readability.
 The operator / represents integer division, rounded down. You may assume that no test case contains division by zero and that in all test cases all intermediate results are non-negative.
 The easy data set only contains the operator +. 
 
 Output
 For each sequence from the input file output the number that would be displayed on the calculator. 
 
 Sample Input
 4
 
 1 + 1 * 2 =
 
 29 / 5 =
 
 103 * 103 * 5 =
 
 50 * 40 * 250 + 791 = 
 Sample Output
 4
 5
 53045
 500791
*/