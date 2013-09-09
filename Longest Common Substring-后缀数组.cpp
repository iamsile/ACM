#include <iostream>
#include <string>
using namespace std;

#define N 200005

int Wa[N],Wb[N],Wv[N],Ws[N],sa[N],rank[N],h[N];

int cmp(int *r,int a,int b,int l)
{
    return (r[a]==r[b]&&r[a+l]==r[b+l]);
}

void DA(const char r[],int n,int m)
{
    int i,j,p,*x=Wa,*y=Wb,*t;
    for (i=0; i<m; i++)
        Ws[i]=0;
    for (i=0; i<n; i++)
        Ws[x[i]=r[i]]++;
    for (i=1; i<m; i++)
        Ws[i]+=Ws[i-1];
    for (i=n-1; i>=0; i--)
        sa[--Ws[x[i]]]=i;
    for (j=1,p=1; p<n; j*=2,m=p) {
        for (p=0,i=n-j; i<n; i++)
            y[p++]=i;
        for (i=0; i<n; i++)
            if (sa[i]>=j)
                y[p++]=sa[i]-j;
        for (i=0; i<n; i++)
            Wv[i]=x[y[i]];
        for (i=0; i<m; i++)
            Ws[i]=0;
        for (i=0; i<n; i++)
            Ws[Wv[i]]++;
        for (i=1; i<m; i++)
            Ws[i]+=Ws[i-1];
        for (i=n-1; i>=0; i--)
            sa[--Ws[Wv[i]]]=y[i];
        for (t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y, sa[i-1], sa[i], j)?(p-1):(p++);
    }
}

void CallHeight(const char r[],int n)
{
    int i,j,k=0;
    for (i=1; i<=n; i++)
        rank[sa[i]]=i;
    for (i=0; i<n; h[rank[i++]]=k)
        for (k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++)
            ;
}

bool Check(int i,int n)
{
    return (sa[i]<=n)!=(sa[i-1]<=n);
}

int main()
{
    string str1,str2;
    while (cin >> str1 >> str2) {
        int Size1=str1.size();
        str1+=('#'+str2);
        int Size=str1.size();
        DA(str1.c_str(), Size, 123);
        CallHeight(str1.c_str(), Size);
        int i,maxn=0;
        for (i=1; i<Size; i++)
            if (h[i]>maxn&&Check(i, Size1))
                maxn=h[i];
        cout << maxn << '\n';
    }
    return 0;
}
/*
#include <iostream>
#include <string>
using namespace std;
const int MAX = 200005;//两个串之和的最大长度
int WA[MAX],WB[MAX],WV[MAX],WS[MAX],sa[MAX],rank[MAX],height[MAX];
int cmp(int *r,int a,int b,int l)
{return (r[a]==r[b] && r[a+l]==r[b+l]);}
//r待排字符串，结果sa，n字符串长度，最大字符小于m
void DA(const char* r,int n,int m)
{
    int i,j,p,*x=WA,*y=WB,*t;
    //以下四步，对长度为1的字符串进行排序(基数排序)
    for(i=0;i<m;i++) WS[i] = 0;
    for(i=0;i<n;i++) WS[x[i]=r[i]]++;
    for(i=1;i<m;i++) WS[i] += WS[i-1];
    for(i=n-1;i>=0;i--) sa[--WS[x[i]]] = i;
    for(j=1,p=1;p<n;j*=2,m=p)//进行j次双关键字基数排序
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++] = sa[i]-j;
        for(i=0;i<n;i++) WV[i] = x[y[i]];
        for(i=0;i<m;i++) WS[i] = 0;
        for(i=0;i<n;i++) WS[WV[i]]++;
        for(i=1;i<m;i++) WS[i] += WS[i-1];
        for(i=n-1;i>=0;i--) sa[--WS[WV[i]]] = y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?(p-1):(p++);
    }
}
void CalHeight(const char* r,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++) rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
}
//判断两个后缀是不是属于同一个字符串
bool Check(int i, int n)
{
    return (sa[i]<=n) != (sa[i-1]<=n);
}int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        const int Size1 = str1.size();
        str1 += ('#'+str2);//#作为分隔字符
        const int Size = str1.size();
        DA(str1.c_str(),Size,123);//'z'=122
        CalHeight(str1.c_str(),Size);
        int max = 0;
        for(int i=1; i<Size; ++i)
            if(height[i]>max && Check(i,Size1))
                max = height[i];
        cout<<max<<endl;
    }
    return 0;
}
*/
/*
 求A和B的最长公共子串等价于求A的后缀和B的后缀的最长公共前缀的最大值.将AB合并成一个串 A#B ,其中#用于分隔,然后调用DA求这个串的后缀，然后求所有后缀中排名相邻的两个后缀的最长公共前缀(就是height数组)。
 用到了height数组(排名相邻的两个后缀的最长公共前缀)，注意并不是height值中的最大值就是答案，还要保证suffix(sa[i-1])和suffix(sa[i])不是同一个字符串的两个后缀(Check函数)
 Problem Description
 Given two strings, you have to tell the length of the Longest Common Substring of them.
 
 For example:
 str1 = banana
 str2 = cianaic
 
 So the Longest Common Substring is "ana", and the length is 3.
 
 
 Input
 The input contains several test cases. Each test case contains two strings, each string will have at most 100000 characters. All the characters are in lower-case.
 
 Process to the end of file.
 
 
 Output
 For each test case, you have to tell the length of the Longest Common Substring of them.
 
 
 Sample Input
 banana
 cianaic
*/