#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[10010]={'('};
    while (scanf("%s",a+1)!=EOF) {
        int i,j,cur,len=strlen(a),q[10010];
        bool flag[10010];
        memset(flag, false, sizeof(flag));
        a[len]=')';//这步不能少
        for (i=1,cur=-1; i<len; i++) {
            if (a[i]=='('||a[i]==')') {
                flag[i]=false;
                if (a[i]=='(')
                    q[++cur]=i;//为相应的括号匹配做准备
                else {
                    flag[i]=flag[q[cur]];//检查')'是否匹配
                    cur--;
                }
            }
            else {
                flag[i]=true;
                if (a[i]=='+')
                    flag[q[cur]]=true;
            }
        }
        for (i=1,j=1; i<len; i++)
            if (flag[i])
                a[j++]=a[i];//去掉内层多余的括号，缩进字符串
        len=j;
        a[len]=')';//这步也不能少
        for (i=1,cur=-1; i<len; i++) {
            if (a[i]=='('||a[i]==')') {
                flag[i]=false;
                if (a[i]=='(')
                    q[++cur]=i;
                else {
                    flag[i]=flag[q[cur]];
                    if (a[i+1]=='('||(a[i+1]<='z'&&a[i+1]>='a')||a[q[cur]-1]==')'||(a[q[cur]-1]<='z'&&a[q[cur]-1]>= 'a')) {
                        flag[q[cur]] = true;
                        flag[i] = true;
                    }//把内层有用的括号保留下来
                    cur--;
                }
            }
            else flag[i]=true;
        }
        for (i=1; i<len; i++)
            if (flag[i])
                cout << a[i];
        cout << '\n';
    }
    return 0;
}
/*
 Problem description
 To a computer, there is no difference between the expression (((x)+(y))(t)) and (x+y)t; but, to a human, the latter is easier to read. When writing automatically generated expressions that a human may have to read, it is useful to minimize the number of parentheses in an expression. We assume expressions consist of only two operations: addition (+) and multiplication (juxtaposition), and these operations act on single lower-case letter variables only. Specifically, here is the grammar for an expression E:
 
 E : P | P '+' E
 P : F | F  P
 F : V | '(' E ')'
 V : 'a' | 'b' | .. | 'z'
 The addition (+, as in x+y) and multiplication (juxtaposition, as in xy) operators are associative: x+(y+z)=(x+y)+z=x+y+z and x(yz)=(xy)z=xyz. Commutativity and distributivity of these operations should not be assumed. Parentheses have the highest precedence, followed by multiplication and then addition.
 
 
 
 Input
 The input consists of a number of cases. Each case is given by one line that satisfies the grammar above. Each expression is at most 1000 characters long.
 
 
 
 Output
 For each case, print on one line the same expression with all unnecessary parentheses removed.
 
 
 
 Sample Input
 x
 (x+(y+z))
 (x+(yz))
 (x+y(x+t))
 x+y+xt
 Sample Output
 x
 x+y+z
 x+yz
 x+y(x+t)
 x+y+xt
*/