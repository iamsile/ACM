#include <iostream>
using namespace::std;

int main()
{
	float a,b,sum;
	int c,d;
	while(scanf("%f%f%d%d",&a,&b,&c,&d)!=EOF)
	{
		sum=(a+b*(d-d/(c+1)))/d;
		printf("%.2f\n",sum);
	}
	return 0;
}
/*
 Problem description
 Annual membership at a health club costs M dollars. In addition to the annual membership fee, members are normally charged an admission of A dollars upon each visit. After F visits, however, members are entitled to one free admission.
 
 For example, if M = 100.00, A = 4.00, F = 10, and a particular member visited the club 60 times during the year, then five of the 60 visits were free. The total cost to the member is 100.00 + 55 * 4.00 = 320.00 and the average cost per visit is 320.00 / 60 = 5.33 (rounded to the nearest cent).
 
 
 
 Input
 Each line of the input will contain data for one problem instance: positive values for M, A and F (defined above), and the actual number of visits V. M and A are positive floating point numbers (specified to two decimal places), F is a positive integer, and V is a non-negative integer. The end of input will be marked by end-of-file.
 
 
 
 Output
 For each line of input, the output will consist of the average cost per visit, displayed with a precision of two decimal places, i.e., rounded to the nearest cent.
 
 
 
 Sample Input
 100.00 4.00 10 60
 100.00 4.00 10 55
 Sample Output
 5.33
 5.45
*/