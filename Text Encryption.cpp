#include <iostream>
using namespace std;

int main()
{
    int n;
    char cc;
    while (cin >> n&&n) {
        cc=getchar();
        int i,j,k,l=0,m=0;
        char a[1100],b[1100]={0},c[1100]={0};
        gets(a);
        for (i=0,j=0; a[i]; i++) {
            if (a[i]==' ')
                continue;
            b[j++]=a[i];
        }
        for (i=0,k=j; i<j; i++,m+=n) {
            if(k==0)
                break;
            if (m>=j) {
                l=0;
                while (c[l])
                    l++;
                m=l;
                c[m]=b[i];
            }
            else {
                c[m]=b[i];
                k--;
            }
        }
        for (i=0; i<j; i++)
            if (c[i]>='a'&&c[i]<='z')
                cout << (char)(c[i]-32);
            else cout << c[i];
        cout << '\n';
    }
    return 0;
}
/*
 Problem description
 To keep privacy of messages and prevent the aliens from reading them, we may use various encryption algorithms. These algorithms encode a message into the so-called ciphertext that is difficult (or impossible) to decode for anyone else than the intended recipient. Transposition ciphers are a type of encryption that do not change the letters of the message but only change their order (&Prime shuffle&Prime the letters). Of course, the shuffling must be reversible to allow later decryption.
 In this problem, we will consider a simple transposition cipher which shuffles the letters in such a way that the decryption algorithm always takes every n-th letter. More specifically: when decrypting, the first letter of the ciphertext is taken first, then the next n − 1 letters are (repeatedly) skipped and the next letter taken, and so on until we reach the end of the ciphertext. After that, we repeat the procedure starting with the second letter of the ciphertext, and so on until all letters are used.
 Your task is to implement the encryption algorithm for this cipher. For a given message, produce the encrypted text (ciphertext). To make the cipher a little bit stronger, you should convert all letters to uppercase and leave out all spaces between words.
 
 Input
 The input contains several messages. Each message is described by two lines. The first line contains one integer number N (1 <=N <= 1000). The second line contains the message. The message will be at most 10 000 characters long, it will only contain letters and spaces, and there will be at least one letter in each message. The last message is followed by a line containing zero.
 
 Output
 For each message, output the ciphertext that, after using the described decryption algorithm, will result in the original message (with all spaces removed and all letters in uppercase).
 
 Sample Input
 2
 CTU Open Programming Contest
 7
 This is a secret message that noone should ever see Lets encrypt it
 15
 text too short
 0
 Sample Output
 CMTMUIONPGECNOPNRTOEGSRTA
 TESNUECHCAOLERIRGODLYSEENEEPITTEVTTSMHSESIAEAHRETSSTOSN
 TEXTTOOSHORT
*/