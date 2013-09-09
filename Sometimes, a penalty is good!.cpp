#include <iostream>
#include <stdio.h>
using namespace std;
//typedef long long ll;
int main()
{
    __int64 sum,y,g,t,k,a,d,i;
    while (~scanf("%I64d%I64d%I64d%I64d",&g,&t,&a,&d)) {
        if (g==-1&&t==-1&&a==-1&&d==-1)
            break;
        sum=t*(t-1)/2*g;
        k=g*a+d-1;
        for (i=0; k; k/=2,i++);
        y=(1LL<<i)-g*a-d;
        sum+=(1LL<<i)-1;
        printf("%I64d*%I64d/%I64d+%I64d=%I64d+%I64d\n",g,a,t,d,sum,y);
    }
    return 0;
}
/*
 Problem description
 FIFA is considering a few changes to the way it organizes the Football World Cup. Currently, 32 teams compete for the World Title in two stages. During the first stage, known as the groups stage, the 32 teams are split evenly into 8 groups. Every team in the group plays 3 games, one against each team in their own group. Teams are then ranked within their group according to some points system. During the second (and final) stage, the top two teams from each group advance to the knockout stage where eight games are played to determine eight winners who would then play four games to determine four winners, then two games to determine the two winners who would then play the final game to determine the world champion. Needless to say, for the knockout stage to work, the number of teams in that stage has to be a power of two.
 FIFA is considering adding more groups, adding more teams to groups, and possibly changing the number of teams advancing from each group to the knockout stage. In addition, FIFA is considering having certain teams (previous champion, host country, etc.) advance to the knockout stage directly (without having to play in the groups stage.) But FIFA needs to know how many games will be played if any of these changes are applied. Please help them! 
 
 
 Input
 Your program will be tested on one or more test cases. Each test case is specified on a single line made of 4 natural numbers with the following format:
 G T A D
 Where (G > 0) is the number of groups; T is the number of teams in each group; A is the number of teams advancing from each group to the knockout stage; and D is the number of teams directly advancing to the knockout stage without going through the groups stage. Note that (0 < A ≤ T) and that the four numbers in the input are no larger than 216.
 If the total number of teams in the knockout stage is not a power of two, your program must increase them to the closest power of two.
 The last test case is followed by a dummy line made of four -1’s. 
 
 
 Output
 For each test case, print:
 G*A/T+D=X+Y
 where G, A, T, and D are as in the input, X is the total number of games, and Y is the number of teams your program determined it must add. 
 
 
 Sample Input
 8 4 2 0
 8 4 2 1
 -1 -1 -1 -1
 
 Sample Output
 8*2/4+0=63+0
 8*2/4+1=79+15
*/