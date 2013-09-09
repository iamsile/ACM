#include <iostream>
#include <string.h>
using namespace::std;

int main()
{
	char a[120],b[120];
	while(gets(a)!=NULL)
	{
		int i,j,flag=1,k=strlen(a);
		while(flag)
		{
			flag=0;
			for(i=0,j=0;i<k;i++)
			{
				if(i+2<k&&a[i]=='B'&&a[i+1]=='U'&&a[i+2]=='G')
				{
					i=i+2;
					flag=1;
				}
				else 
					b[j++]=a[i];
			}
			b[j]='\0';
			for(i=0;i<=j;i++)
			{
				a[i]=b[i];
			}
			k=j;
		}
		puts(b);
		
	}
	return 0;
}//有一个小陷阱，有可能删除一个bug后剩下的字符串又组合成了一个bug单词
/*
 Problem description
 The biggest problem for all software developers are bugs. You definitely know the situation when a user calls to say ”I’ve found a bug in your program”. Once you have found and removed the bug, another one appears immediately. It is a hard and never-ending process.
 Recently, there appeared a promising open-source initiative called “bug-preprocessor”. The bugpreprocessor is a program able to find all bugs in your source code and mark them, so they are relatively easy to be removed. Your task is to write a program that will remove all marked bugs from the preprocessed source code.
 
 Input
 The input contains a text representing the preprocessed source code, an unspecified number of lines of text, some of them may be empty. Bugs are represented by a case-sensitive string “BUG”.
 The text is terminated by the end of file. No line in the input will be longer than 100 characters.
 
 Output
 Your program must remove all of the bugs from the input and print a text that does not contain any BUG strings. Nothing else than bugs may be removed, not even spaces.
 
 Sample Input
 print "No bugs here..."
 void hello() {
 BUGBUG
 printfBUG("Hello, world!\n");
 }
 
 wriBUGBUGtelBUGn("Hello B-U-G");
 Sample Output
 print "No bugs here..."
 void hello() {
 
 printf("Hello, world!\n");
 }
 
 writeln("Hello B-U-G");
*/