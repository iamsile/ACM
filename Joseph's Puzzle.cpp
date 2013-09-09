#include <iostream>
using namespace::std;

int move(int num[],int M2)
{
    int c=0,p=0;
    while(1){
		if(num[p]!=-1){ 
			c++;
			if(c==M2)
				return p;
		}
		p++;
    }
}


int main()
{
	int num[10000],n,Mright=0,p=0,total=0,M1=0,M2=0;
	int i;
	for(i=0;i<10000;i++)
        num[i]=-2;
	while(cin >> n >> M1&&n&&M1){
		for(i=0;i<n;i++)
			cin >> num[i];
		total=n;
		p=0;
		M2=M1%n;
		while(total>0){
			p=move(num,M2);
			if(total==1){
				cout << p+1;
				break;
			}
			else
				cout << p+1<< " ";
			M1=num[p];
			num[p]=-1;
			total--;
			p++;
			M1=M1%total;
			i=p;
			Mright=0;
			while(num[i]!=-2){
				if(num[i]!=-1)
					Mright++;
				i++;
			}
			if(M1==0&&total==1){
				M2=1;
				continue;
			}
			if(M1==0)
				M2=total-Mright;
			else if(M1>Mright)
				M2=M1-Mright;
			else 
				M2=total+M1-Mright;
		}
		cout << '\n';
		for(i=0;i<10000;i++)
			num[i]=-2;             
	}
	return 0;
}
/*
 Problem description
 Persons, whose number order is from 1 to N, hold a password (the straight integer less than 10000) each person and sit around clockwise.
 At first we choose a positive integer factor as the count off number M and start to number clockwise from number one .As we number to M the person who numbers M leaves the rank and whose password will be the new number M. And then start to number again from the person who is sit clockwise next to the person who has been out off the rank just before then. Continue like this, until all people are out off the rank completely. Please design a program of leaving order. 
 
 Input
 There have some groups data. First line of each group data is two integers N, M (0<N, M<100),the second line is N positive integer, separately express every person’s password.The last line contins 0,0 ,which means the end of input data.
 
 Output
 To each group of data, according to the order which leaves outputs their serial number. Between the numeral separates with a blank space. Each group of data monopolize line of outputs.
 
 Sample Input
 7 20
 3 1 7 2 4 8 4
 4 3
 1 2 3 4
 0 0
 Sample Output
 6 1 4 7 2 3 5
 3 2 1 4
*/