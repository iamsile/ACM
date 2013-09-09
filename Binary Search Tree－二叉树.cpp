#include <iostream>
using namespace std;

struct node {
    int v;
    node *left,*right;
};
int n;

void print(node *s)
{
    if (s->left)
        print(s->left);
    if (s->right)
        print(s->right);
    printf("%d\n",s->v);
}

void build(node *t,int maxn)
{
    node *m;
    if (t->v>n) {
        if (!t->left) {
            t->left=m=new node();
            m->left=m->right=NULL;
            m->v=n;
            if (scanf("%d",&n)<1)
                return;
        }
        build(t->left, t->v);
    }
    if (n>maxn)
        return;
    if (t->v<n) {
        if (!t->right) {
            t->right=m=new node();
            m->left=m->right=NULL;
            m->v=n;
            if (scanf("%d",&n)<1)
                return;
        }
        build(t->right, maxn);
    }
}

int main()
{
    node tree;
    tree.right=tree.left=NULL;
    scanf("%d",&tree.v);
    if (scanf("%d",&n)>0)
        build(&tree,(int)1e7);
    print(&tree);
    return 0;
}

/*
#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
struct node {
    int v;
    node *left;
    node *right;
};
int n,a[100000];
set<int> que;

node *build(int s)
{
    node *m=new node;
    m->v=a[s++];
    que.insert(m->v);
    if (s!=n&&a[s]<m->v)
        m->left=build(s);
    if (s!=n&&a[s]<*que.upper_bound(m->v))
        m->right=build(s);
    return m;
}

void dfs(node *m) {
    if (m->left) 
        dfs(m->left);
    if (m->right) 
        dfs(m->right);
    printf("%d\n", m->v);
}

int main()
{
    n=0;
    que.insert(1<<20);
    while (~scanf("%d",&a[n])) {
        n++;
    }
    int s=0;
    node *tree=build(0);
    dfs(tree);
    return 0;
}
*/
/*
 Problem description
 A binary search tree is a binary tree that satisfies the following properties:
 • The left subtree of a node contains only nodes with keys less than the node's key.
 • The right subtree of a node contains only nodes with keys greater than the node's key.
 • Both the left and right subtrees must also be binary search trees.
 
 Pre-order traversal (Root-Left-Right) prints out the node’s key by visiting the root node then traversing the left subtree and then traversing the right subtree. Post-order traversal (Left ? Right-Root) prints out the left subtree first and then right subtree and finally the root node. For example, the results of pre-order traversal and post-order traversal of the binary tree shown in Figure 1 are as follows:
 Pre-order: 50 30 24 5 28 45 98 52 60
 Post-order: 5 28 24 45 30 60 52 98 50
 Given the pre-order traversal of a binary search tree, you task is to find the post-order traversal of this tree. 
 
 Input
 The keys of all nodes of the input binary search tree are given according to pre-order traversal. Each node has a key value which is a positive integer less than 106. All values are given in separate lines (one integer per line). You can assume that a binary search tree does not contain more than 10,000 nodes and there are no duplicate nodes.
 
 Output
 The output contains the result of post-order traversal of the input binary tree. Print out one key per line.
 
 Sample Input
 50
 30
 24
 5
 28
 45
 98
 52
 60
 Sample Output
 5
 28
 24
 45
 30
 60
 52
 98
 50
*/