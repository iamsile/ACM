#include<iostream> 
using namespace::std;

int main() 
{ 
	char a[100],b[100],c,d; 
	int  a0[100],b0[100],c0[100],l,l1,l2,i,j; 
	while(scanf("%s%c%c%c%s",a,&d,&c,&d,b)!=EOF) 
    {  
		for(i=l1=strlen(a)-1;i>=0;--i)  
			a0[i]=a[l1-i]-'0'; 
		for(j=l2=strlen(b)-1;j>=0;--j) 
			b0[j]=b[l2-j]-'0'; 
		l=l1+1; 
		if(l1<l2)
		{ 
			l=l2+1;
			for(i=l1+1;i<l;i++) 
				a0[i]=0;
		} 
		else if(l1>l2) 
		{ 
			l=l1+1;
			for(i=l2+1;i<l;i++)
				b0[i]=0;
		} 
		for(i=0;i<100;i++) 
			c0[i]=0; 
		if(c=='X') 
			for(i=0;i<l;i++) 
			{ 
				if(a0[i]==b0[i]) 
					c0[i]=0; 
			else 
				c0[i]=1; 
			} 
		else if(c=='O') 
			for(i=0;i<l;i++) 
			{
				if(a0[i]+b0[i]>0) 
					c0[i]=1; 
				else 
					c0[i]=0; 
			} 
		else  for(i=0;i<l;i++)  
			c0[i]=a0[i]*b0[i]; 
		while(!c0[i]&&i>0)
			i--; 
		for(j=i;j>=0;j--) 
			cout << c0[j]; 
		cout << '\n'; 
	} 
	return 0; 
}
/*
 Problem description
 Good ol' bit operations. In this problem, you'll be applying bit operations to two bit strings.
 
 Input
 Each test case will be three lines. The first line will be a bit string (1s and 0s), the second line will be one character representing what bit operation should be carried out, and the third string will be the second bit string. The operations we're concerned about are exclusive or, bitwise or, and bitwise and. The character will representing those operations will be an X for exclusive or, O for bitwise or, and A for bitwise and. No other characters will appear there. The strings will be no more than 80 characters long.
 
 Just to refresh your memory, here are the truth tables for those operations:
 
 Bitwise or (O):	Bitwise and (A):	Exclusive or (X):
 P	Q	P O Q       P	Q	P A Q       P	Q	P X Q
 0	0	0	        0	0	0           0	0	0
 0	1	1           0	1	0           0	1	1
 1	0	1           1	0	0           1	0	1
 1	1	1           1	1	1           1	1	0
 
 Output
 Your program is to print out the resultant string after applying the operation to the given input strings. Leading 0s should not be printed. If your answer string is all 0s, then print exactly one 0. The operations are carried out bit by bit. If the two input strings are not equal length, you may pad the shorter string with 0s in the leftmost position. 
 
 Sample Input
 1010001100
 X
 100
 1
 O
 101010101011010101010
 101101111001111011111111100 
 A
 000000
 Sample Output
 1010001000
 101010101011010101011
 0
*/