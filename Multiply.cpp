#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	while (n--) {
        char a[9]={0},b[9]={0},c[9]={0},tmp[9]={0};
        long x,y,z,m=1;
		cin >> a >> b >> c;
		while (++m<17) {
			x=strtol(a, NULL, m);
			y=strtol(b, NULL, m);
			z=strtol(c, NULL, m);
			if (x * y != z)
				continue;
			if (strcmp(a, itoa(x, tmp, m)))
				continue;
			if (strcmp(b, itoa(y, tmp, m)))
				continue;
			if (strcmp(c, itoa(z, tmp, m)))
				continue;
			break;
		}
		printf("%d\n", m<17?m:0);
	}
	return 0;
}
/*
#include <stdlib.h>
long strtol( const char *start, char **end, int base );
功能：函数返回带符号的字符串start所表示的长整型数。参数base代表采用的进制方式。指针end 指向start所表示
的整型数之后的部分。如果返回值无法用长整型表示，函数则返回LONG_MAX或LONG_MIN. 错误发生时，返回零。
#include <stdlib.h>
long atol( const char *str );

功能：将字符串转换成长整型数并返回结果。函数会扫描参数str字符串，跳过前面的空格字符，
直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时才结束转换，并将结果返回。例如，
x = atol( "1024.0001" );
x的值为1024L.

#include <stdlib.h>
double atof( const char *str );
功能:将字符串str转换成一个双精度数值并返回结果。 参数str 必须以有效数字开头,但是允许以“E”或“e”除外的任意非数字字符结尾。例如：
x = atof( "42.0is_the_answer" );
x的值为42.0.

#include <stdlib.h>
int atoi( const char *str );
功能：将字符串str转换成一个整数并返回结果。参数str 以数字开头，当函数从str 中读到非数字字符则结束转换并将结果返回。例如，
i = atoi( "512.035" );
i 的值为 512.

#include <string.h>
char *strstr( const char *str1, const char *str2 );
功能：函数返回一个指针，它指向字符串str2 首次出现于字符串str1中的位置，如果没有找到，返回NULL。
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_lb(char x[], char y[], char z[]){
    char *p;
    int max = 0;
    p = x;
    while (*p){
        if (*p > max){
            max = *p;
        }
        ++p;
    }
    p = y;
    while (*p){
        if (*p > max){
            max = *p;
        }
        ++p;
    }
    p = z;
    while (*p){
        if (*p > max){
            max = *p;
        }
        ++p;
    }
    return max-'0'+1;
}
int f(char x[], int m){
    int i, r, l;
    r = 0;
    l = 1;
    for (i=strlen(x)-1; i>=0; --i){
        r += (x[i]-'0')*l;
        l *= m;
    }
    return r;
}
int main(){
    char x[33], y[33], z[33];
    int w, a, b, c;
    int i, t;
    scanf("%d", &w);
    while (w-- != 0){
        scanf("%s %s %s", x, y, z);
        t = atoi(z)+1;
        for (i=get_lb(x, y, z); i<=t; ++i){
            a = f(x, i);
            b = f(y, i);
            c = f(z, i);
            if (c%a==0 && c/a==b){
                break;
            }
        }
        printf("%d\n", i<=t ? i : 0);
    }
    return 0;
}*/
/*
 Problem description
 6*9 = 42" is not true for base 10, but is true for base 13. That is, 6(13) * 9(13) = 42(13) because 42(13) = 4 * 131 + 2 * 130 = 54(10). 
 
 You are to write a program which inputs three integers p, q, and r and determines the base B (2<=B<=16) for which p * q = r. If there are many candidates for B, output the smallest one. For example, let p = 11, q = 11, and r = 121. Then we have 11(3) * 11(3) = 121(3) because 11(3) = 1 * 31 + 1 * 30 = 4(10) and 121(3) = 1 * 32 + 2 * 31 + 1 * 30 = 16(10). For another base such as 10, we also have 11(10) * 11(10) = 121(10). In this case, your program should output 3 which is the smallest base. If there is no candidate for B, output 0. 
 
 
 Input
 The input consists of T test cases. The number of test cases (T ) is given in the first line of the input file. Each test case consists of three integers p, q, and r in a line. All digits of p, q, and r are numeric digits and 1<=p,q, r<=1,000,000.
 
 Output
 Print exactly one line for each test case. The line should contain one integer which is the smallest base for which p * q = r. If there is no such base, your program should output 0.
 
 Sample Input
 3
 6 9 42
 11 11 121
 2 2 2
 Sample Output
 13
 3
 0
*/