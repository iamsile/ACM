#include <iostream>
#include <string>
using namespace std;
int n,m,map[40][40];
int d[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
bool flag;
string a[40];

string change(int x,int y)
{
    string tmp;
    tmp+=(char)(y+'A');
    tmp+=(char)(x+'1');
    return tmp;
}

void save(int n,int m)
{
    int i,j;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            a[map[i][j]]=change(i,j);
}

void dfs(int n,int m,int begin,int x,int y)
{
    if (begin==n*m) {
        flag=true;
        save(n,m);
        return;
    }
    int dx,dy;
    for (int i=0; i<8; i++) {
        if (flag)
            return;
        dx=x+d[i][0];
        dy=y+d[i][1];
        if ((dx>=0&&dx<n)&&(dy>=0&&dy<m)&&map[dx][dy]==0) {
            map[dx][dy]=begin+1;
            dfs(n, m, begin+1, dx, dy);
            map[dx][dy]=0;
        }
    }
}

int main()
{
    int i,j(1),t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(map, 0, sizeof(map));
        map[0][0]=1;
        flag=false;
        dfs(n,m,1,0,0);
        cout << "Scenario #" << j++ << ":\n";
        if (flag) {
            for (i=1; i<=n*m; i++)
                cout << a[i];
            cout << '\n';
        }
        else cout << "impossible\n";
        if (t)
            cout << '\n';
    }
    return 0;
}
/*
 Description
 
 Background 
 The knight is getting bored of seeing the same black and white squares again and again and has decided to make a journey 
 around the world. Whenever a knight moves, it is two squares in one direction and one square perpendicular to this. The world of a knight is the chessboard he is living on. Our knight lives on a chessboard that has a smaller area than a regular 8 * 8 board, but it is still rectangular. Can you help this adventurous knight to make travel plans? 
 
 Problem 
 Find a path such that the knight visits every square once. The knight can start and end on any square of the board.
 Input
 
 The input begins with a positive integer n in the first line. The following lines contain n test cases. Each test case consists of a single line with two positive integers p and q, such that 1 <= p * q <= 26. This represents a p * q chessboard, where p describes how many different square numbers 1, . . . , p exist, q describes how many different square letters exist. These are the first q letters of the Latin alphabet: A, . . .
 Output
 
 The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing the lexicographically first path that visits all squares of the chessboard with knight moves followed by an empty line. The path should be given on a single line by concatenating the names of the visited squares. Each square name consists of a capital letter followed by a number. 
 If no such path exist, you should output impossible on a single line.
 Sample Input
 
 3
 1 1
 2 3
 4 3
 Sample Output
 
 Scenario #1:
 A1
 
 Scenario #2:
 impossible
 
 Scenario #3:
 A1B3C1A2B4C2A3B1C3A4B2C4
*/