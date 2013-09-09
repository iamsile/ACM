#include <iostream>
using namespace::std;

int main()
{
    char a[1001];
    while(scanf("%s",a)!=EOF)
    {
        string s=a;
        if(next_permutation(a, a+strlen(a)))
           cout << s << " -> " << a << '\n';
        else 
           cout << s << " -> no successor\n";
    }
}
/*
Problem description
Consider all strings that can be obtained by permuting the characters of a given string. For example, the permutations of the string cab listed alphabetically are

abc, acb, bac, bca, cab, cba.

In general, there are n! permutations of a string of length n. In this problem, you are given a string x over the 36-character alphabet {0, 1, 2, . . . , 9, a, b, c, . . . , z}, and must find the permutation of x that immediately follows x in the alphabetical list of permutations of x. For example, the successor permutation of cab is cba, and there is no successor permutation of cba.


Input
Each line of input contains a nonempty string x over the 36-character alphabet{0, 1, 2, . . . , 9, a, b, c, . . . , z}.

Output
For each input string x, find the permutation of x that immediately follows x in the alphabetical list of permutations of x. Output x and its successor permutation separated by ’ -> ’, as shown in the output sample. If there is no successor permutation of x, output ’no successor’ instead.

Sample Input
12
03snd3fk5ee2
gfedcba987
036420
Sample Output
12 -> 21
03snd3fk5ee2 -> 03snd3fke25e
gfedcba987 -> no successor
036420 -> 040236
*/