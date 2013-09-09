#include <iostream>
using namespace std;
#define N 52
int map[N][N],v[N],flag[N];
int A[N],B[N],t,n;
int dfs(int k)
{
    int i;
    for(i=1;i<=n;i++) 
        if(map[k][i]&&!v[i]) {
            v[i]=1;
            if(flag[i]==0||dfs(flag[i])) {
                flag[i]=k;
                return 1;
            }
        }
    return 0;
}

int main()
{
    char c,d,e;
    int i,j,vv,lab,ans;
    int ap,bp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        lab=1;
        ap=bp=0;
        for(i=0;i<2*n;i++)
        {
            scanf("%c%c%c",&c,&d,&e);
            if(c>='0'&&c<='9')
                vv=c-'0';
            if(c=='T')vv=10;
            if(c=='J')vv=11;
            if(c=='Q')vv=12;
            if(c=='K')vv=13;
            if(c=='A')vv=14;
            vv*=100;
            if(d=='H')vv+=4;
            if(d=='S')vv+=3;
            if(d=='D')vv+=2;
            if(d=='C')vv+=1;
            if(lab)
                A[++ap]=vv;
            else
                B[++bp]=vv;
            if(e=='\n')
                lab=0;
        }
        memset(map,0,sizeof(map));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(A[i]<B[j])
                    map[j][i]=1;
        memset(flag,0,sizeof(flag));
        ans=0;
        for(i=1;i<=n;i++) {
            memset(v,0,sizeof(v));
            if(dfs(i))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
 Problem Description
 Adam and Eve play a card game using a regular deck of 52 cards. The rules are simple. The players sit on opposite sides of a table, facing each other. Each player gets k cards from the deck and, after looking at them, places the cards face down in a row on the table. Adam’s cards are numbered from 1 to k from his left, and Eve’s cards are numbered 1 to k from her right (so Eve’s i:th card is opposite Adam’s i:th card). The cards are turned face up, and points are awarded as follows (for each i ∈ {1, . . . , k}):
 
 
 If Adam’s i:th card beats Eve’s i:th card, then Adam gets one point.
 
 
 If Eve’s i:th card beats Adam’s i:th card, then Eve gets one point.
 
 
 A card with higher value always beats a card with a lower value: a three beats a two, a four beats a three and a two, etc. An ace beats every card except (possibly) another ace.
 
 
 If the two i:th cards have the same value, then the suit determines who wins: hearts beats all other suits, spades beats all suits except hearts, diamond beats only clubs, and clubs does not beat any suit.
 
 For example, the ten of spades beats the ten of diamonds but not the Jack of clubs.
 
 This ought to be a game of chance, but lately Eve is winning most of the time, and the reason is that she has started to use marked cards. In other words, she knows which cards Adam has on the table before he turns them face up. Using this information she orders her own cards so that she gets as many points as possible.
 
 Your task is to, given Adam’s and Eve’s cards, determine how many points Eve will get if she plays optimally.
 
 
 
 Input
 There will be several test cases. The first line of input will contain a single positive integer N giving the number of test cases. After that line follow the test cases.
 
 Each test case starts with a line with a single positive integer k <= 26 which is the number of cards each player gets. The next line describes the k cards Adam has placed on the table, left to right. The next line describes the k cards Eve has (but she has not yet placed them on the table). A card is described by two characters, the first one being its value (2, 3, 4, 5, 6, 7, 8 ,9, T, J, Q, K, or A), and the second one being its suit (C, D, S, or H). Cards are separated by white spaces. So if Adam’s cards are the ten of clubs, the two of hearts, and the Jack of diamonds, that could be described by the line
 
 TC 2H JD
 
 
 Output
 For each test case output a single line with the number of points Eve gets if she picks the optimal way to arrange her cards on the table.
 
 
 
 Sample Input
 3
 1
 JD
 JH
 2
 5D TC
 4C 5H
 3
 2H 3H 4H
 2D 3D 4D
 
 
 Sample Output
 1
 1
 2
*/