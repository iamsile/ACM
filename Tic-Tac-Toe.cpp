#include <iostream>
using namespace std;
char map[3][3];

int main()
{
    char a[10];
    while(cin >> a&&a[0]!='e') {
        int i,j,k=0,flagx=0,flagy=0,x=0,y=0,nx=0,ny=0,sum=0;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++) {
                if(a[k]=='X') {
                    x++;
                    sum++;
                }
                if(a[k]=='O') {
                    y++;
                    sum++;
                }
                map[i][j]=a[k++];
            }
        if(x-y>1||y>x) {
            cout << "invalid\n";
            continue;
        }
        for(i=0;i<3;i++) {
            if(map[i][0]==map[i][1]&&map[i][1]==map[i][2]) {
                if(map[i][1]=='X')
                    nx++;
                if(map[i][1]=='O')
                    ny++;
            }
            if(map[0][i]==map[1][i]&&map[1][i]==map[2][i]) {
                if(map[1][i]=='X')
                    nx++;
                if(map[1][i]=='O')
                    ny++;
            }
        }
        if(map[0][0]==map[1][1]&&map[1][1]==map[2][2]) {
            if(map[1][1]=='X'&&!flagx) {
                nx++;
                flagx=1;
            }
            if(map[1][1]=='O'&&!flagy) {
                ny++;
                flagy=1;
            }
        }
        if(map[0][2]==map[1][1]&&map[1][1]==map[2][0]) {
            if(map[1][1]=='X'&&!flagx)
                nx++;
            if(map[1][1]=='O'&&!flagy)
                ny++;
        }
        if(nx&&ny)
            cout << "invalid\n";
        else if(!nx&&!ny&&sum!=9)
            cout << "invalid\n";
        else if(ny&&x==y+1)
            cout << "invalid\n";
        else if(nx&&x==y)
            cout << "invalid\n";
        else cout << "valid\n";
    }
    return 0;
}
/*
 Problem description
 In the game of tic-tac-toe, two players take turns marking squares of an initially empty 3×3 grid with either X’s or O’s. The first player always marks squares using X’s, whereas the second player always marks squares using O’s. If at any point during the game either player manages to mark three consecutive squares in a row, column, or diagonal with his/her symbol, the game terminates. Given a board configuration, your goal is to determine whether the board configuration represents the possible final state of a valid tic-tac-toe game.
 
 Input
 The input test file will contain multiple cases. Each test case consists of a single line containing 9 characters, which represent the 9 squares of a tic-tac-toe grid, given one row at a time. Each character on the line will either be ‘X’, ‘O’ (the letter O), or ‘.’ (indicating an unfilled square). The end-of-file is marked by a single line containing the word “end”.
 
 Output
 For each input test case, write a single line containing either the word “valid” or “invalid” indicating whether the given board configuration is the final state of some possible tic-tac-toe game.
 
 Sample Input
 XXXOO.XXX
 XOXOXOXOX
 OXOXOXOXO
 XXOOOXXOX
 XO.OX...X
 .XXX.XOOO
 X.OO..X..
 OOXXXOOXO
 end
 Sample Output
 invalid
 valid
 invalid
 valid
 valid
 invalid
 invalid
 invalid
*/