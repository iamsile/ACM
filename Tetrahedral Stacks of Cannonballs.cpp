#include<stdio.h>

int main()
{
    long long t,n,k,ans;
    scanf("%I64d",&t);
    k=0;
    while(t--)
    {
        k++;
        scanf("%I64d",&n);
        ans = (n*(n+1)*(2*n+1)/6 + n*(n+1)/2)/2;
        printf("%I64d: %I64d %I64d\n",k,n,ans);
    }
    return 0;
}
/*
 Problem description
 
 WALL ,as he cleans up and organizes the depopulated Earth, has come upon some Civil War memorials. He is consolidating the cannonballs into one location, and decides to use pyramids with triangular bases rather than ones with square bases.
 In Civil War memorials with cannons and stacks of cannonballs, the cannonballs were sometimes stacked as a four-sided pyramid, with the base as a square of cannonballs with n balls on each side. An alternative is to stack them in a three-sided pyramid, which is in fact one of the Platonic solids, a tetrahedron.
 This tetrahedron of cannonballs has a base that is an equilateral triangle of cannonballs with n balls on each side. The number of balls in that triangle is given simply by adding together the numbers from 1 to n. On top of each layer (starting from the base) is a triangle with one less ball on each side, up to the top-most layer with a single ball.
 Given the number of cannonballs on each side of the base, compute the total number of cannonballs in the entire tetrahedral stack.
 
 
 Input
 The first line contains a single number n, giving the number of tetrahedral problems posed, for a maximum of 100 problems. Following that are exactly n lines, each with a single number giving the number of cannonballs on each side of the base for a tetrahedron of cannonballs, a number greater than 0 and less than 1000. 
 
 Output
 For each problem, output the problem number (starting from 1), a colon and a blank, the number of cannonballs on each side of the base, one blank, and finally the total number of cannonballs in the tetrahedron. 
 
 Sample Input
 6
 1
 2
 3
 5
 27
 999
 
 Sample Output
 1: 1 1
 2: 2 4
 3: 3 10
 4: 5 35
 5: 27 3654
 6: 999 166666500
*/