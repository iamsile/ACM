#include <iostream>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		int i,n=0,count=1;
		char t,a[10010]={0};
        cin >> a;
		n=strlen(a);
		t=a[0];
		for(i=1;i<n;i++) 
		{ 
			if (a[i]!=t)
			{
                if (count>1)
                    cout << count;
                cout << t;
				t=a[i]; 
				count=1;
			} 
			else
				count++; 
		}
        if (count>1)
            cout << count;
		cout<< t<< '\n'; 
		memset(a, 0, sizeof(a));
	}
	return 0;
}
/*
 Problem Description
 Given a string containing only 'A' - 'Z', we could encode it using the following method: 
 
 1. Each sub-string containing k same characters should be encoded to "kX" where "X" is the only character in this sub-string.
 
 2. If the length of the sub-string is 1, '1' should be ignored.
 
 
 Input
 The first line contains an integer N (1 <= N <= 100) which indicates the number of test cases. The next N lines contain N strings. Each string consists of only 'A' - 'Z' and the length is less than 10000.
 
 
 Output
 For each test case, output the encoded string in a line.
 
 
 Sample Input
 2
 ABC
 ABBCCC
 
 
 Sample Output
 ABC
 A2B3C
*/