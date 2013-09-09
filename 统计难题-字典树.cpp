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