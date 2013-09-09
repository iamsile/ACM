#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    char a[5100];
    int T,i;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        string x,y;
        string tx,ty;
        gets(a);
        while(strcmp(a,"END"))
        {
            for(i=0;i<strlen(a);i++)
            {
                if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n')x+=a[i];
                else tx+=a[i];
            }
            char tmp;
            while(scanf("%c",&tmp))
            {
                if(tmp=='\n')tx+=tmp;
                else {ungetc(tmp,stdin);break;}
            }
            gets(a);
        }
        gets(a);
        while(strcmp(a,"END"))
        {
            for(i=0;i<strlen(a);i++)
            {
                if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n')y+=a[i];
                else ty+=a[i];
            }
            char tmp;
            while(scanf("%c",&tmp))
            {
                if(tmp=='\n')ty+=tmp;
                else {ungetc(tmp,stdin);break;}
            }
            gets(a);
        }
        if(x==y&&tx==ty)printf("Accepted\n");
        else if(x==y&&tx!=ty)printf("Presentation Error\n");
        else if(x!=y)printf("Wrong Answer\n");
    }
    return 0;
}
/*
 
 Problem Description
 Ignatius is building an Online Judge, now he has worked out all the problems except the Judge System. The system has to read data from correct output file and user's result file, then the system compare the two files. If the two files are absolutly same, then the Judge System return "Accepted", else if the only differences between the two files are spaces(' '), tabs('\t'), or enters('\n'), the Judge System should return "Presentation Error", else the system will return "Wrong Answer".
 
 Given the data of correct output file and the data of user's result file, your task is to determine which result the Judge System will return.
 
 
 Input
 The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
 Each test case has two parts, the data of correct output file and the data of the user's result file. Both of them are starts with a single line contains a string "START" and end with a single line contains a string "END", these two strings are not the data. In other words, the data is between the two strings. The data will at most 5000 characters.
 
 
 Output
 For each test cases, you should output the the result Judge System should return.
 
 
 Sample Input
 4
 START
 1 + 2 = 3
 END
 START
 1+2=3
 END
 START
 1 + 2 = 3
 END
 START
 1 + 2 = 3
 
 END
 START
 1 + 2 = 3
 END
 START
 1 + 2 = 4
 END
 START
 1 + 2 = 3
 END
 START
 1	+	2	=	3
 END
 
 
 Sample Output
 Presentation Error
 Presentation Error
 Wrong Answer
 Presentation Error
*/