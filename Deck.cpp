#include <iostream>
#include <iomanip>
using namespace::std;

int main()
{
	long int n,i,k;
	double j,sum;
	cout << " Cards  Overhang\n";
	while(cin >>n&&n)
	{
		sum=0;
		k=0;
		for(i=1;i<=n;i++)
		{
			j=1;
			k+=2;
			j/=k;
			sum+=j;
		}
		cout << setw(5) << n;
		cout << setw(5) << " ";
		printf("%.3f\n",sum);
	}
	return 0;
}
/*
 Problem description
 
 A single playing card can be placed on a table, carefully, so that the short edges of the card are parallel to the table's edge, and half the length of the card hangs over the edge of the table. If the card hung any further out, with its center of gravity off the table, it would fall off the table and flutter to the floor. The same reasoning applies if the card were placed on another card, rather than on a table.
 Two playing cards can be arranged, carefully, with short edges parallel to table edges, to extend 3/4 of a card length beyond the edge of the table. The top card hangs half a card length past the edge of the bottom card. The bottom card hangs with only 1/4 of its length past the table's edge. The center of gravity of the two cards combined lies just over the edge of the table.
 
 Three playing cards can be arranged, with short edges parallel to table edges, and each card touching at most one other card, to extend 11/12 of a card length beyond the edge of the table. The top two cards extend 3/4 of a card length beyond the edge of the bottom card, and the bottom card extends only 1/6 over the table's edge; the center of gravity of the three cards lines over the edges of the table.
 
 If you keep stacking cards so that the edges are aligned and every card has at most one card above it and one below it, how far out can 4 cards extend over the table's edge? Or 52 cards? Or 1000 cards? Or 99999? 
 
 Input
 
 The input file contains several nonnegative integers, one to a line. No integer exceeds 99999.
 
 Output
 
 The standard output will contain, on successful completion of the program, a heading: " Cards Overhang" (that's two spaces between the words) and, following, a line for each input integer giving the length of the longest overhang achievable with the given number of cards, measured in cardlengths, and rounded to the nearest thousandth. The length must be expressed with at least one digit before the decimal point and exactly three digits after it. The number of cards is right-justified in column 5, and the decimal points for the lengths lie in column 12. 
 
 Sample Input
 1
 2
 3
 4
 30
 Sample Output
  Cards  Overhang
     1     0.500
     2     0.750
     3     0.917
     4     1.042
	30     1.997
*/