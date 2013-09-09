#include <iostream>
#include <string.h>
using namespace std;

int cal(char ch) 
{
    if (ch >= '0' && ch <= '9') 
        return int(ch - '0');
    if (ch >= 'A' && ch <= 'Z') 
        return int(ch - 'A') + 10;
    return int(ch - 'a') + 36;
}

int main() 
{
    string s;
    while (cin >> s) 
    { 
        int sum = 0;
        if (s == "end") 
            break;
        for (size_t i = 0; i < s.length(); i++)
            sum += cal(s[i]);
        cout << (sum % 61 == 0 ? "yes" : "no") << '\n';
    }
    return 0;
}
/*
 Problem description
 On the planet Zoop, numbers are represented in base 62, using the digits
 0, 1, . . . , 9, A, B, . . . , Z, a, b, . . . , z
 where
 A (base 62) = 10 (base 10)
 B (base 62) = 11 (base 10)
 ...
 z (base 62) = 61 (base 10).
 Given the digit representation of a number x in base 62, your goal is to determine if x is divisible by 61.
 
 
 Input
 The input test file will contain multiple cases. Each test case will be given by a single string containing only the digits ‘0’ through ‘9’, the uppercase letters ‘A’ through ‘Z’, and the lowercase letters ’a’ through ’z’. Allstrings will have a length of between 1 and 10000 characters, inclusive. The end-of-input is denoted by a single line containing the word “end”, which should not be processed.
 
 Output
 For each test case, print “yes” if the number is divisible by 61, and “no” otherwise.
 
 Sample Input
 1v3
 2P6
 IsThisDivisible
 end
 Sample Output
 yes
 no
 no
 Judge Tips
 In the first example, 1v3 = 1 × 622 + 57 × 62 + 3 = 7381, which is divisible by 61.
 In the second example, 2P6 = 2 × 622 + 25 × 62 + 6 = 9244, which is not divisible by 61.
*/