#include <iostream>
using namespace std;
int n,a[101][101],b[101],x[101],y[101];
bool sx[101],sy[101];

bool path(int l)
{
    sx[l]=true;
    for (int i=0; i<n; i++)
        if (!sy[i]&&x[l]+y[i]==a[l][i]) {
            sy[i]=true;
            if (b[i]==-1||path(b[i])) {
                b[i]=l;
                return true;
            }
        }
    return false;
}

int bestmatch()
{
    int i,j,k,dx,sum;
    for (i=0; i<n; i++) {
        x[i]=-999999;
        y[i]=0;
        for (j=0; j<n; j++)
            if (x[i]<a[i][j])
                x[i]=a[i][j];
    }
    memset(b, -1, sizeof(b));
    for (k=0; k<n; k++)
        while (1) {
            memset(sx, 0, sizeof(sx));
            memset(sy, 0, sizeof(sy));
            if (path(k))
                break;
            dx=9999999;
            for (i=0; i<n; i++)
                if (sx[i]) {
                    for (j=0; j<n; j++) {
                        if (!sy[j]) {
                            if (dx>x[i]+y[j]-a[i][j])
                                dx=x[i]+y[j]-a[i][j];
                        }
                    }
                }
            for (i=0; i<n; i++) {
                if (sx[i])
                    x[i]-=dx;
                if (sy[i])
                    y[i]+=dx;
            }
        }
    for (i=0,sum=0; i<n; i++)
        sum+=a[b[i]][i];
    return sum;
}

int main()
{
    while (scanf("%d",&n)&&n) {
        int i,j;
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        printf("%d\n",bestmatch());
    }
    return 0;
}
/*
 工作安排
 Problem description
 
 One problem comes up when we are trying to assign jobs about ACM/ICPC to staffs. Because some of them complain that the tasks assigned to them are so bother. This emotion will lead to very bad effect in sequence. So we try to satisfy every staff as possible as we can. At first, we make an investigation to get the information about staffs’ attitude towards every task. And then we evaluate each attitude as a point ( a positive integer number not larger than 100). The higher the point is, the more the staff is satisfied. Because the staffs are very busy, they have only a little leisure time to finish the task. So we just assign one task to one person, of course,one task can not be assigned to different persons. Now we give you all the points and hope you can help us to assign the tasks to make the sum of the points which correspond the assignment is maximum.
 
 Input
 
 Input will contain several test cases. The first line of each case only contains one integer number N(0<=N<=100). N is the number of staffs, also is the number task. And then, the following N lines describe staffs’ attitude. Each line contains n positive integer numbers. The j-th number in the i-th line describes j-th staff’s attitude to the i-th task.N=0 indicates the end of input.
 
 Output
 
 For each test case you should output one line, and just one number in this line. The number is the maximum. 
 
 Sample Input
 2
 10 90
 80 100
 3
 50 60 70
 70 75 80
 80 90 100
 0
 Sample Output
 170
 230
*/