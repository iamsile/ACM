#include <iostream>
#include <queue>
using namespace std;
#define FF(i,n) for(int i=0;i<n;i++)
const int inf=999999;

struct node {
    int x,y,v;
    node():x(0),y(0),v(0) {}
}cur,next,path[4001];
int n,m,cnt,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},v[101][101],G[101][101],dis[101];
bool vv[101][101];
char map[101][101];

void bfs(node s)
{
    queue<node> q;
    memset(vv, 0, sizeof(vv));
    q.push(s);
    vv[s.x][s.y]=1;
    while (!q.empty()) {
        cur.x=q.front().x;
        cur.y=q.front().y;
        cur.v=q.front().v;
        q.pop();
        FF(i, 4) {
            next.x=cur.x+dx[i];
            next.y=cur.y+dy[i];
            next.v=cur.v+1;
            if (next.x<n&&next.x>=0&&next.y<m&&next.y>=0&&!vv[next.x][next.y]) {
                if (map[next.x][next.y]=='S'||map[next.x][next.y]=='A') {
                    G[v[s.x][s.y]][v[next.x][next.y]]=G[v[next.x][next.y]][v[s.x][s.y]]=next.v;
                    q.push(next);
                    vv[next.x][next.y]=1;
                }
                else if (map[next.x][next.y]==' ') {
                    q.push(next);
                    vv[next.x][next.y]=1;
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&m,&n);
        char c[50];
        int i,j,sum,min,flag;
        gets(c);
        FF(i, n)gets(map[i]);
        cnt=0;
        FF(i, n) FF(j, m)
        if (map[i][j]=='A'||map[i][j]=='S') {
            path[cnt].x=i;
            path[cnt].y=j;
            path[cnt].v=0;
            v[i][j]=cnt++;
        }
        FF(i, cnt)
            for (G[i][i]=0,j=i+1; j<cnt; j++)
                G[i][j]=G[j][i]=inf;
        FF(i, cnt) bfs(path[i]);
        FF(i, cnt) dis[i]=G[0][i];
        sum=0;
        FF(i, cnt) {
            min=inf;
            flag=0;
            FF(j, cnt)
            if (dis[j]&&dis[j]<min) {
                min=dis[j];
                flag=j;
            }
            if (min!=inf) {
                sum+=min;
                dis[flag]=0;
            }
            FF(j, cnt) if (dis[j]&&dis[j]>G[flag][j])
                dis[j]=G[flag][j];
        }
        printf("%d\n",sum);
    }
    return 0;
}
/*
 
 Problem description
 
 
 The Borg is an immensely powerful race of enhanced humanoids from the delta quadrant of the galaxy. The Borg collective is the term used to describe the group consciousness of the Borg civilization. Each Borg individual is linked to the collective by a sophisticated subspace network that insures each member is given constant supervision and guidance. 
 
 Your task is to help the Borg (yes, really) by developing a program which helps the Borg to estimate the minimal cost of scanning a maze for the assimilation of aliens hiding in the maze, by moving in north, west, east, and south steps. The tricky thing is that the beginning of the search is conducted by a large group of over 100 individuals. Whenever an alien is assimilated, or at the beginning of the search, the group may split in two or more groups (but their consciousness is still collective.). The cost of searching a maze is definied as the total distance covered by all the groups involved in the search together. That is, if the original group walks five steps, then splits into two groups each walking three steps, the total distance is 11=5+3+3. 
 
 Input
 On the first line of input there is one integer, 50>=N , giving the number of test cases in the input. Each test case starts with a line containg two integers x, y such that 50 >= x,y >=1 . After this, y lines follow, each which x characters. For each character, a space `` '' stands for an open space, a hash mark ``#'' stands for an obstructing wall, the capital letter ``A'' stand for an alien, and the capital letter ``S'' stands for the start of the search. The perimeter of the maze is always closed, i.e., there is no way to get out from the coordinate of the ``S''. At most 100 aliens are present in the maze, and everyone is reachable. 
 
 Output
 For every test case, output one line containing the minimal cost of a succesful search of the maze leaving no aliens alive. 
 
 Sample Input
 2                        
 6 5                      
 ##### 
 #A#A##
 # # A#
 #S  ##
 ##### 
 7 7
 #####  
 #AAA###
 #    A#
 # S ###
 #     #
 #AAA###
 #####  
 Sample Output
 8
 11
*/