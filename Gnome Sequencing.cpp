#include <iostream>
using namespace::std;

int main()
{
	int n,i,a[4];
	cin >> n;
	cout << "Gnomes:\n";
	while(n--)
	{
		for(i=0;i<3;i++)
			cin >> a[i];
		if((a[0]>a[1]&&a[1]>a[2])||
			(a[0]<a[1]&&a[1]<a[2]))
			cout << "Ordered\n";
		else 
			cout << "Unordered\n";
	}
	return 0;
}
/*
 Problem description
 In the book All Creatures of Mythology, gnomes are kind, bearded creatures, while goblins tend to be bossy and simple-minded. The goblins like to harass the gnomes by making them line up in groups of three, ordered by the length of their beards. The gnomes, being of different physical heights, vary their arrangements to confuse the goblins. Therefore, the goblins must actually measure the beards in centimeters to see if everyone is lined up in order.
 
 Your task is to write a program to assist the goblins in determining whether or not the gnomes are lined up properly, either from shortest to longest beard or from longest to shortest.
 
 
 
 Input
 The input starts with line containing a single integer N, 0 < N < 30, which is the number of groups to process. Following this are N lines, each containing three distinct positive integers less than 100. 
 
 Output
 There is a title line, then one line per set of beard lengths. See the sample output for capitalization and punctuation.
 
 
 Sample Input
 3
 40 62 77
 88 62 77
 91 33 18
 Sample Output
 Gnomes:
 Ordered
 Unordered
 Ordered
*/