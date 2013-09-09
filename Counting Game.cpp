#include <iostream>
#include <string.h>
using namespace std;

int cal(int k) {
    if (k%7==0)
        return 1;
    int l=k;
    while (l) {
        if (l%10==7)
            return 1;
        l/=10;
    }
    return 0;
}

int main()
{
    int n,m,k;
    while (cin >> n >> m >> k) {
        if (!n&&!m&&!k)
            break;
        int i=1,j=1,a[110],lab,sum=0,flag=0;
        memset(a, 0, sizeof(a));
        while (1) {
            while (i<=n) {
                a[i%(1+n)]=j++;
                if (cal(a[m])&&(i%(n+1)==m)) {
                    lab=j;
                    sum++;
                    a[m]=0;
                }
                i++;
                if (sum==k) {
                    flag=1;
                    break;
                }
            }
            i-=2;
            while (i>=1) {
                a[i%(n+1)]=j++;
                if (cal(a[m])&&(i%(n+1)==m)) {
                    lab=j;
                    sum++;
                    a[m]=0;
                }
                i--;
                if (sum==k) {
                    flag=1;
                    break;
                }
            }
            i+=2;
            if (flag)
                break;
        }
        cout << lab-1 << '\n';
    }
    return 0;
}
/*
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
bool aa[1000000];
bool solve(int n)
{
    if(n%7==0)  return true;
    int t=n;
    while(t)
    {
        if(t%10==7)  return true;
        t/=10;
    }    
    return false;
}  
void calc()
{
    for(int i=1;i<1000000;i++)
    {
        if(solve(i))  aa[i]=true;
        else  aa[i]=false;
    }    
    
}      
int main()
{
    int n,m,k;
    int t;
    int cnt,lab=1;
    calc();
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if(n==0&&m==0&&k==0) break;
        t=m;
        cnt=0;
        while(1)
        {
            if(aa[t]) {
                //cout << lab++ << '\n';
                cout << "..." <<  t << '\n';
                cout << lab++ << '\n';
                cnt++;
                //cout << aa[t] << '\n';
            }
            if(cnt==k)
            {
                printf("%d\n",t);
                break;
            }  
            if(n==m)
            {
                t+=2*(m-1); 
                continue;
            }  
            if(m==1)
            {
                t+=2*(n-m);
                continue;
            }      
            t+=2*(n-m);
            if(aa[t])cnt++;
            if(cnt==k)
            {
                printf("%d\n",t);
                break;
            }  
            
            t+=2*(m-1);  
        }    
    } 
    return 0;   
}    
*/
/*
 There are n people standing in a line, playing a famous game called ``counting". When the game begins, the leftmost person says ``1" loudly, then the second person (people are numbered 1 to n from left to right) says ``2" loudly. This is followed by the 3rd person saying ``3" and the 4th person say ``4", and so on. When the n-th person (i.e. the rightmost person) said ``n" loudly, the next turn goes to his immediate left person (i.e. the (n - 1)-th person), who should say ``n + 1" loudly, then the (n - 2)-th person should say ``n + 2" loudly. After the leftmost person spoke again, the counting goes right again.
 
 There is a catch, though (otherwise, the game would be very boring!): if a person should say a number who is a multiple of 7, or its decimal representation contains the digit 7, he should clap instead! The following tables shows us the counting process for n = 4 (`X' represents a clap). When the 3rd person claps for the 4th time, he's actually counting 35.
 
 Person	 1	 2	 3	 4	 3	 2	 1	 2	 3
 Action	 1	 2	 3	 4	 5	 6	 X	 8	 9
 Person	 4	 3	 2	 1	 2	 3	 4	 3	 2
 Action	 10	 11	 12	 13	 X	 15	 16	 X	 18
 Person	 1	 2	 3	 4	 3	 2	 1	 2	 3
 Action	 19	 20	 X	 22	 23	 24	 25	 26	 X
 Person	 4	 3	 2	 1	 2	 3	 4	 3	 2
 Action	 X	 29	 30	 31	 32	 33	 34	 X	 36
 Given n, m and k, your task is to find out, when the m-th person claps for the k-th time, what is the actual number being counted.
 
 Input 
 
 There will be at most 10 test cases in the input. Each test case contains three integers n, m and k ( 2n100, 1mn, 1k100) in a single line. The last test case is followed by a line with n = m = k = 0, which should not be processed.
 Output 
 
 For each line, print the actual number being counted, when the m-th person claps for the k-th time. If this can never happen, print `-1'.
 Sample Input 
 
 4 3 1
 4 3 2
 4 3 3
 4 3 4
 0 0 0
 Sample Output 
 
 17
 21
 27
 35
*/