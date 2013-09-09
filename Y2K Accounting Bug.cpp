#include<iostream>
using namespace std;

int main()
{
	int s, d, res;
	while(scanf("%d%d", &s, &d) ==2)
	{
		if(d>4*s)
			res=10*s-2*d;
		else if(2*d>3*s)
			res=8*s-4*d;
		else if(3*d>2*s)
			res=6*s-6*d;
		else if(4*d>s) 
			res=3*s-9*d;
		else 
			res=-12*d;
		if(res<=0)
			cout << "Deficit" << '\n';
		else 
			cout << res << '\n';
	}
	return 0;
}
/*
 题意：某公司要统计全年盈利状况，对于每一个月来说，如果盈利则盈利S，如果亏空则亏空D。
 公司每五个月进行一次统计，全年共统计8次(1-5、2-6、3-7、4-8、5-9、6-10、7-11、8-12)，
 已知这8次统计的结果全部是亏空(盈利-亏空<0)。题目给出S和D，判断全年是否能盈利，如果能则
 求出盈利的最大值，如果不能盈利则输出Deficit
 输入：每月盈利和亏空的数值（每月都一样）
 输出：能最大盈利多少，不能则输出Deficit
 题意懂了，其他都不难了，一共统计8次，8次都是亏空的，要保证尽量盈利。所以把亏空放到5月份，
 如果还不能保证1-5月总额亏空，再在4月亏空，以此类推，直到1-5月亏空，6-10月复制1-5月。
 全年的盈亏情况可以由前五个月直接决定
 1、若SSSSD亏空，那么全年最优情况为SSSSDSSSSDSS
 2、若SSSDD亏空，那么全年最优情况为SSSDDSSSDDSS
 3、若SSDDD亏空，那么全年最优情况为SSDDDSSDDDSS
 4、若SDDDD亏空，那么全年最优情况为SDDDDSDDDDSD
 5、若DDDDD亏空，全年必亏空...
*/
/*
 Problem description
 Accounting for Computer Machinists (ACM) has sufferred from the Y2K bug and lost some vital data for preparing annual report for MS Inc. All what they remember is that MS Inc. posted a surplus or a deficit each month of 1999 and each month when MS Inc. posted surplus, the amount of surplus was s and each month when MS Inc. posted deficit, the deficit was d. They do not remember which or how many months posted surplus or deficit. MS Inc., unlike other companies, posts their earnings for each consecutive 5 months during a year. ACM knows that each of these 8 postings reported a deficit but they do not know how much. The chief accountant is almost sure that MS Inc. was about to post surplus for the entire year of 1999. Almost but not quite. 
 
 Write a program, which decides whether MS Inc. suffered a deficit during 1999, or if a surplus for 1999 was possible, what is the maximum amount of surplus that they can post.
 
 Input
 Input is a sequence of lines, each containing two positive integers s and d.
 
 Output
 For each line of input, output one line containing either a single integer giving the amount of surplus for the entire year, or output Deficit if it is impossible.
 
 Sample Input
 59 237
 375 743
 200000 849694
 2500000 8000000
 Sample Output
 116
 28
 300612
 Deficit
*/