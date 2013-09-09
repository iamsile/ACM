/*#include <iostream>
using namespace::std;

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n))
	{
		if(m%(n-1)==0)
			printf("%d\n",m*n/(n-1)-1);
		else
			printf("%d\n",n*(m/(n-1))+m%(n-1));
	}
	return 0;			
}*/
//m%(n-1)==0->n*(m/(n-1)-1)+n-1
//m%(n-1)!=0->n*(m/(n-1))+m%(n-1)
#include<iostream>
using namespace::std;
int main()
{
	int n,k,sum;
	while(cin >> n >> k)
	{
		sum=n;
		while(n>=k)
		{
			sum+=n/k;
			n=n/k+n%k;
		}
		cout << sum << '\n';
	}
	return 0;
}

/*
 Problem description
 Peter has n cigarettes. He smokes them one by one keeping all the butts. Out of k > 1 butts he can roll a new igarette. 
 How many cigarettes can Peter have? 
 
 Input
 Input is a sequence of lines. Each line contains two integer numbers giving the values of n and k. 
 
 Output
 For each line of input, output one integer number on a separate line giving the maximum number of cigarettes that Peter can have.
 
 Sample Input
 4 3
 10 3
 100 5
 Sample Output
 5
 14
 124
*/