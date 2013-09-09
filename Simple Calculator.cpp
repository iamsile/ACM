#include <iostream>
using namespace std;

int main()
{
    char a[6][20];
    int i=0,j,k,flag,lab1,lab2,x=0,y=0,num,b[6]={0};
    while (scanf("%s",a[i])&&i<5) {
        i++;
    }
    for (i=0; i<6; i++) {
        k=strlen(a[i]);
        flag=0;lab1=0;lab2=0;num=0;x=0;y=0;
        for (j=2; j<k; j++) {
            if (a[i][j]=='-')
                flag=1;
            else if (a[i][j]>='0'&&a[i][j]<='9') {
                if (flag)
                    x=0-(a[i][j]-'0')+x*10;
                else x=(a[i][j]-'0')+x*10;
            }
            else if (a[i][j]=='*') {
                flag=0;
                lab1=1;
                break;
            }
            else if (a[i][j]=='+') {
                flag=0;
                lab2=1;
                break;
            }
            else if (a[i][j]<='e'&&a[i][j]>='a') {
                if (flag)
                    x=0-b[a[i][j]-'a'];
                else x=b[a[i][j]-'a'];
            }
            else if (a[i][j]=='n')
                x=0;
        }
        for (j++; j<k; j++) {
            if (a[i][j]=='-')
                flag=1;
            else if (a[i][j]>='0'&&a[i][j]<='9') {
                if (flag)
                    y=0-(a[i][j]-'0')+y*10;
                else y=(a[i][j]-'0')+y*10;
            }
            else if (a[i][j]<='e'&&a[i][j]>='a') {
                if (flag)
                    y=0-b[a[i][j]-'a'];
                else y=b[a[i][j]-'a'];
            }
            else if (a[i][j]=='n')
                y=0;
        }
        if (lab1)
            printf("%d\n",num=(x*y));
        else printf("%d\n",num=(x+y));
        if (a[i][j]=='n')
            b[5]=0;
        else b[a[i][0]-'a']=num;
    }
    for (i=0; i<5; i++)
        cout << char(i+97) << '=' << b[i] << '\n';
    cout << "n=0\n";
    return 0;
}
/*
 Problem description
 A very simple calculator would have support for instructions of the form z = x op y where op is some operation, x, y can be either variables or numbers, and z is a variable. (btw: this syntax is similar to 3 address code, which simple compilers make use of). 
 
 for our purposes, op can only be +, or * (each with their usual, obvious, meanings). the variables can be a, b, c, d, e, n All of them, except n can store values. n is a "null" variable. You can write to it, but it's value always stays at 0. All the variables are initialized to 0 at the start. 
 
 Input
 Each line of input will be in the form of z = x op y where x, y can be either one of the varaibles listed above, or an integer (positive or negative). All integers given will be between -32767 to 32767, inclusive. Each variable, though, can store a full 32-bit number. z can only be a variable. op is a +, or *. 
 
 No embedded spaces will appear on the line. No other characters, other than the ones for variables, numbers, or operations, will appear. All variables will be lower case. 
 
 Output
 For each line, print the value of x op y. (the semantics are that the value is first printed, then it's stored into the variable). AFter all lines of input have been read in, print the final values of each register. These values should be printed one per line in the form var=val 
 
 Sample Input
 a=0*2
 b=a+2
 c=b*10
 d=c+-20
 e=n+d
 n=100*b
 Sample Output
 0
 2
 20
 0
 0
 200
 a=0
 b=2
 c=20
 d=0
 e=0
 n=0
*/