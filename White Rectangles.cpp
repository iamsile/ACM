#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char map[101][101];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int i,j,x,y,lx,ly,ux,uy,sum=0;//lx=low_x,ux=up_x;
        for (i=0; i<n; i++)
            cin >> map[i];
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                if (map[i][j]=='.') {
                    lx=i;ly=j;ux=i;uy=j;
                    while (lx>=0&&map[lx][j]=='.')
                        lx--;
                    lx++;
                    while (ly>=0&&map[i][ly]=='.')
                        ly--;
                    ly++;
                    for (y=uy; y>=ly; y--)
                        for (x=ux; x>=lx; x--)
                            if (map[x][y]=='.')
                                sum++;
                            else {
                                lx=x+1;
                                break;
                            }
                }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem Description
 You are given a chessboard made up of N squares by N squares with equal size. Some of the squares are colored black, and the others are colored white. Please write a program to calculate the number of rectangles which are completely made up of white squares. 
 
 
 Input
 There are multiple test cases. Each test case begins with an integer N (1 <= N <= 100), the board size. The following N lines, each with N characters, have only two valid character values:
 
 # - (sharp) representing a black square;
 . - (point) representing a white square.
 
 Process to the end of file.
 
 
 Output
 For each test case in the input, your program must output the number of white rectangles, as shown in the sample output.
 
 
 
 Sample Input
 2
 .#
 ..
 4
 ..#.
 ##.#
 .#..
 .#.#
 
 
 Sample Output
 5
 15
*/