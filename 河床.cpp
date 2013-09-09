#include <iostream>
using namespace std;

int main()
{
    long n,k,a[30010];
    while(cin>>n>>k)
    {
        if (n==0&&k==0)
            return 0;
        long i,j,flag=0,lab=1;
        for(i=0;i<n;i++)
            cin >> a[i];
        for(i=0;i<n;i++)
        {
            long max=a[i],min=a[i];
            for(j=i;j<n;j++)
            {
                if(lab>n-i)
                    break;
                if(a[j]>max)
                    max=a[j];
                if(a[j]<min)
                    min=a[j];
                if(max-min>k)
                {
                    flag=j-i;
                    break;
                }
                if(j==n-1)
                    flag=j-i+1;
            }
            if(flag>lab)
                lab=flag;
        }
        cout << lab << '\n';
    }
    return 0;
}
/*
 地理学家对一段河床进行测量分析。他们从上游到下游等距离的选择了n(<=30000)个水位点深度。 得到一组数据d1，d2...dn，且都是非负整数(di<=32767)。回到试验室后数据分析员根据需要对数据进行分析，发觉隐藏在数据背后的规律。最近，Dr.Sun 发现某种水文现象与河床地势有关，于是他指示分析员找出一段河流中最大高低起伏差不超过k(k<=100)的最长一段。
 
 Input
 
 输入包含多个case 每个case的第一行为整数n和k 每个case第二行有n个数，为d1,d2,...dn 当n = m = 0时代表输入的结束
 
 Output
 
 每一行输出起伏不超过k的河流最长长度。
 
 Input
 
 6 2
 10 7 6 5 6 7
 0 0
 Output
 
 5
*/