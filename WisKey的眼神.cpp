#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a,int b)
{
    return b?gcd(b, a%b):a;
}

int main()
{
    int l;
    while (scanf("%d",&l)&&l) {
        int sx,sy,ex,ey;
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        if (abs(ex)>l||abs(ey)>l)
            puts("Out Of Range");
        else {
            ex-=sx;
            ey-=sy;
            if (gcd(abs(ex),abs(ey))==1)
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
/*
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main()
{
    double l,x1,x2,p1,p2,y,k,f;
    while(scanf("%lf",&l))
    {
        if(l==0)  break;
        scanf("%lf%lf%lf%lf",&x1,&x2,&p1,&p2);
        if(fabs(x1)>l||fabs(x2)>l||fabs(p1)>l||fabs(p2)>l)
        {
            printf("Out Of Range\n");
            continue;
        }
        
        if(x1==p1)
        {
            if(fabs(fabs(x2)-fabs(p2))==1)
            {
                printf("Yes\n");continue;
            }
            else
            {
                printf("No\n");;continue;
            }
        }
        if(x1>p1)
        {
            swap(x1,p1);swap(x2,p2);
        }
        k=(p2-x2)/(p1-x1);f=0;
        for(int i=x1+1;i<p1;i++)
        {
            y=k*(i-x1)+x2;
            if(int(y)==y)
            {
                printf("No\n");;f=1;break;
            }
        }
        if(f==0)  printf("Yes\n");
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int l,x1,y1,x2,y2;
    while(scanf("%d",&l))//>>l)
    {
        if(l==0)
            break;
        else
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);//cin>>x1>>y1>>x2>>y2;
        
        if(abs(x2)>l||abs(y2)>l)
        {
            printf("Out Of Range\n");//cout<<"Out Of Range"<<endl;            
        }
        else if(x1==x2)
        {
            if(abs(y1-y2)>1)
                printf("No\n");//cout<<"No"<<endl;
            else
                printf("Yes\n");//cout<<"Yes"<<endl;     
        }                              
        else
        {
            int Y,i,j;
            double dy;
            bool yes=1;
            for(i=min(x1,x2)+1;i<max(x1,x2);i++)
            {
                if(yes)
                {
                    dy=double(y1)+double((i-x1)*(y2-y1))/double(x2-x1);
                    Y=dy;
                    for(j=-1;j<=1;j++)
                    {
                        if(abs(Y+j)>l)
                            continue;
                        if((i-x1)*(y2-y1)==(Y+j-y1)*(x2-x1))
                        {
                            yes=0;
                            break;                    
                        }                  
                    }       
                }                   
            }    
            if(yes)
                printf("Yes\n");
            else
                printf("No\n");
        }   
    }    
}
*/
/*
 Problem Description
 WisKey的眼镜有500多度,所以眼神不大好,而且他有个习惯,就是走路喜欢看着地(不是为了拣钱哦^_^),所以大家下次碰见他的时候最好主动打下招呼,呵呵.
 但是Rabbit总是喜欢扮神秘,一天WisKey去食堂排队等着买饭,突然收到一道短消息,是Rabbit发的,”呵呵,又看见你了,你没看到我吧”.WisKey马上拉长脖子扫描食堂,可是就是看不到,再发短信问Rabbit在哪,Rabbit回信曰”我已经在寝室了”.WisKey无语....
 假设食堂是个正方形,食堂中心坐标为(0,0),长度为2*L, WisKey保证在食堂内.
 因为是吃饭高峰期,所以每个点上都站着人,当某些人处在同一直线上时就有可能被前面的人挡住.
 聪明的ACMer请你帮帮WisKey,告诉他能不能看见Rabbit.
 
 Input
 输入L,sx,sy,px,py; L<=1000,sx,sy是WisKey的坐标,px,py是Rabbit的坐标.
 以L=0为结束.
 Output
 对于每组输入数据，能看见输出”Yes”,看不见输出”No”.
 Rabbit不在食堂输出”Out Of Range”.
 Sample Input
 5 0 0 1 1
 5 0 0 2 0
 5 0 0 6 6
 5 0 0 -1 -1
 0
 Sample Output
 Yes
 No
 Out Of Range
 Yes
*/