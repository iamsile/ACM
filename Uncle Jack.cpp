#include <iostream>
#include <string.h>
using namespace std;
int N,D;
char c[2][100];
void mult(char c[],char t[],int m)
{
    int i,l,k,flag,add=0;
    char s[100];
    l=strlen(c);
    for(i=0;i<l;i++)
        s[l-i-1]=c[i]-'0';
    for(i=0;i<l;i++)
    {
        k=s[i]*m+add;
        if (k>=10) 
        {
            s[i]=k%10;
            add=k/10;
            flag=1;
        } 
        else 
        {
            s[i]=k;
            flag=0;
            add=0;
        }
    }
    if(flag) 
    {
        l=i+1;
        s[i]=add;
    } 
    else 
        l=i;
    for(i=0;i<l;i++)
        t[l-1-i]=s[i]+'0';
    t[l]='\0';
}

int main()
{
    int i,x,y,temp;
    while(1)
    {
        cin >> N >> D;
        if(N==0&&D==0)break;
        if(N<10)
        {
            c[0][0]=N+'0';
            c[0][1]='\0';
        }
        else
        {
            c[0][0]='1';
            c[0][1]='0';
            c[0][2]='\0';
        }
        x=0;
        y=1;
        if(D==0)
            cout << 1 << endl;
        else
        {
            for(i=1;i<D;i++)
            {
                mult(c[x],c[y],N);
                temp=x;
                x=y;
                y=temp;
            }
            cout << c[x] << endl;
        }
    }
    return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m) {
        if (!n&&!m)
            break;
        if(n==10) { 
            printf("1"); 
            for(int i=0; i<m; ++i) 
                printf("0"); 
            puts(""); 
            continue; 
        }
        int a[30]={0},b[30]={0};
        a[0]=1;
        while(m--) {
            for(int i=0; i<30; ++i) 
                b[i]=a[i]*n;
            int carry = 0;
            for(int i=0; i<30; ++i) {
                a[i] = b[i]+carry;
                carry = a[i]/10;
                a[i]%=10;
            }
        }
        bool vis=false;
        for(int i=29; i>=0; --i)
            if(a[i]>0||vis) 
                printf("%d", a[i]), 
                vis=true;
        puts("");
    }
    return 0;
}
*/
/*
题目描述：D张不同CD派给N个不同的小孩，可以小孩得到0张CD，问有多少种派法。 
题目分析：从输入数据1 20得出1分析直到，D张CD必须要派完，幂运算与阶乘一样是大数，需要高精。
所犯错误：容易忘记出离D为0的情况。
*/
/*
 Problem description
 Dear Uncle Jack is willing to give away some of his collectable CDs to his nephews. Among the titles you can find very rare albums of Hard Rock, Classical Music, Reggae and much more; each title is considered to be unique. Last week he was listening to one of his favorite songs, Nobody's fool, and realized that it would be prudent to be aware of the many ways he can give away the CDs among some of his nephews.
 So far he has not made up his mind about the total amount of CDs and the number of nephews. Indeed, a given nephew may receive no CDs at all.
 
 Please help dear Uncle Jack, given the total number of CDs and the number of nephews, to calculate the number of different ways to distribute the CDs among the nephews. 
 
 
 Input
 The input consists of several test cases. Each test case is given in a single line of the input by, space separated, integers N ( 1N10) and D ( 0D25), corresponding to the number of nephews and the number of CDs respectively. The end of the test cases is indicated with N = D = 0. 
 
 Output
 The output consists of several lines, one per test case, following the order given by the input. Each line has the number of all possible ways to distribute D CDs among N nephews. 
 
 Sample Input
 1 20
 3 10
 0 0
 Sample Output
 1
 59049
*/