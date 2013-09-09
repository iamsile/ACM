#include<iostream>
using namespace::std;

int main() 
{ 
	
    int i,j,k,g=0,n=0,m=0,t=0,count,num; 
    int a[2001]; 
    cin >> num;
    cin >> count; 
    for(i=0;i<count;i++) 
		cin >> a[i];
    a[count]=32767; 
    for(i=0,j=1;i<=num;) 
    { 
        if(a[n]<=m) 
        { 
            k=a[n]+j-1; 
            if((m%2==0&&a[n]%2==0)||(m%2!=0&&a[n]%2!=0)) 
				for(g=n+1;k>=a[g];g++) 
					if(k==a[g])
						t++; 
            if(a[n-1]>m-j+2&&a[n-1]+1==a[n])
				t++; 
            n++; 
        } 
        else 
        {   m+=j; 
            i++; 
            j+=2; 
        } 
    } 
	cout << count*3-2*t << '\n'; 
    return 0; 
}//t在这里是代表两个病毒间，相邻的边，最后用总的边数减去两病毒间相邻边数的总和就是最后所有的边数
/*
 Problem description
 某实验室在一种正三角型的实验器皿中进行一种特殊的病毒繁殖实验，此器皿分成很多正三角形形状的小格，每个格子的边长为1。按从上到下，从左到右的顺序对所有格子进行编号。已知在某些格子中含有病毒，为了不让这些病毒无限制的扩散，必须将有病毒的这些格子圈起来。请你编程需求出圈住这些格子所需要的材料长度。
 
 Input
 输入文件第一行为大三角形中小格子的行数N (1≤N≤100) 
 输入文件第二行为含有病毒的三角形的个数M (1≤M≤2000) 
 以下M行分别为含有病毒的小格编号，此编号按从小到大排序 
 
 
 Output
 输出文件仅一行，为圈住这些格子的边长。
 
 Sample Input
 4 
 8 
 3 
 4 
 6 
 7 
 8 
 11 
 14 
 15 
 Sample Output
 14 
*/