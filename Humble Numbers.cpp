#include<iostream>  
using namespace std;  

int Min(int a ,int b)  
{  
    return a<b?a:b;  
}  

int main()  
{    
    int i,j,k,l;  
    i=j=k=l=1;       //用来控制2，3，5，7应乘以那个数的  
    int a[5843];  
    memset(a,0,sizeof(a));  
    a[0]=1;  
    for(int m=1;m<=5842;m++)  
    {  
        int num1=a[i-1]*2;  
        int num2=a[j-1]*3;  
        int num3=a[k-1]*5;  
        int num4=a[l-1]*7;  
        int min=Min(Min(num1,num2),Min(num3,num4));  
        a[m]=min;  
        //当2，3，5，7中的一个数相乘得到的数是最小的，那相应就要乘以数组后面的  
        //数，以免重复，i,j,k,l就是控制往下走  
        if(num1==min) 
			i++;  
        if(num2==min) 
			j++;  
        if(num3==min) 
			k++;  
        if(num4==min) 
			l++;  
		
    }  
    int n;  
    while(cin>>n&&n)  
    {  
        //按题意对输出格式的控制  
        if(n%10==1&&n%100!=11)   
            cout<<"The "<<n<<"st humble number is "<<a[n-1]<<'.'<<endl;  
        else if(n%10==2&&n%100!=12)   
            cout<<"The "<<n<<"nd humble number is "<<a[n-1]<<'.'<<endl;  
        else if(n%10==3&&n%100!=13)   
            cout<<"The "<<n<<"rd humble number is "<<a[n-1]<<'.'<<endl;  
        else   
            cout<<"The "<<n<<"th humble number is "<<a[n-1]<<'.'<<endl;    
    }  
    return 0;  
} 
/*
解题思路：不断找出最小的值，然后插进去，主要是关系到是用2,3,5,7去乘，当其中的一个得到的是最小的，
 那么它相对应后面乘的时候就要往数组后面移一位，使其不会一直重复，保证了数据的正确性，看代码更易懂。
*/
/*
 Problem description
 A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers. 
 
 Write a program to find and print the nth element in this sequence. 
 
 
 Input
 The input consists of one or more test cases. Each test case consists of one integer n with 1 <= n <= 5842. Input is terminated by a value of zero (0) for n. 
 
 Output
 For each test case, print one line saying "The nth humble number is number.". Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" for the ordinal number nth has to be used like it is shown in the sample output.
 
 Sample Input
 1
 2
 3
 4
 11
 12
 13
 21
 22
 23
 100
 1000
 5842
 0
 
 Sample Output
 The 1st humble number is 1.
 The 2nd humble number is 2.
 The 3rd humble number is 3.
 The 4th humble number is 4.
 The 11th humble number is 12.
 The 12th humble number is 14.
 The 13th humble number is 15.
 The 21st humble number is 28.
 The 22nd humble number is 30.
 The 23rd humble number is 32.
 The 100th humble number is 450.
 The 1000th humble number is 385875.
 The 5842nd humble number is 2000000000.
*/