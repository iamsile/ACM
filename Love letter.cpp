#include <iostream>
#include <string.h>
using namespace::std;

int m,n,t,prob;
char s1[110], s2[110];
int a[110][110],b[110][110];

int find(int i, int j)
{
    if (a[i][j]!=prob)
    {
        a[i][j]=prob;
        if (i==m||j==n||s1[i]!=s2[j])
            b[i][j]=0;
        else
            b[i][j]=1+find(i+1,j+1);
    }
    return b[i][j];
}

int main()
{
    int i,j,k,max;
    cin >> t;
    for (prob=1;prob<=t;prob++) 
    {
        cin >> m >> n;
        cin >> s1;
        cin >> s2;
        max=0;
        for (i=0;i<m;i++)
            for (j=0;j<n;j++) 
            {
                k=find(i,j);
                if (k>max) 
                    max=k;
            }
        cout << max << '\n';
    }
    return 0;
}
/*
 Problem description
 立哥最近收到一封情书，其字里行间那诚挚的内心独白和纯真的感情叙述令立哥感动不已。但已有4次被甩经历的立哥怎么也不明白为什么会有女孩子突然莫名其妙给自己写情书。拥有超高智商的立哥很快想到这有可能是他的那帮狐朋狗友在捉弄他，所以在按照情书的约定于某月某日晚上12点半赴上海市郊黄渡镇见面之前，立哥打算先暗中调查一下这封情书是不是他的那帮死党炮制出来的。
 
 他花了好大的功夫，终于把这帮人平时写给女生们的怪诗以及他们的心情日记、检讨等搜集起来，汇总成册（立哥将该册子称为“材料”）。接下来，他打算通过对作文风格的对比，来分析他收到的这封神秘情书是否出自这些人之手。不过首先，他要找一找两者（情书和材料）之间完全相同的句子，为了得到更可靠的分析结果，他要找到两者之间最长的那个公共句子。
 
 不过这可不是件易事，所以他找到正在参加ACM训练的你，希望你能写个程序，帮他找到这个最长公共句子。 这里你只需要完成核心工作，求出最长公共句子的长度就可以了。 
 
 Input
 第1行只包含一个整数T（0＜T≤10），表示一共有T组测试数据。 从第2行到第3T+1行每三行为一组测试数据。每组测试数据的第一行包含两个整数 m，n（0＜m、n≤100），第二行为一个长度为m的字符串，为情书的内容。第三行为一个长度为n的字符串，为材料的内容。为简化处理，两个字符串都仅包含小写英文字母。 
 
 Output
 共T行，每行对应一组测试数据的答案（将第I组测试数据的答案输出在第I行）。 每组测试数据的答案为一个整数：最长公共句子的长度（字符数）。 
 
 Sample Input
 3
 10 24
 helloworld
 thisisalowercasesentense
 6 8
 abcdef
 ghijklmn
 9 22
 abcababab
 bababcababcababababcab
 Sample Output
 3
 0
 9
 Judge Tips
 第一组数据的最长公共句子长度为3，这是因为在helloworld和thisisalowercasesentense这两个字符串中，都有一个公共的子串low,其长度为3，并且不存在长度超过3的公共字串。 第二组数据abcdef和ghijklmn完全不存在相同的子串，故其最长公共句子长度为0。 第三组数据abcababab和bababcababcababababcab都包含abcababab这个子串，其长度为9，且不存在更长的公共子串。故答案为9。
*/