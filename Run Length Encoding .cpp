#include <stdio.h>

struct node{// 数据结构，保存连续字符的个数和值
	int c;// 保存个数
	char ch;// 保存该字符
}a;

int main()
{
	int one,b;
	char ch;// 暂存当前输入的字符
	a.c=0;// 初始化为0
	one=0;// 初始化为0
	b=0;// 初始化为0
	while(1)
	{
		ch=getchar();// 输入字符
		if(ch=='\n')// 当第一个输入的字符为'\n'时即为输入空行，则输出空行
		{
			printf("\n");
			continue;
		}
		a.ch=ch,a.c=1;// 保存当前输入的第一个字符到a结构中
		while(ch=getchar())// 继续输入字符
		{
			{// 对于ch，结构a中保存的字符即为前一个输入的字符
				if(a.ch==ch)// 若与前一个输入的字符相同，则进行累加
				{
					a.c++;
					if(a.c>9)// 若累加达到了10个则需先输出前9个
					{
						if(one)// 若前面存在未输出的全为当字符串时的‘1’结束的标志，先输出‘1’
						{
							printf("1");
							one=0;// 把单字符串的标志清楚
						}
						printf("9%c",a.ch);// 输出9个连续相同的编码
						a.c=1;// 把相同的字符个数置为 1
					}
				}
				else// 当前输入的字符与前一个输入的字符不相同
				{
					if(a.c==1)// 当前一个字符的个数只是一个时
					{
						if(!one)// 判断前面是不是一个未终止的单字符串，
						{
							printf("1");
							one=1;// 单字符串的标志置为1
						}
						if(a.ch=='1')// 若前一个字符为‘1’则输出‘11’，否则输出前一个字符
						{
							printf("11");
						}
						else
							printf("%c",a.ch);
						a.ch=ch;a.c=1;// 保存当前字符到a中
					}
					else
					{
						if(one)//若前面是单字符串，即单字符串标志one为1
						{
							printf("1");
							one=0;
						}
						printf("%d%c",a.c,a.ch);// 输出a的编码情况
						a.ch=ch,a.c=1;// 保存当前字符到a中
					}
				}
			}
			if(ch=='\n')// 若当前的字符是'\n'，则一行的输入结束，
			{
				if(one)// 若单字符串标志one为1，则结束单字符串
					printf("1");
				printf("\n");// 输出换行
				a.c=0;// 初始置为0
				one=0;
				break;
			}
			if(ch==EOF)// 若当前输入的字符是EOF，这整个程序的输入结束
			{
				b=1;// 设置标志，以便退出整个程序
				if(one)// 若单字符串标志one为1，则结束单字符串
					printf("1");
				printf("\n");
				break;
			}
		}
		if(b) break;// 退出循环，以退出程序
	}
	return 0;
}
/*
 （1）对于2~9个连续相同的字符，输出连续字符的长度和字符的值；
 （2）对于超过9个连续相同字符的串，先对前面的9个做编码并输出，后面的继续编码。
 （3）对于都是单个的字符序列，编码输出时，头尾各加一个‘1’再输出；字符当中如果包含了‘1’则输出‘11’；
 */
/*
 
 Problem description
 Your task is to write a program that performs a simple form of run-length encoding, as described by the rules below. 
 
 Any sequence of between 2 to 9 identical characters is encoded by two characters. The first character is the length of the sequence, represented by one of the characters 2 through 9. The second character is the value of the repeated character. A sequence of more than 9 identical characters is dealt with by first encoding 9 characters, then the remaining ones. 
 
 Any sequence of characters that does not contain consecutive repetitions of any characters is represented by a 1 character followed by the sequence of characters, terminated with another 1. If a 1 appears as part of the sequence, it is escaped with a 1, thus two 1 characters are output. 
 
 
 Input
 The input consists of letters (both upper- and lower-case), digits, spaces, and punctuation. Every line is terminated with a newline character and no other characters appear in the input. 
 
 Output
 Each line in the input is encoded separately as described above. The newline at the end of each line is not encoded, but is passed directly to the output. 
 
 Sample Input
 AAAAAABCCCC
 12344
 Sample Output
 6A1B14C
 11123124
*/