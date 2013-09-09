#include <iostream>
#include <string.h>
using namespace std;

char a[8][3]={
    'T','T','T',
    'T','T','H',
    'T','H','T',
    'T','H','H',
    'H','T','T',
    'H','T','H',
    'H','H','T',
    'H','H','H',
};
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,n,k,sum[9];
        char s[50];
        cin >> n;
        cin >> s;
        k=strlen(s);
        memset(sum, 0, sizeof(sum));
        for (i=0; i<8; i++)
            for (j=0; j<k-2; j++)
                if (a[i][0]==s[j]&&a[i][1]==s[j+1]&&a[i][2]==s[j+2])
                    sum[i]++;
        cout << n << ' ';
        for (i=0; i<8; i++) {
            if (i>0)
                cout << ' ';
            cout << sum[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem description
 Penney’s game is a simple game typically played by two players. One version of the game calls for each player to choose a unique three-coin sequence such as HEADS TAILS HEADS (HTH). A fair coin is tossed sequentially some number of times until one of the two sequences appears. The player who chose the first sequence to appear wins the game.
 
 For this problem, you will write a program that implements a variation on the Penney Game. You will read a sequence of 40 coin tosses and determine how many times each three-coin sequence appears. Obviously there are eight such three-coin sequences: TTT, TTH, THT, THH, HTT, HTH, HHT and HHH. Sequences may overlap. For example, if all 40 coin tosses are heads, then the sequence HHH appears 38 times.
 
 Input
 The first line of input contains a single integer P, (1 <= P <= 1000), which is the number of data sets that follow. Each data set consists of 2 lines. The first line contains the data set number N. The second line contains the sequence of 40 coin tosses. Each toss is represented as an upper case H or an upper case T, for heads or tails, respectively. There will be no spaces on any input line.
 
 Output
 For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of occurrences of each three-coin sequence, in the order shown above, with a space between each one. There should be a total of 8 space separated decimal integers on each output line.
 
 Sample Input
 4
 1
 HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
 2
 TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
 3
 HHTTTHHTTTHTHHTHHTTHTTTHHHTHTTHTTHTTTHTH
 4
 HTHTHHHTHHHTHTHHHHTTTHTTTTTHHTTTTHTHHHHT
 Sample Output
 1 0 0 0 0 0 0 0 38
 2 38 0 0 0 0 0 0 0
 3 4 7 6 4 7 4 5 1
 4 6 3 4 5 3 6 5 6
*/