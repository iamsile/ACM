#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	double x,y,c,l,r,w;
	while(cin >> x >> y >> c)
	{
		l=0;
		r=x>y?y:x;
		while(l+(1e-10)<r)
		{
			w=(l+r)/2;
			if((c/sqrt(x*x-w*w)+c/sqrt(y*y-w*w))<=1)
				l=w;
			else 
				r=w;
		}
		printf("%.3f\n",l);
	}
	return 0;
}
/*
 Problem description
 A narrow street is lined with tall buildings. An x foot long ladder is rested at the base of the building on the right side of the street and leans on the building on the left side. A y foot long ladder is rested at the base of the building on the left side of the street and leans on the building on the right side. The point where the two ladders cross is exactly c feet from the ground. How wide is the street? 
 
 
 Input
 Each line of input contains three positive floating point numbers giving the values of x, y, and c. 
 
 Output
 For each line of input, output one line with a floating point number giving the width of the street in feet, with three decimal digits in the fraction. 
 
 Sample Input
 30 40 10
 12.619429 8.163332 3
 10 10 3
 10 10 1
 Sample Output
 26.033
 7.000
 8.000
 9.798
*/