#include <iostream>
using namespace std;

int sg[16000],h[7];

int dfs(int s)
{
    if(sg[s]!=-1)
        return sg[s];
    int i,j,k,b[10],sum=0;
    memset(b,0,sizeof(b));
    for(i=1;i<=6;i++)
        sum+=h[i]*i;
    for(i=1;i<=6;i++)
        if(h[i]<4&&i+sum<=31) {
            ++h[i];
            for(j=1,k=0;j<=6;j++)
                k=k*5+h[j];
            b[dfs(k)]=1;
            --h[i];
        }
    for(i=0;b[i];i++) ;
    return sg[s]=i;
}

int main()
{
    char a[40];
    while(gets(a)!=NULL) {
        int i,j,k=strlen(a),flag;
        memset(sg,-1,sizeof(sg));
        memset(h,0,sizeof(h));
        for(i=0;i<k;i++)
            ++h[a[i]-'0'];
        flag=i%2;
        for(i=1,j=0;i<=6;i++)
            j=j*5+h[i];
        k=dfs(j);
        printf("%s ",a);
        if(flag==0)
            printf("%s\n",k==0?"B":"A");
        else printf("%s\n",k==0?"A":"B");
    }
    return 0;
}
/*
 Problem description
 The game of 31 was a favourite of con artists who rode the railroads in days of yore. The game is played with a deck of 24 cards: four labelled each of 1, 2, 3, 4, 5, 6. The cards in the deck are visible to both players, who alternately withdraw one card from the deck and place it on a pile.
 The object of the game is to be the last player to lay a card such that the sum of the cards in the pile does not exceed 31. Your task is to determine the eventual winner of a partially played game, assuming each player plays the remainder of the game using a perfect strategy.
 For example, in the following game player B wins:
 Player A plays 3
 Player B plays 5
 Player A plays 6
 Player B plays 6
 Player A plays 5
 Player B plays 6
 
 
 Input
 The input will consist of several lines; each line consists of a sequence of zero or more digits representing a partially completed game. The first digit is player A's move; the second player B's move; and so on. You are to complete the game using a perfect strategy for both players and to determine who wins. 
 
 Output
 For each game, print a line consisting of the input, followed by a space, followed by A or B to indicate the eventual winner of the game.
 
 Sample Input
 356656
 35665
 3566
 111126666
 552525
 Sample Output
 356656 B
 35665 B
 3566 A
 111126666 A
 552525 A
*/