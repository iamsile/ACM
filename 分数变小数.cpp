#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        int k,j,i=1,flag=0,l=0,a[1001]={n},lab=0,b[1001];
        if (n>m) {
            cout << a[0]/m;
            a[0]%=m;
        }
        cout << '.';
        while (1) {
            k=a[i-1]*10/m;
            a[i]=a[i-1]*10%m;
            b[l++]=k;
            if (a[i]==0) {
                lab=2;
                break;
            }
            for (j=0; j<i; j++)
                if (a[j]==a[i]) {
                    lab=1;
                    flag=j;
                    break;
                }
            if (lab==1||lab==2)
                break;
            i++;
        }
        for (i=0; i<l; i++) {
            if (flag==i&&lab==1)
                cout << '(';
            cout << b[i];
        }
        if (lab==1)
            cout << ")\n";
        else cout << '\n';
    }
    return 0;
}
/*
写出一个程序，接受一个以N/D 的形式输入的分数，其中N为分子，D为分母，输出它的小数形式。如果它的
小数形式存在循环节，要将其用括号括起来。例如：1/3=.33333...表示为.(3)，又如41/333=.123123123...
表示为.(123)。
一些转化的例子：
1/3=.(3)
22/5=4.4
1/7=.(142857)
3/8=.375
45/56=.803(571428)
11/59=.(1864406779661016949152542372881355932203389830508474576271)

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc,char **args)
{/*
  //test "find" function
  vector<int> vec;
  for(vector<int>::size_type i=0;i<10;i++)
  vec.push_back(i);
  cout<<(find(vec.begin(),vec.end(),9)==(vec.end()-1))<<endl;
  
    int N,D,zheng,yu;
    cout<<45.0/56<<endl;
    
    while(cin>>N>>D){
        vector<int> yuShu,xiaoShu;//yuShu容器用来存放做除运算中产生的余数 xiaoShu容器用来同步存放做除运算后的小数
        zheng=N/D;//整数
        yu=N%D;//余数    
        
        /*
         结束循环的条件是要么余数为0（被整除） 要么出现循环节
         
        
        do{        
            yu*=10;
            for(int i=0;i<100;i++)
            {
                if(yu>D)
                    break;
                //下面是补0仍没有b大的情况
                
                yuShu.push_back(yu);
                xiaoShu.push_back(0);
                yu*=10;
            }
            //如果有循环节出现的话 到最后后面的一位是多出来的
            yuShu.push_back(yu%D);
            xiaoShu.push_back(yu/D);
            yu=yu%D;
        }while(yu!=0&&find(yuShu.begin(),yuShu.end(),yu)==(yuShu.end()-1));
        if(yu==0)
        {//整除情况
            if(zheng==0)
                ;
            else
                cout<<zheng;
            cout<<".";
            for(vector<int>::size_type i=0;i<xiaoShu.size();i++)
                cout<<xiaoShu[i];
            cout<<endl;            
        }else 
        {//出现循环节的情况
            if(zheng==0)
                ;
            else
                cout<<zheng;
            cout<<".";
            vector<int>::size_type count=0;//用来记录循环节出现的位置 完全可以放到循环里面 不过那样循环就有点乱了 故放在此
            for(vector<int>::size_type i=0;i<yuShu.size();i++)
                if(yu==yuShu[i])
                {
                    count=i;//找到循环节出现的地方
                    break;
                }
            for(vector<int>::size_type i=0;i<xiaoShu.size()-1;i++)
            {
                if(i==count){
                    if(count==0)//循环节紧贴小数点后面
                        cout<<"(";
                    else{//循环节是后来出现的 比如45/56=.803(571428)
                        cout<<xiaoShu[i]<<"(";continue;
                    }
                }                
                cout<<xiaoShu[i];
            }
            if(count==0)
                cout<<")"<<endl;
            else
                cout<<xiaoShu[xiaoShu.size()-1]<<")"<<endl;
        }
    }
    return 0;
}
*/
/*
 Problem description
 
 写出一个程序，接受一个以N/D的形式输入的分数，其中N为分子，D为分母，输出它的小数形式。如果它的小数形式存在循环 节，要将其用括号括起来。例如：1/3=.00000...表示为.(3)。 
 
 Input
 
 第一行输入一个整数表示分数的个数K，接下来K行，每一行包含两个整数，N和D，1<=N,D<=65535。 
 
 Output
 
 每一行分数输出转换的小数，运算结果小数点后最多保留100位。
 
 Sample Input
 2
 1 3
 22 4
 Sample Output
 .(3)
 5.5
*/