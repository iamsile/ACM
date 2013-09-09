#include <iostream> 
#include <string.h>  

char number[23][11]={"zero","one","two","three","four","five",
	"six","seven","eight","nine", "ten","eleven","twelve","thirteen",
	"fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",  
	"twenty","thirty","forty"};  

void tostring(int h,int m,char *buffer) 
{  
	if(m==0)  
		sprintf(buffer,"%s o'clock",number[h] );  
	else if(m==15)  
		sprintf( buffer,"Quarter past %s",number[h]);  
	else if(m==30)  
		sprintf(buffer,"%s thirty",number[h]);              
	else if(m<=20)   
		sprintf(buffer,"%s %s",number[h],number[m]);  
	else if(m>=45) 
	{  
		if(h==12)  
			h=1;  
		else  
			h++;  
		if(m==45)  
			sprintf(buffer,"Quarter to %s",number[h]);  
		else  
			sprintf(buffer,"%s to %s",number[60-m],number[h]);  
	}  
	else 
	{ 
		sprintf(buffer,"%s %s",number[h],number[m/10+18]);  
		if((m%=10)>0)  
			sprintf(buffer+strlen(buffer),"-%s",number[m]);  
	}  
}  

int main() 
{  
	char buffer[100];  
	int n,h,m;
	scanf("%d",&n);  
	while(n--) 
	{  
		scanf("%d:%d",&h,&m);          
		tostring(h,m,buffer);  
		buffer[0]=toupper(buffer[0]);  
		puts(buffer);  
	}  
	return 0;  
}
/*#include <iostream>
using namespace::std;
char T[46][15]={"o'clock","one","two","three","four","five","six","seven","eight","nine", 
	"ten","eleven","twelve","thirteen","fourteen","Quarter","sixteen","seventeen",
	"eighteen","nineteen","twenty","twenty-one","twenty-two","twenty-three","twenty-four",
	"twenty-five","twenty-six","twenty-seven","twenty-eight","twenty-nine","thirty","thirty-one",
	"thirty-two","thirty-three","thirty-four","thirty-five","thirty-six","thirty-seven",
	"thirty-eight","thirty-nine","forty","forty-one","forty-two","forty-three","forty-four"};
char Tf[15][15]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Elven",
	"Twelve","Thirteen","Fourteen","Quarter"};

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int s,k;
		scanf("%d:%d",&s,&k);
		if(k>44)
		{
			if(k==45)
				cout << Tf[14] << " to " << T[(s+1)%12] << '\n';
			else 
				cout << Tf[60-k-1] << " to " << T[(s+1)%12] << '\n';
		}
		else if(k==0)
			cout << Tf[s-1] << " " << T[0] << '\n';
		else if(k==15)
			cout << Tf[14] << " past " << T[s] << '\n';
		else
			cout << Tf[s-1] << " " << T[k] << '\n';
		
	}//不知道为什么过不了，这种方法貌似不行？
	return 0;
}*/
/*
 Problem description
 Years ago, Brian Redman amused the entire networking community by asking on a newsgroup, ``What time is it? E-mail me and I'll summarize to the net.'' Ha ha.
 Write a program to convert a time expressed as hour:minute to the (stylized, see below) American english language version of the time. Here are the rules to implement (note that they might be different from what you are used to and are certainly different from British rules):
 
 Capitalize the first letter of the output
 Compound english numbers are hyphenated, e.g.: forty-four
 Express x:00 as [x_in_english] o'clock
 Express x:15 as Quarter past [x_in_english]
 Express x:30 as [x_in_english] thirty
 Express x:45 as Quarter to [next_hour_in_english]
 Otherwise, express x:nn as:
 [x_in_english] [nn_in_english] when nn<45
 [60-nn_in_english] to [next_hour_in_english] when nn>45
 Examples:
 
 5:00 Five o'clock
 10:10 Ten ten
 9:22 Nine twenty-two
 5:15 Quarter past five
 2:30 Two thirty
 6:40 Six forty
 5:45 Quarter to six
 8:47 Thirteen to nine
 Word list: { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
 
 
 Input
 The first line of input is a number N, then follwing N lines, each line with a time expressed as hour:minutes. Each hour is in the range 1..12; minutes are always expressed in two digits and are in the range 0..59.
 
 Output
 N lines with the time expressed as English.
 
 Sample Input
 2
 5:45
 1:12
 Sample Output
 Quarter to six
 One twelve
*/