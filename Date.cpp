#include<iostream>
using namespace::std;

int main()
{
	int n;
    cin >> n;
    while(n--)
    {
		double m;
        cin >> m;
        if(m>120)
			m=120;
        printf("%.3lf\n",(14400-(120-m)*(120-m))/28800);
    }
    return 0;
}
/*
 Problem description
 This afternoon,hft has a date with a beauty.The beauty wants to know whether they are the right people for each other,so They have made an appointment that they will select a random time between 6:00pm and 8:00pm at the palaestra(I think this is a good time to have a look at sunset!).They want to know whether they can arrive at the palaestra at the same time.You know this is almost impossible thing.So hft decides to wait n minutes at the palaestra and when the beauty arrive,he will say:"I arrive here just now!".Now,we want to know the probability of their meeting.
 
 
 Input
 The first line of the input is the number t,the number of the test case.
 Each test case:
 One line with one integer n,correponding to the minutes hft will wait.
 
 
 Output
 One line for each case:the probability of their meeting.You should print your result with exactly three digits after the decimal point.
 
 
 Sample Input
 1
 60
 Sample Output
 0.375
*/