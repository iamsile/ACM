#include <iostream>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
	    long int a,b,c;
		cin >> a >> b >> c;
		if(b-c>a)
			cout << "advertise\n";
		else if(b-c==a)
			cout << "does not matter\n";
		else
			cout << "do not advertise\n";
		
	}
	return 0;
}
/*
 Problem description
 
 You are the CEO of Nasty Hacks Inc., a company that creates small pieces of malicious software which teenagers may use
 to fool their friends. The company has just finished their first product and it is time to sell it. You want to make as much money as possible and consider advertising in order to increase sales. You get an analyst to predict the expected revenue, both with and without advertising. You now want to make a decision as to whether you should advertise or not, given the expected revenues. 
 
 
 Input
 The input consists of n cases, and the first line consists of one positive integer giving n. The next n lines each contain 3 integers, r, e and c. The first, r, is the expected revenue if you do not advertise, the second, e, is the expected revenue if you do advertise, and the third, c, is the cost of advertising. You can assume that the input will follow these restrictions: −106 ≤ r, e ≤ 106 and 0 ≤ c ≤ 106. 
 
 Output
 Output one line for each test case: “advertise”, “do not advertise” or “does not matter”, presenting whether it is most profitable to advertise or not, or whether it does not make any difference.
 
 Sample Input
 3
 0 100 70
 100 130 30
 -100 -70 40
 Sample Output
 advertise
 does not matter
 do not advertise
*/