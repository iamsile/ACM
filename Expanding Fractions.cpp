#include <iostream>
using namespace std;

int main()
{
    int n,m;
    while (cin >> n >> m) {
        if (!n&&!m)
            break;
        int k,j,i=1,a[1001]={n},lab=0;//a[]存的是余数
        cout << '.';
        while (1) {
            k=a[i-1]*10/m;
            a[i]=a[i-1]*10%m;//如果余数相同了则代表有循环节了
            cout << k;
            if (a[i]==0) {
                lab=2;
                break;
            }
            for (j=0; j<i; j++)
                if (a[j]==a[i]) {
                    lab=1;
                    break;
                }
            if (lab==1||lab==2)
                break;
            if (i==49||((i>50)&&((i+1)%50==0)))
                cout << '\n';
            i++;
        }
        if (lab==1)
            cout << "\nThe last " << i-j << " digits repeat forever.\n";
        else cout << "\nThis expansion terminates.\n";
    }
    return 0;
}
/*
 真分式除式的原理就是用一个数乘以除数,使被除数被足0后与得到的这个积的差小于除数.然后再用这个差补足0再重复上面的步骤.
 判断从那开始循环时,大家是不是会很快地想到用类似字符比较的方法?其实,只要看是不是有和前面得出来的余数相同的余数就可以了!因为余数是会马上被当作被除数来用的,而相同的除数不变,被除数又与前面的相同,自然除得的结果会与前面的重复.太奇妙了~
 if( (i==49)  || ( (i > 51) && ((i+1)%50==0)   )     )printf("/n");   /*关键是这句！可以看出，第一行只有49个数字（因为包括了“.”），而第二行以后就要有50个*/

/*
 Problem description
 n this problem you are to print the decimal expansion of a quotient of two integers. As you well know, the decimal expansions of many integer quotients result in decimal expansions with repeating sequences of digits. You must identify these. You will print the decimal expansion of the integer quotient given, stopping just as the expansion terminates or just as the repeating pattern is to repeat itself for the first time. If there is a repeating pattern, you will say how many of the digits are in the repeating pattern.
 
 Input
 There will be multiple input instances, each instance consists of two positive integers on a line. The first integer represents the numerator of the fraction and the second represents the denominator. In this problem, the numerator will always be less than the denominator and the denominator will be less than 1000. Input terminates when numerator and denominator are both zero.
 
 Output
 For each input instance, the output should consist of the decimal expansion of the fraction, starting with the decimal point. If the expansion terminates, you should print the complete decimal expansion. If the expansion is infinite, you should print the decimal expansion up to, but not including the digit where the repeated pattern first repeats itself. For instance, 4/11 = .3636363636..., should be printed as .36. (Note that the shortest repeating pattern should be found. In the above example, 3636 and 363636, among others, are repeating patterns, but the shortest repeating pattern is 36.) Since some of these expansions may be quite long, multiple line expansions should each contain exactly 50 characters on each line (except the last line, which, of course, may be shorter) | that includes the beginning decimal point. (Helpful hint: The number of digits before the pattern is repeated will never be more than the value of the denominator.) 
 
 On the line immediately following the last line of the decimal expansion there should be a line saying either "This expansion terminates.", or "The last n digits repeat forever.", where n is the number of digits in the repeating pattern. 
 
 Output for each input instance (including the last input instance) should be followed by a blank line. 
 
 Sample Input
 3 7
 345 800
 112 990
 53 122
 0 0
 Sample Output
 .428571
 The last 6 digits repeat forever.
 .43125
 This expansion terminates.
 .113
 The last 2 digits repeat forever.
 .4344262295081967213114754098360655737704918032786
 885245901639
 The last 60 digits repeat forever.
*/