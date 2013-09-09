#include <iostream>
using namespace std;
#define N 105
#define FF(i,n) for(i=0;i<n;i++)
int ans[N][N];
int init[N][N];
int buf[N][N];
void matrixMul(int a[][N],int b[][N],int n,int mod){
	int i,j,k;
	FF(i,n)FF(j,n) buf[i][j]=0;
	FF(i,n)FF(k,n) if(a[i][k])FF(j,n) if(b[k][j])
		buf[i][j]=(buf[i][j]+a[i][k]*b[k][j])%mod;
	FF(i,n)FF(j,n) a[i][j]=buf[i][j];
}
void matrixMul(int n,int m,int mod){
	int i,j;
	FF(i,n)FF(j,n) ans[i][j]=(i==j);
	for(;m;m>>=1){
		if(m&1) matrixMul(ans,init,n,mod);
		matrixMul(init,init,n,mod);
	}
}

int main()
{
    int i,j,n,m,mod;
    while (scanf("%d%d%d",&n,&mod,&m)) {
        if (!n&&!m&&!mod)
            break;
        FF(i, n) FF(j, n) scanf("%d",&init[i][j]);
        matrixMul(n,m,mod);
        printf("\n");
        FF(i,n) {
            FF(j,n) {
                if (j)
                    printf(" ");
                printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
 Problem description
 Your task is to write a program to raise an integer matrix to a given power using modulo arithmetic.There is no back story here; at least not one that can be told. The application is too confidential(spying and military intelligence and all that) to be described in public. For example, to raise the 2 by 2 matrix 
 
 to the power 2 using modulo 17 arithmetic 
 
 
 
 Input
 The input consists of a number of problems. Each problem starts with a line holding three numbers (N, M, and P) separated by single spaces. 1 <= N <= 100 is the size (N by N) of the matrix to be processed. 2 <= M <= 32000 is the modulo base and 1 <= P <= 32000 is the power to which the matrix must be raised. Following this line are N lines, each holding the n integer values of successive rows of the matrix as a series of positive integers i: 0 <= i < M separated by single spaces. Input is terminated by a line with three zeros.
 
 Output
 Output for each problem consists of a blank line, followed by the N rows of the result matrix. Each row is output on a single line as a sequence of integer values separated by single spaces. It doesn´t matter that lines may be quite long-no-one will be allowed to read them anyway.
 
 Sample Input
 2 17 2
 1 2
 3 4
 0 0 0
 Sample Output
 
 7 10
 15 5
*/