#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct node {
    node *next[26];
    bool m;
};
char c[50000][50];

void build(node *root,char a[])
{
    node *p=root;
    int i,j;
    for (i=0; a[i]; i++) {
        if (p->next[a[i]-'a']==NULL) {
            node *np=(node *)malloc(sizeof(node));
            np->m=0;
            for (j=0; j<26; j++)
                np->next[j]=NULL;
            p->next[a[i]-'a']=np;
        }
        p=p->next[a[i]-'a'];
    }
    p->m=1;
}

bool Search(node *root,char w[])
{
    node *p=root;
    int i;
    for (i=0; w[i]; i++) {
        if (p==NULL||p->next[w[i]-'a']==NULL)
            return false;
        p=p->next[w[i]-'a'];
    }
    return p->m;
}

int main()
{
    char a[30];
    int i,j,cnt=0;
    node *root=(node *)malloc(sizeof(node));
    for (i=0; i<26; i++)
        root->next[i]=NULL;
    root->m=0;
    while (~scanf("%s",a)) {
        strcpy(c[cnt++], a);
        build(root,a);
    }
    for (i=0; i<cnt; i++)
        for (j=1; j<strlen(c[i]); j++) {
            char b1[50]={0},b2[50]={0};
            strncpy(b1, c[i], j);
            strncpy(b2, c[i]+j, strlen(c[i])-j);
            if (Search(root, b1)&&Search(root, b2)) {
                printf("%s\n",c[i]);
                break;
            }
        }
    return 0;
}
/*
 Problem Description
 A hat’s word is a word in the dictionary that is the concatenation of exactly two other words in the dictionary.
 You are to find all the hat’s words in a dictionary.
 
 
 Input
 Standard input consists of a number of lowercase words, one per line, in alphabetical order. There will be no more than 50,000 words.
 Only one case.
 
 
 Output
 Your output should contain all the hat’s words, one per line, in alphabetical order.
 
 
 Sample Input
 a
 ahat
 hat
 hatword
 hziee
 word
 
 
 Sample Output
 ahat
 hatword
*/