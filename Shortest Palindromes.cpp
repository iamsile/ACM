#include<iostream>
using namespace std;

int isPalindromes(char str[35])
{
    int len=strlen(str);
    int i=0,j=len-1;
    while(i<j)
    {
        if(str[i]!=str[j]) 
			return 0;
        i++;
        j--;
    }
    return 1;
}

char* translate(char str[])
{
    char c;
    int len=strlen(str);
    int i=0,j=len-1;
    while(i<j)
    {
        c=str[i];
        str[i]=str[j];
        str[j]=c;
        i++;
        j--;
    }
    return str;
}

void shortest(char str[])
{
    char tmp[35];
    strcpy(tmp,str);
    strcpy(tmp,translate(tmp));
    int i=0,j=0,k;
    int len=strlen(str);
    while(i<len)
    {
        if(str[i]==tmp[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    for(k=i,i=0;i<k;i++)
        cout<<str[i];
    for(;j<len;j++)
        cout<<tmp[j];
    cout<<endl;
}

int main()
{ 
    char str[35];
    while(gets(str))
    {
        if(isPalindromes(str))
            cout << str<< endl;
        else 
            shortest(str);
    }
    return 0;
}
/*
 Problem description
 A palindrome is a word that is the spelled the same forwards and backwards. ie, bab, and a are both palindromes, while ab is not. Any word that is not already a palindrome can be made into one by attaching the appropriate letters. ab may not be a palindrome, but by attaching an a, we get aba which is a palindrome. Note that we could also attach ba to get abba which is also a palindrome. There are an infinite number of strings you can attach to get a palindrome. In this problem, we're interested in the shortest-length string that gives us the palindrome. 
 
 Input
 Each line of input will have one word on it. The word will have no more than 30 characters. No spaces will appear on the line. The word consists solely of lower case alphabetic characters.
 
 Output
 For each line of input, print out the palindrome that comes from attaching the shortest length string of letters to the given word. Note that if the word is already a palindrome, then nothing should be added. Just print the word out again. 
 
 Sample Input
 palin
 a
 ab
 aba
 Sample Output
 palinilap
 a
 aba
 aba
*/