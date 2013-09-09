/*#include<iostream>
#include<string>
using namespace std;

int main(){
    char str[100];
    int x,c,n,i,j,sum[110];
    cin>>n;
    while(n--){
        memset(sum,0,sizeof(sum));
        c=0;
        while(cin>>str,strcmp(str,"0")){
            for(i=j=strlen(str)-1;0<=i;i--)
                sum[j-i]+=str[i]-'0';
        }
        for(i=0;i<110;i++){
            x=sum[i]+c;
            sum[i]=x%10;
            c=x/10;
        }
        i=109;
        while(sum[i]==0)i--;
        if(i<0)cout<<"0";
        for(;i>=0;i--)
            cout<<sum[i];
        cout<<endl;
        if(n)cout<<endl;
    }
    return 0;
}*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        char a[110];
        int i,k,b[110];
        memset(b, 0, sizeof(b));
        while (cin >> a) {
            if (a[0]=='0')
                break;
            k=(int)strlen(a);
            for (i=0; i<k; i++)
                b[i]+=a[k-i-1]-'0';
            memset(a, 0, sizeof(a));
        }
        for (i=0; i<110; i++) {
            if (b[i]>9) {
                b[i+1]+=b[i]/10;
                b[i]%=10;
            }
        }
        for (i=109; i>=0; i--)
            if (b[i]!=0)
                break;
        if (i<0)
            cout << "0";
        for (; i>=0; i--)
            cout << b[i];
        cout << '\n';
        if (n)
            cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 One of the first users of BIT's new supercomputer was Chip Diller. He extended his exploration of powers of 3 to go from 0 to 333 and he explored taking various sums of those numbers. 
 ``This supercomputer is great,'' remarked Chip. ``I only wish Timothy were here to see these results.'' (Chip moved to a new apartment, once one became available on the third floor of the Lemon Sky apartments on Third Street.) 
 
 
 Input
 The input will consist of at most 100 lines of text, each of which contains a single VeryLongInteger. Each VeryLongInteger will be 100 or fewer characters in length, and will only contain digits (no VeryLongInteger will be negative). 
 
 The final input line will contain a single zero on a line by itself.
 
 
 Output
 Your program should output the sum of the VeryLongIntegers given in the input. 
 
 
 This problem contains multiple test cases!
 
 The first line of a multiple input is an integer N, then a blank line followed by N input blocks. Each input block is in the format indicated in the problem description. There is a blank line between input blocks.
 
 The output format consists of N output blocks. There is a blank line between output blocks.
 
 
 Sample Input
 1
 
 
 123456789012345678901234567890
 123456789012345678901234567890
 123456789012345678901234567890
 0
 
 
 Sample Output
 370370367037037036703703703670
*/