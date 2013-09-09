#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char ch[205];	
	cin >> ch;
	sort(ch, ch+strlen(ch));
	char *first=ch;
	char *last=ch+strlen(ch);
	do {
		cout << ch << endl;
	}while(next_permutation(first, last));
	return 0;
}
/*
 Description
 
 The stores manager has sorted all kinds of goods in an alphabetical order of their labels. All the kinds having labels starting with the same letter are stored in the same warehouse (i.e. in the same building) labelled with this letter. During the day the stores manager receives and books the orders of goods which are to be delivered from the store. Each order requires only one kind of goods. The stores manager processes the requests in the order of their booking. 
 
 You know in advance all the orders which will have to be processed by the stores manager today, but you do not know their booking order. Compute all possible ways of the visits of warehouses for the stores manager to settle all the demands piece after piece during the day. 
 Input
 
 Input contains a single line with all labels of the requested goods (in random order). Each kind of goods is represented by the starting letter of its label. Only small letters of the English alphabet are used. The number of orders doesn't exceed 200. 
 Output
 
 Output will contain all possible orderings in which the stores manager may visit his warehouses. Every warehouse is represented by a single small letter of the English alphabet -- the starting letter of the label of the goods. Each ordering of warehouses is written in the output file only once on a separate line and all the lines containing orderings have to be sorted in an alphabetical order (see the example). No output will exceed 2 megabytes. 
 Sample Input
 
 bbjd
 Sample Output
 
 bbdj
 bbjd
 bdbj
 bdjb
 bjbd
 bjdb
 dbbj
 dbjb
 djbb
 jbbd
 jbdb
 jdbb
*/