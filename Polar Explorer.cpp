#include<iostream>
using namespace std;

int main(){
    double x,y,z;
    char s[15];
    while(cin>>s&&s[3]!='O'){
		cin>>x>>y>>z>>s;
		y*=5;
        if(z>180)z=360-z;
		x*=(4*3.14159*(z/360));
        if(x>y)
			cout << "NO " << int(y) << endl;
        else{
			y-=x;
			cout << "YES " << int(y/5) << endl;
		}
	}
    return 0;
}
/*
#include "iostream.h"
#include "math.h"
#include "string.h"

#define MPG 5        //Miles per gallon
#define MOE .000001  //Margin of error (how close the float has to be
//to an integer to be considered equal)
#define PI 3.14159

int main(int argc, char* argv[])
{
    
	char token[30];
	int radius;  //Planet radius
	int fuel;    //Amount of fuel
	int angle;   //Angle of path
    
	double fuelNeeded;  //Amount of fuel needed to reach crash site
    
	cin >> token;
    
	while (strcmp(token,"ENDOFINPUT"))
	{
		cin >> radius;
		cin >> fuel;
		cin >> angle;
		if (radius < 1 || radius > 100)
		{
			cout << "Error: invalid radius -- " << radius << endl;
			break;
		}
		if (fuel < 0 || fuel > 100)
		{
			cout << "Error: invalid fuel -- " << fuel << endl;
			break;
		}
		if (angle < 0 || angle > 360)
		{
			cout << "Error: invalid angle -- " << angle << endl;
			break;
		}
        
		//If angle > 180, we want to go around the planet
		//the other way
		if (angle > 180)
			angle = 360 - angle;
        
		fuelNeeded = 2 * PI * radius * ((double) angle / 360) * 2 / MPG;
        
		if (fuel >= fuelNeeded || (fabs(fuel - fuelNeeded) <= MOE))
			cout << "YES " << (int) (fuel - fuelNeeded) << endl;
		else
			cout << "NO " << fuel * MPG << endl;
        
		cin >> token;
		cin >> token;
	}
    
	return 0;
}
*/
/*
圆半径为X，两地夹角为Z，每加仑汽油可以走Y，求能否往返于两地。
*/
/*
 Problem description
 You are a intrepid 2-dimensional explorer located at the northern polar reaches of a distant 2-dimensional planet. Unfortunately, you have been assigned to explore the most boring planet in the known universe (due primarily to your lack of social skills and aggressive body odor). Having a perfectly circular surface, your planet holds no surprises for a would-be explorer.
 However, you have recently received a distress call from an alien ship which has crash-landed somewhere on the surface of your planet. Unfortunately, you designed your own equipment, and the only information it will give you is an angle (measured from the center of the planet) separating you from the crash site. 
 
 Using this information along with how much gasoline is available for your planet-rover (which gets a measley 5 miles per gallon), you have to determine if you can possibly get to the crash site and back without running out of fuel. 
 
 
 Input
 Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be no blank lines separating data sets. A single data set has 3 components: 
 Start line - A single line, "START". 
 Input line - A single line, "X Y Z", where:
 X : (1 <= X <= 100) is the radius of your planet in integer miles 
 Y : (0 <= Y <= 100) is the amount of gasoline in your planet-rover in integer gallons 
 Z : (0 <= Z <= 360) is an angle separating you from the crash site in integer degrees 
 
 End line - A single line, "END". 
 Following the final data set will be a single line, "ENDOFINPUT". 
 Take note of the following: 
 The circumference of a circle in terms of its radius, r, is known to be 2πr 
 Assume that π = 3.14159 
 
 
 
 Output
 For each data set, there will be exactly one line of output. If you have enough fuel to get to the crash site and back, the line will read, "YES X", where X is the amount of fuel you will have left expressed as an integer number of gallons (truncate any fractional gallons). If you do not have sufficient fuel, the line will read, "NO Y", where Y is the distance you can travel expressed as an integer number of miles. 
 
 Sample Input
 START
 1 100 0
 END
 START
 10 0 1
 END
 START
 100 50 90
 END
 START
 100 50 270
 END
 ENDOFINPUT
 Sample Output
 YES 100
 NO 0
 NO 250
 NO 250
*/