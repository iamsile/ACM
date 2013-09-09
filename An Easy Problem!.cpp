#include <iostream>
using namespace std;

int main()
{
    char a[1001];
    while (~scanf("%s",a)) {
        int i,k=strlen(a),max=0,num=0,flag=0;
        for (i=0; i<k; i++)
            if (a[i]>='0'&&a[i]<='9') {
                if (a[i]-'0'>max)
                    max=a[i]-'0';
                num=num+a[i]-'0';
            }
            else if (a[i]>='a'&&a[i]<='z') {
                if (a[i]-'a'+36>max)
                    max=a[i]-'a'+36;
                num=num+a[i]-'a'+36;
            }
            else if (a[i]>='A'&&a[i]<='Z') {
                if (a[i]-'A'+10>max)
                    max=a[i]-'A'+10;
                num=num+a[i]-'A'+10;
            }
        for (i=2,flag=0; i<=62; i++)
            if (num%(i-1)==0&&i>max) {
                flag=1;
                break;
            }
        if (flag)
            cout << i << '\n';
        else cout << "such number is impossible!\n";
    }
    return 0;
}
/*
 输入一个2至62进制的数(其中A—>Z表示：10—>35
 a->z表示：36->62)试着求出含有此数的最小进制并输出；比如输入3则其出现在的n进制里4最小，于是输出4；
 进制转换：如输入abcd，则对应的n进制为：（a*n*n*n+b*n*n+c*n+d）
 根据题目要求：：（a*n*n*n+b*n*n+c*n+d）%（n-1)要等于0
 即：a%（n-1)+b%(n-1)+c%(n-1)+d%(n-1)=0;
 注：（n*n*n%（n-1)=1）
 Problem description
 Have you heard the fact “ The base of every normal number system is 10 ”? Of course, I am not talking about number systems like Stern Brockot Number System. This problem has nothing to do with this fact but may have some similarity.
 You will be given an N based integer number R and you are given the guaranty that R is divisible by (N − 1). You will have to print the smallest possible value for N. The range for N is 2  N  62 and the digit symbols for 62 based number is (0..9 and A..Z and a..z). Similarly, the digit symbols for 61 based number system is 0..9 and A..Z and a..y) and so on.
 
 Input
 Each line in the input file will contain an integer (as defined in mathematics) number of any integer base (2..62). You will have to determine what is the smallest possible base of that number for the given conditions. No invalid number will be given as input. The largest size of the input file will be 32KB
 
 Output
 If number with such condition is not possible output the line ‘such number is impossible!’ For each line of input there will be only a single line of output. The output will always be in decimal number system.
 
 Sample Input
 3
 5
 A
 Sample Output
 4
 6
 11
*/