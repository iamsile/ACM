#include <iostream>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		long int n,f,b,x,y,i,j,t,sum,a[1001]={0};
		cin >> n >> f >> b;
		for(i=0;i<n;i++)
		{
			cin >> x >> y;
			if(y==1)
				a[i]=3*f-x;//如果有箱子的人则先上去再下来再上去，完成第一次搬箱的时间记录下来放到a中
			else 
				a[i]=f+x;//如果没有箱子的人则先下来再上去，完成第一次搬箱的时间记录下来放到a中
		}
		sort(a,a+n);//再将搬一次所需的时间进行从小到大快排，这样最后一个就是最迟搬箱的那个人，
		//最前的就是每次都是第一个搬箱的那个人
		j=b%n;//用来判断b是否能被n整除
		t=b/n;//计算b是n的多少倍
		if(j==0)////若正好整除，则按照那个走的最慢的那个人来计算，也就是a[n-1]；求出time(t倍数)，
		//若为1倍说明只要n个人都完成一次搬运就行了，也就是a[n-1]的时间；若为2倍说明只要n个人都完成两次搬运就行了，
		//也按最慢的那个人进行计算，把搬一次最慢所需时间+剩下的几趟所用时间就行了，即a[n-1]+2*f*(time-1);
		//若为0倍说明只要有箱子的人把箱子运到最上就行了，这种情况依然符合这条公式，不信大家可以验证下
			sum=a[n-1]+2*f*(t-1);
		else //若不整除,则要根据余数来判断谁是这个状态下最慢的那个人；假如n=3,b=2,则left=b%n=2,
		//说明只要跑的快的两个人把箱子搬上去就行了，所以这种状态下其实最慢的是第2个人，由于数组从0开始，
		//所以这时最慢的时间应该是a[left-1],只要这个人跑到了就是总的时间；假如n=3,b=5,则left=b%n=2,
		//和上面一样，这种状态下其实最慢的还是第2个人，他运完一次所需时间为a[left-1]，
		//再加上后面几趟的时间2*f*time，就得他的总时间了。其他情况也可依此类推。
			sum=a[j-1]+2*f*t;
		cout << sum << '\n';
		
	}
	return 0;
}
//这题看起来有很多人在传东西，其实可以把每个人都看成独立的个体，这样分析就简单多了
/*
 Problem description
 John is moving to the penthouse of a tall sky-scraper. He packed all his stuff in boxes and drove them to the entrance of the building on the ground floor. Unfortunately the elevator is out of order, so the boxes have to be moved up the stairs. 
 Luckily John has a lot of friends that want to help carrying his boxes up. They all walk the stairway at the same speed of 1 floor per minute, regardless of whether they carry a box or not. The stairway however is so narrow that two persons can't pass each other on it. Therefore they deciced to do the following: someone with a box in his hands is always moving up and someone empty-handed is always moving down. When two persons meet each other somewhere on the stairway, the lower one (with a box) hands it over to the higher one (without a box). (And then the lower one walks down again and the higher one walks up.) The box exchange is instantaneous. When someone is back on the ground floor, he picks up a box and starts walking up. When someone is at the penthouse, he drops the box and walks down again. 
 
 After a while the persons are scattered across the stairway, some of them with boxes in their hands and some without. There are still a number of boxes on the ground floor and John is wondering how much more time it will take before all the boxes are up. Help him to find out!
 
 
 Input
 One line with a positive number: the number of test cases. Then for each test case: 
 One line with three numbers N, F, B with 1 ≤ N,F ≤ 1000 and 1 ≤ B ≤ 1000000: the number of persons, the number of floors (0=ground floor, F=penthouse) and the number of boxes that are still on the ground floor. 
 N lines with two numbers fi and bi with 0 ≤ fi ≤ F and bi = 0 or bi = 1: the floors where the persons are initially and whether or not they have a box in their hands (1=box, 0=no box).
 
 
 Output
 One line with the amount of time (in minutes) it will take to get all the remaining boxes to the penthouse. 
 
 Sample Input
 2
 3 10 5
 0 0
 0 0
 0 0
 2 5 1
 2 1
 3 0
 Sample Output
 30
 8
*/