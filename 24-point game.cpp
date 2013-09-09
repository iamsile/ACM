#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int label[6][3]={
    0,1,2,
    0,2,1,
    1,0,2,
    1,2,0,
    2,0,1,
    2,1,0,
};//数的优先级计算顺序(ab)(cd)、((ab)c)d、(a(bc)d)、a((bc)d)、a(b(cd))
int num[4];//记录数字

double fourcal(double a,double b,int op)
{
    if (op==0)
        return a+b;
    if (op==1)
        return a-b;
    if (op==2)
        return a*b;
    if (op==3) {
        if (b==0)
            return -1000000000;
        return a/b;
    }
}//0、1、2、3代表+-*/

double cal(int op,int pos)
{
    int i,ans,opp[4];
    double tmp[4],temp;
    for (i=0; i<4; i++) {
        tmp[i]=num[i];
        opp[i]=(op>>(4-(i<<1)))&3;
    }
    for (i=0; i<3; i++) {
        ans=label[pos][i];
        temp=fourcal(tmp[ans],tmp[ans+1],opp[ans]);
        if (temp==-1000000000)
            return -1000000000;
        tmp[ans]=tmp[ans+1]=temp;
        if ((pos==2||pos==3)&&i==1)
            tmp[1]=tmp[2]=temp;
    }
    return tmp[ans];
}

int main()
{
    char b[4][2];
    while (scanf("%s %s %s %s",b[0],b[1],b[2],b[3])!=EOF) {
        int i,j,flag=0;
        double result;
        for (i=0; i<4; i++) {
            if (b[i][0]>='0'&&b[i][0]<='9') {
                if (b[i][1]=='0')
                    num[i]=10;
                else num[i]=b[i][0]-'0';
            }
            else if (b[i][0]=='A')
                num[i]=1;
            else if (b[i][0]=='J')
                num[i]=11;
            else if (b[i][0]=='Q')
                num[i]=12;
            else if (b[i][0]=='K')
                num[i]=13;
        }
        sort(num, num+4);
        do {
            for (i=0; i<64; i++)//三个运算符，共有64种可能
                for (j=0; j<6; j++) {
                    result=cal(i,j);
                    if (fabs(result-24)<1E-7)
                        flag=1;
                }
        }while (next_permutation(num, num+4));//生成下一个数的全排列
        if (flag==1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
#include <stdio.h>
#include <ctype.h>
int Get(int j, int sum,int a[]){
	if(j==4 && sum==24)
		return 1;
	else if(j==4)
		return 0;
	if(Get(j+1,sum+a[j],a))
		return 1;
	if(Get(j+1,sum-a[j],a))
		return 1;
	if(Get(j+1,sum*a[j],a))
		return 1;
	if(Get(j+1,sum/a[j],a))
		return 1;
	return 0;
}
int main(){
	int  i,j,k,t,a[4];
	char d[4];
	scanf("%c %c %c %c",&d[0],&d[1],&d[2],&d[3]);
	for(i = 0; i < 4; i++)
		a[i] = (isdigit(d[i]) ? d[i]-48 : d[i]-64);
	for(i = k = 0; k < 24; k++){
		if(Get(1,a[0],a)){
			printf("Y\n");
			return 0;
		}
		j = (i >= 3 ? 0 : i+1);
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i = j;
	}
	printf("N\n");	
	return 0;
}

#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int style[6][3]={
	0,1,2,
	0,2,1,
	1,0,2,
	1,2,0,
	2,0,1,
	2,1,0
};
int permul[24][4]={0,1,2,3};
int num[4];
double BaseCalu(double a, double b, int op){
	switch(op){
        case 0:return a+b;
        case 1:return a-b;
        case 2:return a*b;
        case 3:
            if(b==0)return -1000000000;
            return a/b;
	}
}
double Calu(int opc, int sy){
	int i,j,rs,op[4];
	double itmp[4],tmp;
	for(i=0;i<4;++i){
		itmp[i]=num[i];
		op[i]=(opc>>(4-(i<<1)))&3;
	}
	for(i=0;i<3;++i){
		rs=style[sy][i];
		tmp=BaseCalu(itmp[rs],itmp[rs+1],op[rs]);
		if(tmp==-1000000000)return -1000000000;
		itmp[rs]=itmp[rs+1]=tmp;
		if((sy==2||sy==3)&&i==1)
			itmp[1]=itmp[2]=tmp;
	}
	return itmp[rs];
}

char Find(){
	int opc,sy;
	double result;
	do{
		for(opc=0;opc<64;++opc){
			for(sy=0;sy<6;++sy){
				result=Calu(opc,sy);
				if(fabs(result-24)<1E-7)return 1;
			}
		}
	}while(next_permutation(num, num+4));
	return 0;
}
int ParseInt(char *&p){
	switch(*p){
        case '1':p+=3;return 10;
        case 'A':p+=2;return 1;
        case 'J':p+=2;return 11;
        case 'Q':p+=2;return 12;
        case 'K':p+=2;return 13;
	}
	p+=2;return *(p-2)-'0';
}
char Input(){
	char str[100], *p=str;
	if(!gets(str))return 0;
	for(int i=0;i<4;++i){
		num[i]=ParseInt(p);
	}
	sort(num, num+4);
	return 1;
}
int main(){
	while(Input()){
		if(Find())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}*/
/*
 Problem description
 I think most of the HNU_ACM school team members like playing a game called ‘250’, which is taught by the Doctor Wu. As we all know, Doctor Wu is talented and humorous. He is very approachable and often play games with us students when we are in the trip of taking part in the competition. One time , Kenan , Dxx, Superlong and me are playing the 24-point game in a trip. Doctor Wu seats next to us. What is terrible is that Doctor Wu often tell the answer quickly before we can calculate the answer. We feel very ashamed . How can Doctor Wu always be quicker than us? But we know, beating Doctor Wu is a difficult thing. So I decide to write a program to help us to calculate the answer. As a acmer , can you help me to complete the program? 
 As a player, you can get four cards 1?13(A is 1, J is 11, Q is 12, K is 13), and your task is to do some arithmetic operations (+, - , * , /) using the four numbers. In this game we must consider the fractions(such as 5 is divided by 4 is 5/4 ). You just need to judge if the answer can be 24. If it can puts “YES”, else puts ”NO”. 
 
 
 Input
 There are plenty of test cases, each test case contains four cards numbers(A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) in one line. 
 The end of the input is indicated by the end of the file. 
 
 
 Output
 For each test case ,you just need to output “YES” or “NO” in a line. 
 
 
 Sample Input
 3 8 10 Q
 Sample Output
 YES
*/