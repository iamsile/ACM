#include <iostream>
#include <map>
using namespace std;

int main()
{
    long n,m;
    while (cin >> n >> m) {
        if (n==0&&m==0)
            return 0;
        int i;
        string s;
        map<string, int> word;
        for (i=0; i<n; i++) {
            cin >> s;
            ++word[s];
        }
        for (i=0; i<m; i++) {
            cin >> s;
            cout << word[s] << '\n';
        }
    }
    return 0;
}
/*
 Problem description
 Tom is a very diligent boy, and he is very good at English. As he want to take part in the entrance exams for postgraduate schools, there are too many words to remember. He want to know how many times the word have appeared in the previous entrance exams for postgraduate schools.
 
 
 Input
 The input contains multiple test case.;
 The first line contains two integers n and m, (n represent the number of words in the previous entrance exams for postgraduate schools, m represent the number of words Tom wants to know, 0 < n ,m ≤ 50000) ;
 The follow n lines contain n words which have appeared in the previous entrance exams for postgraduate schools, one word per line. Every words only contain lower-case letters, the length of every word not more than 10;
 The next m lines contain m words Tom want to know , one word per line. Every words only contain lower-case letters, the length of every word not more than 10;
 The end of test case with EOF;
 
 
 Output
 The output contains m integers ,one per line, how many times the words have appeared in the previous entrance exams for postgraduate schools Tom wants to know.
 
 
 Sample Input
 4 3
 rescue
 word
 exam
 word
 word
 exam
 put
 Sample Output
 2
 1
 0
*/