#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string,int> m;
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    
    int a,b;
    string s1,s2;
    
    while(1)
    {
        cin>>s1>>s2;
        if("+" == s2)
            a = m[s1];
        else
            a = m[s1]*10 + m[s2], cin>>s2;
        cin>>s1>>s2;
        if("=" == s2)
            b = m[s1];
        else
            b = m[s1]*10 + m[s2], cin>>s2;
        if(0 == a+b)
            break;
        cout<<a+b<<endl;
    }
    return 0;
}
/*
 Problem Description
 读入两个小于100的正整数A和B,计算A+B.
 需要注意的是:A和B的每一位数字由对应的英文单词给出.
 
 
 Input
 测试输入包含若干测试用例,每个测试用例占一行,格式为"A + B =",相邻两字符串有一个空格间隔.当A和B同时为0时输入结束,相应的结果不要输出. 
 
 
 Output
 对每个测试用例输出1行,即A+B的值.
 
 
 Sample Input
 one + two =
 three four + five six =
 zero seven + eight nine =
 zero + zero =
 
 
 Sample Output
 3
 90
 96
*/