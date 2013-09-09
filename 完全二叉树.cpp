#include <iostream>
#include <queue>
using namespace std;

struct tree {
    int v,fk;
    tree() {
        v=0;
        fk=1;
        left=right=NULL;
    };
    tree *left,*right;
};

void dele(tree *r)
{
    if (r->left)
        dele(r->left);
    if (r->right)
        dele(r->right);
    delete r;
}

int main()
{
    char a[101];
    tree *root=new tree,*labr;
    labr=root;
    int lab=0;
    while (~scanf("%s",a)) {
        if (strcmp(a, "()")==0) {
            int i,c[1001]={0},cnt=0,flag=0;
            queue<tree> q;
            tree *cur=root;
            q.push(*cur);
            while (!q.empty()) {
                *cur=q.front();
                q.pop();
                c[cnt++]=cur->v;
                if (cur->fk) {
                    flag=1;
                    break;
                }
                if (cur->left)
                    q.push(*cur->left);
                if (cur->right)
                    q.push(*cur->right);
            }
            if (flag||lab)
                printf("not complete\n");
            else {
                for (i=0; i<cnt; i++) {
                    if (i)
                        printf(" ");
                    printf("%d",c[i]);
                }
                printf("\n");
            }
            dele(root);
            tree *root=new tree;
            labr=root;
            lab=0;
        }
        else {
            char b[100];
            int i,n,k;
            sscanf(a, "(%d,%s)", &n,b);
            k=strlen(b)-1;
            for (i=0; i<k; i++) {
                if (b[i]=='L') {
                    if (root->left==NULL)
                        root->left=new tree;
                    root=root->left;
                }
                else if (b[i]=='R') {
                    if (root->right==NULL)
                        root->right=new tree;
                    root=root->right;
                }
            }
            if (root->fk==1) {
                root->v=n;
                root->fk=0;
            }
            else if (root->v)
                lab=1;
            root=labr;
        }
    }
    return 0;
}
/*
#include<iostream>
using namespace std;
struct node
{
	int num;
	char str[1000];
}nod[1000000],temp;
char str[1000];
int comp(const void *a,const void *b)
{
	if(strlen(((node*)a)->str)!=strlen(((node*)b)->str))
		return strlen(((node*)a)->str)-strlen(((node*)b)->str);
	return strcmp(((node*)a)->str,((node*)b)->str);
}
void deal(int i)
{
	int pos=i,j,flag=0;
	for(i=0;i<pos;i++)
		nod[i].str[strlen(nod[i].str)-1]='\0';
	qsort(nod,pos,sizeof(temp),comp);	
	for(i=0;i<pos-1;i++)
		if(strcmp(nod[i].str,nod[i+1].str)==0)
		{
			flag=1;
			break;
		}
	for(i=pos-1;i>0;i--)
	{
		strcpy(str,nod[i].str);
		str[strlen(str)-1]='\0';
		for(j=i-1;j>=0;j--)
			if(strcmp(str,nod[j].str)==0)
				break;
		if(j<0)
			break;
	}
	if(i>0||!pos||flag)
	{
		puts("not complete");
		return;
	}
	printf("%d",nod[0].num);
	for(i=1;i<pos;i++)
		printf(" %d",nod[i].num);
	putchar(10);
}
int main()
{
	int i=0;
	while(~scanf("%s",str))
	{
		if(strcmp(str,"()")==0)
		{
			deal(i);
			i=0;
			continue;
		}
		sscanf(str,"(%d,%s",&nod[i].num,nod[i].str);
		i++;
	}
	return 0;
}
*/
/*
#include <iostream>
#include <cmath>
#define MAX_TEST 1000000
using namespace std;

typedef struct node{
    int first,second;
}NODE;
NODE gNode[400];
bool gbFlag[MAX_TEST]={false},bFlag=false;

void mySet(int j, int& m,int& gN){
    if(gbFlag[j])
        bFlag = true;
    else{
        gbFlag[j] = true;
        gNode[gN].first = j;
        gNode[gN++].second = m;
    }
}

int myCmp(const void *a,const void *b){
    if(((NODE*)a)->first > ((NODE*)b)->first)
        return 1;
    else if(((NODE*)a)->first < ((NODE*)b)->first)
        return -1;
    return 0;
}

int main(){ 
    char buf[30],str[60];
    int i,j,m,gN=0,sum;
    while(cin>>str){
        if(!strcmp(str,"()")){
            if(!bFlag && gbFlag[1]){
                qsort(gNode,gN,sizeof(NODE),myCmp);
                for(i=1; i<gN; i++){
                    if(gbFlag[gNode[i].first] && !gbFlag[gNode[i].first>>1]){
                        cout<<"not complete"<<endl;
                        break;
                    }
                }
                if(i>=gN){
                    cout<<gNode[0].second;
                    for(i=1; i<gN; i++)
                        cout<<" "<<gNode[i].second;
                    cout<<endl;
                }
            }else
                cout<<"not complete"<<endl;
            for(i=0; i<gN; i++)
                gbFlag[gNode[i].first]=false;
            gN = bFlag =false;
        }
        else if(!bFlag){
            for(j=(int)strlen(str),i=1; str[i]!=','; i++)
                buf[i-1]=str[i];
            buf[i-1]='\0';
            m = atoi(buf);
            if(str[i+1]==')'){
                mySet(1,m,gN);
                continue;
            }
            sum = (int)pow((float)2,j-i-2);
            for(i=1,j-=2; str[j]!=','; j--,i<<=1){
                if(str[j]=='R')
                    sum+=i;
            }
            mySet(sum,m,gN);
        }
    } 
    return 0;
}
#include<cstdio>
#include<queue>
using namespace std;
char str[100];
struct Node {
    int time, value;
    Node *left, *right;
    Node() {
        time=0;
        value=0;
        left=right=NULL;
    }
};
struct Tree {
    Node *head;
    void Create() {
        head = new Node;
    }
    void Destroy( Node *pos ) {
        if( pos->left ) Destroy( pos->left );
        if( pos->right ) Destroy( pos->right );
        delete pos;
    }
    void Add( char *str ) {
        int v, si;
        sscanf( str, "(%d", &v );
        for( si=1; str[si]!=','; ++si );
        Node *p=head;
        for( ; str[si]; ++si ) {
            if( str[si]=='L' ) {
                if( p->left==NULL )
                    p->left=new Node;
                p=p->left;
            }
            if( str[si]=='R' ) {
                if( p->right==NULL )
                    p->right=new Node;
                p=p->right;
            }
        }
        ++(p->time);
        p->value=v;
    }
    bool Check( Node *pos ) {
        if( pos==NULL ) return true;
        if( pos->time!=1 ) return false;
        return Check( pos->left ) && Check( pos->right );
    }
    void Output() {;
        queue<Node*> aqe;
        aqe.push( head );
        while( !aqe.empty() ) {
            if( aqe.front()->left )
                aqe.push( aqe.front()->left );
            if( aqe.front()->right )
                aqe.push( aqe.front()->right );
            printf( "%d", aqe.front()->value );
            if( aqe.size()>1 ) putchar(' ');
            aqe.pop();
        }
        putchar('\n');
    }
};
int main() {
    Tree atr;
    atr.Create();
    while( EOF != scanf( "%s", str ) ) {
        if( str[1]==')' ) {
            if( atr.head==NULL || atr.Check( atr.head )==false )
                printf( "not complete\n" );
            else atr.Output();
            atr.Destroy( atr.head );
            atr.Create();
        }else atr.Add( str );
    }
    return 0;
}
*/
/*
 Problem description
 “树”在计算机科学中是一种非常重要的 数据结构。它的应用极为广泛，从计算机图形学中的空间层次剖分到人工智能中的状态搜索都离不开它。 二叉树是一种特殊的树，它的每个节点最多只有左、右两个子树，如下图所示。
 
 
 我们用二元组(n,s)来表示二叉树中的任意节点。其中n代表该节点的值，s代表从根节点到该节点的路径字符串， 字符串中只包含’L’和’R’两种字符，分别指“左子树”和“右子树”。上图中值为13的节点用(13,RL)表示， 值为2的节点用(2, LLR)表示；根节点用(5,)表示，空路径字符串表示它是根节点。如果每个节点到根节点的路 径上都没有缺少节点，而且每个节点只被赋值一次，则称这样的二叉树是“完备描述”的。本题目要求你判断给 定二叉树是否是“完备描述”的，如果是，输出其节点值的按层次遍历序列（即先上层后下层、从左至右地遍历）。 图1中的二叉树，其节点值的按层次遍历序列为：5, 4, 8, 11, 13, 4, 7, 2, 1。
 
 Input
 输入文件中包含多个二叉树的节点序列，每个节点用上述(n,s)形式描述， 节点值都是正整数。节点之间以空格分隔，节点内部没有空格。每个二叉树至少包含一个节点，树的结尾处以两个英文括 号字符“()”标记，括号之内没有空格。
 
 Output
 针对输入文件中的每个二叉树，分别输出其对应的信息。对于完备描述的二叉树， 输出其节点值的按层次遍历序列。每个二叉树的遍历序列值占据一行，且值与值之间用空格分隔。对于不完备描述的二叉树，则 在新的一行中输出字符串“not complete”。 
 
 Sample Input
 (11,LL) (7,LLL) (8,R)
 (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
 (3,L) (4,R) ()
 Sample Output
 5 4 8 11 13 4 7 2 1
 not complete
*/