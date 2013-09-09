#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    long n;
    while (~scanf("%ld",&n)) {
        char c,c2;
        c2=getchar();
        long i,m,x=0,y=0,cnt=0;
        for (i=0; i<n; i++) {
            scanf("%c %ld",&c,&m);
            c2=getchar();
            if (c=='M') {
                if (cnt==0||cnt==360)
                    x+=m;
                else if (cnt==180||cnt==-180)
                    x-=m;
                else if (cnt==90||cnt==-270)
                    y+=m;
                else if (cnt==270||cnt==-90)
                    y-=m;
            }
            else if (c=='L') {
                if (m==90)
                    cnt+=90;
                else if (m==180)
                    cnt+=180;
                else if (m==270)
                    cnt+=270;
                else if (m==360)
                    cnt+=360;
                if(cnt>360)
					cnt=cnt%360;
            }
            else if (c=='R') {
                if (m==90)
                    cnt-=90;
                else if (m==180)
                    cnt-=180;
                else if (m==270)
                    cnt-=270;
                else if (m==360)
                    cnt-=360;
                if(cnt<0)
					cnt=cnt%360;
            }
        }
        printf("%ld %ld\n",x,y);
    }
    return 0;
}/*
  Problem description
  People whose name is admin or administration have priority privacy. Mr. admin has a robot and he can control this robot by command. 
  He has three kinds of commands 'L', 'R', 'M'. For example: "L D" means robot turn left by D degrees; 
  D is an integer of {90, 180, 270, 360}.
  "R D" means robot turn right by D degrees; D is an integer of {90, 180, 270, 360}.
  "M D" means robot move forward D units; D is a positive integer less than 1000.
  At first, the robot stand at position (0,0) and face to the positive direction of X coordinate. We intend to find the last position of robot after lots of commands. 
  
  
  
  
  
  Input
  There are several test cases end with EOF. 
  For each test case, the first line is an integer n(0< n ≤ 100000),n means the number of commands. Follow n lines represent n commands, the format of command is given above.
  
  
  Output
  For each the case, just output two integers x, y, (x, y) is the last position of robot. 
  
  
  Sample Input
  3 
  M 10
  L 90
  M 10
  9
  M 1
  L 90
  M 1
  R 90
  M 1
  L 90
  M 1
  R 180
  M 2
  Sample Output
  10 10
  2 0
*/