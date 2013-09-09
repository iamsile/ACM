#include <iostream>
using namespace std;
int main()
{
	int n,w,sum,i,j,k;
	while(cin >> n&&n)
	{
		if(n==1)
		{
			cout <<"Printing order for " << n << " pages:" << endl;
			cout << "Sheet 1, front: Blank, 1" << endl;
		}
		else
		{
			if(n%4!=0)
				w=n/4+1;
			else
				w=n/4;
			sum=4*w+1;
			k=0;
			cout <<"Printing order for " << n << " pages:" << endl;
			for(i=1,j=n;i<=j;i++)
			{
				if(i+j!=sum)
				{
					if(i%2==1)
						cout << "Sheet " << ++k << ", front: " << "Blank" <<", " << i << endl;
					else
						cout << "Sheet " << k << ", back : " << i <<", " << "Blank" << endl;
				}
				else
				{
					if(i%2==1&&k<=w)
						cout << "Sheet " << ++k << ", front: " << j <<", " << i << endl;
					else
						cout << "Sheet " << k << ", back : " << i <<", " << j << endl;
					j--;
				}
			}
		}
	}
	return 0;
}
/*
 Problem description
 
 When printing out a document, normally the first page is printed first, then the second, then the third, and so on until the end. However, when creating a fold-over booklet, the order of printing must be altered. A fold-over booklet has four pages per sheet, with two on the front and two on the back. When you stack all the sheets in order, then fold the booklet in half, the pages appear in the correct order as in a regular book. For example, a 4-page booklet would print on 1 sheet of paper: the front will contain page 4 then page 1, and the back will contain page 2 then page 3.
 Front              Back
 -------------      -------------
 |     |     |      |     |     |
 |  4  |  1  |      |  2  |  3  |
 |     |     |      |     |     |
 -------------      -------------
 Your task is to write a program that takes as input the number of pages to be printed, then generates the printing order. 
 
 Input
 
 The input file contains one or more test cases, followed by a line containing the number 0 that indicates the end of the file. Each test case consists of a positive integer n on a line by itself, where n is the number of pages to be printed; n will not exceed 100.
 
 Output
 
 For each test case, output a report indicating which pages should be printed on each sheet, exactly as shown in the example. If the desired number of pages does not completely fill up a sheet, then print the word Blank in place of a number. If the front or back of a sheet is entirely blank, do not generate output for that side of the sheet. Output must be in ascending order by sheet, front first, then back.
 
 Sample Input
 1
 14
 4
 0
 Sample Output
 Printing order for 1 pages:
 Sheet 1, front: Blank, 1
 Printing order for 14 pages:
 Sheet 1, front: Blank, 1
 Sheet 1, back : 2, Blank
 Sheet 2, front: 14, 3
 Sheet 2, back : 4, 13
 Sheet 3, front: 12, 5
 Sheet 3, back : 6, 11
 Sheet 4, front: 10, 7
 Sheet 4, back : 8, 9
 Printing order for 4 pages:
 Sheet 1, front: 4, 1
 Sheet 1, back : 2, 3
*/