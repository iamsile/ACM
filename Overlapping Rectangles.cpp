#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

int mark[4];

struct Point{
    int x, y;
};

struct Rectangle{
    struct Point u, l, d, r;
}arr[MAXN], ans;

inline bool is_overlpping(struct Point const& p, struct Rectangle const& r){
    if(p.x>=r.l.x&&p.y>=r.l.y&&p.x<=r.r.x&&p.y<=r.r.y)
        return true;
    else return false;
}

inline void cp(struct Rectangle & q,struct Rectangle const& p){
    q.u.x=p.u.x;
    q.u.y=p.u.y;
    q.l.x=p.l.x;
    q.l.y=p.l.y;
    q.d.x=p.d.x;
    q.d.y=p.d.y;
    q.r.x=p.r.x;
    q.r.y=p.r.y;
}

inline bool get_overlpping_area(struct Rectangle const& r0, struct Rectangle const& r1){
    memset(mark, 0, sizeof mark);
    int cnt=0;
    bool overlpping;
    overlpping=is_overlpping(r0.u, r1);
    if(overlpping){
        ++cnt;
        mark[0]=1;
    }
    overlpping=is_overlpping(r0.l, r1);
    if(overlpping){
        ++cnt;
        mark[1]=1;
    }
    overlpping=is_overlpping(r0.d, r1);
    if(overlpping){
        ++cnt;
        mark[2]=1;
    }
    overlpping=is_overlpping(r0.r, r1);
    if(overlpping){
        ++cnt;
        mark[3]=1;
    }
    if(cnt==4){
        cp(ans, r0);
        return true;
    } else if(cnt==2){
        cp(ans, r0);
        if(mark[0]==1&&mark[1]==1)
            ans.r.x=ans.d.x=r1.d.x;
        else if(mark[1]==1&&mark[2]==1)
            ans.u.y=ans.r.y=r1.r.y;
        else if(mark[2]==1&&mark[3]==1)
            ans.u.x=ans.l.x=r1.l.x;
        else if(mark[0]==1&&mark[3]==1)
            ans.l.y=ans.d.y=r1.d.y;
        return true;
    } else if(cnt==1){
        cp(ans, r0);
        if(mark[0]==1){
            ans.l.y=r1.l.y;
            ans.d.x=r1.d.x;
            ans.d.y=r1.d.y;
            ans.r.x=r1.r.x;
        } else if(mark[1]==1){
            ans.u.y=r1.u.y;
            ans.d.x=r1.d.x;
            ans.r.x=r1.r.x;
            ans.r.y=r1.r.y;
        } else if(mark[2]==1){
            ans.u.x=r1.u.x;
            ans.u.y=r1.u.y;
            ans.l.x=r1.l.x;
            ans.r.y=r1.r.y;
        } else if(mark[3]==1){
            ans.u.x=r1.u.x;
            ans.l.x=r1.l.x;
            ans.l.y=r1.l.y;
            ans.d.y=r1.d.y;
        }
        return true;
    } else if(cnt == 0){
        if(r0.u.y>=r1.u.y&&r0.l.y<=r1.l.y&&r1.u.x<=r0.u.x&&r1.r.x>=r0.r.x){
            cp(ans, r0);
            ans.u.y=ans.r.y=r1.r.y;
            ans.l.y=ans.d.y=r1.d.y;
            return true;
        } else 
            return false;
    }
    return false;
}            

int main(){
    bool has_ans,over;
    int n,i,cnt=0;
    while(scanf("%d", &n)&&n) {
        for(i=0; i<n; ++i) {
            scanf("%d%d%d%d", &arr[i].l.x, &arr[i].l.y, &arr[i].r.x, &arr[i].r.y);
            arr[i].u.x=arr[i].l.x;
            arr[i].u.y=arr[i].r.y;
            arr[i].d.x=arr[i].r.x;
            arr[i].d.y = arr[i].l.y;
        }
        has_ans=true;
        for(i=1; i<n; ++i) {
            over=get_overlpping_area(arr[0], arr[i]);
            if(over) 
                cp(arr[0], ans);
            else {
                over=get_overlpping_area(arr[i], arr[0]);
                if(over) 
                    cp(arr[0], ans);
                else {
                    has_ans=false;
                    break;
                }
            }
        }
        ++cnt;
        if(n==1)
            has_ans=false;
        if(!has_ans) 
            printf("Set %d: No overlap\n", cnt);
        else 
            printf("Set %d: (%d,%d), (%d,%d)\n", cnt, arr[0].l.x, arr[0].l.y, arr[0].r.x, arr[0].r.y);
    }
    return 0;
}
/*
Problem description
Given N rectangular areas in the plane, we try to find whether it exists overlapping area of N rectangles, and if so, where is the overlapping region?

Input
The input for this problem will consist of one or more sets of data in free format. Each set will begin with an integer N < 1000 giving a number of rectangles to follow. Next will follow N rectangles, each specified as four integers, Xl, Yl, Xr, and Yr. These specify coordinates for the lower left corner (Xl, Yl) and upper right corner (Xr, Yr) of the rectangle (whose sides are always aligned parallel to the x and y axes). Coordinates may be any integer in the range -231 to 231-1.The last set of input is followed by a single integer 0.

Output
The output will consist of one line for each set, giving the number of the set and either the lower left and upper right corners of the overlapping rectangle formed by the input rectangles, or a message “No overlap” that the area covered do not exist. Use the format shown in the example.

Sample Input
3
0 0 3 3 0 1 4 4
1 0 5 2
2
-1 -1 1 3 0 -1 4 1
4
0 0 2 4 1 0 5 1
1 3 5 4 4 0 5 4
0
Sample Output
Set 1: (1,1), (3,2)
Set 2: (0,-1), (1,1)
Set 3: No overlap
*/