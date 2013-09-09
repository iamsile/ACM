#include <iostream>
using namespace std;
#define MAX 10

typedef struct TrieNode {
    int flag;//标记该字符是否是某一字符串的结尾
    struct TrieNode *next[MAX];
}TrieNode;

TrieNode Mem[1000000];
int allocp=0,nflag=0;

void Init(TrieNode **pRoot)
{
    *pRoot=NULL;
}

TrieNode *Creat()
{
    int i;
    TrieNode *p;
    p=&Mem[allocp++];
    p->flag=0;
    for (i=0; i<MAX; i++)
        p->next[i]=NULL;
    return p;
}

void Insert(TrieNode **pRoot,char *s)
{
    int i=0,k;
    TrieNode *p;
    if (!(p=*pRoot))
        p=*pRoot=Creat();
    while (s[i]) {
        k=s[i++]-'0';
        if (p->next[k]) {
            if (p->next[k]->flag==1||s[i]=='\0') {//先短后长 || 先长后短
                nflag=1;
                return;
            }
        }
        else p->next[k]=Creat();
        p=p->next[k];
    }
    p->flag=1;//标记结尾
}

int main()
{
    int t,n,i;
    char s[20];
    TrieNode *Root;
    cin >> t;
    while (t--) {
        nflag=0;
        allocp=0;
        Init(&Root);
        cin >> n;
        getchar();
        for (i=0; i<n; i++) {
            gets(s);
            if (!nflag)
                Insert(&Root, s);
        }
        if (nflag)
            cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
/*
 Problem Description
 Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. Let’s say the phone catalogue listed these numbers:
 1. Emergency 911
 2. Alice 97 625 999
 3. Bob 91 12 54 26
 In this case, it’s not possible to call Bob, because the central would direct your call to the emergency line as soon as you had dialled the first three digits of Bob’s phone number. So this list would not be consistent.
 
 
 Input
 The first line of input gives a single integer, 1 <= t <= 40, the number of test cases. Each test case starts with n, the number of phone numbers, on a separate line, 1 <= n <= 10000. Then follows n lines with one unique phone number on each line. A phone number is a sequence of at most ten digits.
 
 
 Output
 For each test case, output “YES” if the list is consistent, or “NO” otherwise.
 
 
 Sample Input
 2
 3
 911
 97625999
 91125426
 5
 113
 12340
 123440
 12345
 98346
 
 
 Sample Output
 NO
 YES
*/