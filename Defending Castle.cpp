#include <iostream>
#include <math.h>
using namespace::std;
typedef long long I;
I d, n;
I res;

int main()
{
    I low, high, x, temp;
    while(cin >> d >> n&&d&&n)
	{
        res=0;
        low=high=0; 
		x=d;
        while(x>1)
		{
            x=(d+high)/(high+1);
            if(x==1) 
				break;
            low=high+1;
            if(n<low) 
				break;
            temp=d/(x-1);
            if(temp*(x-1)==d)
                high=temp-1;
            else
                high=temp;
            if(n<=high)
                res+=(I)(n-low+1)*x;
            else
                res+=(I)(high-low+1)*x;
        }
        if(n>=d) 
			res+=(n-d+1);
        printf("%I64d\n", res);
    }
    return 0;
}
/*
 roblem description
 The kingdom Eintagra is in great danger! Overwhelming enemy has surrounded the emperor's castle and once they enter, a massacre is just what is going to be. 
 
 Now what all people in the kingdom Eintagra can rely on, is a huge catapult that can throw heavy rocks to the crowd of enemy. The catapult is so huge that it is too hard to adjust the direction it targets. So the damage it can do to the enemy is decreasing for every throw because the enemy in the targeted area are going to move away. If on the first attack it can make a certain damage, then on the second it can do only half, and 1/3 the damage on the third attack, and this holds, by estimation, that the K-th attack does 1/K damage of the first attack can do. People are optimistic so if the damage is not an integer, they round it up to the nearest bigger integer. 
 
 Given the damage of the first attack of the catapult and the life of the catapult, people need to know how much total damage the catapult can do to the enemy. 
 
 
 
 Input
 There are multiple test cases. Each contains two positive integers D and N in a single line, where D is the damage of the first attack of the catapult, and N is its life measured by the number of attacks it can make. D and N are both positive integers and not more than 2,000,000,000.
 
 Input ends with two zeros and this line should not be processed.
 
 Output
 Output a single line with an integer reporting the total damage that the catapult can do to the enemy. 
 
 Sample Input
 1 1
 2 3
 0 0
 Sample Output
 1
 4
*/