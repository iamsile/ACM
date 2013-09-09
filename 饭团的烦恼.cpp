#include <iostream> 
#include <string.h> 
#include <math.h> 
using namespace::std;

const int N=17; 

int main() 
{ 
	int i,a,b,c,d,x,best=-10000,rec=-1,nc,need,np,hun[17],la[17],su[17],dan[17],p[17],sum[4]; 
	char name[17][100]; 
	cin >> nc >> need >> np; 
	for(i=0;i<nc;i++)
	{ 
		scanf("%s %d %d %d",&name[i],&p[i],&hun[i],&la[i]); 
		su[i]=1-hun[i]; 
		dan[i]=1-la[i]; 
	} 
	cin >> a >> b >> c >> d;
	for(x=0;x<(1<<nc);++x) 
	{ 
		memset(sum, 0, sizeof(sum)); 
		int price=0,cnt=0; 
		for(i=0;i<nc;++i) 
			if((x&(1<<i))!=0) 
			{ 
				cnt++; 
				price+=p[i]; 
			} 
		if(cnt!=need||abs(price-np*15)>=abs(best-np*15)) 
			continue; 
		for(i=0;i<nc;++i) 
			if((x&(1<<i))!=0) 
			{ 
				sum[0]+=hun[i]; 
				sum[1]+=su[i]; 
				sum[2]+=la[i]; 
				sum[3]+=dan[i]; 
			}
		if(sum[0]==a&&sum[1]==b&&sum[2]==c&&sum[3]==d)
		{
			best=price; 
			rec=x; 
		}
	} 
	for(i=0;i<nc;i++) 
		if((rec&(1<<i))!=0) 
			puts(name[i]); 
	printf("%.2lf\n",0.8*best/np); 
	return 0; 
} 
/*
 Problem description
 “午餐饭团”是百度内部参与人数最多的民间组织。
 同一个部门的、同一所大学的、同一年出生的、使用同一种型号电脑的员工们总是以各种理由组织各种长期的、临时的饭团。
 参加饭团，不仅可以以优惠的价格尝到更加丰富的菜式，还可以在吃饭的时候和同事们增进感情。
 但是，随着百度的员工越来越多，各个饭团的管理变得繁杂起来。特别是为了照顾员工们越来越挑剔的胃，饭团的点菜负责人的压力也越来越大。现在，这个任务就交给“百度之星”了，因为，你将要为所有的百度饭团设计一个自动点菜的算法。
 饭团点菜的需求如下：
 1．经济是我们要考虑的一个因素，既要充分利用百度员工的午餐补助，又不能铺张浪费。因此，我们希望最后的人均费用越接近12元越好。
 2．菜式丰富是我们要考虑的另一个因素。为简单起见，我们将各种菜肴的属性归结为荤菜，素菜，辛辣，清淡，并且每个菜只能点一次。
 3．请谨记，百度饭团在各大餐馆享受8折优惠。
 
 
 Input
 1．输入数据第一行包含三个整数N，M，K(0<N<=16，0<M<=N，0<K<=12)，分别表示菜单上菜的数目，饭团需要点的菜的数目，就餐的人数；
 2．紧接着N行，每行的格式如下：
 菜名（长度不超过20个字符） 价格（原价，整数） 是否荤菜（1表示是，0表示否） 是否辛辣（1表示是，0表示否）；
 3．第N+2行是 a b c d 四个整数，分别表示需要点的荤菜，素菜，辛辣，清淡菜的数目。
 
 Output
 对于每组测试数据，输出数据包含M+1行，前M行每行包含一个菜名（按菜名在原菜单的顺序排序）。第M+1行是人均消费，结果保留两位小数。
 
 Sample Input
 3 2 2
 水煮鱼 30 1 1
 口水鸡 18 1 1
 清炖豆腐 12 0 0
 1 1 1 1
 Sample Output
 口水鸡
 清炖豆腐
 12.00
*/