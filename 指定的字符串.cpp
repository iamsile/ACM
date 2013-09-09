#include <iostream>
#include <string.h>
int height,width,strNum,len;
bool isHave;
char rect[90][90]={0};
char str[30];
const char Dir[8][2]=
{-1,-1, -1,0, -1,1, 0,-1, 0,1, 1,-1, 1,0, 1,1};

void InitRect()
{
	scanf("%ld%ld",&width,&height);
	for(int i=1;i<=height;i++)
		for(int j=1;j<=width;j++)
		{
            getchar();
            rect[i][j]=getchar();
        }
}

void CheckString()
{
	int i,j,k,m;
	for(i=1;i<=height;i++)
		for(j=1;j<=width;j++)
            if(str[0]==rect[i][j])
                for(k=0;k<8;k++)
                {
                    isHave=1;
                    if(i+len*Dir[k][0]<1||i+len*Dir[k][0]>height)
                        continue;
                    if(j+len*Dir[k][1]<1||j+len*Dir[k][1]>width)
                        continue;
                    for(m=1;str[m];m++)
                        if(str[m]!=rect[i+m*Dir[k][0]][j+m*Dir[k][1]])
                        {isHave=0;break;}
                    if(isHave)
                    {
                        printf("(%ld,%ld)->(%ld,%ld)\n",
                               j,i,j+len*Dir[k][1],i+len*Dir[k][0]);
                        return;
                    }
                }
}

void InitString()
{
	scanf("%ld",&strNum);
    getchar();
	while(strNum--)
	{
		gets(str);
		len=strlen(str)-1;
		CheckString();
	}
}

int main()
{
	InitRect();
	InitString();
	return 0;
}
/*
 Problem description
 在二维字符阵列中寻找指定的字符串
 
 Input
 前两行分别指示字符矩阵的宽w 和高h（1<=w<=80 且1<=h<=80）。接下来的h 行每行w 个用空格分开的字 符便是字符矩阵的内容，再下面的1 行为要寻找的字符串的数目n（n<10），其后的n 行便是要 寻找的字符串，每个字符串不会超过20 个字符。
 
 Output
 n 行，每行保存1 个字符串的位置。位置的格式形如(1,2)->(2,6)，意为该字符串首字母在字符矩 阵中的位置是第1 列2 行，尾字母在字符矩阵中的位置是第2 列6 行。 如果某个字符串在字符阵列中出现多次，则只记录任意一个出现位置即可。字符串出现的形式 可能是水平、竖直、向前、向后和斜向。输出的位置顺序应该与输入中的字符串出现顺序一致。 区分字符的大小写。
 
 Sample Input
 7
 7
 E Y B E Y B D
 K D I C J E N
 A K E W N Q A
 O A Y T U E L
 E N A M A J R
 Z Z C A D W O
 E K S I A P B
 3
 AAAAA
 BYEBYE
 BORLAND
 Sample Output
 (1,3)->(5,7)
 (6,1)->(1,1)
 (7,7)->(7,1)
*/