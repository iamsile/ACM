#include <iostream>
#include <string.h>
using namespace std;

void cal(char *a,char *b)
{
    int i,j,lena,lenb,temp=0;
    lena=strlen(a);
    lenb=strlen(b);
    int ax[201],bx[201],cx[201];
    for (i=0; i<lena; i++)
        ax[i]=(a[lena-i-1]-'A');
    for (i=0; i<lenb; i++)
        bx[i]=(b[lenb-i-1]-'A');
    for (i=lenb; i<lena; i++)
        bx[i]=0;
    for (i=0; i<lena; i++) {
        cx[i]=temp+ax[i]+bx[i];
        if (cx[i]>=26) {
            temp=1;
            cx[i]=cx[i]-26;
        }
        else temp=0;
    }
    cx[lena]=temp;
    int flag=0;
    char ans;
    for (i=lena; i>=0; i--) {
        if (cx[i]!=0)
            flag=1;
        if (flag==1) {
            ans='A'+cx[i];
            cout << ans;
        }
    }
    cout << '\n';
}

int main()
{
    char a[201],b[201];
    while (cin >> a >> b) {
        int lena,lenb;
        lena=strlen(a);
        lenb=strlen(b);
        if (lena>=lenb)
            cal(a,b);
        else cal(b,a);
    }
    return 0;
}
/*
 Problem Description
 XYZ-26进制数是一个每位都是大写字母的数字。 A、B、C、…、X、Y、Z 分别依次代表一个0 ~ 25 的数字，一个 n 位的26进制数转化成是10进制的规则如下
 A0A1A2A3…An-1 的每一位代表的数字为a0a1a2a3…an-1 ，则该XYZ-26进制数的10进制值就为 
 
 m ＝ a0 * 26^(n-1) + a1 * 26^(n-2) + … + an-3* 26^2 + an-2*26 + an-1 
 
 一天vivi忽然玩起了浪漫，要躲在学校的一个教室，让枫冰叶子去找，当然，她也知道枫冰叶子可不是路痴，于是找到了XYZ的小虾和水域浪子帮忙，他们会在vivi藏的教室的门口，分别写上一个XYZ-26进制数，分别为 a 和 b，并且在门锁上设置了密码。显然，只有找到密码才能打开锁，顺利进入教室。这组密码被XYZ的成员称为lovekey。庆幸的是，枫冰叶子知道lovekey是 a的10进制值与b的10进制值的和的XYZ-26进制形式。当然小虾和水域浪子也不想难为枫冰叶子，所以a 和 b 的位数都不会超过200位。
 例如第一组测试数据 
 a = 0 * 26^5+0* 26^4+ 0* 26^3+ 0 *26^2 + 3*26 + 7 = 85
 b = 1*26^2 + 2*26 + 4 = 732
 则 a + b = 817 = BFL
 
 
 Input
 题目有多组测试数据。
 每组测试数据包含两个值均为的XYZ－26进制数，每个数字的每位只包含大写字母，并且每个数字不超过200位。
 
 
 Output
 输出XYZ的lovekey，每组输出占一行。
 
 
 Sample Input
 AAAADH  BCE
 DRW  UHD
 D  AAAAA
 
 
 Sample Output
 BFL
 XYZ
 D
*/