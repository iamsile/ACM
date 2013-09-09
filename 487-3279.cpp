#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
int a[27]={0,2,2,2,3,3,3,4,4,4,5,
5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main()
{
    long n;
    char s[1000];
    map <int,int > tel;
    cin >> n;
    getchar();
    while (n--) {
        gets(s);
        unsigned i,num=0;
        for (i=0; s[i]; i++) {
            if (s[i]>='A'&&s[i]<='Z')
                num=num*10+a[s[i]-64];
            else if (s[i]>='0'&&s[i]<='9')
                num=num*10+s[i]-'0';
        }
        ++tel[num];
        memset(s, 0, sizeof(s));
    }
    for (map<int, int>::const_iterator it = tel.begin(); it != tel.end(); ++ it)
        if (it->second > 1)
            printf("%03d-%04d %d\n", it->first/10000, it->first%10000, it->second);
    return 0;
}/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef struct node{
    char str[8];
}NODE;
NODE p[1000002];
int myCmp(const NODE *a, const NODE *b){
    return strcmp(a->str,b->str);
}
void putOut(char *str,int n){
    int i;
    for(i=0; i < 7; i++){
        if(i==3)
            putchar('-');
        putchar(str[i]);
    }
    printf(" %d\n",n);
}
int main(){
    char c;
    unsigned int i,j,t,n,flag;
    scanf("%d",&n);
    getchar();
    for(i=0; i < n; i++){
        for(t=0; ; ){
            c=getchar();
            if(c == '\n')
                break;
            if(c >= '0' && c <= '9')
                p[i].str[t++] = c;
            else if(c >= 'A' && c <= 'O')
                p[i].str[t++] = (c - 'A')/3+50;
            else if(c >= 'T' && c <= 'Y')
                p[i].str[t++] = (c - 'T')/3+56;
            else if(c=='P' || c=='R' || c=='S')
                p[i].str[t++] = 55;
        }
        p[i].str[t] = '\0';
    }
    qsort(p,n,sizeof(NODE),myCmp);
    strcpy(p[n].str,"sdkfjskd");
    for(flag=t=j=0,i=1; i <= n; i++){
        if(strcmp(p[t].str,p[i].str)){
            if(i-t >= 2){
                putOut(p[t].str,i-t);
                flag = 1;
            }
            t = i;
        }
    }
    if(!flag)
        printf("No duplicates.\n");
    return 0;
}*/
/*
 Problem description
 Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10.
 
 The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows:
 
 
 A, B, and C map to 2
 
 D, E, and F map to 3
 
 G, H, and I map to 4
 
 J, K, and L map to 5
 
 M, N, and O map to 6
 
 P, R, and S map to 7
 
 T, U, and V map to 8
 
 W, X, and Y map to 9
 
 
 There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010.
 
 
 Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.)
 
 
 Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to check that no two (or more) businesses in the directory have the same telephone number. 
 
 
 Input
 The input will consist of one case. The first line of the input specifies the number of telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with each number alone on a line. Each telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will be digits or letters. 
 
 Output
 Generate a line of output for each telephone number that appears more than once in any form. The line should give the telephone number in standard form, followed by a space, followed by the number of times the telephone number appears in the directory. Arrange the output lines by telephone number in ascending lexicographical order. If there are no duplicates in the input print the line:
 No duplicates.
 
 
 Sample Input
 12
 4873279
 ITS-EASY
 888-4567
 3-10-10-10
 888-GLOP
 TUT-GLOP
 967-11-11
 310-GINO
 F101010
 888-1200
 -4-8-7-3-2-7-9-
 487-3279
 
 Sample Output
 310-1010 2
 487-3279 4
 888-4567 3
*/