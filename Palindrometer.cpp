#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    string a;
    while (cin >>a&&a!="0") {
        string b=a;
        int i,h=0,l=a.size()-1;
        while (h<l) {
            if (b[h]==b[l]) {
                h++;
                l--;
            }
            else {
                if (b[l]<b[h]) {
                    b[l]=b[h];
                    h++;
                    l--;
                }
                else {
                    b[l]=0;
                    for (i=l-1; i>=0; i--) {
                        if (b[i]=='9')
                            b[i]='0';
                        else {
                            b[i]=b[i]+1;
                            break;
                        }
                    }
                    h=0;
                    l=b.size()-1;
                }
            }
        }
        long long n,m;
        istringstream k(a+" "+b);
        k >> n >> m;
        cout << m-n << '\n';
    }
    return 0;
}
/*
 Problem description
 While driving the other day, John looked down at his odometer, and it read 100000. John was pretty excited about that. But, just one mile further, the odometer read 100001, and John was REALLY excited! You see, John loves palindromes — things that read the same way forwards and backwards. So, given any odometer reading, what is the least number of miles John must drive before the odometer reading is a palindrome? For John, every odometer digit counts. If the odometer reading was 000121, he wouldn’t consider that a palindrome.
 
 
 Input
 There will be several test cases in the data file, each consisting of an odometer reading on its own line. Each odometer reading will be from 2 to 9 digits long. The odometer in question has the number of digits given in the input - so, if the input is 00456, the odometer has 5 digits. There will be no spaces in the input, and no blank lines between input sets.
 The data file will end with a line with a single 0. 
 
 
 Output
 For each test case, output the minimum number of miles John must drive before the odometer reading is a palindrome. This may be 0 if the number is already a palindrome. Output each integer on its own line. 
 
 
 Sample Input
 100000
 100001
 000121
 00456
 0
 Sample Output
 1
 0
 979
 44
*/