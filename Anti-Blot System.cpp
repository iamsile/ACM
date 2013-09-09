#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    char ch,s[60],a[3][20];
    scanf("%d%c",&t,&ch);
    while (t--) {
        scanf("%c",&ch);
        gets(s);
        sscanf(s, "%s + %s = %s",a[0],a[1],a[2]);
        int j,A,B,C;
        for (j=0; j<3; j++)
            if (strchr(a[j], 'm'))//extern char *strchr(const char *s,char c),查找字符串s中首次出现字符c的位置,返回首次出现c的位置的指针，如果s中不存在c则返回NULL。
                break;
        if (j==0) {
            sscanf(a[1], "%d",&B);
            sscanf(a[2], "%d",&C);
            printf("%d + %d = %d\n",C-B,B,C);
        }
        else if (j==1) {
            sscanf(a[0], "%d",&A);
            sscanf(a[2], "%d",&C);
            printf("%d + %d = %d\n",A,C-A,C);
        }
        else {
            sscanf(a[0], "%d",&A);
            sscanf(a[1], "%d",&B);
            printf("%d + %d = %d\n",A,B,A+B);
        }
    }
    return 0;
}
/*
 Problem description
 Jimmy is a hard-working pupil in his second year at primary school. Recently he decided to convert all his notes into an electronic version. Sadly, he found that his math notes were full of ink blots.
 
 He scanned the notes and sent them through his own OCR package (yes, he coded it all by himself at the age of 8). The OCR package replaced all ink blots by the string "machula".
 
 You are given Jimmy's notes, processed by the OCR. They contain simple math exercises, which were used to practice addition on positive integers. Your task is to recover the damaged part of the notes.
 
 
 
 Input
 The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.
 
 Each test case consists of exactly one line. The line represents an equation of the form "number + number = number", where each number is a positive integer. One part of the equation will be replaced by the string "machula". The string always covers a contiguous non-empty sequence of digits, possibly even an entire number. You may assume that for each equation in the input there will be exactly one way to fill in the missing digits.
 
 
 
 Output
 For each test case, the output shall contain one line of the form "number + number = number". The line must represent the equation from that test case with all missing digits filled in.
 
 
 
 Sample Input
 3
 
 23 + 47 = machula
 
 3247 + 5machula2 = 3749
 
 machula13 + 75425 = 77038
 
 Sample Output
 23 + 47 = 70
 3247 + 502 = 3749
 1613 + 75425 = 77038
*/