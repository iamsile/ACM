#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d\n",&t);
    while (t--) {
        char a[20];
        gets(a);
        int i,j,flag=15,len=0,k=strlen(a),b[20]={0},maxn=0,minn=0,lab;
        for (i=0,j=0; i<k; i++)
            if (a[i]==' ') {
                b[len++]=j;
                j=0;
            }
            else j=a[i]-'0';
        b[len++]=j;
        sort(b, b+len);
        if (len%2) {
            if (!b[0])
                swap(b[0], b[1]);
            for (i=0; i<=len/2; i++)
                maxn=maxn*10+b[i];
            for (i=len-1; i>len/2; i--)
                minn=minn*10+b[i];
        }
        else {
            for (i=(len-1)/2,j=(len-1)/2+1; i>=0; i--,j++) {
                if (flag>b[i+1]-b[i])
                    if (b[i]) {
                        flag=b[i+1]-b[i];
                        lab=i;
                    }
                if (flag>b[j]-b[j-1]) {
                    flag=b[j]-b[j-1];
                    lab=j-1;
                }
            }
            maxn=b[lab+1];b[lab+1]=-1;
            minn=b[lab];b[lab]=-1;
            for (i=0,k=len/2-1; k;i++)
                if (b[i]!=-1) {
                    maxn=maxn*10+b[i];
                    b[i]=-1;
                    k--;
                }
            for (i=len-1,k=len/2-1; k; i--)
                if (b[i]!=-1) {
                    minn=minn*10+b[i];
                    k--;
                }
        }
        printf("%d\n",maxn-minn);
    }
    return 0;
}
/*
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <queue>
using namespace std;
int pow10[]={1,10,100,1000,10000,100000};
int n,digits[10];

typedef pair<int,int> P;

struct State{
	int a,b;
	int used;
	int max_dist;
	int min_dist;
	int k;
	State(int a,int b,int used,int k):a(a),b(b),used(used),k(k){
		max_dist=(a-b)*pow10[k]+pow10[k]-1;
		min_dist=(a-b)*pow10[k]+1-pow10[k];
	}
};
bool operator<(const State &a,const State &b){
	return a.min_dist>b.min_dist;
}
int solve(){
	int ans=9999999;
	priority_queue<State> que;
	set<P> ac;
	if(digits[n-1]!=0){
		for(int i=0;i<n;i++){
			if(digits[i]==0)
                continue;
			for(int j=i+1;j<n;j++){
				que.push(State(digits[j],digits[i],(1<<i)|(1<<j),n/2-1));
			}
		}
	}else{
		for(int i=0;i<n-1;i++){
			if(digits[i]==0)
                continue;
			que.push(State(digits[i],digits[n-1],(1<<(n-1)|(1<<i)),n/2-1));
		}
	}
	while(!que.empty()){
		State now=que.top();
        que.pop();
		if(ans<now.min_dist)
            break;
		ans=min(ans,now.max_dist);
		if(now.used==(1<<n)-1)
            continue;
		for(int i=0;i<n;i++){
			if((now.used>>i)&1)
                continue;
			for(int j=0;j<n;j++){
				if(i==j)
                    continue;
				if((now.used>>j)&1)
                    continue;
				int na=now.a*10+digits[i];
				int nb=now.b*10+digits[j];
				if(ac.find(P(na,nb))==ac.end()){
					ac.insert(P(na,nb));
					que.push(State(na,nb,now.used|(1<<i)|(1<<j),now.k-1));
				}
			}
		}
	}
	return ans;
}
int dfs(int x=-1,int y=-1,int used=0){
	if(used==(1<<n)-1&&x!=-1&&y!=-1) {
		return abs(x-y);
	}
    
	int ans=99999999;
	for(int i=0;i<n;i++){
		if(((used>>i)&1)==0){
			if(x==-1)
                ans=min(ans,dfs(digits[i],y,used|(1<<i)));
			if(y==-1)
                ans=min(ans,dfs(x,digits[i],used|(1<<i)));
			if(x>0)
                ans=min(ans,dfs(x*10+digits[i],y,used|(1<<i)));
			if(y>0)
                ans=min(ans,dfs(x,y*10+digits[i],used|(1<<i)));
		}
	}
	return ans;
}
int main() {
	int tcase;
	string in;
	getline(cin,in);
	tcase=atoi(in.c_str());
	for(int T=0;T<tcase;T++){
		n=0;getline(cin,in);
		stringstream ss(in);
		while(ss>>digits[n])n++;
		if(n<5){
			cout<<dfs()<<endl;
		}else{
			if(n&1)digits[n++]=0;
			cout<<solve()<<endl;
		}
	}
	return 0;
}
*/
/*
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char str[25];
	char fuckyou[1];
	int a[10];
	int n,i,j;
	int a1,a2;
	while(cin>>n)
	{
		gets(fuckyou);
		while(n--)
		{
			memset(a,-1,sizeof(a));
			memset(str,0,sizeof(a));
			gets(str);
			for(i=0;str[i]>='0'&&str[i]<='9';i+=2)
				a[i/2]=str[i]-'0';
			int s=(i-2)/2;
			sort(a,a+s+1);
			int min=12,mini;
			if(s%2==0)
			{
				if(a[0]==0)
					swap(a[0],a[1]);
				min=a[0];
				mini=-1;
			}
			else
			{
				for(i=s/2,j=s/2+1;i>=0;i--,j++)
				{
					if(min>a[i+1]-a[i])
					{
						if(a[i]!=0)
						{
							min=a[i+1]-a[i];
							mini=i;
						}
					}
					if(min>a[j]-a[j-1])
					{
						min=a[j]-a[j-1];
						mini=j-1;
					}
				}
			}
			a1=a[mini+1];
			if(mini==-1)
				a2=0;
			else
				a2=a[mini];
			for(i=0,j=s;1;i++,j--)
			{
				if(i==mini)
					i+=2;
				if(i==mini+1)
					i++;
				if(j==mini+1)
					j-=2;
				if(i>=j)
					break;
				a1=a1*10+a[i];
				a2=a2*10+a[j];
			}
			cout<<a1-a2<<endl;
		}
	}
	return 0;
}
*/
/*
 Problem description
 Given a number of distinct decimal digits, you can form one integer by choosing a non-empty subset of these digits and writing them in some order. The remaining digits can be written down in some order to form a second integer. Unless the resulting integer is 0, the integer may not start with the digit 0. For example, if you are given the digits 0, 1, 2, 4, 6 and 7, you can write the pair of integers 10 and 2467. Of course, there are many ways to form such pairs of integers: 210 and 764, 204 and 176, etc. The absolute value of the difference between the integers in the last pair is 28, and it turns out that no other pair formed by the rules above can achieve a smaller difference.
 
 Input
 The first line of input contains the number of cases to follow. For each case, there is one line of input containing at least two but no more than 10 decimal digits. (The decimal digits are 0, 1, ..., 9.) No digit appears more than once in one line of the input. The digits will appear in increasing order, separated by exactly one blank space.
 
 Output
 For each test case, write on a single line the smallest absolute difference of two integers that can be written from the given digits as described by the rules above.
 
 Sample Input
 1
 0 1 2 4 6 7
 Sample Output
 28
*/