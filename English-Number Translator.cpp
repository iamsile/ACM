#include<iostream>
#include<string>
using namespace std;

void fun(string str[32])
{
	long sum=0,sum2=0,sum3=0;
	int j=0;    
	string chestr[32]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
		"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
		"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred","thousand",
		"million","negative"};
	int number[32]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000,21};
	for(j=0;str[j]!="\n";j++ )
	{
		for(int i=0;i<32;i++)
		{
			if(str[j]==chestr[31])
			{
				cout<<"-";
				break;  
			}
			if(str[j]==chestr[i] )
			{
				if(i>=0&&i<=20)
				{
					sum+=i;
					break;
				}
				if(i>=21&&i<=27)
				{
					sum+=number[i];
					break;
				}
				if(i==28)
				{
					sum*=100;
					break;
				}
				if(i==29)
				{
					sum*=1000;
					sum3=sum;
					sum=0;
					break;
				}
				if(i==30)
				{
					sum*=1000000;
					sum2=sum;
					sum=0;
					break;
				}
			}   
		}
	}
	cout<<(sum+sum2+sum3)<<endl;       
}

int main()
{   
	string inputstr[32];
	char ch;
	int i;
	while(1)
	{
		inputstr[0]="zero";        
		for( i=1; ;i++ )
		{
			cin>>inputstr[i-1];               
			if(inputstr[i-1].empty())
				break;               
			ch=getchar();        
			if(ch==' ')
				continue;                    
			if(ch=='\n')
			{
				inputstr[i]="\n";
				break;
			}
		}        
		if(inputstr[i-1].empty())
			break;
		fun(inputstr);
	}
	return 0;
}
//所有测试数据都过了，但却是wa。。。。。
/*#include <iostream>
#include <map>
using namespace::std;

int main()
{
	map <string,long int> A;
	A["zero"]=0;A["one"]=1;A["two"]=2;A["three"]=3;A["four"]=4;A["five"]=5;
	A["six"]=6;A["seven"]=7;A["eight"]=8;A["nine"]=9;A["ten"]=10;A["eleven"]=11;
	A["twelve"]=12;A["thirteen"]=13;A["fourteen"]=14;A["fifteen"]=15;
	A["sixteen"]=16;A["seventeen"]=17;A["eighteen"]=18;A["nineteen"]=19;
	A["twenty"]=20;A["thirty"]=30;A["forty"]=40;A["fifty"]=50;A["sixty"]=60;
	A["seventy"]=70;A["eighty"]=80;A["ninety"]=90;A["hundred"]=100;
	A["thousand"]=1000;A["million"]=1000000;A["negative"]=-1;
	char a[10001]={0},*k;
	int j,t[100]={0};
	while(gets(a))
	{
		long int sum=0,i=0,flag=0;
		k=strtok(a, " ");
		while(k)
		{
			t[i]=A[k];
			i++;
			k=strtok(NULL, " ");
		}
		for(j=i-1;j>=0;j--)
		{
			if(t[j]>=100)
			{
				if(t[j]>flag)
					flag=t[j];
				if(t[j]<flag)
					sum+=t[j-1]*t[j]*flag;
				else 
					sum+=t[j-1]*t[j];
				j--;
			}
			else if(t[j]==-1)
				sum*=-1;
			else 
			{
				if(flag)
					sum+=t[j]*flag;
				else 
					sum+=t[j];
			}
		}
		cout << sum << '\n';
	}
	return 0;
}*/
/*
 Problem description
 In this problem, you will be given one or more integers in English. Your task is to translate these numbers into their integer representation. The numbers can range from negative 999,999,999 to positive 999,999,999. The following is an exhaustive list of English words that your program must account for: 
 negative, zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety, hundred, thousand, million 
 
 
 
 Input
 The input consists of several instances. Notes on input: 
 
 Negative numbers will be preceded by the word negative. 
 The word "hundred" is not used when "thousand" could be. For example, 1500 is written "one thousand five hundred", not "fifteen hundred".
 
 The input is terminated by an empty line.
 
 
 Output
 The answers are expected to be on separate lines with a newline after each.
 
 
 
 Sample Input
 six
 negative seven hundred twenty nine
 one million one hundred one
 eight hundred fourteen thousand twenty two
 Sample Output
 6
 -729
 1000101
 814022
*/