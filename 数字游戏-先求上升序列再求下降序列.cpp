#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        char a[500010]={0};
        scanf("%s",a);
        list<char> s(a,a+strlen(a));
        list<char>::iterator it=s.begin();
        list<char>::iterator ov=s.end();
        ov--;
        while (it!=ov&&m) {
            if (*it<*++it) {
                --it;
                it=s.erase(it);
                if (it!=s.begin())
                    --it;
                m--;
            }
        }
        while (m--)
            s.pop_back();
        for (it=s .begin(); it!= s.end()&&*it=='0';it++);
		if (it== s.end()) {
            printf("0\n"); 
            continue;
        } 
		for (; it!=s.end(); it++) 
            printf("%c",*it); 
		printf("\n");
    }
    return 0;
}
/*
 Problem Description
 小艾和小牛在上数学课的时候觉得非常的无聊，于是他们想出了一个新的游戏，小牛写下N位的数字，小艾的任务就是在去除了K位后得到一个最大的数。
 Input
 输入有多组数据。第一行输入一个N和一个K( 1 <= K < N <= 500 000 ).
 接下来就是N位数字，确保输入数据中没有前导0。
 Output
 输出去除了K位后的最大数字。
 Sample Input
 4 2
 1924
 7 3
 1231234
 10 4
 4177252841
 Sample Output
 94
 3234
 775841
*/