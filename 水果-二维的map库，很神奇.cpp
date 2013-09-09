#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string ,map<string,int> >fset;
map<string ,map<string,int> >::iterator it;
map<string ,int>::const_iterator ip;
int main()
{
    bool flag=false;
    int M;
    scanf("%d",&M);
    while(M--)
    {
        int N;
        scanf("%d",&N);
        while(N--)
        {
            string s,t;
            int a;
            cin>>s>>t>>a;
            //水果名称，水果产地和交易的水果数目
            fset[t][s]+=a;
            //很神奇吧!像个二维数组.
        }
        if(flag)
            printf("\n");
        flag = true;
        for(it=fset.begin(); it!=fset.end(); it++)
        {
            cout<<it->first<<"\n";  //输出水果的产地
            for(ip=it->second.begin(); ip!=it->second.end(); ip++)
                cout<<"   |----"+ip->first<<"("<<ip->second<<")\n";
        }
        //第一次不输出空行,以后都输出空行,然后才输出结果;
        //这样就确保了最后的一个结果后面没有空行.
        fset.clear();
    }
    return 0;
}
/*
 Problem Description
 夏天来了~~好开心啊,呵呵,好多好多水果~~
 Joe经营着一个不大的水果店.他认为生存之道就是经营最受顾客欢迎的水果.现在他想要一份水果销售情况的明细表,这样Joe就可以很容易掌握所有水果的销售情况了.
 
 
 Input
 第一行正整数N(0<N<=10)表示有N组测试数据.
 每组测试数据的第一行是一个整数M(0<M<=100),表示工有M次成功的交易.其后有M行数据,每行表示一次交易,由水果名称(小写字母组成,长度不超过80),水果产地(小写字母组成,长度不超过80)和交易的水果数目(正整数,不超过100)组成.
 
 
 Output
 对于每一组测试数据,请你输出一份排版格式正确(请分析样本输出)的水果销售情况明细表.这份明细表包括所有水果的产地,名称和销售数目的信息.水果先按产地分类,产地按字母顺序排列;同一产地的水果按照名称排序,名称按字母顺序排序.
 两组测试数据之间有一个空行.最后一组测试数据之后没有空行.
 
 
 Sample Input
 1
 5
 apple shandong 3
 pineapple guangdong 1
 sugarcane guangdong 1
 pineapple guangdong 3
 pineapple guangdong 1
 
 
 Sample Output
 guangdong
 |----pineapple(5)
 |----sugarcane(1)
 shandong
 |----apple(3)
*/