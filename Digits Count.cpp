#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> cal(int n)
{
    int m,i,j,t,l,len=log10(n);
    char d[16];
    vector<int> pow10(12,1), c(10,0);
    for(i=1; i<12;i++)
        pow10[i]=pow10[i-1]*10;
    sprintf(d, "%d", n);
    m=n+1;
    for(i=0; i<=len; i++) {
        l=d[i]-'0';
        t=(m-1)/pow10[len-i];
        c[l]+=m-t*pow10[len-i]; 
        t/=10;
        j=0;
        while(j<=l-1) {
            c[j]+=(t+1)*pow10[len-i];
            j++;
        }
        while(j<10) {
            c[j]+=t*pow10[len-i];
            j++;
        }
        c[0]-=pow10[len-i]; 
    }
    return c;
}

int main()
{
    int i,x,y;
    while (cin >> x >> y) {
        if (!x&&!y)
            break;
        vector<int> a,b;
        a=cal(--x);
        b=cal(y);
        for (i=0; i<10; i++)
            b[i]-=a[i];
        for (i=0; i<10; i++) {
            if (i)
                cout << ' ';
            cout << b[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
 仔细考虑m个n位十进制数的特点，在一个n位十进制数的由低到高的第i个数位上，总是连续出现10^i个0，然后是10^i个1……一直到10^i个9，9之后又是连续的10^i个0，这样循环出现。找到这个规律，就可以在常数时间内算出第i个数位上每个数字出现的次数。而在第i个数位上，最前面的10^i个0是前导0，应该把它们减掉。
 这样，可以只分析给定的输入整数n的每个数位，从面可以得到一个log10(n)的算法
 */
/*
 This problem was simple, logic was as follows.
 Not seek from a to b, look of 0 to a and then from 0 to b.
 0 to a = {array A}
 0 to b = {array B}
 
 And subtract that obtained with a.
 arrayResult = arrayB - arrayA
 If we accept leading zeros.
 0   1   2   3   4   5   6   7   8   9
 0 to 9 =     {1   1   1   1   1   1   1   1   1   1}
 00 to 99 =   {20  20  20  20  20  20  20  20  20  20}
 000 to 999 = {300 300 300 300 300 300 300 300 300 300}
 
 Understanding.
 0   1   2   3   4   5   6   7   8   9
 10 to 19 =   {1   1   1   1   1   1   1   1   1   1} (0 to 9)
 + {0   10  0   0   0   0   0   0   0   0} (1 repeated ten times)
 =   {1   11  1   1   1   1   1   1   1   1} (Total)
 
 If we have a number ending in 9 we subtract from 10 to 10.
 0 to 59 = (0 to 9) + (10 to 19) + (20 to 29) + ... + (50 to 59)
 
 And.
 0   1   2   3   4   5   6   7   8   9
 100 to 199 = {20  20  20  20  20  20  20  20  20  20} (00 to 99)
 + {0   100 0   0   0   0   0   0   0   0 } (1 repeated 100 times)
 = {20  120 20  20  20  20  20  20  20  20} (Total)
 
 Now need to be in positions which have nine, this can be done with brute force.
 Using this we can make several solutions, here is an acceptable solution.
 #include <iostream>
 #include <vector>
 using namespace std;
 vector<int> solve(int a){
 vector<int> dig(10, 0);
 if(a > 30000){
 while(a%10000 != 9999){
 int aux = a;
 while(aux){
 dig[aux%10]++;
 aux/=10;
 }
 a--;
 }
 while(a > 20000){
 for(int i=0;i<10;i++)
 dig[i] += 4000;
 int aux = a/10000;
 while(aux){
 dig[aux%10]+=10000;
 aux/=10;
 }
 a-=10000;
 }
 }
 if(a > 3000){
 while(a%1000 != 999){
 int aux = a;
 while(aux){
 dig[aux%10]++;
 aux/=10;
 }
 a--;
 }
 while(a > 2000){
 for(int i=0;i<10;i++)
 dig[i] += 300;
 int aux = a/1000;
 while(aux){
 dig[aux%10]+=1000;
 aux/=10;
 }
 a-=1000;
 }
 }
 for(int i=1; i<=a ;i++){
 int aux = i;
 while(aux){
 dig[aux%10]++;
 aux/=10;
 }
 }
 return dig;
 }
 
 int main() {
 int a, b;
 scanf("%d %d", &a, &b);
 while(a){
 a--;
 vector<int> digA, digB;
 digA = solve(a);
 digB = solve(b);
 for(int i=0;i<10;i++)
 digB[i] -= digA[i];
 printf("%d", digB[0]);
 for(int i=1;i<10;i++)
 printf(" %d", digB[i]);
 printf("\n");
 scanf("%d %d", &a, &b);
 }
 }
*/
/*
 Problem description
 Diana is going to write a list of all positive integers between A and B, inclusive, in base 10 and without any leading zeros. She wants to know how many times each digit is going to be used.
 
 Input
 Each test case is given in a single line that contains two integers A and B (1 ≤ A ≤ B ≤ 108). The last test case is followed by a line containing two zeros. 
 
 
 Output
 For each test case output a single line with 10 integers representing the number of times each digit is used when writing all integers between A and B, inclusive, in base 10 and without leading zeros. Write the counter for each digit in increasing order from 0 to 9. 
 
 
 Sample Input
 1 9
 12 321
 5987 6123
 12345678 12345679
 0 0
 Sample Output
 0 1 1 1 1 1 1 1 1 1
 61 169 163 83 61 61 61 61 61 61
 134 58 28 24 23 36 147 24 27 47
 0 2 2 2 2 2 2 2 1 1
*/