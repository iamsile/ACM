#include <iostream>
using namespace std;

struct node {
    int l,r,v;
}t[1000010];

int sum;

void build(int cur,int l,int r)
{
    t[cur].l=l;
    t[cur].r=r;
    t[cur].v=0;
    if(l==r)
        return;
    build(cur*2,l,(l+r)/2);
    build(cur*2+1,(l+r)/2+1,r);
}

void update(int cur,int x,int num)
{
    if(x<=t[cur].r&&x>=t[cur].l) {
        t[cur].v+=num;
        update(cur*2,x,num);
        update(cur*2+1,x,num);
    }
}

void query(int cur,int l,int r)
{
    int mid=(t[cur].l+t[cur].r)/2;
    if(t[cur].l==l&&t[cur].r==r)
        sum+=t[cur].v;
    else if(r<=mid)
        query(cur*2,l,r);
    else if(l>mid)
        query(cur*2+1,l,r);
    else {
        query(cur*2,l,mid);
        query(cur*2+1,mid+1,r);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int i,x,y,n,p,q;
        scanf("%d%d%d\n",&n,&p,&q);
        build(1,1,n);
        char c[2];
        for(i=0;i<p+q;i++) {
            scanf("%s",c);
            scanf("%d%d",&x,&y);
            if(c[0]=='P')
                update(1,x,y);
            else {
                sum=0;
                query(1,x,y);
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}
/*
 Problem description
 A game consists of putting beads in boxes. The rules of the game are too complex to describe here, but all you need to know is that keeping track of the number of beans in adjacent boxes are very important to the outcome of the game.
 You are asked by a friend to write a program to help him win the game every time. At the start of a game, all boxes are empty.
 
 Input
 The first line of the input consists of a single number T, the number of games played. Each game start with a line describing B, P and Q, the number of boxes, put requests and query requests, respectively. Then follows P + Q lines with either P i a, saying a beads are put in box number i,or Q i j, a query request for the number of beads in boxes i through j, inclusive.
 
 Output
 For each query request, output the number of beads in boxes a through b, inclusive, that are in the boxes at this point of the game.
 
 Sample Input
 1
 7 5 3
 P 2 1
 P 3 3
 P 4 7
 Q 1 4
 P 7 6
 Q 4 4
 P 6 4
 Q 1 7
 Sample Output
 11
 7
 21
*/