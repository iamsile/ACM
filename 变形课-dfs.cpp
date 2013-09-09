#include <iostream>
#include <string.h>
using namespace std;
int map[100][100],flag,v[100];

void dfs(int n)
{
    if (flag)
        return;
    if (n=='m'-'a') {
        flag=1;
        return;
    }
    for (int i=0; i<26&&!flag; i++)
        if (n!=i&&map[n][i]==1&&!v[i]) {
            v[i]=1;
            dfs(i);
            v[i]=0;
        }
}

int main()
{
    char ak[100];
    int s,t,len;
    while (~scanf("%s",ak)) {
        if (ak[0]=='0') {
            flag=0;
            memset(v, 0, sizeof(v));
            dfs(1);
            if (flag)
                puts("Yes.");
            else puts("No.");
            memset(ak, 0, sizeof(ak));
            memset(map, 0, sizeof(map));
        }
        else {
            flag=0;
            len=strlen(ak);
            s=ak[0]-'a';
            t=ak[len-1]-'a';
            map[s][t]=1;
        }
    }
    return 0;
}
/*
 无限re
 #include <iostream>
 #include <string.h>
 using namespace std;
 char a[1001][101];
 int map[1001],flag;
 
 void dfs(char s,int k)
 {
 if (s=='m')
 flag=1;
 int i,len;
 for (i=0; i<k&&!flag; i++) {
 if (!map[i]&&a[i][0]==s) {
 len=strlen(a[i]);
 dfs(a[i][len-1], k);
 }
 }
 }
 
 int main()
 {
 int i,j,k=0,len;
 char s[1000];
 while (~scanf("%s",s)) {
 if (s[0]=='0') {
 for (i=0,flag=0; i<k&&!flag; i++)
 if (!map[i]&&a[i][0]=='b') {
 len=strlen(a[i]);
 dfs(a[i][len-1],k);
 map[i]=1;
 }
 if (flag)
 puts("Yes.");
 else puts("No.");
 memset(a, 0, sizeof(a));
 memset(map, 0, sizeof(map));
 }
 else {
 j=strlen(s);
 for (i=0; i<j; i++)
 a[k][i]=s[i];
 map[k++]=0;
 }
 }
 
 return 0;
 }
 Problem Description
 呃......变形课上Harry碰到了一点小麻烦,因为他并不像Hermione那样能够记住所有的咒语而随意的将一个棒球变成刺猬什么的,但是他发现了变形咒语的一个统一规律:如果咒语是以a开头b结尾的一个单词,那么它的作用就恰好是使A物体变成B物体. 
 Harry已经将他所会的所有咒语都列成了一个表,他想让你帮忙计算一下他是否能完成老师的作业,将一个B(ball)变成一个M(Mouse),你知道,如果他自己不能完成的话,他就只好向Hermione请教,并且被迫听一大堆好好学习的道理.
 
 
 Input
 测试数据有多组。每组有多行，每行一个单词,仅包括小写字母,是Harry所会的所有咒语.数字0表示一组输入结束.
 
 
 Output
 如果Harry可以完成他的作业,就输出"Yes.",否则就输出"No."(不要忽略了句号)
 
 
 Sample Input
 so
 soon
 river
 goes
 them
 got
 moon
 begin
 big
 0
 
 
 Sample Output
 Yes.

*/