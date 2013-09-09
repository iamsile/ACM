#include <iostream>
using namespace::std;

int main()
{
    char a[100];
    int num=0;
    while(gets(a)!=NULL)
        num++;
    cout << num << '\n';
    return 0;
}
/*
 Problem description
 This problem is strictly to acclimate teams to the contest environment. We strongly suggest you first finish this problem, and then attempt the more complex practice problem. 
 
 Input
 The input file will contain an unknown number of lines with at most 100 characters on each line. All the characters will be printable ASCII characters. Note that the input file will always exist, but may be empty. 
 
 Output
 The number of lines in the input file. 
 
 Sample Input
 one
 and two
 three
 
 Sample Output
 3
*/