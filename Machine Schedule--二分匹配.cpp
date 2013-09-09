#include <iostream>
using namespace std;
int n,m,map[101][101],v[1010],lk[1010];//lk=link

bool find(int x)
{
    for (int i=1; i<m; i++)
        if (map[x][i]&&!v[i]) {
            v[i]=1;
            if (lk[i]==0||find(lk[i])) {
                lk[i]=x;
                return true;
            }
        }
    return false;
}

int main()
{
    while (cin >> n&&n) {
        int i,l,k,x,y,sum;
        cin >> m >> l;
        memset(map, 0, sizeof(map));
        memset(lk, 0, sizeof(lk));
        for (i=0; i<l; i++) {
            cin >> x >> y >> k;
            if (y==0||k==0)
                continue;
            map[y][k]=1;
        }
        for (i=0,sum=0; i<n; i++) {
            memset(v, 0, sizeof(v));
            if (find(i))
                sum++;
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem Description
 As we all know, machine scheduling is a very classical problem in computer science and has been studied for a very long history. Scheduling problems differ widely in the nature of the constraints that must be satisfied and the type of schedule desired. Here we consider a 2-machine scheduling problem.
 
 There are two machines A and B. Machine A has n kinds of working modes, which is called mode_0, mode_1, …, mode_n-1, likewise machine B has m kinds of working modes, mode_0, mode_1, … , mode_m-1. At the beginning they are both work at mode_0.
 
 For k jobs given, each of them can be processed in either one of the two machines in particular mode. For example, job 0 can either be processed in machine A at mode_3 or in machine B at mode_4, job 1 can either be processed in machine A at mode_2 or in machine B at mode_4, and so on. Thus, for job i, the constraint can be represent as a triple (i, x, y), which means it can be processed either in machine A at mode_x, or in machine B at mode_y.
 
 Obviously, to accomplish all the jobs, we need to change the machine's working mode from time to time, but unfortunately, the machine's working mode can only be changed by restarting it manually. By changing the sequence of the jobs and assigning each job to a suitable machine, please write a program to minimize the times of restarting machines. 
 
 
 Input
 The input file for this program consists of several configurations. The first line of one configuration contains three positive integers: n, m (n, m < 100) and k (k < 1000). The following k lines give the constrains of the k jobs, each line is a triple: i, x, y.
 
 The input will be terminated by a line containing a single zero.
 
 
 Output
 The output should be one integer per line, which means the minimal times of restarting machine.
 
 
 Sample Input
 5 5 10
 0 1 1
 1 1 2
 2 1 3
 3 1 4
 4 2 1
 5 2 2
 6 2 3
 7 2 4
 8 3 3
 9 4 3
 0
 
 
 Sample Output
 3
*/