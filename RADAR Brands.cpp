#include <iostream>
/*翻转数字*/
int cal(int n)
{
	int j;
	for(j=0;n;n/=10)
		j=10*j+(n%10);
	return j;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;n!=cal(n);i++)
		n+=cal(n);
	printf("%d %d\n",i,n);
	return 0;
}
/*This problem presents but one major challenge:
how does one reverse the digits of a number? It's 
pretty easy to write a short routine that extracts 
the digits in order from the right side of the number 
(using the mod operator: 1234%10 = 4) and assembles 
them onto the new number (by multiplying by 10 to 
shift the number left and adding/appending the new digit). 
*/
/*
 
 Problem description
 Farmer John has been branding the cows with a serial number ever since he started the farm. The new cow fad is 'RADAR' brands, so-called because they read the same forwards and backwards (they are palindromic). All the cows want their daughters branded in the new RADAR style.
 
 Each mother wants her daughter's brand to be derived from her own non-RADAR brand by summing the mother's brand and its reverse. Sometimes (e.g., 12 + 21 = 33) this yields a RADAR palindrome right away. Sometimes the process must be repeated several times until a RADAR brand emerges. Consider the brand '87' that requires four steps to convert to a RADAR brand:
 Brand  Reverse   Sum
 Step 1:   87 +    78 =  165
 Step 2:  165 +   561 =  726
 Step 3:  726 +   627 = 1353
 Step 4: 1353 +  3531 = 4884
 Given the mother's brand (a positive integer), determine the number of steps and ultimate RADAR brand that results from applying the procedure above. No answer will be greater than two billion.
 
 
 Input
 Line 1: A single integer, the mother's non-RADAR brand.
 
 
 Output
 Line 1: Two space-separated integers, respectively: the number of steps to find the RADAR brand and the ultimate RADAR brand.
 
 
 Sample Input
 87
 Sample Output
 4 4884
*/