#include <iostream>
#include <string.h>
using namespace std;

bool judge(char s)
{
    if (s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        return true;
    else return false;
}

int main()
{
    char a[10001];
    while (scanf("%s",a)!=EOF) {
        int i,k=strlen(a),flag=0,lab=1;
        if (strcmp(a, "end")==0)
            break;
        for (i=0; i<k; i++) {
            if (a[i]=='a'||a[i]=='e'||a[i]=='i'||
                a[i]=='o'||a[i]=='u')
                flag=1;
            if (i>0&&i<k-1&&((judge(a[i])&&judge(a[i-1])&&judge(a[i+1])))) {
                lab=0;
                break;
            }
            else if (a[i]==a[i+1]) {
                if (a[i]=='e'||a[i]=='o')
                    continue;
                else {
                    lab=0;
                    break;
                }
            }
            else if (i>0&&i<k-1&&(!judge(a[i])&&(!judge(a[i-1]))&&(!judge(a[i+1])))) {
                lab=0;
                break;
            }
            else if (i>0&&i<k-1&&(a[i-1]==a[i]&&a[i]==a[i+1])) {
                lab=0;
                break;
            }
            
        }
        if (flag&&lab)
            cout << '<' << a << '>' << " is acceptable.\n";
        else cout << '<' << a << '>' << " is not acceptable.\n";
    }
    return 0;
}
/*
 Problem Description
 Password security is a tricky thing. Users prefer simple passwords that are easy to remember (like buddy), but such passwords are often insecure. Some sites use random computer-generated passwords (like xvtpzyo), but users have a hard time remembering them and sometimes leave them written on notes stuck to their computer. One potential solution is to generate "pronounceable" passwords that are relatively secure but still easy to remember.
 
 FnordCom is developing such a password generator. You work in the quality control department, and it's your job to test the generator and make sure that the passwords are acceptable. To be acceptable, a password must satisfy these three rules:
 
 It must contain at least one vowel.
 
 It cannot contain three consecutive vowels or three consecutive consonants.
 
 It cannot contain two consecutive occurrences of the same letter, except for 'ee' or 'oo'.
 
 (For the purposes of this problem, the vowels are 'a', 'e', 'i', 'o', and 'u'; all other letters are consonants.) Note that these rules are not perfect; there are many common/pronounceable words that are not acceptable.
 
 
 Input
 The input consists of one or more potential passwords, one per line, followed by a line containing only the word 'end' that signals the end of the file. Each password is at least one and at most twenty letters long and consists only of lowercase letters.
 
 
 Output
 For each password, output whether or not it is acceptable, using the precise format shown in the example.
 
 
 Sample Input
 a
 tv
 ptoui
 bontres
 zoggax
 wiinq
 eep
 houctuh
 end
 
 
 Sample Output
 <a> is acceptable.
 <tv> is not acceptable.
 <ptoui> is not acceptable.
 <bontres> is not acceptable.
 <zoggax> is not acceptable.
 <wiinq> is not acceptable.
 <eep> is acceptable.
 <houctuh> is acceptable.
*/