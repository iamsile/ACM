#include <iostream>
using namespace std;

int main()
{
    int i,j,n,m;
    for (i=100; i<999; i++)
        for (j=100; j<999; j++) {
            if (1.0*i/j==1)
                continue;
            n=i/10;
            m=j%100;
            if ((1.0*i/j==1.0*n/m)&&(i%10==j/100))
                printf("%d / %d = %d / %d\n",i,j,n,m);
        }
    return 0;
}
/*
 Problem description
 
 
 The wise Sir Bedavere often uses non-standard logic, yet achieves positive results . Well, it seems he has been at it again, this time with division. He has determined that canceling the common digit of a numerator and denominator produces the correct answer. Of course, Sir Bedavere only tried this on a small sample of three digit numbers. An example of what he did is shown in the following division problem (in which he canceled the common 6): 
 
 
 
 Your task is to find all three digit number combinations with the following property: 
 
 number combinations where removing the rightmost digit from the top number (numerator) and the identical leftmost digit from the bottom number (denominator) leaves the result of the calculation unchanged. 
 
 Omit all of the trivial cases — xxx/xxx = xx/xx (222/222 = 22/22). The solutions are to be shown in increasing order of the top number (the numerator). 
 
 Input
 NONE! There is no input for this problem.
 
 Output
 Show the bogus division problems one to a line in the format shown below (which gives a sample merely to show the format) — single spaces separate the non-blank characters.
 
 Sample Input
 NONE
 Sample Output
 217 / 775 = 21 / 75
 249 / 996 = 24 / 96
*/