#include <iostream>
using namespace std;

struct node {
    int l,w;
    node() {
        l=w=0;
    }
};

int cmp(const void *a,const void *b)
{
    node *c=(node *)a;
    node *d=(node *)b;
    if (c->l!=d->l)
        return c->l - d->l;
    else return c->w - d->w;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int i,n,j,sum=0;
        node s[5005],cur;
        scanf("%d",&n);
        for (i=0; i<n; i++)
            scanf("%d%d",&s[i].l,&s[i].w);
        qsort(s, n, sizeof(s[0]), cmp);
        for (i=0; i<n; i++)
            if (s[i].l!=0&&s[i].w!=0) {
                cur=s[i];
                s[i].l=s[i].w=0;
                for (j=i+1; j<n; j++)
                    if (s[j].l>=cur.l&&s[j].w>=cur.w) {
                        cur=s[j];
                        s[j].l=0;
                        s[j].w=0;
                    }
                sum++;
            }
        printf("%d\n",sum);
    }
    return 0;
}
/*
 Problem description
 There is a pile of n wooden sticks. The length and weight of each stick are known in advance. The sticks are to be processed by a woodworking machine in one by one fashion. It needs some time, called setup time, for the machine to prepare processing a stick. The setup times are associated with cleaning operations and changing tools and shapes in the machine. The setup times of the woodworking machine are given as follows:
 
 (a) The setup time for the first wooden stick is 1 minute.
 (b) Right after processing a stick of length l and weight w , the machine will need no setup time for a stick of length l' and weight w' if l<=l' and w<=w'. Otherwise, it will need 1 minute for setup.
 
 You are to find the minimum setup time to process a given pile of n wooden sticks. For example, if you have five sticks whose pairs of length and weight are (4,9), (5,2), (2,1), (3,5), and (1,4), then the minimum setup time should be 2 minutes since there is a sequence of pairs (1,4), (3,5), (4,9), (2,1), (5,2).
 
 
 Input
 The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of two lines: The first line has an integer n , 1<=n<=5000, that represents the number of wooden sticks in the test case, and the second line contains n 2 positive integers l1, w1, l2, w2, ..., ln, wn, each of magnitude at most 10000 , where li and wi are the length and weight of the i th wooden stick, respectively. The 2n integers are delimited by one or more spaces.
 
 
 Output
 The output should contain the minimum setup time in minutes, one per line.
 
 
 Sample Input
 3
 5
 4 9 5 2 2 1 3 5 1 4
 3
 2 2 1 1 2 2
 3
 1 3 2 2 3 1
 Sample Output
 2
 1
 3
*/