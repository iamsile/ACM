#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	double a,b,c,x,y,z;
	while(cin >> a >> b >>c)
	{
		
		x=a*sin(b)*cos(c);
		y=a*sin(b)*sin(c);
		z=a*cos(b);
		printf("(%.2f,%.2f,%.2f)\n",x,y,z);
	}
	return 0;
}
/*
 Problem description
 Spherical coordinates are important to physicists because they make certain problems alot easier (problems like finding the electric potential of a sphere. Much easier to do in spherical coordinates than in cartesian).
 In spherical coordinates, you have 3 quantities:
 
 r -- radial distance from the origin to a point on the sphere.
 theta -- (sorry, some terminals can't display the character right, so I'm explicitly writing it) the angle from the z axis to the radial line from the origin to the point on a sphere.
 phi -- angle in the xy plane from the x axis over to the radial from the origin to the point on the sphere.
 These quantities can describe any point on any sphere.
 Every now and then, it's useful to convert spherical over to cartesian. This can be done by:
 
 x = r sin (theta) cos (phi)
 y = r sin (theta) sin (phi)
 z = r cos (theta)
 In this problem you'll be given, r, theta and phi and will have to convert them over to x, y, and z. 
 
 Input
 Each line of input contains one test case. The numbers for r, theta and phi will be on the line, in that order, separated by a space. Each quantity will be a real number out to at least 4 digits of precision. theta and phi are specified in radians. 
 
 Output
 for each line of input, print a line saying:
 (x, y, z)
 (parentheses required). where x, y, and z are the cartesian equivalents of the given quantities. x, y and z should be rounded to 2 decimal places. 
 
 
 Sample Input
 4.4450 1.57079632 0.0000
 0.0000 0.0000 0.0000
 4.4450 1.57079632 1.57079632
 1.0000 0.987323 0.23332
 Sample Output
 (4.45,0.00,0.00)
 (0.00,0.00,0.00)
 (0.00,4.45,0.00)
 (0.81,0.19,0.55)
*/