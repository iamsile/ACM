#include <iostream>
using namespace::std;

int main()
{
	unsigned int n,k;
	while(cin >> n >> k&&n&&k)
	{
		unsigned int i,m=0,a[1001]={0};
		for(i=0;i<n;i++)
			cin >> a[i];
		k-=1;
		for(i=0;i<n;i++)
		{
			if(i>0)
				cout << ' ';
			m=k/a[i];
			k%=a[i];
			cout << m;
		}
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 Imperative programming languages allow the use of both linear and multi-dimensional arrays. E.g. in Pascal for an array named X the expression array [0..2, 0..1, 0..3] declares a three-dimensional array having the following boundaries for each dimension: 0..2, 0..1, 0..3. (We consider only zero-based arrays here though other values are possible in Pascal for lower bounds of each dimension.)
 
 It is always possible to determine the order in which the items of the array are enumer-ated. Consider that this order is determined by the principle "right-hand indices change faster". This means that the last (rightmost) index iterates through all possible values, then the index that is next to it (second from the right) changes its value by 1, and the last index iterates between the lower and upper boundaries again, and so on.
 
 Example. The items of the array mentioned above are enumerated in the following order: X[0,0,0], X[0,0,1], X[0,0,2], X[0,0,3], X[0,1,0], X[0,1,1], X[0,1,2], X[0,1,3], X[1,0,0], X[1,0,1], X[1,0,2], X[1,0,3], X[1,1,0], X[1,1,1], X[1,1,2], X[1,1,3], X[2,0,0], X[2,0,1], X[2,0,2], X[2,0,3], X[2,1,0], X[2,1,1], X[2,1,2], X[2,1,3].
 
 Let an n -ary array X is declared as array[0..k 1 , 0..k 2 , ..., 0..k n ] . The theory says that the order P of any item X[i1 , i2 , …, in ] is calculated as P(i1 , i2 , …, in ) = 1 + D1 *i1 +D2 *i2 +… Dn *in , if we use the enumeration described above. Here D1 , D2 , ..., Dn are so-called index multipliers .
 
 Example . For the array in discussion the index multipliers are D1 =8, D2 =4, D3 =1. Then, for example, the order of X[1,0,3] will be P(1,0,3) = 1+8*1+4*0+1*3 = 12 .
 
 Your task is to calculate the unknown upper boundaries (k1 , k2 , …, kn ) for given index multipliers D1 , D2 , ..., Dn and total number of items s in the array. 
 
 Input
 The first line of the input contains n ?C the number of dimensions (1 <= n <= 20) and s - the total number of items in the array (1 <= s < MaxLongInt =231 -1). The following n lines contain the index multipliers D1 , D2 , ..., Dn . 
 
 Output
 Determine the upper boundaries for each dimension of the array in order: k1 , k2 , ..., kn (0 < k i <= 1000). The numbers in the output may be delimited with spaces and/or CR/LF characters. 
 
 Sample Input
 3 24
 8
 4
 1
 Sample Output
 2 1 3
*/