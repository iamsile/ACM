#include <iostream>
using namespace std;

int main()
{
    char a[1000];
    while(cin >> a)
    {
        int i,k=strlen(a),sum=0,max=0,flag=1;
        char lab=a[0];
        for(i=0;i<k;i++)
        {
            if(a[i]==lab)
                sum++;
            else {
                lab=a[i];
                if(sum>max)
                    max=sum;
                sum=1;
                flag=0;
            }
        }
        if(sum>max)
            max=sum;
        if(flag)
            cout << sum << '\n';
        else
            cout << max << '\n';
    }
    return 0;
}
/*
 Problem description
  Alice and Bob are playing the game SanguoSha 1VS1.If Alice take a card or use a card (it may be slash,missed,peach,duel,sabotage or theft and so on) or discard (sometimes he does not need to throw any card) we will write down an uppercase 'A', if Bob does this, of course, we will write down the letter "B'. Tell me the length of the longest operation combo performed by either player.
 
 Input
  There are several test cases, each test case contains only a string composed of uppercase 'A' and 'B'.The input will finish with the end of file. The length of the string is no more than 1000.
 
 Output
  For each the case, output an integer indicate for the length.
 
 Sample Input
 AAABBAAAAA
 AABBBBAA
 AAAAAAAA
 Sample Output
 5
 4
 8
*/