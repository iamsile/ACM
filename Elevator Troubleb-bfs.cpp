#include <iostream>
#include <queue>
using namespace std;

int cnt,s,t,u,d,num,flag;
bool v[1000010];

struct node {
    int f,num;
};

bool judge(int k)
{
    if (k>=1&&k<=cnt)
        return 1;
    return 0;
}

void bfs()
{
    queue<node> q;
    node cur,nex;
    cur.f=s;
    cur.num=0;
    v[cur.f]=1;
    q.push(cur);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        if (cur.f==t) {
            printf("%d\n",cur.num);
            flag=1;
            return ;
        }
        nex.f=cur.f+u;
        nex.num=cur.num+1;
        if (!v[nex.f]&&judge(nex.f)) {
            v[nex.f]=1;
            q.push(nex);
        }
        nex.f=cur.f-d;
        nex.num=cur.num+1;
        if (!v[nex.f]&&judge(nex.f)) {
            v[nex.f]=1;
            q.push(nex);
        }
    }
}

int main()
{
    
    while (~scanf("%d%d%d%d%d",&cnt,&s,&t,&u,&d)) {
        int i;
        for (i=0; i<cnt; i++)
            v[i]=0;
        flag=0;
        bfs();
        if (!flag)
            printf("use the stairs\n");
    }
    return 0;
}
/*
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int f,s,g,u,d;
	while(cin>>f>>s>>g>>u>>d)
	{
		if(s>g)
		{
			s=f-s+1;
			g=f-g+1;
			swap(u,d);
		}
		int n=g-s;
		if(u==0)
		{
			cout<<"use the stairs"<<endl;
			continue;
		}
		int sum=0;
		int dum=0;
		int um=0;
		um=n%u;
		sum=n/u;
		if(um==0)
		{
			cout<<sum<<endl;
			continue;
		}
		um+=d;
		int i=1;
		while(um<f)
		{
			if(um%u==0)
			{
				cout<<sum+i+um/u<<endl;
				break;
			}
			i++;
			um+=d;
		}
		if(um>=f)
			cout<<"use the stairs"<<endl;
	}
	return 0;
}
*/
/*
 Problem description
 You are on your way to your rst job interview as a program tester, and you are already late. The interview is in a skyscraper and you are currently in floor s, where you see an elevator. Upon entering the elvator, you learn that it has only two buttons, marked "UP u" and "DOWN d". You conclude that the UP-button takes the elevator u floors up (if there aren't enough floors, pressing the UP-botton does nothing, or at least so you assume), whereas the DOWN-button takes you d stories down (or none if there aren't enough). Knowing that the interview is at floor g, and that there are only f floors in the building, you quickly decide to write a program that gives you the amount of button pushes you need to perform. If you simply cannot reach the correct floor, your program halts with the message "use the stairs".
 Given input f, s, g, u and d (floors, start, goal, up, down), find the shortest sequence of button presses you must press in order to get from s to g, given a building of f floors, or output "use the stairs" if you cannot get from s to g by the given elevator.
 
 Input
 The input will consist of one line, namely f s g u d, where 1 <= s, g <=f <= 1000000 and 0 <= u, d <= 1000000. The oors are one-indexed, i.e. if there are 10 stories, s and g be in [1, 10].
 
 Output
 You must reply with the minimum numbers of pushes you must make in order to get from s to g, or output use the stairs if it is impossible given the conguration of the elvator
 
 Sample Input
 10 1 10 2 1
 100 2 1 1 0
 Sample Output
 6
 use the stairs
*/