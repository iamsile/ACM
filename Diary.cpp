#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--) {
        char a[1100];
        gets(a);
        int i,x,flag,lab,maxn=-1,k=strlen(a),b[30]={0};
        for(i=0;i<k;i++)
            b[a[i]-'A']++;
        for(i=0;i<26;i++)
            if(b[i]>maxn) {
                maxn=b[i];
                flag=i;
            }
        for(i=0,lab=1;i<26;i++)
            if(b[i]==maxn&&i!=flag) {
                lab=0;
                printf("NOT POSSIBLE\n");
                break;
            }
        if(!lab)
            continue;
        x=(flag+22)%26;
        printf("%d ",x);
        for(i=0;i<k;i++) {
            if(a[i]==' ')
                printf(" ");
            else printf("%c",(a[i]-'A'-x+26)%26+'A');
        }
        printf("\n");
    }
    return 0;
}
/*
 Problem description
 Nowadays, people who want to communicate in a secure way use asymmetric encryption algorithms such as RSA. However, my older brother uses another, simpler encryption method for his diary entries. He uses a substitution cipher where each letter in the plaintext is substituted by another letter from the alphabet. The distance between the plaintext letter and the encrypted letter is fixed. If we would define this fixed distance d to 5, A would be replaced by F, B by G, C by H, ..., Y by D, Z by E.
 With a fixed and known distance d the decryption would be somewhat simple. But my brother uses random distances for each of his diary entries. To decrypt his diary I have to guess the distance d for each entry. Thus, I use the well known phenomenon that the letter E is used more often in English words than other letters. Can you write a program for me that calculates the distance d based on the fact that the most used letter in the encrypted text corresponds to the letter E in plaintext? Of course, I am interested in the decrypted text, too.
 
 
 
 Input
 The input consists of several test cases c that follow (1 ≤ c ≤ 100). Each test case is given in exactly one line containing one diary entry. Diary entries only use upper case letters (A-Z) and spaces. Each diary entry consists of at most 1000 encrypted letters (including spaces).
 
 Output
 For each test case, print one line containing the smallest possible distance d (0 ≤ d ≤ 25) and the decrypted text. If the decryption is not possible because there are multiple distances conforming to the rules above, print NOT POSSIBLE instead. Spaces are not encrypted.
 
 Sample Input
 4
 RD TQIJW GWTYMJWX INFWD JSYWNJX ZXJ F XNRUQJ JSHWDUYNTS YJHMSNVZJ
 THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
 XVIDRE TFCCVXZRKV GIFXIRDDZEX TFEKVJK UVTIPGKZFE
 XVIDRE TFCCVXZRKV GIFXIRDDZEX TFEKVJK
 Sample Output
 5 MY OLDER BROTHERS DIARY ENTRIES USE A SIMPLE ENCRYPTION TECHNIQUE
 10 JXU GKYSA RHEMD VEN ZKCFI ELUH JXU BQPO TEW
 17 GERMAN COLLEGIATE PROGRAMMING CONTEST DECRYPTION
 NOT POSSIBLE
*/