#include<iostream> 
using namespace::std;

int main() 
{ 
	char a[1001];
    while(cin >> a) 
    { 
		int i=0,f,l,n=strlen(a); 
		while(a[i]!='\0') 
		{ 
			while(a[i]!='<'&&a[i]!='\0')
				i++; 
			if(a[i]=='\0') 
				break; 
			i++;
			f=1;
			l=0; 
			while(l<=f&&a[i]!='\0') 
			{ 
				if(a[i]=='<') 
					f++; 
				else 
					l++; 
				i++; 
			} 
			if(a[i]=='\0') 
			{
				if(l>f) 
					n-=2*f; 
				else 
					n-=2*l;
				break;
			} 
			else 
				n-=2*f;
		} 
		cout << n << '\n';
    } 
    return 0; 
} 
/*
 Problem description
 You are doing a counting job looking for bracket pairs in a string. The characters of the string is only '<' and '>' , and a bracket pair is in the form of "<>". Each time you find a bracket pair, you remove it and the residual string is updated by removing the 2 characters from the string.
 
 For example, if you are giving a string like "><<><>>><", you can start by removing the first appearance of "<>" to get "><<>>><", then remove the only remaining bracket pair to get "><>><". Note that this produces a new bracket pair which you can remove to get ">><". Since there are no bracket pairs left, your expedition is done.
 
 Given a string, your job is count the number of characters left in the string after removing all the bracket pairs can be found. Note that the order in which you remove simultaneous appearances of bracket pairs is irrelevant; any order will lead to the same result.
 
 
 Input
 The input consists of several test cases. each case is a string on a line. The length of the string will be between 1 and 1000, inclusive.
 
 Output
 For each test case, print a line containing the number of characters left in the string.
 
 Sample Input
 ><<><>>><
 >>>><<
 <<<<<<<<<>>>>>>>>>
 ><<><><<>>>><<>><<><<>><<<>>>>>><<<
 Sample Output
 3
 6
 0
 7
*/