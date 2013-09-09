#include <iostream>
using namespace std;

int main()
{
    unsigned n;
    while (cin >> n) {
        if(n<1)
        {
            cout<<"NO!\n";
            continue;
        }
        n+=1;
        while (n%2==0)
            n/=2;
        while (n%3==0)
            n/=3;
        if (n==1)
            cout << "YES!\n";
        else 
            cout << "NO!\n";
    }
    return 0;
}
/*
friend number=(a+1)*(b+1)-1;.........i式
因为a和b也是其他friend number,那么可设a=(c+1)*(d+1)-1;b=(e+1)*(f+1)-1;代入得：
friend number=(c+1)*(d+1)*(e+1)*(f+1)-1;........ii式
又因为c,d,e,f也是其他friend number，可以在设在代入，一直带到原始的friend number，1和2为止，可以得到friend number=（(1+1)^x）*((1+2)^y)-1;
friend number=(2^x)*(3^y)-1;(x,y>=0)；
也就是只要这个数 N 满足 N++后能被2整数得到一个整数X后继续能被3整数得到一个Y，那么这个数 N 就是friend number了；
 */
/*
 Problem description
 Friend numbers are defined recursively as follows.
 
 (1)numbers 1 and 2 are friend numbers;
 (2)if a and b are friend numbers,so is ab+a+b;
 (3)only the numbers defined in (1) and (2) are friend numbers.
 
 Now your task is to judge whether an integer is a friend number. 
 
 Input
 There are several lines in input files,each line has a nonnegative integer a,0≤a≤2^30. 
 
 Output
 For the number a on each line of the input file,if a is a friend number,output "YES!",otherwise output "NO!" 
 
 Sample Input
 3
 13121
 12131
 Sample Output
 YES!
 YES!
 NO!
*/