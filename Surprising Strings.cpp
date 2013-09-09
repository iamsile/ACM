#include<iostream>
using namespace std;

int main()
{
	char *a=new char[100];	
	while(cin >> a&&a[0]!='*')
	{
		int i,j,f,k=strlen(a);
		bool b[30][30];
		memset(b,false,sizeof(b));
		for(i=0;i<k-2;i++)
		{       
			f=0;//fail
			memset(b,false,sizeof(b));
			for(j=0;j<k;j++)
			{
				if(j+i+1>=k)
					break;
				if(b[a[j]-'A'][a[j+i+1]-'A']==true)
				{       
					++f;
					break;
				}
				else
					b[a[j]-'A'][a[j+i+1]-'A']=true;
			}
			if(f)
				break;
		}
		if(f)
			cout<<a<<" is NOT surprising.\n";
		else
			cout<<a<<" is surprising.\n";
	}
	return 0;
}
/*
 Problem description
 The D-pairs of a string of letters are the ordered pairs of letters that are distance D from each other. A string is D-unique if all of its D-pairs are different. A string is surprising if it is D-unique for every possible distance D.
 
 Consider the string ZGBG. Its 0-pairs are ZG, GB, and BG. Since these three pairs are all different, ZGBG is 0-unique. Similarly, the 1-pairs of ZGBG are ZB and GG, and since these two pairs are different, ZGBG is 1-unique. Finally, the only 2-pair of ZGBG is ZG, so ZGBG is 2-unique. Thus ZGBG is surprising. (Note that the fact that ZG is both a 0-pair and a 2-pair of ZGBG is irrelevant, because 0 and 2 are different distances.)
 
 
 
 Input
 The input consists of one or more nonempty strings of at most 79 uppercase letters, each string on a line by itself, followed by a line containing only an asterisk that signals the end of the input.
 
 Output
 For each string of letters, output whether or not it is surprising using the exact output format shown below.
 Acknowledgement: This problem is inspired by the "Puzzling Adventures" column in the December 2003 issue of Scientific American.
 
 
 
 Sample Input
 ZGBG
 X
 EE
 AAB
 AABA
 AABB
 BCBABCC
 *
 Sample Output
 ZGBG is surprising.
 X is surprising.
 EE is surprising.
 AAB is surprising.
 AABA is surprising.
 AABB is NOT surprising.
 BCBABCC is NOT surprising.
*/