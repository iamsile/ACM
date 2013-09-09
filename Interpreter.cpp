#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace::std;
#define Mod 1000
int n,j,lab=0,m[20]={0};
char a[10]={'\0'};

int cal()
{
    int s[10]={0},k=0,arg1,arg2,num=0,oper;
    while(++num)
    {
        oper=m[k]/100;
        arg1=m[k]%100/10;
        arg2=m[k]%10;
        k=(k+1)%Mod;
        if(oper==1)
            return num;
        else if(oper==2) 
            s[arg1]=arg2;
        else if(oper==3) 
            s[arg1]=(s[arg1]+arg2)%Mod;
        else if(oper==4) 
            s[arg1]=(s[arg1]*arg2)%Mod;
        else if(oper==5) 
            s[arg1]=s[arg2];
        else if(oper==6) 
            s[arg1]=(s[arg1]+s[arg2])%Mod;
        else if(oper==7) 
            s[arg1]=(s[arg1]*s[arg2])%Mod;
        else if(oper==8) 
            s[arg1]=m[s[arg2]];
        else if(oper==9) 
            m[s[arg2]]=s[arg1];
        else if(oper==0)
            if(s[arg2]) 
                k=s[arg1];
    }
    return 0;
}
int main()
{
    scanf("%d\n",&n);
    while(lab<n)
    {
        j=0;
        while(gets(a)!=NULL)
        {
            if(!isdigit(a[0])) 
                break;
            sscanf(a,"%d",&m[j++]);
        }
        if(lab) 
            printf("\n");
        printf("%d\n",cal());
        lab++;
    }
    return 0;
}
/*
 A certain computer has ten registers and 1,000 words of RAM. Each register or RAM location holds a three-digit integer between 0 and 999. Instructions are encoded as three-digit integers and stored in RAM. The encodings are as follows:
 
 100	 means halt
 2dn	 means set register d to n (between 0 and 9)
 3dn	 means add n to register d
 4dn	 means multiply register d by n
 5ds	 means set register d to the value of register s
 6ds	 means add the value of register s to register d
 7ds	 means multiply register d by the value of register s
 8da	 means set register d to the value in RAM whose address is in register a
 9sa	 means set the value in RAM whose address is in register a to the value of register s
 0ds	 means goto the location in register d unless register s contains 0
 All registers initially contain 000. The initial content of the RAM is read from standard input. The first instruction to be executed is at RAM address 0. All results are reduced modulo 1,000.
 
 Input
 
 The input begins with a single positive integer on a line by itself indicating the number of cases, each described as below. This is followed by a blank line, and there will be a blank line between each two consecutive inputs.
 
 Each input case consists of up to 1,000 three-digit unsigned integers, representing the contents of consecutive RAM locations starting at 0. Unspecified RAM locations are initialized to 000.
 
 Output
 
 The output of each test case is a single integer: the number of instructions executed up to and including the halt instruction. You may assume that the program does halt. Separate the output of two consecutive cases by a blank line.
 
 Sample Input
 
 1
 
 299
 492
 495
 399
 492
 495
 399
 283
 279
 689
 078
 100
 000
 000
 000
 Sample Output
 
 16
*/