#include <iostream>
#include <queue>
using namespace std;
#define x 130

struct node {
    int flag;
    node *next[x],*fail;
    node() {
        flag=0;
        memset(next, 0, sizeof(next));
        fail=NULL;
    }
};

int b[51],len;

void build(int m,char s[],node *root)
{
    int i,j,k=strlen(s);
    for (i=0; i<k; i++) {
        j=s[i];
        if (root->next[j]==NULL)
            root->next[j]=new node();
        root=root->next[j];
    }
    root->flag=m;
}

void buildac(node *root)
{
    root->fail=NULL;
    queue<node *> q;
    node *cur,*p;
    q.push(root);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        for (int i=0; i<x; i++)
            if (cur->next[i]) {
                p=cur->fail;
                while (p) {
                    if (p->next[i]) {
                        cur->next[i]->fail=p->next[i];
                        break;
                    }
                    p=p->fail;
                }
                if (p==NULL)
                    cur->next[i]->fail=root;
                q.push(cur->next[i]);
            }
    }
}

void query(char s[],node *root)
{
    int i,ind,k=strlen(s);
    node *cur,*p=root;
    for (i=0; i<k; i++) {
        ind=s[i];
        while (p->next[ind]==NULL&&p!=root)
            p=p->fail;
        p=p->next[ind];
        if (p==NULL)
            p=root;
        cur=p;
        while (cur!=root) {
            if (cur->flag)
                b[len++]=cur->flag;
            cur=cur->fail;
        }
    }
}

int main()
{
    int n,m;
    while (~scanf("%d",&n)) {
        int i,j,sum=0;
        char a[210],str[10010];
        node *root=new node();
        for (i=1; i<=n; i++) {
            scanf("%s",a);
            build(i,a,root);
        }
        buildac(root);
        scanf("%d",&m);
        for (i=1; i<=m; i++) {
            scanf("%s",str);
            len=0;
            memset(b, 0, sizeof(b));
            query(str,root);
            if (len) {
                sort(b, b+len);
                printf("web %d:",i);
                for (j=0; j<len; j++)
                    printf(" %d",b[j]);
                printf("\n");
                sum++;
            }
        }
        printf("total: %d\n",sum);
    }
    return 0;
}
/*
 Problem Description
 当太阳的光辉逐渐被月亮遮蔽，世界失去了光明，大地迎来最黑暗的时刻。。。。在这样的时刻，人们却异常兴奋——我们能在有生之年看到500年一遇的世界奇观，那是多么幸福的事儿啊~~
 但网路上总有那么些网站，开始借着民众的好奇心，打着介绍日食的旗号，大肆传播病毒。小t不幸成为受害者之一。小t如此生气，他决定要把世界上所有带病毒的网站都找出来。当然，谁都知道这是不可能的。小t却执意要完成这不能的任务，他说：“子子孙孙无穷匮也！”（愚公后继有人了）。
 万事开头难，小t收集了好多病毒的特征码，又收集了一批诡异网站的源码，他想知道这些网站中哪些是有病毒的，又是带了怎样的病毒呢？顺便还想知道他到底收集了多少带病毒的网站。这时候他却不知道何从下手了。所以想请大家帮帮忙。小t又是个急性子哦，所以解决问题越快越好哦~~
 
 
 Input
 第一行，一个整数N（1<=N<=500），表示病毒特征码的个数。
 接下来N行，每行表示一个病毒特征码，特征码字符串长度在20—200之间。
 每个病毒都有一个编号，依此为1—N。
 不同编号的病毒特征码不会相同。
 在这之后一行，有一个整数M（1<=M<=1000），表示网站数。
 接下来M行，每行表示一个网站源码，源码字符串长度在7000—10000之间。
 每个网站都有一个编号，依此为1—M。
 以上字符串中字符都是ASCII码可见字符（不包括回车）。
 
 
 Output
 依次按如下格式输出按网站编号从小到大输出，带病毒的网站编号和包含病毒编号，每行一个含毒网站信息。
 web 网站编号: 病毒编号 病毒编号 …
 冒号后有一个空格，病毒编号按从小到大排列，两个病毒编号之间用一个空格隔开，如果一个网站包含病毒，病毒数不会超过3个。
 最后一行输出统计信息，如下格式
 total: 带病毒网站数
 冒号后有一个空格。
 
 
 Sample Input
 3
 aaa
 bbb
 ccc
 2
 aaabbbccc
 bbaacc
 
 
 Sample Output
 web 1: 1 2 3
 total: 1
*/