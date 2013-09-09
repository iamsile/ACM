#include<iostream> 
#include<string.h> 
#include<ctype.h> 

int main() 
{ 
    char str1[1001]={NULL}; 
    char str2[1001]={NULL};; 
    int i,j; 
    while(gets(str1)) 
    { 
        if(str1[0]=='\0') 
            return 0; 
        for(i=0,j=0;str1[i]!='\0';i++) 
            if(isalpha(str1[i])) 
                str1[j++] = str1[i]; 
        str1[j]='\0'; 
        memcpy(str2,str1,strlen(str1)+1); 
        strrev(str1); 
        if(!strcmp(str1,str2)) 
            printf("YES\n"); 
        else 
            printf("NO\n"); 
    } 
    return 0; 
} 
/*#include <iostream>//wa很奇怪的代码
using namespace::std;

int main()
{
    char a[101]={0};
    while(cin.getline(a, 101))
    {
        int i,j=0,k=strlen(a),flag=1;
        char b[101]={0};
        for(i=0;i<k;i++)
            if((a[i]<='z'&&a[i]>='a')||(a[i]<='Z'&&a[i]>='A'))
                b[j++]=a[i];
        for(i=0;i<j/2;i++)
            if(b[i]!=b[j-i-1]&&(char)(b[i]+32)!=b[j-i-1]&&b[i]!=(char)(b[j-i-1]+32)
               &&(char)(b[i]-32)!=b[j-i-1]&&b[i]!=(char)(b[j-i-1]-32))
            {
                cout << "NO\n";
                flag=0;
                break;
            }
        if(flag)
            cout << "YES\n";
    }
    return 0;
}*/
/*
 Problem description
 Bart is trying to come up with funny palindromes, and decides to write a program to check whether a string is a palindrome. The program should read strings on separate lines and determine whether the entire string is a palindrome. The program should only check letters (i.e., a-z, A-Z), and ignore all blanks, numbers, and punctuation.
 
 
 
 
 Input
 The input will consist of a sequence of lines, each of which should be tested separately. Each line will be no greater than 100 characters long. A blank line signals the end of input. 
 
 Output
 After each line, the program should print on a separate line, either YES (if the input was a palindrome) or NO (otherwise).
 
 Sample Input
 radar
 rAd. Ar
 radiar
 able was I ere I saw elba!
 b
 bb
 ab
 aabaa
 aabbaa
 aab2aa
 aabaaa
 This is a palindrome
 radar is a palindrome
 a man, a plan, a canal, panama!
 a bell was eye, ear I saw elbow
 go hang a salami, bub, i’m a lasagna hog!!
 Sample Output
 YES
 YES
 NO
 YES
 YES
 YES
 NO
 YES
 YES
 YES
 NO
 NO
 NO
 YES
 NO
 YES
*/