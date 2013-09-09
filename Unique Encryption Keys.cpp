#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m),n||m) {
        int i,x,y;
        vector<int> a(n);
        vector<int> b(n);
        map<int, int> dic;
        for (i=0; i<n; i++)
            scanf("%d",&a[i]);
        for (i=n-1; i>=0; i--) {
            b[i]=n;
            if (i<n-1)
                b[i]=b[i+1];
            if (dic.count(a[i]))
                b[i]=min(b[i], dic[a[i]]);
            dic[a[i]]=i;
        }
        while (m--) {
            scanf("%d%d",&x,&y);
            x--;y--;
            if (b[x]<=y)
                printf("%d\n",a[b[x]]);
            else printf("OK\n");
        }
    }
    return 0;
}
/*
 Problem description
 The security of many ciphers strongly depends on the fact that the keys are unique and never re-used. This may be vitally important, since a relatively strong cipher may be broken if the same key is used to encrypt several different messages.
 In this problem, we will try to detect repeating (duplicate) usage of keys. Given a sequence of keys used to encrypt messages, your task is to determine what keys have been used repeatedly in some specified period.
 
 
 
 Input
 The input contains several cipher descriptions. Each description starts with one line containing two integer numbers M and Q separated by a space. M (1≤M≤1000000) is the number of encrypted messages, Q is the number of queries (0≤Q≤1000000).
 
 Each of the following M lines contains one number Ki (0≤i≤230) specifying the identifier of a key used to encrypt the i-th message. The next Q lines then contain one query each. Each query is specified by two integer numbers Bj and Ej, 1≤Bj≤Ej≤M, giving the interval of messages we want to check.
 
 There is one empty line after each description. The input is terminated by a line containing two zeros in place of the numbers M and Q.
 
 Output
 For each query, print one line of output. The line should contain the string ``OK" if all keys used to encrypt messages between Bj and Ej (inclusive) are mutually different (that means, they have different identifiers). If some of the keys have been used repeatedly, print one identifier of any such key.
 Print one empty line after each cipher description.
 
 
 
 Sample Input
 10 5
 3
 2
 3
 4
 9
 7
 3
 8
 4
 1
 1 3
 2 6
 4 10
 3 7
 2 6
 
 5 2
 1
 2
 3
 1
 2
 2 4
 1 5
 
 0 0
 Sample Output
 3
 OK
 4
 3
 OK
 OK
 1
*/