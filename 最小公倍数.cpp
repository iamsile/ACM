#include <iostream>
#define M 1000000
using namespace std;

int main(){
    __int64 a,b;
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        __int64 s,m,k;
        if(a>b){ s=b; m=a;}
        else{s=a; m=b;}
        
        for(__int64 i=s;i<=M;i++){
            if(i%m==0 && i%s==0){
                k=i;
                break;
            }
        }
        printf("%I64d\n",k);
	}
    return 0;
}
/*
 Problem Description
 给定两个正整数，计算这两个数的最小公倍数。
 
 
 Input
 输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数.
 
 
 Output
 对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。
 
 
 Sample Input
 10 14
 
 
 Sample Output
 70
*/