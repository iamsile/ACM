#include <iostream>
#include <string.h>
using namespace std;

struct node {
    int cnt,flag;
    node *next[26];
    node() {
        cnt=0;
        flag=-1;
        memset(next,0,sizeof(next));
    }
};

void build(node *root,char s[],int id)
{
    int i,k=strlen(s);
    for(i=0;i<k;i++) {
        if(root->next[s[i]-'a']==NULL)
            root->next[s[i]-'a']=new node;
        root=root->next[s[i]-'a'];
        if(root->flag!=id) {
            root->flag=id;
            root->cnt++;
        }
    }
}

int query(node *root,char s[])
{
    int i,k=strlen(s);
    for(i=0;i<k;i++) {
        if(root->next[s[i]-'a']==NULL)
            return 0;
        root=root->next[s[i]-'a'];
    }
    return root->cnt;
}

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        node *root=new node;
        char a[100];
        int i,j;
        for(i=0;i<n;i++) {
            scanf("%s",a);
            for(j=0;j<strlen(a);j++)
                build(root,a+j,i);
        }
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            scanf("%s",a);
            printf("%d\n",query(root,a));
        }
    }
    return 0;
}
/*
 Problem Description
 When you go shopping, you can search in repository for avalible merchandises by the computers and internet. First you give the search system a name about something, then the system responds with the results. Now you are given a lot merchandise names in repository and some queries, and required to simulate the process.
 
 
 Input
 There is only one case. First there is an integer P (1<=P<=10000)representing the number of the merchanidse names in the repository. The next P lines each contain a string (it's length isn't beyond 20,and all the letters are lowercase).Then there is an integer Q(1<=Q<=100000) representing the number of the queries. The next Q lines each contains a string(the same limitation as foregoing descriptions) as the searching condition.
 
 
 Output
 For each query, you just output the number of the merchandises, whose names contain the search string as their substrings.
 
 
 Sample Input
 20
 ad
 ae
 af
 ag
 ah
 ai
 aj
 ak
 al
 ads
 add
 ade
 adf
 adg
 adh
 adi
 adj
 adk
 adl
 aes
 5
 b
 a
 d
 ad
 s
 
 
 Sample Output
 0
 20
 11
 11
 2
*/