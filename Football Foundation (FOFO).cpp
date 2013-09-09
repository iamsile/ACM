#include <iostream>
using namespace std;

int main()
{
    int n,m,s;
    while (cin >> n >> m >> s) {
        if (!n&&!m&&!s)
            break;
        int i,j,k,step,loop,v[10001];
        char map[101][101];
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                cin >> map[i][j];
        memset(v, 0, sizeof(v));    
        for (i=0,j=s-1,step=0,loop=0; i>=0&&i<n&&j>=0&&j<m; ) {
            k=i*m+j;
            v[k]++;
            if (v[k]==1)
                step++;
            else if (v[k]==2) {
                step--;
                loop++;
            }
            else if (v[k]==3)
                break;
            if (map[i][j]=='W') 
                j--;
            else if (map[i][j]=='E')
                j++;
            else if (map[i][j]=='N')
                i--;
            else if (map[i][j]=='S')
                i++;
        }
        if (loop)
            cout << step << " step(s) before a loop of " << loop << " step(s)\n";
        else cout << step << " step(s) to exit\n";
    }
    return 0;
}
/*
 Problem description
 
 The football foundation (FOFO) has been researching on soccer; they created a set of sensors to describe the ball behavior based on a grid uniformly distributed on the field. They found that they could predict the ball movements based on historical analysis. Each square sensor of the grid can detect the following patterns:
 N north (up the field)
 S south (south the field)
 E east (to the right on the field)
 W west (to the left on the field)
 For example, in grid 1, suppose the ball was thrown into the field from north side into the field. The path the sensors detected for this movement follows as shown. The ball went through 10 sensors before leaving the field.
 Comparing with what happened on grid 2, the ball went through 3 sensors only once, and started a loop through 8 instructions and never exits the field.
 You are selected to write a program in order to evaluate line judges job, with the following out put based on each grid of sensors, the program needs to determine how long it takes to the ball to get out of the grid or how the ball loops around.
 
 Input
 There will be one or more grids of sensors for the same game. The data for each is in the following form. On the first line are three integers separated by blanks: The number of rows in the grid, the number of columns in the grid, and the number of the column in which the ball enters from the north. The grid column’s number starts with one at the left. Then come the rows of direction instructions. The lines of instructions contain only the characters N, S,E or W, with no blanks. The end of input is indicated by a grid containing 0 0 0 as limits.
 
 Output
 For each grid in the input there is one line of output. Either the ball follows a certain number of sensors and exits the field on any one of the four sides or else the ball follows the behavior on some number of sensors repeatedly. The sample input below corresponds to the two grids above and illustrates the two forms of output. The word “step” is always immediately followed by “(s)“ whether or not the number before is 1.
 
 Sample Input
 3 6 5
 NEESWE
 WWWESS
 SNWWWW
 4 5 1
 SESWE
 EESNW
 NWEEN
 EWSEN
 0 0 0
 Sample Output
 10 step(s) to exit
 3 step(s) before a loop of 8 step(s)
*/