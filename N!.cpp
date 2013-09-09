/*#include <iostream>
using namespace::std;

int main() 
{ 
    int n,j,i,k=0,t=0,p=0,sum=0,s[16000]={0};  
    while(scanf("%d",&n)!=EOF)
    { 
        s[0]=1;
        k=0; 
        t=0; 
        p=0;
        for(j=1;j<=n;j++) 
        { 
            for(i=0;i<=t;i++) 
            { 
                sum=s[i]*j+p; 
                p=0; 
                if(sum>9999) 
                { 
                    s[i]=sum%10000; 
                    p=sum/10000; 
                    if(t==i) 
                    { 
                        t++; 
                        s[t]=0; 
                    } 
                } 
                else 
                    s[i]=sum; 
            } 
        }         
        cout << s[t]; 
        for(i=t-1;i>=0;i--)
        { 
            if (s[i]<10) 
                cout << "000"; 
            else if(s[i]<100)
                cout << "00"; 
            else if(s[i]<1000)
                cout << "0"; 
            
            cout << s[i]; 
        } 
        cout << '\n';
    }
    return 0; 
}
 
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,t;
    int a[301];
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        if(n==0){
            printf("1\n");continue;
        }
        t=1;a[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<t;j++)a[j]=a[j]*i;
            for(j=0;j<t;j++){
                a[j+1]+=a[j]/10;
                a[j]=a[j]%10;    
            }
            while(a[t]){
                a[t+1]+=a[t]/10;
                a[t]=a[t]%10;
                t++;
            }
        }
        for(i=t-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}*/
#include <iostream>
#include <string.h>
using namespace std;
int a[100001];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n==0)
            cout << "1\n";
        else {
            int i,j,k=1;
            memset(a, 0, sizeof(a));
            a[0]=1;
            for (i=1; i<=n; i++) {
                for (j=0; j<=k; j++)
                    a[j]*=i;
                for (j=0; j<=k; j++)
                    if (a[j]>9) {
                        a[j+1]+=a[j]/10;
                        a[j]%=10;
                        if (j+1==k)
                            k++;
                    }
            }
            for (i=k;i>=0;i--)
                if (a[i])
                    break;
            for (j=i; j>=0; j--)
                cout << a[j];
            cout << '\n';
        }
    }
    return 0;
}

/*
 Problem Description
 Given an integer N(0 ≤ N ≤ 10000), your task is to calculate N!
 
 
 Input
 One N in one line, process to the end of file.
 
 
 Output
 For each N, output N! in one line.
 
 
 Sample Input
 1
 2
 3
 
 
 Sample Output
 1
 2
 6
*/