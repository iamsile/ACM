#include<iostream>
using namespace std;
struct node {
    int x,y,d;
} r[200]; //每一个机器人的坐标和方向 1 2 3 4 对应 N E S W

int n,m,A,B,map[120][120],flag,mx[5]={0,0,1,0,-1},my[5]={0,1,0,-1,0};//mx, my 方向数组, map[x][y] (x, y) 处的机器人编号，flag判断是否已经撞墙或者机器人相撞了

void work(int k, char ch, int l)
{
    int i;
    if(ch=='L') {//左转
        l%=4;
        r[k].d-=l;
        if(r[k].d<=0)
            r[k].d+=4;
    }
    if(ch=='R') {//右转
        r[k].d+=l;
        r[k].d%=4;
    }
    if(ch=='F') {
        for(i=1; i<=l&&flag; ++i) {
            map[r[k].x][r[k].y]=-1;
            r[k].x+=mx[r[k].d];
            r[k].y+=my[r[k].d];
            if(flag&&r[k].x==0||r[k].x==A+1||r[k].y==0||r[k].y==B+1) {//撞墙
                printf("Robot %d crashes into the wall\n", k);
                flag=0;
                break;
            }
            if(flag&&map[r[k].x][r[k].y]!=-1) {//相撞 
                printf("Robot %d crashes into robot %d\n", k,map[r[k].x][r[k].y]);
                flag=0;
                break;
            }
            map[r[k].x][r[k].y]=k;
        }
    }
}

int main()
{
    
    int i,k,l,t;
    char ch;
    cin >> t;
    while(t--) {
        memset(map, -1, sizeof(map));
        cin >> A >> B >> n >> m;
        for(i=1; i<=n; i++) {
            cin >> r[i].x >> r[i].y >> ch;
            map[r[i].x][r[i].y]=i;
            if(ch=='N')
                r[i].d=1;
            if(ch=='E') 
                r[i].d=2;
            if(ch=='S') 
                r[i].d=3;
            if(ch=='W') 
                r[i].d=4;
        }
        for(i=1,flag=1; i<=m; i++) {
            cin >> k >> ch >> l;
            work(k, ch, l);
        }
        if(flag)
            cout << "OK\n";
    }
    return 0;
}
/*
 
 Problem description
 In a modernized warehouse, robots are used to fetch the goods. Careful planning is needed to ensure that the robots reach their destinations without crashing into each other. Of course, all warehouses are rectangular, and all robots occupy a circular floor space with a diameter of 1 meter. Assume there are N robots, numbered from 1 through N. You will get to know the position and orientation of each robot, and all the instructions, which are carefully (and mindlessly) followed by the robots. Instructions are processed in the order they come. No two robots move simultaneously; a robot always completes its move before the next one starts moving. 
 A robot crashes with a wall if it attempts to move outside the area of the warehouse, and two robots crash with each other if they ever try to occupy the same spot.
 
 Input
 The first line of input is K, the number of test cases. Each test case starts with one line consisting of two integers, 1 <= A, B <= 100, giving the size of the warehouse in meters. A is the length in the EW-direction, and B in the NS-direction. 
 The second line contains two integers, 1 <= N, M <= 100, denoting the numbers of robots and instructions respectively. 
 Then follow N lines with two integers, 1 <= Xi <= A, 1 <= Yi <= B and one letter (N, S, E or W), giving the starting position and direction of each robot, in order from 1 through N. No two robots start at the same position. 
 
 Figure 1: The starting positions of the robots in the sample warehouse
 
 Finally there are M lines, giving the instructions in sequential order. 
 An instruction has the following format: 
 < robot #> < action> < repeat> 
 Where is one of 
 L: turn left 90 degrees, 
 R: turn right 90 degrees, or 
 F: move forward one meter,
 
 and 1 <= < repeat> <= 100 is the number of times the robot should perform this single move.
 
 Output
 Output one line for each test case: 
 Robot i crashes into the wall, if robot i crashes into a wall. (A robot crashes into a wall if Xi = 0, Xi = A + 1, Yi = 0 or Yi = B + 1.) 
 Robot i crashes into robot j, if robots i and j crash, and i is the moving robot. 
 OK, if no crashing occurs.
 
 Only the first crash is to be reported.
 
 Sample Input
 4
 5 4
 2 2
 1 1 E
 5 4 W
 1 F 7
 2 F 7
 5 4
 2 4
 1 1 E
 5 4 W
 1 F 3
 2 F 1
 1 L 1
 1 F 3
 5 4
 2 2
 1 1 E
 5 4 W
 1 L 96
 1 F 2
 5 4
 2 3
 1 1 E
 5 4 W
 1 F 4
 1 L 1
 1 F 20
 Sample Output
 Robot 1 crashes into the wall
 Robot 1 crashes into robot 2
 OK
 Robot 1 crashes into robot 2
*/