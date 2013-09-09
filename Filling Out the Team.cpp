#include <iostream>
using namespace::std;
int a[3][3]={45,150,200,60,300,500,50,200,300};
string b[3]={"Wide Receiver ","Lineman ","Quarterback "};
int main()
{
	float s;
	int w,st,i,flag;
	while(cin >> s >> w >> st&&s&&w&&st)
	{
		s=10*s;
		flag=0;
		for(i=0;i<3;i++)
			if(s<=a[i][0]&&w>=a[i][1]&&st>=a[i][2])
			{
				cout << b[i];
				flag++;
			}
		if(!flag)
			cout << "No positions";
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 Over the years, the people of the great city of Pittsburgh have repeatedly demonstrated a collective expertise at football second to none. Recently a spy has discovered the true source of the city's football power-a wizard known only as "Myron," who is infallible at selecting the proper position at which each player will excel. 
 
 Now that you know the source of Pittsburgh's wisdom, you are determined to provide your school's football team with a computer program that matches the wisdom of "Myron." You have consulted with the best football minds you can find, and they have dispensed their wisdom on the slowest speed, minimum weight, and minimum strength required to play each position. 
 
 Position        slow.speed   min.weight   min.streng
 wide receiver     4.5           150          200
 lineman           6.0           300          500
 quarterback       5.0           200          300
 
 Using this knowledge, you will develop a program that reads in several players physical attributes and outputs what position(s) they are able to play.
 
 
 Input
 Each line of the input file will list the attributes for one player: 
 < speed > < weight > < strength > 
 Each number will be a real-valued number. The file will end with a line reading "0 0 0"
 
 
 Output
 For each player, you will output one line listing the positions that player can play. A player can play a position if each of their attributes is greater or equal to the minimum for weight and strength, and less than or equal to the slowest speed. If a player can play multiple positions, output them in the order listed above, separated by whitespace. eg [position1][space][position2][space]...[positionN][space]. If a player can play no positions, write "No positions" on the line.
 
 
 Sample Input
 4.4 180 200
 5.5 350 700
 4.4 205 350
 5.2 210 500
 0 0 0
 Sample Output
 Wide Receiver 
 Lineman 
 Wide Receiver Quarterback 
 No positions
*/