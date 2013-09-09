#include <iostream>
using namespace std;
char input[250005];
char str[250005];

int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%s",input);
        int len;
        while (1) {
            int flag=0;
            int c=0;
            int i,j,k;
            len=strlen(input);
            for (i=0; i<len; i++) {
                if (input[i]>='a'&&input[i]<='z')
                    str[c++]=input[i];
                else if (input[i]>='0'&&input[i]<='9')
                {
                    int cnt=0;
                    while (input[i]>='0'&&input[i]<='9') {
                        cnt*=10;
                        cnt+=input[i]-'0';
                        ++i;
                    }
                    if (input[i]!='(') {
                        while (cnt--) {
                            str[c++]=input[i];
                        }
                    }
                    else {
                        int t=1;
                        int temp=i+1;
                        while (t!=0) {
                            if (input[temp]=='(')
                                ++t;
                            else if (input[temp]==')')
                                --t;
                            ++temp;
                        }
                        for (j=0; j<cnt; j++)
                            for (k=i+1; k<temp-1; ++k) {
                                str[c++]=input[k];
                                if (input[k]=='('||input[k]==')'||input[k]>='0') {
                                    flag=1;
                                }
                            }
                        i=temp-1;
                    }
                }
            }
            str[c]=0;
            memcpy(input, str, sizeof(str));
            if (!flag)
                break;
        }
        cout << str << '\n';
    }
    return 0;
}
/*
 Problem Description
 在纺织CAD系统开发过程中，经常会遇到纱线排列的问题。
 该问题的描述是这样的：常用纱线的品种一般不会超过25种，所以分别可以用小写字母表示不同的纱线，例如：abc表示三根纱线的排列；重复可以用数字和括号表示，例如：2(abc)表示abcabc；1(a)=1a表示a;2ab表示aab;如果括号前面没有表示重复的数字出现，则就可认为是1被省略了，如：cd(abc)=cd1(abc)=cdabc;这种表示方法非常简单紧凑，也易于理解；但是计算机却不能理解。为了使计算机接受，就必须将简单紧凑的表达方式展开。某ACM队接受了此项任务。现在你就是该ACM队的一员，请你把这个程序编写完成。
 已知条件：输入的简单紧凑表达方式的长度不超过250个字符；括号前表示重复的数不超过1000；不会出现除了数字、括号、小写字母以外的任何其他字符；不会出现括号不配对等错误的情况（错误处理已由ACM其他队员完成了）。
 
 
 Input
 本题有多个测试数据组，第一行输入的就是数据组数N，接着就是N行表达式，表达式是按照前面介绍的意义书写的。
 
 
 Output
 输出时含有N行，每行对应一个输入的表达式。
 
 
 Sample Input
 2
 1(1a2b1(ab)1c)
 3(ab2(4ab))
 
 
 Sample Output
 abbabc
 abaaaabaaaababaaaabaaaababaaaabaaaab
*/