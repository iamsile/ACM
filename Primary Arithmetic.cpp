#include <iostream>

int main()
{
	unsigned a,b;
	while(scanf("%u%u",&a,&b)&&a&&b)
	{
		int sum=0,num=0;
		while(a||b)
		{
			sum+=a%10+b%10;
			a/=10;
			b/=10;
			sum/=10;
			if(sum)
				num++;
		}
		if(num==1)
			printf("1 carry operation.\n");
		else if(num==0)
			printf("No carry operation.\n");
		else 
			printf("%d carry operations.\n",num);
	}
	return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
	unsigned n,m,x,y,cnt,lab;
	while(cin >> n >> m)
	{
		cnt=0;
		lab=0;
		if(n==0&&m==0)
			return 0;
		if(n<m)
			swap(n,m);
		while(n!=0)
		{
			x=n%10+lab;
			y=m%10;
			n/=10;
			m/=10;
			if(x+y>9)
			{
				cnt++;
				lab=(x+y)/10;
			}
			else lab=0;
		}
		if(cnt==1)
			cout << cnt << " carry operation.\n";
		else if(cnt>1)
			cout << cnt << " carry operations.\n";
		else if(cnt==0)
			cout << "No carry operation.\n";
	}
	return 0;
}*/
/*
 这道题目就是求两个数相加时需要进位的次数，所以模拟大整数加法来计算，但有一点要注意，那就是输出时应注意operation的单复数形式，
 */
/*
 Problem description
 Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the "carry" operation - in which a 1 is carried from one digit position to be added to the next - to be a significant challenge. Your job is to count the number of carry operations for each of a set of addition problems so that educators may assess their difficulty.
 
 Input
 Each line of input contains two unsigned integers less than 10 digits. The last line of input contains 0 0.
 
 Output
 For each line of input except the last you should compute and print the number of carry operations that would result from adding the two numbers, in the format shown below. 
 
 Sample Input
 123 456
 555 555
 123 594
 0 0
 Sample Output
 No carry operation.
 3 carry operations.
 1 carry operation.
*/