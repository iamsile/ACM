#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int times;
	while(cin>>times)
	{
		for(int items;times&&cin>>items;times--)
		{
			vector<int> leftParenthsis(items,0);
			int preNumber=0;
			for(int numbers,i=0;i<items&&cin>>numbers;i++)
			{
				leftParenthsis[i]=numbers-preNumber;
				preNumber=numbers;
				cout<<(i ? " ":"");
				if(leftParenthsis[i])
				{
					cout<<1;
					leftParenthsis[i]--;
				}
				else
				{
					for(int j=i;j>=0;j--)
					{
						if(leftParenthsis[j])
						{
							cout<<i-j+1;
							leftParenthsis[j]--;
							break;
						}
					}
				}            
			}
			cout<<endl;
		}
	}
	return 0;
 }
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,n,m,num=0;
        cin >> n;
        vector<int> a(n,0);
        for (i=0; i<n; i++) {
            cin >> m;
            a[i]=m-num;
            num=m;
            if (i)
                cout << ' ';
            if (a[i]) {
                cout << 1;
                a[i]--;
            }
            else {
                for (j=i; j>=0; j--) {
                    if (a[j]) {
                        cout << i-j+1;
                        a[j]--;
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
*/
/*
 题意是这样的，现在有一系列的（），要对这些左右圆括号进行编码。现在有两种编码形式，
 1。用一个整数序列P＝p1p2...pn,其中pi是第i个右括号前的左括号个数
 2。用一个整数序列W＝w1w2...wn，其中 wi 是从第 i 个右括号往左数直到遇到和它
 相对应的左括号时经过的左括号个数（包括与第i个右括号相对应的左括号）。例如：
 S (((()()()))) 
 P-sequence 4 5 6666 
 W-sequence 1 1 1456
*/
/*
 Problem description
 Let S = s1 s2 … s2n be a well-formed string of parentheses. S can be encoded in two different ways:
 	By an integer sequence P = p1 p2 … pn where pi is the number of left parentheses before the ith right 
 parenthesis in S (P-sequence).
 	By an integer sequence W = w1 w2 … wn where for each right parenthesis, say a in S, we associate an integer which is the number of right parentheses counting from the matched left parenthesis of a up to a. (W-sequence).
 
 Following is an example of the above encodings:
 
 S	 (((()()())))
 P-sequence	 4 5 6666
 W-sequence	 1 1 1456
 
 Write a program to convert P-sequence of a well-formed string to the W-sequence of the same string. 
 
 Input
 The first line of the input file contains a single integer t (1 <= t <= 10), the number of test cases, followed by the input data for each test case. The first line of each test case is an integer n (1<= n <= 20), and the second line is the P-sequence of a well-formed string. It contains n positive integers, separated with blanks, representing the P-sequence.
 
 Output
 The output file consists of exactly t lines corresponding to test cases. For each test case, the output line should contain n integers describing the W-sequence of the string corresponding to its given P-sequence.
 
 Sample Input
 2
 6
 4 5 6 6 6 6
 9
 4 6 6 6 6 8 9 9 9
 Sample Output
 1 1 1 4 5 6
 1 1 2 4 5 1 1 3 9
*/