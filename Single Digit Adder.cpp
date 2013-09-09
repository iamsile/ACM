#include <iostream>
#include <stack>
using namespace std;

bool judge(char d)
{
    if (d>='0'&&d<='9')
        return true;
    return false;
}

int main()
{
    string s;
    while (cin >> s) {
        stack<char> a;
        stack<int> n;
        string ss;
        int i,m1,m2;
        for (i=0; i<s.length(); i++) {
            if ((s[i]=='+'||s[i]=='-')&&
                (i-1<0||(!judge(s[i-1])&&s[i-1]!=')'))) {
                s.insert(i,"0");
                i--;
            }
            else if (judge(s[i]))
                ss+=s[i];
            else if (s[i]=='(')
                a.push(s[i]);
            else if (s[i]==')') {
                while (a.top()!='(') {
                    ss+=a.top();
                    a.pop();
                }
                a.pop();
            }
            else {
                if (a.empty()||a.top()=='(')
                    a.push(s[i]);
                else {
                    ss+=a.top();
                    a.pop();
                    a.push(s[i]);
                }
            }
        }
        while (!a.empty()) {
            ss+=a.top();
            a.pop();
        }
        for (i=0; i<ss.length(); i++) {
            if (judge(ss[i]))
                n.push(ss[i]-'0');
            else {
                m2=n.top();
                n.pop();
                m1=n.top();
                n.pop();
                if (ss[i]=='+')
                    n.push(m1+m2);
                else n.push(m1-m2);
            }
        }
        cout << n.top() << '\n';
    }
    return 0;
}
/*
 给出表达式。 由有符号一位数和运算符 + - 及 括号 组成。
 计算结果。
 为了将中缀表达为后缀。 将单操作数运算符前补零。
 如 (-2)+3 先转换为 (0-2)+3。
 然后中缀转后缀。 后缀运算。 
 stl stack 实现。 
 Problem description
 Write a program that can evaluate expressions from the following roughly BNF (Backus Naur Form) grammar:
 expr ::= term | expr ‘+’ term | expr ‘-’ term
 unary_op ::= ‘+’ term | ‘-’ term
 term ::= ‘(’ expr ‘)’ | ‘(’ unary_op ‘)’ | literal
 literal ::= [0-9]
 There will be no whitespace within an expression. All expressions will consist solely of the
 characters (, ), +, -, and the digits 0 through 9. You may assume that all input is well-formed.
 
 
 Input
 The input will consist of one expression per line followed by a newline. There will be no blank lines in the standard input file. 
 
 Output
 For each expression, output its integer value, followed by a single newline.
 
 Sample Input
 1
 (-2)+3
 (1-(2+3))
 (1-2+3)
 (1-(+(2-3)))
 Sample Output
 1
 1
 -4
 2
 2
*/