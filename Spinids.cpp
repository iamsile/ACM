#include <iostream>
using namespace std;

int main()
{
    char a[1000];
    while (scanf("%s",a)!=EOF) {
        int i,k=(int)strlen(a),sum=0;
        for (i=0; i<k; i++) {
            if (a[i]==a[k-i-1]&&(a[i]=='l'||a[i]=='o'||a[i]=='x'))
                sum+=3;
            else if (a[i]==a[k-i-1])
                sum+=1;
            else if ((a[i]=='l'&&a[k-i-1]=='l')||(a[i]=='o'&&a[k-i-1]=='o')
                     ||(a[i]=='x'&&a[k-i-1]=='x')||(a[i]=='b'&&a[k-i-1]=='q')
                     ||(a[i]=='q'&&a[k-i-1]=='b')||(a[i]=='d'&&a[k-i-1]=='p')
                     ||(a[i]=='p'&&a[k-i-1]=='d')||(a[i]=='m'&&a[k-i-1]=='w')
                     ||(a[i]=='w'&&a[k-i-1]=='m')||(a[i]=='n'&&a[k-i-1]=='u')
                     ||(a[i]=='u'&&a[k-i-1]=='n'))
                sum+=2;
        }
        cout << a << ' ' << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 Score words according to how similar they look when given a 180-degree spin.
 
 Spinning the shape of lowercase letters 180 degrees can transform them into other characters or into themselves. Such symmetric characters can be used in words, which when spinned, form the same word, such as mow and pod. In a spinids game, words are scored with respect to how symmetric they are when given a 180-degree spin.
 
 The letters that are spin-symmetric with themselves are l, o, and x. The letters that are spin-symmetric with some other letter are b vs. q, d vs. p, m vs. w, and n vs. u.
 
 The score s(c1,c2) of two letters c1 and c2 is 3 if the two letters are the same and spin symmetric, 2 if the letters are different and spin-symmetric, 1 if the letters are the same but not spin-symmetric, and 0 if the letters are not the same and not spin-symmetric.
 
 The score for a n-letter word w is the sum of the scores of the letter pairs:
 
 s(w) = s(w1,wn)+s(w2,wn-1)+...+s(wn,w1).
 
 
 Input
 A list of lowercase alphabetic words, one per line.
 
 
 
 Output
 For every word in the input, the word and spinids-score of each word in the input, separated by a single blank space, one per line.
 
 
 
 Sample Input
 spinids
 xoxox
 deep 
 mow
 pod
 sis
 un
 Sample Output
 spinids 9
 xoxox 15
 deep 6
 mow 7
 pod 7
 sis 3
 un 4
*/