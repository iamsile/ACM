#include <iostream>
using namespace std;

int mg[9][9],n;
bool fr[10][10],fc[10][10],fb[10][10];

void Check()
{
    int i,j;
    for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			fr[i][j]=fc[i][j]=fb[i][j]=0;
    for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(fr[i][mg[i][j]]||fc[mg[i][j]][j]||fb[(i/3)*3+(j/3)][mg[i][j]])
			{
				cout << "No!\n";
				return;
			}
			else
				fr[i][mg[i][j]]=fc[mg[i][j]][j]=fb[(i/3)*3+(j/3)][mg[i][j]]=true;
		}
   cout << "Yes!\n";
}

int main()
{
    int t,i,j,tt=1;
    cin>>t;
    while(t--)
    {
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				cin>>mg[i][j];
		cout << "Case " << tt++ << ":\n";
		Check();
    }
    return 0;
}
/*#include <iostream>
using namespace std;

int tcase,fcase,x,y,b,temp,flag;
bool han[9][9],lie[9][9],kuai[9][9]; //用3个数组分别记录行列块的情况 

int getb(int x,int y) //由行号和列号返回块号 
{
    int tx,ty,ans;
    if((x>=1)&&(x<=3))
		tx=1;
    if((x>=4)&&(x<=6)) 
		tx=2;
    if((x>=7)&&(x<=9)) 
		tx=3;
    if((y>=1)&&(y<=3))
		ty=1;
    if((y>=4)&&(y<=6)) 
		ty=2;
    if((y>=7)&&(y<=9)) 
		ty=3;
    ans=(tx-1)*3+ty;
    return ans;
}

int main()
{
    cin >> tcase;
    for(fcase=1;fcase<=tcase;fcase++)
    {
        for(x=1;x<=9;x++) //赋初值 
			for(y=1;y<=9;y++)
			{
				han[x][y]=true;
				lie[x][y]=true;
				kuai[x][y]=true;
			}
        for(x=1;x<=9;x++)
			for(y=1;y<=9;y++)
			{
				cin >> temp; 
				if(han[x][temp]==true) //记录temp在第X行中出现过 
					han[x][temp]=false;
				if(lie[y][temp]==true) //记录temp在第Y列中出现过 
					lie[y][temp]=false;
				b=getb(x,y);
				if(kuai[b][temp]==true) //记录temp在第B块中出现过 
					kuai[b][temp]=false;
			}         
        flag=0; 
        for(x=1;x<=9;x++) //如果是一个合法的数独，那么所有数字都出现过一次，判断是否有哪个数字没有出现过 
			for(y=1;y<=9;y++)
			{
				if(han[x][y]==true)
					flag=1;
				if(lie[x][y]==true) flag=1;
				if(kuai[x][y]==true) 
					flag=1;
			}
        cout << "Case " << fcase << ":" << endl;
        if(flag==0)
			cout << "Yes!" << endl;
        else
            cout << "No!" << endl;
    }
    return 0;
}*/
/*
 Problem description
 Sudoku is a puzzle of a 9´9 grid made up of 3´3 subgrids (called "regions").Some cells already contain numbers, known as "givens". The goal is to fill in the empty cells, one number in each, so that each column, row, and region contains the numbers 1 through 9 exactly once. Each number in the solution therefore occurs only once in each of three "directions", hence the "single numbers" implied by the puzzle's title. 
 The attraction of the puzzle is that the completion rules are simple, yet the line of reasoning required to reach the completion may be difficult. Published puzzles often are ranked in terms of difficulty. This also may be expressed by giving an estimated solution time. While, generally speaking, the greater the number of givens, the easier the solution, the opposite is not necessarily true. The true difficulty of the puzzle depends upon how easy it is to logically determine subsequent numbers. 
 TheBeet is fond of this game, he has solve lots of sudokus. But one day, when he check the puzzles he had solve before, some of them does not look correct. 
 
 Now TheBeet is busy with his homework. Could you kind enough to help TheBeet to check the puzzles?
 
 
 
 Input
 The first line of the input contains one integer n (n < 20), which represents the number of test cases. 
 Each test case contains 9 lines, each line contains 9 integers, which represent the answer to the puzzle you should check. 
 There is a blank line after each test case. 
 
 Output
 For each test case, output "Case #:" on the first line, '#' is the number of the test case; then you should output "Yes!" (without quotes) if the answer is correct, otherwise you should output "No!".
 
 Sample Input
 1
 5 6 2 8 3 9 1 4 7
 7 1 4 5 2 6 8 3 9
 3 8 9 1 4 7 2 6 5
 1 2 8 9 5 3 6 7 4
 6 4 5 7 1 8 9 2 3
 9 3 7 4 6 2 5 1 8
 2 9 6 3 8 4 7 5 1
 4 7 1 2 9 5 3 8 6
 8 5 3 6 7 1 4 9 2
 Sample Output
 Case 1:
 Yes!
*/