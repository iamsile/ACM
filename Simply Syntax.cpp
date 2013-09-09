#include <iostream>
using namespace::std;

int main()
{
	char s[257];
	int i;
	int len;
	while(cin >>s)
	{
		int count=0;
		len=strlen(s);
		for(i=len-1;i>=0;i--)
		{
			if(s[i]>='p'&&s[i]<='z')
				count++;
			else if(s[i]=='N')
			{
				if(count==0)
					break;
			}
			else if(s[i]=='C'||s[i]=='D'||s[i]=='E'||s[i]=='I')
				if(count>= 2)
					count--;
				else
				{
					count=0;
					break;
				}
			else 
			{
				count=0;
				break;
			}
		}
		count==1?cout << "YES\n":cout << "NO\n";
	}
	return 0;
}
/*
 Problem description
 In the land of Hedonia the official language is Hedonian. A Hedonian professor had noticed that many of her students still did not master the syntax of Hedonian well. Tired of correcting the many syntactical mistakes, she decided to challenge the students and asked them to write a program that could check the syntactical correctness of any sentence they wrote. Similar to the nature of Hedonians, the syntax of Hedonian is also pleasantly simple. Here are the rules: 
 
 0. The only characters in the language are the characters p through z and N, C, D, E, and I. 
 
 1. Every character from p through z is a correct sentence. 
 
 2. If s is a correct sentence, then so is Ns. 
 
 3. If s and t are correct sentences, then so are Cst, Dst, Est, and Ist. 
 
 4. Rules 0. to 3. are the only rules to determine the syntactical correctness of a sentence. 
 
 You are asked to write a program that checks if sentences satisfy the syntax rules given in Rule 0. - Rule 4. 
 
 Input
 The input consists of a number of sentences consisting only of characters p through z and N, C, D, E, and I. Each sentence is ended by a new-line character. The collection of sentences is terminated by the end-of-file character. If necessary, you may assume that each sentence has at most 256 characters and at least 1 character. 
 
 Output
 The output consists of the answers YES for each well-formed sentence and NO for each not-well-formed sentence. The answers are given in the same order as the sentences. Each answer is followed by a new-line character, and the list of answers is followed by an end-of-file character. 
 
 Sample Input
 Cp
 Isz
 NIsz
 Cqpq
 Sample Output
 NO
 YES
 YES
 NO
*/