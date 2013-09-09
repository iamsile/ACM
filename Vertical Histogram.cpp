#include <iostream>
using namespace std;

void count(char a[],int sum[])//统计A~Z各个字符在字符串中出现的次数
{
    int i;
    for (i=0;i<strlen(a);i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
            sum[a[i]-'A'+1]++;
    }
}

int main()
{
    char a[75],b[75],c[75],d[75];
    int sum[27]={0},max,i,j,flag;
    cin.getline(a,75);
    cin.getline(b,75);
    cin.getline(c,75);
    cin.getline(d,75);
    count(a,sum);
    count(b,sum);
    count(c,sum);
    count(d,sum);
    max=sum[1];
    for (i=1;i<=26;i++)//选出出现次数最高的，以控制行的输出
        if(sum[i]>max)
            max=sum[i];
    for (i=max;i>=1;i--)//行控制
    {
        for (j=1;j<=26;j++)//找到该行的结束标记
            if(sum[j]==i)
                flag=j;
        for (j=1;j<=26;j++)//列控制
        {
            if(sum[j]==i)//满足当前为最大时输出
            {
                j<flag?cout<<"* ":cout<<"*";//结束之前输出* 结束位置输出*
                sum[j]--;   
            }
            else
                j<flag?cout<<"  ":cout<<" ";
            if(j==flag)//达到结束标记时，回车推出循环
            {
                cout<<endl;break;
            }
        }
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    return 0;
}
/*
 
 Problem description
 Write a program to read four lines of upper case (i.e., all CAPITAL LETTERS) text input (no more than 72 characters per line) from the input file and print a vertical histogram that shows how many times each letter (but not blanks, digits, or punctuation) appears in the all-upper-case input. Format your output exactly as shown.
 
 Input
 Lines 1..4: Four lines of upper case text, no more than 72 characters per line.
 
 Output
 * Lines 1..??: Several lines with asterisks and spaces followed by one line with the upper-case alphabet separated by spaces. Do not print unneeded blanks at the end of any line. Do not print any leading blank lines. 
 
 Sample Input
 THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
 THIS IS AN EXAMPLE TO TEST FOR YOUR
 HISTOGRAM PROGRAM.
 HELLO!
 Sample Output
         *
         *
         *                   *
         *                   *     *   *
         *                   *     *   *
 *       *     *             *     *   *
 *       *     * *     * *   *     * * *
 *       *   * * *     * *   * *   * * * *
 *     * * * * * *     * * * * *   * * * *     * *
 * * * * * * * * * * * * * * * * * * * * * * * * * *
 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 
*/