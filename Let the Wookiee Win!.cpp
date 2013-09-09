#include<stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char a[5][5];
int path(int x,int y)
{
    int i,j,step;
    for (i=x-1,step=1; i>=0&&i<5&&y<5&&y>=0; i--)
        if (a[i][y]=='X')
            step++;
        else break;
    for (i=x+1; i>=0&&i<5&&y<5&&y>=0; i++)
        if (a[i][y]=='X')
            step++;
        else break;
    if (step>=4)
        return 1;
    for (i=x-1,step=1; i>=0&&i<5&&y<5&&y>=0; i--)
        if (a[i][y]=='O')
            step++;
        else break;
    for (i=x+1; i>=0&&i<5&&y<5&&y>=0; i++)
        if (a[i][y]=='O')
            step++;
        else break;
    if (step>=4)
        return 1;
    for (j=y-1,step=1; x>=0&&x<5&&j<5&&j>=0; j--)
        if (a[x][j]=='X')
            step++;
        else break;
    for (j=y+1; x>=0&&x<5&&j<5&&j>=0; j++)
        if (a[x][j]=='X')
            step++;
        else break;
    if (step>=4)
        return 1;
    for (j=y-1,step=1; x>=0&&x<5&&j<5&&j>=0; j--)
        if (a[x][j]=='O')
            step++;
        else break;
    for (j=y+1; x>=0&&x<5&&j<5&&j>=0; j++)
        if (a[x][j]=='O')
            step++;
        else break;
    if (step>=4)
        return 1;
    for (i=x-1,j=y-1,step=1; i>=0&&i<5&&j<5&&j>=0; i--,j--)
        if (a[i][j]=='O')
            step++;
        else break;
    for (i=x+1,j=y+1; i>=0&&i<5&&j<5&&j>=0; i++,j++)
        if (a[i][j]=='O')
            step++;
        else break;
    if (step>=4)
        return 1;
    for (i=x-1,j=y-1,step=1; i>=0&&i<5&&j<5&&j>=0; i--,j--)
        if (a[i][j]=='X')
            step++;
        else break;
    for (i=x+1,j=y+1; i>=0&&i<5&&j<5&&j>=0; i++,j++)
        if (a[i][j]=='X')
            step++;
        else break;
    if (step>=4)
        return 1;
    for (i=x-1,j=y+1,step=1; i>=0&&i<5&&j<5&&j>=0; i--,j++)
        if (a[i][j]=='X')
            step++;
        else break;
    for (i=x+1,j=y-1; i>=0&&i<5&&j<5&&j>=0; i++,j--)
        if (a[i][j]=='X')
            step++;
        else break;
    if (step>=4)
        return 1;
    for (i=x-1,j=y+1,step=1;i>=0&&i<5&&j<5&&j>=0; i--,j++)
        if (a[i][j]=='O')
            step++;
        else break;
    for (i=x+1,j=y-1; i>=0&&i<5&&j<5&&j>=0; i++,j--)
        if (a[i][j]=='O')
            step++;
        else break;
    if (step>=4)
        return 1;
    return 0;
}

int main()
{
    char b[20]={"Finished"};
    char str[100];
    int i,j,flag;
    int c[5][5]={1,2,3,4,5,6,7,8,9,10,
        11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    while (1) {
        flag=0;
        for (i=0; i<5; i++) {
            gets(str);
            sscanf(str,"%c %c %c %c %c",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
        }
        gets(str);
        for (i=0; i<5; i++) {
            for (j=0; j<5; j++)
                if (a[i][j]=='*')
                {
                    if (path(i,j)==0)
                    {
                        cout << c[i][j] << '\n';
                        flag=1;
                        break;
                    }
                }
            if (flag)
                break;
        }
        if (strcmp(str, b)==0)
            return 0;
    }
    return 0;
}
/*
 Problem description
 You are playing against Chewbacca in a tough battle of Galactic Tic-Tac-Toe, which is just like simple Tic-Tac-Toe except that the playing board is 5 × 5 and the goal is to get 4 in a row. In response to a brilliant move, Chewbacca protests loudly and plays his next move, setting you up to win. However, before you can claim victory, Han Solo takes this opportunity to warn you that it’s not wise to upset a Wookiee. After all, they’re known to pull people’s arms out of their sockets when they lose. Wisely, you decide on a new strategy: Let the Wookiee win! 
 
 
 Input
 Input consists of a series of 5 × 5 playing boards, each separated by a blank line. Each square in a row is separated by a single space. You are ‘O’, Chewie is ‘X’, and empty squares are denoted by ‘*’. For each board, there is exactly one empty square that you can play that does not cause you to win and does not block any of Chewie's winning moves on his next turn. The final board is followed immediately by the word “Finished” on the next line.
 
 
 Output
 For each board, print a line consisting of the number of the square that you should play to avoid having your arms pulled out of their sockets. The numbering should conform to the following table. 
 1	2	3	4	5
 6	7	 8	9	10
 11	 12	 13	 14	 15
 16	 17	 18	 19	 20
 21	 22	 23	 24	 25
 
 
 
 Sample Input
 X O * X X
 O O X X *
 O O * X X
 O X O O X
 X O O X O
 
 X X X * O
 O * * O X
 O O X * X
 O * X X O
 * X O O O
 Finished
 Sample Output
 3
 17
*/