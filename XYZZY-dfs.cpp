#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int inf=999999;
int n,map[110][110],e[110],v[110];

int dfs(int s,int t)
{
    int i;
    v[s]=1;
    for (i=1; i<=n; i++)
        if (!v[i]&&map[s][i]) {
            if (i==t)
                return 1;
            if (dfs(i, t))
                return 1;
        }
    return 0;
}

void SPFA()
{
    int i,s,dis[110]={0},num[110]={0};
    queue<int> q;
    for (i=1; i<=n; i++)
        dis[i]=-inf;
    dis[1]=100+e[i];
    num[1]=1;
    q.push(1);
    while (!q.empty()) {
        s=q.front();
        q.pop();
        for (i=1; i<=n; i++)
            if (map[s][i]&&dis[i]<dis[s]+e[i]) {
                dis[i]=dis[s]+e[i];
                if (dis[i]>0) {
                    q.push(i);
                    num[i]++;
                    if (num[i]>n) {
                        memset(v, 0, sizeof(v));
                        if (dis[n]>0||dfs(i,n))
                            cout << "winnable\n";
                        else cout << "hopeless\n";
                        return;
                    }
                }
            }
    }
    if (dis[n]>0)
        cout << "winnable\n";
    else cout << "hopeless\n";
}

int main()
{

    while (~scanf("%d",&n)&&n!=-1) {
        int i,j,m,end;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                map[i][j]=0;
        memset(e, 0, sizeof(e));
        for (i=1; i<=n; i++) {
            cin >> e[i] >> m;
            while (m--) {
                cin >> end;
                map[i][end]=1;
            }
        }
        SPFA();
    }
    return 0;
}
/*
 Problem Description
 It has recently been discovered how to run open-source software on the Y-Crate gaming device. A number of enterprising designers have developed Advent-style games for deployment on the Y-Crate. Your job is to test a number of these designs to see which are winnable. 
 Each game consists of a set of up to 100 rooms. One of the rooms is the start and one of the rooms is the finish. Each room has an energy value between -100 and +100. One-way doorways interconnect pairs of rooms. 
 
 The player begins in the start room with 100 energy points. She may pass through any doorway that connects the room she is in to another room, thus entering the other room. The energy value of this room is added to the player's energy. This process continues until she wins by entering the finish room or dies by running out of energy (or quits in frustration). During her adventure the player may enter the same room several times, receiving its energy each time. 
 
 
 Input
 The input consists of several test cases. Each test case begins with n, the number of rooms. The rooms are numbered from 1 (the start room) to n (the finish room). Input for the n rooms follows. The input for each room consists of one or more lines containing: 
 
 the energy value for room i 
 the number of doorways leaving room i 
 a list of the rooms that are reachable by the doorways leaving room i 
 The start and finish rooms will always have enery level 0. A line containing -1 follows the last test case. 
 
 
 Output
 In one line for each case, output "winnable" if it is possible for the player to win, otherwise output "hopeless". 
 
 
 Sample Input
 5
 0 1 2
 -60 1 3
 -60 1 4
 20 1 5
 0 0
 5
 0 1 2
 20 1 3
 -60 1 4
 -60 1 5
 0 0
 5
 0 1 2
 21 1 3
 -60 1 4
 -60 1 5
 0 0
 5
 0 1 2
 20 2 1 3
 -60 1 4
 -60 1 5
 0 0
 -1
 
 
 Sample Output
 hopeless
 hopeless
 winnable
 winnable
*/