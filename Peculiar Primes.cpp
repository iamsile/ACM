#include <iostream>
using namespace::std;

int *b=new int[300000],cnt;
int primes[16],n;

int compint(const void* a, const void* b)
{
	return *((const int*)a) - *((const int*)b);
}

void solve(int min,int mult,int first,int last) 
{
	int i;
	if(first==1)
		b[cnt++]=mult;
	for(i=min;i<n;++i) 
	{
		int p=primes[i];
		if(last>=p) 
			solve(i, mult*p, (first-1)/p+1, last/p);
	}
}

int main(void) 
{
	int i, beg, end;
	while (cin >> n&&n) 
	{
		for(i=0;i<n;++i) 
			scanf("%d", primes+i);
		scanf("%d%d", &beg, &end);
		cnt=0;
		solve(0,1,beg,end);
		qsort(b, cnt, sizeof(b[0]), compint);
		for(i=0;i<cnt;++i) 
		{
			if (i>0) 
				cout << ',';
			printf("%d", b[i]);
		}
		if(cnt==0) 
			printf("none");
		printf("\n");
	}
	return 0;
}
/*
 Problem description
 The level of corruption in some countries is really high. It is hard to imagine that these unethical manners have already hit the academic field. Some rumors are spreading that some students tried to bribe their lecturers to get better grades. Would you believe it?
 
 But the real situation may be even much worse. ACM has a very strong suspicion that somebody has bribed mathematicians in the Academy of Sciences in order to forge some of their results. In particular, it is suspected that a very influential person wants to prefer some prime numbers over others.
 
 It is said that many mathematicians have already completely stopped using some primes and
 they create only those numbers that can be “assembled” without those primes. Your task is to verify this hypothesis.
 
 Given a set of prime numbers, your program should output all integer numbers that can be
 created solely by multiplying these primes, without using any other primes.	
 
 Input
 The input will consist of several test scenarios. Each scenario starts by a line with a single positive integer N (1≤N≤10) — the number of primes in the set.
 
 On the second line of a scenario, there are N integer numbers 2 ≤ P1 < P2 < P3 < . . . < PN < 10000, separated by a space. You are guaranteed that all these numbers are prime.
 
 On the third line of each scenario, there are 2 integers X and Y (1 ≤ X ≤Y <231), separated by a space.
 
 The last scenario is followed by a line containing single zero.	
 
 Output
 Your task is to print all positive integer numbers in the closed interval [X, Y ] that have no other prime factors than those given in the input (Pi). Print all such numbers in the increasing order, with no duplicates and separated by a single comma character (“,”). If there are no such numbers, print the word “none” instead.
 
 Note that the number 1 does not need any primes to be constructed and is therefore always
 allowed.	
 
 Sample Input
 1
 3
 1 12
 2
 2 3
 10 20
 3
 2 3 5
 20 30
 1
 17
 20 30
 0 
 Sample Output
 1,3,9
 12,16,18
 20,24,25,27,30
 none
 */
