#include <iostream>
using namespace::std;

void cal(int *a,int base,int n)
{
	int i,j,lab=0;
	memset(a, 0, sizeof(int)*200);
	for(i=0,j=base;i<200;i++,j=j/10)
		a[i]=j%10;
	for(i=0;i<n-1;i++)
	{
		j=0;
		for(j=0;j<200;j++)
		{
			lab=a[j]*base+lab;
			a[j]=lab%10;
			lab/=10;
		}
	}
}

int main()
{
	char s[200];
	int a[200],n,i,base,len,lab=1,k=0;
	while(cin >> s >> n)
	{
		base=0;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]=='.')
			{
				k=len-i-1;
				continue;
			}
			base=base*10+(s[i]-'0');
		}
		if(k!=0)
		{
			for(i=len-1;s[i]=='0';i--,k--)
				base=base/10;
			k=k*n;
		}
		cal(a,base,n);
		for(i=199;i>=0;i--)
		{
			if(a[i]!=0)
				break;
		}
		if(i<=k-1)
		{
			cout << '.';
			for(i=k-1;i>=0;i--)
				cout << a[i];
		}
		else
		{
			for(;i>=k;i--)
			{
				cout << a[i];
				lab=0;
			}
			if(k!=0)
				cout << '.';
			for(;i>=0;i--)
				cout << a[i];
		}
		cout << '\n';
	}
	return 0;
}
/*
import java.util.*;
import java.math.*;

public class Main{
    public static void main(String args[]) {
        BigDecimal r, mul;
        int n;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNextBigDecimal()) {
            r = cin.nextBigDecimal();
            mul = BigDecimal.ONE;
            n = cin.nextInt();
            for(int i = 0; i < n; i++) {
                mul = mul.multiply(r);
            }
            String str = mul.stripTrailingZeros().toPlainString();
            if (str.charAt(0) == '0')
                System.out.println(str.substring(1));
            else
                System.out.println(str);
        }
    }
}
*/
/*
#include<iostream>
using namespace std;
const int maxn=10000;
int h[maxn+1];
int m,n;
void mul(int h[],int k)
{
	int i;
	for(i=0;i<=maxn;i++)h[i]=h[i]*k;
	for(i=0;i<=maxn-1;i++)
	{
		h[i+1]+=h[i]/10;
		h[i]=h[i]%10;
	}
}
int main()
{
	int i,j,k,len,p;
	char s[maxn];
	while(scanf("%s%d",s,&n)==2)
	{
		m=j=0;
		len=strlen(s);
		for(i=0;i<maxn;i++)h[i]=0;
		h[0]=1;
		for(i=len-1;i>=0;i--)if(s[i]!='0')break;
		len=i+1;
		for(i=0;i<len;i++)
		{
			if(s[i]=='.')p=(len-1-i)*n;
			else m=m*10+s[i]-'0';
		}
		for(i=0;i<n;i++)mul(h,m);
		i=maxn;
		j=0;
		while(i>=0&&h[i]==0)i--;
		i=max(i,p-1);
		for(k=i;k>=0;k--)
		{
			if(k==p-1)printf(".%d",h[k]);
			else printf("%d",h[k]);
		}
		printf("\n");
	}
	return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
#include<math.h>
void reverse(char*str);
void multi(char*num1,char*num2,char*result);
char a[100]; 
char str[100];
char sum[200];
char tem[200];
char tem2[100];
int main()
{
    int flag;
    int n,i; 
    int key;
    int flag2;
    int kk;
    while(scanf("%s%d",a,&n)==2)
    {
        memset(str,0,sizeof(str));
        kk=0;
        flag=-1;
        flag2=6;
        int g=0;
        int j=0;
        int t = 0;
        if(a[0]=='.') { g=1;}
        for(int i = 0 ; i < 6 ; i++)
        {
            if(a[i]=='0'&&kk==0)continue;    
            kk=1;
            a[t++]=a[i];
        }
        a[t]='\0';
        
        if(a[0]=='.')
        {
            for(int i =strlen(a);i>=0;i--)
                a[i+1]=a[i];  
            a[0]='0';
        }
        {
            int i;
            for(i=0 ; i < strlen(a);i++ )
                if(a[i]=='.') break;
            if(i==strlen(a)) {a[i]='.';a[i+1]='0';a[i+2]='\0';}}
        for(i=0;i<strlen(a);i++)
            if(a[i]=='.') 
            {  
                flag=i;kk=1;
            }
            else 
            {
                if(a[i]=='0'&&flag!=-1&&flag2==strlen(a)) flag2=i;
                if(a[i]!='0'&&flag!=-1) flag2=strlen(a);
                str[j++]=a[i];      
            } 
        int ne=strlen(a)-flag-1;
        for(j = strlen(str)-1 ; j >= 0 ; j-- ){
            if(str[j] == '0'&&ne--){
                str[j]='\0';
            }    
            else  break;
        }
        flag=flag2-flag-1;
        if(g==1)
            printf(".");
        memset(sum,0,sizeof(sum));
        memset(tem,0,sizeof(tem));
        memset(tem2,0,sizeof(tem2));
        key=0;
        sum[0]='1';
        sum[1]='\0';    
        for(i=0; i < n ; i++)
        {     
            if(key!=1){ 
                key=1;
                strcpy(tem2,str);
                multi(sum,tem2,tem);
                memset(sum,0,sizeof(sum));
                memset(tem2,0,sizeof(tem2));
            }     
            else{
                strcpy(tem2,str);
                key=0;
                multi(tem,tem2,sum);
                memset(tem,0,sizeof(tem));
                memset(tem2,0,sizeof(tem2));
            }
        } 
        if(key==1)
        { 
            for(int i = 0 ; tem[i] != '\0' ; i++ )
            {
                if( tem[i] == '0' && i == 0 ) continue;
                if(i==strlen(tem)-(flag*n)&&g!=1) printf(".");
                printf("%c",tem[i]);
            }
        }
        else 
        {          
            for(int i = 0 ; sum[i] != '\0' ; i++ )
            {
                if( sum[i] == '0' && i == 0 ) continue;
                if(i==strlen(sum)-(flag*n)&&g!=1) printf(".");
                printf("%c",sum[i]);
            }
        }
        printf("\n");       
    }
    return 0;
}
void multi(char*num1,char*num2,char*result)
{
    int i,j,len1,len2,len;
    
    len1=strlen(num1);
    len2=strlen(num2);
    reverse(num2);
    reverse(num1);
    for (i=0;i<len1;i++)
        num1[i] -= '0';
    for (i=0;i<len2;i++)
        num2[i] -= '0';
    
    for (i=0;i<len2;i++)
        for (j=0;j<len1;j++)
        {
            len=i+j;
            result[len] += num2[i]*num1[j];
            result[len+1] += result[len]/10;
            result[len] %= 10;
        }
    len=len1+len2-1;
    for (i=0;i<len;i++)
        result[i] += '0';
    if (result[len]) result[len] += '0';
    reverse(result);
}
void reverse(char*str)
{
    int i;
    char c;
    for (i=0;i<strlen(str)/2;i++)
    {
        c=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=c;
    }
}*/
/*
 Description
 
 Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems. 
 
 This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
 Input
 
 The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6, and the n value will be in columns 8 and 9.
 Output
 
 The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if the result is an integer.
 Sample Input
 
 95.123 12
 0.4321 20
 5.1234 15
 6.7592  9
 98.999 10
 1.0100 12
 Sample Output
 
 548815620517731830194541.899025343415715973535967221869852721
 .00000005148554641076956121994511276767154838481760200726351203835429763013462401
 43992025569.928573701266488041146654993318703707511666295476720493953024
 29448126.764121021618164430206909037173276672
 90429072743629540498.107596019456651774561044010001
 1.126825030131969720661201
*/