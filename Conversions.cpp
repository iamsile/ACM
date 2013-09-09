#include <iostream>
using namespace::std;

int main()
{
    double t,flag=1;
    cin >> t;
    while (t--) 
    {
        char c[2];
        double n,num;
        cin >> n >> c;
        cout << flag++ << ' ';
        if (c[0]=='k') {
            num=n*2.2046;
            printf("%.4f lb\n",num);
        }
        if (c[1]=='b')
        {
            num=n*0.4536;
            printf("%.4f kg\n",num);
        }
        if (c[0]=='l'&&c[1]!='b')
        {
            num=n*0.2642;
            printf("%.4f g\n",num);
        }
        if (c[0]=='g')
        {
            num=n*3.7854;
            printf("%.4f l\n",num);
        }
    }
    return 0;
}
/*
 Problem description
 Conversion between the metric and English measurement systems is relatively simple. Often, it involves either multiplying or dividing by a constant. You must write a program that converts between the following units:
 
 Type	Metric	English equivalent
 Weight	 1.000 kilograms	 2.2046 pounds
 0.4536 kilograms	 1.0000 pound
 Volume	 1.0000 liter	 0.2642 gallons
 3.7854 liters	 1.0000 gallon
 
 
 Input
 The first line of input contains a single integer N, (1 ≤ N ≤ 1000) which is the number of datasets that follow.
 
 Each dataset consists of a single line of input containing a floating point (double precision) number, a space and the unit specification for the measurement to be converted. The unit specification is one of kg, lb, l, or g referring to kilograms, pounds, liters and gallons respectively.
 
 Output
 For each dataset, you should generate one line of output with the following values: The dataset number as a decimal integer (start counting at one), a space, and the appropriately converted value rounded to 4 decimal places, a space and the unit specification for the converted value.
 
 Sample Input
 5
 1 kg
 2 l
 7 lb
 3.5 g
 0 l
 Sample Output
 1 2.2046 lb
 2 0.5284 g
 3 3.1752 kg
 4 13.2489 l
 5 0.0000 g
*/