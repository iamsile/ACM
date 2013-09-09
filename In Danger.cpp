#include <iostream>
using namespace std;

int main()
{
	while(1)
	{
		double d;
		cin >> d;
		int n=(int)d;
		if (n==0) 
			break;
		int k=1<<30;
		while(!(n&k))
			k>>=1;
		cout << ((n^k)<<1)+1 << endl;
	}
	return 0;
}
/*#include <iostream>
#include <string.h>
#include <math.h>
using namespace::std;

unsigned int cal(unsigned int n)
{
	unsigned int i=n/2;
	if(n==1)
		return 0;
	else 
		return n&1?((i=cal((n>>1)+1))?(i-1)<<1:n-1):cal(n>>1)<<1;
}

int main() 
{ 
	char a[5]={0}; 
	while(cin >> a)
	{
		unsigned int n;
		if(!strcmp(a, "00e0"))
			break;
		if(a[3]=='0')
			n=(a[0]-'0')*10+(a[1]-'0');
		else 
			n=((a[0]-'0')*10+(a[1]-'0'))*(int)pow(10, a[3]-'0');
		cout << cal(n)+1 << '\n';
	}
	return 0;
}*/
/*
 约瑟夫问题。 
 假设编号从0开始，n是人数，i=n/2。 
 当n为偶数时，第一圈出列后，剩下的人只有以前一半，i个，如果知道i个人时幸运号码为m，则n个人时的幸运号码为2m，那么有递推公式J(n)=J(n/2)*2; 
 当n为奇数时，第一圈出列后，剩下的人为i+1个，如果知道i+1个人时幸运号码为m，则n个人时的幸运号码为2(m-1)，那么有递推公式J(n)=(J(n/2+1)-1)*2; 
 当然最后解出来的J(n)+1才是要求的答案（编号从1开始）。
 int J(int n){ 
 return n&1?((i=J((n>>1)+1))?(i-1)<<1:n-1):J(n>>1)<<1;}
 */
/*
 Problem description
 Flavius Josephus and 40 fellow rebels were trapped by the Romans. His companions preferred suicide to surrender, so they decided to form a circle and to kill every third person and to proceed around the circle until no one was left. Josephus was not excited by the idea of killing himself, so he calculated the position to be the last man standing (and then he did not commit suicide since nobody could watch). 
 
 We will consider a variant of this "game" where every second person leaves. And of course there will be more than 41 persons, for we now have computers. You have to calculate the safe position. Be careful because we might apply your program to calculate the winner of this contest! 
 
 
 Input
 The input contains several test cases. Each specifies a number n, denoting the number of persons participating in the game. To make things more difficult, it always has the format "xyez" with the following semantics: when n is written down in decimal notation, its first digit is x, its second digit is y, and then follow z zeros. Whereas 0<=x,y<=9, the number of zeros is 0<=z<=6. You may assume that n>0. The last test case is followed by the string 00e0. 
 
 Output
 For each test case generate a line containing the position of the person who survives. Assume that the participants have serial numbers from 1 to n and that the counting starts with person 1, i.e., the first person leaving is the one with number 2. For example, if there are 5 persons in the circle, counting proceeds as 2, 4, 1, 5 and person 3 is staying alive.
 
 Sample Input
 05e0
 01e1
 42e0
 66e6
 00e0
 Sample Output
 3
 5
 21
 64891137
*/