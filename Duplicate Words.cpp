#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct {
    char c[60];
}dic;
dic word[200001];

int cmp(const void *a,const void *b)
{
    return strcmp(((dic *)a)->c, ((dic *)b)->c);
}

int main()
{
    char a[1001],s[1]={'\0'};
    int i,j = 0,k = 0,flag=0;
    while (fgets(a,1001,stdin) != NULL) {
        for (i=0; i<strlen(a); i++) {
            if (isalpha(a[i])) {
                if (isupper(a[i]))
                    word[k].c[j++]=a[i]+32;
                else
                    word[k].c[j++]=a[i];
            }
            else{ 
                k++,j=0;
                word[k++].c[0]='\0';
            }
        }
    }
    qsort(word, k, sizeof(word[0]), cmp);
    for (i=1; i<=k; i++) {
        if ((strcmp(word[i].c, word[i-1].c)==0)&&strcmp(word[i].c, word[i+1].c)
            &&flag==0&&strcmp(word[i].c, s)) {
            cout << word[i].c << '\n';
            flag=1;
        }
        else flag=0;
    }
    return 0;
}
/*
 Problem description
 What background? Seemed like a good idea at the time... 
 
 Input
 Anyway, you're to write a program that reads in a whole bunch of text ,including more than one line. (each word is no more than 20 characters) and spit out the duplicate words. For our purposes, words are to be separated by spaces, commas (,), !, ?, and periods (.). No word goes past the end of a line. There can be an arbitrary amount of duplicate words. All comparisons should ignore case.
 
 Output
 Output the duplicate words, one per line, in lower case and in sorted order. 
 
 Sample Input
 How much wood would a woodchuck chuck if a woodchuck could chuck wood? Well? what do you think? Are you feeling well? 
 Sample Output
 a
 chuck
 well
 wood
 woodchuck
 you
*/