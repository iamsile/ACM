#include <iostream>
using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int n;
    while (cin >> n&&n) {
        int i,j,k,m,lab,sum,a[1010],b[1010];
        for (i=0; i<n; i++)
            cin >> a[i];
        for (i=0; i<n; i++)
            cin >> b[i];
        qsort(a, n, sizeof(a[0]), cmp);
        qsort(b, n, sizeof(b[0]), cmp);
        for (i=0; i<n; i++)
            if (a[0]>=b[i])
                break;
        lab=i;
        sum=-200*n;
        for (i=lab; i<n; i++) {
            m=-200*i;
            for (j=i,k=0; j<n; j++,k++) {
                if (a[k]>b[j])
                    m+=200;
                else if (a[k]<b[j])
                    m-=200;
            }
            if (m>sum)
                sum=m;
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int i,j,k,s,x,n,t[1000],q[1000];
    while (scanf("%d",&n),n)
    {
        for (i=0;i<n;i++)
            scanf("%d",&t[i]);
        for (i=0;i<n;i++)
            scanf("%d",&q[i]);
        
        qsort(t,n,sizeof(t[0]),cmp);
        qsort(q,n,sizeof(q[0]),cmp);
        
        for (i=0;i<n;i++)
        {
            if(t[0] >= q[i]) break;
        }
        
        for (s=-200*n;i<n;i++)
        {
            x=-i*200;
            for (j=i,k=0;j<n;j++,k++)
            {
                if (t[k]>q[j])
                    x+=200;
                else if (t[k]<q[j])
                    x-=200;
            }
            if (x>s)
                s=x;
        }
        printf("%d\n",s);
    }
    return 0;
}

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    
    while(cin>>n,n)
    {
        list<long long> T,K;
        long long tmp;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            T.push_back(tmp);
        }   
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            K.push_back(tmp);
        }
        T.sort();
        K.sort(); 
        int cnt = 0;
        
        
        while(!T.empty())
        {
            list<long long>::iterator it1 = T.end(),it2 = K.end();
            it1--;
            it2--;
            if(*it1>*it2)
            {
                cnt+=200;
                T.erase(it1);
                K.erase(it2);
            }
            else if(*it1==*it2)
            {
                if(*(T.begin())>*(K.begin()))
                {
                    cnt+=200;
                    T.erase(T.begin());
                    K.erase(K.begin());
                }
                else if(*(T.begin())==*(K.begin()))
                {
                    if(*(T.begin())==*it2)
                    {}else
                    {
                        cnt-=200;
                    }
                    T.erase(T.begin());
                    K.erase(it2);
                }
                else
                {
                    if(*(T.begin())==*it2)
                    {}else
                    {
                        cnt-=200;
                    }
                    T.erase(T.begin());
                    K.erase(it2);
                }
            }
            else 
            {
                cnt-=200;
                T.erase(T.begin());
                K.erase(it2);
            }
        }
        
        cout<<cnt<<endl;
    }
    return 0;
}

 Problem description
 Here is a famous story in Chinese history. 
 That was about 2300 years ago. General Tian Ji was a high official in the country Qi. He likes to play horse racing with the king and others. 
 
 Both of Tian and the king have three horses in different classes, namely, regular, plus, and super. The rule is to have three rounds in a match; each of the horses must be used in one round. The winner of a single round takes two hundred silver dollars from the loser. 
 
 Being the most powerful man in the country, the king has so nice horses that in each class his horse is better than Tian's. As a result, each time the king takes six hundred silver dollars from Tian. 
 
 Tian Ji was not happy about that, until he met Sun Bin, one of the most famous generals in Chinese history. Using a little trick due to Sun, Tian Ji brought home two hundred silver dollars and such a grace in the next match. 
 
 It was a rather simple trick. Using his regular class horse race against the super class from the king, they will certainly lose that round. But then his plus beat the king's regular, and his super beat the king's plus. What a simple trick. And how do you think of Tian Ji, the high ranked official in China? 
 
 
 Were Tian Ji lives in nowadays, he will certainly laugh at himself. Even more, were he sitting in the ACM contest right now, he may discover that the horse racing problem can be simply viewed as finding the maximum matching in a bipartite graph. Draw Tian's horses on one side, and the king's horses on the other. Whenever one of Tian's horses can beat one from the king, we draw an edge between them, meaning we wish to establish this pair. Then, the problem of winning as many rounds as possible is just to find the maximum matching in this graph. If there are ties, the problem becomes more complicated, he needs to assign weights 0, 1, or -1 to all the possible edges, and find a maximum weighted perfect matching... 
 
 However, the horse racing problem is a very special case of bipartite matching. The graph is decided by the speed of the horses -- a vertex of higher speed always beat a vertex of lower speed. In this case, the weighted bipartite matching algorithm is a too advanced tool to deal with the problem. 
 
 In this problem, you are asked to write a program to solve this special case of matching problem. 
 
 Input
 The input consists of up to 50 test cases. Each case starts with a positive integer n ( n≤1000) on the first line, which is the number of horses on each side. The next n integers on the second line are the speeds of Tian's horses. Then the next n integers on the third line are the speeds of the king's horses. The input ends with a line that has a single `0' after the last test case. 
 
 Output
 For each input case, output a line containing a single number, which is the maximum money Tian Ji will get, in silver dollars. 
 
 Sample Input
 3
 92 83 71
 95 87 74
 2
 20 20
 20 20
 2
 20 19
 22 18
 0
 
 Sample Output
 200
 0
 0
*/