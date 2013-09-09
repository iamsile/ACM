#include <iostream>
#include <math.h>
using namespace std;
char a[1100];

void create(int l,int r)
{
    int b=0,i=0,j,mid=(l+r)/2;
    if (l!=r) {
        create(l, mid);
        create(mid+1, r);
    }
    for (j=l;j<=r; j++) {
        if (a[j]=='1')
            i++;
        else b++;
    }
    if (b>0&&i>0)
        cout << 'F';
    else if (b>0)
        cout << 'B';
    else cout << 'I';
}

int main()
{
    int n;
    while (cin >> n) {
        int i,k=(int)pow(2,n);
        for (i=0; i<k; i++)
            cin >> a[i];
        create(0,k-1);
        cout << '\n';
    }
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct Tree  // 以二叉树结构存储结果
{ char  data;
    int  flag;
    struct Tree *lchild;
    struct Tree *rchild;
}TREE;
struct Stack
{ TREE  *tree;
    struct Stack *next;
};
void get(char *str,int len,TREE *node)
{ char  *sub1,*sub2;
    int i,j;
    if( len == 1 && str[0] == '1')
    { node -> data = 'I';
        node -> lchild = NULL;
        node -> rchild = NULL;
        return ;
    }
    else if( len == 1 && str[0] == '0' )
    { node -> data = 'B';
        node -> lchild = NULL;
        node -> rchild = NULL;
        return ;
    }
    else if( !strchr(str,'1') )
        node -> data = 'B';
    else if( !strchr(str,'0') )
        node -> data = 'I';
    else    node -> data = 'F';
    sub1 = (char*)malloc(len/2 + 2); /* 递归测试 str的前半部分 */
    sub2 = (char*)malloc(len/2 + 2); /* 递归测试 str的后半部分 */
    for(i = 0,len = len >> 1,j = len; i < len; i ++,j ++)
    {  sub1[i] = str[i];
        sub2[i] = str[j];
    }
    sub1[i] = 0;
    sub2[i] = 0;
    node -> lchild = (TREE*)malloc(sizeof(TREE));
    node -> lchild -> flag = 0;
    node -> rchild = (TREE*)malloc(sizeof(TREE));
    node -> rchild -> flag = 0;
    get(sub1,len,node -> lchild);
    free( sub1 );
    get(sub2,len,node -> rchild);
    free( sub2 );
}
void out(TREE *root)  /* 堆栈方式输出结果 */
{ struct Stack *top = NULL,*stemp;
    TREE  *temp;
    if( !root -> lchild && !root -> rchild )
    { printf("%c",root -> data);
        return;
    }
    top = (struct Stack*)malloc(sizeof(struct Stack));
    top -> next = NULL;
    top -> tree = root;
    while( top )
    { if( (!top -> tree -> lchild && !top -> tree -> rchild) || 
         (top -> tree -> lchild -> flag && top -> tree -> rchild -> flag) )
    { stemp = top;
        printf("%c",top -> tree -> data);
        top -> tree -> flag = 1;
        top = top -> next;
        free(stemp);
    }
    else{ temp = top -> tree;
        if( !temp -> lchild -> flag && temp -> lchild )
        {  stemp = (struct Stack*)malloc(sizeof(struct Stack));
            stemp -> next = top;
            stemp -> tree = temp -> lchild;
            top = stemp;
        }
        else if( temp -> rchild )
        {  stemp = (struct Stack*)malloc(sizeof(struct Stack));
            stemp -> next = top;
            stemp -> tree = temp -> rchild;
            top = stemp;
        }
        else { printf("%c",temp -> data);
            temp -> flag = 1;
            stemp = top;
            top = top -> next;
            free( stemp );
        }
    }
    }
}
void free_mem(TREE *root) /* 递归方式释放二叉树 */
{ if( !root -> lchild && !root -> rchild )
{ free( root );
    return ;
}
else if( root -> lchild )
    free_mem( root -> lchild );
else   free_mem( root -> rchild );
}
int main()
{ char  str[1100];
    int len;
    TREE  *root = NULL;
    
    scanf("%d",&len);
    while(scanf("%s",str) != EOF) /* 输入 ctrl + z 退出测试*/
    { root = (TREE*)malloc(sizeof(TREE));
        root -> flag = 0;
        len = strlen(str);
        get(str,len,root);
        out( root );
        free_mem(root);
    }
    return 0;
}
*/
/*
 Problem description
 我们可以把由“0”和“1”组成的字符串分为三类：全“0”串称为B串，全“1”串称为I串，既含“0”又含“1”的串则称为F串。
 
 FBI树是一种二叉树 ，它的结点类型也包括F结点，B结点和I结点三种。由一个长度为2N的“01”串S可以构造出一棵FBI树T，递归的构造方法如下：
 
 1)	T的根结点为R，其类型与串S的类型相同；
 2)	若串S的长度大于1，将串S从中间分开，分为等长的左右子串S1和S2；由左子串S1构造R的左子树T1，由右子串S2构造R的右子树T2。
 
 现在给定一个长度为2N的“01”串，请用上述构造方法构造出一棵FBI树，并输出它的后序遍历序列。 
 
 
 Input
 输入第一行是一个整数N(0 <= N <= 10)，第二行是一个长度为2N的“01”串。
 
 Output
 输出包括一行，这一行只包含一个字符串，即FBI树的后序遍历序列。
 
 Sample Input
 3
 10001011
 Sample Output
 IBFBBBFIBFIIIFF
 */
