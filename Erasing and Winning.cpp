#include<iostream>   
using namespace::std;  
char s[100001];    
void Greedy (int now,int start,int end,int need)   
{   
    if(now==-1||need==0) 
		return;   
    int a,last=start-1; /*start-1 是可能之間都沒有該數字...*/  
    for(a=start;a<=end;a++) /*在之間取需要的個數*/  
		if(s[a]-48==now)   
		{   
			if((end-a)>=need)    
			{   
				putchar(now+48);   
				last=a; /*紀錄上一次的位子*/  
				need--; /*需要的個數一直減少*/  
				if(need==0) 
					return;    
			}                      
			else /* 若無法在剩餘的數字中取到足夠的個數 則在上一次出現的位子中取數 */  
			{    
				Greedy (now-1,last+1,a-1,need-(end-a)-1); /*不足的往數字(now-1) 從上一次數字(now)出現的位子 到 這個數(now)之前 取不足的數字*/  
				for(a=a;a<=end;a++)/*退回來之後 輸出剩餘的全部*/  
					printf("%c",s[a]);
				return;   
			}    
		}   
    if(need!=0) 
		Greedy (now-1,last+1,end,need);   
    /* 取了或者根本沒取 需求不足 則從上一次紀錄的地方往結尾去找 下一個數字(now-1)*/  
}    
main()   
{   
	int n,m;   
	while(cin >> m >> n&&m&&n)   
	{   
		cin >> s;
		Greedy (9,0,m-1,m-n);/*先找數字 9*/  
		printf("\n");   
	}    
	return 0;   
}  
/*
 Problem description
 Juliano is a fan of the TV show Erasing and Winning, where participants are selected in a draw and receive money for taking part in the show.
 In the show, the presenter writes a number of N digits in a board. The participant must then erase exactly D digits from the number in the board; the number formed by the remaining digits is the value of the money prize for the participant.
 
 Juliano was at last selected to take part in the show, and asked you to write a program that, given the number the presenter wrote in the board, and the number of digits Juliano must erase, determines the highest value of the prize he can win. 
 
 
 Input
 The input contains several test cases. The first line of a test case contains two integers N and D (1 ≤ D < N ≤ 105) indicating respectively the number of digits of the number the presenter wrote in the board and the number of digits that must be erased. The next line contains the number the presenter wrote; the number does not start with a zero.
 The end of input is indicated by a line containing only two zeros, separated by a space. 
 
 
 Output
 For each test case in the input your program must produce one single line in the output, containing the highest prize Juliano can win. 
 
 Sample Input
 4 2
 3759
 6 3
 123123
 7 4
 1000000
 0 0
 
 Sample Output
 79
 323
 100
*/