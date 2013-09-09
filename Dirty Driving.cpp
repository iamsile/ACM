#include <iostream>
using namespace std;

int main()
{
    int n,p;
    while (scanf("%d%d",&n,&p)!=EOF) {
        int i,sum,a[100010];
        for (i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a, a+n);
        for (i=0,sum=0; i<n; i++)
            sum=max(sum, p*(i+1)-a[i]);
        printf("%d\n",sum+a[0]);
    }
    return 0;
}
/*
 Sort the distances to those cars, to easily find the number of cars between you and some other car (by just looking at its index in the sorted array).
 Let S be the sorted array of length n, and find M=max{p(i+1)−Si :i∈[0,n−1]}.
 This is what you should modify your distance to the queue with, so after this modification your (correct) distance to the next car is M +S[0]
 
 Problem description
 Like all other good drivers, you like to curse, swear and honk your horn at your fellow automobile drivers. Today you're at the rear of a long line, brooding over the others' inability to keep proper distance to the car in front. But are you really keeping your own distance? You have calculated that in order to never have to use your breaks, you must keep a distance to any car x in front of you at least p(n + 1) where n is the number of cars between you and x, and p is an integer constant determined by which of your cars you are currently driving.
 Given the value of p and the current distances (in random order) to each of the cars ahead of you, calculate the minimum distance you should be keeping to the car directly in front, in order to not have to use your breaks. 
 
 
 Input
 There are several test cases.
 For each test case, the first line with 1 ≤ n ≤ 100000 - the number of cars ahead of you -and 1 ≤ p ≤ 20 - the deceleration constant.
 A single line with n unique integers denoting the current distance to each of the cars ahead of you. Each of these integers are in the interval [1; 107]
 
 
 Output
 For each test case, output the minimum distance you must keep to the car directly in front, in order to not have to use your breaks.
 
 
 Sample Input
 3 1
 1 2 4
 6 3
 2 3 4 5 6 1
 Sample Output
 1
 13
*/