#include<stdio.h> 
#define MAX 500000 
int f[500001]={0};
int main() 
{ 
    int t,n,i,j; 
    f[0]=f[1]=0; 
    for(i=1;i<=MAX/2;i++) 
        for(j=i+i;j<=MAX;j+=i)
            f[j]+=i; 
    scanf("%d",&t); 
    while(t--) 
    { 
        scanf("%d",&n);
        printf("%d\n",f[n]);
    } 
    return 0; 
}
/*
 Problem Description
 七夕节那天,月老来到数字王国,他在城门上贴了一张告示,并且和数字王国的人们说:"你们想知道你们的另一半是谁吗?那就按照告示上的方法去找吧!"
 人们纷纷来到告示前,都想知道谁才是自己的另一半.告示如下:
 
 
 
 
 数字N的因子就是所有比N小又能被N整除的所有正整数,如12的因子有1,2,3,4,6.
 你想知道你的另一半吗?
 
 
 Input
 输入数据的第一行是一个数字T(1<=T<=500000),它表明测试数据的组数.然后是T组测试数据,每组测试数据只有一个数字N(1<=N<=500000).
 
 
 Output
 对于每组测试数据,请输出一个代表输入数据N的另一半的编号.
 
 
 Sample Input
 3
 2
 10
 20
 
 
 Sample Output
 1
 8
 22
 */