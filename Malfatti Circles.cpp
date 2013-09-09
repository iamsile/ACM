#include <iostream>
#include <math.h>
using namespace std;

double cal( double a, double b, double c, double d)
{
    double x=a-c,y=b-d;
    return sqrt(x*x+y*y);
}

double cal2( double a, double b, double c, double d)
{
    return a*d-b*c;
}
int main()
{
    double x1,x2,x3,y1,y2,y3,sa,sb,sc,s,r,aa,bb,cc,da,db,dc,r1,r2,r3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        if(!x1&&!y1&&!x2&&!y2&&!x3&&!y3)
            return 0;
        sa=cal(x2,y2,x3,y3);
        sb=cal(x1,y1,x3,y3);
        sc=cal(x1,y1,x2,y2);
        r=fabs(cal2((x2-x1),(y2-y1),(x3-x1),(y3-y1)))/(sa+sb+sc);
        s=(sa+sb+sc)/2;
        aa=(sb+sc-sa)/2;
        bb=(sa+sc-sb)/2;
        cc=(sa+sb-sc)/2;
        da=sqrt(aa*aa+r*r);
        db=sqrt(bb*bb+r*r);
        dc=sqrt(cc*cc+r*r);
        r1=(s-r-db-dc+da)*r/(2*(s-sa));
        r2=(s-r-da-dc+db)*r/(2*(s-sb));
        r3=(s-r-da-db+dc)*r/(2*(s-sc));
        printf("%.5f %.5f %.5f\n",r1,r2,r3);
    }
    return 0;
}
/*
 Problem description
 The configuration of three circles packed inside a triangle such that each circle is tangent to the other two circles and to two of the edges of the triangle has been studied by many mathematicians for more than two centuries. Existence and uniqueness of such circles for an arbitrary triangle are easy to prove. Many methods of numerical calculation or geometric construction of such circles from an arbitrarily given triangle have been discovered. Today, such circles are called the Malfatti circles. Figure 7 illustrates an example. The Malfatti circles of the triangle with the vertices (20, 80), (¡40, ¡20) and (120, ¡20) are approximately ² the circle with the center (24.281677, 45.219486) and the radius 21.565935, ² the circle with the center (3.110950, 4.409005) and the radius 24.409005, and ² the circle with the center (54.556724, 7.107493) and the radius 27.107493. Figure 8 illustrates another example. The Malfatti circles of the triangle with the vertices (20, -20), (120, -20) and (-40, 80) are approximately ² the circle with the center (25.629089, -10.057956) and the radius 9.942044, ² the circle with the center (53.225883, -0.849435) and the radius 19.150565, and ² the circle with the center (19.701191, 19.203466) and the radius 19.913790. Your mission is to write a program to calculate the radii of the Malfatti circles of the given triangles. 
 
 Input
 The input is a sequence of datasets. A dataset is a line containing six integers x1, y1, x2, y2, x3 and y3 in this order, separated by a space. The coordinates of the vertices of the given triangle are (x1, y1), (x2, y2) and (x3, y3), respectively. You can assume that the vertices form a triangle counterclockwise. You can also assume that the following two conditions hold. ² All of the coordinate values are greater than -1000 and less than 1000. ² None of the Malfatti circles of the triangle has a radius less than 0.1
 
 Output
 For each input dataset, three decimal fractions r1, r2 and r3 should be printed in a line in this order separated by a space. The radii of the Malfatti circles nearest to the vertices with the coordinates (x1, y1), (x2, y2) and (x3, y3) should be r1, r2 and r3, respectively. None of the output values may have an error greater than 0.0001. No extra character should appear in the output.
 
 Sample Input
 20 80 -40 -20 120 -20
 20 -20 120 -20 -40 80
 0 0 1 0 0 1
 0 0 999 1 -999 1
 897 -916 847 -972 890 -925
 999 999 -999 -998 -998 -999
 -999 -999 999 -999 0 731
 -999 -999 999 -464 -464 999
 979 -436 -955 -337 157 -439
 0 0 0 0 0 0
 Sample Output
 21.56593 24.40900 27.10749
 9.94204 19.15056 19.91379
 0.14885 0.20711 0.20711
 0.12513 0.49975 0.49975
 0.37346 0.38390 0.10046
 0.70677 0.35351 0.35351
 365.63802 365.63802 365.60104
 378.52409 378.60534 378.60534
 21.89580 22.05292 5.89571
*/