#include <iostream>  
#include <string.h>   
char s[1000001];  
int a[1000001];

int main()  
{ 
    scanf("%s",s);
    while(s[0]!='.')  
    {    
        int l=strlen(s),i=0,j=-1; 
        a[0]=-1;  
        while(i<=l)  
        {  
            if(j==-1||s[i]==s[j])  
            {  
                i++;  
                j++;  
                a[i]=j;  
            }  
            else  
                j=a[j];  
        }  
        if(l%(l-a[l])==0)  
			printf("%d\n",l/(l-a[l]));
        else  
			printf("%d\n",1);
        scanf("%s",s);
    }  
    return 0;  
}
/*
 设文本为T={t1，t2...tn}，模式为P={p1,p2...pn}，则KMP算法的大概思想就是提前计算出在字符处匹配中遇到前q个字符匹配而第q+1个字符不匹配时，模式P需要移动的位置数。在算法导论中，引入了一个数组π，用于保存这样的信息。π［ｍ］的含义就是既是Ｐｍ的前缀又是Ｐｍ的真后缀的最大子串长度。之所以是“真”后缀，是因为如果非真后缀的话，此时已经匹配了。π的含义如
 i     1 2 3 4 5 6 7 8
 pi    a b a b a b a b
 π[i]  0 0 1 2 3 4 5 6 
 而需要特别注意的是算法导论中的下标是从1开始的，这是和π中元素的含义(即上面所说)相匹配的，这种情况下，如果遇到不匹配的字符时，移动量的计算公式为最后一个匹配字符的索引(设为q)-π[q]。如
 1 2 3 4 5 6  7
 a b a b a b c
 a b a b a b d
 那么此时需要移动的量为6-π[6]=6-4=2。而在具体的代码实现时，我们需要计算的是next数组，a数组的计算结果和π有一点点的不相同，因为在代码实现中，我们的下标都是从0开始的。仍以上面的例子为例： 
 i      0  1 2 3 4 5 6 7 8
 pi     a  b a b a b a b 
 a[i]  -1  0 0 1 2 3 4 5 6//注意a中-1后有两个0，看了几个网上的答案，都是一个，需要特别注意。 
 此时，如果遇到不匹配的字符时，计算公式为第一个不匹配字符的索引(设为q)-next[q]。如： 
 0  1 2 3 4 5  6 
 a  b a b a b c 
 a  b a b a b d 
 -1 0 0 1 2 3 4
 则需要移动的量为6-4=2。而此时的next数组的含义也不再是算法导论中真后缀的最大前缀子串的长度了。
*/
/*
 Problem description
 Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).
 
 Input
 Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.
 
 Output
 For each s you should print the largest n such that s = a^n for some string a. 
 
 Sample Input
 abcd
 aaaa
 ababab
 .
 Sample Output
 1
 4
 3
*/