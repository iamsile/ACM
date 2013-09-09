#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace::std;

struct Node{
	char name[30];
	int weight;
}d[11];

int cmp(const void *a , const void *b)
{
	struct Node *c=(Node *)a;
	struct Node *d=(Node *)b;
	if(c->weight!=d->weight) 
		return d->weight - c->weight;
	else 
		return strcmp((char *)c->name,(char *)d->name);
}

int main()
{
	char str[30];
	int n,a,b;
	bool f=0;
	while(cin >> str)
	{
		n=0;
		while(cin >> str)
		{
			if(!strcmp(str, "END"))
				break;
			strcpy(d[n].name, str);
			cin >> a >> b;
			if(b-a>0)
				d[n].weight=b-a;
			else
				d[n].weight = 0;
			n++;
		}
		qsort(d, n, sizeof(d[0]), cmp);
		if(f) cout << '\n';
		f=1;
		for(int i=0;i<n;i++)
			cout << d[i].name << '\n';
	}
}
/*
 Problem description
 As the host of a popular daytime television talk show, you are working through the details of an upcoming episode on dieting. Your guest is the controversial Dr. Kevorkian, who has recently invented his own weight-loss plan, "Do You Want To Diet?" that guarantees to reduce your body weight by 1 pound every day.
 You have a number of dieters scheduled to be on the show who have all been using Dr. Kevorkian’s new plan. You want to make the episode more dramatic by introducing your guests in decreasing order of their weights on the day of the show. The problem is that the forms you had them fill out only requested the following information: Name, Days on the diet, Weight at start of diet. Hopefully you can dredge up those long-forgotten math skills before the filming time tonight!
 
 
 Input
 Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be no blank lines separating data sets.
 A single data set has 3 components:
 
 Start line - A single line, "START"
 Dieter list - A series of 1 to 10 (inclusive) single lines consisting of three fields, with each field separated from the others by a single space:
 Name - The dieter’s first name. This will be a text string containing 1 to 20 (inclusive) alphanumeric characters (no spaces).
 Days On Diet - The number of days the dieter has been on the "Do You Want To Diet" as of the day of the talk show. This will be a non-zero positive integer strictly less than 1000.
 Starting Weight - The weight, in pounds, of the dieter just before starting the diet. This will be a non-zero positive integer strictly less than 10,000.
 End line - A single line, "END"
 Here are some facts that may be useful:
 
 All dieters lost exactly 1 pound every day they were on the diet, as advertised.
 Nobody stayed on the diet long enough to weigh less than 1 pound at the time of the show.
 All dieters in a given input set will have different weights on the day of the show.
 All dieters in a given input set will have different names.
 
 
 Output
 For each input data set, there will be exactly one output set, and there will be exactly one blank line separating output sets.
 A single output set consists of a series of lines, each containing the Name of one of the dieters from the Dieter list. The list will be sorted in descending order according to weight at the time of the TV show. All dieters must be listed.
 
 
 Sample Input
 START
 Joe 10 110
 END
 START
 James 100 150
 Laura 100 140
 Hershey 100 130
 END
 START
 Hershey0 1 5
 Hershey2 1 3
 Hershey1 1 4
 Hershey3 1 2
 END
 Sample Output
 Joe
 
 James
 Laura
 Hershey
 
 Hershey0
 Hershey1
 Hershey2
 Hershey3
*/