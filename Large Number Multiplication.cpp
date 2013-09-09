#include <iostream>
#include <string>
using namespace::std;
unsigned int total[400];
unsigned int num1[200];
unsigned int num2[200];

int main()
{
	int len,index,i,j;
	bool flag;
	string str1,str2;
	while(cin>>str1>>str2)
	{
		memset(total,0,sizeof(total));
		len=str1.length();
		index=0;
		for(i=len-1;i>=0;i--)
			num1[index++]=str1[i]-'0';
		len=str2.length();
		index=0;
		for(i=len-1;i>=0;i--)
			num2[index++]=str2[i]-'0';
		for(i=0;i<str1.length();i++)
			for(j=0;j<str2.length();j++)
				total[i+j]+=num1[i]*num2[j];
		for(i=0;i<400;i++)
		{
			if(total[i]>=10)
			{
				total[i+1]+=total[i]/10;
				total[i]%=10;
			}
		}
		flag=false;
		for(i=399;i>=0;i--)
		{
			if(flag||total[i])
			{
				flag=true;
				cout<<total[i];
			}
		}
		if(!flag)
		{
			cout<<"0";
		}
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 Multiplying integers is easy, provided they fit within 32 bits. Unfortunately, not everything falls within 32 bits. We want exact results for multiplying two obnoxiously large numbers. 
 
 Input
 Each input set consists of two lines. Each line consists of a positive integer no more than 100 digits in length. There are no spaces on a line. 
 
 Output
 For each input set, output the result of multiplying the two integers togther. All leading zeros should be repressed. 
 
 Sample Input
 9
 8
 9
 7
 100
 16
 105679
 103457
 Sample Output
 72
 63
 1600
 10933232303
 */
