#include <iostream>
using namespace std;
int dig[1010][1010];

int main()
{
    dig[1][0]=0;
    dig[2][0]=1;
    //模拟大整数！！
	int n,i,j;
	bool flag;
    for(i=3;i<=1000;i++)
        for(j=0;j<1000;j++)
        {
            dig[i][j]+=dig[i-2][j]*2+dig[i-1][j];
            if(dig[i][j]>9)
            {
                dig[i][j+1]=dig[i][j]/10;
                dig[i][j]%=10;
            }
        }
    while(cin>>n&&n)
    {
        if(n==1) 
			cout << "0" << '\n';
        else
        {
			flag=true;
            for(i=999;i>=0;i--)
            {
                if(dig[n][i]&&flag)
                    flag=false;
                if(!flag)
					cout << dig[n][i] ;
            }
            cout << '\n';
        }
    }
    return 0;
}
/*
 不少童鞋，得到了本题的递推关系：if(n&1) a[n]=2*a[n-1]-1;else a[n]=2*a[n-1]+1;这
 
 牵涉到大数，如果用c或c++ dp上去的话，有可能会超时。我们可以耍一个小聪明。
 
 把式子统一起来：a[n]=2*a[n-1]+(-1)^n。设它可以写成这样的形式:a[n]+k*(-1)^n=2*(
 
 a[n-1]+k*(-1)^(n-1))，可以解的k=-1/3，所以a[n]-(-1)^n/3是一个等比数列，然后易得
 
 a[n]=(2^(n-1)+(-1)^n)/3。n可以达到1000，所以对这么简单的式子，不用想，java！
 
 注意多用一些shift操作。
*/
/*
 Problem description
 A sequence consisting of one digit, the number 1 is initially written into a computer. At each successive time step, the computer simultaneously tranforms each digit 0 into the sequence 1 0 and each digit 1 into the sequence 0 1. So, after the first time step, the sequence 0 1 is obtained; after the second, the sequence 1 0 0 1, after the third, the sequence 0 1 1 0 1 0 0 1 and so on.
 How many pairs of consecutive zeroes will appear in the sequence after n steps?
 
 
 Input
 Every input line contains one natural number n (0 < n ≤ 1000).
 
 Output
 For each input n print the number of consecutive zeroes pairs that will appear in the sequence after n steps.
 
 Sample Input
 2
 3
 Sample Output
 1
 1
*/