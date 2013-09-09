#include <iostream>
using namespace std;
int map[3][3],num;

int judge()
{
    for (int i=0; i<3; i++) {
        if (map[i][0]==map[i][1]&&map[i][1]==map[i][2])
            return map[i][0];
        if (map[0][i]==map[1][i]&&map[1][i]==map[2][i])
            return map[0][i];
        }
    if ((map[0][0]==map[1][1]&&map[1][1]==map[2][2])||
        (map[0][2]==map[1][1]&&map[1][1]==map[2][0]))
        return map[1][1];
    return 0;
}

int dfs(int num)
{
    int i,j,k=0,m,lab=0;
    m=judge();
    if (m||num==9)
        return m;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            if (map[i][j]==0) {
                map[i][j]=2-num%2;
                k=dfs(num+1);
                map[i][j]=0;
                if (k==2-num%2)
                    return 2-num%2;
                else if (k==0)
                    lab=1;
            }
    if (lab)
        return 0;
    else return 1+num%2;
}

int main()
{
    int i,j,ans;
    char c;
    for (i=0,num=0; i<3; i++)
        for (j=0; j<3; j++) {
            cin >> c;
            if (c=='X') {
                map[i][j]=2;
                num++;
            }
            else if (c=='O') {
                map[i][j]=1;
                num++;
            }
            else map[i][j]=0;
        }
    ans=dfs(num);
    if (ans==2)
        cout << "X WILL WIN\n";
    else if (ans==1)
        cout << "O WILL WIN\n";
    else cout << "TIL\n";
    return 0;
}
/*
#include <iostream>
using namespace std;
int   map[3][3];
int num;

int checkwin()         //测试是否有一方获胜
{
    int i;
    for(i=0;i<3;i++)
    {
        if(map[i][0]==map[i][1] && map[i][1]==map[i][2])
            return map[i][0];
        if(map[0][i]==map[1][i]&&map[2][i]==map[1][i])
            return map[0][i];                 
    }
    if((map[0][0]==map[1][1]&&map[2][2]==map[1][1])
       ||(map[0][2]==map[1][1]&&map[2][0]==map[1][1]))
        return map[1][1];
    
    return 0;       
}

int DFS(int num)   //num 记录步数 ，区别轮到谁走
{
    int i,j,t,m;
    int draw=0;
    m=checkwin();
    if(m!=0||num==9)
        return m;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(map[i][j]==0)
            {
                map[i][j]=2-num%2;
                t=DFS(num+1);
                map[i][j]=0;
                if(t==2-num%2)          //任何一步可以赢，则返回赢的一方，否则如果任何一步    
                    return 2-num%2;      //可以获得平局，返回平局，否则返回0；
                else if(t==0)
                    draw=1;
                map[i][j]=0;    
            }     
        }
    if(draw)
        return 0;
    else return 1+num%2;                 
    
}     

int main()
{
    int i,j;
    char ch;
    
    num=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>ch;
            if(ch=='O')
            {
                map[i][j]=1;
                num++;
            }     
            else if(ch=='X')
            {
                map[i][j]=2;
                num++;
            }     
            else
                map[i][j]=0;
        }
        
    }
    int re=DFS(num);     
    
    if(re==2)
        cout<<"X WILL WIN"<<endl;
    else if(re==1)
        cout<<"O WILL WIN"<<endl;
    else
        cout<<"TIL"<<endl;    
    
    return 0;
    
}
 Problem description
 Recently fks has studied artificial intelligence, and wants to develop a game. To avoid embarrassing himself，he decideds to make a simple game. In the book there are detailed explanations on three stone game, So he decided to do this.The three stone game is also called Tic-Tac-Toe. It's chessboard is very simple, Is a 3 × 3 Lattice，like the Chinese characters “井”,so it is called "井字棋". Its rules are similar with the five stone game ,it’s that the person who put three pawns in one line first will win. Through fks’s relentless endeavor, finally realized this gambling algorithm. He is very pround, also wants to let you have a try.
 Give you a chessboard（maybe not a empty one）Your duty is to judge which side will win or they are draw. Assume that they both use the best strategy. The chessboard given is a available one so that the two player have not got the final result—win, lost or draw. The‘X’always plays first and they play by turn.
 ‘X’ stands for one person 'O' stands for another. 
 
 
 Input
 The input consists three lines, each line three character 'X','O'or '.', stands for the pawns they put, '.'stands for a empty position.
 
 Output
 The output consists one line ,it's“X WILL WIN”,“O WILL WIN”, or “TIL”(draw).
 
 Sample Input
 XXO
 OXO
 ...
 Sample Output
 X WILL WIN
*/