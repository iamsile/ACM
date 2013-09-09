#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        char a[1001];
        scanf("%s",a);
        int i,j,flagl=0,flago=0,minn=999999,k=strlen(a);
        for(i=0;i<k;i++) {
            if(a[i]=='l') {
                if (a[i]=='l'&&a[i+1]=='l')
                    j=1;
                else if(a[i+1]=='o'&&a[i+2]=='l')
                    j=0;
                else if (a[i+1]=='o'&&a[i+2]!='l')
                    j=1;
                else if (a[i+1]!='o'&&a[i+2]=='l')
                    j=1;
                else if (a[i+1]!='o'&&a[i+2]!='l')
                    j=2;
                flagl=1;
            }
            else if (a[i]=='o') {
                if(a[i+1]=='l')
                    j=1;
                else if (a[i+1]!='l')
                    j=2;
                flago=1;
            }
            if(minn>j&&(flagl||flago))
                minn=j;
        }
        if(!flagl&&!flago)
            printf("3\n");
        else {
            printf("%d\n",minn);
        }
    }
    return 0;
}
/*
 Problem description
 Your friend Andreas has a very good sense of humour. In fact, it is so good that he even enjoys to change words so that they will contain the substring lol. For example,during the 2010 FIFA World Cup in soccer he had much fun changing the word fotball to fotbalol. In order to be more ecient in his word plays, he has asked you to make a computer program that nds the minimum number of changes needed in order to transform a string into a new string containing lol as a substring. There are three legal ways to change a string: delete a character, insert a new character and replace an existing character with a new one.
 
 Input
 The first line of the input consists of a single number T, the number of test cases. Then follows T lines, containing a string S consisting of lower case letters between a and z only.
 
 Output
 For each string, output on its own line the minimum number of changes needed in order to obtain a string containing lol as a substring.
 
 Sample Input
 4
 fotball
 sopp
 ingenting
 spillolje
 Sample Output
 1
 2
 3
 0
*/