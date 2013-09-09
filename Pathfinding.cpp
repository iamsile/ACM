#include <iostream>
using namespace std;

int main()
{
    int x,y;
    while (cin >> x >> y) {
        if (x>=0&&y>=0) {
            if (x%2&&y%2)
                cout << x+y+2 << '\n';
            else cout << x+y << '\n';
        }
        else if (x<0&&y>0) {
            if (x%2&&!(y%2))
                cout << -x+y+2 << '\n';
            else cout << -x+y << '\n';
        }
        else if (x<=0&&y<=0) {
            if (!(x%2)&&!(y%2))
                cout << -x-y+4 << '\n';
            else cout << -x-y+2 << '\n';
        }
        else {
            if (!(x%2)&&y%2)
                cout << x-y+2 << '\n';
            else cout << x-y << '\n';
        }
    }
    return 0;
}
/*
#include <stdio.h>

int getRightUp(int x, int y){
    if(!(x%2) && !(y%2))
        return x+y;
    if(!(x%2) && y%2)
        return x+y;
    if(!(y%2) && x%2)
        return x+y;
    return x+y+2;
}
int getLeftUp(int x, int y){
    if(!(x%2) && !(y%2))
        return -x+y;
    if(!(x%2) && y%2)
        return -x+y;
    if(!(y%2) && x%2)
        return -x+y+2;
    return -x+y;
}
int getLeftDown(int x, int y){
    if(!(x%2) && !(y%2))
        return -x-y+4;
    if(!(x%2) && y%2)
        return -x-y+2;
    if(!(y%2) && x%2)
        return -x-y+2;
    return -x-y+2;
}
int getRightDown(int x, int y){
    if(!(x%2) && !(y%2))
        return x-y;
    if(!(x%2) && y%2)
        return x-y+2;
    if(!(y%2) && x%2)
        return x-y;
    return x-y;
}
int main(){
    int x,y;
    while(scanf("%d %d",&x,&y)!=EOF){
        if(x>=0 && y>=0)
            printf("%d\n",getRightUp(x,y));
        else if(x<0 && y>0)
            printf("%d\n",getLeftUp(x,y));
        else if(x<=0 && y<=0)
            printf("%d\n",getLeftDown(x,y));
        else
            printf("%d\n",getRightDown(x,y));
    }
    return 0;
}
*/
/*
Problem description
Recently you have been working on the pathfinding module for your AI system. Your objective is to find the shortest path for an agent that wants to travel between two points on a plane. The agent will start at the point (0,0), and travel to the point (x,y). You decided that the agent will move either on horizontal of vertical lines such that, at every moment, at least one coordinate of the agent is an integer.

There is yet another restriction however. Each line will only allow movement in one direction. All horizontal lines with odd y-coordinates will be directed toward decreasing values of x, and all other horizontal lines toward increasing values of x. Similarly, all vertical lines with odd x-coordinates will be directed toward decreasing values of y, and all other vertical lines toward increasing values of y.

Given x and y, output the distance that the agent must travel.


Input
Several lines, each contains two integers x and y. (-1000000 <= x,y <= 1000000)


Output
For each x, y, output the distance that the agent must travel.


Sample Input
0 -4
5 -4
0 0
5 4
-1 -4
Sample Output
8
9
0
9
7
Judge Tips
For Sample1: A possible path from (0,0) to (0,-4) is through the points (1,0), (1,-3), (-1,-3) and (-1,-4). 
*/