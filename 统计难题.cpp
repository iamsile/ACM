#include <iostream>
#define MAX 26

typedef struct TrieNode {
    int nCount;
    struct TrieNode *next[MAX];
}TrieNode;

TrieNode Mem[1000000];
int allocp=0;

void Init(TrieNode **pRoot)
{
    *pRoot=NULL;
}

TrieNode *Create()
{
    int i;
    TrieNode *p;
    p=&Mem[allocp++];
    p->nCount=1;
    for (i=0; i<MAX; i++)
        p->next[i]=NULL;
    return p;
}

void Insert(TrieNode **pRoot,char *s)
{
    int i=0,k;
    TrieNode *p;
    if (!(p=*pRoot))
        p=*pRoot=Create();
    while (s[i]) {
        k=s[i++]-'a';
        if (p->next[k])
            p->next[k]->nCount++;
        else p->next[k]=Create();
        p=p->next[k];
    }
}

int Search(TrieNode **pRoot,char *s)
{
    TrieNode *p;
    int i=0,k;
    if (!(p=*pRoot))
        return 0;
    while (s[i]) {
        k=s[i++]-'a';
        if (p->next[k]==NULL)
            return 0;
        p=p->next[k];
    }
    return p->nCount;
}

int main()
{
    char s[20];
    TrieNode *Root=NULL;
    Init(&Root);
    while (gets(s)&&s[0]) {
        Insert(&Root, s);
    }
    while (gets(s)) {
        printf("%d\n",Search(&Root, s));
    }
    return 0;
}
/*
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int n;                     ////这里是代表有某个节点的字符串数
    struct node *child[26];    ////字典树嘛，26个字母；
}Lnode,*Link;                 ///建立链表习惯，就延续下来了
Link root;
int m=sizeof(Lnode);      

void Insert(char str[])       ///建立起字典树
{
    int i,j,len;
    Link s,t;
    len=strlen(str);
    if(len==0)
        return;
    s=root;
    for(i=0;i<len;i++)
    {  
        if(s->child[str[i]-'a']!=0)
        {
            s=s->child[str[i]-'a'];
            s->n=s->n+1;
        }
        else
        {
            t=(Link)malloc(m);          ///这个就是组建过程，
            for(j=0;j<26;j++)
                t->child[j]=0;
            s->child[str[i]-'a']=t;      ///这个是正确的，把新开辟的空间，连在刚刚的地方；
            s=t;                        ///这个也是，主要在进行过程中用的是s处理的，这里把t赋给s
            s->n=1;                     ///当某个节点有字母时，就可以加1；
        }  
    }
}
int find(char str[])                ///搜索过程
{
    Link s;
    int i,len;
    len=strlen(str);
    if(len==0)
        return 0;
    s=root;
    for(i=0;i<len;i++)
    {
        if(s->child[str[i]-'a']!=0)     ///找到的话自然顺着str往下找
            s=s->child[str[i]-'a'];
        else
            return 0;                   ///有一个不存在，说明字典树不存在str这样的为前缀的
    }
    return s->n;
}
int main()
{
    char str[15];
    int i;
    root=(Link)malloc(m);
    for(i=0;i<26;i++)
        root->child[i]=0;
    while(gets(str),strcmp(str,"")!=0)
        Insert(str);
    while(gets(str))
    {
        i=find(str);
        printf("%d\n",i);
    }
    return 0;
}
*/
/*
 Problem Description
 Ignatius最近遇到一个难题,老师交给他很多单词(只有小写字母组成,不会有重复的单词出现),现在老师要他统计出以某个字符串为前缀的单词数量(单词本身也是自己的前缀).
 
 
 Input
 输入数据的第一部分是一张单词表,每行一个单词,单词的长度不超过10,它们代表的是老师交给Ignatius统计的单词,一个空行代表单词表的结束.第二部分是一连串的提问,每行一个提问,每个提问都是一个字符串.
 
 注意:本题只有一组测试数据,处理到文件结束.
 
 
 Output
 对于每个提问,给出以该字符串为前缀的单词的数量.
 
 
 Sample Input
 banana
 band
 bee
 absolute
 acm
 
 ba
 b
 band
 abc
 
 
 Sample Output
 2
 3
 1
 0
*/