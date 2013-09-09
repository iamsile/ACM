#include <iostream>
#include <math.h>
using namespace std;

struct Status {
    int board[3][3];
    int px,py;
};

Status init,target={1,2,3,4,5,6,7,8,9,2,2};
int targetPos[10][2],path[10000],maxDepth;
int move[4][2]={0,-1,-1,0,0,1,1,0};

int H(Status &s)
{
    int i,j,temp,sum=0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++) {
            temp=s.board[i][j];
            if (temp<9)
                sum+=abs(i-targetPos[temp][0])+abs(j-targetPos[temp][i]);
        }
    return sum;
}

bool IsSolvable()
{
    int i,j,k=0,sum=0,a[9];
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            a[k++]=init.board[i][j];
    for (i=0; i<8; i++)
        for (j=i+1; j<9; j++)
            if (a[i]>a[j])
                sum++;
    sum+=abs(init.px-targetPos[9][0])+abs(init.py-targetPos[9][1]);
    return sum%2==0;
}

void Output(int depth)
{
    for (int i=0; i<depth; i++)
        if (path[i]==0)
            cout << 'l';
        else if (path[i]==1)
            cout << 'u';
        else if (path[i]==2)
            cout << 'r';
        else cout << 'd';
}

bool IDAStar(Status &s,int depth,int h,int prev)
{
    if (memcmp(&s, &target, sizeof(Status))==0) {
        Output(depth);
        return true;
    }
    if (depth==maxDepth)
        return false;
    Status ns;
    int k,nh,nx,ny,temp;
    for (k=0; k<4; k++) {
        if (abs(k-prev)==2)
            continue;
        ns=s;
        nx=s.px+move[k][0];
        ny=s.py+move[k][1];
        if (nx<0||ny<0||nx==3||ny==3)
            continue;
        temp=s.board[nx][ny];
        ns.board[s.px][s.py]=temp;
        ns.board[nx][ny]=9;
        ns.px=nx;
        ns.py=ny;
        if (k==0&&ny<targetPos[temp][1])
            nh=h-1;
        else if (k==1&&nx<targetPos[temp][0])
            nh=h-1;
        else if (k==2&&ny>targetPos[temp][1])
            nh=h-1;
        else if (k==3&&ny<targetPos[temp][0])
            nh=h-1;
        else nh=h+1;
        if (depth+nh>=maxDepth)
            continue;
        path[depth]=k;
        if (IDAStar(ns, depth+1, nh, k))
            return true;
    }
    return false;
}

int main()
{
    char tmp;
    int i,j,index=0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++) {
            cin >> tmp;
            if (tmp=='x') {
                tmp='9';
                init.px=i;
                init.py=j;
            }
            init.board[i][j]=tmp-'0';
            targetPos[++index][0]=i;
            targetPos[index][1]=j;
        }
    if (IsSolvable()) {
        int h=H(init);
        for (maxDepth=h; ; maxDepth++)
            if (IDAStar(init,0,h,-10))
                break;
    }
    else cout << "unsolvable\n";
    return 0;
}
/*
#include <iostream>
#include <math.h>
using namespace std;

struct map {
    int board[3][3];
    int dx,dy;
};

map init,pst={1,2,3,4,5,6,7,8,9,2,2};
int pstPos[10][2],path[10000],maxdepth;
int move[4][2]={0,-1,-1,0,0,1,1,0};

int cal(map &s)
{
    int i,j,temp,sum=0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++) {
            temp=s.board[i][j];
            if (temp<9)
                sum+=abs(i-pstPos[temp][0])+abs(j-pstPos[temp][i]);
        }
    return sum;
}

bool solve()
{
    int i,j,k=0,sum=0,a[9];
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            a[k++]=init.board[i][j];
    for (i=0; i<8; i++)
        for (j=i+1; j<9; j++)
            if (a[i]>a[j])
                sum++;
    sum+=abs(init.dx-pstPos[9][0])+abs(init.dy-pstPos[9][1]);
    return sum%2==0;
}

void print(int depth)
{
    for (int i=0; i<depth; i++)
        if (path[i]==0)
            cout << 'l';
        else if (path[i]==1)
            cout << 'u';
        else if (path[i]==2)
            cout << 'r';
        else cout << 'd';
}

bool IDA(map &s,int depth,int h,int prev)
{
    if (memcmp(&s, &pst, sizeof(map))==0) {
        print(depth);
        return true;
    }
    if (depth==maxdepth)
        return false;
    map ns;
    int i,nh,x,y,temp;
    for (i=0; i<4; i++) {
        if (abs(i-prev)==2)
            continue;
        ns=s;
        x=s.dx+move[i][0];
        y=s.dy+move[i][1];
        if (x<0||y<0||x==3||y==3)
            continue;
        temp=s.board[x][y];
        ns.board[s.dx][s.dy]=temp;
        ns.board[x][y]=9;
        ns.dx=x;
        ns.dy=y;
        if (i==0&&y<pstPos[temp][1])
            nh=h-1;
        else if (i==1&&x<pstPos[temp][0])
            nh=h-1;
        else if (i==2&&y>pstPos[temp][1])
            nh=h-1;
        else if (i==3&&y<pstPos[temp][0])
            nh=h-1;
        else nh=h+1;
        if (depth+nh>=maxdepth)
            continue;
        path[depth]=i;
        if (IDA(ns, depth+1, nh, i))
            return true;
    }
    return false;
}

int main()
{
    char tmp;
    int i,j,index=0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++) {
            cin >> tmp;
            if (tmp=='x') {
                tmp='9';
                init.dx=i;
                init.dy=j;
            }
            init.board[i][j]=tmp-'0';
            pstPos[++index][0]=i;
            pstPos[index][1]=j;
        }
    if (solve()) {
        int h=cal(init);
        for (maxdepth=h; ; maxdepth++)
            if (IDA(init, 0, h, -10))
                break;
    }
    else cout << "unsolvable\n";
    return 0;
}*/
/*
 Description
 
 The 15-puzzle has been around for over 100 years; even if you don't know it by that name, you've seen it. It is constructed with 15 sliding tiles, each with a number from 1 to 15 on it, and all packed into a 4 by 4 frame with one tile missing. Let's call the missing tile 'x'; the object of the puzzle is to arrange the tiles so that they are ordered as: 
 1  2  3  4 
 
 5  6  7  8 
 
 9 10 11 12 
 
 13 14 15  x 
 
 where the only legal operation is to exchange 'x' with one of the tiles with which it shares an edge. As an example, the following sequence of moves solves a slightly scrambled puzzle: 
 1  2  3  4    1  2  3  4    1  2  3  4    1  2  3  4 
 
 5  6  7  8    5  6  7  8    5  6  7  8    5  6  7  8 
 
 9  x 10 12    9 10  x 12    9 10 11 12    9 10 11 12 
 
 13 14 11 15   13 14 11 15   13 14  x 15   13 14 15  x 
 
 r->           d->           r-> 
 
 The letters in the previous row indicate which neighbor of the 'x' tile is swapped with the 'x' tile at each step; legal values are 'r','l','u' and 'd', for right, left, up, and down, respectively. 
 
 Not all puzzles can be solved; in 1870, a man named Sam Loyd was famous for distributing an unsolvable version of the puzzle, and 
 frustrating many people. In fact, all you have to do to make a regular puzzle into an unsolvable one is to swap two tiles (not counting the missing 'x' tile, of course). 
 
 In this problem, you will write a program for solving the less well-known 8-puzzle, composed of tiles on a three by three 
 arrangement. 
 Input
 
 You will receive a description of a configuration of the 8 puzzle. The description is just a list of the tiles in their initial positions, with the rows listed from top to bottom, and the tiles listed from left to right within a row, where the tiles are represented by numbers 1 to 8, plus 'x'. For example, this puzzle 
 1  2  3 
 
 x  4  6 
 
 7  5  8 
 
 is described by this list: 
 
 1 2 3 x 4 6 7 5 8 
*/