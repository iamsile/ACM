#include <iostream>
using namespace::std;
const int monlen[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	while(1)
	{
		char bfr[22];
		fgets(bfr,25,stdin);
		if(bfr[0]=='e')
			break;
		int i,dig,dcnt=0,scnt=0,year=0,month=0,day=0,last=0,test=0;		
		for(i=0;bfr[i]!='\0';i++)
		{
			if(bfr[i]>='0'&&bfr[i]<='9')
			{
				dig=bfr[i]-'0';
				if(scnt==0)
				{
					if(dcnt<2) 
						year=10*year+dig;
					else if(dcnt<4) 
						month=10*month+dig;
					else if(dcnt<6)
						day=10*day+dig;
					else 
						goto print;
				}
				else
				{
					if(dcnt>=4||(year>=10&&year<=53&&dcnt>=3)) 
						goto print;
					last=10*last+dig;
				}
				test+=((dcnt&1)?(dig):(-dig));
				dcnt++;
			}
			if(bfr[i]=='/') 
			{ 
				if(dcnt!=6) 
					goto print;
				scnt++;
				dcnt=0; 
			}
			if(scnt>=2)
				goto print;
		}
		if(dcnt<3||(dcnt==3&&(year<10||year>53))) 
			goto print;
		if(test%11!=0&&(year<=9||year>=54))
			goto print;
		if((year>9&&year<20)||(month%50==0||month%50>12))
			goto print;
	 	if(day==0||(day>monlen[month%50]&&(day!=29||month%50!=2||(year&3)!=0)))
			goto print;
		if(month>50) 
			printf("girl\n"); 
		else
			printf("boy\n");
		continue;
	print:
		printf("invalid\n");
		
	}
	return 0;
}
/*
 Problem description
 Corruptionists often use fictional persons to camouflage their illegal activities. They create fake database records containing non-existing names, addresses, or even personal identifiers. ACM would like to fight against such practices. They are going to examine several suspicious databases and search them for invalid records. Can you help them by checking validity of Personal IDs?
 (Please note: In reality, some of the facts stated below may not be true and some identifiers may violate them in exceptional cases. However, for the purpose of this problem, we will assume an ideal world without any such exceptions.)
 Personal ID (a.k.a. “rodn´e ˇc´ıslo” or simply RˇC) is a unique identifier of a Czech (or Slovak) citizen. It is assigned once a child is born and remains unchanged for the whole life.
 The identifier has two numerical parts separated with a single slash character (“/”). The first part always consists of exactly six digits and it represents the birth date of the person in the form of “YYMMDD”: the first two digits specify a year (“modulo” 100), other two digits a month (01?12), and the last two digits a day in the month (01?31, but some months have less days, of course). Beside the birth date, this part stores also information about the gender: all girls get the month number increased by 50. Thus, for instance, 61 means November for them.
 The second part may have either 3 or 4 digits (all of them may be zero). For all identifiers assigned until December 31, 1953, there were only three digits. Starting from January 1, 1954, all children are assigned IDs with exactly four digits after the slash. The additional digit allows for a simple automated check — if we remove the slash, the whole ten-digits-long number must be divisible by 11. 
 
 Input
 Each line of the input contains one string consisting of at least 1 and at most 20 characters, each of them being either a digit or a slash (“/”). The word “end” follows the last string. 
 
 Output
 For each string, output the word “invalid” if the given string does not represent a valid Personal ID of a person born between January 1, 1920 and December 31, 2009, inclusive. For valid identifiers, print either “girl” or “boy”, depending on the gender of the child who could be assigned that ID. 
 
 Sample Input
 531019/534
 541019/123
 535318/6663
 545318/6662
 545318/6666
 006231/5000
 000229/0002
 010229/0001
 /
 /3/
 200101/000
 191231/999
 end
 
 Sample Output
 boy
 invalid
 invalid
 girl
 invalid
 girl
 boy
 invalid
 invalid
 invalid
 boy
 invalid
*/