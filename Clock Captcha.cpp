#include <iostream>
#include <string.h>

const int
DOT_COLUMN=14;
int cols[4]={0,7,17,24};
char screen[7][31];
char digits[10][7][6]=
{
   {"+---+",                   			
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
	"+---+"}};

bool match_digit(int pos, int digit )
{
	for(int i=0;i<7;i++)
		for(int j=0;j<5;j++)
		{
			char c=screen[i][cols[pos]+j];
			if(c!='.'&&c!=digits[digit][i][j])
			{
				return false;
			}
		}
	return true;
}

bool read_screen()
{
	if(!fgets(screen[0],31,stdin)||strcmp("end",screen[0])==0)
		return false;
	screen[0][29]='\0';
	for(int i=1;i<7;i++)
	{
		if(!fgets(screen[i],31,stdin))
			return false;
		screen[i][29]='\0';
	}
	char skip[29+1];
	return (fgets(skip,31,stdin)&&fgets(skip,31,stdin));
}

int main() 
{
	bool allowed[4][10]={
		{1,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,0,0,0}, 
		{1,1,1,1,1,1,1,1,1,1}
	};
	bool matching_digits[4][10];
	int nmatching[4];  
	while(read_screen())
	{
		memset(matching_digits,false,40*sizeof(bool));
		memset(nmatching,0,4*sizeof(int));
		for(int p=0;p<4;p++)
		{
			for(int d=0;d<10;d++)
			{	
				if(match_digit(p,d) &&
				   allowed[p][d])
				{
					matching_digits[p][d]=true;
					nmatching[p]++;
				}
				else
				{
					matching_digits[p][d]=false;
				}
			}
		}
		if(nmatching[0]==1 && matching_digits[0][2])
		{
			for(int d=4;d<10;d++)
			{
				if(matching_digits[1][d]==1)
				{
					matching_digits[1][d]=0;
					nmatching[1]--;
				}
			}
		}
		for(int d=4;d<10;d++)
		{
			if(matching_digits[1][d])
			{
				if(matching_digits[0][2])
				{
					matching_digits[0][2]=false;
					nmatching[0]--;
				} 
			}
		}
		int solution[4]={-1,-1,-1,-1};
		bool ambiguous=false;
		for(int p=0;p<4;p++)
		{
			for(int d=0;d<10;d++)
			{
				if(matching_digits[p][d] && solution[p]>=0)
				{
					ambiguous=true;
					break;
				}
				else if(matching_digits[p][d])
				{
					solution[p]=d;
				}
			}
		}
		if(ambiguous)
			puts("ambiguous");
		else
			printf("%d%d:%d%d\n",solution[0],solution[1],solution[2],solution[3]);
	}
	puts("end");
	return 0;
}
/*
 Problem description
 The digital display clock installed in problem dd is only one part of the solution to eliminate antedating documents. The second part is a camera which takes pictures of the office regularly and records at what times was each document signed and stamped. These records can later serve as an evidence.
 
 Your task is to scan a picture take by the camera and decode numbers on the digital display.	
 
 Input
 The input will exactly follow Output Specification for Problem dd, with only one important
 exception: Since image scanning is always an error-prone process, some of the characters representing the display may not be recognized correctly. Fortunately, we know which characters are incorrect, because a very sophisticated error-detecting mechanism is used. These characters are replaced by dots (“.”) in the input. Such spots can represent any of the allowed characters.
 
 There will be two blank line between adjacent cases~~	
 
 Output
 Your output must follow Input Specification for Problem dd. For each display, output the time shown on it. You may assume that at least one such time exists. However, due to the scanning errors, sometimes there may be several possible valid times that could be represented by the same picture. In such cases, we may not risk giving an incorrect information — print the word “ambiguous” instead of the time. 
 
 Sample Input
 ....+  +---+     +---+  +---+
 ...|  |          .....     |
 ...|  |      .      ..   ...
 ....+  +-...     +--....    +
 ......     |  o  |   .....  |
 . . .     ...   ....        |
 ....+  +---+     +---+      +
 
 
 ....+  +---+     +---+  +---+
 ...|      |      .....     |
 ...|      |  .      ..   ...
 ....+  +-...     +--....    +
 ......     |  o  |   .....  |
 . . .     ...   ....        |
 ....+  +---+     +---+      +
 
 
 end
 Sample Output
 15:27 
 ambiguous 
 end
*/