#include<iostream> 
#include<string> 
#include<map> 
using namespace std;

int pow(int x, int y)
{
	int sum=x;
	for(int i=0;i<y;i++)
		sum*=10;
	return sum;
}
int main(int argc, char* argv[])
{    
    int i = 0;
    int len;
    int r=0;
    int l=0;
    char *ptr;
    int t[1000];
    string*s=new string[1000];
    map<string,int> m;
    map<int,string> m1;
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    m1[0]="zero" ;
    m1[1]="one";
    m1[2]="two";
    m1[3]="three";
    m1[4]="four";
    m1[5]="five";
    m1[6]="six";
    m1[7]="seven";
    m1[8]="eight";
    m1[9]="nine";
    char in[100000];
    while(gets(in))
    {
		len=strlen(in)+1;
		ptr=strtok(in, " ");
		while(ptr)
		{
			if(ptr[0]!='+'&&ptr[0]!='=')
			{
				t[i]=m[ptr];
				i++;
			}
			else
			{
				for(int k=i-1,f=0;k>=0;k--,f++)
				{
					r+=pow(t[f],k);
				}
				i=0;
			}
			ptr=strtok(NULL," ");
		}
		if(r==0)
			return 0;
		int count=0;
		while(r)
		{
			s[count++]=m1[r%10];
			r=r/10;
			l++;
		} 
		for(int p=count-1; p>=0; p--)
		{
			cout<<s[p];
			if(p>0)
				cout<<" ";
		}
		cout<<endl;
		l=0;
		r=0;
    }
    return 0;
}
/*
 Problem description
 Reads in positive integers A and B,calculates A + B.Pay attention:A and B is composed by simple English word. 
 [0-9]:"zero","one","two","three","four","five","six","seven","eight","nine";
 
 Input
 Standard input will contain multiple test cases.Each testcase occupies a line.the form is "A + B =",the neighboring two characters string has a blank space.When A and B is 0 at the same time ,inputs finished.You shouldn't output the result 0.
 
 Output
 For each testcase outputs 1 line,The result of A + B,by simple English word too.Each word is separated with a single space.There's no space after the last word.
 
 Sample Input
 one + two =
 three four + five six =
 zero + zero =
 Sample Output
 three
 nine zero
*/