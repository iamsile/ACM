#include <iostream>
#include <vector>
using namespace std;

inline int cal(int h,int m)
{
    return h*60+m;
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n) {
        vector<int> a(1000,0);
        vector<int> b(1000,-1);
        int i,j,M,D,h,m,id,t;
        char s[2];
        for(i=0;i<n;i++) {
            scanf("%02d/%02d %02d:%02d %s %03d",&M,&D,&h,&m,s,&id);
            if(s[0]=='I'){
                b[id]=cal(h, m);
            }else{
                t=cal(h, m);
                if(id==0){
                    for(j=1;j<1000;j++)
                        if(b[j]!=-1)
                            a[j]+=t-max(b[j],b[0]);
                }else {
                    if(b[0]!=-1)
                        a[id]+=t-max(b[id],b[0]);
                }
                b[id]=-1;
            }
        }
        printf("%d\n",*max_element(a.begin()+1,a.end()));
    }
    return 0;
}
/*
 Problem description
 The goddess of programming is reviewing a thick logbook, which is a yearly record of visitors to her holy altar of programming. The logbook also records her visits at the altar.
 The altar attracts programmers from all over the world because one visitor is chosen every year and endowed with a gift of miracle programming power by the goddess. The endowed programmer is chosen from those programmers who spent the longest time at the altar during the goddess's presence. There have been enthusiastic visitors who spent very long time at the altar but failed to receive the gift because the goddess was absent during their visits.
 
 Now, your mission is to write a program that finds how long the programmer to be endowed stayed at the altar during the goddess's presence.
 
 
 
 Input
 The input is a sequence of datasets. The number of datasets is less than 100. Each dataset is formatted as follows.
 
 n 
 M1/D1 h1 : m1 e1 p1 
 M2/D2 h2 : m2 e2 p2 
 
 Mn/Dn hn : mn en pn
 
 
 The first line of a dataset contains a positive even integer, n1000, which denotes the number of lines of the logbook. This line is followed by n lines of space-separated data, where Mi/Di identifies the month and the day of the visit, hi : mi represents the time of either the entrance to or exit from the altar, ei is either `I' for entrance, or `O' for exit, and pi identifies the visitor.
 
 All the lines in the logbook are formatted in a fixed-column format. Both the month and the day in the month are represented by two digits. Therefore April 1 is represented by 04/01 and not by 4/1. The time is described in the 24-hour system, taking two digits for the hour, followed by a colon and two digits for minutes, 09:13 for instance and not like 9:13. A programmer is identified by an ID, a unique number using three digits. The same format is used to indicate entrance and exit of the goddess, whose ID is 000.
 
 All the lines in the logbook are sorted in ascending order with respect to date and time. Because the altar is closed at midnight, the altar is emptied at 00:00. You may assume that each time in the input is between 00:01 and 23:59, inclusive.
 
 A programmer may leave the altar just after entering it. In this case, the entrance and exit time are the same and the length of such a visit is considered 0 minute. You may assume for such entrance and exit records, the line that corresponds to the entrance appears earlier in the input than the line that corresponds to the exit. You may assume that at least one programmer appears in the logbook.
 
 The end of the input is indicated by a line containing a single zero.
 
 
 
 Output
 For each dataset, output the total sum of the blessed time of the endowed programmer. The blessed time of a programmer is the length of his/her stay at the altar during the presence of the goddess. The endowed programmer is the one whose total blessed time is the longest among all the programmers. The output should be represented in minutes. Note that the goddess of programming is not a programmer. 
 
 Sample Input
 14
 04/21 09:00 I 000
 04/21 09:00 I 001
 04/21 09:15 I 002
 04/21 09:30 O 001
 04/21 09:45 O 000
 04/21 10:00 O 002
 04/28 09:00 I 003
 04/28 09:15 I 000
 04/28 09:30 I 004
 04/28 09:45 O 004
 04/28 10:00 O 000
 04/28 10:15 O 003
 04/29 20:00 I 002
 04/29 21:30 O 002
 20
 06/01 09:00 I 001
 06/01 09:15 I 002
 06/01 09:15 I 003
 06/01 09:30 O 002
 06/01 10:00 I 000
 06/01 10:15 O 001
 06/01 10:30 I 002
 06/01 10:45 O 002
 06/01 11:00 I 001
 06/01 11:15 O 000
 06/01 11:30 I 002
 06/01 11:45 O 001
 06/01 12:00 O 002
 06/01 12:15 I 000
 06/01 12:30 I 002
 06/01 12:45 O 000
 06/01 13:00 I 000
 06/01 13:15 O 000
 06/01 13:30 O 002
 06/01 13:45 O 003
 0
 Sample Output
 45
 120
*/