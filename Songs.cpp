#include <iostream>
#include <algorithm>
using namespace::std;

struct A{
	int k;
	double t;
}num[5001];

int cmp(const void *a,const void *b)
{
	return ((struct A*)a)->t<((struct A*)b)->t?1:-1;
}

int main()
{
	int n,i,lab;
	double c,d;
	while(cin >> n&&n)
	{
		for(i=0;i<n;i++)
		{
			cin >> num[i].k >> c >> d;
			num[i].t=d/c;
		}
		cin >> lab;
		qsort(num, n, sizeof(num[0]), cmp);
		cout << num[lab-1].k << '\n';
	}
	return 0;
}
//用d/c后算出频率，从大到小排列，然后找出需要查找的值
/*Problem description
 John Doe is a famous DJ and, therefore, has the problem of optimizing the placement of songs on his tapes. For a given tape and for each song on that tape John knows the length of the song and the frequency of playing that song. His problem is to record the songs on the tape in an order that minimizes the expected access time. If the songs are recorded in the order Ss(1), ..., Ss(n) on the tape then the function that must be minimized is
 
 where fs(i) is the frequency of playing the ith song and l is the length of the song. Can you help John?
 
 The program input is from standard input. Each data set in the input stands for a particular set of songs that must be recorded on a tape. A data set starts with the number N (fits a 16 bit integer) of songs. Follow N the song specifications, and in the end, a number representing the position of a song S on the optimized tape. A song specification consists of the song identifier (fits an integer), the length of the song (fits a 16 bit integer), and the frequency of playing the song (a floating-point number). The program prints the identifier of the song S.
 
 White spaces can occur freely in the input. The input data are correct and terminate with an end of file.
 
 For each set of data the program prints the result to the standard output from the beginning of a line. An input/output sample is given below. There is a single data set that contains 5 song specifications. The first song has the identifier 1, length 10 and playing frequency 45.5 etc. The result for the data set is the identifier of the 3rd song on the optimized tape. It is 2 for the given example.
 
 Sample Input
 5
 1     10    45.5
 2     5     20
 30    20    10
 400   50    35
 15    17    89.9
 3
 Sample Output
 2
*/