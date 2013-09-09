#include <iostream>
using namespace::std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x,y,i,j;
		char a[110][110]={0},b[110][110]={0};
		cin >> x >> y;
		for(i=1;i<=y;i++)
			for(j=1;j<=x;j++)
				cin >> a[i][j];
		for(i=1;i<=y;i++)
			for(j=1;j<=x;j++)
				if(a[i][j]=='*')
				{
					b[i][j]='*';
					b[i][j+1]='*';
					b[i][j-1]='*';
					b[i+1][j]='*';
					b[i-1][j]='*';
				}
		for(i=0;i<=y+1;i++,cout << '\n')
			for(j=0;j<=x+1;j++)
				if(b[i][j]=='*')
					cout << b[i][j];
				else 
					cout << '.';
		if(t)
			cout << "---\n";
	}
	return 0;
}
/*
 Problem description
 Your grandmother recently developed a passion for the internet and the new technologies in general, and is now discovering the wonders of ASCII art. Unfortunately, her sight is not as it once was, and she has difficulty seeing the pictures.
 
 Moreover, she cannot merely increase the font size as she usually does, because doing so makes the characters stand out more on their own and less as a whole. You come up with a solution: writing a program which duplicates the ASCII lines in order to make them look bold.
 
 Input
 The first line of the input will contain n, the number of test cases.
 
 Output
 For each test case, the first line will contain the positive integers w and h, both of which will be at most 100. h lines will follow, each containing w ASCII characters.
 The character “.” (dot) will denote the background ASCII “color”, and the only other color will be “*” (star). For each image, add a 1-character wide border of dots around the image, and proceed to replace every single star character in the original picture with a
 *
 ***
 *
 , where the middle star is positioned where the original star was. In the output, separate each test case with “---”.
 
 Sample Input
 2
 2 1
 *.
 3 3
 .*.
 *.*
 .*.
 Sample Output
 .*..
 ***.
 .*..
 ---
 ..*..
 .***.
 *****
 .***.
 ..*..
*/