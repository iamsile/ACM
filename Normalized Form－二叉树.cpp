#include <iostream>
#include <cstring>
using namespace std;
char a[34000];
bool cal(int &i,int m)
{
    int n=m;
    for (++i; a[i]; i++) {
        if (a[i]=='(') {
            if (m)
                n&=cal(i, m^1);
            else n|=cal(i, m^1);
        }
        else if (a[i]==')')
            return n;
        else if (a[i]=='F') {
            if (m)
                n&=0;
            else n|=0;
        }
        else if (a[i]=='T') {
            if (m)
                n&=1;
            else n|=1;
        }
    }
}

int main()
{
    
    int lab=1;
    while (~scanf("%s",a)) {
        if (strcmp(a, "()")==0)
            break;
        int i,k=strlen(a),sum=0,dep=0;
        for (i=0; i<k; i++)
            if (a[i]=='(') {
                sum++;
                dep=max(sum, dep);
            }
            else if (a[i]==')')
                sum--;
        cout << lab++;
        i=0;
        if(cal(i,dep%2))
            cout << ". true\n";
        else cout << ". false\n";
        memset(a,0,sizeof(a));
    }
    return 0;
}
/*
#include<cstdio>
#include<cstring>

char str[32000];
int n,num;

char get(char a ,char b,int type){
    int num = type%2;
    if(num==1){
        if(a=='F'|| b=='F') return 'F';
        else return 'T';
    }
    else{
        if(a=='T'|| b=='T') return 'T';
        else return 'F';
    }
}

char tof()
{
    char now;
    int cnt = 0;
    while(1){
        if(str[n]=='('){
            n++;
            tof();
        }
        else if(str[n]==')'){
            n--;
            return now;
        }
        else{
            if(cnt==0)  now = str[n];
            else now = get(str[n],now,num);
            cnt++;
        }
        n++;
    }
}

int main(){
    char now;
    while(scanf("%s",str)){
        if(strcmp(str,"()")==0) break;
        
        //int len = strlen(str);
        
        n = 0; num=0;
        
        now = tof();
        if(now=='T') printf("true\n");
        else printf("false\n");
    }
    return 0;
}
*/
/*
#include<iostream>
#include<stack>
using namespace std;

int main()
{
	char str[32100];
	int count=1;
	while(gets(str))
	{
		if(strcmp(str,"()")==0)
			break;
		stack <char> sch;
		int i,len=strlen(str),num=0,max=0;
		for(i=0;i<len;i++)
		{
			if(str[i]=='(')
				num++;
			else if(str[i]==')')
				num--;
			if(num>max)
				max=num;
		}
		int ans=1;
		if(max%2==0)
			ans=0;
		num=i=0;
		int flag=0;
		while(i<len)
		{
			if(str[i]=='(')
			{
				flag=1;
				num++;
			}
			else if(str[i]==')')
			{
				flag=0;
				num--;
			}
			if(flag)
				sch.push(str[i]);
			else
			{
				int pt;
				if((num+1)%2==ans)
				{
					pt=1;
					while(sch.top()!='(')
					{
						if(sch.top()=='F')
							pt=0;
						sch.pop();
					}
					sch.pop();
					if(pt)
						sch.push('T');
					else
						sch.push('F');
				}
				else
				{
					pt=0;
					while(sch.top()!='(')
					{
						if(sch.top()=='T')
							pt=1;
						sch.pop();
					}
					sch.pop();
					if(pt)
						sch.push('T');
					else
						sch.push('F');
				}
				flag=1;
			}
			i++;
		}
		if(sch.top()=='T')
			printf("%d. true\n",count++);
		else if(sch.top()=='F')
			printf("%d. false\n",count++);
        
	}
	return 0;
}
*/
/*
 Problem description
 As you most probably know, any boolean expression can be expressed in either a disjunctive normal form or a conjunctive normal form. In a disjunctive normal form, a boolean expression is written as a disjunct (logical or) of one-or more sub-expressions where each of these sub-expressions is written in a conjunctive normal form. Similarly, an expression written in a conjunctive normal form is a conjunct (logical and) of sub-expressions each written in a disjunctive normal form. An AND/OR tree is a tree-like graphical-representation of boolean expressions written as either conjunctive- or disjunctive-normal form.
 Since the sub-expressions of a normalized form alternate in being either disjunctive or conjunctive forms, you’d expect the sub-trees on an AND/OR tree to alternate in being AND- or OR- trees depending on the sub-tree’s depth-level. The example on the right illustrates this observation for the boolean expression (A∨(B ∧C))∧(D∨E) where the trees in the 1st (top-most) and 3rd levels are AND-trees.
 Write a program that evaluates a given and/or tree. 
 
 Input
 Your program will be tested on one or more test cases. Each test case is specified on exactly one line (which is no longer than 32,000 characters) of the form:
 (E1 E2 . . . En )
 
 where n > 0 and Ei is either T for true, F for false, or a sub-expression using the same format.
 The trees at the deepest level are AND-trees. The last test case is followed by a dummy line made of ().
 
 
 Output
 For each test case, print the following line:
 k.E
 Where k is the test case number (starting at one,) and E is either true or false depending on the value of the expression in that test case.
 
 
 Sample Input
 ((F(TF))(TF))
 (TFT)
 ((TFT)T)
 ()
 Sample Output
 1. false
 2. false
 3. true
*/