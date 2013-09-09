#include <iostream>
using namespace std;

int main()
{
    int i,j,m,t,x,y,x1,y1,a[3][3]={0};    
    char d;    
    cin >> t;    
    while(t--)
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                cin >> a[i][j];
                if(a[i][j]==0)
                {
                    x=i;
                    y=j;
                }
            }        
        cin >> m;
        for(i=0;i<m;i++)
        {
            cin >> d;
            if(d=='D')
            {
                x1=x+1;
                y1=y;
            }
            else if(d=='U')
            {
                x1=x-1;
                y1=y;
            }
            else if(d=='R')
            {
                y1=y+1;
                x1=x;
            }
            else if(d=='L')
            {
                y1=y-1;
                x1=x;
            }
            if(x1>=0&&x1<3&&y1>=0&&y1<3)
            {
                swap(a[x][y], a[x1][y1]);
                x=x1;
                y=y1;
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(j)
                    cout << ' ';
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
/*
 Problem description
 I think almost every acmer will know the 8 numbers problem which is a very famous problem.The game begin from the initial state of a 3*3 matrix which makes up of 8 numbers(1-8) and a blank block(0).move the blank block with its adjacent block until reach the objective state.It is obvious that the blank block has four directions which it can move to when it is at the middle position,i.e.up,down,left,right.Also,it has two directions when it is at the corner of the matrix and three directions at other posintion.
 Form example,the initial state of the matrix:
 8 0 3
 2 1 4
 7 6 5
 the objective state:
 1 2 3
 8 0 4
 7 6 5
 and we give a valid moving path:
 8 0 3     8 1 3     8 1 3     0 1 3      1 0 3      1 2 3
 2 1 4  >  2 0 4  >  0 2 4  >  8 2 4   >  8 2 4   >  8 0 4
 7 6 5     7 6 5     7 6 5     7 6 5      7 6 5      7 6 5
 Moreover,the path with least steps is called the shortest path.And the 8 numbers is check whether there are the path from the initial state to the objective state and if it exists,give the shortest path.
 And we all know huicpc229 is not very good at search,so he hasn't solved this problem now.But he has solved another easy problem. The problem is described as follow:
 Give an initial state of the matrix,and give a sequence of moving. For every moving,if the blank block can move to the direction as the moving,move it,otherwise ignore this moving.And we want to know the final state of the matrix.
 
 
 Input
 The first line of the input is one integer t,the number of testcase.
 For each testcase:
 Three lines respond to the initial state of the matrix,and there will be three numbers on each of the three lines.
 Follow by an interger m corresponding to the number of moving.
 The next m line,every line contain only one character:
 U: move the blank block up for one block.
 D: move the blank block down for one block.
 L: move the blank block left for one block.
 R: move the blank block right for one block.
 
 
 Output
 For each testcase output the final state of the matrix for three lines as above.And there will be a blank space between every two numbers on the same line.And you should output one blank line after each testcase.
 
 
 Sample Input
 1
 8 0 3
 2 1 4
 7 6 5
 2
 D
 R
 Sample Output
 8 1 3
 2 4 0
 7 6 5
*/