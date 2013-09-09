#include <iostream>
using namespace std;

struct node {
    node *next[2];
    node(){
        next[0]=next[1]=NULL;
    }
};

char str[10010][110];

int mins(char a[])
{
    int i=0,j=1,k=0,len=strlen(a),t;
    while (i<len&&j<len&&k<len) {
        t=a[(i+k)%len]-a[(j+k)%len];
        if (!t)
            k++;
        else {
            if (t>0)
                i=i+k+1;
            else j=j+k+1;
            if (i==j)
                j++;
            k=0;
        }
    }
    return min(i,j);
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,k,l,len,flag,ans=0;
        memset(str, 0, sizeof(str));
        for (i=0; i<n; i++)
            scanf("%s",str[i]);
        node *tree=new node;
        for (i=0; i<n; i++) {
            k=mins(str[i]);
            node *p=tree;
            len=strlen(str[i]);
            l=0;
            flag=0;
            while (l<len) {
                j=str[i][(l+k)>=len?(l+k-len):(l+k)]-'0';
                l++;
                if (p->next[j]==NULL) {
                    flag=1;
                    node *np=new node;
                    p->next[j]=np;
                }
                p=p->next[j];
            }
            if (flag)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
 Problem Description
 Give you n ( n < 10000) necklaces ,the length of necklace will not large than 100,tell me
 How many kinds of necklaces total have.(if two necklaces can equal by rotating ,we say the two necklaces are some).
 For example 0110 express a necklace, you can rotate it. 0110 -> 1100 -> 1001 -> 0011->0110.
 
 
 Input
 The input contains multiple test cases.
 Each test case include: first one integers n. (2<=n<=10000)
 Next n lines follow. Each line has a equal length character string. (string only include '0','1').
 
 
 Output
 For each test case output a integer , how many different necklaces.
 
 
 Sample Input
 4
 0110
 1100
 1001
 0011
 4
 1010
 0101
 1000
 0001
 
 
 Sample Output
 1
 2
*/