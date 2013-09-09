#include <iostream>

int main()
{ 
	int m,n;
    while(scanf("%d%d",&m,&n)!=EOF) 
	{
		if (m<=0||n<=0||((m+n)&1)==0) 
			printf("%d %d\n",m,n); 
		else 
			printf("%d %d\n",n,m); 
	}
	return 0;
}
/*
 分析过程（/函数）（C代码，Pascal一样） 
 int f(long& x, long& y)  {                                            1 
 if (x>0 && y>0) {                                                   2 
 for (long i=1; i<=x+y; i++) {                                      3 
 y=x*x+y;                                                      4 
 x=x*x+y;                                                      5 
 y=round(sqrt(x+(y/labs(y))*(-labs(y))));                      6 
 for (long j=0; j<2*y; j++)                                     7 
 x=x-y;                                                        8 
 }                                                             9 
 }                                                                10 
 return 0;                                                          11 
 }                                                                      12 
 1.	程序头表示过程（/函数）的输入输出都是长整型； 
 2.	第二行表明如果输入中如果有小于等于0的数值，输入输出的值是相同的。 
 3.	从第3行到第9行是循环，我们把循环开始的值记为x[i],y[i],以后变化的值记为x[i+1],y[i+1];从第4行开始到第6行，值的变化如下：  
 y[i+1]=y[i]+x[i]*x[i] 
 x[i+1]=y[i+1]+x[i]*x[i]=y[i]+2*x[i]*x[i] 
 第6行的是最夸张的y=round(sqrt(x+(y/labs(y))*(-labs(y))));首先x+(y/labs(y))*(-labs(y))=x-y=x[i+1]-y[i+1]=x[i]*x[i],所以round（sqrt(x[i]*x[i])）=x[i];                       
 4.	第7行循环次数是2y[i+1]=2x[i],每次循环将x[i+1]的值减掉y[i+1]=x[i],所以经过第7行的循环后，x[i+1]=x[i+1]-2y[i+1]*y[i+1]=y[i] 。 
 5.	经过第3行到第9行的一次循环，x和y的值作了互换。x+y不变，也就是循环次数不变。 
 6.	当x和y的值是正整数，且x+y是奇数，第3行到第9行的循环次数是奇数，x和y的值互换。输入的x和y的值互换就是输出的x和y。其他情况，输入输出的值是相同的。 
 本题就是考察分析和调试程序的能力，其实程序很简单。
 */
/*
 Problem description
 It's often happens in programming that one has to test and debug an existing program code. Imagine that your colleague has passed you fragment of program code of his because he is to work at another program. Here follows the fragment of the program code - a function with two input-output parameters: 
 
 The Pascal text
 
 The C text
 
 procedure P(var x,y: longint); 
 var i,j: longint; 
 begin 
 if (x>0) and (y>0) then 
 begin 
 for j:=1 to x+y do 
 begin 
 y:=x*x+y; 
 x:=x*x+y; 
 y:=round(sqrt(x+(y/abs(y))*(-abs(y))));
 for i:=1 to 2*y do 
 x:=x-y; 
 end; 
 end; 
 end;
 
 #include 
 int f(long& x, long& y) 
 { 
 if (x>0 && y>0) 
 { 
 for (long i=1; i<=x+y; i++) 
 { 
 y=x*x+y; 
 x=x*x+y; 
 y=round(sqrt(x+(y/labs(y))*(-labs(y)))); 
 for (long j=0; j<2*y; j++) 
 x=x-y; 
 } 
 } 
 return 0; 
 }
 
 
 Your task is unusual: in order to debug the function it's necessary to work out a program that would restore input parameters given output data of the function. It's guaranteed that no variable has left its type during the processing of the function.
 
 Input
 There are several test cases, each test case contains two numbers x and y separated with a space in a line- those are output parameters of the function.
 
 Output
 should contain two numbers x and y separated with a space in a line that were given to the function as input parameters. 
 
 Sample Input
 1 1
 Sample Output
 1 1
*/