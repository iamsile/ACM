#include <iostream>
#include <string.h>
using namespace std;

int max(int a,int b)
{
    return a>b ? a:b;
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        char *a=new char[n+1];
        char *b=new char[n+1];
        char s;int len=0;
        int **dp=new int *[n+1];
        dp[0]=new int[n+1];
        dp[1]=new int[n+1];
        dp[0][0]=dp[1][0]=0;
        int i,j;
        for (i=1,j=n; i<=n; i++,j--) {
            dp[0][i]=dp[1][i]=0;
            cin >> s;
            a[i]=b[j]=s;
        }
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++) {
                if (a[i]==b[j])
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1; 
                else  
                    dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
                if (len<dp[i%2][j])
                    len=dp[i%2][j];
            }
        cout << n-len << '\n';
    }
    return 0;
}
/*
#include<iostream>  
using namespace std;  

int max(int a,int b)  
{  
    return a>b?a:b;  
}  

int main()  
{  
    int n;  
    while(cin>>n)  
    {  
        char* s1=new char[n+1];  
        char* s2=new char[n+1];   //s1的逆序列  
        
        int **dp=new int*[n+1];   //定义二维动态滚动数组（本题以01行滚动）  
        dp[0]=new int[n+1];  
        dp[1]=new int[n+1];  
        dp[0][0]=dp[1][0]=0; //动态数组初始化 行开头为全0  
        int i,j;
        for(i=1,j=n;i<=n;i++,j--)  
        {  
            dp[0][i]=dp[1][i]=0;  //动态数组初始化 列开头为全0  
            
            char temp;  
            cin>>temp;  
            s1[i]=s2[j]=temp;  
        } 
        
        int max_len=0;  
        for(i=1;i<=n;i++)  
            for(j=1;j<=n;j++)  
            {  
                if(s1[i]==s2[j])  
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;   //如果字符相等，则继承前一行前一列的dp值+1  
                else  
                    dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]); //否则，取上方或左方的最大dp值  
                
                if(max_len<dp[i%2][j])  
                    max_len=dp[i%2][j];  
            }  
        
        cout<<n-max_len<<endl;  
        
        delete s1;  
        delete s2;  
        delete[] dp;  
    }  
    return 0;  
}
*/
/*
 Description
 
 A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. You are to write a program which, given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome. 
 
 As an example, by inserting 2 characters, the string "Ab3bd" can be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). However, inserting fewer than 2 characters does not produce a palindrome. 
 Input
 
 Your program is to read from standard input. The first line contains one integer: the length of the input string N, 3 <= N <= 5000. The second line contains one string with length N. The string is formed from uppercase letters from 'A' to 'Z', lowercase letters from 'a' to 'z' and digits from '0' to '9'. Uppercase and lowercase letters are to be considered distinct.
 Output
 
 Your program is to write to standard output. The first line contains one integer, which is the desired minimal number.
 Sample Input
 
 5
 Ab3bd
 Sample Output
 
 2
*/