#include <iostream>
using namespace::std;

int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{
		double x5=0,y5=0;
		if(x1==x3&&y1==y3)
		{
			x5=x4-x3+x2;
			y5=y4-y3+y2;
		}
		else if(x1==x4&&y1==y4)
		{
			x5=x2-x1+x3;
			y5=y2-y1+y3;
		}
		else if(x2==x4&&y2==y4)
		{
			x5=x1-x2+x3;
			y5=y1-y2+y3;
		}
		else if(x2==x3&&y2==y3)
		{
			x5=x1-x2+x4;
			y5=y1-y2+y4;
		}
		printf("%4.3f %4.3f\n",x5,y5);
	}
	return 0;
}
/*
 Problem description
 Given are the (x,y) coordinates of the endpoints of two adjacent sides of a parallelogram. Find the (x,y) coordinates of the fourth point.
 
 Input
 Each line of input contains eight floating point numbers: the (x,y) coordinates of one of the endpoints of the first side followed by the (x,y) coordinates of the other endpoint of the first side, followed by the (x,y) coordinates of one of the endpoints of the second side followed by the (x,y) coordinates of the other endpoint of the second side. All coordinates are in meters, to the nearest mm. All coordinates are between -10000 and +10000. 
 
 Output
 For each line of input, print the (x,y) coordinates of the fourth point of the parallelogram in meters, to the nearest mm, separated by a single space. 
 
 Sample Input
 0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
 1.000 0.000 3.500 3.500 3.500 3.500 0.000 1.000
 1.866 0.000 3.127 3.543 3.127 3.543 1.412 3.145
 Sample Output
 1.000 0.000
 -2.500 -2.500
 0.151 -0.398
*/