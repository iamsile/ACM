#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char a[101];
    int v,ci;
	double ave;
}dic;
dic word[1000001];

int cmp(const void *a,const void *b)
{
	dic *x=(dic *)a;
	dic *y=(dic *)b;
    
	if(x->ave != y->ave)return y->ave>x->ave?1:-1;
	else return y->v-x->v;
}
int main()
{
    long n,c;
    while (scanf("%ld%ld",&n,&c)!=EOF)
	{
        long i,sum;
        for (i=0; i<n; i++)
        {
            scanf("%s%d%d",word[i].a,&word[i].v,&word[i].ci);
            word[i].ave=(double)word[i].v/word[i].ci;
        }
        qsort(word, n, sizeof(word[0]), cmp);
		sum=0;
        for (i=0; i<n && c>=0; i++)
            if (word[i].ci <= c)
			{
                sum+=word[i].v;
                c-=word[i].ci;
            }
		printf("%ld\n",sum);
    }
    return 0;
}
/*
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int p[11][11];
int pack[10001];

int main()
{
    int n,V,i,t,c;
    char str[11];
    while(scanf("%d%d",&n,&V)!=EOF){
        memset(p,0,sizeof(p));
        memset(pack,0,sizeof(int)*(V+1));
        for(i=1;i<=n;i++){
            scanf("%s%d%d",str,&t,&c);
            p[c][t]++;
        }
        int i,j,k;
        int tc,tv,temp;
        for(i=0;i<=10;i++){
            for(j=1;j<=10;j++){
                if(!p[i][j])
                    continue;
                temp=1;
                while(p[i][j]){
                    if(p[i][j]<temp)
                        temp=p[i][j];
                    tv=i*temp;
                    tc=j*temp;
                    for(k=V;k>=tv;k--){
                        pack[k]=max(pack[k],pack[k-tv]+tc);
                    }
                    p[i][j]-=temp;
                    temp*=2;
                }
            }
        }
        printf("%d\n",pack[V]);
    }
    return 0;
}
*/
/*
 Problem Description
 We all know that English is very important, so Ahui strive for this in order to learn more English words. To know that word has its value and complexity of writing (the length of each word does not exceed 10 by only lowercase letters), Ahui wrote the complexity of the total is less than or equal to C.
 Question: the maximum value Ahui can get.
 Note: input words will not be the same.
 Input
 The first line of each test case are two integer N , C, representing the number of Ahui’s words and the total complexity of written words. (1 ≤ N ≤ 100000, 1 ≤ C ≤ 10000)
 Each of the next N line are a string and two integer, representing the word, the value(Vi ) and the complexity(Ci ). (0 ≤ Vi , Ci ≤ 10)
 Output
 Output the maximum value in a single line for each test case.
 Sample Input
 5 20
 go 5 8
 think 3 7
 big 7 4
 read 2 6
 write 3 5
 Sample Output
 15
*/