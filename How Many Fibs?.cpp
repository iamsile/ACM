#include <iostream>
#include <string>
using namespace std;
static string f[2100];

string operator+(const string &a,const string &b)
{
    int i,k,len1=strlen(a.c_str()),len2=strlen(b.c_str()),sum[2100]={0};
    for (i=0; i<len1; i++)
        sum[i]+=a.at(len1-i-1)-'0';
    for (i=0; i<len2; i++)
        sum[i]+=b.at(len2-i-1)-'0';
    k=len1>len2?len1:len2;
    for (i=0; i<k; i++)
        if (sum[i]>9) {
            sum[i+1]+=sum[i]/10;
            sum[i]=sum[i]%10;
            if (i==k-1)
                k++;
        }
    string temp("");
    for (i=k-1; i>=0; i--)
        temp+=sum[i]+'0';
    return temp;
}

int main()
{
    int i;
    f[0]="1";f[1]="1";
    for (i=2; i<1024; i++)
        f[i]=f[i-1]+f[i-2];
    f[0]="0";
    string a,b;
    while (cin >> a >> b&&(a[0]-'0'||b[0]-'0')) {
        int i=1,c=0;
        while(1) {  
            if(f[i].length()>a.length()) 
                break;
            else if(f[i].length()==a.length()&&f[i]>=a) break;
            i++;
        }
        while(1) {
            if(f[i]==b) {
                c++;
                break;
            }
            if(f[i].length()>b.length())  
                break;
            else if(f[i].length()==b.length()&&f[i]>b) 
                break;
            i++;  
            c++;  
        }
        cout << c << endl;
    }
    return 0;
}
/*
 Problem Description
 Recall the definition of the Fibonacci numbers: 
 f1 := 1 
 f2 := 2 
 fn := fn-1 + fn-2 (n >= 3) 
 
 Given two numbers a and b, calculate how many Fibonacci numbers are in the range [a, b]. 
 
 
 Input
 The input contains several test cases. Each test case consists of two non-negative integer numbers a and b. Input is terminated by a = b = 0. Otherwise, a <= b <= 10^100. The numbers a and b are given with no superfluous leading zeros.
 
 
 Output
 For each test case output on a single line the number of Fibonacci numbers fi with a <= fi <= b. 
 
 
 Sample Input
 10 100
 1234567890 9876543210
 0 0
 
 
 Sample Output
 5
 4
*/