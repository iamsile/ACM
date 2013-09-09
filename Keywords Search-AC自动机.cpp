#include <iostream>
#include <queue>
using namespace std;

struct node {
    int cnt;
    node *next[26],*fail;
    node() {
        cnt=0;
        memset(next, 0, sizeof(next));
        fail=NULL;
    }
};

void build(char s[],node *root)
{
    int i,k=strlen(s);
    node *p=root;
    for (i=0; i<k; i++) {
        if (p->next[s[i]-'a']==NULL)
            p->next[s[i]-'a']=new node();
        p=p->next[s[i]-'a'];
    }
    p->cnt++;
}

void buildac(node *root)
{
    root->fail=NULL;
    node *cur,*p;
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        for (int i=0; i<26; i++)
            if (cur->next[i]) {
                p=cur->fail;
                while (p) {
                    if (p->next[i]) {
                        cur->next[i]->fail=p->next[i];
                        break;
                    }
                    p=p->fail;
                }
                if (p==NULL)
                    cur->next[i]->fail=root;
                q.push(cur->next[i]);
            }
    }
}

int query(char s[],node *root)
{
    node *p=root;
    int i,ans=0,ind,k=strlen(s);
    for(i=0; i<k; i++) {
		ind=s[i]-'a';
		while(p->next[ind]==NULL&&p!=root )
			p=p->fail;
		p=(p->next[ind]==NULL) ? root : p->next[ind];
		node *cur=p;
		while(cur!=root&&cur->cnt!=-1) {
			ans+=cur->cnt;
			cur->cnt=-1;
			cur=cur->fail;
		}
	}
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int i,n;
        char a[90],str[1000005];
        scanf("%d",&n);
        node *root=new node();
        for (i=0; i<n; i++) {
            scanf("%s",a);
            build(a,root);
        }
        scanf("%s",str);
        buildac(root);
        printf("%d\n",query(str,root));
    }
    return 0;
}
/*
  Problem Description
  In the modern time, Search engine came into the life of everybody like Google, Baidu, etc.
  Wiskey also wants to bring this feature to his image retrieval system.
  Every image have a long description, when users type some keywords to find the image, the system will match the keywords with description of image and show the image which the most keywords be matched.
  To simplify the problem, giving you a description of image, and some keywords, you should tell me how many keywords will be match.
  
  
  Input
  First line will contain one integer means how many cases will follow by.
  Each case will contain two integers N means the number of keywords and N keywords follow. (N <= 10000)
  Each keyword will only contains characters 'a'-'z', and the length will be not longer than 50.
  The last line is the description, and the length will be not longer than 1000000.
  
  
  Output
  Print how many keywords are contained in the description.
  
  
  Sample Input
  1
  5
  she
  he
  say
  shr
  her
  yasherhs
  
  
  Sample Output
  3
*/