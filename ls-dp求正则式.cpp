#include <iostream>
using namespace std;

int main()
{
    char a[101],b[101];
    int n;
    scanf("%s",a);
    scanf("%d",&n);
    while (n--) {
        scanf("%s",b);
        int i,j,k,l1=strlen(a),l2=strlen(b);
        bool d[101][101];
        for (i=l1; i>=0; i--)
            for (j=l2; j>=0; j--) {
                if (i==l1&&j==l2)
                    d[i][j]=1;
                else if (a[i]==b[j])
                    d[i][j]=d[i+1][j+1];
                else if (a[i]=='*') {
                    d[i][j]=0;
                    for (k=j; k<=l2; k++)
                        if (d[i+1][k]) {
                            d[i][j]=1;
                            break;
                        }
                }
                else d[i][j]=0;
            }
        if (d[0][0])
            printf("%s\n",b);
    }
    return 0;
}
/*
#include <cstdio>
#include <cstring>

const int SIZE = 110;

char pat[SIZE], str[SIZE];
bool f[SIZE][SIZE];
bool check() {
    memset( f, 0, sizeof(f) );
    f[0][0] = 1;
    if( pat[1]=='*' ) f[1][0] = 1;
    int lp, ls;
    lp = strlen( pat+1 );
    ls = strlen( str+1 );
    for( int i=1; i<=lp; ++i )
        for( int j=1; j<=ls; ++j ) {
            if( f[i-1][j-1] && pat[i]==str[j] )
                f[i][j] = 1;
            if( pat[i]=='*' && ( f[i][j-1] || f[i-1][j] || f[i-1][j-1] ) )
                f[i][j] = 1;
        }
    return f[lp][ls];
}



int main() {
    while( EOF != scanf( "%s", pat+1 ) ) {
        int n;
        scanf( "%d", &n );
        while( n-- ) {
            scanf( "%s", str+1 );
            if( check() )
                puts( str+1 );
        }
    }
}
*/
/*
 Problem description
 You are implementing an operating system, and now need to write a program to list files in a directory: `ls'. You want the user to be able to list only files that match a given pattern that can include wildcards (*), for example *.c. A wildcard matches zero or more characters of any kind.
 
 
 Input
 The first line contains a string P, containing 1-100 characters 'a'-'z', '*' and '.'. This is the pattern. The second line contains an integer N, 1 <= N <= 100, which is the number of files in the directory. Then follows N lines containing the names of the files in the directory. Each line is a string containing 1{100 characters 'a'-'z' and '.'.
 
 Output
 The output shall consist of the lenames that match the pattern, P, each on its own line, in the same order that they were given as input.
 
 Sample Input
 *.*
 4
 main.c
 a.out
 readme
 yacc
 *a*a*a
 4
 aaa
 aaaaa
 aaaaax
 abababa
 Sample Output
 main.c
 a.out
 aaa
 aaaaa
 abababa
*/