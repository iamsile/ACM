#include<iostream>
#include<algorithm>
using namespace std;
string operator+(string x, string y){
	if(x.size() < y.size()) // 预处理，保证x的实际长度>=y
		
		x.swap(y);
	y.insert(y.begin(), x.size()-y.size(), '0'); // y开头补0到和x一样长
	
	string sum(x.size(), -1); // 初始大小：x.size()
	
	int carry=0;
	for(int i=x.size()-1; i >= 0; --i)
	{
		carry += x[i]+y[i]-2*'0';
		sum[i] = carry%10+'0';
		carry /= 10;
	}
	
	if(carry > 0) // 还有进位1
		
		return string("1") += sum; // 给开头添加一个“1”
	
	return sum;
}
string operator*(string s, int a){
	if(s == "0" || a == 0) // 以免后面特殊处理！
		
		return "0"; 
	string prod(s.size(), -1); // 先申请s.size()位
	
	int carry=0;
	for(int i=s.size()-1; i >= 0; --i)
	{
		carry += (s[i]-'0')*a;
		prod[i] = carry%10+'0';
		carry /= 10;
	}
	while(carry>0)
	{
		prod.insert(prod.begin(), carry%10+'0');
		carry /= 10;
	}
	return prod;
}
string operator*(string x, string y){
	string prod="0"; //初值：0
	
	for(int i=y.size()-1; i >= 0; --i)
	{
        string p_sum = x * (y[i]-'0'); // p_sum：部分积
		
		if(p_sum != "0") // 保证后面加0后也符合UAdd的要求！
			
			p_sum.insert(p_sum.end(), y.size()-1-i, '0');
		prod = prod + p_sum;
	} 
	return prod;
}
int main()
{
	int n,i,j;
	string s[101];
	string temp;
	s[0]="1";
	s[1]="1";
	for(i=2;i<=100;i++)
		for(j=0;j<=i-1;j++)
		{
			temp=s[j]*s[i-1-j]; s[i]=s[i]+temp;
		}
	while(cin>>n)
	{
		if(n==-1) return 0;
		cout<<s[n]<<endl;
	}
	system("pause");
	return 0;
}
/*
 Problem description
 This is a small but ancient game. You are supposed to write down the numbers 1, 2, 3, . . . , 2n - 1, 2n consecutively in clockwise order on the ground to form a circle, and then, to draw some straight line segments to connect them into number pairs. Every number must be connected to exactly one another. And, no two segments are allowed to intersect. It's still a simple game, isn't it? But after you've written down the 2n numbers, can you tell me in how many different ways can you connect the numbers into pairs? Life is harder, right?
 
 Input
 Each line of the input file will be a single positive number n, except the last line, which is a number -1. You may assume that 1 <= n <= 100.
 
 Output
 For each n, print in a single line the number of ways to connect the 2n numbers into pairs.
 
 Sample Input
 2
 3
 -1
 Sample Output
 2
 5
*/