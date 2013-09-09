#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct map {
    int x,y,step;
}start,end;

int dir[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
int n,step[301][301],v[301][301];

void bfs()
{
    map p,next;
    queue<map> Q1,Q2;
    p=start;
    Q1.push(p);
    p=end;
    Q2.push(end);
    while (!Q1.empty()) {
        p=Q1.front();
        Q1.pop();
        if (p.x==start.x&&p.y==start.y&&p.x==end.x&&p.y==end.y) {
            cout << p.step << '\n';
            return;
        }
        for (int i=0; i<8; i++) {
            next.x=p.x+dir[i][0];
            next.y=p.y+dir[i][1];
            next.step=p.step+1;
            if (next.x>=0&&next.x<n&&next.y>=0&&next.y<n) {
                if (v[next.x][next.y]==0) {
                    v[next.x][next.y]=1;
                    step[next.x][next.y]=next.step;
                    Q1.push(next);
                }
                else if (v[next.x][next.y]==2) {
                    cout << next.step+step[next.x][next.y] << '\n';
                    return;
                }
            }
        }
        p=Q2.front();
        Q2.pop();
        for (int i=0; i<8; i++) {
            next.x=p.x+dir[i][0];
            next.y=p.y+dir[i][1];
            next.step=p.step+1;
            if (next.x>=0&&next.y<n&&next.y>=0&&next.y<n) {
                if (v[next.x][next.y]==0) {
                    v[next.x][next.y]=2;
                    step[next.x][next.y]=next.step;
                    Q2.push(next);
                }
                else if (v[next.x][next.y]==1) {
                    cout << next.step+step[next.x][next.y] << '\n';
                    return;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        memset(v, 0, sizeof(v));
        memset(step, 0, sizeof(step));
        cin >> n;
        cin >> start.x >> start.y;
        start.step=0;
        v[start.x][start.y]=1;
        cin >> end.x >> end.y;
        end.step=0;
        v[end.x][end.y]=2;
        bfs();
    }
    return 0;
}
/*
 Description
 
 Background 
 Mr Somurolov, fabulous chess-gamer indeed, asserts that no one else but him can move knights from one position to another so fast. Can you beat him? 
 The Problem 
 Your task is to write a program to calculate the minimum number of moves needed for a knight to reach one point from another, so that you have the chance to be faster than Somurolov. 
 For people not familiar with chess, the possible knight moves are shown in Figure 1. 
 
 
 Input
 
 The input begins with the number n of scenarios on a single line by itself. 
 Next follow n scenarios. Each scenario consists of three lines containing integer numbers. The first line specifies the length l of a side of the chess board (4 <= l <= 300). The entire board has size l * l. The second and third line contain pair of integers {0, ..., l-1}*{0, ..., l-1} specifying the starting and ending position of the knight on the board. The integers are separated by a single blank. You can assume that the positions are valid positions on the chess board of that scenario.
 Output
 
 For each scenario of the input you have to calculate the minimal amount of knight moves which are necessary to move from the starting point to the ending point. If starting point and ending point are equal,distance is zero. The distance must be written on a single line.
 Sample Input
 
 3
 8
 0 0
 7 0
 100
 0 0
 30 50
 10
 1 1
 1 1
 Sample Output
 
 5
 28
 0
*/