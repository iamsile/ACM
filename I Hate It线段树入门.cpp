#include <iostream>
using namespace std;
#define Max 200001

struct data {
    int l,r,max;
}node[3*Max];
int score[Max];

int max(int a,int b)
{
    return a>b?a:b;
}

void BuildTree(int left,int right,int u)
{
    node[u].l=left;
    node[u].r=right;
    if (left==right)
        node[u].max=score[left];
    else {
        BuildTree(left, (left+right)>>1, 2*u);
        BuildTree(((left+right)>>1)+1, right, 2*u+1);
        node[u].max=max(node[2*u].max, node[2*u+1].max);
    }
}

void Update(int stu,int val,int u)
{
    node[u].max=max(val, node[u].max);
    if (node[u].l==node[u].r) {
        return;
    }
    if (stu<=node[2*u].r)
        Update(stu, val, 2*u);
    else Update(stu, val, 2*u+1);
}

int Query(int left,int right,int u)
{
    if (node[u].l==left&&node[u].r==right)
        return node[u].max;
    if (right<=node[2*u].r)
        return Query(left, right, 2*u);
    if (left>=node[2*u+1].l)
        return Query(left, right, 2*u+1);
    int mid=(node[u].l+node[u].r)>>1;
    return max(Query(left, mid, 2*u), Query(mid+1, right, 2*u+1));
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int i;
        for (i=1; i<=n; i++)
            scanf("%d",&score[i]);
        getchar();
        char c;
        int s,e;
        BuildTree(1, n, 1);
        for (i=0; i<m; i++) {
            cin >> c >> s >> e;
            getchar();
            if (c=='U')
                Update(s, e, 1);
            if (c=='Q')
                printf("%d\n",Query(s, e, 1));
        }
    }
    return 0;
}
/*
 Problem Description
 很多学校流行一种比较的习惯。老师们很喜欢询问，从某某到某某当中，分数最高的是多少。
 这让很多学生很反感。
 
 不管你喜不喜欢，现在需要你做的是，就是按照老师的要求，写一个程序，模拟老师的询问。当然，老师有时候需要更新某位同学的成绩。
 
 
 Input
 本题目包含多组测试，请处理到文件结束。
 在每个测试的第一行，有两个正整数 N 和 M ( 0<N<=200000,0<M<5000 )，分别代表学生的数目和操作的数目。
 学生ID编号分别从1编到N。
 第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩。
 接下来有M行。每一行有一个字符 C (只取'Q'或'U') ，和两个正整数A，B。
 当C为'Q'的时候，表示这是一条询问操作，它询问ID从A到B(包括A,B)的学生当中，成绩最高的是多少。
 当C为'U'的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。
 
 
 Output
 对于每一次询问操作，在一行里面输出最高成绩。
 
 
 Sample Input
 5 6
 1 2 3 4 5
 Q 1 5
 U 3 6
 Q 3 4
 Q 4 5
 U 2 9
 Q 1 5
 
 
 Sample Output
 5
 6
 5
 9
*/