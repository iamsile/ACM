#include <iostream>
using namespace::std;

int main()
{
	char a[50],b[50],f;
	double sum,n;
	while(cin >> a&&a[0]!='#')
	{
		
		if(a[0]=='0')
		{
			cout << sum << '\n';
			sum=0;
			continue;
		}
		cin >> b >> n >> f;
		if(f=='F')
			sum+=n*2;
		else if(f=='B')
			sum+=n+n/2;
		else if(f=='Y'&&n<=500)
			sum+=500;
		else 
			sum+=n;
	}
	return 0;
}
/*
 Problem description
 Mileage program of ACM (Airline of Charming Merlion) is really nice for the travelers flying frequently. Once you complete a flight with ACM, you can earn ACMPerk miles in your ACM Mileage Bank depended on mileage you actual fly. In addition, you can use the ACMPerk mileage in your Mileage Bank to exchange free flight ticket of ACM in future. 
 
 The following table helps you calculate how many ACMPerk miles you can earn when you fly on ACM. 
 
 When you fly ACM		 Class Code	          You'll earn
 
 
 
 First Class			 F		 Actual mileage + 100% mileage Bonus
 
 
 
 Business Class		   	 B		 Actual mileage + 50% mileage Bonus
 
 
 
 Economy Class			 Y
 
 1-500 miles					 500 miles
 
 500+ miles					 Actual mileage
 
 It's shown that your ACMPerk mileage consists of two parts. One is your actual flight mileage (the minimum ACMPerk mileage for Economy Class for one flight is 500 miles), the other is the mileage bonus (its accuracy is up to 1 mile) when you fly in Business Class and First Class. For example, you can earn 1329 ACMPerk miles, 1994 ACMPerk miles and 2658 ACMPerk miles for Y, B or F class respectively for the fly from Beijing to Tokyo (the actual mileage between Beijing and Tokyo is 1329 miles). When you fly from Shanghai to Wuhan, you can earn ACMPerk 500 miles for economy class and ACMPerk 650 miles for business class (the actual mileage between Shanghai and Wuhan is 433 miles). 
 
 Your task is to help ACM build a program for automatic calculation of ACMPerk mileage.
 
 Input
 The input file contains several data cases. Each case has many flight records, each per line. The flight record is in the following format: 
 OriginalCity DistanceCity ActualMiles ClassCode
 Each case ends with a line of one zero. 
 A line of one # presents the end of the input file.
 
 Output
 Output the summary of ACMPerk mileages for each test case, one per line.
 
 Sample Input
 Beijing Tokyo 1329 F 
 Shanghai Wuhan 433 Y 
 0 
 #
 Sample Output
 3158
*/