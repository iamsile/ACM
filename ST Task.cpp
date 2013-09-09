#include <iostream>
#include <math.h>

int main()
{
	double n,m;
	int k,z,i=0,j;
	scanf("%lf%lf",&n,&m);
	while(i*m<=180)
	{
		if(i*m<=90)
		{   
			k=(int)(n*cos(((i*m)/180)*3.14159265358979)+0.50000);
			z=n-k;
			for(j=0;j<z;j++)
				printf("S");
			for(j=0;j<k;j++)
				printf("T");
			for(j=0;j<n;j++)
				printf("S");
			printf("  %.5lf\n",cos(((i*m)/180)*3.14159265358979)/2);
		}
		else
		{
			k=(int)(n*cos(((180-(i*m))/180)*3.14159265358979)+0.50000);
			z=k;
			for(j=0;j<n;j++)
				printf("S");
			for(j=0;j<z;j++)
				printf("T");
			for(j=z;j<n;j++)
				printf("S");
			printf("  %.5lf\n",cos(((180-i*m)/180)*3.14159265358979)/2);
		}
		i++;
	}
	return 0;
}
/*
 Problem description
 You get a ST task, that is: given a stick one end of who is moored on the ground, you are asked to turn over the stick by holding the other end. When it reaches the ground again, the task is finished. It is true that on the process, the stick is always on the same plane vertical the ground. And on this plane, there is light from up to down, so that we can see on the ground a line of shadow. Look at the picture:
 
 
 In order to express the shadow part and the un-shadow (light space) part, to simple the problem we just need to express the length that 2 times of the length of the stick where the shadow may occur. 
 Now, give the problem: the stick on the beginning is on the left of the moored point, and we turn it on certain angular speed, using a ‘S’ to denote one unit of the light space and a ‘T’ for one unit of the shadow line. Beside that, a real number is needed to tell the scale between the shadow line and the full line where shadow may be.
 
 
 Input
 There is only one case. Two integers L (0 < L ≤ 25) and V (0 < V ≤ 90) is given.
 L is the length of the stick; V is the angular speed of the turning task, in angle per second
 
 
 Output
 For every second during the task, you are asked to tell the shape of the shadow on the ground. See the sample: ‘S’ for the light space and ‘T’ for the shadow.
 
 
 Sample Input
 25 15
 Sample Output
 TTTTTTTTTTTTTTTTTTTTTTTTTSSSSSSSSSSSSSSSSSSSSSSSSS  0.50000
 STTTTTTTTTTTTTTTTTTTTTTTTSSSSSSSSSSSSSSSSSSSSSSSSS  0.48296
 SSSTTTTTTTTTTTTTTTTTTTTTTSSSSSSSSSSSSSSSSSSSSSSSSS  0.43301
 SSSSSSSTTTTTTTTTTTTTTTTTTSSSSSSSSSSSSSSSSSSSSSSSSS  0.35355
 SSSSSSSSSSSSTTTTTTTTTTTTTSSSSSSSSSSSSSSSSSSSSSSSSS  0.25000
 SSSSSSSSSSSSSSSSSSSTTTTTTSSSSSSSSSSSSSSSSSSSSSSSSS  0.12941
 SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS  0.00000
 SSSSSSSSSSSSSSSSSSSSSSSSSTTTTTTSSSSSSSSSSSSSSSSSSS  0.12941
 SSSSSSSSSSSSSSSSSSSSSSSSSTTTTTTTTTTTTTSSSSSSSSSSSS  0.25000
 SSSSSSSSSSSSSSSSSSSSSSSSSTTTTTTTTTTTTTTTTTTSSSSSSS  0.35355
 SSSSSSSSSSSSSSSSSSSSSSSSSTTTTTTTTTTTTTTTTTTTTTTSSS  0.43301
 SSSSSSSSSSSSSSSSSSSSSSSSSTTTTTTTTTTTTTTTTTTTTTTTTS  0.48296
 SSSSSSSSSSSSSSSSSSSSSSSSSTTTTTTTTTTTTTTTTTTTTTTTTT  0.50000
 */