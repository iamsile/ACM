#include <iostream>
#include <string.h>
using namespace std;

struct node {
    char data;
}tree[1024],judge[1024];

bool eq(struct node c[],struct node e[])
{
    int i;
    for(i=1;i<1024 && c[i].data==e[i].data;i++);
    if(i==1024)
        return true;
    return false;
}

int main()
{
    int t;
    while (cin >> t&&t) {
        char a[1024];
        cin >> a;
        int k=strlen(a),i,j;
        for (i=1; i<1024; i++)
            tree[i].data=-1;
        tree[1].data=a[0];
        for (i=1; i<k; i++) {
            j=1;
            while (tree[j].data!=-1) {
                if (a[i]>tree[j].data)
                    j=j*2+1;
                else j=j*2;
            }
            tree[j].data=a[i];
        }
        while (t--) {
            cin >> a;
            k=strlen(a);
            for (i=1; i<1024; i++)
                judge[i].data=-1;
            judge[1].data=a[0];
            for(i=1;i<k;i++) {
                j=1;
                while(judge[j].data!=-1) {
                    if(a[i]>judge[j].data)
                        j=2*j+1;
                    else
                        j=2*j;
                }
                judge[j].data=a[i];
            }
            if(eq(tree,judge))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
/*
 Problem Description
 判断两序列是否为同一二叉搜索树序列
 
 
 Input
 开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
 接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
 接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
 
 
 Output
 如果序列相同则输出YES，否则输出NO
 
 
 Sample Input
 2
 567432
 543267
 576342
 0
 
 
 Sample Output
 YES
 NO
*/