#include <iostream>
#include <string>
using namespace std;
string s[251];

string multiplyTwo(string s1)
{
	int i,t,r=0;
	for(i=s1.size()-1;i>=0;i--)
	{
        t=s1[i]-'0';
        s1[i]=(t*2+r)%10+'0';
        r=(t*2+r)/10;
	}
	if(r!=0)
        s1.insert(s1.begin(),r+'0');
	return s1;
}

string add(string s1, string s2)
{
	if(s1.size()<s2.size())
	{
		string tmp=s1;
		s1=s2;
		s2=tmp;
	}    
	int n=s1.size();
	int m=s2.size();
	int i,t1,t2,r=0;
	for(i=1;i<=n-m;i++)
		s2.insert(s2.begin(),'0');
	for(i=n-1;i>=0;i--)
	{
		t1=s1[i]-'0';
		t2=s2[i]-'0';
		s1[i]=(t1+t2+r)%10+'0';
		r=(t1+t2+r)/10;
	}
	if(r!=0)
		s1.insert(s1.begin(),r+'0');
	return s1;
}
int main()
{
	int i,n;
	string tmp;	
	s[0]="1";
	s[1]="1";
	for(i=2;i<=250;i++)
	{
		tmp=multiplyTwo(s[i-2]);
		s[i]=add(tmp,s[i-1]);
	}
	while(scanf("%d",&n)!=EOF)
		cout<<s[n]<<endl;
	return 0;
}
//a[0]=a[1]=1;a[i]=a[i-1]+2*a[i-1];
/*
 Problem description
 In how many ways can you tile a 2xn rectangle by 2x1 or 2x2 tiles? 
 Here is a sample tiling of a 2x17 rectangle. 
 
 
 Input
 Input is a sequence of lines, each line containing an integer number 0 <= n <= 250. 
 
 Output
 For each line of input, output one integer number in a separate line giving the number of possible tilings of a 2xn rectangle. 
 
 Sample Input
 2
 8
 12
 100
 200
 Sample Output
 3
 171
 2731
 845100400152152934331135470251
 1071292029505993517027974728227441735014801995855195223534251
*/