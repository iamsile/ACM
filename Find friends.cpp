#include <iostream>
using namespace std;

int main()
{
    unsigned n,i,sum;
    while (cin >> n&&n!=-1) {
        sum=n;
        for(i=2;i<10010&&n>=i;++i){
            if(n%i==0){
                sum=sum/i*(i-1);
                while(n%i==0)n/=i;
            }
        }
        if(n>1)sum=sum/n*(n-1);
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 Due to some reasons, Tom goes to a new school. There are many students in Tom's new school, they numbered from 1 to n-1 and Tom numbered n.One day Tom wants to elect some of the students to make friends,and they must meet the following conditions : The number of the students must be relatively prime to Tom's number. We define that one number is relatively prime to another one if and only if the Great Common Divisor (GCD) is 1.For instance, 1, 3, 5, 7, 9...are all relatively prime to 1003. Give you an integer n(the number of Tom).(2<=n<=100000000),Now your task is to calculate the number of students can be elected by Tom to do his friends. 
 
 Input
 The first line of input contains a single integer n, (2<= n<= 100000000). The end-of-file is denoted by a single line containing the number -1. 
 
 Output
 For each testcase, there is to be one line of output consisting of the numbers of Tom's friends.
 
 Sample Input
 10
 12
 15
 -1
 Sample Output
 4
 4
 8
*/