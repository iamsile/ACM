#include <iostream>
#include <string.h>
#include <math.h>
using namespace::std;
char map[7][1000][1000];

void find(int n)
{ 
	int i,j,k;
    for(i=0;i<pow(3,n-1);i++)
    {
        for(j=pow(3,n-1);j>=0;j--)
            if(map[n-1][i][j]=='X')
                break;
        for(k=0;k<=j;k++)
        {
            putchar(map[n-1][i][k]=='X'?'X':' ');
        }
        putchar('\n');
    }
}
void copy(int n,int x,int y,int size)
{
    int i,j;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            map[n+1][i+x][j+y]=map[n][i][j];
}
void init()
{ 
    int i,size;
    map[0][0][0]='X';    
    for(i=1;i<7;i++)
    {
        size=pow(3,i-1);
        copy(i-1,0,0,size);//计算左上角的值
        copy(i-1,0,size*2,size);//计算左下角的值
        copy(i-1,size,size,size);//计算中间的值
        copy(i-1,2*size,0,size);//计算右上角的值
        copy(i-1,2*size,2*size,size);//计算右下角的值
    }    
}

int main()
{
    int n;
    memset(map,' ',sizeof(map));
    init();
    while(cin >> n&&n!=-1)
    { 
        find(n);
        printf("-\n");
    }
    return 0;
}

/*#include <iostream>
#include <math.h>
#include <string.h>
using namespace::std;

char a[740][740];

int f(int b,int p,int q)
{
	int m,n,l;
	m=(int)pow(3, b-1);
	n=m/3;
	l=2*m/3;
	if(b==1)
	{
		a[p][q]='X';
		return 0;
	}
	else 
		if(b>1)
		{
			f(b-1,p,q);//计算的是a[0][0]
			f(b-1,p,l+q);//右上角的那个a[p][l+q]	
			f(b-1,l+p,q);//左下角的那个a[n+p][n+q]
			f(b-1,n+p,n+q);//最中心的那个a[n+p][n+p]
			f(b-1,l+p,l+q);//右下角的那个a[l+p][l+q]
		}
	return 0;
}

int main()
{
	int i,j,num;
	while(scanf("%d",&num)!=EOF)
	{
		memset(a, ' ', sizeof(a));
		f(num,0,0);
		for(i=0;i<pow(3, num-1);i++)
		{
			for(j=0;j<pow(3, num-1);j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}
 //超时的代码。。。。(递归的方法）
*/

/*
 Problem description
 A fractal is an object or quantity that displays self-similarity, in a somewhat technical sense, on all scales. The object need not exhibit exactly the same structure at all scales, but the same "type" of structures must appear on all scales. 
 A box fractal is defined as below : 
 　
 A box fractal of degree 1 is simply 
 X 
 　
 A box fractal of degree 2 is 
 X  X 
 X 
 X  X 
 　
 If using B(n - 1) to represent the box fractal of degree n - 1, then a box fractal of degree n is defined recursively as following 
 　
 B(n - 1)        B(n - 1)
 
 B(n - 1)
 
 B(n - 1)        B(n - 1)
 
 Your task is to draw a box fractal of degree n.
 
 
 Input
 The input consists of several test cases. Each line of the input contains a positive integer n which is no greater than 7. The last line of input is a negative integer −1 indicating the end of input.
 
 Output
 For each test case, output the box fractal using the 'X' notation. Please notice that 'X' is an uppercase letter. Print a line with only a single dash after each test case. be careful, no extra blankspace allowed in the output.
 
 Sample Input
 1
 2
 3
 4
 -1
 Sample Output
 X
 -
 X X
  X
 X X
 -
 X X   X X
  X     X
 X X   X X
    X X
     X
    X X
 X X   X X
  X     X
 X X   X X
 -
 X X   X X         X X   X X
  X     X           X     X
 X X   X X         X X   X X
	X X               X X
	 X                 X
	X X               X X
 X X   X X         X X   X X
  X     X           X     X
 X X   X X         X X   X X
          X X   X X
           X     X
          X X   X X
             X X
              X
             X X
          X X   X X
           X     X
          X X   X X
 X X   X X         X X   X X
  X     X           X     X
 X X   X X         X X   X X
    X X               X X
     X                 X
    X X               X X
 X X   X X         X X   X X
  X     X           X     X
 X X   X X         X X   X X
 -
*/