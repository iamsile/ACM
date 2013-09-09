#include <iostream>
using namespace std;
int flag,a[1011],b[1011];

void print(int s1,int n1,int s2,int n2)
{
    if (s1>n1||s2>n2)
        return;
    int i,r=a[s1];
    for (i=s2; i<=n2&&b[i]!=r; i++);
    print(s1+1,s1+i-s2,s2,i-1);
    print(s1+i-s2+1,n1,i+1,n2);
    if (flag) {
        printf("%d",r);
        flag=0;
    }
    else printf(" %d",r);
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i;
        for (i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for (i=1; i<=n; i++)
            scanf("%d",&b[i]);
        flag=1;
        print(1,n,1,n);
        printf("\n");
    }
    return 0;
}
/*
 Problem Description
 A binary tree is a finite set of vertices that is either empty or consists of a root r and two disjoint binary trees called the left and right subtrees. There are three most important ways in which the vertices of a binary tree can be systematically traversed or ordered. They are preorder, inorder and postorder. Let T be a binary tree with root r and subtrees T1,T2.
 
 In a preorder traversal of the vertices of T, we visit the root r followed by visiting the vertices of T1 in preorder, then the vertices of T2 in preorder.
 
 In an inorder traversal of the vertices of T, we visit the vertices of T1 in inorder, then the root r, followed by the vertices of T2 in inorder.
 
 In a postorder traversal of the vertices of T, we visit the vertices of T1 in postorder, then the vertices of T2 in postorder and finally we visit r.
 
 Now you are given the preorder sequence and inorder sequence of a certain binary tree. Try to find out its postorder sequence.
 
 
 
 Input
 The input contains several test cases. The first line of each test case contains a single integer n (1<=n<=1000), the number of vertices of the binary tree. Followed by two lines, respectively indicating the preorder sequence and inorder sequence. You can assume they are always correspond to a exclusive binary tree.
 
 
 Output
 For each test case print a single line specifying the corresponding postorder sequence.
 
 
 Sample Input
 9
 1 2 4 7 3 5 8 9 6
 4 7 2 1 8 5 9 3 6
 
 
 Sample Output
 7 4 2 8 9 5 6 3 1
*/