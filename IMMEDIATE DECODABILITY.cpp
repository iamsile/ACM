#include <iostream>
#include <string.h>
using namespace std;

bool cal(char c[],char d[])
{
    int i;
    char e[1001];
    memset(e, 0, sizeof(e));
    if (strlen(c)>strlen(d)) {
        for (i=0; i<strlen(d); i++)
            e[i]=c[i];
        if (strcmp(d, e)==0)
            return true;
    }
    else {
        for (i=0; i<strlen(c); i++)
            e[i]=d[i];
        if (strcmp(c, e)==0)
            return true;
    }
    return false;
}

int main()
{
    char a[1001],b[100][100];
    int i=0,lab=1;
    while (cin >> a) {
        if (a[0]=='9') {
            int j,h=i,flag=1;
            for (i=1; i<h; i++)
                for (j=0; j<i; j++)
                    if (cal(b[i], b[j])) {
                        flag=0;
                        break;
                    }
            if (flag)
                cout << "Set " << lab++ << " is immediately decodable\n";
            else cout << "Set " << lab++ << " is not immediately decodable\n";
            i=0;
            memset(b, 0, sizeof(b));
        }
        else {
            memcpy(b[i++], a, strlen(a));
        }
    }
    return 0;
}
/*
 Problem description
 An encoding of a set of symbols is said to be immediately decodable if no code for one symbol is the prefix of a code for another symbol. We will assume for this problem that all codes are in binary, that no two codes within a set of codes are the same, that each code has at least one bit and no more than ten bits, and that each set has at least two codes and no more than eight. 
 
 Examples: Assume an alphabet that has symbols {A, B, C, D} 
 
 The following code is immediately decodable: 
 A:01 B:10 C:0010 D:0000 
 
 but this one is not: 
 A:01 B:10 C:010 D:0000 (Note that A is a prefix of C) 
 
 
 Input
 Write a program that accepts as input a series of groups of records from standard input. Each record in a group contains a collection of zeroes and ones representing a binary code for a different symbol. Each group is followed by a single separator record containing a single 9; the separator records are not part of the group. Each group is independent of other groups; the codes in one group are not related to codes in any other group (that is, each group is to be processed independently). 
 
 Output
 For each group, your program should determine whether the codes in that group are immediately decodable, and should print a single output line giving the group number and stating whether the group is, or is not, immediately decodable.
 
 Sample Input
 01
 10
 0010
 0000
 9
 01
 10
 010
 0000
 9
 
 Sample Output
 Set 1 is immediately decodable
 Set 2 is not immediately decodable
*/