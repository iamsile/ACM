#include <iostream>
using namespace::std;

int main()
{
	int n;
	char a[1001];
	cin >> n;
	while (n--) {
		cin >> a;
		int i,sum=0;
		for (i=0; i<strlen(a); i++) {
			switch (a[i]) {
				case 'I':
					if ((a[i+1]=='V')||(a[i+1]=='X')||(a[i+1]=='L')||(a[i+1]=='C')||(a[i+1]=='D')||(a[i+1]=='M')) {
						sum-=1;
					}
					else sum+=1;
					break;
				case 'V':
					if ((a[i+1]=='X')||(a[i+1]=='L')||(a[i+1]=='C')||(a[i+1]=='D')||(a[i+1]=='M')) {
						sum-=5;
					}
					else sum+=5;
					break;
				case 'X':
					if ((a[i+1]=='L')||(a[i+1]=='C')||(a[i+1]=='D')||(a[i+1]=='M')) {
						sum-=10;
					}
					else sum+=10;
					break;
				case 'L':
					if ((a[i+1]=='C')||(a[i+1]=='D')||(a[i+1]=='M')) {
						sum-=50;
					}
					else sum+=50;
					break;
				case 'C':
					if ((a[i+1]=='D')||(a[i+1]=='M')) {
					sum-=100;
					}
					else sum+=100;
					break;
				case 'D':
					if (a[i+1]=='M') {
						sum-=500;
					}
					else sum+=500;
					break;
				case 'M':
					sum+=1000;
				default:
					break;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 The Romans used letters from their Latin alphabet to represent each of the seven numerals in their number system. The list below shows which letters they used and what numeric value each of those letters represents:
 
 I		=	1
 V		=	5
 X		=	10
 L		=	50
 C		=	100
 D		=	500
 M		=	1000
 Using these seven numerals, any desired number can be formed by following the two basic additive and subtractive rules. To form a number using the additive rule the Roman numerals are simply written from left to right in descending order, and the value of each roman numeral is added together. For example, the number MMCLVII has the value 1000 + 1000 + 100 + 50 + 5 + 1 + 1 = 2157. Using the addition rule alone could lead to very long strings of letters, so the subtraction rule was invented as a result. Using this rule, a smaller Roman numeral to the left of a larger one is subtracted from the total. In other words, the number MCMXIV is interpreted as 1000 − 100 + 1000 + 10 − 1 + 5 = 1914.
 
 Over time the Roman number writing system became more standardized and several additional rules were developed. The additional rules used today are:
 
 The I, X, or C Roman numerals may only be repeated up to three times in succession. In other words, the number 4 must be represented as IV and not as IIII.
 The V, L, or D numerals may never be repeated in succession, and the M numeral may be repeated as many times as necessary.
 Only one smaller numeral can be placed to the left of another. For example, the number 18 is represented as XVIII but not as XIIX.
 Only the I, X, or C can be used as subtractive numerals.
 A subtractive I can only be used to the left of a V or X. Likewise a X can only appear to the left of a L or C, and a C can only be used to the left of a D or M. For example, 49 must be written as XLIX and not as IL.
 Your goal is to write a program which converts Roman numbers to base 10 integers. 
 
 
 Input
 The input to this problem will consist of the following:
 
 A line with a single integer "N" (1 ≤ N ≤ 1000), where N indicates how many Roman numbers are to be converted.
 A series of N lines of input with each line containing one Roman number. Each Roman number will be in the range of 1 to 10,000 (inclusive) and will obey all of the rules laid out in the problem's introduction.
 
 
 Output
 For each of the N Roman numbers, print the equivalent base 10 integer, one per line. 
 
 
 Sample Input
 3        
 IX
 MMDCII
 DXII
 Sample Output
 9
 2602
 512
*/