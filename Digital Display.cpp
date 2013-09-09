#include <iostream>
using namespace::std;

char t[12][7][6]=
{  {"+---+",                   			
	"|   |",	                                
	"|   |",	                                    
	"+   +",	                                  
	"|   |",	                                              
	"|   |",	                                         
	"+---+"},
	{"    +",	
	 "    |",	
	 "    |",	
	 "    +",	
	 "    |",	
	 "    |",	
	 "    +"},
	{"+---+",  
	 "    |",	
	 "    |",	
	 "+---+",	
	 "|    ",	
	 "|    ",	  
	 "+---+"},
	{"+---+",	
	 "    |",	
	 "    |",	
	 "+---+",	
	 "    |",	
	 "    |",	 
	 "+---+"},
	{"+   +", 
	 "|   |",	
	 "|   |",	
	 "+---+",	
	 "    |",	
	 "    |",	 
	 "    +"},
	{"+---+", 
	 "|    ",	
	 "|    ",	
	 "+---+",	
	 "    |",	
	 "    |",	
	 "+---+"},
	{"+---+", 
	 "|    ",	
	 "|    ",	
	 "+---+",	
	 "|   |",	
	 "|   |",	
	 "+---+"},
	{"+---+", 
	 "    |",	
	 "    |",	
	 "    +",	
	 "    |",	
	 "    |",	
	 "    +"},
	{"+---+", 
	 "|   |",	
	 "|   |",	
	 "+---+",	
	 "|   |",	
	 "|   |",	
	 "+---+"}, 
	{"+---+",	 
	 "|   |",	 
	 "|   |",	 
	 "+---+",	 
	 "    |",	 						  
	 "    |",	 						  
	 "+---+"},
	{"  ",
	 "  ",
	 "  ",
	 "  ",
	 "  ",
	 "  ",
	 "  "},
	{" ",
	 " ",
	 "o",
	 " ",
	 "o",
	 " ",
	 " "}
};
char b[8][30]={0};

int cal(int num,int n)
{
	int i,j,k;
	if(n==10)
	{
		for(i=0;i<7;i++)
			for(j=0;j<2;j++)
				b[i][j+num]=t[10][i][j];
		k=2;
	}
	else if(n==11)
	{
		for(i=0;i<7;i++)
			for(j=0;j<1;j++)
				b[i][j+num]=t[11][i][j];
		k=1;
	}
	else
	{
		for(i=0;i<7;i++)
			for(j=0;j<5;j++)
				b[i][j+num]=t[n][i][j];
		k=5;
	}
	return k;
}

int main()
{
	char a[6]={0};
	while(gets(a))
	{
		int i,j,num=0;
		if(a[0]=='e'&&a[1]=='n'&&a[2]=='d')
		{
			cout << "end\n";
			break;
		}
		else 
		{
			for(i=0;i<strlen(a);i++)
			{
				if(i>0)
					num+=cal(num,10);
				if(a[i]==':')
					num+=cal(num,11);
				else 
					num+=cal(num,a[i]-'0');
			}
		}
		for(i=0;i<7;i++)
		{
			for(j=0;j<num;j++)
				cout << b[i][j];
			cout << '\n';
		}
		cout << '\n';
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 There is a suspicion that some officers cheat when reporting exact time of various events. They antedate important documents and gain enormous profit by that. To eliminate such practices,ACM decided to install big digital clock on the wall of each office. Thank to this, everyone can easily see the current time and verify that it is correctly recorded on documents.
 Your task is to write a firmware for this digital clock. Digits will be shown using the classical seven-segment display. 
 
 Input
 On each line of the input, there are exactly five characters: two digits, a colon (“:”) and another two digits. These characters specify a time between 00:00 and 23:59, inclusive. The last time is followed by a line containing the word “end”. 
 
 Output
 For each input line, print a display consisting of seven rows of exactly 29 characters each. The only characters allowed are dashes (“-”) for horizontal segments, pipes (“|”) for vertical segments, plus signs (“+”) for corners, small latin letter “o” for the colon between hours and minutes, and spaces (“ ”). The area for each digit is exactly 5 characters wide and there are two empty columns (spaces)between neighboring digit areas or between a digit area and the colon. Exact digit shapes and placements can be seen in Sample Output.
 Always print two empty lines after each time displayed. Also, print the word “end” at the end of the output.
 Notice In this problem, the meaning of evaluation system responses is a little bit different than usual. If you get a Presentation Error, it most probably means that you did not follow the output format exactly. Note that it does not necessarily imply that your answer is close to the correct one. On the other hand, a Wrong Answer will be issued if the format seems basically all-right but the contents of the display are not correct. If your output contains both errors, the decision between Wrong Answer and Presentation Error is solely at the discretion of the system. Therefore, you should never try to derive any important conclusions from the response. 
 
 Sample Input
 23:00
 22:00
 21:00
 end
 Sample Output
 +---+  +---+     +---+  +---+
     |      |     |   |  |   |
     |      |  o  |   |  |   |
 +---+  +---+     +   +  +   +
 |          |  o  |   |  |   |
 |          |     |   |  |   |
 +---+  +---+     +---+  +---+
 
 
 +---+  +---+     +---+  +---+
	 |      |     |   |  |   |
     |      |  o  |   |  |   |
 +---+  +---+     +   +  +   +
 |      |      o  |   |  |   |
 |      |         |   |  |   |
 +---+  +---+     +---+  +---+
 
 
 +---+      +     +---+  +---+
     |      |     |   |  |   |
     |      |  o  |   |  |   |
 +---+      +     +   +  +   +
 |          |  o  |   |  |   |
 |          |     |   |  |   |
 +---+      +     +---+  +---+
 
 
 end
*/