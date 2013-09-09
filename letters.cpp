#include <iostream>
using namespace std;

int main()
{
    char a[1001];
    while (~scanf("%s",a)&&a[0]!='#') {
        int i,n,k=strlen(a),flag,b[26]={0};
        bool c[26]={0};
        for (i=0,flag=1; i<k; i++) {
            if (a[i]>='a'&&a[i]<='z')
                n=a[i]-'a';
            else n=a[i]-'A';
            if (b[n]==0)
                b[n]=1;
            else if (b[n]) {
                if (b[n]==1&&flag==1)
                    b[n]=2,flag=2;
                if (b[n]==1&&flag==2)
                    b[n]=3,flag=3;
                if (b[n]==1&&flag==3)
                    b[n]=4,flag=4;
                if (b[n]==1&&flag==4)
                    b[n]=5,flag=5;
                if (b[n]==1&&flag==5)
                    b[n]=6,flag=6;
            }
        }
        for (i=0; i<k; i++) {
            if (a[i]>='a'&&a[i]<='z')
                n=a[i]-'a';
            else n=a[i]-'A';
            if (!c[n]) {
                cout << a[i];
                c[n]=1;
            }
            else if (b[n]==2&&c[n])
                cout << '*';
            else if (b[n]==3&&c[n])
                cout << '?';
            else if (b[n]==4&&c[n])
                cout << '/';
            else if (b[n]==5&&c[n])
                cout << '+';
            else if (b[n]==6&&c[n])
                cout << '!';
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem description
 Mr Sythe is teaching an ESOL class about repeated letters in English words. As an exercise,he gets his students to replace all the repeated letters in a word with symbols.
 The symbols used are as follows:
 * is used to replace the first repeated letter (the first letter encountered which has occurred before)
 ? for the second repeated letter
 / for the third repeated letter
 + for the fourth repeated letter
 ! for the fifth repeated letter.
 No word that Mr Sythe uses has more than 5 repeated letters.
 So, for example, the word Reindeer would become Reind**? because e is repeated twice and r is repeated once. The repeated e comes before the repeated r, hence the allocation of * to e and ? to r. Note that the first letter in the word is an upper case R, but this is treated as the same letter as the lower case r. 
 
 Input
 In this problem, you will write a program to help Mr Sythe mark the exercise by giving him a list of correct answers. Input will consist of a list of words, one per line. Each word begins with an upper case letter and contains no more than 10 letters. The last line contains just a # - do not process this line.
 
 Output
 Output will be one word for each line of input each on a separate line. The output word must be the input word with repeated letters replaced as indicated by Mr Sythe's rules.
 
 Sample Input
 Reindeer
 Bubbles
 Occurrence
 #
 Sample Output
 Reind**?
 Bu**les
 Oc*ur?en*/
