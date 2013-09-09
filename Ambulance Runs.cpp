#include <iostream>
using namespace std;

int main()
{
    int i,j,k,x,y,g,a[100][100],max=-200;
    char s[5];
    for (i=1; i<7; i++)
        for (j=1; j<7; j++)
            if (i==j)
                a[i][j]=0;
            else
                a[i][j]=1000000;
    while (cin >> s) {
        if (s[0]=='$')
            break;
        else {
            cin >> y >> g;
            x=s[0]-'0';
            a[x][y]=g;
            if (x>max)
                max=x;
            if(y>max)
                max=y;
        }
    }
    for (k=2; k<=max; k++)
        for (i=1; i<=max; i++)
            for (j=1; j<=max; j++)
                if (a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
    while (scanf("%d%d",&x,&y)!=EOF) {
        if (a[x][y]==1000000)
            printf("%d to %d: No Path\n",x,y);
        else 
            printf("%d to %d: %d\n",x,y,a[x][y]);
    }
    return 0;
}
/*
 Problem description
 Just in case you weren't sure, an ambulance is a vehicle to transport people who need medical attention. When an ambulance is not involved in a life threatening emergency, they follow all the normal traffic laws. Even so, an ambulance has a vested interest in travelling the shortest possible path from wherever they are to wherever they have to go. However, not all paths are equal. A street could be one way, or could have an excessive amount of traffic. In this problem, you'll be asked to say what the shortest path is from one point to another in a given street layout.
 Each intersection is assigned a number larger than 1. A street is described by identifying the two intersections that start and end the street. Each street also has a weight associated with it saying how difficult it is to go along that road. All weights are greater than 0. 
 
 
 Input
 The first part of the input is an arbitrary number of lines describing the city. The format is
 s e w
 
 where s and e are the starting and ending numbers of the intersections identifying a particular street. w is the weight associated for driving down the street in that direction. Note that not all streets are two way streets. It is possible for a street to have one way, or even for a two way street to have two different weights associated with depending on what direction you're heading. A two way street will be identified by having two separate lines in the input, one for each direction. You may assume that no intersection will point to itself (be kinda pointless wouldn't it?). The three numbers are separated by an arbitrary amount of spaces. This part of the input is terminated by a line containing just $END.
 Following the $END line will be the test cases you should run through. Each test case has the form,
 
 s e
 
 where s is the intersection the ambulance is starting at and e is the intersection the ambulance wants to wind up at. This part of the input will be terminated by end of file. 
 
 Output
 For each test case you are to calculate the shortest path, defined as the sum of the weights from s to e. Output will be either
 s to e: spath
 
 or
 s to e: No such path.
 
 where s and e are the starting and ending intersections, and spath is the shortest path. If there is no path from s to e then print the second message. 
 
 Sample Input
 1 2 1
 1 3 3
 2 3 1
 3 4 5
 1 4 2
 5 4 4
 $END
 1 2
 1 3
 1 5
 4 1
 5 4
 5 5
 Sample Output
 1 to 2: 1
 1 to 3: 2
 1 to 5: No Path
 4 to 1: No Path
 5 to 4: 4
 5 to 5: 0
*/