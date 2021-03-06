#include<stdio.h>
#include<string.h>

int le[30],n1[55],n2[55];

void GF(  )
{
    memset(n1,0,sizeof(n1));
    memset(n2,0,sizeof(n2));
    n1[0]=1; //在上一篇报告里面讲过其作用，可以说是一个入口 
    for(int i=1;i<=26;++i)
    {
        for(int j=0;j<=50;++j)  
            // j从0开始还是为了保留未参与合并的原值 
            for(int k=0;k<=le[i]&&k*i+j<=50;k++)
                // k从0开始是为了保留n1[x]中原有的值，不至于在
                // 后面n1[x]=n2[x]语句中出现n1[x]数据丢失。 
                n2[j+k*i]+=n1[j]; // 这和前面的判断是否存在（只需赋值 为1）组合不同 
        for(int j=0;j<=50;++j)
        { 
            n1[j]=n2[j]; // k从0开始保证了n1[x]只增不减 
            n2[j]=0;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    { 
        int cnt=0;
        for(int i=1;i<=26;++i)
            scanf("%d",&le[i]);
        GF();
        for(int i=1;i<=50;++i) // 题目是要统计小于50的所有可能 
            cnt+=n1[i];
        printf("%d\n",cnt);
    }
    return 0;
}
/*
 Problem Description
 假设有x1个字母A， x2个字母B,..... x26个字母Z，同时假设字母A的价值为1，字母B的价值为2,..... 字母Z的价值为26。那么，对于给定的字母，可以找到多少价值<=50的单词呢？单词的价值就是组成一个单词的所有字母的价值之和，比如，单词ACM的价值是1+3+14=18，单词HDU的价值是8+4+21=33。(组成的单词与排列顺序无关，比如ACM与CMA认为是同一个单词）。
 Input
 输入首先是一个整数N，代表测试实例的个数。
 然后包括N行数据，每行包括26个<=20的整数x1,x2,.....x26.
 Output
 对于每个测试实例，请输出能找到的总价值<=50的单词数,每个实例的输出占一行。
 Sample Input
 2
 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 9 2 6 2 10 2 2 5 6 1 0 2 7 0 2 2 7 5 10 6 10 2 10 6 1 9
 Sample Output
 7
 379297
*/