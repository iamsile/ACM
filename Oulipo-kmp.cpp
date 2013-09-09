#include <iostream>
using namespace std;
char a[10009],b[1000005];
int i,j,k,num=0,next[10009];

void NEXT()
{
    j=0,k=-1;
    next[0]=-1;
    int l=strlen(a);
    while (j<l) {
        if (k==-1||a[j]==a[k]) {
            j++;
            k++;
            if (a[j]!=a[k])
                next[j]=k;
            else
                next[j]=next[k];
        }
        else k=next[k];
    }
}

int kmp()
{
    i=0;
    j=0;
    num=0;
    int l1=strlen(b),l2=strlen(a);
    while (i<l1) {
        if (j==-1) {
            i++;
            j=0;
        }
        else if (b[i]==a[j])
        {
            i++;
            j++;
        }
        else 
            j=next[j];
        if (j>=l2)
        {
            j=next[j];
            num++;
        }
    }
    return num;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%s%s",a,b);
        NEXT();
        printf("%d\n",kmp());
    }
    return 0;
}
/*
 Problem description
 The French author Georges Perec (1938-1982) once wrote a book, La disparition, without the letter ‘e’. He was a member of Oulipo group. A quote from the book:
 Tout avait l’air normal, mais tout s’affirmait faux. Tout avait l’air normal, d’abord, puis surgissait l’inhumain, l’affolant.Ⅱaurait voulu savoir ou s, articulait l’association qui l’unissait au roman: sur son tapis, assailant atout instant son imagination, l’intution d’un tabou, la vision d’un mal obscure, d’sun quoi vacant, d’un non-dit: la vision, l’avision d’un oubli commandant tout,ou s’abolissait la raison: tout avait l’air normal mais …
 Perec would probably have scored high (or rather, low) in the following contest. People are asked to write a perhaps even meaningful text on some subject with as few occurrences of a given ”word” as possible. Our task is to provide the jury with a program that counts these occurrences, in order to obtain a ranking of the competitors. These competitors often write very long texts with nonsense meaning; a sequence of 500,000 consecutive ‘T’s is not unusual. And they never use spaces.
 So we want to quickly find out how often a word, i.e., a given string, occurs in a text. More formally: given the alphabet {‘A’,’B’,’C’, …,’Z’} and two finite strings over that alphabet, a word W and a text T ,count the number of occurrences of W in T. All the consecutive characters of W must exactly match consecutive characters of T. Occurrences may overlap.
 
 
 Input
 The first line of the input file contains a single number: the number of the cases to follow. Each test case has following format:
 One line with the word W, a string over {‘A’,’B’,’C’, …,’Z’}, with 1<=|W|<=10,000(here |W| denotes the length of the string W).
 One line with text T, a string over {‘A’,’B’,’C’, …,’Z’}, with |W|<=|T|<=1,000,000. 
 
 Output
 For every test case in the input file, the output should contain a single number, on a single line: the number of occurrences of the word W in the text T.
 
 Sample Input
 3
 BAPC
 BAPC
 AZA
 AZAZAZA
 VERDI
 AVERDXIVYERDIAN
 Sample Output
 1
 3
 0
*/