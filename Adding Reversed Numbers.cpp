#include <string>
#include <iostream>
#define MAX 1000
using namespace std;

int main()
{
    string str1,str2;
    int N;
    cin>>N;
    while(N--)
    {
        cin>>str1>>str2;
        int num[MAX],num1[MAX],i=0;
        memset(num,0,sizeof(num));
        memset(num1,0,sizeof(num1));
        int len=str1.length();
        bool flag = false;
        for(i=0;i<len;++i)
        {
            num[i]=str1[i]-'0';
        }
        len=str2.length();
        for (i=0;i<len;++i)
        {
            num1[i]=str2[i]-'0';
        }
        len = str1.length()>str2.length()?str1.length():str2.length();
        for(i=0;i<len;i++)
        {
            num[i]+=num1[i];
            if(num[i]>=10)
            {
                num[i]-=10;
                num[i+1]++;
            }
        }
        if(num[len]==1) //这一步得特别在意了，在这个地方没少WA。
			len++;
        flag = false;
        for(i=0;i<len;++i) //去除多余的前导0。
        {
            if(flag||num[i])
            {
                flag=true;
                cout<<num[i];
            }
        }
        if(!flag)
            cout<<"1";
        cout<<endl;
    }
    return 0;
}
/*#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
	unsigned long int sum;
	string a,b;
    cin>>n;
    while(n--)
    {
        cin>> a >> b;
        while(a[a.length()-1]=='0')
            a = a.substr(0,a.length()-1); 
        while(b[b.length()-1]=='0')
            b = b.substr(0,b.length()-1);
        reverse(a.begin(),a.end()); 
        reverse(b.begin(),b.end());
        
        sum = atoi(a.c_str())+atoi(b.c_str());//将字符串转化为整型并相加
        while(sum%10==0)
        {
            sum = sum/10;
        }
        while(sum)
        {   
			if(sum%10!=0)
                ct<<sum%10;
            sum = sum/10;
        }
        ct<<'\n';
    }
    return 0;
}*/
//10 10的时候应该时2，不是20，oj上只有是20的时候才能过
/*
 Problem description
 The Antique Comedians of Malidinesia prefer comedies to tragedies. Unfortunately, most of the ancient plays are tragedies. Therefore the dramatic advisor of ACM has decided to transfigure some tragedies into comedies. Obviously, this work is very hard because the basic sense of the play must be kept intact, although all the things change to their opposites. For example the numbers: if any number appears in the tragedy, it must be converted to its reversed form before being accepted into the comedy play. 
 
 Reversed number is a number written in arabic numerals but the order of digits is reversed. The first digit becomes last and vice versa. For example, if the main hero had 1245 strawberries in the tragedy, he has 5421 of them now. Note that all the leading zeros are omitted. That means if the number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). Also note that the reversed number never has any trailing zeros. 
 
 ACM needs to calculate with reversed numbers. Your task is to add two reversed numbers and output their reversed sum. Of crse, the result is not unique because any particular number is a reversed form of several numbers (e.g. 21 cld be 12, 120 or 1200 before reversing). Thus we must assume that no zeros were lost by reversing (e.g. assume that the original number was 12). 
 
 Input
 The input consists of N cases. The first line of the input contains only positive integer N. Then follow the cases. Each case consists of exactly one line with two positive integers (it may be greater than 10^20.) separated by space. These are the reversed numbers you are to add. 
 
 Output
 For each case, print exactly one line containing only one integer - the reversed sum of two reversed numbers. Omit any leading zeros in the output.
 
 Sample Input
 3
 24 1
 4358 754
 305 794
 Sample Output
 34
 1998
 1
 */
