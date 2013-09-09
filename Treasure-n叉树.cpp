#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

struct tree {
    unsigned int cnt;
    vector<string> next;
    tree():cnt(1) {};
    void add(const string &s) {
        next.push_back(s);
    }
    bool leaf() {
        return next.size() == 0;
    }
};

void ncount(map<string, tree> &root, const string &parent,unsigned cnt=1)
{
    if (root[parent].leaf()) {
        root[parent].cnt=cnt;
        return;
    }
    for (vector<string>::const_iterator it=root[parent].next.begin();
         it!=root[parent].next.end(); it++) {
        ncount(root, *it,cnt*root[parent].next.size());
    }
}

int main()
{
    string a;
    while (getline(cin, a)) {
        if (a=="**")
            break;
        vector<string> n;
        map<string, tree> root;
        bool f=1;
        do {
            istringstream is(a);
            string parent,child;
            is >> parent;
            if (f)
                n.push_back(parent);
            while (is >> child) {
                n.push_back(child);
                root[parent].add(child);
            }
            f=0;
            getline(cin, a);
        }while (a!="*");
        ncount(root,n[0]);
        for (vector<string>::const_iterator it=n.begin(); it!=n.end(); it++)
            if (root[*it].leaf())
                cout << *it << ": 1/" << root[*it].cnt << '\n';
        cout << "--------------------\n";
    }
    return 0;
}
/*
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

struct Info {
    unsigned int denom;
    vector<string> children;
    
    Info()
    : denom(1) { };
    
    void add_child(const string &child)
    {
        children.push_back(child);
    }
    
    bool is_leaf() const
    {
        return children.size() == 0;
    }
};

void distribute(map<string, Info> &info, const string &parent,
                unsigned int denom = 1)
{
    if (info[parent].is_leaf()) {
        info[parent].denom = denom;
        return;
    }
    
    for (vector<string>::const_iterator it = info[parent].children.begin();
         it != info[parent].children.end(); ++it) {
        distribute(info, *it, denom * info[parent].children.size());
    }
}

bool do_case(void)
{
    string line;
    
    getline(cin, line);
    if (line == "**") {
        return false;
    }
    
    vector<string> names;
    map<string, Info> info;
    
    // build the tree
    bool first = true;
    do {
        istringstream iss(line);
        string parent, child;
        iss >> parent;
        if (first) {
            // if not first, the parent has already appeared as a child before
            names.push_back(parent);
        }
        while (iss >> child) {
            names.push_back(child);
            info[parent].add_child(child);
        }
        first = false;
        getline(cin, line);
    } while (line != "*");
    
    // process the tree
    distribute(info, names[0]);
    
    // print the results
    for (vector<string>::const_iterator it = names.begin(); it != names.end();
         ++it) {
        if (info[*it].is_leaf()) {
            cout << *it << ": 1/" << info[*it].denom << endl;
        }
    }
    
    return true;
}

int main(void)
{
    while (do_case()) {
        cout << "--------------------"  << endl;
    }
    
    return 0;
}

*/
/************************************************************************/
/* coder:huifeng00                                                      */
/* 时间：2010-5-12 下午 9点                                             */
/* 实现：多叉树的后序遍历，先序遍历，及其释放操作                       */
/* 语言：C       工具：VC++6.0                                          */
/************************************************************************/
/*
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#define MAXSIZE 5//这是多叉树最多可以的分支数
typedef struct _TREENODE
{
        int data;
        int cnChild;
        struct _TREENODE *parent;
        struct _TREENODE *child[MAXSIZE];
} TREENODE, *PTREENODE;

PTREENODE InsertNode(PTREENODE *ppNode,int data)//向一个多叉树节点插入一个孩子节点
{
        int cnChild = (*ppNode)->cnChild;
        PTREENODE temp = (PTREENODE)malloc(sizeof(TREENODE));
        temp->data = data;
        temp->cnChild =0;
        temp->parent = *ppNode;
        memset(temp->child,0,MAXSIZE);
        
        (*ppNode)->child[cnChild] = temp;
        (*ppNode)->cnChild++;
        return temp;
}

void PrintTree(PTREENODE root)//递归格式化先序打印多叉树
{
        static depth = 0;
        int i;
        if (root == NULL)
            {
                    return;
                }
        for (i=0;i<depth;i++)
            {
                    printf(" ");
                }
        printf("%d\n",root->data);
        for (i=0;i<root->cnChild;i++)
            {
                    depth++;
                    PrintTree((root->child)[i]);
                    depth--;
                }
}

void PrintTreelast(PTREENODE root)//递归格式化后序打印多叉树
{
        static depth = 0;
        int i;
        if (root == NULL)
            {
                    return;
                }
        
        for (i=0;i<root->cnChild;i++)
            {
                    depth++;
                    PrintTreelast((root->child)[i]);
                    depth--;
                }
        for (i=0;i<depth;i++)
            {
                    printf(" ");
                }
        printf("%d\n",root->data);
}
void destroyTree(PTREENODE root)//释放多叉树节点所占内存
{
        int i;
        if (root == NULL)
            {
                    return;
                }
        for (i=0;i<root->cnChild;i++)
            {
                    destroyTree((root->child)[i]);
                }
        free(root);
}

int main()
{
        PTREENODE root = (PTREENODE)malloc(sizeof(TREENODE));//根节点
        PTREENODE temp1,temp2;
        root->data = 1;
        root->cnChild =0;
        root->parent = NULL;
        memset(root->child,0,MAXSIZE);
        
        
        //对根节点插入2个孩子
        temp1 = InsertNode(&root,11);
        temp2 = InsertNode(&root,12);
        
        //对第一个孩子节点插入3个孩子节点
        InsertNode(&temp1,111);
        InsertNode(&temp1,112);
        InsertNode(&temp1,113);
        
        //对第二个孩子节点插入3个孩子节点
        InsertNode(&temp2,121);
        InsertNode(&temp2,122);
        InsertNode(&temp2,123);
        
        PrintTree(root);//先序打印多叉树
        printf("*****************\n");
        PrintTreelast(root);//后序打印多叉树
        destroyTree(root);//后序释放多叉树节点
        return 0;
}
*/
/*
 Problem description
 
 Figure 1: Example family tree.
 
 Distribute an inheritance among the heirs.
 
 A rich person buries a treasure chest in their back yard and dies. Years (perhaps generations) later, the chest is unearthed, its contents are sold, and the proceeds are distributed among the living descendants. To this end, a family tree is drawn. The family tree starts with the originator (who buried the treasure) and traces the genealogy down to the currently living descendents.
 
 Any person X who appears in the family tree along with one or more descendants, is deceased. The share of the inheritance of any such person X is divided equally among those children of X who are either currently living or produced (directly or indirectly) currently living descendants. (Any deceased descendants of the originator who did not produce further descendants are omitted from the family tree.)
 
 Any person Y who is shown in the family tree without descendants, is a currently living descendant. Your goal is to determine the fractional share of the inheritance for each such person Y. The sum of the shares must of course equal 1. (Such a person Y may in reality have some living descendants, but they will not be shown in the family tree.)
 
 Consider, for example, the family tree of figure 1. The originator is Judith. The currently living descendants (shown without children in the family tree) are Dick, Cathy, Maggie, Carl, and Bob. Their respective shares of the inheritance are: 1/3, 1/6, 1/12, 1/12 and 1/3.
 
 
 
 Input
 The input will contain data for a number of problem instances. For each problem instance, the input will represent a family tree on one or more lines. The first problem instance in the sample input (below) corresponds to the family tree of Figure 1.
 
 The first line will begin with the name of the originator, followed by a list of the originator’s children (there will be at least one).
 
 There will be one additional line for each deceased descendant. Each of those lines will begin with the name of the deceased descendant, followed by the list of his or her children.
 
 Each problem instance will be terminated with a line containing a single asterisk (*). The input will be terminated with a line containing two asterisks.
 
 Notes:
 
 A name consists of upper / lower case letters.
 Names are delimited by (one or more) blank spaces.
 No name will occur more than once in the family tree for one problem instance.
 
 
 Output
 For each problem instance, the output will consist of the list of living descendants from the family tree, one name per line. Each name will be followed by a colon, one blank space, and the corresponding fractional share of the inheritance, in the form 1/N.
 
 You may assume the input will be such that this N will be within the bounds of 32-bit (signed) integer variables.
 
 The names will be listed in the same order in which they appear in the input.
 
 The output will not contain any blank spaces, except the one blank space following each colon.
 
 Each problem instance will be followed by a line of 20 hyphens (-).
 
 
 
 Sample Input
 Judith Dick Ethel Linda
 Ethel Cathy Jack 
 Jack Maggie Carl
 Linda Bob
 *
 Bill Jill
 *
 Jackie Rod Sarah
 Rod Albert
 Albert Carol Susie Max
 *
 **
 Sample Output
 Dick: 1/3
 Cathy: 1/6
 Maggie: 1/12
 Carl: 1/12
 Bob:  1/3
 -------------------
 Jill: 1/1
 -------------------
 Sarah: 1/2
 Carol: 1/6
 Susie: 1/6
 Max: 1/6
 -------------------
*/