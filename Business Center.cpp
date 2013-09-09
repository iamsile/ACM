#include <iostream>
using namespace std;

int main() 
{
	long int n,m,i;
    cin >> n >> m;
    long result=1000000;
    for(i=0;i<m;i++) 
	{
		long u,d;
        cin >> u >> d;
		long k=u*n;
		long m=k%(u+d);
		result=min(result, m==0?u+d:m);
    }
    cout << result << '\n';
    return 0;
}
/*
 Problem description
 International Cyber Police Corporation (ICPC) had built a new mega-tall business center to host its headquarters and to lease some space for extra profit. It has so many floors, that it is impractical to have a separate button in each of its m elevator cars for each individual floor. Instead, each elevator car has just two buttons. One button in i-th elevator car makes it move up ui floors, the other makes it move down di floors. The business center is so high, that we can ignore its height for this problem (you will never reach the top floor), but you cannot go below the ground floor. All floors are numbered by integer numbers starting from zero, zero being the ground floor.
 You start on the ground floor of the business center. You have to choose one elevator car out of m to ride on. You cannot switch elevators cars after that. What is the lowest floor above the ground floor you can get to after you press elevator car buttons exactly n times? 
 
 Input
 The first line of the input file contains two integer numbers n and m (1 ≤ n ≤ 1 000 000, 1 ≤ m ≤ 2 000)| the number of button presses and the number of elevator cars to choose from. The following m lines describe elevator cars. Each line contains two integer numbers ui and di (1 ≤ ui, di ≤ 1 000). 
 
 Output
 Write to the output file a single positive integer number ---the number of the lowest floor above ground floor that can be reached by one of m elevators after pressing its buttons exactly n times.
 
 
 Sample Input
 10 3
 15 12
 15 4
 7 12
 Sample Output
 13
*/