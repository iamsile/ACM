#include <iostream>
using namespace std;

int n,map[20][20]={0};
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,2},{1,-2},{2,1},{2,-1}};

int judge(int x,int y)
{
    if (x<0||x>=n||y<0||y>=n||map[x][y])
        return 0;
    return 1;
}

int getexit(int x,int y)
{
    int i,cnt=0;
    if (!judge(x,y))
        return 9;
    for (i=0; i<8; i++)
        if (judge(x+dir[i][0], y+dir[i][1]))
            cnt++;
    return cnt;
}

int main()
{
    while (cin >> n&&n) {
        if (n>1&&n<5) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        int i,m,lab,k,min,x=0,y=0;
        map[x][y]=1;
        printf("aA\n");
        for (m=1; m<n*n; m++) {
            k=0;
            min=9;
            for (i=0; i<8; i++) {
                lab=getexit(x+dir[i][0],y+dir[i][1]);
                if (lab<min) {
                    k=i;
                    min=lab;
                }
            }
            x+=dir[k][0];
            y+=dir[k][1];
            map[x][y]=m+1;
            printf("%c%c\n",x+'a',y+'A');
        }
    }
    return 0;
}/*
#include <stdio.h>
#define N 5

int board[N][N]={0};
int moves[8][2]={{-2,1},{-1,2},{1,2},{2,1},
    {2,-1},{1,-2},{-1,-2},{-2,-1}};

//
int valid(int x,int y){
	if(x<0 || x >=N || y<0 || y>=N || board[x][y]) return 0;
	else return 1;
}

//计算出口数
int getExit(int x,int y){
	int i,cnt=0;
	if(!valid(x,y)) return 9; 
	for(i=0;i<8;i++){
		if(valid(x+moves[i][0],y+moves[i][1])) cnt++;
	}
	return cnt;
}


int main()
{
	int x,y,i,j,k,min,m,t;
	scanf("%d %d",&x,&y);
	board[x][y] = 1;
	printf("%3d:%d %c\n",1,x+1,y+'A');
	for(m=1;m<N*N;m++){
		k = 0;
		min = 9;
		for(i=0;i<8;i++){
			t = getExit(x+moves[i][0],y+moves[i][1]);
			if(t<min){
				k = i;
				min = t;
			}
		}
		if(min == 9){
			printf("Error!\n");
			return 0;
		}
		x += moves[k][0];
		y += moves[k][1];
		board[x][y] = m+1;
		printf("%2d:%d %c\n",m+1,x+1,y+'A');
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%3d ",board[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/
/*
 Problem description
 Even paratroopers have vacations. The flight to Sirius in the depths of “The Admiral Brisco” Leo Hao whiled away with chessboard. No, he did not like usual chess game, and in addition, he did not have likely rival. The whole day Leo amused himself with an interesting thing: he tried to travel over all cells of the chessboard with the knight so that the knight visited each cell only one time. Leo attempted one time, then second, but always something was wrong. Leo became a little angry. Then he attempted board 4*4 instead of 8*8. Again failure after failure. A little angry, with the chessboard under his arm, Leo went to look for a local programmer. They two together indeed will solve this problem.
 
 Input
 There is only one number N (1 <= N <= 15) in the input.
 
 Output
 If it is possible to travel with the knight over the square field N×N cells, then output should contain N^2 lines with tour over the chessboard with mentioned property, otherwise the only word “IMPOSSIBLE”.
 
 Sample Input
 5
 Sample Output
 aA
 bC
 aE
 cD
 eE
 dC
 eA
 cB
 aC
 bA
 dB
 eD
 cE
 aD
 bB
 dA
 eC
 dE
 bD
 aB
 cA
 eB
 cC
 bE
 dD
*/