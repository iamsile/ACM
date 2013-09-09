#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int i,j,n,m,sum=0,a[1010];
        scanf("%d%d",&n,&m);
        for (i=0; i<m; i++)
            scanf("%d",&a[i]);
        sort(a, a+m);
        j=m/(n+1);
        for (i=m-1; j>0; i--,j--)
            sum+=a[i];
        printf("%d\n",sum);
    }
    return 0;
}
/*
 Problem description
 
 You have successfully led a group of pirates in taking over a commercial vessel. You have seized gold coins, silver coins, and other precious goods. Now it comes down to dividing the loot. It is important to keep everyone satisfied, otherwise you risk mutiny. A pirate is not satisfied if another pirate gets more items than he does. Therefore you might have to content yourself with fewer items than the other pirates or throw some items into open sea. Fortunately, the other pirates have no notion of the value of the items, while you do. Can you make the most out of this without mutiny?
 
 Input
 The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:
 One line with two integers P and N, satisfying 0 ≤ P ≤ 1000, 1 ≤ N ≤ 1000: the number of other pirates you have to share the loot with and the number of items, respectively.
 One line with N integers, vi, satisfying 1 ≤ vi ≤ 1000: the value of each item.
 
 
 Output
 For every test case in the input, the output should contain one integer on a single line: the maximum total value of all the items that you can give yourself, while keeping all other pirates satisfied.
 
 Sample Input
 2
 2 7
 1 1 1 1 3 3 7
 5 9
 2 2 4 4 6 8 11 11 13
 Sample Output
 10
 13
*/