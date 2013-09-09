#include <iostream>
#include <string.h>
#include <map>
using namespace std;

void print(map<string, int> str,string s,int len)
{
    int num=str[s],cnt=0,t;
    while (num) {
        num/=10;
        cnt++;
    }
    char c[85];
    strcpy(c, s.c_str());
    t=len-(s.size()+cnt);
    if (t<0) {
        c[s.size()+t]='\0';
        printf("%s%d\n",c,str[s]);
    }
    else printf("%s%d\n",c,str[s]);
}

int main()
{
    int n,len,lab=1;
    while (~scanf("%d%d",&n,&len)) {
        if (!n&&!len)
            break;
        getchar();
        char a[85];
        int i,j,k,cnt=1;
        map<string, int> str;
        printf("Case %d\n",lab++);
        for (i=0; i<n; i++) {
            gets(a);
            string s="";
            s+=tolower(a[0]);
            k=strlen(a);
            for (j=k-1; j>=0; j--)
                if (a[j]==' ')
                    break;
            for (j++,cnt=1; j<k&&cnt<len; j++)
                if (isalpha(a[j])) {
                    s+=tolower(a[j]);
                    cnt++;
                }
            if (!str[s]) {
                str[s]++;
                printf("%s\n",s.c_str());
            }
            else {
                print(str,s,len);
                str[s]++;
            }
        }
    }
    return 0;
}
/*
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int MAX=205;

string cal(char s[],int l)
{
    int i,cnt=1,pos=-1,k=strlen(s);
    for (i=k-1; i>=0; i--)
        if (s[i]==' ') {
            pos=i+1;
            break;
        }
    string ans="";
    ans+=s[0];
    for (i=pos; i<k; i++) {
        if (isalpha(s[i])) {
            ans+=s[i];
            cnt++;
        }
        if (cnt==l)
            break;
    }
    return ans;
}

void print(map<string, int> str,string temp, int len)
{
    int num=str[temp],cnt=0,t;
    while (num) {
        num/=10;
        cnt++;
    }
    char c[85];
    strcpy(c, temp.c_str());
    t=len-(temp.size()+cnt);
    if (t<0) {
        c[temp.size()+t]='\0';
        printf("%s%d\n",c,str[temp]);
    }
    else printf("%s%d\n",c,str[temp]);
}

int main()
{
    int i,j,k,n,len,casc=1;
    while (~scanf("%d%d",&n,&len)) {
        if (!n&&!len)
            break;
        char name[85];
        getchar();
        map<string, int > str;
        printf("Case %d\n",casc++);
        for (i=0; i<n; i++) {
            gets(name);
            k=strlen(name);
            for (j=0; j<k; j++)
                name[j]=tolower(name[j]);
            string ss=cal(name,len);
            if (!str[ss]) {
                str[ss]++;
                printf("%s\n",ss.c_str());
            }
            else {
                print(str,ss,len);
                str[ss]++;
            }
        }
    }
    return 0;
}
 */
/*
 Problem description
 A university´s computer system assigns user names according to the following set of rules:
 
 The maximum length of a username is MAXLEN characters. (The value of MAXLEN will be specified in the input for each problem instance.)
 The first character of the user name is the first letter of the person´s first name, converted to lower case. Ignore apostrophes and hyphens here and in Step 3.
 Append as many letters of the person´s last name as possible (converted to lower case, if necessary), without exceeding a total of MAXLEN characters. Starting with the first letter of the last name, append these letters in the order in whch they appear in the last name.
 If a user name assigned on basis of Rules 1 - 3 already exists in the database, break the tie as follows: append serial numbers 1 - 9, in that order, to the username from step 3, if that can be done without exceeding the limit of MAXLEN characters in the username. Otherwise, drop the last letter before appending the serial number.
 If a user name assigned on basis of Rules 1 - 4 already exists in the database, break the tie as follows: append serial numbers 10 - 99, in that order, to the username from step 3, if that can be done without exceeding the limit of MAXLEN characters in the username. Otherwise, drop the last letter or the last two letters (whichever is necessary) before appending the serial number.
 It is assumed that the above rules will avoid ties. 
 
 Input
 The input will contain data for a number of test cases. The first line of each test case will contain two positive integers: the number of names and the value of MAXLEN (5 <= MAXLEN <= 80). This will be followed by the list of names. Each name will consist of at most 80 characters and will begin with the first name, followed by middle names, if any, and will conclude with the last name. A single blank space will separate first, middle, and last names. Any name can contain upper and lower case letters, hyphens, and apostrophes. A last name will contain at least two letters, other names will contain at least one letter (they could be just initials). There will be no more than 200 names in each case. The last test case will be followed by a line containing two zeros for the number of names and MAXLEN.
 
 Output
 For each case, the output will begin with a line containing the case number. This will be followed by the list of user names, one per line, in the same order as the corresponding names in the input.
 
 Sample Input
 2 6
 Jenny Ax
 Christos H Papadimitriou
 11 8 
 Jean-Marie d'Arboux
 Jean-Marie A d'Arboux
 Jean-Marie B d'Arboux
 Jean-Marie C d'Arboux
 Jean-Marie D d'Arboux
 Jean-Marie D d'Arboux
 Jean-Marie F d'Arboux
 Jean-Marie G d'Arboux
 Jean-Marie H d'Arboux
 Jean-Marie I d'Arboux
 Jean-Marie J d'Arboux
 11 9 
 Jean-Marie d'Arboux
 Jean-Marie A d'Arboux
 Jean-Marie B d'Arboux
 Jean-Marie C d'Arboux
 Jean-Marie D d'Arboux
 Jean-Marie D d'Arboux
 Jean-Marie F d'Arboux
 Jean-Marie G d'Arboux
 Jean-Marie H d'Arboux
 Jean-Marie I d'Arboux
 Jean-Marie J d'Arboux
 0 0
 Sample Output
 Case 1
 jax
 cpapad
 Case 2
 jdarboux
 jdarbou1
 jdarbou2
 jdarbou3
 jdarbou4
 jdarbou5
 jdarbou6
 jdarbou7
 jdarbou8
 jdarbou9
 jdarbo10
 Case 3
 jdarboux
 jdarboux1
 jdarboux2
 jdarboux3
 jdarboux4
 jdarboux5
 jdarboux6
 jdarboux7
 jdarboux8
 jdarboux9
 jdarbou10
*/