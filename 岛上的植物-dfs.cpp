#include <iostream>
#include <math.h>
using namespace std;

int lenp,leno,map[101][101],v[101][101];
int n,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},ap[1000];

bool cal(int m)
{
    if (m==1)
        return 0;
    for (int i=2; i<=sqrt(m); i++)
        if (!(m%i))
            return 0;
    return 1;
}

void dfsp(int x,int y)
{
    int i,nx,ny;
    for (i=0,v[x][y]=1; i<4; i++) {
        nx=x+dx[i];
        ny=y+dy[i];
        if (nx>=0&&nx<n&&ny>=0&&ny<n&&!v[nx][ny]&&cal(map[nx][ny])) {
            ap[lenp]++;
            dfsp(nx, ny);
        }
    }
}

void dfso(int x,int y)
{
    int i,nx,ny;
    for (i=0,v[x][y]=1; i<4; i++) {
        nx=x+dx[i];
        ny=y+dy[i];
        if (nx>=0&&nx<n&&ny>=0&&ny<n&&!v[nx][ny]&&!cal(map[nx][ny]))
            dfso(nx, ny);
    }
}

int main()
{
    int i,j,lab=1;
    while (scanf("%d",&n)&&n!=-1) {
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                scanf("%d",&map[i][j]);
        lenp=0;leno=0;
        memset(v, 0, sizeof(v));
        memset(ap, 0, sizeof(ap));
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                if (!v[i][j]&&cal(map[i][j])) {
                    dfsp(i, j);
                    lenp++;
                }
                else if (!v[i][j]&&!cal(map[i][j])) {
                    dfso(i,j);
                    leno++;
                }
        sort(ap, ap+lenp);
        printf("Area %d:\n",lab++);
        printf("%d unique vegetation regions:",lenp);
        for (i=0; i<lenp; i++)
            printf(" %d",ap[i]+1);
        printf("\n%d non-unique vegetation regions\n",leno);
    }
    return 0;
}
/*
 Problem description
 测绘人员将卫星拍摄的地面遥感图像转换成了数值方阵。方阵中的每个元素都是正整数，代表某单位面积土地上的植物类型。元素为质数时对应土地上的植物为稀有类型，元素为合数时对应土地上的植物为常见类型。为保护稀有植物，林业局雇佣你编写程序分析上述数值方阵，从中检测出稀有植物区和非稀有植物区。划分区域的原则是：如果数值方阵中的两个元素同为质数或同为合数，而且它们共行相邻或共列相邻，则这两个元素同属一个区域。 
 
 Input
 输入文件中包含若干待分析的数值方阵。方阵的每一行占据文件的每一行，同一行的方阵元素之间用空格分隔。每个数值方阵的前一行包含且仅包含一个正整数，代表该方阵的行数。文件的结尾行包含且仅包含一个负整数。数值方阵的行数不会超过100，元素的值不会大于100000000。
 
 Output
 针对输入文件中的每一个数值方阵分别输出如下信息： 1 该数值方阵的序号（按照其在输入文件中的位置从1计起）。格式是：“Area n:” (n代表方阵序号) 2 稀有植物区域的数目和每个稀有植物区域的面积（按升序排列）。格式是： “M unique vegetation regions: a1 a2 ...” (M为区域数目，a1, a2,...等代表每个区域的面积) 3 非稀有植物区域的数目。格式是：“K non-unique vegetation regions” (K为区域数目) 具体的输出格式请参考示例。 
 
 Sample Input
 3
 2  4 9
 17 6 37
 29 8 11
 4
 2 3 12 15
 5 7 21 33
 4 6 11 17
 8 9 13 29
 -1
 Sample Output
 Area 1:
 2 unique vegetation regions: 2 3 
 1 non-unique vegetation regions
 Area 2:
 2 unique vegetation regions: 4 4
 2 non-unique vegetation regions
*/