#include <iostream>
#include <math.h>
using namespace std;
int a[3][3];

void cal(int n,int x[][3],int dep)
{
    unsigned i,l,f;
    i=.5+sqrt(2.*n+.25);
    if (i&1)
        l=((i-1)>>1)*i;
    else l=(i>>1)*(i-1);
    if (l==n)
        i--;
    if (i&1)
        l=((i+1)>>1)*i;
    else l=(i>>1)*(i+1);
    f=l-i;
    a[dep][0]=i;
    a[dep][1]=n-f;
    a[dep][2]=l-n+1;
}

int main()
{
    int x,y,z;
    while (scanf("%d%d%d",&x,&y,&z)!=EOF) {
        cal(x,a,0);
        cal(y,a,1);
        cal(z,a,2);
        int i,j,num;
        for (i=0,num=1; i<3&&num; i++)
            for (j=0,num=0; !num&&j<3; j++)
                num=(a[(i+1)%3][j]==a[(i+2)%3][j]&&a[i][j]!=a[(i+1)%3][j]);
        if (num)
            cout << x << ' ' << y << ' ' << z << " are vertices of an equilateral triangle.\n";
        else cout << x << ' ' << y << ' ' << z << " are not vertices of an equilateral triangle.\n";
    }
    return 0;
}
/*
#include <cstdio>
#include <cmath>
#include <climits>
#define MAXN  3
#define DEBUG 0
using namespace std;

int flag;

struct rr{
    long long n;
    long long depth;
}arr[MAXN];

inline long long get_depth(long long n){
    long long depth = sqrt(2 *(float)n);
#if DEBUG
    printf("depth=%lld\n", depth);
#endif
    if((depth + 1) * depth / 2 + 1 <= n && n <= (depth + 1) * depth / 2 + depth + 1) return depth + 1;
    else return depth;
}

inline long long get_left(long long n){
    return (1LL + n) * n / 2 - n + 1LL;
}

inline long long get_right(long long n){
    return (1LL + n) * n / 2;
}

inline void swap(struct rr *a, struct rr *b){
    long long tmp;
    tmp = a->n;
    a->n = b->n;
    b->n = tmp;
    tmp = a->depth;
    a->depth = b->depth;
    b->depth = tmp;
}

inline void sort(){
    for(long long i = 0; i < MAXN; ++i){
        long long min = INT_MAX;
        long long min_pos = i;
        for(long long j = i; j < MAXN; ++j){
            if(min >= arr[j].depth){
                min = arr[j].depth;
                min_pos = j;
            }
        }
        swap(&arr[i], &arr[min_pos]);
    }
    if(arr[0].depth == arr[1].depth){
        flag = 1;
        if(arr[0].n > arr[1].n) swap(&arr[0], &arr[1]);
    } else if(arr[1].depth == arr[2].depth){
        flag = 2;
        if(arr[1].n > arr[2].n) swap(&arr[1], &arr[2]);
    } else flag = 0;
    if(arr[0].n == arr[1].n && arr[0].n == arr[2].n && arr[1].n == arr[2].n) flag = 0;
}

int main(){
    long long va, vb, vc;
    bool ans;
    long long left, _left, right, _right, len0, len1, len2, left_len, _left_len, right_len, _right_len;
    while(scanf("%lld%lld%lld", &va, &vb, &vc) != EOF){
        arr[0].n = va;
        arr[0].depth = get_depth(va);
        arr[1].n = vb;
        arr[1].depth = get_depth(vb);
        arr[2].n = vc;
        arr[2].depth = get_depth(vc);
#if DEBUG
        printf("%lld %lld %lld %lld %lld %lld\n", va, arr[0].depth, vb, arr[1].depth, vc, arr[2].depth);
#endif
        sort();
        if(flag == 0) ans = false;
        else if(flag == 1){
            len0 = arr[1].n - arr[0].n;
            len1 = arr[2].depth - arr[0].depth;
            len2 = arr[2].depth - arr[1].depth;
            if(len0 == len1){
                left = get_left(arr[0].depth);
                right = get_right(arr[0].depth);
                _left = get_left(arr[2].depth);
                _right = get_right(arr[2].depth);
                left_len = arr[1].n - left;
                right_len = right - arr[0].n;
                _left_len = arr[2].n - _left;
                _right_len = _right - arr[2].n;
                if(left_len == _left_len && right_len == _right_len) ans = true;
                else ans = false;
            } else ans = false;
        } else if(flag == 2){
            len0 = arr[1].depth - arr[0].depth;
            len1 = arr[2].depth - arr[0].depth;
            len2 = arr[2].n - arr[1].n;
            if(len0 == len2){
                left = get_left(arr[0].depth);
                right = get_right(arr[0].depth);
                _left = get_left(arr[2].depth);
                _right = get_right(arr[2].depth);
                left_len = arr[0].n - left;
                right_len = right - arr[0].n;
                _left_len = arr[1].n - _left;
                _right_len = _right - arr[2].n;
                if(left_len == _left_len && right_len == _right_len) ans = true;
                else ans = false;
            } else ans = false;
        }
        printf("%lld %lld %lld %s\n", va, vb, vc, ans ? "are vertices of an equilateral triangle." : "are not vertices of an equilateral triangle.");
    }
    return 0;
}
*/
/*
 没想到这题的通过率这么低。 
 求等边三角形网格中(i,j,k)的是否等边三角形，将每一点的序号转换为一个三维坐标，分别表示点所在层数，60度直线循序数，120度直线循序数。如：点1的坐标为(1,1,1),4->(3,1,3),6->(3,3,1) 
 判断三个点是否等边三角形，显然只有2点之间有且只有一个座标值相同。 
 核心代码： 
 coordinate(int n,int x[3])//输入序号n,返回坐标值x[3] 
 {unsigned i,last,first;//注意数据溢出 
 i=.5+sqrt(2.*n+.25); 
 if(i&1)last=((i-1)>>1)*i;else last=(i>>1)*(i-1);//注意数据溢出 
 if(last==n)i--; 
 if(i&1)last=((i+1)>>1)*i;else last=(i>>1)*(i+1);//注意数据溢出 
 first=last-i; 
 x[0]=i;x[1]=n-first;x[2]=last-n+1;} 
 判断是否等边三角形的代码： 
 coordinate（i,x[0]);coordinate(j,x[1]);coordinate(k,x[2]); 
 for(m=0,f=1;f&&m<3;++m) 
 for(n=f=0;!f&&n<3;++n) 
 f=(x[(m+1)%3][n]==x[(m+2)%3][n]&&x[m][n]!=x[(m+1)%3][n]);//f为1是等边三角形，否则不是 
 
 
 Equilateral triangle 的另一篇解题报告 
 
 arr[]用来存储每行序号的最大值 ：1, 3, 6, 10, 15 … 
 
 void getpos(int n, int &x, int &y) 
 //输入序号n,返回坐标值x,y，分别为n所在行号和列号（从0数起），例如序号5为2，1；6为3，2 
 { 
 x = binsearch(n);//二分法查找n的行号,写得极其痛苦，调试了n久才发现边界出了问题，代码超级垃圾。顺序查找会超时。 
 y = x - (arr[x] - n); 
 } 
 
 
 bool check(int ax,int  ay, int bx, int  by, int  cx, int  cy) 
 //判断是否为正三角形，a,b为在同一行的两点，c为剩下的一点 
 { 
 int edge = abs(ay - by);    //在同一行的两点组成的边的长度，暂且称其为底边长度 
 if(abs(cx - ax) != edge) return 0;//c与a,b的行号之差，如果与底边长不相等则肯定不是正三角形 
 if(cx < ax && cy == (ay < by ? ay : by)) return 1;//当c点在a,b上面时，若c与a,b中靠左边的一个点共线则是正三角形 
 else if(cx > ax && cy == (ay > by ? ay : by)) return 1;  //当c点在a,b下面时，若与a,b中靠右边的一个点共线则是正三角形 
 else return 0; 
 } 
 */
/*
 Problem description
 
 
 There is an infinite equilateral triangle gridding ， numbering vertices(crossing points) as shown in figure below.Some three vertices of them form an equilateral triangle,for example,{1,2,3},{7,9,18},etc.These equilateral triangles must satisfy that each edge of the equilateral triangle is a part of a line of the equilateral triangle gridding.Thus vertices{5 10 13} are not vertices of an equilateral triangle.
 Your task is to point out whether three given vertices form an equilateral triangle. 
 
 Input
 Input is a sequence of lines, each line containing three integers:i,j,k , indicating numbers of 3 vertices. You may assume that 0 < i,j,k<231 .
 
 Output
 For each line of input, output one line “i j k are vertices of an equilateral triangle.” if vertices {i,j,k} form an equilateral triangle,otherwise, output one line “i j k are not vertices of an equilateral triangle.”
 
 Sample Input
 1 2 3
 6 7 8
 7 9 18
 5 10 13
 Sample Output
 1 2 3 are vertices of an equilateral triangle.
 6 7 8 are not vertices of an equilateral triangle.
 7 9 18 are vertices of an equilateral triangle.
 5 10 13 are not vertices of an equilateral triangle.
*/