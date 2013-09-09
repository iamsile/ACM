#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int a[20],tmp[20];
    char l[20],r[20],res[20];
    int i,j,len,c;
    int n;
    cin >> n;
    while (n--) {
        memset(a, -1, sizeof(a));
        for (j=0; j<3; j++) {
            cin >> l >> r >> res;
            c=strcmp(res, "even");
            len=strlen(l);
            if (c==0) {
                for (i=0; i<len; i++)
                    a[l[i]-'A']=a[r[i]-'A']=0;
            } 
            else if (c<0) {
                memcpy(tmp, a, sizeof(a));
                memset(a, -1, sizeof(a));
                for (i=0; i<len; i++) {
                    a[l[i]-'A']=1;
                    a[r[i]-'A']=2;
                }
                for (i=0; i<20; i++) {
                    if (tmp[i]>=0&&tmp[i]!=a[i])
                        a[i]=0;
                }
            } 
            else {
                memcpy(tmp, a, sizeof(a));
                memset(a, -1, sizeof(a));
                for (i=0; i<len; i++) {
                    a[l[i]-'A']=2;
                    a[r[i]-'A']=1;
                }
                for (i=0; i<20; i++)
                    if (tmp[i]>=0&&tmp[i]!=a[i])
                        a[i]=0;
            }
        }
        for (i=0; i<20; i++)
            if (a[i]>0) {
                printf("%c is the counterfeit coin and it is %s.\n", i+'A', a[i]==1?"light":"heavy");
                break;
            }
    }
    return 0;
}
/*
要注意的问题主要是以下几点：



1. 如果天平两边都是even的话，就可以说明天平两盘上放置的都是真币



2. 如果天平up的话，就可以说明左盘重，右盘轻；反之如果天平down的话，就可以说明右盘重，左盘轻，这一点很重要



3. 如果天平up或者down的话，就可以说明剩下的还没有称量的全部为真币



好了，下面是做题思路：



（-1：未判断 0：真 1：轻 2：重）

开辟两个数组，一个是临时temp数组，另一个是储存每一次称量后及最终结果的数组，在我的程序里是tmp和real（初始化为-1）



输入数据后，首先比较天平平衡，如果even的话，所有的称量货币全部置为真，如果是down的话，将当前real数组中的数据暂存到tmp数组中，然后将real全部置为-1，继而将左盘中的置为1，右盘的置为2，然后将real数组和tmp数组逐位对比，如果不相等，就可以置为真，最后得到的就是本次称量后得到的结果，real中仍然为1或2的就可能为假币，当然，三次循环过后，就可以确定real中哪个是假币，继而输出即可。



个人翻译如下：



Description

Sally Jones 有十二个硬币。然后，只有十一个是真的硬币；一个是假的，尽管它的颜色和大小和
真的硬币没有什么不同。这个假的硬币有着不同的重量，但是Sally不知道这个假的硬币比真的硬币
轻还是重。

幸运的是，Sally的一个朋友有一个非常精准的天平。这个朋友允许Sally称量三次来找到这个假的
硬币。举个例子，如果Sally称量两组硬币并且天平平衡，然后她就可以知道这两组硬币都是真的；
如果Sally称量两组硬币，天平倾斜，Sally就可以知道其中一组是假的硬币，并且知道天平是如何
倾斜的。

通过称量三次，Sally就可以知道三组硬币中的假的硬币。

Input

第一行输入一个数字n (n > 0)，表示将称量n组硬币。每组称量包含三行的输入，每行说明了天平的
情况。Sally已经确定每个硬币都是A--L中的字符，硬币的重量信息将通过两个字符串和一个单词
("up","down","even")。第一个字符串说明了天平左边的硬币，第二个字符串说明了天平右边的硬
币(Sally将保持天平两边的硬币数保持相等)。第三个单词将告诉你天平的右边是上升，下降还是保持
平衡。

Output

对于每组称量，将输出这个伪造的硬币的字母代称和它相比于真的硬币的重量是轻还是重。每组数据
将保证有一个准确的答案。

Sample Input

1 
ABCD EFGH even 
ABCI EFJK up 
ABIJ EFGH even 

Sample Output

K is the counterfeit coin and it is light.



附上一组测试数据：

sample input 
12 
ABCD EFGH even 
ABCI EFJK up 
ABIJ EFGH even 
AGHL BDEC even 
JKI ADE up 
J K even 
ABCDEF GHIJKL up 
ABC DEF even 
I J down 
ABCDEF GHIJKL up 
ABHLEF GDIJKC down 
CD HA even 
A B up 
B A down 
A C even 
A B up 
B C even 
DEFG HIJL even 
ABC DEJ down 
ACH IEF down 
AHK IDJ down 
ABCD EFGH even 
AB IJ even 
A L down 
EFA BGH down 
EFC GHD even 
BA EF down 
A B up 
A C up 
L K even 
ACEGIK BDFHJL up 
ACEGIL BDFHJK down 
ACEGLK BDFHJI down 
ACEGIK BDFHJL up 
ACEGIL BDFHJK down 
ACEGLK BDFHJI up 

sample output 
K is the counterfeit coin and it is light. 
I is the counterfeit coin and it is heavy. 
I is the counterfeit coin and it is light. 
L is the counterfeit coin and it is light. 
B is the counterfeit coin and it is light. 
A is the counterfeit coin and it is heavy. 
A is the counterfeit coin and it is light. 
L is the counterfeit coin and it is heavy. 
A is the counterfeit coin and it is light. 
A is the counterfeit coin and it is heavy. 
L is the counterfeit coin and it is light. 
K is the counterfeit coin and it is heavy.

代码：

#include <stdio.h>
#include <string.h>

int main(void)
{
    int real[20], tmp[20];
    char left[20], right[20], res[20];
    int i, j, len, bl;
    int n;
    
    scanf("%d", &n);
    while (n--) {
        memset(real, -1, sizeof(real));
        for (j = 0; j < 3; j++) {
            scanf("%s%s%s", left, right, res);
            bl = strcmp(res, "even");
            len = strlen(left);
            
            if (bl == 0) {
                for (i = 0; i < len; i++)
                    real[left[i]-'A'] = real[right[i]-'A'] = 0;
            } else if (bl < 0) {
                memcpy(tmp, real, sizeof(real));
                memset(real, -1, sizeof(real));
                for (i = 0; i < len; i++) {
                    real[left[i]-'A'] = 1;
                    real[right[i]-'A'] = 2;
                }
                for (i = 0; i < 20; i++) {
                    if (tmp[i] >=0 && tmp[i] != real[i])
                        real[i] = 0;
                }
            } else {
                memcpy(tmp, real, sizeof(real));
                memset(real, -1, sizeof(real));
                for (i = 0; i < len; i++) {
                    real[left[i]-'A'] = 2;
                    real[right[i]-'A'] = 1;
                }
                for (i = 0; i < 20; i++) {
                    if (tmp[i] >= 0 && tmp[i] != real[i])
                        real[i] = 0;
                }
            }
        }
        
        for (i = 0; i < 20; i++)
            if (real[i] > 0) {
                printf("%c is the counterfeit coin and it is %s.\n", i+'A', real[i] == 1 ? "light" : "heavy");
                break;
            }
        
    }
    
    return 0;
}
 Problem description
 Your friend has a dozen identical coins. However, one coin is counterfeit even though its color and size make it indistinguishable from the genuine ones. The counterfeit coin has a different weight from the other coins but your friend does not know if it is heavier or lighter than the real coins. Your friend has a very accurate balance scale, but no weights, so she can only weigh the coins against each other. She tells you that she has an algorithm that can provably find the fake coin in three weighings. As a first step towards ensuring correctness of her approach, you write a program to check her findings. 
 
 Input
 The first line of input is an integer n (n > 0) specifying the number of problem instances to follow. Each instance consists of three lines of input, one for each weighing. Your friend has identified each of the coins with the letters A-L. Information on a weighing will be given by two strings of letters and then one of the words ``up'', ``down'', or ``even''. The first string of letters will represent the coins on the left balance; the second string, the coins on the right balance. (For simplicity, assume that your friend always places four coins on each side of the scale). The word in the third position indicates whether the right side of the balance goes up, down, or remains even. 
 
 Output
 For each case, the output will identify the counterfeit coin by its letter and tell whether it is heavy or light. The solution will always be uniquely determined. 
 
 Sample Input
 1
 ABCD EFGH even
 ABCI EFJK up
 ABIJ EFGH even
 Sample Output
 K is the counterfeit coin and it is light.
 Problem Source
*/