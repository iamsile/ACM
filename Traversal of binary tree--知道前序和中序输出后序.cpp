#include <iostream>
using namespace std;
int a[1001],b[1001];

void print(int s1,int n1,int s2,int n2)
{
    int i,r;
    if (s1>n1||s2>n2)
        return;
    r=a[s1];
    for (i=s2; i<=n2&b[i]!=r; i++);
    print(s1+1,s1+i-s2,s2,i-1); 
    print(s1+i-s2+1,n1,i+1,n2); 
    printf("%8d",r);
}

int main()
{
    int n;
    while (cin >> n&&n) {
        int i;
        char c[50];
        getchar();
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        gets(c);
        for (i=1; i<=n; i++)
            scanf("%8d",&a[i]);
        getchar();
        gets(c);
        for (i=1; i<=n; i++)
            scanf("%8d",&b[i]);
        printf("Postorder Traversal:\n");
        print(1,n,1,n);
        printf("\n");
    }
    return 0;
}
/*
#include<iostream>
#include<stack>
#define N 1001
using namespace std;
stack<int>S;//存放父节点
int pre[N],ino[N];//先序数组和后序数组
int n,i;
void make(int l1,int r1,int l2,int r2)//l1,r1,是先序遍历的数组的开始和末尾，l2,r2是中序的
{
    int i,j;
    S.push(pre[l1]);    //父节点入栈
    for(i=l2;i<=r2;i++)            //找到父节点在中序遍历的位置i
        if(ino[i]==pre[l1])
            break;
    j=i-l2+l1+1;        //确定左子树和右子树在先序遍历的分界点j，即右子树的父节点
    if(j<=r1 && i+1<=r2)
        make(j,r1,i+1,r2);        //求解右子树
    if(l1+1<=j-1 && l2<=i-1)
        make(l1+1,j-1,l2,i-1);        //求解左子树
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&pre[i]);
        for(i=0;i<n;i++)
            scanf("%d",&ino[i]);
        make(0,n-1,0,n-1);
        while(!S.empty())
        {
            printf("%d",S.top());
            S.pop();
            if(!S.empty())
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
*/
/*
 本题是标准的数据结构知识：已知二叉树的前序和中序结果，就决定了一棵二叉树。 
 解题思路如下：已知二叉树的前序结果，最前面的一定是根节点的数据，而在二叉树的中序结果中，根节点之前的是左子树，之后是右子树，据此，可以递归的得到整个二叉树。最后递归输出结果，对于学习过数据结构的人，是再简单不过的了。
 定义树： 
 struct node{ 
 int data; 
 struct node *left,*right;}; 
 建立树： 
 struct node *create_tree(int s1,int n1,int s2,int n2){ 
 int i,r; 
 if(s1>n1||s2>n2)return NULL; 
 struct node *root; 
 root=malloc(sizeof(struct node)); 
 r=pre[s1]; 
 for(i=s2;i<=n2&&in[i]!=r;++i); 
 root->data=r; 
 root->left=create_tree(s1+1,s1+i-s2,s2,i-1); 
 root->right=create_tree(s1+i-s2+1,n1,i+1,n2); 
 return root;} 
 遍历树： 
 void post_visit(struct node *root){ 
 if(root==NULL)return ; 
 post_visit(root->left); 
 post_visit(root->right); 
 printf("%8d",root->data); 
 free(root);}
 建树的同时就递归输出了，没有必要建树。 
 建树主要是说明清楚。 
 post_visit(int s1,int n1,int s2,int n2){ 
 int i,r; 
 if(s1>n1||s2>n2)return; 
 r=pre[s1]; 
 for(i=s2;i<=n2&&in[i]!=r;++i); 
 post_visit(s1+1,s1+i-s2,s2,i-1); 
 post_visit(s1+i-s2+1,n1,i+1,n2); 
 printf("%8d",r);}
 
 Problem description
 We know that there are three major ways to traverse a binary tree:
 1.Preorder traversal: First access the root node,then traversal the left subtree,in the end traversal the right subtree.
 2.Inorder traversal: First access the left subtree,then traversal the root node,in the end traversal the right subtree.
 3.Postorder traversal: First access the left subtree,then traversal the right subtree,in the end traversal the root node.
 Towards the binary tree,it has a very good characteristic:
 If we know the results of the preorder traversal and the inorder traversal for a binary tree,then we can and only can build one binary tree.
 Now give you the results of the preorder traversal and the inorder traversal for a non-null binary tree, please output the result of the postorder traversal for the binary tree.
 
 
 Input
 The input consists of test cases.Each test case contains five lines:
 The first line is a positive integer N, which is the nodes’ number of the binary tree,and each node has an unique id（1<=id<=N）.
 The second line contains a string “Preorder Traversal:”.
 The third line is the result of the preorder traversal for a binary tree.Each integer takes 8- space,to use JustifyRight mode.
 The fourth line contains a string “Inorder Traversal:”.
 The fifth line is the result of the inorder traversal for a binary tree.Each integer takes 8- space,and also use JustifyRight mode.
 N = 0 indicates the end of input.
 
 Output
 For each test case,output two lines :
 The first line contains a string “Postorder Traversal:”.
 The second line is the result of the postorder traversal for the binary tree, each integer takes 8-space,to use JustifyRight mode.
 
 
 Sample Input
 2
 Preorder Traversal:
 1       2
 Inorder Traversal:
 2       1
 10
 Preorder Traversal:
 1       2       3       4       5       6       7       8       9      10
 Inorder Traversal:
 2       7      10       9       8       6       5       4       3       1
 0
 Sample Output
 Postorder Traversal:
 2       1
 Postorder Traversal:
 10       9       8       7       6       5       4       3       2       1
*/