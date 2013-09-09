#include<iostream>
#include<string.h>

double result[277];
int flag[7];
void init()
{
	int i=0;
	double sum=0;
	int initFlag=1;
	flag[0]=0;
	result[0]=0.0;
	while(sum<=5.20)
	{
		i++;
		sum+=1.0/(i+1);
		result[i]=sum;
		if(sum>=initFlag)
		{
			flag[initFlag]=i;
			initFlag++;
		}
	}
	flag[6]=276;
}

int main()
{
	char word[100000][4];
	unsigned long int total;
	unsigned long int i=0;
	double wordNum;
	int pos;
	int high,low,mid;
	init();
	while(1)
	{
		scanf("%s",word[i]);
		if(strcmp(word[i],"0.00")==0)
			break;
		i++;
	}
	total=i;
	for(i=0;i<total;i++)
	{
		wordNum=(word[i][0] - '0') * 1.0 + (word[i][2] - '0') * 0.1 + (word[i][3] - '0') * 0.01;
		pos=(int)wordNum;
		if(result[flag[pos]]<wordNum)
		{
			low=flag[pos];
			high=flag[pos+1];
		}
		else
		{
			low=flag[pos-1];
			high=flag[pos];
		}
		while(1)
		{
			if((high==(low + 1))&&result[low]<wordNum&&result[high]>=wordNum)
			{
				printf("%d card(s)\n",high);
				break;
			}
			mid=(high + low)/2;
			if(result[mid]<wordNum)
				low=mid;
			else
				high=mid;
		}
	}
	return 0;
}
/*
 Description
 
 How far can you make a stack of cards overhang a table? If you have one card, you can create a maximum overhang of half a card length. (We're assuming that the cards must be perpendicular to the table.) With two cards you can make the top card overhang the bottom one by half a card length, and the bottom one overhang the table by a third of a card length, for a total maximum overhang of 1/2 + 1/3 = 5/6 card lengths. In general you can make n cards overhang by 1/2 + 1/3 + 1/4 + ... + 1/(n + 1) card lengths, where the top card overhangs the second by 1/2, the second overhangs tha third by 1/3, the third overhangs the fourth by 1/4, etc., and the bottom card overhangs the table by 1/(n + 1). This is illustrated in the figure below.
 
 
 
 
 Input
 
 The input consists of one or more test cases, followed by a line containing the number 0.00 that signals the end of the input. Each test case is a single line containing a positive floating-point number c whose value is at least 0.01 and at most 5.20; c will contain exactly three digits.
 Output
 
 For each test case, output the minimum number of cards necessary to achieve an overhang of at least c card lengths. Use the exact output format shown in the examples.
 Sample Input
 
 1.00
 3.71
 0.04
 5.19
 0.00
 Sample Output
 
 3 card(s)
 61 card(s)
 1 card(s)
 273 card(s)
*/